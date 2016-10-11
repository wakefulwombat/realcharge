#ifndef _ENEMY_
#define _ENEMY_

#include "charactor.h"
#include "common.h"
#include "bullet.h"
#include "barrage.h"
#include "IsetBarrage.h"
#include "IsetItem.h"
#include "IsetEnemyDamage.h"
#include "IsetBurnEffect.h"

struct StaticEnemyData{
	int appearTime,disappearTime_min;
	Point startPosition,stopPosition;
	int kind;
	int movePattern,itemPattern;
	int HP_MAX;
	int movingTime,stoppingTime,barrageStartTime[3];
	double move_trans_vel,move_trans_acc,move_trans_rad,move_rotate_vel;
	int barrageDataID[3];
};

class Enemy : public Charactor,ISetEnemyDamage{
private:
	StaticEnemyData* staticData;
	ISetBarrage* isetBarrage;
	ISetItem* isetItem;
	IGetPosition* igetPlayerPosition;
	ISetBurnEffect* isetBurnEffect;

	int CSVIndex;
	double life;

	void adjustTransRad();
	void getDirectionFromTransRad();

	void movePattern();
	void itemPattern();

public:
	Enemy(StaticEnemyData* staticData, int CSVIndex, ISetBarrage* isetBarrage, ISetItem* isetItem, IGetPosition* igetPlayerPosition, ISetBurnEffect* isetBurnEffect);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getCSVIndex(){return this->CSVIndex;};
	void setInvalid();
	double getLife(){ return this->life; };
	void damaged(double decreaceHP, bool isBurnEffect, double expand);
	ISetEnemyDamage* getThis(){ return this; };
	void isetEnemyDamage(int damage, bool isBurnEffect, double expand) override;
};

#endif