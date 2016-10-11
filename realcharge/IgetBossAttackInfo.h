#ifndef _IGETBOSSATTACKINFO_
#define _IGETBOSSATTACKINFO_

#include "common.h"
#include "bossAttack.h"

class IGetBossAttackInfo{
public:
	virtual int igetAttackNumCount() = 0;
	virtual BossAttack* igetBossAttack(int id) = 0;
	virtual int igetHowManyBossAttackInBattle() = 0;
};

#endif