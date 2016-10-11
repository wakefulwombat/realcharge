#ifndef _BACKEFFECT_
#define _BACKEFFECT_

#include "mover.h"

enum BackEffectMoveType{
	BackEffect_Falling,
	BackEffect_EnemyAppear
};

class BackEffect : public Mover{
private:
	int kind;
	double expand;
	BackEffectMoveType type;
	int validTime;

public:
	BackEffect(int kind, Point position, BackEffectMoveType type);
	BackEffect(int kind, Point position, BackEffectMoveType type, int validTime);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif