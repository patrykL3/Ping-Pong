//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tennis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1UpTimer(TObject *Sender)
{
        if(paddle1 -> Top > 10) paddle1 -> Top -= 10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1DownTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height -15) paddle1->Top += 10;
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
        if(paddle2->Top > 10) paddle2->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2DownTimer(TObject *Sender)
{
         if(paddle2->Top + paddle2->Height < background->Height -15) paddle2->Top += 10;
}
//---------------------------------------------------------------------------

