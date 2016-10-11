#include "sceneSelectDifficulty.h"
#include "DxLib.h"
#include "picture.h"
#include "input.h"
#include "sound.h"

SceneSelectDifficulty::SceneSelectDifficulty(ISetNextScene* changer, ISetDifficulty* setDifficulty, IGetGameClearData* igetGameClearData){
	this->isetNextScene = changer;
	this->selecting_type = 0;
	this->selectNum_difficulty = 0;
	this->selectNum_mode = 0;
	this->setDifficulty = setDifficulty;
	this->igetGameClearData = igetGameClearData;

	this->bfCount = 0;
	this->backEffectManager = new BackEffectManage();

	this->difficulty[0].start = Point();
	this->difficulty[1].start = Point();
	this->difficulty[2].start = Point();
	this->difficulty[0].end = Point(350, 300);
	this->difficulty[1].end = Point(600, 550);
	this->difficulty[2].end = Point(850, 800);
	this->difficulty[0].count = 0;
	this->difficulty[1].count = 0;
	this->difficulty[2].count = 0;

	this->mode[0].start = Point(-300, 200);
	this->mode[0].end = Point(-300, 200);
	this->mode[0].count = 0;
	this->mode[1].start = Point(-300, 200);
	this->mode[1].end = Point(-300, 200);
	this->mode[1].count = 0;
	this->mode[2].start = Point(-300, 200);
	this->mode[2].end = Point(-300, 200);
	this->mode[2].count = 0;
}

void SceneSelectDifficulty::initialize(){

}

void SceneSelectDifficulty::update(){
	if (this->selecting_type == 0){//difficulty
		if (Input::getGridYDownOnce() == 1){
			this->selectNum_difficulty = (this->selectNum_difficulty + 1) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(350 + 250 * (i - this->selectNum_difficulty), 300 + 250 * (i - this->selectNum_difficulty));
			}
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectNum_difficulty = (this->selectNum_difficulty + 2) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(350 + 250 * (i - this->selectNum_difficulty), 300 + 250 * (i - this->selectNum_difficulty));
			}
		}
		if (Input::getGridXDownOnce() == 1){
			this->selectNum_difficulty = (this->selectNum_difficulty + 1) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(350 + 250 * (i - this->selectNum_difficulty), 300 + 250 * (i - this->selectNum_difficulty));
			}
		}
		if (Input::getGridXDownOnce() == -1){
			this->selectNum_difficulty = (this->selectNum_difficulty + 2) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(350 + 250 * (i - this->selectNum_difficulty), 300 + 250 * (i - this->selectNum_difficulty));
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->mode[i].count = 0;

				this->difficulty[i].start = this->difficulty[i].end;
				if (i == this->selectNum_difficulty) this->difficulty[i].end = Point(100, 150);
				else this->difficulty[i].end = Point(-100, -100);

				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectNum_mode) + 270, 200);
			}

			this->selecting_type = 1;
		}
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			this->isetNextScene->isetNextScene(Scene_Opening);
		}
	}
	else{
		if (Input::getGridXDownOnce() == 1){
			this->selectNum_mode = (this->selectNum_mode + 1) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectNum_mode) + 270, 200);
			}
		}
		if (Input::getGridXDownOnce() == -1){
			this->selectNum_mode = (this->selectNum_mode + 2) % 3;
			Sound::playSound(Sound_SelectMove);

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(400 * (i - this->selectNum_mode) + 270, 200);
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			this->setDifficulty->isetDifficulty(this->selectNum_difficulty);
			this->setDifficulty->isetModeEX(this->selectNum_mode);
			this->setDifficulty->isetStageNum(1);
			this->isetNextScene->isetNextScene(Scene_GameFilm);
		}
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);

			for (int i = 0; i < 3; i++){
				this->difficulty[i].count = 0;
				this->mode[i].count = 0;

				this->difficulty[i].start = this->difficulty[i].end;
				this->difficulty[i].end = Point(350 + 250 * (i - this->selectNum_difficulty), 300 + 250 * (i - this->selectNum_difficulty));

				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(-300, 200);
			}

			this->selecting_type = 0;
		}
	}

	for (int i = 0; i < 3; i++){
		this->difficulty[i].count++;
		this->mode[i].count++;
	}

	this->bfCount++;
	if(this->bfCount==10){
		this->bfCount=0;
		this->backEffectManager->isetBackEffect(GetRand(5),Point(1.0*GetRand(WINDOW_WIDTH),-100.0));
	}
	this->backEffectManager->update();
}

void SceneSelectDifficulty::draw(){
	this->backEffectManager->draw();

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
	DrawGraph(0, 0, Picture::getBack(1), false);
	if (this->selecting_type == 0) DrawGraph(50, 30, Picture::getSelectText(SEL_RANKSELECT), true);
	else DrawGraph(50, 30, Picture::getSelectText(SEL_MODESELECT), true);

	for (int i = 0; i < 3; i++){
		if (i == this->selectNum_difficulty) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->difficulty[i].count < 30){
			DrawGraph(2.0*(this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count / 30 - (this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.x, 2.0*(this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count / 30 - (this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.y, Picture::getSelectText((TextPictureKind)(SEL_EASY + i)), true);
			if(this->selecting_type==0) DrawGraph(2.0*(this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count / 30 - (this->difficulty[i].end.x - this->difficulty[i].start.x)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.x - 70, 2.0*(this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count / 30 - (this->difficulty[i].end.y - this->difficulty[i].start.y)*this->difficulty[i].count*this->difficulty[i].count / 900 + this->difficulty[i].start.y + 60, Picture::getSelectText((TextPictureKind)(SEL_EXPLAINEATTACKING + i)), true);
		}
		else{
			DrawGraph(this->difficulty[i].end.x, this->difficulty[i].end.y, Picture::getSelectText((TextPictureKind)(SEL_EASY + i)), true);
			if (this->selecting_type == 0) DrawGraph(this->difficulty[i].end.x - 70, this->difficulty[i].end.y + 60, Picture::getSelectText((TextPictureKind)(SEL_EXPLAINEATTACKING + i)), true);
		}

		if (i == this->selectNum_mode) SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->mode[i].count < 30){
			DrawGraph(2.0*(this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count / 30 - (this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.x, 2.0*(this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count / 30 - (this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.y, Picture::getPlayerModeExplain(i), true);
			if (this->igetGameClearData->igetStageClearData(this->selectNum_difficulty,i) == true){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				DrawRotaGraph2(2.0*(this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count / 30 - (this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.x + 150, 2.0*(this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count / 30 - (this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count*this->mode[i].count / 900 + this->mode[i].start.y + 150, 75, 30, 1.0, -M_PI / 4, Picture::getSelectText(SEL_CLEAR), true);
			}
		}
		else{
			DrawGraph(this->mode[i].end.x, this->mode[i].end.y, Picture::getPlayerModeExplain(i), true);
			if (this->igetGameClearData->igetStageClearData(this->selectNum_difficulty,i) == true){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
				DrawRotaGraph2(this->mode[i].end.x + 150, this->mode[i].end.y + 150, 75, 30, 1.0, -M_PI / 4, Picture::getSelectText(SEL_CLEAR), true);
			}
		}
	}
}

void SceneSelectDifficulty::finalize(){
	delete this->backEffectManager;
}