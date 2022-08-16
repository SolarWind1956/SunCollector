//---------------------------------------------------------------------------

#ifndef VectAlgH
#define VectAlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TVectAlgFm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label2;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TMaskEdit *Ax;
        TMaskEdit *Ay;
        TMaskEdit *Az;
        TMaskEdit *ModylA;
        TMaskEdit *Bx;
        TMaskEdit *By;
        TMaskEdit *Bz;
        TMaskEdit *ModylB;
    TBitBtn *CalcBitBtn;
        TMaskEdit *ABx;
        TMaskEdit *ABy;
        TMaskEdit *ABz;
        TMaskEdit *ModylAB;
        TMaskEdit *N;
        TMaskEdit *ANx;
        TMaskEdit *ANy;
        TMaskEdit *ANz;
        TMaskEdit *ModylAN;
        TMaskEdit *PrABx;
        TMaskEdit *VABx;
        TMaskEdit *VABy;
        TMaskEdit *VABz;
        TMaskEdit *ModylVAB;
        TStaticText *StaticText3;
        TMaskEdit *Cx;
        TMaskEdit *Cy;
        TMaskEdit *Cz;
        TMaskEdit *ModulC;
        TStaticText *StaticText4;
        TMaskEdit *VABCx;
        TMaskEdit *VABCy;
        TMaskEdit *VABCz;
        TMaskEdit *ModulABC;
        void __fastcall CalcBitBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TVectAlgFm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVectAlgFm *VectAlgFm;
//---------------------------------------------------------------------------
#endif
