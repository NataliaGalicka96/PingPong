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
        void __fastcall TimerLeftTopTimer(TObject *Sender);
        void __fastcall TimerLeftDownTimer(TObject *Sender);
        void __fastcall TimerRightTopTimer(TObject *Sender);
        void __fastcall TimerRightDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Timer_BallTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
