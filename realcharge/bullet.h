#ifndef _BULLET_
#define _BULLET_

#include "bulletBase.h"

struct StaticBulletData{
	BulletKind kind;
	BulletColor color;
	double trans_vel, trans_acc, trans_rad, rotate_vel, rotate_rad;
	int movePattern;
	int disappearTime_min;//ï\é¶Ç≥ÇÍÇÈç≈í·éûä‘
	double param1, param2, param3;
};

class Bullet : public BulletBase{
private:
	StaticBulletData* bulletData;
	double trans_acc,rotate_acc;
	void move();
public:
	Bullet(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0,ISetBullet* isetBullet);

	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif