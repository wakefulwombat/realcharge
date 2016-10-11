#ifndef _SCENESELECTBOSSPRACTICE_
#define _SCENESELECTBOSSPRACTICE_

#include "sceneBase.h"
#include "common.h"
#include "backEffectManage.h"
#include "IsetDifficulty.h"
#include "igetGameClearData.h"
#include <string>
using namespace std;

class SceneSelectBossPractice : public SceneBase{
	Selection stage[7];
	Selection level[3];
	Selection spell[18];
	Selection mode[3];

	int selectingType;
	int selectNum_stage;
	int selectNum_level;
	int selectNum_spell;
	int selectNum_mode;
	int spellNumMax;
	string spellName[18];


	int bfCount;
	BackEffectManage* backEffectManager;

	ISetDifficulty* isetDifficulty;
	IGetGameClearData* igetGameClearData;

	void setSpellNumMax();
	void setSpellName();

public:
	SceneSelectBossPractice(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetGameClearData* igetGameClearData);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif