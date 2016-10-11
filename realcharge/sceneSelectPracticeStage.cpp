#include "sceneSelectPracticeStage.h"
#include "DxLib.h"
#include "picture.h"
#include "input.h"
#include "sound.h"

SceneSelectPracticeStage::SceneSelectPracticeStage(ISetNextScene* changer,ISetDifficulty* isetDifficulty){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->selectDifficultyNum=0;
	this->selectStageNum=0;
	this->selectModeNum = 0;
	this->selectingType = 0;

	this->bfCount=0;
	this->backEffectManager = new BackEffectManage();

	for (int i = 0; i < 6; i++){
		this->stage[i].count = 0;
		this->stage[i].start = Point(300, -100);
		this->stage[i].end = Point(300, 300 + 150 * i);
	}
	for (int i = 0; i < 3; i++){
		this->difficulty[i].count = 0;
		this->difficulty[i].start = Point(450, -100);
		this->difficulty[i].end = Point(450, -100);
	}
	for (int i = 0; i < 3; i++){
		this->mode[i].count = 0;
		this->mode[i].start = Point(-300, 200);
		this->mode[i].end = Point(-300, 200);
	}
}

void SceneSelectPracticeStage::initialize(){

}

void SceneSelectPracticeStage::update(){
	if (this->selectingType == 0){
		if (Input::getGridYDownOnce() == 1){
			this->selectStageNum = (this->selectStageNum + 1) % 6;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 6; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(300, 300 + 150 * (i - this->selectStageNum));
			}
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectStageNum = (this->selectStageNum + 5) % 6;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 6; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(300, 300 + 150 * (i - this->selectStageNum));
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			this->selectingType = 1;
		
			for (int i = 0; i < 6; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				if(i==this->selectStageNum) this->stage[i].end = Point(150,150);
				else this->stage[i].end = Point(300, -100);
			}
			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(450, 300.0 + 150.0*(i - this->selectDifficultyNum));
			}
		}
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			this->isetNextScene->isetNextScene(Scene_Opening);
		}
	}
	else if (this->selectingType == 1){
		if (Input::getGridYDownOnce() == 1){
			this->selectDifficultyNum = (this->selectDifficultyNum + 1) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(450, 300.0 + 150.0*(i - this->selectDifficultyNum));
			}
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectDifficultyNum = (this->selectDifficultyNum + 2) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(450, 300.0 + 150.0*(i - this->selectDifficultyNum));
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			this->selectingType = 2;

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				if (i == this->selectDifficultyNum) this->difficulty[i].end = Point(500, 150);
				else this->difficulty[i].end = Point(450, -100);
			}
			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectModeNum) + 270, 200);
			}
		}
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			this->selectingType = 0;

			for (int i = 0; i < 6; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(300, 300 + 150 * (i - this->selectStageNum));
			}
			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(450, -100);
			}
		}
	}
	else{
		if (Input::getGridXDownOnce() == 1){
			this->selectModeNum = (this->selectModeNum + 1) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectModeNum) + 270, 200);
			}
		}
		if (Input::getGridXDownOnce() == -1){
			this->selectModeNum = (this->selectModeNum + 2) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectModeNum) + 270, 200);
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			this->selectingType = 2;

			this->isetDifficulty->isetDifficulty(this->selectDifficultyNum);
			this->isetDifficulty->isetStageNum(this->selectStageNum+1);
			this->isetDifficulty->isetModeEX(this->selectModeNum);

			this->isetNextScene->isetNextScene(Scene_StagePractice);
		}
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			this->selectingType = 1;

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = Point(-300, 200);
				this->mode[i].end = Point(-300, 200);
			}
			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(450, 300.0 + 150.0*(i - this->selectDifficultyNum));
			}
		}
	}

	for (int i = 0; i < 6; i++) this->stage[i].count++;
	for (int i = 0; i < 3; i++) this->difficulty[i].count++;
	for (int i = 0; i < 3; i++) this->mode[i].count++;

	this->bfCount++;
	if(this->bfCount==20){
		this->bfCount=0;
		this->backEffectManager->isetBackEffect(GetRand(5),Point(1.0*GetRand(WINDOW_WIDTH),-100.0));
	}
	this->backEffectManager->update();
}

void SceneSelectPracticeStage::draw(){
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	DrawGraph(0,0,Picture::getBack(1),false);
	
	if (this->selectingType == 0) DrawGraph(50, 30, Picture::getSelectText(SEL_STAGESELECT), true);
	else if (this->selectingType == 1) DrawGraph(50, 30, Picture::getSelectText(SEL_RANKSELECT), true);
	else DrawGraph(50, 30, Picture::getSelectText(SEL_MODESELECT), true);

	for (int i = 0; i < 6; i++){
		if (i == this->selectStageNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->stage[i].count < 30){
			DrawGraph(2.0*(this->stage[i].end.x - this->stage[i].start.x)*this->stage[i].count / 30 - (this->stage[i].end.x - this->stage[i].start.x)*this->stage[i].count*this->stage[i].count / 900 + this->stage[i].start.x, 2.0*(this->stage[i].end.y - this->stage[i].start.y)*this->stage[i].count / 30 - (this->stage[i].end.y - this->stage[i].start.y)*this->stage[i].count*this->stage[i].count / 900 + this->stage[i].start.y, Picture::getSelectText((TextPictureKind)(SEL_STAGE1 + i)), true);
		}
		else{
			DrawGraph(this->stage[i].end.x, this->stage[i].end.y, Picture::getSelectText((TextPictureKind)(SEL_STAGE1 + i)), true);
		}
	}
	for (int i = 0; i < 3; i++){
		if (i == this->selectDifficultyNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->difficulty[i].count < 30){
			DrawGraph(2.0*(this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count / 30 - (this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.x, 2.0*(this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count / 30 - (this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.y, Picture::getSelectText((TextPictureKind)(SEL_EASY + i)), true);
		}
		else{
			DrawGraph(this->difficulty[i].end.x, this->difficulty[i].end.y, Picture::getSelectText((TextPictureKind)(SEL_EASY + i)), true);
		}
	}
	for (int i = 0; i < 3; i++){
		if (i == this->selectModeNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->mode[i].count < 30){
			DrawGraph(2.0*(this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count / 30 - (this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.x, 2.0*(this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count / 30 - (this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.y, Picture::getPlayerModeExplain(i), true);
		}
		else{
			DrawGraph(this->mode[i].end.x, this->mode[i].end.y, Picture::getPlayerModeExplain(i), true);
		}
	}

	this->backEffectManager->draw();
}

void SceneSelectPracticeStage::finalize(){
	delete this->backEffectManager;
}