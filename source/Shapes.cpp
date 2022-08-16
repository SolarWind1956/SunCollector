//  *************************************************************************
//  Sergej Edgar Heckel and Sergej Victor Astachov
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  19.05.2001
//  *************************************************************************
#include <vcl.h>
#pragma hdrstop
#include "Shapes.h"
#include <math.h>
#include <Math.hpp>
//---------------------------------------------------------------------------

#pragma package(smart_init)
// Конструктор
TPipe::TPipe(TAlgVector AxBasicVector,
             TAlgVector BegVector,
             long double ldPipeLength,
             long double ldPipeRadius,
             long double ldAngle)
{
    // Система координат трубы
    ShapeCS = new CartesianOrthographicCoordinateSystem(Left) ;
    PipeLength = ldPipeLength;              // Длина трубы
    PipeRadius = ldPipeRadius;              // Радиус трубы
    AxisBasicVector = AxBasicVector;        // Вектор направления оси
    BeginVector = BegVector;                // Вектор начала прорисовки трубы
    // Разворачиваем систему координат трубы
    ShapeCS->BasicVectorZ = AxBasicVector;
    ShapeCS->BasicVectorX = BegVector;
    ShapeCS->BasicVectorY = ShapeCS->BasicVectorZ >> ShapeCS->BasicVectorX;
    ApertureAngle = ldAngle;                // Апертура отражателя
    // Точки оснований трубы в плоскости XOY - начало всегда от оси ОХ системы
    // координат трубы
    TAlgVector BasicVectX = TAlgVector(1, 0, 0);
    PositiveCircle[0] = PipeRadius * BasicVectX;
    PositiveCircle[0].RotateAroundOZ(M_PI - ApertureAngle / 2.0L);
    for (int iPointsCount = 1; iPointsCount < PointsNumber; iPointsCount++) {
        PositiveCircle[iPointsCount] = PositiveCircle[iPointsCount - 1];
        PositiveCircle[iPointsCount].RotateAroundOZ(ApertureAngle / PointsNumber);
    };
    // Развернем основание по осям собственной системы координат
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        PositiveCircle[iPointsCount] = ShapeCS->VectorCoordinate(PositiveCircle[iPointsCount]);
    };
    // Переместим это основание в направлении единичного вектора оси трубы
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        TAlgVector NonNormAxis = (PipeLength / 2.0L) * AxisBasicVector;
        TAlgVector Result = PositiveCircle[iPointsCount] + NonNormAxis;
        PositiveCircle[iPointsCount] = Result;
    };
    // Скопируем положительное основание в направлении,
    // обратном единичному вектору оси трубы
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        TAlgVector NonNormAxis = PipeLength * AxisBasicVector;
        TAlgVector Result = PositiveCircle[iPointsCount] - NonNormAxis;
        NegativeCircle[iPointsCount] = Result;
    };
};
void TPipe::Draw(TFormCanvas* FormCanv)
{
    // Рисуем трубу
    FormCanv->WorkForm->Canvas->Pen->Color   = PipeColor;
    FormCanv->WorkForm->Canvas->Brush->Color = PipeColor;
    for (int iPointsCount = 0; iPointsCount < PointsNumber - 1; iPointsCount += 2) {
        TPoint DrawPoints[4];               // Точки прорисовки образующих
        // Две точки положительного основания
        DrawPoints[0].x = PositiveCircle[iPointsCount].X_Vect;
        DrawPoints[0].y = PositiveCircle[iPointsCount].Y_Vect;
        DrawPoints[3].x = PositiveCircle[iPointsCount + 1].X_Vect;
        DrawPoints[3].y = PositiveCircle[iPointsCount + 1].Y_Vect;
        // Две точки отрицательного основания
        DrawPoints[1].x = NegativeCircle[iPointsCount].X_Vect;
        DrawPoints[1].y = NegativeCircle[iPointsCount].Y_Vect;
        DrawPoints[2].x = NegativeCircle[iPointsCount + 1].X_Vect;
        DrawPoints[2].y = NegativeCircle[iPointsCount + 1].Y_Vect;
        // Сдвигаем трубу к центру экрана
        for (int i = 0; i < 4; i++) {
            DrawPoints[i].x = DrawPoints[i].x + FormCanv->FormCenter.x;
            DrawPoints[i].y = DrawPoints[i].y + FormCanv->FormCenter.y;
        }
        // Собственно прорисовка трубы
        FormCanv->WorkForm->Canvas->Polygon(DrawPoints, 3);
     };
};
// Поворот вокруг оси OX на угол Angle (Rad)
void TPipe::RotateAroundOX(long double Angle){
};
// Поворот вокруг оси OY на угол Angle (Rad)
void TPipe::RotateAroundOY(long double Angle){
};
//Поворот вокруг оси OZ на угол Angle (Rad)
void TPipe::RotateAroundOZ(long double Angle){
};



/*

 // Поворот точек трубы вокруг осей
     for(int Number = 0; Number < 26; Number++)
     {
       // Вокруг оси Х
       Pipe[Number].RotateAroundOX(RotateX);
       // Вокруг оси Y
       Pipe[Number].RotateAroundOY(RotateY);
       // Вокруг оси Z
       Pipe[Number].RotateAroundOZ(RotateZ);
     }
     */

