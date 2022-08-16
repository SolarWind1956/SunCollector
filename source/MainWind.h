//---------------------------------------------------------------------------
#ifndef MainWindH
#define MainWindH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TMainWndF : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TImage *Image1;
    TSpeedButton *SpeedButton1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton3;
    TSpeedButton *SpeedButton4;
    TSpeedButton *CyliReflFmSpeedButton;
    TSpeedButton *ExitSpeedButton;
    void __fastcall AngValBitBtnClick(TObject *Sender);
    void __fastcall MiddTimeBitBtnClick(TObject *Sender);
    void __fastcall VectorBitBtnClick(TObject *Sender);
    void __fastcall ExitSpeedButtonClick(TObject *Sender);
    void __fastcall CyliReflFmSpeedButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TMainWndF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainWndF *MainWndF;
//---------------------------------------------------------------------------
#endif
