//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tennis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformGame *formGame;
//---------------------------------------------------------------------------
__fastcall TformGame::TformGame(TComponent* Owner)
    : TForm(Owner){
    leapOfPaddle = 8;
    initialLeapOfBall = 5;
    xLeapOfBall = initialLeapOfBall;
    yLeapOfBall = initialLeapOfBall;

    numberOfReflections = 0;
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    sound = true;
    gameMode = labelSpecyfyingGameMode->Caption;
    soundFilePath = "Project file\\soundReflection.wav";
    ShowMessage("Witaj w grze ping pong!" sLineBreak sLineBreak "Najpierw wybierz tryb gry." sLineBreak sLineBreak
        "1) W trybie dw�ch graczy lewy u�ytkownik steruje wciskaj�c klawisze A i Z. Prawy u�ytkownik wciska strza�ki do g�ry i w d�." sLineBreak
        "Kiedy odbijesz pi�k� od �rodka paletki pi�ka przy�pieszy." sLineBreak sLineBreak
        "2) W trybie treningu gracz steruje lew� paletk� (przyciskami A,Z). Z ka�dym odbiciem komputera pi�ka przy�piesza." sLineBreak sLineBreak
        "Mi�ej zabawy!");
}
//---------------------------------------------------------------------------

void __fastcall TformGame::resetBallAndPaddlesPosition() {
    ball->Top = 224;
    ball->Left = 552;
    paddle1->Top =  160;
    paddle1->Left = 24;
    paddle2->Top =  160;
    paddle2->Left = 1096;
}

void __fastcall TformGame::rightChoiceButtonFunction() {
    if(labelSpecyfyingGameMode->Caption == "2 graczy")
        labelSpecyfyingGameMode->Caption = "Trening";
    else if (labelSpecyfyingGameMode->Caption == "Trening")
        labelSpecyfyingGameMode->Caption = "2 graczy";
}

void __fastcall TformGame::leftChoiceButtonFunction() {
    if(labelSpecyfyingGameMode->Caption == "2 graczy")
        labelSpecyfyingGameMode->Caption = "Trening";
    else if (labelSpecyfyingGameMode->Caption == "Trening")
        labelSpecyfyingGameMode->Caption = "2 graczy";
}

void __fastcall TformGame::soundButtonFunction() {
    if(sound) {
        sound = false;
        soundOnImage->Picture->LoadFromFile("Project file\\sound off.bmp");
    } else {
        sound = true;
        soundOnImage->Picture->LoadFromFile("Project file\\sound on.bmp");
    }
}

void __fastcall TformGame::trainingMode() {
    if(ball->Top > paddle2->Height/2 - ball->Height/2 && ball->Top < background->Height - paddle2->Height/2  - ball->Height/2)
        paddle2->Top = ball->Top + ball->Height/2 - paddle2->Height/2;

    if(ball->Left < paddle1->Left + paddle1->Width - 25 ) {
        setTrainingComponentVisibilityAndActivityAfterTheEndOfRound();
        numberOfReflectionLabel->Caption =  "Ilo�� odbi�: " + IntToStr(numberOfReflections);
        gameLabel->Caption = "Tryb treningu";
        numberOfReflections = 0;
        yLeapOfBall = initialLeapOfBall;
    } else if(ball->Top  > paddle1->Top - ball->Height/2 && ball->Top  < paddle1->Top + paddle1->Height - ball->Height/2 && ball->Left <= paddle1->Left + paddle1->Width) {
        if(sound)
            sndPlaySound(soundFilePath.c_str(), SND_ASYNC);
        if(yLeapOfBall > 0) {
            yLeapOfBall = -yLeapOfBall;
            numberOfReflections++;
        }
    }  else if(ball->Top  > paddle2->Top - ball->Height/2 && ball->Top  < paddle2->Top + paddle2->Height - ball->Height/2 && ball->Left + ball->Width >= paddle2->Left) {
        if(sound)
            sndPlaySound(soundFilePath.c_str(), SND_ASYNC);
        if(yLeapOfBall < 0) {
            yLeapOfBall = -yLeapOfBall;
            if(checkThatTheBallHitsTheCenterOfThePaddle(paddle2))
                yLeapOfBall = 1.3*yLeapOfBall;
        }
    }
}

void __fastcall TformGame::twoPlayerMode() {
    if(ball->Left < paddle1->Left + paddle1->Width - 25) {
        setMatchComponentVisibilityAndActivityAfterTheEndOfRound();
        numberOfReflectionLabel->Caption =  "Ilo�� odbi�: " + IntToStr(numberOfReflections);
        gameLabel->Caption = "Punkt dla gracza Prawego >";
        rightPlayerPoints++;
        scoreLabel->Caption = "Wynik: " + IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
        numberOfReflections = 0;
        yLeapOfBall = initialLeapOfBall;
    } else if (ball->Left + ball->Width > paddle2->Left + 25) {
        setMatchComponentVisibilityAndActivityAfterTheEndOfRound();
        numberOfReflectionLabel->Caption =  "Ilo�� odbi�: " + IntToStr(numberOfReflections);
        gameLabel->Caption = "< Punkt dla gracza Lewego";
        leftPlayerPoints++;
        scoreLabel->Caption = "Wynik: " + IntToStr(leftPlayerPoints) + ":" + IntToStr(rightPlayerPoints);
        numberOfReflections = 0;
        yLeapOfBall = initialLeapOfBall;
    } else if(ball->Top  > paddle1->Top - ball->Height/2 && ball->Top  < paddle1->Top + paddle1->Height - ball->Height/2 && ball->Left <= paddle1->Left + paddle1->Width) {
        if(sound)
            sndPlaySound(soundFilePath.c_str(), SND_ASYNC);
        if(yLeapOfBall > 0) {
            yLeapOfBall = -yLeapOfBall;
            numberOfReflections++;
            if(checkThatTheBallHitsTheCenterOfThePaddle(paddle1))
                yLeapOfBall = 2*yLeapOfBall;
        }
    } else if(ball->Top  > paddle2->Top - ball->Height/2 && ball->Top  < paddle2->Top + paddle2->Height - ball->Height/2 && ball->Left + ball->Width >= paddle2->Left) {
        if(sound)
            sndPlaySound(soundFilePath.c_str(), SND_ASYNC);
        if(yLeapOfBall < 0) {
            yLeapOfBall = -yLeapOfBall;
            numberOfReflections++;
            if(checkThatTheBallHitsTheCenterOfThePaddle(paddle2))
                yLeapOfBall = 2*yLeapOfBall;
        }
    }
}

bool __fastcall TformGame::checkThatTheBallHitsTheCenterOfThePaddle(TImage *paddle) {
     return (ball->Top  > paddle->Top + paddle->Height/2 - ball->Height*3/4 && ball->Top  < paddle->Top  + paddle->Height/2 - ball->Height*1/4) ? true : false;
}

void __fastcall TformGame::setCommonForAllModesComponentVisibilityAndActivityAfterTheEndOfRound() {
    ballMove->Enabled = false;
    ball->Visible = false;

    gameLabel->Visible = true;
    numberOfReflectionLabel->Visible = true;
    labelSpecyfyingGameMode->Caption = gameMode;
    labelSpecyfyingGameMode->Visible = true;

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

void __fastcall TformGame::setTrainingComponentVisibilityAndActivityAfterTheEndOfRound() {
    scoreLabel->Visible = false;
    setCommonForAllModesComponentVisibilityAndActivityAfterTheEndOfRound();

}
void __fastcall TformGame::setMatchComponentVisibilityAndActivityAfterTheEndOfRound() {
    scoreLabel->Visible = true;
    setCommonForAllModesComponentVisibilityAndActivityAfterTheEndOfRound();
}

void __fastcall TformGame::setComponentVisibilityAndActivityForTheMach() {

    resetBallAndPaddlesPosition();
    numberOfReflections = 0;
    leftPlayerPoints = 0;
    rightPlayerPoints = 0;
    ball->Visible = true;
    ballMove->Enabled = true;

    hideAndDisabledComponentsForTheGame();
}

void __fastcall TformGame::hideAndDisabledComponentsForTheGame() {
    gameLabel->Visible = false;
    scoreLabel->Visible = false;
    numberOfReflectionLabel->Visible = false;
    labelSpecyfyingGameMode->Visible = false;

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

void __fastcall TformGame::paddle1UpTimer(TObject *Sender) {
    if(paddle1 -> Top > 10 && newGameButton->Visible == false)
        paddle1 -> Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TformGame::paddle1DownTimer(TObject *Sender) {
    if(paddle1->Top + paddle1->Height < background->Height -15 && newGameButton->Visible == false)
        paddle1->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------
void __fastcall TformGame::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {
    int aAsciNumber = 65;
    int zAsciNumber = 90;

    if(Key == VK_UP) paddle2Up->Enabled = true;
    if(Key == VK_DOWN) paddle2Down->Enabled = true;
    if(Key == aAsciNumber) paddle1Up->Enabled = true;
    if(Key == zAsciNumber) paddle1Down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TformGame::FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift) {
    paddle1Up->Enabled = false;
    paddle1Down->Enabled = false;
    paddle2Up->Enabled = false;
    paddle2Down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::paddle2UpTimer(TObject *Sender) {
    if(paddle2->Top > 10 && newGameButton->Visible == false)
        paddle2->Top -= leapOfPaddle;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::paddle2DownTimer(TObject *Sender) {
    if(paddle2->Top + paddle2->Height < background->Height -15 && newGameButton->Visible == false)
        paddle2->Top += leapOfPaddle;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::ballMoveTimer(TObject *Sender) {
    ball->Left -= yLeapOfBall;
    ball->Top -= xLeapOfBall;
    if(ball->Top < background->Top) xLeapOfBall = -xLeapOfBall;
    if(ball->Top + ball->Height > background->Height) xLeapOfBall = -xLeapOfBall;

    if(gameMode == "2 graczy")
        twoPlayerMode();
    else if(gameMode == "Trening")
        trainingMode();
}
//---------------------------------------------------------------------------

void __fastcall TformGame::newGameButtonClick(TObject *Sender) {
    if(continueGameButton->Visible == true && Application->MessageBox("czy na pewno rozpocz�� now� gr�?","Potwierd�", MB_YESNO | MB_ICONQUESTION) == IDYES ) {
        gameMode = labelSpecyfyingGameMode->Caption;
        setComponentVisibilityAndActivityForTheMach();
    } else if (continueGameButton->Visible == false) {
        gameMode = labelSpecyfyingGameMode->Caption;
        setComponentVisibilityAndActivityForTheMach();
    }
}
//---------------------------------------------------------------------------

void __fastcall TformGame::continueGameButtonClick(TObject *Sender) {

    resetBallAndPaddlesPosition();
    yLeapOfBall = initialLeapOfBall;
    ball->Visible = true;
    ballMove->Enabled = true;

    hideAndDisabledComponentsForTheGame();
}
//---------------------------------------------------------------------------


void __fastcall TformGame::continueGameButtonMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    continueGameButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::continueGameButtonMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    continueGameButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::newGameButtonMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    newGameButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::newGameButtonMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    newGameButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftChoiceButtonMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    leftChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftChoiceButtonMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    leftChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightChoiceButtonMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    rightChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightChoiceButtonMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    rightChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::soundButtonMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    soundButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::soundButtonMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    soundButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftChoiceButtonClick(TObject *Sender) {
    leftChoiceButtonFunction();

}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightChoiceButtonClick(TObject *Sender) {
    rightChoiceButtonFunction();
}
//---------------------------------------------------------------------------

void __fastcall TformGame::soundButtonClick(TObject *Sender) {
    soundButtonFunction();
}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightArrowImageMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    rightChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightArrowImageMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    rightChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::rightArrowImageClick(TObject *Sender) {
    rightChoiceButtonFunction();
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftArrowImageClick(TObject *Sender) {
    leftChoiceButtonFunction();
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftArrowImageMouseDown(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    leftChoiceButton->BevelOuter = bvLowered;
}
//---------------------------------------------------------------------------

void __fastcall TformGame::leftArrowImageMouseUp(TObject *Sender,
        TMouseButton Button, TShiftState Shift, int X, int Y) {
    leftChoiceButton->BevelOuter = bvRaised;
}
//---------------------------------------------------------------------------


void __fastcall TformGame::soundOnImageClick(TObject *Sender) {
    soundButtonFunction();
}
//---------------------------------------------------------------------------

