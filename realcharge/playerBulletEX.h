#ifndef _PLAYERBULLETEX_
#define _PLAYERBULLETEX_

#include "bulletBase.h"

class PlayerBulletEX : public BulletBase{
private:
	BulletKind kind;
	BulletColor color;
	int movePattern;
	int disappTime_min;
	double trans_acc;
	double attackPower;
public:
	PlayerBulletEX(Point pos, BulletKind kind, BulletColor color, int movePattern, double attackPower, double trans_vel0, double trans_acc, double trans_rad0, int disappTime_min = 0);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	double getAttackPower(){ return this->attackPower; }
};

#endif