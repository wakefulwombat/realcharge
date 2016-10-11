#ifndef _OBJECTBASE_
#define _OBJECTBASE_

#include "common.h"
#include "taskBase.h"

class ObjectBase : public TaskBase{
protected:
	Point position;
	Size size;
	int count;
	bool visible,validated;
	int transparency;

public:
	ObjectBase();
	virtual ~ObjectBase(){};

	virtual void initialize() override {}
	virtual void update() override;
	virtual void draw() override;
	virtual void finalize() override {}
	bool getValidate(){return this->validated;}
	Point getPosition(){return this->position;}
	Size getSize(){return this->size;}
};

#endif