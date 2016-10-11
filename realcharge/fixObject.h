#ifndef _FIXOBJECT_
#define _FIXOBJECT_

#include "objectBase.h"

class FixObject : public ObjectBase{
public:
	virtual ~FixObject(){};

	virtual void initialize() override {};
	virtual void update() override {};
	virtual void draw() override {};
	virtual void finalize() override {};
};

#endif