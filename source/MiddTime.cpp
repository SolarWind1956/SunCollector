//---------------------------------------------------------------------------
#include <vcl3.h>
#pragma hdrstop
#include <SysUtils.hpp>
#include "MiddTime.h"
#include "AstrClas.h"



//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMidTimFm *MidTimFm;
TDateTime DateTime;
extern int DayOfYear(System::TDateTime DateTime);
extern long double TrueMiddayTime(System::TDateTime DateTime);

//---------------------------------------------------------------------------
__fastcall TMidTimFm::TMidTimFm(TComponent* Owner)
    : TForm(Owner)
{
};
//---------------------------------------------------------------------------
void __fastcall TMidTimFm::WinterTagRGrpClick(TObject *Sender)
{
        if (WinterTagRGrp->ItemIndex == 0) {
            WinterTime = 0;
        } else {
            WinterTime = 1;
        };
        AssignValues();
};
//---------------------------------------------------------------------------
void __fastcall TMidTimFm::FormActivate(TObject *Sender)
{
    AssignValues();
};
//---------------------------------------------------------------------------

void __fastcall TMidTimFm::DateTimePickerChange(TObject *Sender)
{
    AssignValues();
};
//---------------------------------------------------------------------------
void __fastcall TMidTimFm::AssignValues(){
        int         Hours, Minutes, Seconds;
        long double ExtMin;
        int iDayOfYear = DayOfYear(DateTimePicker->Date);

        DayOfYearEdit->Text = IntToStr(iDayOfYear);
        MiddayTime = TrueMiddayTime(DateTimePicker->DateTime);

        Hours    = Floor(MiddayTime);           // Целая часть - целые часы
        ExtMin   = (MiddayTime - floorl(MiddayTime)) * 60.0L;
        Minutes  = Floor(ExtMin);        // Целая часть - целые минуты
        Seconds  = Floor((ExtMin - floorl(ExtMin)) * 60.0L);
        TDateTime MyTime = EncodeTime(Hours, Minutes, Seconds, 0);
        TrueMiddTimeME->Text = TimeToStr(MyTime);

        DateTime = DateTimePicker->Date;

};
//---------------------------------------------------------------------------

