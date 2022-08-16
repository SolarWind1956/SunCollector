//
//  *************************************************************************
//  Sergej Victor Astakhov
//  Artel3D
//  Feodosia, Crimea, Ukraine
//  30.03.2001
//  *************************************************************************
//
//---------------------------------------------------------------------------

#ifndef SolarCollectorH
#define SolarCollectorH
#include "Algebra.cpp"
#include "Shapes.h"
#include <math.h>
#include <Math.hpp>
//---------------------------------------------------------------------------
#endif
// ���������� ���������� ������������� ����������
class FSCReflector : public TPipe {
    public:
    // ����������� �� ���������
    FSCReflector(TAlgVector AxisBasicVector,
            TAlgVector BeginVector,
            long double ldPipeLength,
            long double ldPipeRadius,
            long double ldAngle) : TPipe(AxisBasicVector,
                                         BeginVector,
                                         ldPipeLength,
                                         ldPipeRadius,
                                         ldAngle){};
};
class TSolarCollector
{
    public:
        long double RotateX;    // ���� �������� ������� ������� � ��� ��
        long double RotateY;    // ���� �������� ������� ������� � ��� �Y
        long double RotateZ;    // ���� �������� ������� ������� � ��� �Z
        int ReflectorRadius;    // ������ ����������
        int PipeRadius;
        TColor Color;
        TPenMode PenMode;
        int CollectorLength;    // ����� ���������� (�����)
        int X;                  // ���������� ������
        int Z;
   // CONSTRUCTOR
   TSolarCollector()
   {
     RotateX = 0;
     RotateY = 0;
     RotateZ = 0;
     ReflectorRadius = 0;
     PipeRadius = 0;
     Color = clBlue;
     CollectorLength = 0;
     PenMode = pmCopy;
     X = 0;
     Z = 0;
   };
   //�COPY�CONSTRUCTOR
   TSolarCollector(const TSolarCollector& Collector)
   {
     RotateX = Collector.RotateX;
     RotateY = Collector.RotateY;
     RotateZ = Collector.RotateZ;
     ReflectorRadius = Collector.ReflectorRadius;
     PipeRadius = Collector.PipeRadius;
     Color = Collector.Color;
     CollectorLength = Collector.CollectorLength;
     PenMode = Collector.PenMode;
     X = Collector.X;
     Z = Collector.Z;
   };
   //  ���������� ����������
   //
   void DrawSolarCollector(TForm* Form);
 };
