#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include "IsetNextScene.h"
#include "IgameQuit.h"
#include "sceneBase.h"
#include "taskBase.h"
#include "IsetDifficulty.h"
#include "igetGameClearData.h"
#include "isetGameClearData.h"


struct GameClearData{
	bool isClearedStage[3][3];
	bool isClearedStageEX[3];
	bool isClearedBossSpellStage1[4][3][3];
	bool isClearedBossSpellStage2[6][3][3];
	bool isClearedBossSpellStage3[6][3][3];
	bool isClearedBossSpellStage4[8][3][3];
	bool isClearedBossSpellStage5[8][3][3];
	bool isClearedBossSpellStage6[8][3][3];
	bool isClearedBossSpellStageEx[18][3];
};


class SceneManager : public TaskBase, public ISetNextScene, public IGameQuit, public ISetDifficulty, public IGetGameClearData, public ISetGameClearData{
private:
	SceneBase* sceneNow;
	SceneKind nextScene;
	bool quit;
	bool doesStartFromBoss;
	bool isNoContinue;
	int selectDifficultyNum, selectStageNum, selectModeNumEX, selectBossAttackNum;

	GameClearData gameClearData;
	void loadGameClearData();

public:
	SceneManager();
	~SceneManager();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetNextScene(SceneKind nextScene) override;

	void igameQuit() override;
	bool getQuit();

	void isetDifficulty(int difficulty) override { this->selectDifficultyNum = difficulty; }
	void isetStageNum(int stageNum) override { this->selectStageNum = stageNum; }
	void isetModeEX(int mode) override { this->selectModeNumEX = mode; }
	void isetRetryFromBossBattle(bool flag) override { this->doesStartFromBoss = flag; }
	void isetBossAttackNum(int attackNum) override { this->selectBossAttackNum = attackNum; }

	bool igetStageClearData(int difficulty, int mode) override;
	bool igetStageEXClearData(int mode) override;
	bool igetBossAttackClearData(int stageNum, int difficulty, int attackNum) override;
	bool igetBossAttackClearDataDetail(int stageNum, int difficulty, int attackNum, int mode) override;

	void isetStageClearData(int difficulty, int mode) override;
	void isetStageEXClearData(int mode) override;
	void isetBossAttackClearData(int stageNum, int difficulty, int attackNum, int mode) override;
	void isetNoContinueFlag(bool flag) override { this->isNoContinue = flag; }
	bool igetNoContinueFlag() override { return this->isNoContinue; }
};

#endif