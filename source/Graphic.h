//---------------------------------------------------------------------------

#ifndef GraphicH
#define GraphicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TGraphicFm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TTimer *Timer1;
        TImage *ImageSun;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TGraphicFm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGraphicFm *GraphicFm;
//---------------------------------------------------------------------------
#endif
