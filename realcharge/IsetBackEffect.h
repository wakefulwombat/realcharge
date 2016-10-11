#ifndef _ISETBACKEFFECT_
#define _ISETBACKEFFECT_

#include "common.h"
#include "backEffect.h"

class ISetBackEffect{
public:
	virtual void isetBackEffect(int kind, Point position) = 0;
	virtual void isetBackEffect(int kind, Point position, int validTime) = 0;
	virtual void isetBackEffectClearAll() = 0;
};

#endif