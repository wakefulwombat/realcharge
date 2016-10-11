#ifndef _SHOCKWAVE_
#define _SHOCKWAVE_

#include "Mover.h"
#include "IsetBurnEffect.h"

class ShockWave : public Mover{
private:
	int chipCount;
	int kind;
	double power;

public:
	ShockWave(int power,int kind,Point position,double trans_vel=10.0);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getKind(){ return this->kind; }
	void setInvalid(){ this->validated = false; }
	double getAttackPower(){ return this->power; }

	void makeShockWave();
};

#endif