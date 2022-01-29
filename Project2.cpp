//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Project2.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;

int ballBounces = 0;
int leftPlayerPoints = 0;
int rightPlayerPoints = 0;
int numberOfRound=1;

void setWindowStartedParameters()
{
   Form1->Label1->Left = Form1->Tlo->Width/2 - Form1->Label1->Width/2;
   Form1->Label2->Left = Form1->Tlo->Width/2 - Form1->Label2->Width/2;
   Form1->Label3->Left = Form1->Tlo->Width/2 - Form1->Label3->Width/2;
   Form1->Label5->Left = Form1->Tlo->Width/2 - Form1->Label5->Width/2;
   Form1->Button2->Left = Form1->Tlo->Width/2 - Form1->Button2->Width/2;
   Form1->Button1->Left = Form1->Tlo->Width/2 - Form1->Button1->Width/2;
   Form1->Button3->Left = Form1->Tlo->Width/2 - Form1->Button1->Width/2;
}

void startGame()
{
   setWindowStartedParameters();

   x = -8;
   y = -8;
   ballBounces = 0;
   Form1->Timer_Ball->Interval=20;

   Form1->PaddleLeft->Left = 50;
   Form1->PaddleLeft->Top = Form1->Tlo->Height/2 - Form1->PaddleLeft->Height/2;
   Form1->PaddleRight->Left = Form1->Tlo->Width - 50 - Form1->PaddleRight->Width;
   Form1->PaddleRight->Top = Form1->Tlo->Height/2 - Form1->PaddleRight->Height/2;

    //serve of the right player
     if (numberOfRound> 1 && numberOfRound % 2 == 0)
     {
        Form1->Ball->Left = Form1->Tlo->Width - 50 - 20 - 10-36;
        Form1->Ball->Top = Form1->PaddleRight->Top+66-16;
        x = -8, y = -8;
        Form1->Label5->Visible=true;
        Form1->Label5->Caption="The right player serves.";
        Application->ProcessMessages();   Sleep(1000);
        Form1->Label5->Visible=false;
     }
     //serve of the left player
     else if (numberOfRound >= 1 && numberOfRound % 2 == 1)
     {
        Form1->Ball->Left = 50+20+10;
        Form1->Ball->Top = Form1->PaddleLeft->Top+66-16;
        x = 8, y = 8;
        Form1->Label5->Visible=true;
        Form1->Label5->Caption="The left player serves.";
        Application->ProcessMessages();   Sleep(1000);
        Form1->Label5->Visible=false;
     }

   PlaySound("START", HInstance, SND_ASYNC | SND_RESOURCE);
   Application -> ProcessMessages();
   Sleep(1000);

   Form1->Ball->Visible=true;
   Form1->Timer_Ball->Enabled=true;
   Form1->PaddleRight -> Enabled = true;
   Form1->PaddleLeft -> Enabled = true;
   Application -> ProcessMessages();
   Sleep(100);

}

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

    //initial ball movement
    Ball->Left += x;
    Ball->Top += y;

    //reflection of the ball from the upper wall

    if(Ball->Top-5 <= Tlo->Top) y = -y;

    //reflection of the ball from the down wall

    if(Ball->Top+Ball->Height+5 >= Tlo->Height) y = -y;

    //left player's miss
    if(Ball->Left <= PaddleLeft->Left-5)
    {
     PlaySound("LOSS", HInstance, SND_ASYNC | SND_RESOURCE);
     Timer_Ball->Enabled=false;
     Ball->Visible=false;

     //point for right player
     rightPlayerPoints++;

     numberOfRound++;

     PaddleLeft->Enabled = false;
     PaddleRight->Enabled = false;

     Label1->Caption="Point for right player >>";
     Label1->Visible=true;
     Label2->Visible=true;
     Label3->Visible=true;
     Button1->Visible=true;
     Button2->Visible=true;

    }

    //right player's miss
    if(Ball->Left>=PaddleRight->Left+PaddleRight->Width+5)
    {
     PlaySound("LOSS", HInstance, SND_ASYNC | SND_RESOURCE);
     Timer_Ball->Enabled=false;
     Ball->Visible=false;

     //point for left player

     leftPlayerPoints++;

     numberOfRound++;

     PaddleLeft->Enabled = false;
     PaddleRight->Enabled = false;

     Label1->Caption="<< Point for left player";
     Label1->Visible=true;
     Label2->Visible=true;
     Label3->Visible=true;
     Button1->Visible=true;
     Button2->Visible=true;
     }

    //bounce ball from paddle
    else if
    (Ball->Top+Ball->Height/2 >= PaddleLeft->Top &&
     Ball->Top+Ball->Height/2 <= PaddleLeft->Top+PaddleLeft->Height &&
     Ball->Left < PaddleLeft->Left+PaddleLeft->Width)
     {
       x = 1.1*x;
       ballBounces++;
       PlaySound("BALL", HInstance, SND_ASYNC | SND_RESOURCE);

       if(x<0)
       {
       //the middle of the paddle
       if((Ball->Left <= PaddleLeft->Left + PaddleLeft->Width &&
        Ball->Top+Ball->Height/2 <= PaddleLeft->Top+2*PaddleLeft->Height/3 &&
        Ball->Top+Ball->Height/2 >= PaddleLeft->Top + PaddleLeft->Height/3))
            {
             x=-x;
            }
        //top of the paddle
        else if ((Ball->Left <= PaddleLeft->Left + PaddleLeft->Width &&
        Ball->Top + Ball->Height/2 < PaddleLeft->Top + PaddleLeft->Height/3 &&
        Ball->Top + Ball->Height/2 >= PaddleLeft->Top))
            {
             x = -0.9*x;
            }
        //the bottom of the paddle
        else if ((Ball->Left <= PaddleLeft->Left + PaddleLeft->Width &&
        Ball->Top + Ball->Height/2 <=PaddleLeft->Top +  PaddleLeft->Height &&
        Ball->Top + Ball->Height/2 > PaddleLeft->Top + 2/3 * PaddleLeft->Height))
            {
             x = -1.2*x;
            }
       }
     }

    else if
    (Ball->Top+Ball->Height/2 >= PaddleRight->Top &&
     Ball->Top+Ball->Height/2 <= PaddleRight->Top+PaddleRight->Height &&
     Ball->Left+Ball->Width >= PaddleRight->Left)
     {

       x = 1.1 * x;
       ballBounces++;
       PlaySound("BALL", HInstance, SND_ASYNC | SND_RESOURCE);
       if (x>0)
       {
       //the middle of the paddle
       if(Ball->Left <= PaddleRight->Left + PaddleRight->Width &&
       Ball->Top + Ball->Height/2 <= PaddleRight->Top + 2 * PaddleRight->Height/3 &&
       Ball->Top + Ball->Height/2 >= PaddleRight->Top + PaddleRight->Height/3)
            {
             x=-x;
            }
       //top of the paddle
       else if ((Ball->Left + Ball->Width >= PaddleRight->Left &&
       Ball->Top + Ball->Height/2 < PaddleRight->Top + PaddleRight->Height/3 &&
       Ball->Top + Ball->Height/2 >= PaddleRight->Top))
            {
             x = -0.9*x;
            }
       //the bottom of the paddle
       else if ((Ball->Left <= PaddleRight->Left + PaddleRight->Width &&
       Ball->Top + Ball->Height/2 <= PaddleRight->Top +  PaddleRight->Height &&
       Ball->Top + Ball->Height/2 > PaddleRight->Top + 2/3 * PaddleRight->Height))
            {
             x = -1.2*x;
            }
       }

     }

     //show scores
     AnsiString rightPoints;
     rightPoints=IntToStr(rightPlayerPoints);
     AnsiString leftPoints;
     leftPoints=IntToStr(leftPlayerPoints);
     Label2->Caption="Score: "+leftPoints+":"+rightPoints;

     //show the number of bounces
     AnsiString bounces;
     bounces=IntToStr(ballBounces);
     Label3->Caption="Number of bounces: "+ bounces;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if(Application->MessageBox("Are you sure you want to play again?", "Confirm",
    MB_YESNO|MB_ICONQUESTION) == IDYES)
    {
     Button3Click(Form1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

    Button1->Visible=false;
    Button2->Visible=false;
    Button3->Visible=false;

    Label1->Visible=false;
    Label2->Visible=false;
    Label3->Visible=false;
    Label4->Visible=false;
    Label5->Visible=true;

    Label5->Caption="The game starts in: 3 seconds";
    Application->ProcessMessages();   Sleep(1000);
    Label5->Caption="The game starts in: 2 seconds";
    Application->ProcessMessages();   Sleep(1000);
    Label5->Caption="The game starts in: 1 seconds";
    Application->ProcessMessages();   Sleep(1000);
    Label5->Caption="START!";
    Application->ProcessMessages();   Sleep(1000);
    Label5->Visible=false;
    startGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
      if(Application->MessageBox("Are you sure you want to end the program?", "Confirm",
      MB_YESNO|MB_ICONQUESTION) == IDNO)
      {
       Action=caNone;
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Application->MessageBox(
        "Welcome to Ping Pong.\n\n"
        "The left player controls by pressing the A and Z keys.\n"
        "The right player controls by pressing the up and down arrows.\n\n"
        "For variety of fun:\n"
        "The ball bounces at different speeds depending on where it hits.\n"
        "If you bounce ball with the top of the racket, the ball will slow down. \n"
        "If you bounce ball with the bottom of the racket, the ball will speed. \n"
        "If you bounce ball with the middle of the racket, the ball's accelerations will not change. \n"
        "The longer you bounce, the faster the ball moves.\n"
        "You can freely change the playing field.\n\n"
        "Have fun!", "Ping Pong by Natalia", MB_OK);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    rightPlayerPoints=0;
    leftPlayerPoints=0;
    numberOfRound=1;
    Button2Click(Form1);
}
//---------------------------------------------------------------------------





