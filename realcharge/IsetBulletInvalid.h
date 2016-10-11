#ifndef _ISETBULLETINVALID_
#define _ISETBULLETINVALID_

#include "common.h"

class ISetBulletInvalid{
public:
	virtual void isetBulletInvalid(int vectorIndex)=0;
	virtual void isetBulletInvalidAll(Point center,int validTime) = 0;

	virtual void isetLazerInvalid(int vectorIndex) = 0;
	virtual void isetInvalidAll(Point center, int validTime) = 0;
	virtual void isetInvalidSubrange(Point center, double r) = 0;
};

#endif