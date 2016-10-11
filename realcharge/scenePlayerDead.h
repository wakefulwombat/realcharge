#ifndef _SCENEPLAYERDEAD_
#define _SCENEPLAYERDEAD_

#include "sceneBase.h"
#include "IsetDifficulty.h"
#include "IgetStage.h"
#include "IsetBackEffect.h"
#include "IgetBossEventNow.h"
#include "isetGameClearData.h"
#include <string>
using namespace std;

class ScenePlayerDead : public SceneBase{
private:
	int selectNum;
	int count;
	ISetDifficulty* isetDifficulty;
	IGetStage* igetStage;
	ISetBackEffect* isetBackEffect;
	IGetBossEventNow* igetBossEventNow;
	ISetGameClearData* isetGameClearData;
	string text[4];
	int type;//0:Film 1:Extra

public:
	ScenePlayerDead(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData);//Film
	ScenePlayerDead(ISetNextScene* changer, ISetDifficulty* isetDifficulty, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData);//Extra
	ScenePlayerDead(ISetNextScene* changer, ISetBackEffect* isetBackEffect);//BossPractice
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif