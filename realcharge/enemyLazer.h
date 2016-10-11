#ifndef _ENEMYLAZER_
#define _ENEMYLAZER_

#include "enemyLazerBase.h"

class EnemyLazer : public EnemyLazerBase{
private:
	double trans_acc, rotate_acc;
	double param1, param2, param3;
	int movePattern;
	Point start;

	Point getMoveNextPos(Point pos, int count);
public:
	EnemyLazer(Point start, BulletColor color, int movePattern, int maxDivNum, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min = 20, double param1 = 0.0, double param2 = 0.0, double param3 = 0.0);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX) override;
	void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX, Point bossPos) override;
};

#endif