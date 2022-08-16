//---------------------------------------------------------------------------

#ifndef FormCanvH
#define FormCanvH
#include <vcl.h>
#include "Algebra.h"
//---------------------------------------------------------------------------
// Канва формы
class TFormCanvas {
public:
    TForm* WorkForm;                    // Рабочая форма
    TPoint FormCenter;                  // Центр формы
    TAlgVector FormBasicVectorX;        // Орт оси ОХ формы
    TAlgVector FormBasicVectorY;        // Орт оси ОY формы
    TAlgVector FormBasicVectorZ;        // Орт оси ОZ формы
    // Конструктор
    TFormCanvas(TForm*);
};
#endif
