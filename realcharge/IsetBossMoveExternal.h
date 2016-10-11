#ifndef _ISETBOSSMOVEEXTERNAL_
#define _ISETBOSSMOVEEXTERNAL_

#include "common.h"

class ISetBossMoveExternal{
public:
	virtual void isetBossMoveExternal(Point moveTo,int movingTime) = 0;
	virtual void isetBossMoveInternal() = 0;
	virtual void isetBossInvalid() = 0;
};

#endif