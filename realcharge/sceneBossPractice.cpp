#include "sceneBossPractice.h"
#include "music.h"
#include "input.h"
#include "picture.h"
#include "DxLib.h"
#include "sound.h"

SceneBossPractice::SceneBossPractice(ISetNextScene* changer, int stageNum, int difficulty, int attackNum, int mode, ISetGameClearData* isetGameClearData){
	this->isetNextScene = changer;
	this->selectedStageNum = stageNum;
	this->selectedDifficulty = difficulty;
	this->selectedAttackNum = attackNum;
	this->selectedMode = mode;
	this->isetGameClearData = isetGameClearData;

	this->isPausing = false;
	this->isDied = false;
	this->isBossDead = false;
	this->afterBossDeadCount = 0;

	if (selectedMode == 0){//explode
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->bombManage = new BombManage();
		this->textEffectManage = new TextEffectManage();

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->bossManage = new BossManage(this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, stageNum, difficulty, attackNum, this, this->burnEffectManage, 0);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 0);
		this->shockWaveManage = new ShockWaveManage(this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, this->backEffectManage);
		this->scenePause = new ScenePause(changer, this, this->backEffectManage);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->shockWaveManage, this->bombManage, difficulty, true);
	}
	else if (selectedMode == 1){//stand
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->textEffectManage = new TextEffectManage();
		this->playerBulletManage = new PlayerBulletManagerEX();
		this->textEffectManage = new TextEffectManage();

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->bossManage = new BossManage(this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, stageNum, difficulty, attackNum, this, this->burnEffectManage, 1);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 1);
		this->shockWaveManage = new ShockWaveManage(this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, this->backEffectManage);
		this->scenePause = new ScenePause(changer, this, this->backEffectManage);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->playerBulletManage, this->enemyBulletManage, difficulty, true);
	}
	else{//absorb
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->textEffectManage = new TextEffectManage();
		this->textEffectManage = new TextEffectManage();
		this->collapsarManage = new CollapsarManage(difficulty);

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->bossManage = new BossManage(this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, stageNum, difficulty, attackNum, this, this->burnEffectManage, 2);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 2);
		this->shockWaveManage = new ShockWaveManage(this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, this->backEffectManage);
		this->scenePause = new ScenePause(changer, this, this->backEffectManage);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->shockWaveManage, this->collapsarManage, difficulty, true);
	}
}

void SceneBossPractice::initialize(){
	if (this->selectedMode == 0){//explode
		this->player->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->bombManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}
	else if (this->selectedMode == 1){//stand
		this->player->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}
	else{//absorb
		this->player->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->collapsarManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}

	Picture::deletePicture();
	Picture::loadStagePicture();
}

void SceneBossPractice::update(){
	if (this->selectedMode == 0){//explode
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else{
			this->player->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->shockWaveManage->update();
			this->bombManage->update();
			if (this->isBossDead == false) this->bossManage->update();
			this->textEffectManage->update();

			this->hitCheckAllObject_Explode();

			if (this->isBossDead == true){
				this->afterBossDeadCount++;
				if (this->afterBossDeadCount == 360){
					this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetGameClearData->isetBossAttackClearData(this->selectedStageNum, this->selectedDifficulty, this->selectedAttackNum, this->selectedMode);
				}
			}
		}
	}
	else if (this->selectedMode == 1){//stand
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else{
			this->player->update();
			this->playerBulletManage->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->shockWaveManage->update();
			if (this->isBossDead == false) this->bossManage->update();
			this->textEffectManage->update();

			this->hitCheckAllObject_Stand();

			if (this->isBossDead == true){
				this->afterBossDeadCount++;
				if (this->afterBossDeadCount == 360){
					this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetGameClearData->isetBossAttackClearData(this->selectedStageNum, this->selectedDifficulty, this->selectedAttackNum, this->selectedMode);
				}
			}
		}
	}
	else{//absorb
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else{
			this->player->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->shockWaveManage->update();
			if (this->isBossDead == false) this->bossManage->update();
			this->textEffectManage->update();
			this->collapsarManage->update();

			this->hitCheckAllObject_Absorb();

			if (this->isBossDead == true){
				this->afterBossDeadCount++;
				if (this->afterBossDeadCount == 360){
					this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetGameClearData->isetBossAttackClearData(this->selectedStageNum, this->selectedDifficulty, this->selectedAttackNum, this->selectedMode);
				}
			}
		}
	}
}

void SceneBossPractice::draw(){
	if (this->selectedMode == 0){//explode
		this->backEffectManage->draw();
		this->numericalBarManage->draw();
		this->player->draw();
		this->bombManage->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->shockWaveManage->draw();
		this->textEffectManage->draw();
		if (this->isBossDead == false) this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->backEffectManage->draw();
			this->scenePause->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->backEffectManage->draw();
			this->board->draw();
			this->scenePlayerDead->draw();
		}
	}
	else if (this->selectedMode == 1){//stand
		this->backEffectManage->draw();
		this->numericalBarManage->draw();
		this->playerBulletManage->draw();
		this->player->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->shockWaveManage->draw();
		this->textEffectManage->draw();
		if (this->isBossDead == false) this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->scenePause->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->scenePlayerDead->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
	}
	else{
		this->backEffectManage->draw();
		this->collapsarManage->draw();
		this->shockWaveManage->draw();
		this->numericalBarManage->draw();
		this->player->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->textEffectManage->draw();
		if (this->isBossDead == false) this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->scenePause->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->scenePlayerDead->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
	}
}

void SceneBossPractice::finalize(){
	if (this->selectedMode == 0){
		this->player->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->shockWaveManage->finalize();
		this->bombManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->shockWaveManage);
		delete(this->bombManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
	else if (this->selectedMode == 1){
		this->player->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->shockWaveManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();
		this->playerBulletManage->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->shockWaveManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->playerBulletManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
	else{//absorb
		this->player->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->shockWaveManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->shockWaveManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
}

bool SceneBossPractice::isHitPointSquare(Point p_point, Point sq_center, Size sq_size){
	if (p_point.x > sq_center.x - sq_size.width / 2){
		if (p_point.x < sq_center.x + sq_size.width / 2){
			if (p_point.y > sq_center.y - sq_size.height / 2){
				if (p_point.y < sq_center.y + sq_size.height / 2){
					return true;
				}
			}
		}
	}
	return false;
}

bool SceneBossPractice::isHitPointCircle(Point p_point, Point ci_center, double r){
	if (p_point.y - ci_center.y > r) return false;
	if (ci_center.y - p_point.y > r) return false;
	if (p_point.x - ci_center.x > r) return false;
	if (ci_center.x - p_point.x > r) return false;

	return ((p_point.x - ci_center.x)*(p_point.x - ci_center.x) + (p_point.y - ci_center.y)*(p_point.y - ci_center.y) < r*r);
}

bool SceneBossPractice::isHitSquareSquare(Point center1, Size size1, Point center2, Size size2){
	if (center1.x + size1.width / 2 > center2.x - size2.width / 2){
		if (center1.x - size1.width / 2 < center2.x + size2.width / 2){
			if (center1.y + size1.height / 2 > center2.y - size2.height / 2){
				if (center1.y - size1.height / 2 < center2.y + size2.height / 2){
					return true;
				}
			}
		}
	}
	return false;
}

bool SceneBossPractice::isHitCircleCircle(Point center1, double r1, Point center2, double r2){
	if (center1.y - center2.y > r1 + r2) return false;
	if (center2.y - center1.y > r1 + r2) return false;
	if (center1.x - center2.x > r1 + r2) return false;
	if (center2.x - center1.x > r1 + r2) return false;

	return ((center1.x - center2.x)*(center1.x - center2.x) + (center1.y - center2.y)*(center1.y - center2.y) < (r1 + r2)*(r1 + r2));
}

void SceneBossPractice::hitCheckAllObject_Explode(){
	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(2);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(6);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->bombManage->isetBomb(this->itemManage->getPosition(i), 0.0, false);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					for (int j = 0; j < 4; j++){
						this->bombManage->isetBomb(this->itemManage->getPosition(i) + Point(60 * sin(M_PI * 2 * j / 4), 60 * cos(M_PI * 2 * j / 4)), 0.0, false);
					}
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					//this->board->addScore(10);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					//this->board->addScore(40);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//弾と爆風
	for (int bul = 0; bul < this->enemyBulletManage->getBulletVectorSizeMax(); bul++){
		for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
			if (this->enemyBulletManage->getBulletValid(bul) == false)continue;
			if (this->burnEffectManage->getBurnEffectCount(wind) < 7) continue;
			if (this->burnEffectManage->getBurnEffectCount(wind) > 40) continue;

			if (this->isHitPointCircle(this->enemyBulletManage->getBulletPosition(bul), this->burnEffectManage->getBurnEffectPosition(wind), 0.4*this->enemyBulletManage->getBulletSize(bul).width + 0.3*this->burnEffectManage->getBurnEffectExpand(wind)*this->burnEffectManage->getBurnEffectSize(wind).width) == true){
				this->enemyBulletManage->setBulletInvalid(bul);
				//this->board->addScore(10);
				if (this->burnEffectManage->getBurnEffectExpand(wind) > 0.3){
					this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind) / 1.3, this->enemyBulletManage->getBulletPosition(bul), true);
				}
				else{
					this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind), this->enemyBulletManage->getBulletPosition(bul), true);
				}
			}
		}
	}

	//レーザーと爆風
	for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
		for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
			for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
				if (this->enemyBulletManage->getLazerDivValid(l, d) == false) continue;

				if (this->isHitPointCircle(this->enemyBulletManage->getLazerDivPosition(l, d), this->burnEffectManage->getBurnEffectPosition(wind), 0.3*this->burnEffectManage->getBurnEffectExpand(wind)*this->burnEffectManage->getBurnEffectSize(wind).width) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, d);
					//this->board->addScore(10);
					if (this->burnEffectManage->getBurnEffectExpand(wind) > 0.3){
						this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind) / 1.2, this->enemyBulletManage->getLazerDivPosition(l, d), true);
					}
					else{
						this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind), this->enemyBulletManage->getLazerDivPosition(l, d), true);
					}
				}
			}
		}
	}

	//ボムと爆風
	for (int bomb = 0; bomb < this->bombManage->getBombVectorSizeMax(); bomb++){
		for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
			if (this->bombManage->getValid(bomb) == false)continue;

			if (this->isHitPointCircle(this->bombManage->getPosition(bomb), this->burnEffectManage->getBurnEffectPosition(wind), 0.3*this->burnEffectManage->getBurnEffectSize(wind).width*this->burnEffectManage->getBurnEffectExpand(wind))){
				this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), 1.2, this->bombManage->getPosition(bomb), false);
				this->bombManage->setInvalid(bomb);
			}
		}
	}

	//ショックと弾
	for (int b = 0; b < this->enemyBulletManage->getBulletVectorSizeMax(); b++){
		for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
			if (this->enemyBulletManage->getBulletValid(b) == false) break;
			if (this->shockWaveManage->getShockWaveValid(s) == false) continue;

			if (this->isHitPointSquare(this->shockWaveManage->getShockWavePosition(s), this->enemyBulletManage->getBulletPosition(b), this->shockWaveManage->getShockWaveSize(s)) == true){
				this->enemyBulletManage->setBulletInvalid(b);
				//this->board->addScore(10);

				this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), 0.3, this->enemyBulletManage->getBulletPosition(b), false);
				if (this->shockWaveManage->getShockWaveKind(s) == 0){
					this->shockWaveManage->setShockWaveInvalid(s);
				}
			}
		}
	}

	//ショックとレーザー
	for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
		for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
			for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
				if (this->shockWaveManage->getShockWaveValid(s) == false) continue;
				if (this->enemyBulletManage->getLazerDivValid(l, d) == false) break;

				if (this->isHitPointSquare(this->shockWaveManage->getShockWavePosition(s), this->enemyBulletManage->getLazerDivPosition(l, d), this->shockWaveManage->getShockWaveSize(s)) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, d);

					//this->board->addScore(10);
					this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), 0.2, this->enemyBulletManage->getLazerDivPosition(l, d), false);
					if (this->shockWaveManage->getShockWaveKind(s) == 0){
						this->shockWaveManage->setShockWaveInvalid(s);
					}
				}
			}
		}
	}

	//プレイヤーと弾
	if ((this->player->getCharactorStatus() == ChStatus_Normal) || (this->player->getCharactorStatus() == ChStatus_Invincible)){
		if (this->player->isIgnitionReceipting() == true){
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.8*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;
					this->enemyBulletManage->setBulletInvalid(i);

					Sound::playSound(Sound_ignitionGo);
					this->burnEffectManage->isetBurnEffect(Burn_Red, 1.0, this->enemyBulletManage->getBulletPosition(i), false);
					this->player->setIgnitionSuccess();
				}
			}
		}
		else{
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;
					this->enemyBulletManage->setBulletInvalid(i);

					if (this->player->getCharactorStatus() == ChStatus_Normal){
						this->player->die();
						if (this->player->igetPlayerLife() < 0) this->isDied = true;
						Sound::playSound(Sound_playerDead);
					}
				}
			}
		}
	}

	//プレイヤーとレーザー
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		if (this->player->isIgnitionReceipting() == true){
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.6*this->enemyBulletManage->getLazerSize(l).width) == true){
						if (this->enemyBulletManage->getLazerDivValid(l, d) == false) continue;
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						Sound::playSound(Sound_ignitionGo);
						this->burnEffectManage->isetBurnEffect(Burn_Red, 1.0, this->enemyBulletManage->getLazerDivPosition(l, d), false);
						this->player->setIgnitionSuccess();
					}
				}
			}
		}
		else{
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.3*this->enemyBulletManage->getLazerSize(l).width) == true){
						if (this->enemyBulletManage->getLazerDivValid(l, d) == false) continue;
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						this->player->die();
						if (this->player->igetPlayerLife() < 0) this->isDied = true;
						Sound::playSound(Sound_playerDead);
					}
				}
			}
		}
	}


	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスと爆風
	for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
		for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
			if (this->burnEffectManage->getBurnEffectExpand(wind) < 0.2) continue;
			if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->burnEffectManage->getBurnEffectPosition(wind), 0.5*this->burnEffectManage->getBurnEffectExpand(wind)*this->burnEffectManage->getBurnEffectSize(wind).width + this->bossManage->igetBoss(boss)->getSize().width)){
				this->bossManage->damaged(boss, 0.1);
				//this->board->addScore(10);
			}
		}
	}

	//ボスとショック
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
			if (this->isHitSquareSquare(this->shockWaveManage->getShockWavePosition(s), this->shockWaveManage->getShockWaveSize(s), this->bossManage->igetBoss(boss)->getPosition(), this->bossManage->igetBoss(boss)->getSize()) == true){
				this->bossManage->damaged(boss, this->shockWaveManage->getShockWaveAttackPower(s));

				if (this->shockWaveManage->getShockWaveKind(s) == 0){
					this->shockWaveManage->setShockWaveInvalid(s);
				}
			}
		}
	}
}

void SceneBossPractice::hitCheckAllObject_Stand(){
	//プレイヤーと弾
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
			if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
				if (this->enemyBulletManage->getBulletValid(i) == false) continue;

				this->player->die();
				if (this->player->igetPlayerLife() < 0) this->isDied = true;
				Sound::playSound(Sound_playerDead);
			}
		}
	}

	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addBulletPower(5);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addBulletPower(20);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addRecoveringTimeStandStop(50);
					this->player->addBulletPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addRecoveringTimeStandStop(300);
					this->player->addBulletPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					//this->board->addScore(10);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					//this->board->addScore(40);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//プレイヤーとレーザー
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
			for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.35*this->enemyBulletManage->getLazerSize(l).width) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, d);

					this->player->die();
					if (this->player->igetPlayerLife() < 0) this->isDied = true;
					Sound::playSound(Sound_playerDead);
				}
			}
		}
	}

	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスと自機弾
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); ++boss){
		for (int bul = 0; bul < this->playerBulletManage->getBulletSize(); ++bul){
			if (this->playerBulletManage->getValid(bul) == false) continue;

			if (this->isHitPointSquare(this->playerBulletManage->getPosition(bul), this->bossManage->igetBoss(boss)->getPosition(), Size(72, 72)) == true){
				this->bossManage->damaged(boss, this->playerBulletManage->getAttackPower(bul));
				this->playerBulletManage->setInvalid(bul);
			}
		}
	}

	//ボスとショックレーザー
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), 100.0) == true){
					this->bossManage->damaged(boss, this->shockWaveManage->getShockLazerAttackPower(l));
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
				}
			}
		}
	}
}

void SceneBossPractice::hitCheckAllObject_Absorb(){
	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					//this->board->addScore(10);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					//this->board->addScore(40);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//コラプサーと弾
	for (int col = 0; col < this->collapsarManage->getVectorSize(); col++){
		for (int b = 0; b < this->enemyBulletManage->getBulletVectorSizeMax(); b++){
			if (this->enemyBulletManage->getBulletValid(b) == false) continue;

			if (this->isHitPointCircle(this->collapsarManage->getPosition(col), this->enemyBulletManage->getBulletPosition(b), 50) == true){
				this->enemyBulletManage->setBulletInvalid(b);
				//this->board->addScore(10);
				this->player->addChargingPower(1);
			}
		}
	}

	//コラプサーとレーザー
	for (int col = 0; col < this->collapsarManage->getVectorSize(); col++){
		for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); l++){
			for (int div = 0; div < this->enemyBulletManage->getLazerDivVectorSizeMax(l); div++){
				if (this->enemyBulletManage->getLazerDivValid(l, div) == false) continue;

				if (this->isHitPointCircle(this->collapsarManage->getPosition(col), this->enemyBulletManage->getLazerDivPosition(l, div), 60) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, div);
					//this->board->addScore(10);
					this->player->addChargingPower(1);
				}
			}
		}
	}

	//プレイヤーと弾
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		if (this->player->isAbsorbReceipting() == true){
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.8*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;

					this->player->addChargingPower(1);
					this->player->decreaseAbsorbRunnningCount(1);

					this->enemyBulletManage->setBulletInvalid(i);
					Sound::playSound(Sound_ignitionGo);
				}
			}
		}
		else{
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;

					this->player->die();
					if (this->player->igetPlayerLife() < 0) this->isDied = true;
					Sound::playSound(Sound_playerDead);
					this->enemyBulletManage->setBulletInvalid(i);
				}
			}
		}
	}

	//プレイヤーとレーザー
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		if (this->player->isAbsorbReceipting() == true){
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.8*this->enemyBulletManage->getLazerSize(l).width) == true){
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						this->player->addChargingPower(1);
						this->player->decreaseAbsorbRunnningCount(1);
						Sound::playSound(Sound_ignitionGo);
					}
				}
			}
		}
		else{
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.3*this->enemyBulletManage->getLazerSize(l).width) == true){
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						this->player->die();
						if (this->player->igetPlayerLife() < 0) this->isDied = true;
						Sound::playSound(Sound_playerDead);
					}
				}
			}
		}
	}


	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスとショックレーザー
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), 64.0) == true){
					this->bossManage->damaged(boss, this->shockWaveManage->getShockLazerAttackPower(l));
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
				}
			}
		}
	}
}