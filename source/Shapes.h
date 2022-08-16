//---------------------------------------------------------------------------

#ifndef ShapesH
#define ShapesH
#include "Algebra.h"
#include "FormCanv.h"
#include "CoordSys.h"
//---------------------------------------------------------------------------
//
//    Абстрактный класс "Фигуры"
//
class TShape3D
{
public:
    // Центр фигуры (Вектор от начала координат до центра фигуры)
    TAlgVector ShapeCenter;
    // Поворот вокруг оси OX на угол Angle (Rad)
    virtual void RotateAroundOX(long double Angle) = 0;
    // Поворот вокруг оси OY на угол Angle (Rad)
    virtual void RotateAroundOY(long double Angle) = 0;
    //Поворот вокруг оси OZ на угол Angle (Rad)
    virtual void RotateAroundOZ(long double Angle) = 0;
    virtual void Draw(TFormCanvas*) = 0;     // Прорисовка фигуры на канве формы

//virtual void Move(int X, int Y) = 0;      // переместить
// Поворот фигуры вокруг осей
};
// __________________________________________________________________________
// Цилиндр
// Количество точек для прорисовки основания трубы
const int PointsNumber = 24;
class TPipe : public TShape3D {
public:
    // Система координат трубы
    CartesianOrthographicCoordinateSystem* ShapeCS;
    // Единичный вектор направления оси трубы - всегда совпадает с осью
    // OZ системы координат трубы
    TAlgVector AxisBasicVector;
    // Единичный вектор начала прорисовки основания трубы
    TAlgVector BeginVector;
    // Радиус труды
    long double PipeRadius;
    // Длина труды
    long double PipeLength;
    // Апертура отражателя (радианы)
    long double ApertureAngle;
    // Цвет трубы
    TColor PipeColor;
    // Точки окружности трубы в положительном направлении оси
    TAlgVector PositiveCircle[PointsNumber];
    // Точки окружности трубы в положительном направлении оси
    TAlgVector NegativeCircle[PointsNumber];
    // Конструктор
    TPipe  (TAlgVector AxisBasicVector,
            TAlgVector BeginVector,
            long double ldPipeLength,
            long double ldPipeRadius,
            long double ldAngle = 2 * M_PI);
    // Прорисовка трубы на канве формы
    void Draw(TFormCanvas*);
    // Поворот вокруг оси OX на угол Angle (Rad)
    void RotateAroundOX(long double Angle);
    // Поворот вокруг оси OY на угол Angle (Rad)
    void RotateAroundOY(long double Angle);
    //Поворот вокруг оси OZ на угол Angle (Rad)
    void RotateAroundOZ(long double Angle);
};
#endif
