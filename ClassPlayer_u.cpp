//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassPlayer_u.h"
//-----------------------------------------------------------------------//[4]
#pragma package(smart_init)
TSplayer::TSplayer()                                              // provided
{
	Position = "_";
	Name = "yyy";;
	DOB = "__/__/__";
	CAPS = -1;
	Goals = -1;
}
TSplayer::setData(AnsiString zPosition, AnsiString zName, AnsiString zDOB, int zCAPS,
			int zGoals)                                              // provided
{
	Position = zPosition;
	Name = zName;;
	DOB = zDOB;
	CAPS = zCAPS;
	Goals = zGoals;
}
//============================== code from here! ==============================
void TSplayer::getData(AnsiString &zPosition, AnsiString &zName, AnsiString &zDOB,
			int &zCAPS, int &zGoals)                                 // 1
{
	zPosition = Position;                                          //
	zName = Name;;                                                 //
	zDOB = DOB;                                                    // 1
	zCAPS = CAPS;                                                  //
	zGoals = Goals;                                                //
}
AnsiString TSplayer::getName()
{
	return Name;
}

TDate TSplayer::getRealDate()
{
	return StrToDate(DOB);                                         // 1
}
double TSplayer::getPlayerIndx()
{
	return ((2.0 * CAPS + Goals)/ 3) + 1;                          // 1
}

