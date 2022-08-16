//---------------------------------------------------------------------------
#ifndef MiddTimeH
#define MiddTimeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include "Trigonom.h"
#include "AstrClas.h"
//---------------------------------------------------------------------------
class TMidTimFm : public TForm
{
__published:	// IDE-managed Components
    TRadioGroup *WinterTagRGrp;
    TMaskEdit *TrueMiddTimeME;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TDateTimePicker *DateTimePicker;
    TEdit *PerEdit;
    TLabel *Label4;
    TEdit *DayOfYearEdit;
    TEdit *VernalEquinoxDayEdit;
    void __fastcall WinterTagRGrpClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall DateTimePickerChange(TObject *Sender);
    void __fastcall AssignValues();
private:	// User declarations
public:		// User declarations
    int iDayOfYear;
    long double MiddayTime;
    __fastcall TMidTimFm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMidTimFm *MidTimFm;
//  Angular velocity of the Sun motion on the celestial orb
//  Угловая Скорость движения Солнца по небесной сфере
extern TAngularValue SV;
//  Longitude of a time zone
//  Долгота временного пояса
extern TAngularValue TZL;
//  Longitude of a place
//  Долгота местности (данной, где установлен объект)
extern TAngularValue PL;
//  Latitude of terrain
//  Широта местности (данной, где установлен объект)
extern TAngularValue TL;
//  Maximum declination of the Sun
//  Максимальное склонение Солнца
extern TAngularValue MSD;
//  Tag of the summer time
//  Признак летнего времени
extern int WinterTime;


//---------------------------------------------------------------------------
#endif
