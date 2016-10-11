#ifndef _ENEMYMANAGE_
#define _ENEMYMANAGE_

#include "taskBase.h"
#include "enemy.h"
#include "IsetBarrage.h"
#include "IsetItem.h"
#include "IgetEnemyInfomation.h"
#include "IaddBeatedCount.h"
#include "IsetBoss.h"
#include "IgetBossEventNow.h"
#include "IsetBulletInvalid.h"
#include "IsetBurnEffect.h"
#include "IsetBackEffect.h"
#include <vector>
using namespace std;

class EnemyManage : public TaskBase,public IGetEnemyInfomation{
private:
	int count;
	int stageNumStartFromBoss;
	vector<Enemy*> enemy;
	vector<StaticEnemyData> enemyCSV;
	ISetBarrage* isetBarrage;
	ISetItem* isetItem;
	IGetPosition* igetPlayerPosition;
	IAddBeatedCount* iaddBeatedCount;
	ISetBoss* isetBoss;
	IGetBossEventNow* igetBossEventNow;
	ISetBulletInvalid* isetBulletInvalid;
	ISetBurnEffect* isetBurnEffect;
	ISetBackEffect* isetBackEffect;

public:
	EnemyManage(ISetBarrage* isetBarage, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IAddBeatedCount* iaddBeatedCount, ISetBoss* isetBoss, IGetBossEventNow* igetBossEventNow, ISetBulletInvalid* isetBulletInvalid, ISetBurnEffect* isetBurnEffect, ISetBackEffect* isetBackEffect, int stageNumStartFromBoss = -1);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void clearBossStartFlag(){ this->stageNumStartFromBoss = -1; }

	int igetEnemyNum() override;
	Point igetEnemyPosition(int CSVindex) override;
	Point igetEnemyPositionVectorIndex(int vectorIndex) override;

	void clearEnemyDataList();
	void setStaticEnemyData(StaticEnemyData staticEnemyData);
	
	IGetPosition* getEnemyPosition(int vectorIndex);
	Size getEnemySize(int vectorIndex);
	int getEnemyVectorSizeMax();
	void setEnemyInvalid(int vectorIndex);
	ISetEnemyDamage* getISetEnemyDamage(int vectorIndex);
	bool getValidate(int vectorindex){ return this->enemy[vectorindex]->getValidate(); }

	void damaged(int vectorIndex, double damage, bool isBurnEffect, double expand);
};

#endif