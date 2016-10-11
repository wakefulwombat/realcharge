#include "sceneGameExtraSelectMode.h"
#include "DxLib.h"
#include "picture.h"
#include "input.h"
#include "sound.h"

SceneGameExtraSelectMode::SceneGameExtraSelectMode(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetGameClearData* igetGameClearData){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->igetGameClearData = igetGameClearData;

	this->selectNum = 0;

	this->bfcount = 0;
	this->backEffectManager = new BackEffectManage();

	this->mode[0].start = Point(-300, 200);
	this->mode[0].end = Point(270, 200);
	this->mode[0].count = 0;
	this->mode[1].start = Point(-300, 200);
	this->mode[1].end = Point(670, 200);
	this->mode[1].count = 0;
	this->mode[2].start = Point(-300, 200);
	this->mode[2].end = Point(1070, 200);
	this->mode[2].count = 0;
}

void SceneGameExtraSelectMode::initialize(){

}

void SceneGameExtraSelectMode::update(){
	if (Input::getGridXDownOnce() == 1){
		this->selectNum = (this->selectNum + 1) % 3;
		Sound::playSound(Sound_SelectMove);
		for (int i = 0; i < 3; i++){
			this->mode[i].count = 0;
			this->mode[i].start = this->mode[i].end;
			this->mode[i].end = Point(400 * (i - this->selectNum) + 270, 200);
		}
	}
	if (Input::getGridXDownOnce() == -1){
		this->selectNum = (this->selectNum + 2) % 3;
		Sound::playSound(Sound_SelectMove);
		for (int i = 0; i < 3; i++){
			this->mode[i].count = 0;
			this->mode[i].start = this->mode[i].end;
			this->mode[i].end = Point(400 * (i - this->selectNum) + 270, 200);
		}
	}

	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//Œˆ’è
		this->isetDifficulty->isetModeEX(this->selectNum);
		Sound::playSound(Sound_Decide);
		this->isetNextScene->isetNextScene(Scene_GameExtra);
	}
	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//ƒLƒƒƒ“ƒZƒ‹
		Sound::playSound(Sound_Cancel);
		this->isetNextScene->isetNextScene(Scene_Opening);
	}

	for (int i = 0; i < 3; i++){
		this->mode[i].count++;
	}

	this->bfcount++;
	if (this->bfcount == 10){
		this->bfcount = 0;
		this->backEffectManager->isetBackEffect(GetRand(5), Point(1.0*GetRand(WINDOW_WIDTH), -100.0));
	}
	this->backEffectManager->update();
}

void SceneGameExtraSelectMode::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(0, 0, Picture::getBack(1), false);

	SetDrawBright(255, 255, 255);
	this->backEffectManager->draw();

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(50, 30, Picture::getSelectText(SEL_MODESELECT), true);

	for (int i = 0; i < 3; i++){
		if (this->selectNum == i) SetDrawBright(255, 255, 255);
		else SetDrawBright(100, 100, 100);

		double x, y;
		if (this->mode[i].count < 30){
			x = 2.0*(this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count / 30.0 - (this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.x;
			y = 2.0*(this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count / 30.0 - (this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.y;
		}
		else{
			x = this->mode[i].end.x;
			y = this->mode[i].end.y;
		}

		DrawGraph(x, y, Picture::getPlayerModeExplain(i), true);
		if (this->igetGameClearData->igetStageEXClearData(i) == true) DrawRotaGraph2(x + 10, y + 20, 75, 30, 1.0, -M_PI / 4, Picture::getSelectText(SEL_CLEAR), true);
	}

	SetDrawBright(255, 255, 255);
}

void SceneGameExtraSelectMode::finalize(){
	delete this->backEffectManager;
}