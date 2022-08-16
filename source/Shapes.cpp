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
// �����������
TPipe::TPipe(TAlgVector AxBasicVector,
             TAlgVector BegVector,
             long double ldPipeLength,
             long double ldPipeRadius,
             long double ldAngle)
{
    // ������� ��������� �����
    ShapeCS = new CartesianOrthographicCoordinateSystem(Left) ;
    PipeLength = ldPipeLength;              // ����� �����
    PipeRadius = ldPipeRadius;              // ������ �����
    AxisBasicVector = AxBasicVector;        // ������ ����������� ���
    BeginVector = BegVector;                // ������ ������ ���������� �����
    // ������������� ������� ��������� �����
    ShapeCS->BasicVectorZ = AxBasicVector;
    ShapeCS->BasicVectorX = BegVector;
    ShapeCS->BasicVectorY = ShapeCS->BasicVectorZ >> ShapeCS->BasicVectorX;
    ApertureAngle = ldAngle;                // �������� ����������
    // ����� ��������� ����� � ��������� XOY - ������ ������ �� ��� �� �������
    // ��������� �����
    TAlgVector BasicVectX = TAlgVector(1, 0, 0);
    PositiveCircle[0] = PipeRadius * BasicVectX;
    PositiveCircle[0].RotateAroundOZ(M_PI - ApertureAngle / 2.0L);
    for (int iPointsCount = 1; iPointsCount < PointsNumber; iPointsCount++) {
        PositiveCircle[iPointsCount] = PositiveCircle[iPointsCount - 1];
        PositiveCircle[iPointsCount].RotateAroundOZ(ApertureAngle / PointsNumber);
    };
    // ��������� ��������� �� ���� ����������� ������� ���������
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        PositiveCircle[iPointsCount] = ShapeCS->VectorCoordinate(PositiveCircle[iPointsCount]);
    };
    // ���������� ��� ��������� � ����������� ���������� ������� ��� �����
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        TAlgVector NonNormAxis = (PipeLength / 2.0L) * AxisBasicVector;
        TAlgVector Result = PositiveCircle[iPointsCount] + NonNormAxis;
        PositiveCircle[iPointsCount] = Result;
    };
    // ��������� ������������� ��������� � �����������,
    // �������� ���������� ������� ��� �����
    for (int iPointsCount = 0; iPointsCount < PointsNumber; iPointsCount++) {
        TAlgVector NonNormAxis = PipeLength * AxisBasicVector;
        TAlgVector Result = PositiveCircle[iPointsCount] - NonNormAxis;
        NegativeCircle[iPointsCount] = Result;
    };
};
void TPipe::Draw(TFormCanvas* FormCanv)
{
    // ������ �����
    FormCanv->WorkForm->Canvas->Pen->Color   = PipeColor;
    FormCanv->WorkForm->Canvas->Brush->Color = PipeColor;
    for (int iPointsCount = 0; iPointsCount < PointsNumber - 1; iPointsCount += 2) {
        TPoint DrawPoints[4];               // ����� ���������� ����������
        // ��� ����� �������������� ���������
        DrawPoints[0].x = PositiveCircle[iPointsCount].X_Vect;
        DrawPoints[0].y = PositiveCircle[iPointsCount].Y_Vect;
        DrawPoints[3].x = PositiveCircle[iPointsCount + 1].X_Vect;
        DrawPoints[3].y = PositiveCircle[iPointsCount + 1].Y_Vect;
        // ��� ����� �������������� ���������
        DrawPoints[1].x = NegativeCircle[iPointsCount].X_Vect;
        DrawPoints[1].y = NegativeCircle[iPointsCount].Y_Vect;
        DrawPoints[2].x = NegativeCircle[iPointsCount + 1].X_Vect;
        DrawPoints[2].y = NegativeCircle[iPointsCount + 1].Y_Vect;
        // �������� ����� � ������ ������
        for (int i = 0; i < 4; i++) {
            DrawPoints[i].x = DrawPoints[i].x + FormCanv->FormCenter.x;
            DrawPoints[i].y = DrawPoints[i].y + FormCanv->FormCenter.y;
        }
        // ���������� ���������� �����
        FormCanv->WorkForm->Canvas->Polygon(DrawPoints, 3);
     };
};
// ������� ������ ��� OX �� ���� Angle (Rad)
void TPipe::RotateAroundOX(long double Angle){
};
// ������� ������ ��� OY �� ���� Angle (Rad)
void TPipe::RotateAroundOY(long double Angle){
};
//������� ������ ��� OZ �� ���� Angle (Rad)
void TPipe::RotateAroundOZ(long double Angle){
};



/*

 // ������� ����� ����� ������ ����
     for(int Number = 0; Number < 26; Number++)
     {
       // ������ ��� �
       Pipe[Number].RotateAroundOX(RotateX);
       // ������ ��� Y
       Pipe[Number].RotateAroundOY(RotateY);
       // ������ ��� Z
       Pipe[Number].RotateAroundOZ(RotateZ);
     }
     */

