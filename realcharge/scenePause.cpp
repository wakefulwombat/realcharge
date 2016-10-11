#include "scenePause.h"
#include "DxLib.h"
#include "input.h"
#include "picture.h"
#include "music.h"
#include "sound.h"

//Film
ScenePause::ScenePause(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect, IGetBossEventNow* igetBossEventNow, ISetGameClearData* isetGameClearData, bool isExtra){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->selectNum = 0;
	this->count = 0;
	this->igetStage = igetStage;
	this->isetBackEffect = isetBackEffect;
	this->igetBossEventNow = igetBossEventNow;
	this->isetGameClearData = isetGameClearData;

	if (isExtra == false){
		this->type = 0;//Film

		this->text[0] = "ゲームに戻る";
		this->text[1] = "ボスからやり直す";
		this->text[2] = "このステージをやり直す";
		this->text[3] = "最初のステージからやり直す";
		this->text[4] = "タイトル画面に戻る";
	}
	else{
		this->type = 2;//Extra

		this->text[0] = "ゲームに戻る";
		this->text[1] = "ボスからやり直す";
		this->text[2] = "このステージをやり直す";
		this->text[3] = "タイトル画面に戻る";
	}
}

ScenePause::ScenePause(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetStage* igetStage, ISetBackEffect* isetBackEffect){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->selectNum = 0;
	this->count = 0;
	this->igetStage = igetStage;
	this->isetBackEffect = isetBackEffect;
	this->igetBossEventNow = igetBossEventNow;

	this->type = 1;//Practice

	this->text[0] = "ゲームに戻る";
	this->text[1] = "このステージをやり直す";
	this->text[2] = "タイトル画面に戻る";
}

ScenePause::ScenePause(ISetNextScene* changer, IGetStage* igetStage, ISetBackEffect* isetBackEffect){
	this->isetNextScene = changer;
	this->selectNum = 0;
	this->count = 0;
	this->igetStage = igetStage;
	this->isetBackEffect = isetBackEffect;
	this->type = 3;//BossPractice

	this->text[0] = "ゲームに戻る";
	this->text[1] = "ボス戦をやり直す";
	this->text[2] = "ステージ選択画面に戻る";
	this->text[3] = "タイトル画面に戻る";
}

void ScenePause::initialize(){
	this->selectNum=0;
	this->count = 0;
	this->isetBackEffect->isetBackEffectClearAll();
}

void ScenePause::update(){
	if (this->type == 0){//film
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			if (this->type == 0){
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
					case 0:	//return
						this->igetStage->isetPauseInvalid();
						this->isetBackEffect->isetBackEffectClearAll();
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
		else{//boss戦以降
			if (this->type == 0){//Film
				if (Input::getGridYDownOnce() == 1){
					this->selectNum = (this->selectNum + 1) % 5;
					Sound::playSound(Sound_SelectMove);
				}
				if (Input::getGridYDownOnce() == -1){
					this->selectNum = (this->selectNum + 4) % 5;
					Sound::playSound(Sound_SelectMove);
				}

				if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){	//決定
					Sound::playSound(Sound_Decide);
					switch (this->selectNum){
					case 0:	//return
						this->igetStage->isetPauseInvalid();
						this->isetBackEffect->isetBackEffectClearAll();
						break;

					case 1:	//reboss
						this->isetGameClearData->isetNoContinueFlag(false);
						this->isetDifficulty->isetStageNum(this->igetStage->igetStage());
						this->isetDifficulty->isetRetryFromBossBattle(true);
						this->isetNextScene->isetNextScene(Scene_GameFilm);
						break;

					case 2:	//restage
						this->isetGameClearData->isetNoContinueFlag(false);
						this->isetDifficulty->isetStageNum(this->igetStage->igetStage());
						this->isetNextScene->isetNextScene(Scene_GameFilm);
						break;

					case 3:	//regame
						this->isetGameClearData->isetNoContinueFlag(true);
						this->isetDifficulty->isetStageNum(1);
						this->isetNextScene->isetNextScene(Scene_GameFilm);
						break;

					case 4:	//title
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
	}
	else if (this->type == 2){//extra
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
				case 0:	//return
					this->igetStage->isetPauseInvalid();
					this->isetBackEffect->isetBackEffectClearAll();
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
		else{
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
				case 0:	//return
					this->igetStage->isetPauseInvalid();
					this->isetBackEffect->isetBackEffectClearAll();
					break;

				case 1:	//reboss
					this->isetGameClearData->isetNoContinueFlag(false);
					this->isetDifficulty->isetRetryFromBossBattle(true);
					this->isetNextScene->isetNextScene(Scene_GameExtra);
					break;

				case 2:	//restage
					this->isetGameClearData->isetNoContinueFlag(true);
					this->isetNextScene->isetNextScene(Scene_GameExtra);
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
	else if (this->type == 1){//practice
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
			case 0:	//return
				this->igetStage->isetPauseInvalid();
				this->isetBackEffect->isetBackEffectClearAll();
				break;

			case 1:	//restage
				this->isetNextScene->isetNextScene(Scene_StagePractice);
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
	else if (this->type == 3){//BossPractice
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
			case 0:	//return
				this->igetStage->isetPauseInvalid();
				this->isetBackEffect->isetBackEffectClearAll();
				break;

			case 1:	//reboss
				this->isetNextScene->isetNextScene(Scene_BossPractice);
				break;

			case 2:	//regame
				Picture::deletePicture();
				Picture::loadOpeningPicture();
				Music::playMusic(Music_Opening);
				this->isetNextScene->isetNextScene(Scene_SelectBossPractice);
				break;

			case 3://title
				Picture::deletePicture();
				Picture::loadOpeningPicture();
				Music::playMusic(Music_Opening);
				this->isetNextScene->isetNextScene(Scene_Opening);
				break;

			}
		}
	}

	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){	//キャンセル
		Sound::playSound(Sound_Decide);
		this->igetStage->isetPauseInvalid();
		this->isetBackEffect->isetBackEffectClearAll();
	}

	this->count++;
	if (this->count % 20 == 0){
		this->isetBackEffect->isetBackEffect(GetRand(5), Point(1.0*GetRand(GAME_WINDOW_WIDTH)+GAME_WINDOW_OFFSET_X, -100.0));
		this->count = 0;
	}
}

void ScenePause::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawFillBox(GAME_WINDOW_OFFSET_X, GAME_WINDOW_OFFSET_Y, GAME_WINDOW_OFFSET_X + GAME_WINDOW_WIDTH, GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT, GetColor(100, 100, 205));

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawString(100, 100, "一時停止中", GetColor(255, 255, 255));

	if (this->type == 0){
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			for (int i = 0; i < 4; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//return
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 2){//regame
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REGAME), true);
					DrawString(280, 50 * i + 310, this->text[3].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[4].c_str(), GetColor(255, 255, 255));
				}
			}
		}
		else{
			for (int i = 0; i < 5; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//return
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//reboss
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 2){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 3){//regame
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REGAME), true);
					DrawString(280, 50 * i + 310, this->text[3].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[4].c_str(), GetColor(255, 255, 255));
				}
			}
		}
	}
	else if (this->type == 2){//Extra
		if ((this->igetBossEventNow->igetBossEventNow() == false) && (this->igetBossEventNow->igetBossFightingNow() == false)){
			for (int i = 0; i < 3; i++){
				if (i == this->selectNum){
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				}
				else{
					SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
				}

				if (i == 0){//return
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
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

				if (i == 0){//return
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
					DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 1){//reboss
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
					DrawString(280, 50 * i + 310, this->text[1].c_str(), GetColor(255, 255, 255));
				}
				else if (i == 2){//restage
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RESTAGE), true);
					DrawString(280, 50 * i + 310, this->text[2].c_str(), GetColor(255, 255, 255));
				}
				else{//title
					DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_TITLE), true);
					DrawString(280, 50 * i + 310, this->text[3].c_str(), GetColor(255, 255, 255));
				}
			}
		}
	}
	else if (this->type == 1){//Practice
		for (int i = 0; i < 3; i++){
			if (i == this->selectNum){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			}
			else{
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			}

			if (i == 0){//return
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
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
	else if (this->type == 3){//BossPractice
		for (int i = 0; i < 4; i++){
			if (i == this->selectNum){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			}
			else{
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			}

			if (i == 0){//return
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_RETURN), true);
				DrawString(280, 50 * i + 310, this->text[0].c_str(), GetColor(255, 255, 255));
			}
			else if (i == 1){//reboss
				DrawGraph(100, 50 * i + 300, Picture::getSelectText(SEL_REBOSS), true);
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

void ScenePause::finalize(){

}