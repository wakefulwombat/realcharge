#ifndef _SCENESELECTPRACTICESTAGE_
#define _SCENESELECTPRACTICESTAGE_

#include "sceneBase.h"
#include "IsetDifficulty.h"
#include "backEffectManage.h"

class SceneSelectPracticeStage : public SceneBase{
private:
	int selectDifficultyNum,selectStageNum,selectModeNum;
	int selectingType;
	ISetDifficulty* isetDifficulty;
	BackEffectManage* backEffectManager;
	int bfCount;

	Selection stage[6],difficulty[3],mode[3];

public:
	SceneSelectPracticeStage(ISetNextScene* changer,ISetDifficulty* isetDifficulty);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif