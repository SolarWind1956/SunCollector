//---------------------------------------------------------------------------
#ifndef AngValTsH
#define AngValTsH
//---------------------------------------------------------------------------
#include <Mask.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Trigonom.h"
//---------------------------------------------------------------------------
class TAngValFm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMaskEdit *Deg_MaskEdit;
        TMaskEdit *DegI_MaskEdit;
        TMaskEdit *Min_MaskEdit;
        TLabel *Label5;
        TBitBtn *ExitBitBtn;
        TPanel *NumberPanel;
        TSpeedButton *SevenSBut;
        TSpeedButton *FourSBut;
        TSpeedButton *OneSBut;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *EightSBut;
        TSpeedButton *FiveSBut;
        TSpeedButton *TwoSBut;
        TSpeedButton *NineSBut;
        TSpeedButton *SixSBut;
        TSpeedButton *ThreeSBut;
        TSpeedButton *NullSBut;
        TSpeedButton *CommaSBut;
        TSpeedButton *BSSBut;
        TSpeedButton *DeleteSBut;
        TSpeedButton *ClearSBut;
        TSpeedButton *NextSBut;
        TSpeedButton *PrevSBut;
        TSpeedButton *LeftSBut;
        TSpeedButton *RightSBut;
        TMaskEdit *Rad_MaskEdit;
        TMaskEdit *Sec_MaskEdit;
        TBitBtn *HelpBitBtn;
        TBevel *Bevel1;
        TBevel *Bevel2;
    TMaskEdit *MSec_MaskEdit;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall MaskEditChange(TObject *Sender);
        void __fastcall ExitBitBtnClick(TObject *Sender);
        void __fastcall RightSButClick(TObject *Sender);
        void __fastcall DeleteSButClick(TObject *Sender);
        void __fastcall NumberSButClick(TObject *Sender);
        void __fastcall CommaSButClick(TObject *Sender);
        void __fastcall BSSButClick(TObject *Sender);
        void __fastcall LeftSButClick(TObject *Sender);
        void __fastcall NextSButClick(TObject *Sender);
        void __fastcall PrevSButClick(TObject *Sender);
        void __fastcall ClearSButClick(TObject *Sender);
private:	// User declarations
        AnsiString Deg_AnsiString;
        AnsiString DegI_AnsiString;
        AnsiString Min_AnsiString;
        AnsiString Sec_AnsiString;
        AnsiString MSec_AnsiString;
        AnsiString Rad_AnsiString;
public:		// User declarations
        __fastcall TAngValFm(TComponent* Owner);
        long double __fastcall GetMyExtValue(TMaskEdit *MaskEdit, AnsiString SrcString);
        int  __fastcall GetMyIntValue(TMaskEdit *MaskEdit, AnsiString SrcString);
        TAngularValue *BV;
        TAngularValue *AV;
};
//---------------------------------------------------------------------------
extern PACKAGE TAngValFm *AngValFm;
//---------------------------------------------------------------------------
#endif
