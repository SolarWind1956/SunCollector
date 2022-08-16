//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <Math.hpp>
#include "Graphic.h"
#include "Algebra.h"
#include "AstrClas.h"
#include "MiddTime.h"
#include "SolarCollector.h"
#include "CoordSys.h"
#include "Shapes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGraphicFm *GraphicFm;
extern TDateTime DateTime;
const int Radius = 20;                      // ������ ������
const int SunArraySize = 180;
static int NumberArray;                     // ����� �������
TSun Sun;                                   // ������
TSun DrawSunVect;
TPipe* NewPipe = new TPipe(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0), 400, 30);
FSCReflector* NewReflector = new FSCReflector(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0),
                                                 400, 100,
                                                 TAngularValue(120, 0, 0).Rad);

TSolarCollector *Collector = new TSolarCollector;   // ���������
double DrawAngle;                           // ���� �������� ���� ������
int iMinute;
int iHour;
int DMin;
TFormCanvas* FormCanv;                          // �������� ����� ������

TPoint FormCenter;                          // �������� ����� �����
// ������� �������������� ������� ���������
CartesianOrthographicCoordinateSystem UCS = CartesianOrthographicCoordinateSystem(Left);
//---------------------------------------------------------------------------
__fastcall TGraphicFm::TGraphicFm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TGraphicFm::Button1Click(TObject *Sender)
{

    Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TGraphicFm::Button2Click(TObject *Sender)
{
    // �������� ����� ������
    TFormCanvas* FormCanv = new TFormCanvas(this);

    GraphicFm->Canvas->Brush->Color = clBtnFace;
    GraphicFm->Canvas->FillRect(Rect(0, 0, GraphicFm->Width, GraphicFm->Height));
     // ���������� ������ ������� ��������� �� �����
    FormCanv->FormCenter.x = UCS.X_Center = GraphicFm->Width / 2;
    FormCanv->FormCenter.y = UCS.Y_Center = GraphicFm->Height / 2;
    UCS.Z_Center = 0;
    // �������������� ����������� ����
    UCS.BasicVectorX = TAlgVector(1, 0, 0);
    UCS.BasicVectorY = TAlgVector(0, 1, 0);
    UCS.BasicVectorZ = TAlgVector(0, 0, 1);
    // ������� ������� ���������
    UCS.RotateAroundOX(M_PI / 2);
    UCS.RotateAroundOZ(M_PI);
    UCS.RotateAroundOX(M_PI / 4);
    UCS.RotateAroundOZ(M_PI / 4);
    // ���������� ���� ������� ���������
    GraphicFm->Canvas->Pen->Color = clBlack;
    GraphicFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);

    iMinute = 0;
    iHour = 0;
    DMin = 30;
    Timer1->Enabled = true;                   // ��������� ������
}
//---------------------------------------------------------------------------

void __fastcall TGraphicFm::Timer1Timer(TObject *Sender)
{
    // �������� ����� ������
    TFormCanvas* FormCanv = new TFormCanvas(this);
    static bool Start;
    // ���������� ���� ������� ���������
    GraphicFm->Canvas->Pen->Color = clBlack;
    GraphicFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);
    // ���������� ������ �� ����� ����� ������ 6 �����
    GraphicFm->Canvas->Pen->Color   = clBtnFace;
    GraphicFm->Canvas->Brush->Color = clBtnFace;
    DrawSunVect.Draw(FormCanv);
    iMinute = iMinute + DMin;
    if (iMinute == 60) {
        iHour++;
        if (iHour == 24) iHour = 0;
        iMinute = 0;
    };
    // ��������� ������� �����, �� �������� ������� ����
    Word iYear, iMonth, iDay;
    DecodeDate(DateTime, iYear, iMonth, iDay);
    TDateTime Date = EncodeDate(iYear, iMonth, iDay);
    TDateTime Time = EncodeTime(iHour, iMinute, 0, 0);
    DateTime = Date + Time;
    // ���������� ���������� ������� ������ � �������������� ������� ���������
    Sun.SetCoordinate(DateTime);
    // ���� ������ �� ������, ������� �� ���������
    if (Sun.SunVect.Z_Vect < 0.00) return;
    DMin = 6;
    // ������ ������
    Sun.Radius  = Radius;
    // ���������� ������ �� �����, ����� ����, �������
    GraphicFm->Canvas->Pen->Color   = clYellow;
    GraphicFm->Canvas->Brush->Color = clYellow;
    // �������� ���������� ������ � ������� ��������� ������ � ������
    // [S] = Sx * [i] + Sy * [j] + Sz * [k];
    DrawSunVect = Sun;
    DrawSunVect.SunVect = UCS.VectorCoordinate(Sun.SunVect);
    DrawSunVect.Draw(FormCanv);
    Start = true;
    // ����� �����
    // ��� ������ ����������� OY, ��� ��� ��������� ����� ��� ��������
    NewReflector->PipeColor = clBtnFace;
    NewReflector->Draw(FormCanv);
    NewPipe->Draw(FormCanv);
    TAlgVector BeginX = (cosl(asinl(Sun.SunVect.Z_Vect)) * cosl(Sun.SunAzimuth()))
                      * UCS.BasicVectorX;
    TAlgVector BeginZ = Sun.SunVect.Z_Vect * UCS.BasicVectorZ;
    TAlgVector Begin  = BeginX + BeginZ;
    Begin.NormVector();
    (*NewReflector) = FSCReflector(UCS.BasicVectorY, Begin, 300, 100,
                                                 TAngularValue(120, 0, 0).Rad);

    NewReflector->PipeColor = clBlue;
    NewReflector->ShapeCS->X_Center = GraphicFm->Width / 2;
    NewReflector->ShapeCS->Y_Center = GraphicFm->Height / 2;

//    NewReflector->ShapeCS->Draw(FormCanv);
    NewReflector->Draw(FormCanv);

    (*NewPipe) = TPipe(UCS.BasicVectorY, Begin, 300, 20);
    NewPipe->PipeColor = clRed;
    NewPipe->Draw(FormCanv);

    return;
};
//---------------------------------------------------------------------------



