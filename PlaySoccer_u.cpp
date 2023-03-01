//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop                              // Interface F-end + B-end
											 // TOTAL:     53   + 8 = 61
#include "PlaySoccer_u.h"
//---------------------------------------------------------------------------
// ======= Mark 1.2(3)  /  1.4(7)  /  2.2(9)  /  2.3(11)  ONLY ======= [30]
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSocca *frmSocca;
//~~~~~~~~~~~~~~~~~~~~ TAB 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~``
//- Q1.1 ------------------------------------------------------------------- 2
__fastcall TfrmSocca::TfrmSocca(TComponent* Owner): TForm(Owner)
{                                                                      //[2]
	FormatSettings.ShortDateFormat = "yyyy/mm/dd";      // provided!
	FormatSettings.DecimalSeparator = '.';              //

	myList = new TStringList();                                         // 1
	imgIntro->Picture->LoadFromFile("..\\..\\Players\\Intro.jpg");      // 1
}
//- Q1.2 -------------------------------------------------------------------- 3
void __fastcall TfrmSocca::btnOpenClick(TObject *Sender)
{                                                                          //[3]
	myList->LoadFromFile("..\\..\\Players\\WC 2018 France.txt");            // 1
	lstPreview->Items->LoadFromFile("..\\..\\Players\\WC 2018 France.txt"); // 1
	lblHidden->Show();                                                      // 1

	Application->ProcessMessages();
	Sleep(1000);
	pnlData->Show();
}
//---------------------------------------------------------------------------
//- Q1.3 ----------------------- Self-defined!!! ------------------------   //[5]
AnsiString TfrmSocca::ExtractFieldNoFrom(int Nr, AnsiString line, char Delim)// 1
{
	line += Delim;                      // Field Nr 1 => 1 !                // 1
	for (int i = 0; i < Nr; i++)                                            // 1
	{
		line.Delete(1, line.AnsiPos(Delim));                                 // 1
	}
	return line.SubString(1, line.AnsiPos(Delim)-1);                        // 1
}
//- Q1.4 -------------------------------------------------------------------- 7
void __fastcall TfrmSocca::btnAdd2StrgClick(TObject *Sender)
{                                                                          //[7]
	AnsiString ln, nameF;
	strgData->RowCount = myList->Count;                                     // 1
	for (int r = 0; r < myList->Count; r++)                                 // 1
	{
		ln = myList->Strings[r];                                             // 1
		for (int colNr = 0; colNr < 6; colNr++)                              // 1
		{
			if (colNr == 2)                                                   //
			{                                                                 //
				nameF = ExtractFieldNoFrom(colNr, ln, '|');                    // 2
				nameF = nameF.SubString(1, AnsiPos("(", nameF)-2);             //
				strgData->Cells[colNr][ r] = nameF;                            //
			}
			else
				strgData->Cells[colNr][ r] =  ExtractFieldNoFrom(colNr, ln, '|');// 1
		}
	}
}
//- Q1.5 -------------------------------------------------------------------- 2
void __fastcall TfrmSocca::btnHeadersClick(TObject *Sender)
{                                                                          //[2]
	strgData->Cells[0][0] = "Position";
	strgData->Cells[1][0] = "Player's Name";
	strgData->Cells[2][0] = "Date of Birth";
	strgData->Cells[3][0] = "CAPS";
	strgData->Cells[4][0] = "Goals";
}
//- Q1.6 ------------------------------------------------------------------- 10
void __fastcall TfrmSocca::btnCorrectClick(TObject *Sender)
{                                                                          //[10]
	AnsiString months[12] = {"January","February","March","April","May","June"
		,"July","August","September","October","November","December"};       // 1
	// Original data: "13 August 1995 (aged 22)"  => 1995/08/13   + Calc Age now!
	for (int k = 1; k < strgData->RowCount; k++)                            // 1
	{
		AnsiString DOB = strgData->Cells[2][k];
		AnsiString dd = DOB.SubString(1,DOB.AnsiPos(" ")-1);  // day (extract)// 1
		DOB.Delete(1,DOB.AnsiPos(" "));
		AnsiString mmm = DOB.SubString(1,DOB.AnsiPos(" ")-1); // month        // 1
		DOB.Delete(1,DOB.AnsiPos(" "));
		AnsiString yy = DOB;                                  // year         // 1

		int mn;                                                               //
		for (mn = 0; mn < 12; mn++)                                           // 2
			if (mmm == months[mn])                                             //
				break;                                                          //

		AnsiString DOBshrt = yy +"/"+ IntToStr(mn+1) +"/"+ dd;                // 1

		TDate aDate = StrToDate(DOBshrt);                                     //
		strgData->Cells[2][k] = FormatDateTime("yyyy/mm/dd", aDate);          // 1
	}                                            // make sure leading 0 -> month
	bttInstant->Enabled = true;                                             // 1
}
//- Q1.7 -------------------------------------------------------------------- 4
void __fastcall TfrmSocca::btnAvgClick(TObject *Sender)
{                                                                          //[4]
	int sumGoals = 0;                                                       // 1
	for (int r = 1; r < strgData->RowCount; r++)                            // 1
	{
		sumGoals += strgData->Cells[4][r].ToInt();                           // 1
	}
	edtAvgGoals->Text = FloatToStrF(1.0 * sumGoals/ 23, ffFixed, 5, 1);     // 1
}
//- Q2.1 --------- Visit Back-end Class for completion ========> [8]
//- Q2.2 -------------------------------------------------------------------  9
void __fastcall TfrmSocca::bttInstantClick(TObject *Sender)
{                                                                          //[9]
	AnsiString tPoss, tName, tDOB;
	int tCAPS, tGoals;
	cmbNames1->Clear();                                                     // 1
	cmbNames1->Text = "Goto Tab 2 & Select!";                               // 1
	for (int r = 1; r < strgData->RowCount; r++)                            // 1
	{
		// Add names to the combo boxes
		cmbNames1->Items->Add(strgData->Cells[1][r]);                        // 1
		// instantiate objects DYNAMICALLY  - extract data from STRING GIRD!
		tPoss = strgData->Cells[0][r];                                  //
		tName = strgData->Cells[1][r];                                  // 1
		tDOB = strgData->Cells[2][r];                                   //
		tCAPS = strgData->Cells[3][r].ToInt();                       //
		tGoals = strgData->Cells[4][r].ToInt();                      // 1
		
		Splayers[r-1].setData(tPoss, tName, tDOB, tCAPS, tGoals);            // 2
		lblCount->Caption = IntToStr(r);                                     // 1
		Application->ProcessMessages();
		Sleep(100);
	}
}
//----------------- TAB 2 ---------------------------------------------------
//- Q2.3 ------------------------------------------------------------------- 11
void __fastcall TfrmSocca::cmbNames1Select(TObject *Sender)
{                                                                          //[11]
	AnsiString tPoss, tName, tDOB;
	int tCAPS, tGoals;

	// get soccer player name
	AnsiString Name = cmbNames1->Items->Strings[cmbNames1->ItemIndex];       // 1

	// find applicable object!
	for (int i = 0; i < 23; i++)                                             // 1
	{
		if (Splayers[i].getName() == Name)                                   // 1
		{
			lblFound->Show();                                                  //
			lblPos->Show();                                                    // 1
			lblPos->Caption = IntToStr(i);                                     // 
			pnlPlayer->Show();            // Or before loop = also OK          // 

			// Extract info from back-end class object!
			Splayers[i].getData(tPoss, tName, tDOB, tCAPS, tGoals);           // 1
			lblName->Caption = tName;                                         // 1
			AnsiString fileN = "..\\..\\Players\\" + tName + ".jpg";           // 1
			imgPlayer1->Picture->LoadFromFile(fileN);                          // 1
			edtDOB->Text = tDOB;                                            // 1
			lblAge->Caption =                                               // 1
				FormatDateTime("yy", Now() - Splayers[i].getRealDate()) + " years";
			lblIndex->Caption = FloatToStrF(Splayers[i].getPlayerIndx(), ffFixed,6,1);
			break;                                                          // 1
		}
	}
}
//----------------- END assignment 3 ----------------------------------------
// ======= Mark 1.2  /  1.4  /  2.2  /  2.3  ONLY ===========================
