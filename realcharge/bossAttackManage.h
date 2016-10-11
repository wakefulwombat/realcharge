#ifndef _BOSSATTACKmANAGE_
#define _BOSSATTACKmANAGE_
#include <vector>
#include "IgetStage.h"
#include "IgetBoss.h"
#include "bossAttack.h"
#include "IgetPosition.h"
#include "IsetBullet.h"
#include "isetEnemyLazer.h"
#include "IgetBossAttackInfo.h"
using namespace std;

class BossAttackManage : public IGetBossAttackInfo{
private:
	int attackNumCount;//0‚©‚ç
	bool attackValid;
	int playerMode;

	IGetStage* igetStage;
	IGetBoss* igetBoss;
	IGetPosition* igetPlayerPosition;
	ISetBullet* isetBullet;
	ISetEnemyLazer* isetLazer;

public:
	BossAttackManage(IGetStage* igetStage, IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetBullet* isetBullet, int playerMode);
	BossAttackManage(IGetStage* igetStage, IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, int playerMode);

	bool isAllAttackOfStageEnd();
	void setNextAttack(){ this->attackNumCount++; }
	int getHowManyBossAttackInBattle();
	int getHowManyBossActorInBattle();

	int igetAttackNumCount() override { return this->attackNumCount; }
	BossAttack* igetBossAttack(int id) override;
	int igetHowManyBossAttackInBattle() override { return this->getHowManyBossAttackInBattle(); }

	void initAttackNumCount(){ this->attackNumCount = 0; }
	void initAttackNumCount(int num){ this->attackNumCount = num; }
};

#endif