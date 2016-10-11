#include "sceneKeyConfig.h"
#include "DxLib.h"
#include "picture.h"
#include "input.h"
#include "sound.h"
#include <stdio.h>

SceneKeyConfig::SceneKeyConfig(ISetNextScene* changer){
	this->isetNextScene = changer;
	this->selectNum = 0;
	this->selectingMode = 0;
	for (int i = 0; i < 4; i++){
		this->registedJoyPadCode_explode[i] = Input::getRegistedKeyCodeJoyPad_Explode((KeyCode_Explode)i);
		this->registedKeyBoardCode_explode[i] = Input::getRegistedKeyCodeKeyBoard_Explode((KeyCode_Explode)i);
		this->registedJoyPadCode_stand[i] = Input::getRegistedKeyCodeJoyPad_Stand((KeyCode_Stand)i);
		this->registedKeyBoardCode_stand[i] = Input::getRegistedKeyCodeKeyBoard_Stand((KeyCode_Stand)i);
		this->registedJoyPadCode_absorb[i] = Input::getRegistedKeyCodeJoyPad_Absorb((KeyCode_Absorb)i);
		this->registedKeyBoardCode_absorb[i] = Input::getRegistedKeyCodeKeyBoard_Absorb((KeyCode_Absorb)i);
	}
	this->registedJoyPadCode_OK = Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_OK);
	this->registedJoyPadCode_cancel = Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Cancel);
	this->registedJoyPadCode_pause = Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Pause);
	this->registedKeyBoardCode_OK = Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_OK);
	this->registedKeyBoardCode_cancel = Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Cancel);
	this->registedKeyBoardCode_pause = Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Pause);

	for (int i = 0; i < 4; i++) {
		this->other[i].start = Point(-640, 260 + 50 * i);
		this->other[i].end = Point(280, 260 + 50 * i);
		this->other[i].count = 0;
	}
	this->initPosOutOfScreen_Explode();
	this->initPosOutOfScreen_Stand();
	this->initPosOutOfScreen_Absorb();

	this->bfCount = 0;
	this->backEffectManager = new BackEffectManage();
}

void SceneKeyConfig::initialize(){

}

void SceneKeyConfig::update(){
	for (int i = 0; i < 4; i++) this->other[i].count++;
	for (int i = 0; i < 5; i++) this->explode[i].count++;
	for (int i = 0; i < 5; i++) this->stand[i].count++;
	for (int i = 0; i < 5; i++) this->absorb[i].count++;


	if (this->selectingMode == 0){//other
		if (Input::getGridXDownOnce() == 1){//右
			for (int i = 0; i < 4; i++){
				this->other[i].start = this->other[i].end;
				this->other[i].end = Point(-640, 260 + 50 * i);
				this->other[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->explode[i].start = Point(1040, 260 + 50 * i);
				this->explode[i].end = Point(280, 260 + 50 * i);
				this->explode[i].count = 0;
			}

			this->initPosOutOfScreen_Absorb();
			this->initPosOutOfScreen_Stand();
			this->selectingMode = 1;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridXDownOnce() == -1){//左
			for (int i = 0; i < 4; i++){
				this->other[i].start = this->other[i].end;
				this->other[i].end = Point(1040, 260 + 50 * i);
				this->other[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->absorb[i].start = Point(-640, 260 + 50 * i);
				this->absorb[i].end = Point(280, 260 + 50 * i);
				this->absorb[i].count = 0;
			}

			this->initPosOutOfScreen_Explode();
			this->initPosOutOfScreen_Stand();
			this->selectingMode = 3;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getGridYDownOnce() == 1){//下
			this->selectNum = (this->selectNum + 1) % 4;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridYDownOnce() == -1){//上
			this->selectNum = (this->selectNum + 3) % 4;
			Sound::playSound(Sound_SelectMove);
		}
	}
	else if (this->selectingMode == 1){//explode
		if (Input::getGridXDownOnce() == 1){//右
			for (int i = 0; i < 5; i++){
				this->explode[i].start = this->explode[i].end;
				this->explode[i].end = Point(-640, 260 + 50 * i);
				this->explode[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->stand[i].start = Point(1040, 260 + 50 * i);
				this->stand[i].end = Point(280, 260 + 50 * i);
				this->stand[i].count = 0;
			}

			this->initPosOutOfScreen_Absorb();
			this->initPosOutOfScreen_Other();
			this->selectingMode = 2;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridXDownOnce() == -1){//左
			for (int i = 0; i < 5; i++){
				this->explode[i].start = this->explode[i].end;
				this->explode[i].end = Point(1040, 260 + 50 * i);
				this->explode[i].count = 0;
			}
			for (int i = 0; i < 4; i++){
				this->other[i].start = Point(-640, 260 + 50 * i);
				this->other[i].end = Point(280, 260 + 50 * i);
				this->other[i].count = 0;
			}

			this->initPosOutOfScreen_Absorb();
			this->initPosOutOfScreen_Stand();
			this->selectingMode = 0;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getGridYDownOnce() == 1){//下
			this->selectNum = (this->selectNum + 1) % 5;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridYDownOnce() == -1){//上
			this->selectNum = (this->selectNum + 4) % 5;
			Sound::playSound(Sound_SelectMove);
		}
	}
	else if (this->selectingMode == 2){//stand
		if (Input::getGridXDownOnce() == 1){//右
			for (int i = 0; i < 5; i++){
				this->stand[i].start = this->stand[i].end;
				this->stand[i].end = Point(-640, 260 + 50 * i);
				this->stand[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->absorb[i].start = Point(1040, 260 + 50 * i);
				this->absorb[i].end = Point(280, 260 + 50 * i);
				this->absorb[i].count = 0;
			}

			this->initPosOutOfScreen_Explode();
			this->initPosOutOfScreen_Other();
			this->selectingMode = 3;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridXDownOnce() == -1){//左
			for (int i = 0; i < 5; i++){
				this->stand[i].start = this->stand[i].end;
				this->stand[i].end = Point(1040, 260 + 50 * i);
				this->stand[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->explode[i].start = Point(-640, 260 + 50 * i);
				this->explode[i].end = Point(280, 260 + 50 * i);
				this->explode[i].count = 0;
			}

			this->initPosOutOfScreen_Other();
			this->initPosOutOfScreen_Absorb();
			this->selectingMode = 1;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getGridYDownOnce() == 1){//下
			this->selectNum = (this->selectNum + 1) % 5;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridYDownOnce() == -1){//上
			this->selectNum = (this->selectNum + 4) % 5;
			Sound::playSound(Sound_SelectMove);
		}
	}
	else{//absorb
		if (Input::getGridXDownOnce() == 1){//右
			for (int i = 0; i < 5; i++){
				this->absorb[i].start = this->absorb[i].end;
				this->absorb[i].end = Point(-640, 260 + 50 * i);
				this->absorb[i].count = 0;
			}
			for (int i = 0; i < 4; i++){
				this->other[i].start = Point(1040, 260 + 50 * i);
				this->other[i].end = Point(280, 260 + 50 * i);
				this->other[i].count = 0;
			}

			this->initPosOutOfScreen_Explode();
			this->initPosOutOfScreen_Stand();
			this->selectingMode = 0;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridXDownOnce() == -1){//左
			for (int i = 0; i < 5; i++){
				this->absorb[i].start = this->absorb[i].end;
				this->absorb[i].end = Point(1040, 260 + 50 * i);
				this->absorb[i].count = 0;
			}
			for (int i = 0; i < 5; i++){
				this->stand[i].start = Point(-640, 260 + 50 * i);
				this->stand[i].end = Point(280, 260 + 50 * i);
				this->stand[i].count = 0;
			}

			this->initPosOutOfScreen_Other();
			this->initPosOutOfScreen_Explode();
			this->selectingMode = 2;
			this->selectNum = 0;
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getGridYDownOnce() == 1){//下
			this->selectNum = (this->selectNum + 1) % 5;
			Sound::playSound(Sound_SelectMove);
		}
		if (Input::getGridYDownOnce() == -1){//上
			this->selectNum = (this->selectNum + 4) % 5;
			Sound::playSound(Sound_SelectMove);
		}
	}


	if (this->selectingMode == 0){//other
		if (this->selectNum == 3){//exit
			if (Input::isAnyKeyCodeDown() == true){
				this->inputNewKeyConfig();
				Sound::playSound(Sound_Decide);
				this->isetNextScene->isetNextScene(Scene_Opening);
			}
		}
		else{
			if (Input::getJoyPadFlag() == true){
				int key = GetJoypadInputState(DX_INPUT_PAD1);
				for (int i = PAD_INPUT_1; i != PAD_INPUT_28; i *= 2){
					if ((key&i) == 0) continue;

					if (this->selectNum == 0) this->registedJoyPadCode_OK = i;
					if (this->selectNum == 1) this->registedJoyPadCode_cancel = i;
					if (this->selectNum == 2) this->registedJoyPadCode_pause = i;
					break;
				}
			}
			else{
				char tmp[256];
				GetHitKeyStateAll(tmp);
				for (int i = 0; i < 256; i++){
					if (tmp[i] == 0)continue;
					if ((i == KEY_INPUT_UP) || (i == KEY_INPUT_DOWN) || (i == KEY_INPUT_RIGHT) || (i == KEY_INPUT_LEFT) || (i == KEY_INPUT_ESCAPE)) continue;

					if (this->selectNum == 0) this->registedKeyBoardCode_OK = i;
					if (this->selectNum == 1) this->registedKeyBoardCode_cancel = i;
					if (this->selectNum == 2) this->registedKeyBoardCode_pause = i;
					break;
				}
			}
		}
	}
	else if (this->selectingMode == 1){//explode
		if (this->selectNum == 4){//exit
			if (Input::isAnyKeyCodeDown() == true){
				this->inputNewKeyConfig();
				Sound::playSound(Sound_Decide);
				this->isetNextScene->isetNextScene(Scene_Opening);
			}
		}
		else{
			if (Input::getJoyPadFlag() == true){
				int key = GetJoypadInputState(DX_INPUT_PAD1);
				for (int i = PAD_INPUT_1; i != PAD_INPUT_28; i *= 2){
					if ((key&i) == 0) continue;

					this->registedJoyPadCode_explode[this->selectNum] = i;
					break;
				}
			}
			else{
				char tmp[256];
				GetHitKeyStateAll(tmp);
				for (int i = 0; i < 256; i++){
					if (tmp[i] == 0)continue;
					if ((i == KEY_INPUT_UP) || (i == KEY_INPUT_DOWN) || (i == KEY_INPUT_RIGHT) || (i == KEY_INPUT_LEFT) || (i == KEY_INPUT_ESCAPE)) continue;

					this->registedKeyBoardCode_explode[this->selectNum] = i;
					break;
				}
			}
		}
	}
	else if (this->selectingMode == 2){
		if (this->selectNum == 4){//exit
			if (Input::isAnyKeyCodeDown() == true){
				this->inputNewKeyConfig();
				Sound::playSound(Sound_Decide);
				this->isetNextScene->isetNextScene(Scene_Opening);
			}
		}
		else{
			if (Input::getJoyPadFlag() == true){
				int key = GetJoypadInputState(DX_INPUT_PAD1);
				for (int i = PAD_INPUT_1; i != PAD_INPUT_28; i *= 2){
					if ((key&i) == 0) continue;

					this->registedJoyPadCode_stand[this->selectNum] = i;
					break;
				}
			}
			else{
				char tmp[256];
				GetHitKeyStateAll(tmp);
				for (int i = 0; i < 256; i++){
					if (tmp[i] == 0)continue;
					if ((i == KEY_INPUT_UP) || (i == KEY_INPUT_DOWN) || (i == KEY_INPUT_RIGHT) || (i == KEY_INPUT_LEFT) || (i == KEY_INPUT_ESCAPE)) continue;

					this->registedKeyBoardCode_stand[this->selectNum] = i;
					break;
				}
			}
		}
	}
	else{
		if (this->selectNum == 4){//exit
			if (Input::isAnyKeyCodeDown() == true){
				this->inputNewKeyConfig();
				Sound::playSound(Sound_Decide);
				this->isetNextScene->isetNextScene(Scene_Opening);
			}
		}
		else{
			if (Input::getJoyPadFlag() == true){
				int key = GetJoypadInputState(DX_INPUT_PAD1);
				for (int i = PAD_INPUT_1; i != PAD_INPUT_28; i *= 2){
					if ((key&i) == 0) continue;

					this->registedJoyPadCode_absorb[this->selectNum] = i;
					break;
				}
			}
			else{
				char tmp[256];
				GetHitKeyStateAll(tmp);
				for (int i = 0; i < 256; i++){
					if (tmp[i] == 0)continue;
					if ((i == KEY_INPUT_UP) || (i == KEY_INPUT_DOWN) || (i == KEY_INPUT_RIGHT) || (i == KEY_INPUT_LEFT) || (i == KEY_INPUT_ESCAPE)) continue;

					this->registedKeyBoardCode_absorb[this->selectNum] = i;
					break;
				}
			}
		}
	}


	this->bfCount++;
	if(this->bfCount==10){
		this->backEffectManager->isetBackEffect(GetRand(5),Point(1.0*GetRand(WINDOW_WIDTH),-100.0));
	}
	this->backEffectManager->update();
}

void SceneKeyConfig::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(0, 0, Picture::getBack(1), false);
	DrawGraph(50, 30, Picture::getSelectText(SEL_KEYSELECT), true);

	this->backEffectManager->draw();

	double x, y;

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);

	if (this->other[0].count < 15){
		DrawString(
			2.0*(this->other[0].end.x - this->other[0].start.x) * this->other[0].count / 15.0 - (this->other[0].end.x - this->other[0].start.x)* this->other[0].count* this->other[0].count / 15 / 15 + this->other[0].start.x - 50,
			2.0*(this->other[0].end.y - this->other[0].start.y) * this->other[0].count / 15.0 - (this->other[0].end.y - this->other[0].start.y)* this->other[0].count* this->other[0].count / 15 / 15 + this->other[0].start.y - 50,
			"コモン", GetColor(255, 255, 255));
	}
	else{
		DrawString(this->other[0].end.x - 50, this->other[0].end.y - 50, "コモン", GetColor(255, 255, 255));
		for (int i = 0; i < 4; i++){
			if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}
	}

	for (int i = 0; i < 4; i++){
		if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->other[i].count < 15){
			x = 2.0*(this->other[i].end.x - this->other[i].start.x) * this->other[i].count / 15.0 - (this->other[i].end.x - this->other[i].start.x)* this->other[i].count* this->other[i].count / 15 / 15 + this->other[i].start.x;
			y = 2.0*(this->other[i].end.y - this->other[i].start.y) * this->other[i].count / 15.0 - (this->other[i].end.y - this->other[i].start.y)* this->other[i].count* this->other[i].count / 15 / 15 + this->other[i].start.y;
		}
		else{
			x = this->other[i].end.x;
			y = this->other[i].end.y;
		}

		if (i == 0){
			DrawString(x, y, "決定", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_OK), this->registedJoyPadCode_OK);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_OK), this->registedKeyBoardCode_OK);
		}
		else if (i == 1){
			DrawString(x, y, "キャンセル", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Cancel), this->registedJoyPadCode_cancel);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Cancel), this->registedKeyBoardCode_cancel);
		}
		else if (i == 2){
			DrawString(x, y, "ポーズ", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Pause), this->registedJoyPadCode_pause);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Pause), this->registedKeyBoardCode_pause);
		}
		else{
			DrawString(x, y, "コンフィグ終了", GetColor(255, 255, 255));
		}
	}


	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);

	if (this->explode[0].count < 15){
		DrawString(
			2.0*(this->explode[0].end.x - this->explode[0].start.x) * this->explode[0].count / 15.0 - (this->explode[0].end.x - this->explode[0].start.x)* this->explode[0].count* this->explode[0].count / 15 / 15 + this->explode[0].start.x - 50,
			2.0*(this->explode[0].end.y - this->explode[0].start.y) * this->explode[0].count / 15.0 - (this->explode[0].end.y - this->explode[0].start.y)* this->explode[0].count* this->explode[0].count / 15 / 15 + this->explode[0].start.y - 50,
			"エクスプロードモード", GetColor(255, 255, 255));
	}
	else{
		DrawString(this->explode[0].end.x - 50, this->explode[0].end.y - 50, "エクスプロードモード", GetColor(255, 255, 255));
		for (int i = 0; i < 4; i++){
			if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}
	}

	for (int i = 0; i < 5; i++){
		if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->explode[i].count < 15){
			x = 2.0*(this->explode[i].end.x - this->explode[i].start.x) * this->explode[i].count / 15.0 - (this->explode[i].end.x - this->explode[i].start.x)* this->explode[i].count* this->explode[i].count / 15 / 15 + this->explode[i].start.x;
			y = 2.0*(this->explode[i].end.y - this->explode[i].start.y) * this->explode[i].count / 15.0 - (this->explode[i].end.y - this->explode[i].start.y)* this->explode[i].count* this->explode[i].count / 15 / 15 + this->explode[i].start.y;
		}
		else{
			x = this->explode[i].end.x;
			y = this->explode[i].end.y;
		}

		if (i == 0){
			DrawString(x, y, "低速移動", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_SlowMove), this->registedJoyPadCode_explode[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_SlowMove), this->registedKeyBoardCode_explode[i]);
		}
		else if (i == 1){
			DrawString(x, y, "誘爆剤", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_ScatterBomb), this->registedJoyPadCode_explode[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_ScatterBomb), this->registedKeyBoardCode_explode[i]);
		}
		else if (i == 2){
			DrawString(x, y, "イグニッション", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Ignition), this->registedJoyPadCode_explode[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Ignition), this->registedKeyBoardCode_explode[i]);
		}
		else if (i == 3){
			DrawString(x, y, "チャージショット", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_ReleasePower), this->registedJoyPadCode_explode[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_ReleasePower), this->registedKeyBoardCode_explode[i]);
		}
		else{
			DrawString(x, y, "コンフィグ終了", GetColor(255, 255, 255));
		}
	}


	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);

	if (this->stand[0].count < 15){
		DrawString(
			2.0*(this->stand[0].end.x - this->stand[0].start.x) * this->stand[0].count / 15.0 - (this->stand[0].end.x - this->stand[0].start.x)* this->stand[0].count* this->stand[0].count / 15 / 15 + this->stand[0].start.x - 50,
			2.0*(this->stand[0].end.y - this->stand[0].start.y) * this->stand[0].count / 15.0 - (this->stand[0].end.y - this->stand[0].start.y)* this->stand[0].count* this->stand[0].count / 15 / 15 + this->stand[0].start.y - 50,
			"スタンドモード", GetColor(255, 255, 255));
	}
	else{
		DrawString(this->stand[0].end.x - 50, this->stand[0].end.y - 50, "スタンドモード", GetColor(255, 255, 255));
		for (int i = 0; i < 4; i++){
			if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}
	}

	for (int i = 0; i < 5; i++){
		if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->stand[i].count < 15){
			x = 2.0*(this->stand[i].end.x - this->stand[i].start.x) * this->stand[i].count / 15.0 - (this->stand[i].end.x - this->stand[i].start.x)* this->stand[i].count* this->stand[i].count / 15 / 15 + this->stand[i].start.x;
			y = 2.0*(this->stand[i].end.y - this->stand[i].start.y) * this->stand[i].count / 15.0 - (this->stand[i].end.y - this->stand[i].start.y)* this->stand[i].count* this->stand[i].count / 15 / 15 + this->stand[i].start.y;
		}
		else{
			x = this->stand[i].end.x;
			y = this->stand[i].end.y;
		}

		if (i == 0){
			DrawString(x, y, "低速移動", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Stand(KeyCodeStand_SlowMove), this->registedJoyPadCode_stand[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_SlowMove), this->registedKeyBoardCode_stand[i]);
		}
		else if (i == 1){
			DrawString(x, y, "弱ショット", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Stand(KeyCodeStand_ShotBullet), this->registedJoyPadCode_stand[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_ShotBullet), this->registedKeyBoardCode_stand[i]);
		}
		else if (i == 2){
			DrawString(x, y, "フレックス", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Stand(KeyCodeStand_StandFlex), this->registedJoyPadCode_stand[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_StandFlex), this->registedKeyBoardCode_stand[i]);
		}
		else if (i == 3){
			DrawString(x, y, "ホールド", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Stand(KeyCodeStand_StandHold), this->registedJoyPadCode_stand[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_StandHold), this->registedKeyBoardCode_stand[i]);
		}
		else{
			DrawString(x, y, "コンフィグ終了", GetColor(255, 255, 255));
		}
	}


	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);

	if (this->absorb[0].count < 15){
		DrawString(
			2.0*(this->absorb[0].end.x - this->absorb[0].start.x) * this->absorb[0].count / 15.0 - (this->absorb[0].end.x - this->absorb[0].start.x)* this->absorb[0].count* this->absorb[0].count / 15 / 15 + this->absorb[0].start.x - 50,
			2.0*(this->absorb[0].end.y - this->absorb[0].start.y) * this->absorb[0].count / 15.0 - (this->absorb[0].end.y - this->absorb[0].start.y)* this->absorb[0].count* this->absorb[0].count / 15 / 15 + this->absorb[0].start.y - 50,
			"アブソーブモード", GetColor(255, 255, 255));
	}
	else{
		DrawString(this->absorb[0].end.x - 50, this->absorb[0].end.y - 50, "アブソーブモード", GetColor(255, 255, 255));
		for (int i = 0; i < 4; i++){
			if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}
	}

	for (int i = 0; i < 5; i++){
		if (i == this->selectNum) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->absorb[i].count < 15){
			x = 2.0*(this->absorb[i].end.x - this->absorb[i].start.x) * this->absorb[i].count / 15.0 - (this->absorb[i].end.x - this->absorb[i].start.x)* this->absorb[i].count* this->absorb[i].count / 15 / 15 + this->absorb[i].start.x;
			y = 2.0*(this->absorb[i].end.y - this->absorb[i].start.y) * this->absorb[i].count / 15.0 - (this->absorb[i].end.y - this->absorb[i].start.y)* this->absorb[i].count* this->absorb[i].count / 15 / 15 + this->absorb[i].start.y;
		}
		else{
			x = this->absorb[i].end.x;
			y = this->absorb[i].end.y;
		}

		if (i == 0){
			DrawString(x, y, "低速移動", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_SlowMove), this->registedJoyPadCode_absorb[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_SlowMove), this->registedKeyBoardCode_absorb[i]);
		}
		else if (i == 1){
			DrawString(x, y, "アブソーブ", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Absorb), this->registedJoyPadCode_absorb[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Absorb), this->registedKeyBoardCode_absorb[i]);
		}
		else if (i == 2){
			DrawString(x, y, "トランス", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Release), this->registedJoyPadCode_absorb[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Release), this->registedKeyBoardCode_absorb[i]);
		}
		else if (i == 3){
			DrawString(x, y, "コラプサー", GetColor(255, 255, 255));
			if (Input::getJoyPadFlag() == true) DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%u->%u", Input::getRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Collapsar), this->registedJoyPadCode_absorb[i]);
			else DrawFormatString(x + 200, y, GetColor(255, 255, 255), "%d->%d", Input::getRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Collapsar), this->registedKeyBoardCode_absorb[i]);
		}
		else{
			DrawString(x, y, "コンフィグ終了", GetColor(255, 255, 255));
		}
	}

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 150.0*sin(M_PI / 50 * this->bfCount) + 105);
	if (this->selectingMode == 0){
		DrawString(50, 550, "←アブソーブモード", GetColor(255, 255, 255));
		DrawString(790 - GetDrawStringWidth("エクスプロードモード→", strlen("エクスプロードモード→")), 550, "エクスプロードモード→", GetColor(255, 255, 255));
	}
	else if (this->selectingMode == 1){
		DrawString(50, 550, "←コモン", GetColor(255, 255, 255));
		DrawString(790 - GetDrawStringWidth("スタンドモード→", strlen("スタンドモード→")), 550, "スタンドモード→", GetColor(255, 255, 255));
	}
	else if (this->selectingMode == 2){
		DrawString(50, 550, "←エクスプロードモード", GetColor(255, 255, 255));
		DrawString(790 - GetDrawStringWidth("アブソーブモード→", strlen("アブソーブモード→")), 550, "アブソーブモード→", GetColor(255, 255, 255));
	}
	else{
		DrawString(50, 550, "←スタンドモード", GetColor(255, 255, 255));
		DrawString(790 - GetDrawStringWidth("コモン→", strlen("コモン→")), 550, "コモン→", GetColor(255, 255, 255));
	}
}

void SceneKeyConfig::finalize(){
	delete this->backEffectManager;
}

void SceneKeyConfig::inputNewKeyConfig(){
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_SlowMove, this->registedJoyPadCode_explode[KeyCodeExplode_SlowMove]);
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_ScatterBomb, this->registedJoyPadCode_explode[KeyCodeExplode_ScatterBomb]); 
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Ignition, this->registedJoyPadCode_explode[KeyCodeExplode_Ignition]);
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_ReleasePower, this->registedJoyPadCode_explode[KeyCodeExplode_ReleasePower]);
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_OK, this->registedJoyPadCode_OK);
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Cancel, this->registedJoyPadCode_cancel);
	Input::setRegistedKeyCodeJoyPad_Explode(KeyCodeExplode_Pause, this->registedJoyPadCode_pause);

	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_SlowMove, this->registedKeyBoardCode_explode[KeyCodeExplode_SlowMove]);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_ScatterBomb, this->registedKeyBoardCode_explode[KeyCodeExplode_ScatterBomb]);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Ignition, this->registedKeyBoardCode_explode[KeyCodeExplode_Ignition]);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_ReleasePower, this->registedKeyBoardCode_explode[KeyCodeExplode_ReleasePower]);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_OK, this->registedKeyBoardCode_OK);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Cancel, this->registedKeyBoardCode_cancel);
	Input::setRegistedKeyCodeKeyBoard_Explode(KeyCodeExplode_Pause, this->registedKeyBoardCode_pause);


	Input::setRegistedKeyCodeJoyPad_Stand(KeyCodeStand_SlowMove, this->registedJoyPadCode_stand[KeyCodeStand_SlowMove]);
	Input::setRegistedKeyCodeJoyPad_Stand(KeyCodeStand_ShotBullet, this->registedJoyPadCode_stand[KeyCodeStand_ShotBullet]);
	Input::setRegistedKeyCodeJoyPad_Stand(KeyCodeStand_StandFlex, this->registedJoyPadCode_stand[KeyCodeStand_StandFlex]);
	Input::setRegistedKeyCodeJoyPad_Stand(KeyCodeStand_StandHold, this->registedJoyPadCode_stand[KeyCodeStand_StandHold]);

	Input::setRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_SlowMove, this->registedKeyBoardCode_stand[KeyCodeStand_SlowMove]);
	Input::setRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_ShotBullet, this->registedKeyBoardCode_stand[KeyCodeStand_ShotBullet]);
	Input::setRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_StandFlex, this->registedKeyBoardCode_stand[KeyCodeStand_StandFlex]);
	Input::setRegistedKeyCodeKeyBoard_Stand(KeyCodeStand_StandHold, this->registedKeyBoardCode_stand[KeyCodeStand_StandHold]);


	Input::setRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_SlowMove, this->registedJoyPadCode_absorb[KeyCodeAbsorb_SlowMove]);
	Input::setRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Absorb, this->registedJoyPadCode_absorb[KeyCodeAbsorb_Absorb]);
	Input::setRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Release, this->registedJoyPadCode_absorb[KeyCodeAbsorb_Release]);
	Input::setRegistedKeyCodeJoyPad_Absorb(KeyCodeAbsorb_Collapsar, this->registedJoyPadCode_absorb[KeyCodeAbsorb_Collapsar]);

	Input::setRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_SlowMove, this->registedKeyBoardCode_absorb[KeyCodeAbsorb_SlowMove]);
	Input::setRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Absorb, this->registedKeyBoardCode_absorb[KeyCodeAbsorb_Absorb]);
	Input::setRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Release, this->registedKeyBoardCode_absorb[KeyCodeAbsorb_Release]);
	Input::setRegistedKeyCodeKeyBoard_Absorb(KeyCodeAbsorb_Collapsar, this->registedKeyBoardCode_absorb[KeyCodeAbsorb_Collapsar]);

	Input::writeNewKeyConfig();
}

void SceneKeyConfig::initPosOutOfScreen_Other(){
	for (int i = 0; i < 4; i++){
		this->other[i].start = Point(-640, 260 + 50 * i);
		this->other[i].end = Point(-640, 260 + 50 * i);
		this->other[i].count = 0;
	}
}

void SceneKeyConfig::initPosOutOfScreen_Explode(){
	for (int i = 0; i < 5; i++){
		this->explode[i].start = Point(-640, 260 + 50 * i);
		this->explode[i].end = Point(-640, 260 + 50 * i);
		this->explode[i].count = 0;
	}
}

void SceneKeyConfig::initPosOutOfScreen_Stand(){
	for (int i = 0; i < 5; i++){
		this->stand[i].start = Point(-640, 260 + 50 * i);
		this->stand[i].end = Point(-640, 260 + 50 * i);
		this->stand[i].count = 0;
	}
}

void SceneKeyConfig::initPosOutOfScreen_Absorb(){
	for (int i = 0; i < 5; i++){
		this->absorb[i].start = Point(-640, 260 + 50 * i);
		this->absorb[i].end = Point(-640, 260 + 50 * i);
		this->absorb[i].count = 0;
	}
}