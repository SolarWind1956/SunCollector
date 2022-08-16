//---------------------------------------------------------------------------
#include <vcl3.h>
#pragma hdrstop
#include "MainWind.h"
#include "MiddTime.h"
#include "AngValTs.h"
#include "VectAlg.h"
#include "CyliRefl.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainWndF *MainWndF;
//---------------------------------------------------------------------------
__fastcall TMainWndF::TMainWndF(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::AngValBitBtnClick(TObject *Sender)
{
    AngValFm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::MiddTimeBitBtnClick(TObject *Sender)
{
    MidTimFm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::VectorBitBtnClick(TObject *Sender)
{
      VectAlgFm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::ExitSpeedButtonClick(TObject *Sender)
{
    MainWndF->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::CyliReflFmSpeedButtonClick(TObject *Sender)
{
       CyliReflFm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainWndF::FormCreate(TObject *Sender)
{
    Top = 0;
    Left = 0;    
}
//---------------------------------------------------------------------------

