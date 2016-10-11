#ifndef _BOSSMANAGE_
#define _BOSSMANAGE_

#include "taskBase.h"
#include "boss.h"
#include <vector>
#include "bossEventManage.h"
#include "bossAttackManage.h"
#include "IsetBoss.h"
#include "IsetSelifBox.h"
#include "IsetTextEffect.h"
#include "IgetPosition.h"
#include "IgetBoss.h"
#include "IgetStage.h"
#include "IsetBullet.h"
#include "isetEnemyLazer.h"
#include "IsetItem.h"
#include "IgetBossEventNow.h"
#include "IsetBulletInvalid.h"
#include "IsetNextStage.h"
#include "isetBossPracticeBossDeadFlag.h"
#include "IsetBurnEffect.h"
using namespace std;

enum BossManage_Status{
	BMStatus_OpeningEvent,
	BMStatus_Fighting,
	BMStatus_EndingEvent,
	BMStatus_End,
	BMStatus_None
};

class BossManage : public TaskBase, public ISetBoss, public IGetBoss, public IGetBossEventNow{
private:
	vector<Boss*> boss;
	BossManage_Status status;
	int count;

	BossEventManage* bossEventManage;
	BossAttackManage* bossAttackManage;

	ISetSelifBox* isetSelifBox;
	ISetTextEffect* isetTextEffect;
	ISetBullet* isetBullet;
	ISetEnemyLazer* isetLazer;
	ISetBulletInvalid* isetBulletInvalid;
	ISetItem* isetItem;
	ISetNextStage* isetNextStage;
	IGetPosition* igetPlayerPosition;
	IGetStage* igetStage;
	ISetBurnEffect* isetBurnEffect;

	ISetBossPracticeBossDeadFlag* isetBossPracticeBossDeadFlag;//BossPractice‚Ì‚Ý

	bool isBossPractice;

	void setBeginBossEndEvent();

public:
	BossManage(ISetSelifBox* isetSelifBox, ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, ISetNextStage* isetNextStage, ISetBurnEffect* isetBurnEffect, int playerMode);//Film
	BossManage(ISetSelifBox* isetSelifBox, ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, ISetNextStage* isetNextStage, ISetBurnEffect* isetBurnEffect, int playerMode);//Extra
	BossManage(ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, int stageNum, int difficulty, int attackNum, ISetBossPracticeBossDeadFlag* isetBossPracticeBossDeadFlag, ISetBurnEffect* isetBurnEffect, int playerMode);//BossPractice
	~BossManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setStaticBossEventData(StaticBossEventData dat,bool isStartEvent);

	void isetBeginBossStartEvent() override;

	int igetBossSize() override;
	Boss* igetBoss(int vectorIndex) override;

	bool igetBossEventNow() override;
	bool igetBossFightingNow() override;

	BossManage_Status getBossManageStatus(){ return this->status; }
	int getBossVectorSizeMax(){ return this->boss.size(); }
	void clearAll();

	void damaged(int id, double damage){ this->boss[id]->damaged(damage); }

	bool isBossAttackingNow();
};

#endif