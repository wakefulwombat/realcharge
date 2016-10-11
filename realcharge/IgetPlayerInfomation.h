#ifndef _IGETPLAYERINFOMATION_
#define _IGETPLAYERINFOMATION_

#include "common.h"

class IGetPlayerInfomation{
public:
	virtual int igetPlayerChargingPower() = 0;
	virtual int igetPlayerLife() = 0;
	virtual int igetPlayerEXShotPower() = 0;
};


#endif