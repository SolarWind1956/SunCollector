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
//  П а р а м е т р ы    и   п е р е м е н н ы е
//  ______________________________________________________________________
//
TDateTime DateTime;
const int Radius = 20;                      // Радиус солнца
TSun Sun;                                   // Солнце
TSun DrawSunVect;                           // Вектор Солнца для прорисовки
// Труба
TPipe* NewPipe = new TPipe(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0), 400, 30);
// Рефлектор
FSCReflector* NewReflector = new FSCReflector(TAlgVector(0, 0, 1), TAlgVector(1, 0, 0),
                                                 400, 100,
                                                 TAngularValue(120, 0, 0).Rad);
// Коллектор
TSolarCollector *Collector = new TSolarCollector;
int iMinute;                                // Единицы времени
int iHour;
int DMin;                                   // Дискретность изменения времени
TFormCanvas* FormCanv;                      // Условная канва экрана
TPoint FormCenter;                          // Условный Центр формы
// Создаем горизонтальную систему координат
CartesianOrthographicCoordinateSystem UCS = CartesianOrthographicCoordinateSystem(Left);
//---------------------------------------------------------------------------
__fastcall TCyliReflFm::TCyliReflFm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TCyliReflFm::Button1Click(TObject *Sender)
{
    Timer1->Enabled = false;            // Останавливаем прорисовку модели
}
//---------------------------------------------------------------------------
void __fastcall TCyliReflFm::Button2Click(TObject *Sender)
{
    // Текущая дата
    DateTime = DateTimePicker->Date;
    // Условная канва экрана
    TFormCanvas* FormCanv = new TFormCanvas(this);

    CyliReflFm->Canvas->Brush->Color = clBtnFace;
    CyliReflFm->Canvas->FillRect(Rect(0, 0, CyliReflFm->Width, CyliReflFm->Height));
     // Координаты центра системы координат на форме
    FormCanv->FormCenter.x = UCS.X_Center = CyliReflFm->Width / 2;
    FormCanv->FormCenter.y = UCS.Y_Center = CyliReflFm->Height / 2;
    UCS.Z_Center = 0;
    // Инициализируем направление осей
    UCS.BasicVectorX = TAlgVector(1, 0, 0);
    UCS.BasicVectorY = TAlgVector(0, 1, 0);
    UCS.BasicVectorZ = TAlgVector(0, 0, 1);
    // Поворот системы координат
    UCS.RotateAroundOX(M_PI / 2);
    UCS.RotateAroundOZ(M_PI);
    //      Отладочный (проверочный) поворот осей координт
    //      UCS.RotateAroundOX(M_PI / 2);
    UCS.RotateAroundOX(M_PI / 4);
    UCS.RotateAroundOZ(M_PI / 4);
    // Прорисовка осей системы координат
    CyliReflFm->Canvas->Pen->Color = clBlack;
    CyliReflFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);
    // Инициализация времени
    iMinute = 0;
    iHour = 0;
    DMin = 30;
    // Запуск таймер
    Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TCyliReflFm::Timer1Timer(TObject *Sender)
{
    // Условная канва экрана
    TFormCanvas* FormCanv = new TFormCanvas(this);
    static bool Start;
    // Прорисовка осей системы координат
    CyliReflFm->Canvas->Pen->Color = clBlack;
    CyliReflFm->Canvas->Brush->Color = clBlack;
    UCS.Draw(FormCanv);
    // Прорисовка Солнца на форме через каждые 6 минут
    CyliReflFm->Canvas->Pen->Color   = clBtnFace;
    CyliReflFm->Canvas->Brush->Color = clBtnFace;
    DrawSunVect.Draw(FormCanv);
    iMinute = iMinute + DMin;
    if (iMinute == 60) {
        iHour++;
        if (iHour == 24) iHour = 0;
        iMinute = 0;
    };
    // Формируем текущее время, не разрушая текущей даты
    Word iYear, iMonth, iDay;
    DecodeDate(DateTime, iYear, iMonth, iDay);
    TDateTime Date = EncodeDate(iYear, iMonth, iDay);
    TDateTime Time = EncodeTime(iHour, iMinute, 0, 0);
    DateTime = Date + Time;
    // Определяем координаты вектора Солнца в горизонтальной системе координат
    Sun.SetCoordinate(DateTime);
    // Если Солнце не взошло, выходим из процедуры
    if (Sun.SunVect.Z_Vect < 0.00) return;
    DMin = 6;
    // Рисуем Солнце
    Sun.Radius  = Radius;
    // Приведем координаты Солнца к системе координат экрана с учетом
    // [S] = Sx * [i] + Sy * [j] + Sz * [k];
    DrawSunVect = Sun;
    DrawSunVect.SunVect = UCS.VectorCoordinate(Sun.SunVect);

    Start = true;
    // Лепим трубу
    // Ось всегда параллельна OY, так как Эклиптика через нее проходит
    NewReflector->PipeColor = clBtnFace;
    NewReflector->Draw(FormCanv);
    NewPipe->Draw(FormCanv);
    TAlgVector BeginX = (cosl(asinl(Sun.SunVect.Z_Vect)) * cosl(Sun.SolarAzimuth()))
                      * UCS.BasicVectorX;
    TAlgVector BeginZ = Sun.SunVect.Z_Vect * UCS.BasicVectorZ;
    TAlgVector Begin  = BeginX + BeginZ;
    Begin.NormVector();                         // Нормируем вектор
    (*NewReflector) = FSCReflector(UCS.BasicVectorY, Begin, 300, 100,
                                                 TAngularValue(120, 0, 0).Rad);
    NewReflector->PipeColor = clBlue;
    NewReflector->ShapeCS->X_Center = CyliReflFm->Width / 2;
    NewReflector->ShapeCS->Y_Center = CyliReflFm->Height / 2;
    // Reflector
    NewReflector->Draw(FormCanv);
//    Отладочная печать системы координат отражателя
//    NewReflector->ShapeCS->Draw(FormCanv);
    // Pipe
    (*NewPipe) = TPipe(UCS.BasicVectorY, Begin, 300, 20);
    NewPipe->PipeColor = clRed;
    NewPipe->Draw(FormCanv);
    // Sun
    // Прорисовка Солнца на форме, ясное дело, золотом
    CyliReflFm->Canvas->Pen->Color   = clYellow;
    CyliReflFm->Canvas->Brush->Color = clYellow;
    DrawSunVect.Draw(FormCanv);
    return;
};
//---------------------------------------------------------------------------



