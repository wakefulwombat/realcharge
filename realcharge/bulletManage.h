#ifndef _BULLETMANAGE_
#define _BULLETMANAGE_

#include "taskBase.h"
#include "IsetBullet.h"
#include "bulletBase.h"
#include "IsetBulletInvalid.h"
#include "IsetBurnEffect.h"
#include <vector>
using namespace std;

class BulletManage : public TaskBase,public ISetBullet,public ISetBulletInvalid{
private:
	vector<BulletBase*> bullet;
	int clearingTimeCount;
	int clearingTime;
	bool isClearing;
	Point clearingCenter;

	ISetBurnEffect* isetBurnEffect;

public:
	BulletManage(ISetBurnEffect* isetBurnEffect);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetBullet(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0,ISetBullet* isetBullet) override;
	void isetBossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0) override;
	
	int getBulletVectorSizeMax();
	Point getBulletPosition(int vectorIndex);
	Size getBulletSize(int vectorIndex);
	void setInvalid(int vectorIndex);
	bool getValid(int vectorIndex);
	BulletBase* getBullet(int vectorIndex){ return this->bullet[vectorIndex]; }

	void isetBulletInvalid(int vectorIndex) override;
	void isetBulletInvalidAll(Point center, int validTime) override;
	void isetInvalidSubrange(Point center, double r) override {};
	void isetLazerInvalid(int vectorIndex) override {}
	void isetInvalidAll(Point center, int validTime) override {}
};

#endif