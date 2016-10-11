#ifndef _BOSSATTACK_
#define _BOSSATTACK_

#include "common.h"
#include "IgetPosition.h"
#include "bullet.h"
#include "IsetBullet.h"
#include "IsetBossInfo.h"
#include "isetEnemyLazer.h"
#include <string>
using namespace std;

class BossAttack{
protected:
	int count;
	int mode;

	IGetPosition* igetPlayerPosition;
	IGetPosition* igetBossPosition;
	ISetBullet* isetBullet;
	ISetBossInfo* isetBossInfo;
	ISetEnemyLazer* isetLazer;

	//コンストラクタで定義する
	int HP_Max_Explode, HP_Max_Stand, HP_Max_Absorb;
	int limitTime;//[flame]=[s]*60
	string attackName;
	Point initialPosition;

	Point moveFrom, moveTo;

	Point getCircleDistanceMovePosition(double r, Point validSquareLeftUp,Point validSquareRightDown);
	Point getSquareRandomMovePosition(Point validSquareLeftUp, Point validSquareRightDown);
	Point getAccelMovePoint(Point from, Point to, int t, int t_max);

public:
	BossAttack(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	BossAttack(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, int mode);
	virtual void move() = 0;
	virtual void attack() = 0;

	int getHPMax();
	int getLimitTime(){ return this->limitTime; }
	string getAttackName(){ return this->attackName; }
	Point getInitialPosition(){ return this->initialPosition; }

	void setBossInfo(ISetBossInfo* isetBossInfo){ this->isetBossInfo = isetBossInfo; }

	bool isTimeUp(){ return (this->count > this->limitTime); }
	bool isAlartTime(){ return ((this->count >= this->limitTime - 180) && (this->count < this->limitTime) && ((this->limitTime - this->count) % 60 == 0)); }
};

#endif