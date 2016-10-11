#ifndef _ISETBOSSINFO_
#define _ISETBOSSINFO_

#include "common.h"
#include "charactor.h"

class ISetBossInfo{
public:
	virtual void isetPosition(Point position) = 0;
	virtual void isetTransRad(double trans_rad) = 0;
};

#endif