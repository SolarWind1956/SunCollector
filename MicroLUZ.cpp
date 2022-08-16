//---------------------------------------------------------------------------
#include <vcl3.h>
#pragma hdrstop
USERES("MicroLUZ.res");
USEUNIT("source\Algebra.cpp");
USEUNIT("source\Trigonom.cpp");
USEUNIT("source\AstrClas.cpp");
USEFORM("source\MainWind.cpp", MainWndF);
USEFORM("source\AngValTs.cpp", AngValFm);
USEFORM("source\MiddTime.cpp", MidTimFm);
USEFORM("source\VectAlg.cpp", VectAlgFm);
USEUNIT("source\SolarCollector.cpp");
USEUNIT("source\CoordSys.cpp");
USEUNIT("source\Shapes.cpp");
USEUNIT("source\FormCanv.cpp");
USEFORM("source\CyliRefl.cpp", CyliReflFm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
         Application->Initialize();
         Application->CreateForm(__classid(TMainWndF), &MainWndF);
         Application->CreateForm(__classid(TAngValFm), &AngValFm);
         Application->CreateForm(__classid(TMidTimFm), &MidTimFm);
         Application->CreateForm(__classid(TVectAlgFm), &VectAlgFm);
         Application->CreateForm(__classid(TCyliReflFm), &CyliReflFm);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
