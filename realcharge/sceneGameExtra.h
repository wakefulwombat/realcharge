#ifndef _SCENEGAMEEXTRA_
#define _SCENEGAMEEXTRA_

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
#include "selifBoxManage.h"
#include "enemyManage.h"
#include "barrageManage.h"
#include "bossManage.h"
#include "player.h"
#include "enemyBulletManageEX.h"
#include "shockWaveManage.h"
#include "bombManage.h"
#include "collapsarManage.h"
#include "isetGameClearData.h"
#include "IsetDifficulty.h"

class SceneGameExtra : public SceneBase, public IGetStage, public ISetNextStage{
	bool isPausing;
	bool isDied;
	int selectedMode;

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
	ScenePlayerDead* scenePlayerDead;
	PlayerEX* player;

	PlayerBulletManagerEX* playerBulletManage;

	EnemyBulletManageEX* enemyBulletManage;
	ShockWaveManage* shockWaveManage;
	BombManage* bombManage;
	CollapsarManage* collapsarManage;

	ISetGameClearData* isetGameClearData;
		
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
	SceneGameExtra(ISetNextScene* changer, int selectedMode, bool doesStartFromBoss, ISetGameClearData* isetGameClearData, ISetDifficulty* isetDifficulty);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void loadStage();

	int igetStage() override { return 7; }
	int igetDifficulty() override { return 1; }
	void isetPauseInvalid() override { this->isPausing = false; }

	void isetNextStage() override;
};

#endif