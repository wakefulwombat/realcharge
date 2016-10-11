#ifndef _ISETENEMYLAZER_
#define _ISETENEMYLAZER_

#include "common.h"
#include "bulletBase.h"
#include "enemyLazerBezier.h"

class ISetEnemyLazer{
public:
	virtual void isetEnemyLazer(Point start, BulletColor color, int movePattern, int maxDivNum, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0) = 0;
	virtual void isetEnemyLazerBezier(BezierInfo info, BulletColor color, int maxDivNum, int disappTime_min = 20) = 0;
};

#endif