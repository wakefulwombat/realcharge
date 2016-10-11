#ifndef _BOMB_
#define _BOMB_

#include "mover.h"

class Bomb : public Mover{
private:
	bool isMove;
public:
	Bomb(Point position,double trans_rad,bool isMove);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setInvalid(){ this->validated = false; };
};

#endif