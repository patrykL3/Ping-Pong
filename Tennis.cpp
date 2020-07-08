//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tennis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;



/*int leapOfPaddle = 10;
int xLeapOfBall = 4;
 int yLeapOfBall = 4;

    int numberOfReflections = 0;
 int leftPlayerPoints = 0;
  int rightPlayerPoints = 0;
  bool sound = true;
  */




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
leapOfPaddle = 10;
xLeapOfBall = 4;
 yLeapOfBall = 4;

    numberOfReflections = 0;
 leftPlayerPoints = 0;
  rightPlayerPoints = 0;
  sound = true;
  gameMode = labelSpecyfyingGameMode->Caption;
//ShowMessage("Opis gry                       ");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1UpTimer(TObject *Sender)
{
        if(paddle1 -> Top > 10 && newGameButton->Visible == false) paddle1 -> Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1DownTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height -15 && newGameButton->Visible == false) paddle1->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{               int aAsciNumber = 65;
                int zAsciNumber = 90;
          if(Key == VK_UP) paddle2Up->Enabled = true;
          if(Key == VK_DOWN) paddle2Down->Enabled = true;
          if(Key == aAsciNumber) paddle1Up->Enabled = true;
          if(Key == zAsciNumber) paddle1Down->Enabled = true;
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
        if(paddle2->Top > 10 && newGameButton->Visible == false) paddle2->Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2DownTimer(TObject *Sender)
{
         if(paddle2->Top + paddle2->Height < background->Height -15 && newGameButton->Visible == false) paddle2->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------

void TForm1::trainingMode() {

             paddle2->Top =   ball->Top + ball->Height/2 - paddle2->Height/2;
                     if(ball->Left < paddle1->Left + paddle1->Width - 25 ){
                setTrainingComponentVisibilityAndActivityAfterTheEndOfRound();
                numberOfReflectionLabel->Caption =  "Iloœæ odbiæ: " + IntToStr(numberOfReflections);
                gameLabel->Caption = "Tryb treningu";
                numberOfReflections = 0;
                yLeapOfBall = 4;
        } else if(ball->Top  > paddle1->Top - ball->Height/2 && ball->Top  < paddle1->Top + paddle1->Height - ball->Height/2 && ball->Left <= paddle1->Left + paddle1->Width) {
                if(sound) sndPlaySound("Project file\\soundReflection.wav", SND_ASYNC);
                if(yLeapOfBall > 0) {
                        yLeapOfBall = -yLeapOfBall;
                        numberOfReflections++;
                }
        }  else if(ball->Top  > paddle2->Top - ball->Height/2 && ball->Top  < paddle2->Top + paddle2->Height - ball->Height/2 && ball->Left + ball->Width >= paddle2->Left) {
                if(sound) sndPlaySound("Project file\\soundReflection.wav", SND_ASYNC);
                 if(yLeapOfBall < 0) {
                        yLeapOfBall = -yLeapOfBall;



                        if(ball->Top  >= paddle2->Top + paddle2->Height/2 - ball->Height/2 && ball->Top  <= paddle2->Top  + paddle2->Height/2 + ball->Height/2)
                                yLeapOfBall = 1.3*yLeapOfBall;
                 }
        }

}

void TForm1::twoPlayerMode(){
        if(ball->Left < paddle1->Left + paddle1->Width - 25 ){
                setMatchComponentVisibilityAndActivityAfterTheEndOfRound();
                numberOfReflectionLabel->Caption =  "Iloœæ odbiæ: " + IntToStr(numberOfReflections);
                gameLabel->Caption = "Punkt dla gracza Prawego >";
                rightPlayerPoints++;
                scoreLabel->Caption = "Wynik: " + IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
                numberOfReflections = 0;
                yLeapOfBall = 5;
        } else if (ball->Left + ball->Width > paddle2->Left + 25) {
                setMatchComponentVisibilityAndActivityAfterTheEndOfRound();
                numberOfReflectionLabel->Caption =  "Iloœæ odbiæ: " + IntToStr(numberOfReflections);
                gameLabel->Caption = "< Punkt dla gracza Lewego";
                leftPlayerPoints++;
                scoreLabel->Caption = "Wynik: " + IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
                numberOfReflections = 0;
                yLeapOfBall = 5;
        }
          else if(ball->Top  > paddle1->Top - ball->Height/2 && ball->Top  < paddle1->Top + paddle1->Height - ball->Height/2 && ball->Left <= paddle1->Left + paddle1->Width) {
                if(sound) sndPlaySound("Project file\\soundReflection.wav", SND_ASYNC);
                if(yLeapOfBall > 0) {
                        yLeapOfBall = -yLeapOfBall;
                        numberOfReflections++;
                                                if(ball->Top  >= paddle1->Top + paddle1->Height/2 - ball->Height/2 && ball->Top  <= paddle1->Top  + paddle1->Height/2 + ball->Height/2)
                                yLeapOfBall = 2*yLeapOfBall;
                }
        } else if(ball->Top  > paddle2->Top - ball->Height/2 && ball->Top  < paddle2->Top + paddle2->Height - ball->Height/2 && ball->Left + ball->Width >= paddle2->Left) {
                if(sound) sndPlaySound("Project file\\soundReflection.wav", SND_ASYNC);
                 if(yLeapOfBall < 0) {
                        yLeapOfBall = -yLeapOfBall;
                        numberOfReflections++;
                        if(ball->Top  >= paddle2->Top + paddle2->Height/2 - ball->Height/2 && ball->Top  <= paddle2->Top  + paddle2->Height/2 + ball->Height/2)
                                yLeapOfBall = 2*yLeapOfBall;
                 }
        }
}

void TForm1::setTrainingComponentVisibilityAndActivityAfterTheEndOfRound(){
                ballMove->Enabled = false;
                ball->Visible = false;

                  gameLabel->Visible = true;
                scoreLabel->Visible = false;
                numberOfReflectionLabel->Visible = true;
                labelSpecyfyingGameMode->Visible = true;
                soundLabel->Visible = true;

                continueGameButton->Enabled = true;
                newGameButton->Enabled = true;
                leftChoiceButton->Enabled = true;
                rightChoiceButton->Enabled = true;
                soundButton->Enabled = true;

                continueGameButton->Visible = true;
                newGameButton->Visible = true;
                leftChoiceButton->Visible = true;
                rightChoiceButton->Visible = true;
                soundButton->Visible = true;
}
void TForm1::setMatchComponentVisibilityAndActivityAfterTheEndOfRound(){
                ballMove->Enabled = false;
                ball->Visible = false;

                  gameLabel->Visible = true;
                scoreLabel->Visible = true;
                numberOfReflectionLabel->Visible = true;
                labelSpecyfyingGameMode->Visible = true;
                soundLabel->Visible = true;

                continueGameButton->Enabled = true;
                newGameButton->Enabled = true;
                leftChoiceButton->Enabled = true;
                rightChoiceButton->Enabled = true;
                soundButton->Enabled = true;

                continueGameButton->Visible = true;
                newGameButton->Visible = true;
                leftChoiceButton->Visible = true;
                rightChoiceButton->Visible = true;
                soundButton->Visible = true;
}

void TForm1::setComponentVisibilityAndActivityForTheMach(){

           ball->Top = 264;
        ball->Left = 464;
        // paddle1->Top =
        // paddle1->Left =
        // paddle2->Top =
        // paddle2->Left =
         numberOfReflections = 0;
 leftPlayerPoints = 0;
  rightPlayerPoints = 0;
        ball->Visible = true;
        ballMove->Enabled = true;

        gameLabel->Visible = false;
        scoreLabel->Visible = false;
        numberOfReflectionLabel->Visible = false;
        labelSpecyfyingGameMode->Visible = false;
        soundLabel->Visible = false;

        continueGameButton->Enabled = false;
        newGameButton->Enabled = false;
        leftChoiceButton->Enabled = false;
        rightChoiceButton->Enabled = false;
        soundButton->Enabled = false;

        continueGameButton->Visible = false;
        newGameButton->Visible = false;
        leftChoiceButton->Visible = false;
        rightChoiceButton->Visible = false;
        soundButton->Visible = false;
}


void __fastcall TForm1::ballMoveTimer(TObject *Sender)
{
        ball->Left -= yLeapOfBall;
        ball->Top -= xLeapOfBall;
        if(ball->Top < background->Top) xLeapOfBall = -xLeapOfBall;
        if(ball->Top + ball->Height > background->Height) xLeapOfBall = -xLeapOfBall;


          if(gameMode == "2 graczy") twoPlayerMode();
           if(gameMode == "Trening") trainingMode();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameButtonClick(TObject *Sender)
{
               if(continueGameButton->Visible == true && Application->MessageBox("czy na pewno rozpocz¹æ now¹ grê?","PotwierdŸ", MB_YESNO | MB_ICONQUESTION) == IDYES ) {
                        gameMode = labelSpecyfyingGameMode->Caption;
                      setComponentVisibilityAndActivityForTheMach();
                      }
               else if (continueGameButton->Visible == false) {
                          gameMode = labelSpecyfyingGameMode->Caption;
                        setComponentVisibilityAndActivityForTheMach();
                        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::continueGameButtonClick(TObject *Sender)
{

        ball->Top = 264;
        ball->Left = 464;
        yLeapOfBall = 5;
        ball->Visible = true;
        ballMove->Enabled = true;

        gameLabel->Visible = false;
        scoreLabel->Visible = false;
        numberOfReflectionLabel->Visible = false;
        labelSpecyfyingGameMode->Visible = false;
        soundLabel->Visible = false;

        continueGameButton->Enabled = false;
        newGameButton->Enabled = false;
        leftChoiceButton->Enabled = false;
        rightChoiceButton->Enabled = false;
        soundButton->Enabled = false;

        continueGameButton->Visible = false;
        newGameButton->Visible = false;
        leftChoiceButton->Visible = false;
        rightChoiceButton->Visible = false;
        soundButton->Visible = false;

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

void __fastcall TForm1::leftChoiceButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
       leftChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftChoiceButtonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      leftChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightChoiceButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      rightChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightChoiceButtonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
     rightChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::soundButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
       soundButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::soundButtonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
       soundButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::leftChoiceButtonClick(TObject *Sender)
{
        if(labelSpecyfyingGameMode->Caption == "2 graczy")
                labelSpecyfyingGameMode->Caption = "Trening";
        else if (labelSpecyfyingGameMode->Caption == "Trening")
        labelSpecyfyingGameMode->Caption = "1 gracz";
        else if (labelSpecyfyingGameMode->Caption == "1 gracz")
        labelSpecyfyingGameMode->Caption = "2 graczy";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightChoiceButtonClick(TObject *Sender)
{
        if(labelSpecyfyingGameMode->Caption == "2 graczy")
                labelSpecyfyingGameMode->Caption = "1 gracz";
        else if (labelSpecyfyingGameMode->Caption == "1 gracz")
                labelSpecyfyingGameMode->Caption = "Trening";
        else if (labelSpecyfyingGameMode->Caption == "Trening")
                labelSpecyfyingGameMode->Caption = "2 graczy";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::soundButtonClick(TObject *Sender)
{
     if(sound)
        sound = false;
     else
        sound = true;
}
//---------------------------------------------------------------------------



