//---------------------------------------------------------------------------
#include <vcl3.h>
#pragma hdrstop
#include <stdlib.h>
#include <math.h>
#include <Math.hpp>
#include "AngValTs.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAngValFm *AngValFm;
//---------------------------------------------------------------------------
__fastcall TAngValFm::TAngValFm(TComponent* Owner)
        : TForm(Owner)
{
    BV = new TAngularValue(180);
    AV = new TAngularValue(0);
    *AV = *BV;
}
//---------------------------------------------------------------------------
void __fastcall TAngValFm::FormActivate(TObject *Sender)
{
        Deg_MaskEdit->Text  = FloatToStrF(AV->Deg, ffNumber, 7, 11);
        DegI_MaskEdit->Text = IntToStr(AV->DegI);
        Min_MaskEdit->Text  = IntToStr(AV->Min);
        Sec_MaskEdit->Text  = IntToStr(AV->Sec);
        MSec_MaskEdit->Text = IntToStr(AV->MSec);
        Rad_MaskEdit->Text  = FloatToStrF(AV->Rad, ffNumber, 7, 11);
        // Запоминание корректных исходных величин, занесенных во время дизайна
        // в инспекторе объектов
        Deg_AnsiString   = Deg_MaskEdit->Text;
        DegI_AnsiString  = DegI_MaskEdit->Text;
        Min_AnsiString   = Min_MaskEdit->Text;
        Sec_AnsiString   = Sec_MaskEdit->Text;
        MSec_AnsiString  = MSec_MaskEdit->Text;
        Rad_AnsiString   = Rad_MaskEdit->Text;
        Deg_MaskEdit->SetFocus();
}
//---------------------------------------------------------------------------
// Функция преобразования введенного числа в формат с плавающей точкой.
// Функция предотвращает ввод нецифровых данных, т.е. нейтрализует ошибки оператора
// Вторым параметром является строка безусловно корректного ввода. Последнее обеспечивается
// запоминанием каждого корректного ввода в теле программы
//---------------------------------------------------------------------------
long double __fastcall TAngValFm::GetMyExtValue(TMaskEdit *MaskEdit, AnsiString SrcStr)
{
long double MyValue;
        try {
                MyValue = StrToFloat(MaskEdit->Text);
        }
        catch (EInvalidArgument&){
                MaskEdit->Text = SrcStr;
                return StrToFloat(MaskEdit->Text);
        }
        catch (EConvertError&){
                MaskEdit->Text = SrcStr;
                return StrToFloat(MaskEdit->Text);
        }
        catch (EOverflow&){
                MaskEdit->Text = SrcStr;
                return StrToFloat(MaskEdit->Text);
        };
        return MyValue;
}
//---------------------------------------------------------------------------
// Функция преобразования введенного числа в формат целого числа
int __fastcall TAngValFm::GetMyIntValue(TMaskEdit *MaskEdit, AnsiString SrcStr)
{
long double MyValue;
        try {
                MyValue = StrToInt(MaskEdit->Text);
        }
        catch (EInvalidArgument&){
                MaskEdit->Text = SrcStr;
                return StrToInt(MaskEdit->Text);
        }
        catch (EConvertError&){
                MaskEdit->Text = SrcStr;
                return StrToInt(MaskEdit->Text);
        }
        catch (EOverflow&){
                MaskEdit->Text = SrcStr;
                return StrToInt(MaskEdit->Text);
        };
        return MyValue;
}
//---------------------------------------------------------------------------
int Trigger = 1;                // Триггер повторного входа при прорисовке результатов
void __fastcall TAngValFm::MaskEditChange(TObject *Sender)
{
        if (Trigger == 0) return;   // Блокируем повторный вход
        Trigger = 0;
        if (AngValFm->Active == false) return;

        if          (((TMaskEdit*)Sender)->Name =="Deg_MaskEdit")      {
            AV->SetAngularValue(
                            DegToRad(GetMyExtValue(Deg_MaskEdit, Deg_AnsiString)));
        } else if   (((TMaskEdit*)Sender)->Name == "DegI_MaskEdit") {
            AV->SetAngularValue(
                            GetMyIntValue(DegI_MaskEdit, DegI_AnsiString),
                            GetMyIntValue(Min_MaskEdit, Min_AnsiString),
                            GetMyIntValue(Sec_MaskEdit, Sec_AnsiString),
                            GetMyIntValue(MSec_MaskEdit, MSec_AnsiString));
        } else if   (((TMaskEdit*)Sender)->Name == "Min_MaskEdit")  {
            AV->SetAngularValue(
                            GetMyIntValue(DegI_MaskEdit, DegI_AnsiString),
                            GetMyIntValue(Min_MaskEdit, Min_AnsiString),
                            GetMyIntValue(Sec_MaskEdit, Sec_AnsiString),
                            GetMyIntValue(MSec_MaskEdit, MSec_AnsiString));
        } else if   (((TMaskEdit*)Sender)->Name == "Sec_MaskEdit")    {
            AV->SetAngularValue(
                            GetMyIntValue(DegI_MaskEdit, DegI_AnsiString),
                            GetMyIntValue(Min_MaskEdit, Min_AnsiString),
                            GetMyIntValue(Sec_MaskEdit, Sec_AnsiString),
                            GetMyIntValue(MSec_MaskEdit, MSec_AnsiString));
         } else if   (((TMaskEdit*)Sender)->Name == "Rad_MaskEdit")      {
            AV->SetAngularValue(
                            GetMyExtValue(Rad_MaskEdit, Rad_AnsiString));
        };
        Deg_MaskEdit->Text  = FloatToStrF(AV->Deg, ffNumber, 10, 11);
        DegI_MaskEdit->Text = IntToStr(AV->DegI);
        Min_MaskEdit->Text  = IntToStr(AV->Min);
        Sec_MaskEdit->Text  = IntToStr(AV->Sec);
        MSec_MaskEdit->Text = IntToStr(AV->MSec);
        Rad_MaskEdit->Text  = FloatToStrF(AV->Rad, ffNumber, 14, 14);

        Deg_AnsiString   = Deg_MaskEdit->Text;
        DegI_AnsiString  = DegI_MaskEdit->Text;
        Min_AnsiString   = Min_MaskEdit->Text;
        Sec_AnsiString   = Sec_MaskEdit->Text;
        MSec_AnsiString  = MSec_MaskEdit->Text;
        Rad_AnsiString   = Rad_MaskEdit->Text;
        Trigger = 1;                // Разрешаем вход в процедуру
};
//---------------------------------------------------------------------------
void __fastcall TAngValFm::ExitBitBtnClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------
/*void __fastcall TAngValFm::PeriodInterestRGClick(TObject *Sender)
{
        if (PeriodInterestRG->ItemIndex == 0) {
                nPeriodInYear = (long double)MaxInt;
        } else if (PeriodInterestRG->ItemIndex == 1) {
                nPeriodInYear = 12.00;
        } else if (PeriodInterestRG->ItemIndex == 2) {
                nPeriodInYear = 4.00;
        } else if (PeriodInterestRG->ItemIndex == 3) {
                nPeriodInYear = 2.00;
        } else {
                nPeriodInYear = 1.00;
        };
        Calc_F();
}
*/
//---------------------------------------------------------------------------
void __fastcall TAngValFm::LeftSButClick(TObject *Sender)
{
        SendMessage(TAngValFm::ActiveControl->Handle,
                (unsigned int)WM_KEYDOWN,
                (unsigned int)VK_LEFT, HIWORD(KF_EXTENDED));
}
//---------------------------------------------------------------------------
void __fastcall TAngValFm::RightSButClick(TObject *Sender)
{
        SendMessage(TAngValFm::ActiveControl->Handle,
                (unsigned int)WM_KEYDOWN,
                (unsigned int)VK_RIGHT, HIWORD(KF_EXTENDED));
}
//---------------------------------------------------------------------------

void __fastcall TAngValFm::DeleteSButClick(TObject *Sender)
{
        SendMessage(TAngValFm::ActiveControl->Handle,
                        (unsigned int)WM_KEYDOWN,
                        (unsigned int)VK_DELETE, HIWORD(KF_EXTENDED));
}
//---------------------------------------------------------------------------
// Функция цифронабирателя.
// Каждый SpeedBotton цифронабирателя хранит в свойстве Caption
// соответствующую цифру.
void __fastcall TAngValFm::NumberSButClick(TObject *Sender)
{
AnsiString    NumberAS;                 // Цифра в формате AnsiString
char          Number[5];                // Цифра в формате Char
        NumberAS = ((TSpeedButton *)Sender)->Caption;
        itoa(StrToInt(NumberAS), Number, 10);
        SendMessage(TAngValFm::ActiveControl->Handle,
                        (unsigned int)WM_CHAR,
                        (unsigned int)Char(Number[0]),
                        NULL);
}
//---------------------------------------------------------------------------

void __fastcall TAngValFm::CommaSButClick(TObject *Sender)
{
        SendMessage(TAngValFm::ActiveControl->Handle,
                        (unsigned int)WM_CHAR,
                        (unsigned int)',', NULL);
}
//---------------------------------------------------------------------------

void __fastcall TAngValFm::BSSButClick(TObject *Sender)
{
        SendMessage(TAngValFm::ActiveControl->Handle,
                        (unsigned int)WM_CHAR,
                        (unsigned int)VK_BACK, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TAngValFm::NextSButClick(TObject *Sender)
{
        if (Deg_MaskEdit->Focused()){
                DegI_MaskEdit->SetFocus();
                return;
        };
        if (DegI_MaskEdit->Focused()){
                Min_MaskEdit->SetFocus();
                return;
        };
        if (Min_MaskEdit->Focused()){
                Rad_MaskEdit->SetFocus();
                return;
        };
        if (Rad_MaskEdit->Focused()){
                Deg_MaskEdit->SetFocus();
                return;
        };
}
//---------------------------------------------------------------------------

void __fastcall TAngValFm::PrevSButClick(TObject *Sender)
{
        if (Deg_MaskEdit->Focused()){
                Rad_MaskEdit->SetFocus();
                return;
        };
        if (DegI_MaskEdit->Focused()){
                Deg_MaskEdit->SetFocus();
                return;
        };
        if (Min_MaskEdit->Focused()){
                DegI_MaskEdit->SetFocus();
                return;
        };
        if (Sec_MaskEdit->Focused()){
                Min_MaskEdit->SetFocus();
                return;
        };
        if (Rad_MaskEdit->Focused()){
                Sec_MaskEdit->SetFocus();
                return;
        };
}
//---------------------------------------------------------------------------

void __fastcall TAngValFm::ClearSButClick(TObject *Sender)
{
        if (Deg_MaskEdit->Focused()){
                Deg_MaskEdit->Text = '0';
                return;
        };
        if (DegI_MaskEdit->Focused()){
                DegI_MaskEdit->Text = '0';
                return;
        };
        if (Min_MaskEdit->Focused()){
                Min_MaskEdit->Text = '0';
                return;
        };
        if (Sec_MaskEdit->Focused()){
                Sec_MaskEdit->Text = '0';
                return;
        };
        if (Rad_MaskEdit->Focused()){
                Rad_MaskEdit->Text = '0';
                return;
        };
}
//---------------------------------------------------------------------------


