#ifndef _SCENEGAMEFILM_
#define _SCENEGAMEFILM_

#include "sceneBase.h"
#include "scenePause.h"
#include "scenePlayerDead.h"
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

class SceneGameFilm : public SceneBase, public IGetStage, public ISetNextStage{
private:
	int difficulty,stage;
	bool isPausing;
	bool isDied;
	bool isWaitingNextStage;
	int selectedMode;
	ISetDifficulty* isetDifficulty;
	ISetGameClearData* isetGameClearData;

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

	void loadEnemyCSV();
	void loadBarrageCSV();
	void loadBossEventCSV(bool isStartEvent);
	void prepareNextStage();
	bool isHitPointSquare(Point p_point,Point sq_center,Size sq_size);
	bool isHitPointCircle(Point p_point,Point ci_center,double r);
	bool isHitSquareSquare(Point center1,Size size1,Point center2,Size size2);
	bool isHitCircleCircle(Point center1,double r1,Point center2,double r2);

	void hitCheckAllObject_Stand();
	void hitCheckAllObject_Explode();
	void hitCheckAllObject_Absorb();

public:
	SceneGameFilm(ISetNextScene* changer, ISetDifficulty* isetDifficulty, int difficulty, int mode, int stage, bool doesStartFromBoss, ISetGameClearData* isetGameClearData);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void loadStage();

	int igetStage() override {return this->stage;}
	int igetDifficulty() override { return this->difficulty; }
	void isetPauseInvalid() override { this->isPausing = false; }

	void isetNextStage() override;
};

#endif