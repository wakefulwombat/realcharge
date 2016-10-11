#ifndef _ISETSHOCKWAVE_
#define _ISETSHOCKWAVE_

#include "common.h"

class ISetShockWave{
public:
	virtual void isetShockWave(int power,Point position)=0;
	virtual void isetShockLazerStraight(Point position, bool slowMove) = 0;
};

#endif