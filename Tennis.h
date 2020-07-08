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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
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
        TLabel *gameModeLabel;
        TPanel *leftChoiceButton;
        TPanel *rightChoiceButton;
        TLabel *labelSpecyfyingGameMode;
        TLabel *gameLabel;
        TLabel *scoreLabel;
        TLabel *numberOfReflectionLabel;
        TLabel *soundLabel;
        TPanel *continueGameButton;
        void __fastcall paddle1UpTimer(TObject *Sender);
        void __fastcall paddle1DownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paddle2UpTimer(TObject *Sender);
        void __fastcall paddle2DownTimer(TObject *Sender);
        void __fastcall ballMoveTimer(TObject *Sender);
        void __fastcall newGameButtonClick(TObject *Sender);
        void __fastcall continueGameButtonClick(TObject *Sender);
        void __fastcall continueGameButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall continueGameButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall newGameButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall newGameButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall leftChoiceButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall leftChoiceButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall rightChoiceButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall rightChoiceButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall soundButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall soundButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
void setComponentVisibilityAndActivityAfterTheEndOfRound();

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
