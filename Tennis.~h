//---------------------------------------------------------------------------
#ifndef TennisH
#define TennisH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "mmsystem.h"
#include <iostream>
//---------------------------------------------------------------------------
class TformGame : public TForm {
__published:	// IDE-managed Components
    TShape *background;
    TImage *paddle1;
    TImage *ball;
    TTimer *paddle1Up;
    TTimer *paddle1Down;
    TImage *paddle2;
    TTimer *paddle2Up;
    TTimer *paddle2Down;
    TTimer *ballMove;
    TPanel *newGameButton;
    TPanel *soundButton;
    TPanel *leftChoiceButton;
    TPanel *rightChoiceButton;
    TLabel *labelSpecyfyingGameMode;
    TLabel *gameLabel;
    TLabel *scoreLabel;
    TLabel *numberOfReflectionLabel;
    TPanel *continueGameButton;
    TImage *soundOnImage;
    TImage *rightArrowImage;
    TImage *leftArrowImage;
    void __fastcall paddle1UpTimer(TObject *Sender);
    void __fastcall paddle1DownTimer(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,TShiftState Shift);
    void __fastcall paddle2UpTimer(TObject *Sender);
    void __fastcall paddle2DownTimer(TObject *Sender);
    void __fastcall ballMoveTimer(TObject *Sender);
    void __fastcall newGameButtonClick(TObject *Sender);
    void __fastcall continueGameButtonClick(TObject *Sender);
    void __fastcall continueGameButtonMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall continueGameButtonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall newGameButtonMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall newGameButtonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall leftChoiceButtonMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall leftChoiceButtonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall rightChoiceButtonMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall rightChoiceButtonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall soundButtonMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall soundButtonMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall leftChoiceButtonClick(TObject *Sender);
    void __fastcall rightChoiceButtonClick(TObject *Sender);
    void __fastcall soundButtonClick(TObject *Sender);
    void __fastcall rightArrowImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall rightArrowImageMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall rightArrowImageClick(TObject *Sender);
    void __fastcall leftArrowImageClick(TObject *Sender);
    void __fastcall leftArrowImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall leftArrowImageMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall soundOnImageClick(TObject *Sender);

private:	// User declarations
    int leapOfPaddle;
    int xLeapOfBall ;
    int yLeapOfBall ;
    int initialLeapOfBall;

    int numberOfReflections;
    int leftPlayerPoints ;
    int rightPlayerPoints ;
    bool sound;
    AnsiString gameMode;
    AnsiString soundFilePath;

    void __fastcall setMatchComponentVisibilityAndActivityAfterTheEndOfRound();
    void __fastcall setTrainingComponentVisibilityAndActivityAfterTheEndOfRound();
    void __fastcall twoPlayerMode();
    void __fastcall trainingMode();
    void __fastcall setComponentVisibilityAndActivityForTheMach();
    void __fastcall rightChoiceButtonFunction();
    void __fastcall leftChoiceButtonFunction();
    void __fastcall soundButtonFunction();
    void __fastcall resetBallAndPaddlesPosition();
    void __fastcall setCommonForAllModesComponentVisibilityAndActivityAfterTheEndOfRound();
    void __fastcall hideAndDisabledComponentsForTheGame();
    bool __fastcall checkThatTheBallHitsTheCenterOfThePaddle(TImage *paddle);

public:		// User declarations
    __fastcall TformGame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformGame *formGame;
//---------------------------------------------------------------------------
#endif
