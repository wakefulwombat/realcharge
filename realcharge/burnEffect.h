#ifndef _BURNEFFECT_
#define _BURNEFFECT_

#include "fixObject.h"

enum BurnEffectColor{
	Burn_Red,
	Burn_Blue,
	Burn_Yellow,
	Burn_Green,
	Burn_WaterBlue,
	Burn_Orange
};

class BurnEffect : public FixObject{
private:
	BurnEffectColor color;
	int animationDistanceTime;
	double expand;
public:
	BurnEffect(BurnEffectColor color,double expand,Point position);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	double getExpand(){ return this->expand; }
	int getCount(){ return this->count; }
};


#endif