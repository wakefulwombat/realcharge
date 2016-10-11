#ifndef _SCENEPAUSE_
#define _SCENEPAUSE_

#include "sceneBase.h"
#include "IsetDifficulty.h"
#include "IgetStage.h"
#include "IsetBackEffect.h"
#include "IgetBossEventNow.h"
#include "isetGameClearData.h"
#include <string>
using namespace std;

class ScenePause : public SceneBase{
private:
	int selectNum;
	int count;
	ISetDifficulty* isetDifficulty;
	IGetStage* igetStage;
	ISetBackEffect* isetBackEffect;
	IGetBossEventNow* igetBossEventNow;
	ISetGameClearData* isetGameClearData;
	string text[5];
	int type;//(0:Film 1:Practice 2:Extra)

public:
	ScenePause(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData, bool isExtra = false);//for Film, Extra
	ScenePause(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect);//for Practice
	ScenePause(ISetNextScene* changer, IGetStage* igetStage, ISetBackEffect* isetBackEffect);//for BossPractice
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif