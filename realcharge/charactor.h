#ifndef _CHARACTOR_
#define _CHARACTOR_

#include "mover.h"

enum Direction{
	dir_down,
	dir_left,
	dir_right,
	dir_up,
	dir_leftdown,
	dir_rightdown,
	dir_leftup,
	dir_rightup
};

enum CharactorStatus{
	ChStatus_Normal,
	ChStatus_Dying,
	ChStatus_Recovering,
	ChStatus_Preparing,
	ChStatus_Invincible,
	ChStatus_Waiting
};

class Charactor : public Mover{
protected:
	double chip_rad;
	Direction direction;
	int life;
	CharactorStatus status;
	int animationDistanceTime;//アニメーションの切り替え時間
public:
	Charactor();
	virtual ~Charactor(){};

	virtual void initialize() override {}
	virtual void update() override;
	virtual void draw() override;
	virtual void finalize() override {}
};

#endif