#ifndef _SCENESELECTDIFFICULTY_
#define _SCENESELECTDIFFICULTY_

#include "sceneBase.h"
#include "IsetDifficulty.h"
#include "backEffectManage.h"
#include "igetGameClearData.h"

class SceneSelectDifficulty : public SceneBase{
private:
	int selecting_type;
	int selectNum_difficulty,selectNum_mode;
	ISetDifficulty* setDifficulty;
	BackEffectManage* backEffectManager;
	IGetGameClearData* igetGameClearData;

	int bfCount;

	Selection difficulty[3], mode[3];

public:
	SceneSelectDifficulty(ISetNextScene* changer, ISetDifficulty* setDifficulty, IGetGameClearData* igetGameClearData);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif