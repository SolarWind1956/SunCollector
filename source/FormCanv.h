//---------------------------------------------------------------------------

#ifndef FormCanvH
#define FormCanvH
#include <vcl.h>
#include "Algebra.h"
//---------------------------------------------------------------------------
// ����� �����
class TFormCanvas {
public:
    TForm* WorkForm;                    // ������� �����
    TPoint FormCenter;                  // ����� �����
    TAlgVector FormBasicVectorX;        // ��� ��� �� �����
    TAlgVector FormBasicVectorY;        // ��� ��� �Y �����
    TAlgVector FormBasicVectorZ;        // ��� ��� �Z �����
    // �����������
    TFormCanvas(TForm*);
};
#endif
