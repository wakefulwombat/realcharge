#include "sceneOpening.h"
#include "input.h"
#include "picture.h"
#include "music.h"
#include "sound.h"
#include "DxLib.h"

SceneOpening::SceneOpening(ISetNextScene* changer,IGameQuit* gameQuit){
	this->gameQuit = gameQuit;
	this->isetNextScene = changer;
	this->selectNumber=0;
	for(int i=0;i<7;i++){
		this->textPositionX[i]=500;
	}

	for (int i = 0; i < 5; i++){
		this->titleCount[i] = 0;
	}
	this->titlePos[0] = Point(100, 130);
	this->titlePos[1] = Point(200, 130);
	this->titlePos[2] = Point(100, 250);
	this->titlePos[3] = Point(200, 250);
	this->titlePos[4] = Point(300, 250);
}

void SceneOpening::initialize(){
	
}

void SceneOpening::update(){
	if(Input::getGridYDownOnce()==1){
		this->selectNumber = (this->selectNumber+1)%7;
		Sound::playSound(Sound_SelectMove);
	}
	if(Input::getGridYDownOnce()==-1){
		this->selectNumber = (this->selectNumber+6)%7;
		Sound::playSound(Sound_SelectMove);
	}	

	if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK)==1){//決定キーが押されたら
		Sound::playSound(Sound_Decide);
		switch(this->selectNumber){
		case SEL_GAMESTART:
			this->isetNextScene->isetNextScene(Scene_SelectDifficulty);
			break;

		case SEL_EXTRASTAGE:
			this->isetNextScene->isetNextScene(Scene_SelectModeExtra);
			break;

		case SEL_BOSSPRACTICE:
			this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
			break;

		case SEL_STAGEPRACTICE:
			this->isetNextScene->isetNextScene(Scene_SelectPracticeStage);
			break;

		case SEL_MUSICROOM:
			this->isetNextScene->isetNextScene(Scene_MusicRoom);
			break;

		case SEL_KEYCONFIG:
			this->isetNextScene->isetNextScene(Scene_KeyConfig);
			break;

		case SEL_QUIT:
			this->gameQuit->igameQuit();
			break;
		}
	}

	if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel)==1){//キャンセルキーが押されたら
		this->selectNumber=6;
		Sound::playSound(Sound_Cancel);
	}

	for(int i=0;i<7;i++){
		if(this->selectNumber==i){
			if(this->textPositionX[i]>450){
				this->textPositionX[i]-=2;
			}
			else this->textPositionX[i]=450;
		}
		else{
			if(this->textPositionX[i]<500){
				this->textPositionX[i]+=2;
			}
			else this->textPositionX[i] = 500;
		}
	}

	for (int i = 0; i < 5; i++) this->titleCount[i]++;
}

void SceneOpening::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	DrawGraph(0,0,Picture::getBack(0),false);

	for (int i = 0; i < 5; i++){
		if (this->titleCount[i] < 20 * i) continue;

		if (this->titleCount[i] < 20 * i + 30){
			DrawRotaGraph2(this->titlePos[i].x, this->titlePos[i].y, 50, 50, 1.8 - 1.0*(this->titleCount[i] - 20 * i - 30) / 30, M_PI * 2 * (20 * i + 30 - this->titleCount[i]) / 30, Picture::getTitle(i), true);
		}
		else{
			DrawRotaGraph2(this->titlePos[i].x, this->titlePos[i].y, 50, 50, 1.0, 0.0, Picture::getTitle(i), true);
			if (i == 4) DrawRotaGraph2(100, 350, 50, 50, 1.0, 0.0, Picture::getSubTitle(), true);
		}
	}

	for(int i=0;i<7;i++){
		DrawGraph(this->textPositionX[i],50*i+250,Picture::getSelectText((TextPictureKind)i),true);
	}
}

void SceneOpening::finalize(){

}
