#ifndef _ISETPLAYERBULLETEX_
#define _ISETPLAYERBULLETEX_

#include "bulletBase.h"

class ISetPlayerBulletEX{
public:
	virtual void isetPlayerBulletEX(Point pos, BulletKind kind, BulletColor color, int movePattern, double attackPower, double trans_vel0, double trans_acc, double trans_rad0, int disappTime_min = 0) = 0;
};

#endif