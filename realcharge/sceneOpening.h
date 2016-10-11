#ifndef _SCENEOPENING_
#define _SCENEOPENING_

#include "sceneBase.h"
#include "IgameQuit.h"

class SceneOpening : public SceneBase{
private:
	int selectNumber;
	int textPositionX[7];
	IGameQuit* gameQuit;

	Point titlePos[5];
	int titleCount[5];

public:
	SceneOpening(ISetNextScene* changer,IGameQuit* gameQuit);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif