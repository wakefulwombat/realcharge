#ifndef _ISETSTANDBULLETEX_
#define _ISETSTANDBULLETEX_

#include "common.h"

class ISetStandBulletEX{
public:
	virtual void isetBulletStop(Point center, int r) = 0;
	virtual void isetBulletFlex(Point center, int r) = 0;
	virtual void isetBulletClearAfterStop() = 0;
};

#endif