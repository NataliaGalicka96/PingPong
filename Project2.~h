//---------------------------------------------------------------------------

#ifndef Project2H
#define Project2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *Tlo;
        TImage *Ball;
        TImage *PaddleLeft;
        TImage *PaddleRight;
        TTimer *TimerLeftTop;
        TTimer *TimerRightTop;
        TTimer *TimerRightDown;
        TTimer *TimerLeftDown;
        TTimer *Timer_Ball;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label4;
        TButton *Button3;
        TLabel *Label5;
        //TTimer *OdliczanieCzasu;
        void __fastcall TimerLeftTopTimer(TObject *Sender);
        void __fastcall TimerLeftDownTimer(TObject *Sender);
        void __fastcall TimerRightTopTimer(TObject *Sender);
        void __fastcall TimerRightDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Timer_BallTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        //void __fastcall OdliczanieCzasuTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
