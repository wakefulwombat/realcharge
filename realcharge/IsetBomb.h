#ifndef _ISETBOMB_
#define _ISETBOMB_

#include "common.h"

class ISetBomb{
public:
	virtual void isetBomb(Point position,double trans_rad,bool isMove)=0;
};

#endif