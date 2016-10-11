#ifndef _ISETBULLET_
#define _ISETBULLET_

#include "common.h"
#include "IgetPosition.h"

struct StaticBulletData;
enum BulletKind;
enum BulletColor;

class ISetBullet{
public:
	virtual void isetBullet(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0,ISetBullet* isetBullet)=0;
	virtual void isetBossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0) = 0;
};

#endif