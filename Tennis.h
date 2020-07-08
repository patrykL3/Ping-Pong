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
        TPanel *sound;
        TLabel *gameModeLabel;
        TPanel *L;
        TPanel *R;
        TLabel *gameMode;
        TLabel *gameLabel;
        TLabel *score;
        TLabel *numberOfReflection;
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
        void __fastcall newGameButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall newGameButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall soundMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall soundMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall LMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall LMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall RMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall RMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall continueGameButtonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall continueGameButtonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
