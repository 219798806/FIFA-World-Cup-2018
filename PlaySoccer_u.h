//---------------------------------------------------------------------------

#ifndef PlaySoccer_uH
#define PlaySoccer_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Grids.hpp>
#include "System.DateUtils.hpp"
#include <Vcl.Imaging.GIFImg.hpp>
#include <Vcl.Buttons.hpp>
#include "ClassPlayer_u.h"
//---------------------------------------------------------------------------
class TfrmSocca : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *tbsPlay;
	TTabSheet *tbsW;
	TLabel *Label1;
	TImage *imgPlace;
	TPanel *Panel1;
	TButton *btnOpen;
	TLabel *lblHidden;
	TPanel *pnlData;
	TStringGrid *strgData;
	TEdit *edtAvgGoals;
	TButton *btnAvg;
	TButton *btnCorrect;
	TButton *btnHeaders;
	TButton *btnAdd2Strg;
	TImage *imgIntro;
	TBitBtn *bttInstant;
	TLabel *Label4;
	TPanel *pnlPlayer;
	TImage *imgPlayer1;
	TLabel *lblName;
	TLabel *lblDOB;
	TLabel *lblAge;
	TEdit *edtDOB;
	TLabel *lblCount;
	TLabel *Label5;
	TLabel *lblFound;
	TLabel *lblPos;
	TComboBox *cmbNames1;
	TLabel *Label6;
	TListBox *lstPreview;
	TLabel *Label8;
	TBevel *Bevel1;
	TLabel *Label3;
	TLabel *lblIndex;
	void __fastcall btnOpenClick(TObject *Sender);
	void __fastcall btnAdd2StrgClick(TObject *Sender);
	void __fastcall btnHeadersClick(TObject *Sender);
	void __fastcall btnCorrectClick(TObject *Sender);
	void __fastcall btnAvgClick(TObject *Sender);
	void __fastcall bttInstantClick(TObject *Sender);
	void __fastcall cmbNames1Select(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmSocca(TComponent* Owner);
	AnsiString ExtractFieldNoFrom(int Nr, AnsiString line, char Delim);

	TSplayer Splayers[100];          // STATIC
	TStringList *myList;             // out!      nor marked!
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSocca *frmSocca;
//---------------------------------------------------------------------------
#endif
