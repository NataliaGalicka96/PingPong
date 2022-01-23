//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8;
int y=-8;

int ballBounces=0;
int leftPlayerPoints=0;
int rightPlayerPonits=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftTopTimer(TObject *Sender)
{
        if(PaddleLeft->Top > 5)
        {
          PaddleLeft->Top-=5;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerLeftDownTimer(TObject *Sender)
{
        if(PaddleLeft->Top+PaddleLeft->Height<Tlo->Height-5)
        {
         PaddleLeft->Top+=5;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightTopTimer(TObject *Sender)
{
        if(PaddleRight->Top > 5)
        {
          PaddleRight->Top-=5;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerRightDownTimer(TObject *Sender)
{
        if(PaddleRight->Top+PaddleRight->Height<Tlo->Height-10)
        {
         PaddleRight->Top+=10;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x41) TimerLeftTop->Enabled=true;
        if(Key==0x5A) TimerLeftDown->Enabled=true;
        if(Key==VK_UP) TimerRightTop->Enabled=true;
        if(Key==VK_DOWN) TimerRightDown->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x41) TimerLeftTop->Enabled=false;
        if(Key==0x5A) TimerLeftDown->Enabled=false;
        if(Key==VK_UP) TimerRightTop->Enabled=false;
        if(Key==VK_DOWN) TimerRightDown->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer_BallTimer(TObject *Sender)
{
    //ruch poczatkowy pilki
    Ball->Left+=x;
    Ball->Top+=y;

    //odbij pi³kê od górnej sciany

    if(Ball->Top-5 <= Tlo->Top) y=-y;

    //odbij pi³kê od dolnej sciany

    if(Ball->Top+Ball->Height+5 >= Tlo->Height) y=-y;

    //skucha
    if(Ball->Left+Ball->Width <= PaddleLeft->Left-15)
    {
     Timer_Ball->Enabled=false;
     Ball->Visible=false;

     //punkt dla gracza prawego
    }
    if(Ball->Left>=PaddleRight->Left+PaddleRight->Width+15)
    {
     Timer_Ball->Enabled=false;
     Ball->Visible=false;

     //punkt dla gracza lewego
    }


    //odbicie od paletki
    else if
    (Ball->Top+Ball->Height/2 >= PaddleLeft->Top &&
     Ball->Top+Ball->Height/2 <= PaddleLeft->Top+PaddleLeft->Height &&
     Ball->Left < PaddleLeft->Left+PaddleLeft->Width)
     {
       if(x<0) x=-x;
     }
    else if
    (Ball->Top+Ball->Height/2 >= PaddleRight->Top &&
     Ball->Top+Ball->Height/2 <= PaddleRight->Top+PaddleRight->Height &&
     Ball->Left+Ball->Width >= PaddleRight->Left)
     {
      if (x>0) x=-x;
     }
}
//---------------------------------------------------------------------------
