#ifndef _ISETBOSS_
#define _ISETBOSS_

#include "IsetBarrage.h"
#include "IsetItem.h"
#include "IgetPlayerInfomation.h"
#include "IsetSelifBox.h"

class ISetBoss{
public:
	virtual void isetBeginBossStartEvent() = 0;
};

#endif