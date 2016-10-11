#ifndef _MOVER_
#define _MOVER_

#include "objectBase.h"
#include "igetPosition.h"

class Mover : public ObjectBase,public IGetPosition{
protected:
	double trans_vel,rotate_vel;
	double trans_rad,rotate_rad;

public:
	virtual ~Mover(){};

	virtual void initialize() override {};
	virtual void update() override {};
	virtual void draw() override {};
	virtual void finalize() override {}
	Point igetPosition() override;
};

#endif