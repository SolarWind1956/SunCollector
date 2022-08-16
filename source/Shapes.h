//---------------------------------------------------------------------------

#ifndef ShapesH
#define ShapesH
#include "Algebra.h"
#include "FormCanv.h"
#include "CoordSys.h"
//---------------------------------------------------------------------------
//
//    ����������� ����� "������"
//
class TShape3D
{
public:
    // ����� ������ (������ �� ������ ��������� �� ������ ������)
    TAlgVector ShapeCenter;
    // ������� ������ ��� OX �� ���� Angle (Rad)
    virtual void RotateAroundOX(long double Angle) = 0;
    // ������� ������ ��� OY �� ���� Angle (Rad)
    virtual void RotateAroundOY(long double Angle) = 0;
    //������� ������ ��� OZ �� ���� Angle (Rad)
    virtual void RotateAroundOZ(long double Angle) = 0;
    virtual void Draw(TFormCanvas*) = 0;     // ���������� ������ �� ����� �����

//virtual void Move(int X, int Y) = 0;      // �����������
// ������� ������ ������ ����
};
// __________________________________________________________________________
// �������
// ���������� ����� ��� ���������� ��������� �����
const int PointsNumber = 24;
class TPipe : public TShape3D {
public:
    // ������� ��������� �����
    CartesianOrthographicCoordinateSystem* ShapeCS;
    // ��������� ������ ����������� ��� ����� - ������ ��������� � ����
    // OZ ������� ��������� �����
    TAlgVector AxisBasicVector;
    // ��������� ������ ������ ���������� ��������� �����
    TAlgVector BeginVector;
    // ������ �����
    long double PipeRadius;
    // ����� �����
    long double PipeLength;
    // �������� ���������� (�������)
    long double ApertureAngle;
    // ���� �����
    TColor PipeColor;
    // ����� ���������� ����� � ������������� ����������� ���
    TAlgVector PositiveCircle[PointsNumber];
    // ����� ���������� ����� � ������������� ����������� ���
    TAlgVector NegativeCircle[PointsNumber];
    // �����������
    TPipe  (TAlgVector AxisBasicVector,
            TAlgVector BeginVector,
            long double ldPipeLength,
            long double ldPipeRadius,
            long double ldAngle = 2 * M_PI);
    // ���������� ����� �� ����� �����
    void Draw(TFormCanvas*);
    // ������� ������ ��� OX �� ���� Angle (Rad)
    void RotateAroundOX(long double Angle);
    // ������� ������ ��� OY �� ���� Angle (Rad)
    void RotateAroundOY(long double Angle);
    //������� ������ ��� OZ �� ���� Angle (Rad)
    void RotateAroundOZ(long double Angle);
};
#endif
