//---------------------------------------------------------------------------

#ifndef CyliReflH
#define CyliReflH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TCyliReflFm : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TTimer *Timer1;
    TDateTimePicker *DateTimePicker;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCyliReflFm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCyliReflFm *CyliReflFm;
//---------------------------------------------------------------------------
#endif
