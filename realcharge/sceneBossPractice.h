#ifndef _SCENEBOSSPRACTICE_
#define _SCENEBOSSPRACTICE_

#include "sceneBase.h"
#include "board.h"
#include "playerEX.h"
#include "playerBulletManagerEX.h"
#include "itemManage.h"
#include "textEffectManage.h"
#include "numericalBarManage.h"
#include "backEffectManage.h"
#include "scenePause.h"
#include "scenePlayerDead.h"
#include "burnEffectManage.h"
#include "bossManage.h"
#include "player.h"
#include "enemyBulletManageEX.h"
#include "shockWaveManage.h"
#include "collapsarManage.h"
#include "bombManage.h"
#include "isetBossPracticeBossDeadFlag.h"
#include "isetGameClearData.h"

class SceneBossPractice : public SceneBase, public IGetStage, public ISetBossPracticeBossDeadFlag{
private:
	bool isPausing;
	bool isDied;
	bool isBossDead;
	int afterBossDeadCount;

	int selectedMode;
	int selectedStageNum;
	int selectedDifficulty;
	int selectedAttackNum;

	Board* board;
	ItemManage* itemManage;
	TextEffectManage* textEffectManage;
	NumericalBarManage* numericalBarManage;
	BackEffectManage* backEffectManage;
	BurnEffectManage* burnEffectManage;
	BossManage* bossManage;
	ScenePause* scenePause;
	ScenePlayerDead* scenePlayerDead;
	PlayerEX* player;

	PlayerBulletManagerEX* playerBulletManage;

	EnemyBulletManageEX* enemyBulletManage;
	ShockWaveManage* shockWaveManage;
	BombManage* bombManage;
	CollapsarManage* collapsarManage;

	ISetGameClearData* isetGameClearData;

	bool isHitPointSquare(Point p_point, Point sq_center, Size sq_size);
	bool isHitPointCircle(Point p_point, Point ci_center, double r);
	bool isHitSquareSquare(Point center1, Size size1, Point center2, Size size2);
	bool isHitCircleCircle(Point center1, double r1, Point center2, double r2);

	void hitCheckAllObject_Stand();
	void hitCheckAllObject_Explode();
	void hitCheckAllObject_Absorb();

public:
	SceneBossPractice(ISetNextScene* changer, int stageNum, int difficulty, int attackNum, int mode, ISetGameClearData* isetGameClearData);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int igetStage() override { return (this->selectedStageNum + 1); }
	int igetDifficulty() override { return this->selectedDifficulty; }
	void isetPauseInvalid() override { this->isPausing = false; }

	void isetBossPracticeBossDeadFlag() override { this->isBossDead = true; }
};

#endif