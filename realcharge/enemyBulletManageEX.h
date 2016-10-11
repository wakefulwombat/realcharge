#ifndef _ENEMYBULLETMANAGEEX_
#define _ENEMYBULLETMANAGEEX_

#include "taskBase.h"
#include "IsetBullet.h"
#include "isetEnemyLazer.h"
#include "isetStandBulletEX.h"
#include "bulletBase.h"
#include "isetBulletInvalid.h"
#include "IsetBurnEffect.h"
#include "isetStandShockLazerEX.h"
#include "igetIsColding.h"
#include "IgetBoss.h"
#include "IgetBossEventNow.h"
#include <vector>
using namespace std;

class EnemyBulletManageEX : public TaskBase, public ISetBullet, public ISetBulletInvalid, public ISetEnemyLazer, public ISetStandBulletEX{
private:
	vector<BulletBase*> bullet;
	vector<EnemyLazerBase*> lazer;

	int clearingTimeCount;
	int clearingTime;
	bool isClearing;
	Point clearingCenter;

	Point coldingCenter;
	int coldingRadius;

	ISetBurnEffect* isetBurnEffect;
	ISetStandShockLazerEX* isetStandShockLazerEX;
	IGetIsColding* igetIsColding;
	IGetBoss* igetBoss;
	IGetBossEventNow* igetBossEventNow;

public:
	EnemyBulletManageEX();
	void initialize() override;
	void initialize(ISetBurnEffect* isetBurnEffect, ISetStandShockLazerEX* isetStandShockLazerEX, IGetIsColding* igetIsColding, IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow);
	void update() override;
	void draw() override;
	void finalize() override;

	void isetBullet(StaticBulletData* bulletData, Point position, double trans_vel0, double trans_acc0, double trans_rad0, double rotate_vel0, double rotate_acc0, double rotate_rad0, ISetBullet* isetBullet) override;
	void isetBossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0) override;
	void isetEnemyLazer(Point start, BulletColor color, int movePattern, int maxDivNum, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0) override;
	void isetEnemyLazerBezier(BezierInfo info, BulletColor color, int maxDivNum, int disappTime_min = 20) override;

	int getBulletVectorSizeMax() { return this->bullet.size(); }
	Point getBulletPosition(int vectorIndex) { return this->bullet[vectorIndex]->getPosition(); }
	Size getBulletSize(int vectorIndex) { return this->bullet[vectorIndex]->getSize(); }
	void setBulletInvalid(int vectorIndex) { this->bullet[vectorIndex]->setInvalid(); }
	bool getBulletValid(int vectorIndex) { return this->bullet[vectorIndex]->getValidate(); }
	BulletBase* getBullet(int vectorIndex){ return this->bullet[vectorIndex]; }
	int getBulletCount(int vectorIndex){ return this->bullet[vectorIndex]->getCount(); }

	int getLazerVectorSizeMax() { return this->lazer.size(); }
	int getLazerDivVectorSizeMax(int lazerVectorIndex){ return this->lazer[lazerVectorIndex]->getLazerDivSize(); }
	Point getLazerDivPosition(int lazerVectorIndex, int divVectorindex) { return this->lazer[lazerVectorIndex]->getLazerDivPosition(divVectorindex); }
	Size getLazerSize(int vectorIndex) { return this->lazer[vectorIndex]->getSize(); }
	void setLazerDivInvalid(int lazerVectorIndex, int divVectorindex) { this->lazer[lazerVectorIndex]->setLazerDivInvalid(divVectorindex); }
	bool getLazerDivValid(int lazerVectorIndex, int divVectorindex) { return this->lazer[lazerVectorIndex]->getLazerDivValid(divVectorindex); }

	void isetBulletInvalid(int vectorIndex) override { this->bullet[vectorIndex]->setInvalid(); }
	void isetLazerInvalid(int vectorIndex) override { this->lazer[vectorIndex]->setInvalid(); }
	void isetInvalidAll(Point center, int validTime) override;//弾、レーザーすべてを消す
	void isetBulletInvalidAll(Point center, int validTime) override;
	void isetInvalidSubrange(Point center, double r) override;

	void isetBulletStop(Point center, int r) override;
	void isetBulletFlex(Point center, int r) override;
	void isetBulletClearAfterStop() override;
};

#endif