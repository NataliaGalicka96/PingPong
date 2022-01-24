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
int rightPlayerPoints=0;

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

    //skucha gracza lewego
    if(Ball->Left <= PaddleLeft->Left-5)
    {
     Timer_Ball->Enabled=false;
     Ball->Visible=false;

     //punkt dla gracza prawego
     rightPlayerPoints++;

     Label1->Caption="Punkt dla gracza prawego >";
     Label1->Visible=true;
     Label2->Visible=true;
     Label3->Visible=true;
     Button1->Visible=true;
     Button2->Visible=true;

    }

    //skucha gracza prawego
    if(Ball->Left>=PaddleRight->Left+PaddleRight->Width+5)
    {
     Timer_Ball->Enabled=false;
     Ball->Visible=false;
     //punkt dla gracza lewego

     leftPlayerPoints++;

     Label1->Caption="< Punkt dla gracza lewego";
     Label1->Visible=true;
     Label2->Visible=true;
     Label3->Visible=true;
     Button1->Visible=true;
     Button2->Visible=true;


     }

    //odbicie od paletki
    else if
    (Ball->Top+Ball->Height/2 >= PaddleLeft->Top &&
     Ball->Top+Ball->Height/2 <= PaddleLeft->Top+PaddleLeft->Height &&
     Ball->Left < PaddleLeft->Left+PaddleLeft->Width)
     {
       ballBounces++;
       if(x<0) x=-x;
     }
    else if
    (Ball->Top+Ball->Height/2 >= PaddleRight->Top &&
     Ball->Top+Ball->Height/2 <= PaddleRight->Top+PaddleRight->Height &&
     Ball->Left+Ball->Width >= PaddleRight->Left)
     {
      ballBounces++;
      if (x>0) x=-x;
     }

     //pokaz punktacje

     AnsiString rightPoints;
     rightPoints=IntToStr(rightPlayerPoints);
     AnsiString leftPoints;
     leftPoints=IntToStr(leftPlayerPoints);
     Label2->Caption=leftPoints+":"+rightPoints;

     //pokaz ilosc odbic
     AnsiString bounces;
     bounces=IntToStr(ballBounces);
     Label3->Caption="Ilosc odbic: "+ bounces;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        //ustawiam pilke w neutralnym miejsscu
        Ball->Left=368;
        Ball->Top=200;

        //pokaz pilke na ekranie
        Ball->Visible=true;

        //Kierunek pi³ki
        x=-8;
        y=-8;

        //Wprowadzam pilke w ruch
        Timer_Ball->Enabled=true;
        Button1->Visible=false;
        Button2->Visible=false;

        //Ustawiam paletki na pozycjach
        PaddleLeft->Left=32;
        PaddleLeft->Top=168;

        PaddleRight->Left=712;
        PaddleRight->Top=168;

        //Wy³aczam napisy
        Label1->Visible=false;
        Label2->Visible=false;
        Label3->Visible=false;


        //resetuje ilosc odbic i punktacje
        ballBounces=0;
        rightPlayerPoints=0;
        leftPlayerPoints=0;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
          //ustawiam pilke w neutralnym miejsscu
        Ball->Left=368;
        Ball->Top=200;

        //pokaz pilke na ekranie
        Ball->Visible=true;

        //Kierunek pi³ki
        x=-8;
        y=-8;

        //Wprowadzam pilke w ruch
        Timer_Ball->Enabled=true;
        Button1->Visible=false;
        Button2->Visible=false;

        //Ustawiam paletki na pozycjach
        PaddleLeft->Left=32;
        PaddleLeft->Top=168;

        PaddleRight->Left=712;
        PaddleRight->Top=168;

        //Wy³aczam napisy
        Label1->Visible=false;
        Label2->Visible=false;
        Label3->Visible=false;


        //resetuje ilosc odbic
        ballBounces=0;

}
//---------------------------------------------------------------------------

