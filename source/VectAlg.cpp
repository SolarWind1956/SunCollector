//
//  *************************************************************************
//  Sergej Victor Astakhov
//  Artel3D
//  Feodosya, Crimea, Ukraine
//  10.01.2001
//  *************************************************************************
//
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "VectAlg.h"
#include "Algebra.h"
//#include "Matrix.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVectAlgFm *VectAlgFm;
TAlgVector *pAVector = new TAlgVector;      // Указатель на первый исходный вектор
                                            // и сам ветор
TAlgVector *pBVector = new TAlgVector;      // Указатель на второй исходный вектор
TAlgVector *pCVector = new TAlgVector;      // Указатель на третий исходный вектор                                            // и сам ветор
TAlgVector *pABVectSumm = new TAlgVector;   // Сумма двух векторв векторов
TAlgVector *pABVectProduct = new TAlgVector;// Векторное произведение векторов
TAlgVector *pABVectScalar = new TAlgVector; //
TAlgVector *pMixedProduct = new TAlgVector; // Векторнео произведение трех векторов
long double Scalar;                         // Скаляр, умножаемый на вектор
//---------------------------------------------------------------------------
__fastcall TVectAlgFm::TVectAlgFm(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TVectAlgFm::CalcBitBtnClick(TObject *Sender)
{
   try
   {
     //
     pAVector->X_Vect = StrToFloat(Ax->Text);
     pAVector->Y_Vect = StrToFloat(Ay->Text);
     pAVector->Z_Vect = StrToFloat(Az->Text);
     pAVector->VectMagnitude();
     ModylA->Text = FloatToStr(pAVector->AlgVectMagnitude);
     //
     pBVector->X_Vect = StrToFloat(Bx->Text);
     pBVector->Y_Vect = StrToFloat(By->Text);
     pBVector->Z_Vect = StrToFloat(Bz->Text);
     pBVector->VectMagnitude();
     ModylB->Text = FloatToStr(pBVector->AlgVectMagnitude);
     // Scalar Product
     PrABx->Text = FloatToStr((*pAVector) * (*pBVector));
     //Summ Vector
     (*pABVectSumm) = (*pAVector) + (*pBVector);
     ABx->Text = FloatToStr(pABVectSumm->X_Vect);
     ABy->Text = FloatToStr(pABVectSumm->Y_Vect);
     ABz->Text = FloatToStr(pABVectSumm->Z_Vect);
     pABVectSumm->VectMagnitude();
     ModylAB->Text = FloatToStr(pABVectSumm->AlgVectMagnitude);

     // Vector Product
     (*pABVectProduct) = (*pAVector) >> (*pBVector);
     VABx->Text = FloatToStr(pABVectProduct->X_Vect);
     VABy->Text = FloatToStr(pABVectProduct->Y_Vect);
     VABz->Text = FloatToStr(pABVectProduct->Z_Vect);
     pABVectProduct->VectMagnitude();
     ModylVAB->Text = FloatToStr(pABVectProduct->AlgVectMagnitude);

     // Vector * Scalar
     Scalar = StrToFloat(N->Text);
     (*pABVectScalar) = Scalar * (*pAVector);
     ANx->Text = FloatToStr(pABVectScalar->X_Vect);
     ANy->Text = FloatToStr(pABVectScalar->Y_Vect);
     ANz->Text = FloatToStr(pABVectScalar->Z_Vect);
     pABVectScalar->VectMagnitude();
     ModylAN->Text = FloatToStr(pABVectScalar->AlgVectMagnitude);

     // MixedProduct
     pCVector->X_Vect = StrToFloat(Cx->Text);
     pCVector->Y_Vect = StrToFloat(Cy->Text);
     pCVector->Z_Vect = StrToFloat(Cz->Text);
     (*pMixedProduct) = MixedProduct((*pAVector),(*pBVector),(*pCVector));
     VABCx->Text = FloatToStr(pMixedProduct->X_Vect);
     VABCy->Text = FloatToStr(pMixedProduct->Y_Vect);
     VABCz->Text = FloatToStr(pMixedProduct->Z_Vect);
     ModulABC->Text = FloatToStr(pMixedProduct->AlgVectMagnitude);
   }
   catch(EConvertError&)
   {
        Application->MessageBox("Вы ввели ошибочное число","Повторите ввод",MB_OK);
   }
}
//---------------------------------------------------------------------------



