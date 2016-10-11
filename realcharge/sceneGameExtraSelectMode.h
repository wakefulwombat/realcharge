#ifndef _SCENEGAMEEXTRASELECTMODE_
#define _SCENEGAMEEXTRASELECTMODE_

#include "sceneBase.h"
#include "backEffectManage.h"
#include "IsetDifficulty.h"
#include "igetGameClearData.h"

class SceneGameExtraSelectMode : public SceneBase{
private:
	int selectNum;
	BackEffectManage* backEffectManager;
	int bfcount;

	Selection mode[3];

	ISetDifficulty* isetDifficulty;
	IGetGameClearData* igetGameClearData;

public:
	SceneGameExtraSelectMode(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetGameClearData* igetGameClearData);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif