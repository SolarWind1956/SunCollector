//  *************************************************************************
//  Sergej Edgar Heckel and Sergej Victor Astachov
//  Artel3D
//  Schoelkino, Crimea, Ukraine
//  19.05.2001
//  *************************************************************************


#include "FormCanv.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
    // Конструктор
    TFormCanvas::TFormCanvas(TForm* DrawForm){
        // Указатель на текущую форму
        WorkForm    = DrawForm;
        FormBasicVectorX = TAlgVector(1, 0, 0);     // Орт оси ОХ формы
        FormBasicVectorY = TAlgVector(0, 1, 0);     // Орт оси ОY формы
        FormBasicVectorZ = TAlgVector(0, 0, 1);     // Орт оси ОZ формы
        // Центр канвы формы
        FormCenter.x = WorkForm->Width / 2;
        FormCenter.y = WorkForm->Height / 2;
    };

