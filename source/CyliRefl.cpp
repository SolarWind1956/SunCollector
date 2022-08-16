//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include <Math.hpp>
#include "CyliRefl.h"
#include "Algebra.h"
#include "AstrClas.h"
#include "MiddTime.h"
#include "SolarCollector.h"
#include "CoordSys.h"
#include "Shapes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCyliReflFm *CyliReflFm;

//  ______________________________________________________________________
//
//  � � � � � � � � �    �   � � � � � � � � � �
//  ______________________________________________________________________
//
TDateTime DateTime;
const int Radius = 20;                      // ������ ������
TSun Sun;                                   // ������
TSun DrawSunVect;                           // ������ ������ ��� ����������
// �����
TPipe* NewPipe = new TPipe(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0), 400, 30);
// ���������
FSCReflector* NewReflector = new FSCReflector(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0),
                                                 400, 100,
                                                 TAngularValue(120, 0, 0).Rad);
// ���������
TSolarCollector *Collector = new TSolarCollector;
int iMinute;                                // ������� �������
int iHour;
int DMin;                                   // ������������ ��������� �������
TFormCanvas* FormCanv;                      // �������� ����� ������
TPoint FormCenter;                          // �������� ����� �����
// ������� �������������� ������� ���������
CartesianOrthographicCoordinateSystem UCS = CartesianOrthographicCoordinateSystem(Left);
//---------------------------------------------------------------------------
__fastcall TCyliReflFm::TCyliReflFm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TCyliReflFm::Button1Click(TObject *Sender)
{
    Timer1->Enabled = false;            // ������������� ���������� ������
}
//---------------------------------------------------------------------------
void __fastcall TCyliReflFm::Button2Click(TObject *Sender)
{
    // ������� ����
    DateTime = DateTimePicker->Date;
    // �������� ����� ������
    TFormCanvas* FormCanv = new TFormCanvas(this);

    CyliReflFm->Canvas->Brush->Color = clBtnFace;
    CyliReflFm->Canvas->FillRect(Rect(0, 0, CyliReflFm->Width, CyliReflFm->Height));
     // ���������� ������ ������� ��������� �� �����
    FormCanv->FormCenter.x = UCS.X_Center = CyliReflFm->Width / 2;
    FormCanv->FormCenter.y = UCS.Y_Center = CyliReflFm->Height / 2;
    UCS.Z_Center = 0;
    // �������������� ����������� ����
    UCS.BasicVectorX = TAlgVector(1, 0, 0);
    UCS.BasicVectorY = TAlgVector(0, 1, 0);
    UCS.BasicVectorZ = TAlgVector(0, 0, 1);
    // ������� ������� ���������
    UCS.RotateAroundOX(M_PI / 2);
    UCS.RotateAroundOZ(M_PI);
    //      ���������� (�����������) ������� ���� ��������
    //      UCS.RotateAroundOX(M_PI / 2);
    UCS.RotateAroundOX(M_PI / 4);
    UCS.RotateAroundOZ(M_PI / 4);
    // ���������� ���� ������� ���������
    CyliReflFm->Canvas->Pen->Color = clBlack;
    CyliReflFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);
    // ������������� �������
    iMinute = 0;
    iHour = 0;
    DMin = 30;
    // ������ ������
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCyliReflFm::Timer1Timer(TObject *Sender)
{
    // �������� ����� ������
    TFormCanvas* FormCanv = new TFormCanvas(this);
    static bool Start;
    // ���������� ���� ������� ���������
    CyliReflFm->Canvas->Pen->Color = clBlack;
    CyliReflFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);
    // ���������� ������ �� ����� ����� ������ 6 �����
    CyliReflFm->Canvas->Pen->Color   = clBtnFace;
    CyliReflFm->Canvas->Brush->Color = clBtnFace;
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
    // �������� ���������� ������ � ������� ��������� ������ � ������
    // [S] = Sx * [i] + Sy * [j] + Sz * [k];
    DrawSunVect = Sun;
    DrawSunVect.SunVect = UCS.VectorCoordinate(Sun.SunVect);

    Start = true;
    // ����� �����
    // ��� ������ ����������� OY, ��� ��� ��������� ����� ��� ��������
    NewReflector->PipeColor = clBtnFace;
    NewReflector->Draw(FormCanv);
    NewPipe->Draw(FormCanv);
    TAlgVector BeginX = (cosl(asinl(Sun.SunVect.Z_Vect)) * cosl(Sun.SolarAzimuth()))
                      * UCS.BasicVectorX;
    TAlgVector BeginZ = Sun.SunVect.Z_Vect * UCS.BasicVectorZ;
    TAlgVector Begin  = BeginX + BeginZ;
    Begin.NormVector();                         // ��������� ������
    (*NewReflector) = FSCReflector(UCS.BasicVectorY, Begin, 300, 100,
                                                 TAngularValue(120, 0, 0).Rad);
    NewReflector->PipeColor = clBlue;
    NewReflector->ShapeCS->X_Center = CyliReflFm->Width / 2;
    NewReflector->ShapeCS->Y_Center = CyliReflFm->Height / 2;
    // Reflector
    NewReflector->Draw(FormCanv);
//    ���������� ������ ������� ��������� ����������
//    NewReflector->ShapeCS->Draw(FormCanv);
    // Pipe
    (*NewPipe) = TPipe(UCS.BasicVectorY, Begin, 300, 20);
    NewPipe->PipeColor = clRed;
    NewPipe->Draw(FormCanv);
    // Sun
    // ���������� ������ �� �����, ����� ����, �������
    CyliReflFm->Canvas->Pen->Color   = clYellow;
    CyliReflFm->Canvas->Brush->Color = clYellow;
    DrawSunVect.Draw(FormCanv);
    return;
};
//---------------------------------------------------------------------------



