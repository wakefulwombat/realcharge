#ifndef _IGETBOSS_
#define _IGETBOSS_

#include "boss.h"

class IGetBoss{
public:
	virtual int igetBossSize() = 0;
	virtual Boss* igetBoss(int vectorIndex)=0;
};

#endif