#ifndef _ISETBOSSEVENT_
#define _ISETBOSSEVENT_

#include "bossEvent.h"
#include "boss.h"
#include "IgetPosition.h"
#include "common.h"
#include <string>
using namespace std;

class ISetBossEvent{
public:
	virtual void isetBossEventBossTalk(IGetPosition* igetPosition, Point diff, string text, Size size) = 0;
	virtual void isetBossEventBossMove(Point moveTo, int movingTime) = 0;
	virtual void isetBossEventMusicChange(int stage)=0;
};

#endif