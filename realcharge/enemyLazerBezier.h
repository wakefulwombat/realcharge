#ifndef _ENEMYLAZERBEZIER_
#define _ENEMYLAZERBEZIER_

#include "enemyLazerBase.h"

struct BezierInfo{
	Point start, control1, end;
	int arriveTime;
};

class EnemyLazerBezier : public EnemyLazerBase{
private:
	BezierInfo bezierInfo;

	Point getBezierNextPos(int count);
public:
	EnemyLazerBezier(BezierInfo info, BulletColor color, int maxDivNum, int disappTime_min = 20);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX) override;
	void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX, Point bossPos) override;
};

#endif