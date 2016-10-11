#include "sceneManager.h"
#include "sceneEnding.h"
#include "sceneGameExtraSelectMode.h"
#include "sceneGameExtra.h"
#include "sceneGameFilm.h"
#include "sceneKeyConfig.h"
#include "sceneMusicRoom.h"
#include "sceneOpening.h"
#include "sceneSelectDifficulty.h"
#include "sceneSelectPracticeStage.h"
#include "sceneStagePractice.h"
#include "sceneSelectBossPractice.h"
#include "sceneBossPractice.h"
#include "music.h"
#include "sound.h"

SceneManager::SceneManager(){
	this->nextScene = Scene_None;
	this->sceneNow = new SceneOpening(this,this);
	//this->sceneNow = new SceneGameFilm(this,this,2,4);
	this->quit=false;
	this->doesStartFromBoss = false;
	this->isNoContinue = true;
	Music::playMusic(Music_Opening);
	this->loadGameClearData();
}

SceneManager::~SceneManager(){
	delete this->sceneNow;
}

void SceneManager::initialize(){
	this->sceneNow->initialize();
}

void SceneManager::update(){
	if (this->nextScene != Scene_None){
		this->sceneNow->finalize();
		delete this->sceneNow;
		switch (this->nextScene){
		case Scene_Opening:
			this->sceneNow = new SceneOpening(this, this);
			break;

		case Scene_SelectDifficulty:
			this->sceneNow = new SceneSelectDifficulty(this, this, this);
			break;

		case Scene_GameFilm:
			this->sceneNow = new SceneGameFilm(this, this, this->selectDifficultyNum, this->selectModeNumEX, this->selectStageNum, this->doesStartFromBoss, this);
			this->doesStartFromBoss = false;
			break;

		case Scene_Ending:
			this->sceneNow = new SceneEnding(this);
			break;

		case Scene_MusicRoom:
			this->sceneNow = new SceneMusicRoom(this);
			break;

		case Scene_KeyConfig:
			this->sceneNow = new SceneKeyConfig(this);
			break;

		case Scene_SelectModeExtra:
			this->sceneNow = new SceneGameExtraSelectMode(this, this, this);
			break;

		case Scene_GameExtra:
			this->sceneNow = new SceneGameExtra(this, this->selectModeNumEX, this->doesStartFromBoss, this, this);
			this->doesStartFromBoss = false;
			break;

		case Scene_SelectBossPractice:
			this->sceneNow = new SceneSelectBossPractice(this, this, this);
			break;

		case Scene_BossPractice:
			this->sceneNow = new SceneBossPractice(this, this->selectStageNum, this->selectDifficultyNum, this->selectBossAttackNum, this->selectModeNumEX, this);
			break;

		case Scene_StagePractice:
			this->sceneNow = new SceneStagePractice(this, this, this->selectDifficultyNum, this->selectStageNum,this->selectModeNumEX);
			break;

		case Scene_SelectPracticeStage:
			this->sceneNow = new SceneSelectPracticeStage(this, this);
			break;

		}
		this->nextScene = Scene_None;
		this->sceneNow->initialize();
	}

	this->sceneNow->update();
	Sound::PlayAll();
}

void SceneManager::draw(){
	this->sceneNow->draw();
}

void SceneManager::finalize(){
	this->sceneNow->finalize();
}

void SceneManager::loadGameClearData(){
	FILE* fp;
	if ((fp = fopen("record.dat", "rb")) == NULL){
		for (int i = 0; i < 3; i++){
			for (int k = 0; k < 3; k++){
				for (int j = 0; j < 4; j++) this->gameClearData.isClearedBossSpellStage1[j][i][k] = false;
				for (int j = 0; j < 6; j++) this->gameClearData.isClearedBossSpellStage2[j][i][k] = false;
				for (int j = 0; j < 6; j++) this->gameClearData.isClearedBossSpellStage3[j][i][k] = false;
				for (int j = 0; j < 8; j++) this->gameClearData.isClearedBossSpellStage4[j][i][k] = false;
				for (int j = 0; j < 8; j++) this->gameClearData.isClearedBossSpellStage5[j][i][k] = false;
				for (int j = 0; j < 8; j++) this->gameClearData.isClearedBossSpellStage6[j][i][k] = false;
				this->gameClearData.isClearedStage[i][k] = false;
			}
		}
		for (int j = 0; j < 3; j++) this->gameClearData.isClearedStageEX[j] = false;
		for (int k = 0; k < 3; k++) for (int j = 0; j < 18; j++) this->gameClearData.isClearedBossSpellStageEx[j][k] = false;
	}
	else{
		for (int i = 0; i < 3; i++) fread(&this->gameClearData.isClearedStage[i], sizeof(bool), 1, fp);
		for (int i = 0; i < 3; i++) fread(&this->gameClearData.isClearedStageEX[i], sizeof(bool), 1, fp);
		for (int k = 0; k < 3; k++){
			for (int i = 0; i < 3; i++){
				for (int j = 0; j < 4; j++) fread(&this->gameClearData.isClearedBossSpellStage1[j][i][k], sizeof(bool), 1, fp);
				for (int j = 0; j < 6; j++) fread(&this->gameClearData.isClearedBossSpellStage2[j][i][k], sizeof(bool), 1, fp);
				for (int j = 0; j < 6; j++) fread(&this->gameClearData.isClearedBossSpellStage3[j][i][k], sizeof(bool), 1, fp);
				for (int j = 0; j < 8; j++) fread(&this->gameClearData.isClearedBossSpellStage4[j][i][k], sizeof(bool), 1, fp);
				for (int j = 0; j < 8; j++) fread(&this->gameClearData.isClearedBossSpellStage5[j][i][k], sizeof(bool), 1, fp);
				for (int j = 0; j < 8; j++) fread(&this->gameClearData.isClearedBossSpellStage6[j][i][k], sizeof(bool), 1, fp);
			}
			for (int i = 0; i < 18; i++) fread(&this->gameClearData.isClearedBossSpellStageEx[i][k], sizeof(bool), 1, fp);
		}
		fclose(fp);
	}
}

void SceneManager::isetNextScene(SceneKind nextScene){
	this->nextScene = nextScene;
}

void SceneManager::igameQuit(){
	this->quit = true;
}

bool SceneManager::getQuit(){
	return this->quit;
}

bool SceneManager::igetStageClearData(int difficulty, int mode){
	if (difficulty < 0) return false;
	if (difficulty > 2) return false;
	return this->gameClearData.isClearedStage[difficulty][mode];
}

bool SceneManager::igetStageEXClearData(int mode){
	if (mode < 0) return false;
	if (mode > 2) return false;
	return this->gameClearData.isClearedStageEX[mode];
}

bool SceneManager::igetBossAttackClearData(int stageNum, int difficulty, int attackNum){
	if (difficulty < 0) return false;
	if (difficulty > 2) return false;
	if (stageNum < 0) return false;
	if (stageNum > 7) return false;
	if (attackNum < 0) return false;

	if (stageNum == 0) return ((this->gameClearData.isClearedBossSpellStage1[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage1[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage1[attackNum][difficulty][2] == true));
	else if (stageNum == 1) return ((this->gameClearData.isClearedBossSpellStage2[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage2[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage2[attackNum][difficulty][2] == true));
	else if (stageNum == 2) return ((this->gameClearData.isClearedBossSpellStage3[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage3[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage3[attackNum][difficulty][2] == true));
	else if (stageNum == 3) return ((this->gameClearData.isClearedBossSpellStage4[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage4[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage4[attackNum][difficulty][2] == true));
	else if (stageNum == 4) return ((this->gameClearData.isClearedBossSpellStage5[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage5[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage5[attackNum][difficulty][2] == true));
	else if (stageNum == 5) return ((this->gameClearData.isClearedBossSpellStage6[attackNum][difficulty][0] == true) && (this->gameClearData.isClearedBossSpellStage6[attackNum][difficulty][1] == true) && (this->gameClearData.isClearedBossSpellStage6[attackNum][difficulty][2] == true));
	else if (stageNum == 6) return ((this->gameClearData.isClearedBossSpellStageEx[attackNum][0] == true) && (this->gameClearData.isClearedBossSpellStageEx[attackNum][1] == true) && (this->gameClearData.isClearedBossSpellStageEx[attackNum][2] == true));

	return false;
}

bool SceneManager::igetBossAttackClearDataDetail(int stageNum, int difficulty, int attackNum, int mode){
	if (difficulty < 0) return false;
	if (difficulty > 2) return false;
	if (stageNum < 0) return false;
	if (stageNum > 7) return false;
	if (attackNum < 0) return false;
	if (mode < 0) return false;
	if (mode > 2) return false;

	if (stageNum == 0) return this->gameClearData.isClearedBossSpellStage1[attackNum][difficulty][mode];
	else if (stageNum == 1) return this->gameClearData.isClearedBossSpellStage2[attackNum][difficulty][mode];
	else if (stageNum == 2) return this->gameClearData.isClearedBossSpellStage3[attackNum][difficulty][mode];
	else if (stageNum == 3) return this->gameClearData.isClearedBossSpellStage4[attackNum][difficulty][mode];
	else if (stageNum == 4) return this->gameClearData.isClearedBossSpellStage5[attackNum][difficulty][mode];
	else if (stageNum == 5) return this->gameClearData.isClearedBossSpellStage6[attackNum][difficulty][mode];
	else if (stageNum == 6) return this->gameClearData.isClearedBossSpellStageEx[attackNum][mode];

	return false;
}

void SceneManager::isetStageClearData(int difficulty, int mode){
	if (difficulty < 0) return;
	if (difficulty > 2) return;
	this->gameClearData.isClearedStage[difficulty][mode] = true;

	FILE* fp = fopen("record.dat", "wb");
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStage[i], sizeof(bool), 1, fp);
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStageEX[i], sizeof(bool), 1, fp);
	for (int k = 0; k < 3; k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 4; j++) fwrite(&this->gameClearData.isClearedBossSpellStage1[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage2[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage3[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage4[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage5[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage6[j][i][k], sizeof(bool), 1, fp);
		}
		for (int i = 0; i < 18; i++) fwrite(&this->gameClearData.isClearedBossSpellStageEx[i][k], sizeof(bool), 1, fp);
	}
	fclose(fp);
}

void SceneManager::isetStageEXClearData(int mode){
	if (mode < 0) return;
	if (mode > 2) return;
	this->gameClearData.isClearedStageEX[mode] = true;

	FILE* fp = fopen("record.dat", "wb");
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStage[i], sizeof(bool), 1, fp);
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStageEX[i], sizeof(bool), 1, fp);
	for (int k = 0; k < 3; k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 4; j++) fwrite(&this->gameClearData.isClearedBossSpellStage1[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage2[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage3[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage4[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage5[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage6[j][i][k], sizeof(bool), 1, fp);
		}
		for (int i = 0; i < 18; i++) fwrite(&this->gameClearData.isClearedBossSpellStageEx[i][k], sizeof(bool), 1, fp);
	}
	fclose(fp);
}

void SceneManager::isetBossAttackClearData(int stageNum, int difficulty, int attackNum, int mode){
	if (difficulty < 0) return;
	if (difficulty > 2) return;
	if (stageNum < 0) return;
	if (stageNum > 7) return;
	if (attackNum < 0) return;

	if (stageNum == 0) this->gameClearData.isClearedBossSpellStage1[attackNum][difficulty][mode] = true;
	else if (stageNum == 1) this->gameClearData.isClearedBossSpellStage2[attackNum][difficulty][mode] = true;
	else if (stageNum == 2) this->gameClearData.isClearedBossSpellStage3[attackNum][difficulty][mode] = true;
	else if (stageNum == 3) this->gameClearData.isClearedBossSpellStage4[attackNum][difficulty][mode] = true;
	else if (stageNum == 4) this->gameClearData.isClearedBossSpellStage5[attackNum][difficulty][mode] = true;
	else if (stageNum == 5) this->gameClearData.isClearedBossSpellStage6[attackNum][difficulty][mode] = true;
	else if (stageNum == 6) this->gameClearData.isClearedBossSpellStageEx[attackNum][mode] = true;

	FILE* fp = fopen("record.dat", "wb");
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStage[i], sizeof(bool), 1, fp);
	for (int i = 0; i < 3; i++) fwrite(&this->gameClearData.isClearedStageEX[i], sizeof(bool), 1, fp);
	for (int k = 0; k < 3; k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 4; j++) fwrite(&this->gameClearData.isClearedBossSpellStage1[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage2[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 6; j++) fwrite(&this->gameClearData.isClearedBossSpellStage3[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage4[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage5[j][i][k], sizeof(bool), 1, fp);
			for (int j = 0; j < 8; j++) fwrite(&this->gameClearData.isClearedBossSpellStage6[j][i][k], sizeof(bool), 1, fp);
		}
		for (int i = 0; i < 18; i++) fwrite(&this->gameClearData.isClearedBossSpellStageEx[i][k], sizeof(bool), 1, fp);
	}
	fclose(fp);
}