#ifndef _BACKEFFECTMANAGE_
#define _BACKEFFECTMANAGE_

#include "backEffect.h"
#include "IsetBackEffect.h"
#include "taskBase.h"
#include <list>
using namespace std;

class BackEffectManage : public TaskBase,public ISetBackEffect{
private:
	list<BackEffect*> backEffect;
public:
	BackEffectManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetBackEffect(int kind, Point position) override;
	void isetBackEffect(int kind, Point position, int validTime) override;
	void isetBackEffectClearAll() override;
};

#endif