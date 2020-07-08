//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tennis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int leapOfPaddle = 10;
int xLeapOfBall = -5;
 int yLeapOfBall = -5;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1UpTimer(TObject *Sender)
{
        if(paddle1 -> Top > 10) paddle1 -> Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1DownTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height -15) paddle1->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if(Key == VK_UP) paddle2Up->Enabled = true;
          if(Key == VK_DOWN) paddle2Down->Enabled = true;
          if(Key == 65) paddle1Up->Enabled = true;
          if(Key == 90) paddle1Down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          paddle1Up->Enabled = false;
          paddle1Down->Enabled = false;
          paddle2Up->Enabled = false;
          paddle2Down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2UpTimer(TObject *Sender)
{
        if(paddle2->Top > 10) paddle2->Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2DownTimer(TObject *Sender)
{
         if(paddle2->Top + paddle2->Height < background->Height -15) paddle2->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballMoveTimer(TObject *Sender)
{
        ball->Left -= yLeapOfBall;
        ball->Top -= xLeapOfBall;
        if(ball->Top < background->Top) xLeapOfBall = -xLeapOfBall;
        if(ball->Top + ball->Height > background->Height) xLeapOfBall = -xLeapOfBall;

        //paddle2->Top = ball->Top -30;

        if(ball->Left < paddle1->Left + paddle1->Width - 15 || ball->Left + ball->Width > paddle2->Left + 15){
                ballMove->Enabled = false;
                ball->Visible = false;
        } else if(ball->Top  > paddle1->Top - ball->Height/2 && ball->Top  < paddle1->Top + paddle1->Height - ball->Height/2 && ball->Left <= paddle1->Left + paddle1->Width) {
                if(yLeapOfBall > 0) yLeapOfBall = -yLeapOfBall;
        } else if(ball->Top  > paddle2->Top - ball->Height/2 && ball->Top  < paddle2->Top + paddle2->Height - ball->Height/2 && ball->Left + ball->Width >= paddle2->Left) {
                if(yLeapOfBall < 0) yLeapOfBall = -yLeapOfBall;
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::newGameButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
          newGameButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameButtonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        newGameButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::soundMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{        sound->BevelOuter = bvLowered;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::soundMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        sound->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
          L->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
          L->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::RMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
         R->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        R->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::continueGameButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        continueGameButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::continueGameButtonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         continueGameButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

