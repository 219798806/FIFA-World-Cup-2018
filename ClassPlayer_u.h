//---------------------------------------------------------------------------

#ifndef ClassPlayer_uH
#define ClassPlayer_uH
#include "VCL.h"
//--------------------------------------------------------------------//[4]

class TSplayer                                                      // Provided
{
	private:
		AnsiString Position;
		AnsiString Name;
		AnsiString DOB;
		int CAPS;
		int Goals;
	public:
		TSplayer();
		setData(AnsiString zPosition, AnsiString zName,	AnsiString zDOB, int zCAPS,
			int zGoals);                                              // Provided
		//===================== code from here ================================
		void getData(AnsiString &zPosition, AnsiString &zName, AnsiString &zDOB,
			int &zCAPS, int &zGoals);                                    // 1

		AnsiString getName();                                           // 1
		TDate getRealDate();                                            // 1
		double getPlayerIndx();                                         // 1
};

#endif
