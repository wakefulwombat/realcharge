#ifndef _ISETBURNEFFECT_
#define _ISETBURNEFFECT_

#include "burnEffect.h"

class ISetBurnEffect{
public:
	virtual void isetBurnEffect(BurnEffectColor color, double expand, Point position, bool isFromEnemyOrBullet) = 0;
};

#endif