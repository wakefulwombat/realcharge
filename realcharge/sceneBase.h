#ifndef _SCENEBASE_
#define _SCENEBASE_

#include "taskBase.h"
#include "IsetNextScene.h"
#include "common.h"

struct Selection{
	Point start, end;
	int count;
};

class SceneBase : public TaskBase{
protected:
	SceneKind nextScene;
	ISetNextScene* isetNextScene;
public:
	virtual ~SceneBase(){};
	virtual void initialize() override {};
	virtual void update() override{};
	virtual void draw() override {};
	virtual void finalize() override{};
};


#endif