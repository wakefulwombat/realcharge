#ifndef _COLLAPSAR_
#define _COLLAPSAR_

#include "objectBase.h"

class Collapsar : public ObjectBase{
private:

public:
	Collapsar(Point pos);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif