#ifndef _BOSSBULLET_
#define _BOSSBULLET_

#include "bulletBase.h"
#include "common.h"
#include "IgetPosition.h"

class BossBullet : public BulletBase{
private:
	BulletKind kind;
	BulletColor color;
	double trans_vel, trans_acc, trans_rad, rotate_rad, rotate_vel;
	int movePattern;
	int disappearTime_min;//ï\é¶Ç≥ÇÍÇÈç≈í·éûä‘
	double param1, param2, param3;
	ISetBullet* isetBullet;
	IGetPosition* igetPlayerPosition;

	void move();

public:
	BossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif