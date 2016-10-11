#ifndef _SCENESTAGEPRACTICE_
#define _SCENESTAGEPRACTICE_

#include "sceneBase.h"
#include "scenePause.h"
#include "board.h"
#include "playerEX.h"
#include "enemyManage.h"
#include "itemManage.h"
#include "burnEffectManage.h"
#include "backEffectManage.h"
#include "numericalBarManage.h"
#include "selifBoxManage.h"
#include "shockWaveManage.h"
#include "bombManage.h"
#include "barrageManage.h"
#include "textEffectManage.h"
#include "bossManage.h"
#include "IgetStage.h"
#include "IsetNextStage.h"
#include "isetGameClearData.h"
#include "playerBulletManagerEX.h"
#include "enemyBulletManageEX.h"
#include "collapsarManage.h"

class SceneStagePractice : public SceneBase, public IGetStage, public ISetNextStage{
private:
	int difficultyNum,stageNum,modeNum;
	bool isPausing;
	bool isWaitingNextStage;
	ISetDifficulty* isetDifficulty;

	Board* board;
	ItemManage* itemManage;
	EnemyManage* enemyManage;
	TextEffectManage* textEffectManage;
	NumericalBarManage* numericalBarManage;
	BackEffectManage* backEffectManage;
	BurnEffectManage* burnEffectManage;
	SelifBoxManage* selifBoxManage;
	BarrageManage* barrageManage;
	BossManage* bossManage;
	ScenePause* scenePause;
	PlayerEX* player;

	PlayerBulletManagerEX* playerBulletManage;

	EnemyBulletManageEX* enemyBulletManage;
	ShockWaveManage* shockWaveManage;
	BombManage* bombManage;
	CollapsarManage* collapsarManage;

	void loadEnemyCSV();
	void loadBarrageCSV();
	void loadBossEventCSV(bool isStartEvent);
	bool isHitPointSquare(Point p_point, Point sq_center, Size sq_size);
	bool isHitPointCircle(Point p_point, Point ci_center, double r);
	bool isHitSquareSquare(Point center1, Size size1, Point center2, Size size2);
	bool isHitCircleCircle(Point center1, double r1, Point center2, double r2);
	
	void hitCheckAllObject_Stand();
	void hitCheckAllObject_Explode();
	void hitCheckAllObject_Absorb();

public:
	SceneStagePractice(ISetNextScene* changer, ISetDifficulty* isetDifficulty, int difficultyNum, int stageNum, int mode);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void loadStage();

	int igetStage() override { return this->stageNum; }
	int igetDifficulty() override { return this->difficultyNum; }
	void isetPauseInvalid() override { this->isPausing = false; }

	void isetNextStage() override;
};

#endif