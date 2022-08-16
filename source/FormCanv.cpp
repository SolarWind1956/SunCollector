//  *************************************************************************
//  Sergej Edgar Heckel and Sergej Victor Astachov
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  19.05.2001
//  *************************************************************************


#include "FormCanv.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
    // �����������
    TFormCanvas::TFormCanvas(TForm* DrawForm){
        // ��������� �� ������� �����
        WorkForm    = DrawForm;
        FormBasicVectorX = TAlgVector(1, 0, 0);     // ��� ��� �� �����
        FormBasicVectorY = TAlgVector(0, 1, 0);     // ��� ��� �Y �����
        FormBasicVectorZ = TAlgVector(0, 0, 1);     // ��� ��� �Z �����
        // ����� ����� �����
        FormCenter.x = WorkForm->Width / 2;
        FormCenter.y = WorkForm->Height / 2;
    };

