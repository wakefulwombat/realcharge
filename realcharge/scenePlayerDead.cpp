#include "scenePlayerDead.h"
#include "picture.h"
#include "music.h"
#include "input.h"
#include "DxLib.h"
#include "sound.h"

//Film
ScenePlayerDead::ScenePlayerDead(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->selectNum = 0;
	this->count = 0;
	this->igetStage = igetStage;
	this->isetBackEffect = isetBackEffect;
	this->igetBossEventNow = igetBossEventNow;
	this->isetGameClearData = isetGameClearData;
	this->type = 0;//Film

	this->text[0] = "ボスからやり直す";
	this->text[1] = "このステージをやり直す";
	this->text[2] = "最初のステージからやり直す";
	this->text[3] = "タイトル画面に戻る";

}

ScenePlayerDead::ScenePlayerDead(ISetNextScene* changer, ISetDifficulty* isetDifficulty, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData){
	this->isetNextScene = changer;
	this->selectNum = 0;
	this->count = 0;
	this->isetBackEffect = isetBackEffect;
	this->igetBossEventNow = igetBossEventNow;
	this->isetDifficulty = isetDifficulty;
	this->isetGameClearData = isetGameClearData;
	this->type = 1;//Extra

	this->text[0] = "ボスからやり直す";
	this->text[1] = "このステージをやり直す";
	this->text[2] = "タイトル画面に戻る";
}

ScenePlayerDead::ScenePlayerDead(ISetNextScene* changer, ISetBackEffect* isetBackEffect){
	this->isetNextScene = changer;
	this->selectNum = 0;
	this->count = 0;
	this->isetBackEffect = isetBackEffect;
	this->type = 2;//BossPractice

	this->text[0] = "もう一度やり直す";
	this->text[1] = "ステージ選択画面に戻る";
	this->text[2] = "タイトル画面に戻る";
}

void ScenePlayerDead::initialize(){
	this->selectNum = 0;
	this->count = 0;
	this->isetBackEffect->isetBackEffectClearAll();
}

void ScenePlayerDead::update(){
	if (this->type == 0){//Film
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			if (Input::getGridYDownOnce() == 1){
				this->selectNum = (this->selectNum + 1) % 3;
				Sound::playSound(Sound_SelectMove);
			}
			if (Input::getGridYDownOnce() == -1){
				this->selectNum = (this->selectNum + 2) % 3;
				Sound::playSound(Sound_SelectMove);
			}

			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
				Sound::playSound(Sound_Decide);
				switch (this->selectNum){
				case 0:	//restage
					this->isetGameClearData->isetNoContinueFlag(false);
					this->isetDifficulty->isetStageNum(this->igetStage->igetStage());
					this->isetNextScene->isetNextScene(Scene_GameFilm);
					break;

				case 1:	//regame
					this->isetGameClearData->isetNoContinueFlag(true);
					this->isetDifficulty->isetStageNum(1);
					this->isetNextScene->isetNextScene(Scene_GameFilm);
					break;

				case 2:	//title
					this->isetGameClearData->isetNoContinueFlag(true);
					Picture::deletePicture();
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetNextScene->isetNextScene(Scene_Opening);
					break;
				}
			}
		}
		else{//ボス戦以降
			if (Input::getGridYDownOnce() == 1){
				this->selectNum = (this->selectNum + 1) % 4;
				Sound::playSound(Sound_SelectMove);
			}
			if (Input::getGridYDownOnce() == -1){
				this->selectNum = (this->selectNum + 3) % 4;
				Sound::playSound(Sound_SelectMove);
			}

			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
				Sound::playSound(Sound_Decide);
				switch (this->selectNum){
				case 0:	//reboss
					this->isetGameClearData->isetNoContinueFlag(false);
					this->isetDifficulty->isetStageNum(this->igetStage->igetStage());
					this->isetDifficulty->isetRetryFromBossBattle(true);
					this->isetNextScene->isetNextScene(Scene_GameFilm);
					break;

				case 1:	//restage
					this->isetGameClearData->isetNoContinueFlag(false);
					this->isetDifficulty->isetStageNum(this->igetStage->igetStage());
					this->isetNextScene->isetNextScene(Scene_GameFilm);
					break;

				case 2:	//regame
					this->isetGameClearData->isetNoContinueFlag(true);
					this->isetDifficulty->isetStageNum(1);
					this->isetNextScene->isetNextScene(Scene_GameFilm);
					break;

				case 3:	//title
					this->isetGameClearData->isetNoContinueFlag(true);
					Picture::deletePicture();
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetNextScene->isetNextScene(Scene_Opening);
					break;
				}
			}
		}
	}
	else if (this->type == 1){//Extra
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			if (Input::getGridYDownOnce() != 0){
				this->selectNum = (this->selectNum + 1) % 2;
				Sound::playSound(Sound_SelectMove);
			}

			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
				Sound::playSound(Sound_Decide);
				switch (this->selectNum){
				case 0:	//restage
					this->isetGameClearData->isetNoContinueFlag(true);
					this->isetNextScene->isetNextScene(Scene_GameExtra);
					break;

				case 1:	//title
					this->isetGameClearData->isetNoContinueFlag(true);
					Picture::deletePicture();
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetNextScene->isetNextScene(Scene_Opening);
					break;
				}
			}
		}
		else{
			if (Input::getGridYDownOnce() == 1){
				this->selectNum = (this->selectNum + 1) % 3;
				Sound::playSound(Sound_SelectMove);
			}
			if (Input::getGridYDownOnce() == -1){
				this->selectNum = (this->selectNum + 2) % 3;
				Sound::playSound(Sound_SelectMove);
			}

			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
				Sound::playSound(Sound_Decide);
				switch (this->selectNum){
				case 0:	//reboss
					this->isetGameClearData->isetNoContinueFlag(false);
					this->isetDifficulty->isetRetryFromBossBattle(true);
					this->isetNextScene->isetNextScene(Scene_GameExtra);
					break;

				case 1:	//restage
					this->isetGameClearData->isetNoContinueFlag(true);
					this->isetNextScene->isetNextScene(Scene_GameExtra);
					break;

				case 2:	//title
					this->isetGameClearData->isetNoContinueFlag(true);
					Picture::deletePicture();
					Picture::loadOpeningPicture();
					Music::playMusic(Music_Opening);
					this->isetNextScene->isetNextScene(Scene_Opening);
					break;
				}
			}
		}
	}
	else{//BossPractice
		if (Input::getGridYDownOnce() == 1){
			this->selectNum = (this->selectNum + 1) % 3;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectNum = (this->selectNum + 2) % 3;
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
			Sound::playSound(Sound_Decide);
			switch (this->selectNum){
			case 0:	//reboss
				this->isetNextScene->isetNextScene(Scene_BossPractice);
				break;

			case 1:	//regame
				Picture::deletePicture();
				Picture::loadOpeningPicture();
				Music::playMusic(Music_Opening);
				this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
				break;

			case 2:	//title
				Picture::deletePicture();
				Picture::loadOpeningPicture();
				Music::playMusic(Music_Opening);
				this->isetNextScene->isetNextScene(Scene_Opening);
				break;
			}
		}
	}

	this->count++;
	if (this->count % 20 == 0){
		this->isetBackEffect->isetBackEffect(GetRand(5), Point(1.0*GetRand(GAME_WINDOW_WIDTH) + GAME_WINDOW_OFFSET_X, -100.0));
		this->count = 0;
	}
}

void ScenePlayerDead::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawFillBox(GAME_WINDOW_OFFSET_X, GAME_WINDOW_OFFSET_Y, GAME_WINDOW_OFFSET_X + GAME_WINDOW_WIDTH, GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT, GetColor(200, 100, 105));

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawString(100, 100, "GAME OVER", GetColor(255, 255, 255));

	if (this->type == 0){//Film
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			for (int i = 0; i < 3; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//regame
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REGAME), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[3].c_str(), GetColor(255, 255, 255));
				}
			}
		}
		else{
			for (int i = 0; i < 4; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//reboss
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 2){//regame
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REGAME), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[3].c_str(), GetColor(255, 255, 255));
				}
			}
		}
	}
	else if (this->type == 1){//Extra
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			for (int i = 0; i < 2; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
			}
		}
		else{
			for (int i = 0; i < 3; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//reboss
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
			}
		}
	}
	else{//BossPractice
		for (int i = 0; i < 3; i++){
			if (i == this->selectNum){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			}
			else{
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			}

			if (i == 0){//reboss
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
				DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
			}
			else if (i == 1){//regame
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REGAME), true);
				DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
			}
			else{//title
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
				DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
			}
		}
	}
}

void ScenePlayerDead::finalize(){

}