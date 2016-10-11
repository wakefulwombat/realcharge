#include "sceneSelectBossPractice.h"
#include "music.h"
#include "picture.h"
#include "sound.h"
#include "input.h"
#include "DxLib.h"

SceneSelectBossPractice::SceneSelectBossPractice(ISetNextScene* changer, ISetDifficulty* isetDifficulty, IGetGameClearData* igetGameClearData){
	this->isetNextScene = changer;
	this->isetDifficulty = isetDifficulty;
	this->igetGameClearData = igetGameClearData;

	this->selectingType = 0;
	this->selectNum_level = 0;
	this->selectNum_spell = 0;
	this->selectNum_stage = 0;
	this->selectNum_mode = 0;

	for (int i = 0; i < 7; i++){
		this->stage[i].count = 0;
		this->stage[i].start = Point(-250, 300);
		this->stage[i].end = Point(150 + 300 * i, 300);
	}
	for (int i = 0; i < 3; i++){
		this->level[i].count = 0;
		this->level[i].start = Point(-250, -200);
		this->level[i].end = Point(-250, -200);
	}
	for (int i = 0; i < 18; i++){
		this->spell[i].count = 0;
		this->spell[i].start = Point(500, 700);
		this->spell[i].end = Point(500, 700);
	}
	for (int i = 0; i < 3; i++){
		this->mode[i].count = 0;
		this->mode[i].start = Point(-300, -200);
		this->mode[i].end = Point(-300, -200);
	}

	this->bfCount = 0;
	this->backEffectManager = new BackEffectManage();

	this->setSpellName();
	this->setSpellNumMax();
}

void SceneSelectBossPractice::initialize(){

}

void SceneSelectBossPractice::update(){
	if (this->selectingType == 0){//ステージ選択
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			if (this->selectNum_stage < 6){
				for (int i = 0; i < 3; i++){
					this->level[i].count = 0;
					this->level[i].start = Point(200, -100);
					this->level[i].end = Point(200, 250 + 100 * i);
				}

				this->selectNum_level = 0;
				this->selectNum_spell = 0;
				this->setSpellName();
				this->setSpellNumMax();
				for (int i = 0; i < 18; i++){
					if (i == this->spellNumMax) break;
					this->spell[i].end = Point(500, 260 + 40 * i);
					this->spell[i].start = Point(500, 700);
					this->spell[i].count = 0;
				}

				this->selectingType = 1;
			}
			else{
				this->selectNum_level = 1;
				this->selectNum_spell = 0;
				this->setSpellName();
				this->setSpellNumMax();
				for (int i = 0; i < 18; i++){
					if (i == this->spellNumMax) break;
					this->spell[i].end = Point(350, 300 + 40 * i);
					this->spell[i].start = Point(350, 700);
					this->spell[i].count = 0;
				}

				this->selectingType = 2;
			}


			for (int i = 0; i < 7; i++){
				if (i == this->selectNum_stage){
					this->stage[i].count = 0;
					this->stage[i].start = this->stage[i].end;
					this->stage[i].end = Point(50, 150);
				}
				else{
					this->stage[i].count = 0;
					this->stage[i].start = this->stage[i].end;
					this->stage[i].end += Point(0, -400);
				}
			}
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			this->isetNextScene->isetNextScene(Scene_Opening);
		}

		if (Input::getGridXDownOnce() == 1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_stage = (this->selectNum_stage + 1) % 7;
			this->setSpellName();
			this->setSpellNumMax();

			for (int i = 0; i < 7; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(150 + 300 * (i - this->selectNum_stage), 300);
			}
		}

		if (Input::getGridXDownOnce() == -1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_stage = (this->selectNum_stage + 6) % 7;
			this->setSpellName();
			this->setSpellNumMax();

			for (int i = 0; i < 7; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(150 + 300 * (i - this->selectNum_stage), 300);
			}
		}
	}
	else if (this->selectingType == 1){//難易度選択
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			
			for (int i = 0; i < 3; i++){
				if (i == this->selectNum_level){
					this->level[i].count = 0;
					this->level[i].start = this->level[i].end;
					this->level[i].end = Point(350, 150);
				}
				else{
					this->level[i].count = 0;
					this->level[i].start = this->level[i].end;
					this->level[i].end = Point(100,-100);
				}
			}

			for (int i = 0; i < 18; i++){
				this->spell[i].start = this->spell[i].end;
				this->spell[i].end = Point(350, 300 + 40 * i);
				this->spell[i].count = 0;
			}
			
			this->selectingType = 2;
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			
			for (int i = 0; i < 3; i++){
				this->level[i].count = 0;
				this->level[i].start = this->level[i].end;
				this->level[i].end = Point(350, -100);
			}
			for (int i = 0; i < 7; i++){
				this->stage[i].count = 0;
				this->stage[i].start = this->stage[i].end;
				this->stage[i].end = Point(150 + 300 * (i - this->selectNum_stage), 300);
			}
			for (int i = 0; i < 18; i++){
				this->spell[i].count = 0;
				this->spell[i].start = this->spell[i].end;
				this->spell[i].end = Point(500, 700);
			}

			this->selectingType = 0;
			this->selectNum_level = 0;
		}

		if (Input::getGridYDownOnce() == 1){
			this->selectNum_level = (this->selectNum_level + 1) % 3;
			this->setSpellName();
			Sound::playSound(Sound_SelectMove);
		}

		if (Input::getGridYDownOnce() == -1){
			this->selectNum_level = (this->selectNum_level + 2) % 3;
			this->setSpellName();
			Sound::playSound(Sound_SelectMove);
		}

		for (int i = 0; i < 7; i++){
			this->stage[i].count++;
		}
		for (int i = 0; i < 3; i++){
			this->level[i].count++;
		}
	}
	else if (this->selectingType == 2){//スペル選択
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);
			
			for (int i = 0; i < 18; i++){
				this->spell[i].count = 0;
				this->spell[i].start = this->spell[i].end;
				if (i == this->selectNum_spell){
					this->spell[i].end = Point(570, 180);
				}
				else{
					this->spell[i].end = Point(350, 700);
				}
			}

			this->selectNum_mode = 0;
			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = Point(-300, 250);
				this->mode[i].end = Point(250 + 300 * i, 250);
			}

			this->selectingType = 3;
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);
			if (this->selectNum_stage < 6) {
				this->selectingType = 1;
				for (int i = 0; i < 3; i++){
					this->level[i].count = 0;
					this->level[i].start = this->level[i].end;
					this->level[i].end = Point(200, 250 + 100 * i);
				}

				for (int i = 0; i < 18; i++){
					this->spell[i].start = this->spell[i].end;
					this->spell[i].end = Point(500, 260 + 40 * i);
					this->spell[i].count = 0;
				}
			}
			else {
				this->selectingType = 0;
				for (int i = 0; i < 7; i++){
					this->stage[i].count = 0;
					this->stage[i].start = this->stage[i].end;
					this->stage[i].end = Point(150 + 300 * (i - this->selectNum_stage), 300);
				}

				for (int i = 0; i < 18; i++){
					this->spell[i].start = this->spell[i].end;
					this->spell[i].end = Point(350, 700);
					this->spell[i].count = 0;
				}
			}

			this->selectNum_spell = 0;
		}

		if (Input::getGridYDownOnce() == 1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_spell = (this->selectNum_spell + 1) % this->spellNumMax;

			for (int i = 0; i < 18; i++){
				this->spell[i].count = 0;
				this->spell[i].start = this->spell[i].end;
				this->spell[i].end = Point(350, 300 + 40 * (i - this->selectNum_spell));
			}
		}

		if (Input::getGridYDownOnce() == -1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_spell = (this->selectNum_spell + this->spellNumMax - 1) % this->spellNumMax;
			
			for (int i = 0; i < 18; i++){
				this->spell[i].count = 0;
				this->spell[i].start = this->spell[i].end;
				this->spell[i].end = Point(350, 300 + 40 * (i - this->selectNum_spell));
			}
		}
	}
	else{//モード選択
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//決定
			Sound::playSound(Sound_Decide);

			this->isetDifficulty->isetStageNum(this->selectNum_stage);
			this->isetDifficulty->isetDifficulty(this->selectNum_level);
			this->isetDifficulty->isetBossAttackNum(this->selectNum_spell);
			this->isetDifficulty->isetModeEX(this->selectNum_mode);
			this->isetNextScene->isetNextScene(Scene_BossPractice);
			Music::playMusic(Music_Tutorial);
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//キャンセル
			Sound::playSound(Sound_Cancel);

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(-300, 300);
			}

			for (int i = 0; i < 18; i++){
				this->spell[i].count = 0;
				this->spell[i].start = this->spell[i].end;
				this->spell[i].end = Point(350, 300 + 40 * (i - this->selectNum_spell));
			}

			this->selectingType = 2;
		}

		if (Input::getGridXDownOnce() == 1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_mode = (this->selectNum_mode + 1) % 3;

			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(250 + 300 * (i - this->selectNum_mode), 250);
			}
		}

		if (Input::getGridXDownOnce() == -1){
			Sound::playSound(Sound_SelectMove);
			this->selectNum_mode = (this->selectNum_mode + 2) % 3;
			for (int i = 0; i < 3; i++){
				this->mode[i].count = 0;
				this->mode[i].start = this->mode[i].end;
				this->mode[i].end = Point(250 + 300 * (i - this->selectNum_mode), 250);
			}
		}
	}

	for (int i = 0; i < 7; i++){
		this->stage[i].count++;
	}
	for (int i = 0; i < 3; i++){
		this->level[i].count++;
	}
	for (int i = 0; i < 18; i++){
		this->spell[i].count++;
	}
	for (int i = 0; i < 3; i++){
		this->mode[i].count++;
	}

	this->bfCount++;
	if (this->bfCount == 20){
		this->bfCount = 0;
		this->backEffectManager->isetBackEffect(GetRand(5), Point(1.0*GetRand(WINDOW_WIDTH), -100.0));
	}
	this->backEffectManager->update();
}

void SceneSelectBossPractice::draw(){
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawGraph(0, 0, Picture::getBack(1), false);

	if (this->selectingType == 0){
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawGraph(50, 30, Picture::getSelectText(SEL_STAGESELECT), true);
	}
	else if (this->selectingType == 1){
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawGraph(50, 30, Picture::getSelectText(SEL_RANKSELECT), true);
	}
	else if (this->selectingType == 2){
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		DrawGraph(50, 30, Picture::getSelectText(SEL_ATTACKSELECT), true);
	}
	else{
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		DrawGraph(50, 30, Picture::getSelectText(SEL_MODESELECT), true);
	}

	double x, y;
	for (int i = 0; i < 7; i++){
		if (i == this->selectNum_stage){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		}
		else{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}

		if (this->stage[i].count < 15){
			x = 2.0*(this->stage[i].end.x - this->stage[i].start.x)*this->stage[i].count / 15 - (this->stage[i].end.x - this->stage[i].start.x)*this->stage[i].count*this->stage[i].count / 15 / 15 + this->stage[i].start.x;
			y = 2.0*(this->stage[i].end.y - this->stage[i].start.y)*this->stage[i].count / 15 - (this->stage[i].end.y - this->stage[i].start.y)*this->stage[i].count*this->stage[i].count / 15 / 15 + this->stage[i].start.y;
		}
		else{
			x = this->stage[i].end.x;
			y = this->stage[i].end.y;
		}
		DrawGraph(x, y, Picture::getSelectText((TextPictureKind)(SEL_STAGE1 + i)), true);
	}

	for (int i = 0; i < 3; i++){
		if (i == this->selectNum_level){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		}
		else{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}

		if (this->level[i].count < 15){
			x = 2.0*(this->level[i].end.x - this->level[i].start.x)*this->level[i].count / 15 - (this->level[i].end.x - this->level[i].start.x)*this->level[i].count*this->level[i].count / 15 / 15 + this->level[i].start.x;
			y = 2.0*(this->level[i].end.y - this->level[i].start.y)*this->level[i].count / 15 - (this->level[i].end.y - this->level[i].start.y)*this->level[i].count*this->level[i].count / 15 / 15 + this->level[i].start.y;
		}
		else{
			x = this->level[i].end.x;
			y = this->level[i].end.y;
		}
		DrawGraph(x, y, Picture::getSelectText((TextPictureKind)(SEL_EASY + i)), true);
	}

	for (int i = this->selectNum_spell; i < this->selectNum_spell + 6; i++){
		if (i == this->spellNumMax) break;

		if (this->selectingType != 1){
			if (i == this->selectNum_spell){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			}
			else{
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
			}
		}
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);

		if (this->spell[i].count < 15){
			x = 2.0*(this->spell[i].end.x - this->spell[i].start.x)*this->spell[i].count / 15 - (this->spell[i].end.x - this->spell[i].start.x)*this->spell[i].count*this->spell[i].count / 15 / 15 + this->spell[i].start.x;
			y = 2.0*(this->spell[i].end.y - this->spell[i].start.y)*this->spell[i].count / 15 - (this->spell[i].end.y - this->spell[i].start.y)*this->spell[i].count*this->spell[i].count / 15 / 15 + this->spell[i].start.y;
		}
		else{
			x = this->spell[i].end.x;
			y = this->spell[i].end.y;
		}
		DrawString(x, y, this->spellName[i].c_str(), GetColor(255, 255, 255));
		if (this->igetGameClearData->igetBossAttackClearData(this->selectNum_stage, this->selectNum_level, i) == true) DrawRotaGraph2(x-20, y, 75, 30, 0.5, -M_PI / 6, Picture::getSelectText(SEL_CLEAR), true);
	}

	for (int i = 0; i < 3; i++){
		if (i == this->selectNum_mode){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
		}
		else{
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 100);
		}

		if (this->mode[i].count < 15){
			x = 2.0*(this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count / 15 - (this->mode[i].end.x - this->mode[i].start.x)*this->mode[i].count*this->mode[i].count / 15 / 15 + this->mode[i].start.x;
			y = 2.0*(this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count / 15 - (this->mode[i].end.y - this->mode[i].start.y)*this->mode[i].count*this->mode[i].count / 15 / 15 + this->mode[i].start.y;
		}
		else{
			x = this->mode[i].end.x;
			y = this->mode[i].end.y;
		}
		DrawGraph(x, y, Picture::getPlayerModeExplain(i), true);
		if (this->igetGameClearData->igetBossAttackClearDataDetail(this->selectNum_stage, this->selectNum_level, this->selectNum_spell, i) == true) DrawRotaGraph2(x+150,y+150, 75, 30, 1.0, -M_PI / 6, Picture::getSelectText(SEL_CLEAR), true);
	}

	this->backEffectManager->draw();
}

void SceneSelectBossPractice::finalize(){
	delete this->backEffectManager;
}

void SceneSelectBossPractice::setSpellNumMax(){
	switch (this->selectNum_stage){
	case 0: this->spellNumMax = 4; break;
	case 1: this->spellNumMax = 6; break;
	case 2: this->spellNumMax = 6; break;
	case 3: this->spellNumMax = 8; break;
	case 4: this->spellNumMax = 8; break;
	case 5: this->spellNumMax = 8; break;
	case 6: this->spellNumMax = 18; break;
	}
}

void SceneSelectBossPractice::setSpellName(){
	if (this->selectNum_stage == 6){
		this->spellName[0] = "アマテラスの導き";
		this->spellName[1] = "ラララライ麦畑でつかまえて";
		this->spellName[2] = "高速ナイフシャワー";
		this->spellName[3] = "ワイリー凍結仮説";
		this->spellName[4] = "彗星の赤いシャア";
		this->spellName[5] = "リンガディンドン";
		this->spellName[6] = "ジェットスキードリーマー";
		this->spellName[7] = "ミスティックアークアロー";
		this->spellName[8] = "天高く虹の橋立";
		this->spellName[9] = "スターダストアレイ";
		this->spellName[10] = "びりびりすぱーく";
		this->spellName[11] = "金のハンマー銀の弾丸";
		this->spellName[12] = "雷神グサンタケミカヅチ";
		this->spellName[13] = "ウカノミタマウィルス";
		this->spellName[14] = "ロケットゼロテイクオフ";
		this->spellName[15] = "ナトリウムが実に面白い";
		this->spellName[16] = "サークルメイズ";
		this->spellName[17] = "今宵星が見えずとも";
		return;
	}

	if (this->selectNum_level == 0){
		if (this->selectNum_stage == 0){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "迷刀政宗";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "秘剣武蔵";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "きれいな花が咲きました";
			this->spellName[1] = "トイレで跳ね返るアレ";
			this->spellName[2] = "名無し１";
			this->spellName[3] = "ドッチビーで大乱闘したらこうなる";
			this->spellName[4] = "親方！空から星屑が！";
			this->spellName[5] = "パチモンクオリティ";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "ハゲアンプ";
			this->spellName[2] = "オレンジクロスパープルクロス";
			this->spellName[3] = "ミラーボールマン";
			this->spellName[4] = "名無し２";
			this->spellName[5] = "恐怖体験！寝起きの枕";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "掘ラートイレの音姫さん";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "ビッグベンフォーリンダウン";
			this->spellName[4] = "名無し３";
			this->spellName[5] = "三位一体絶叫ビッグベン";
			this->spellName[6] = "名無し４";
			this->spellName[7] = "レズとゲイがありあまる";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "センコウ花火";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "すべてが枯草になる";
			this->spellName[4] = "これフラクタルなんだぜ";
			this->spellName[5] = "開花乱舞";
			this->spellName[6] = "名無し３";
			this->spellName[7] = "大地が見た夢";
		}
		else {
			this->spellName[0] = "名無し１";
			this->spellName[1] = "ミルキーウェイパレード";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "囚われた火鳥";
			this->spellName[4] = "核爆発イリュージョン";
			this->spellName[5] = "イドはリビドーの夢を見るか";
			this->spellName[6] = "スキツォフレニア";
			this->spellName[7] = "クローズドゲートアセンション";
		}
	}
	else if (this->selectNum_level == 1){
		if (this->selectNum_stage == 0){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "迷刀政宗";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "秘剣武蔵";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "きれいな花が咲きました";
			this->spellName[1] = "トイレで跳ね返るアレ";
			this->spellName[2] = "名無し１";
			this->spellName[3] = "ドッチビーで大乱闘したらこうなる";
			this->spellName[4] = "親方！空から流れ星が！";
			this->spellName[5] = "パチモンクオリティ";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "ヘッドリフレクショナルオペアンプ";
			this->spellName[2] = "オレンジクロスパープルクロス";
			this->spellName[3] = "ミラーボールマン";
			this->spellName[4] = "名無し２";
			this->spellName[5] = "恐怖体験！寝起きの枕";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "掘ラートイレの音姫さん";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "ビッグベンフォーリンダウン";
			this->spellName[4] = "名無し３";
			this->spellName[5] = "三位一体絶叫ビッグベン";
			this->spellName[6] = "名無し４";
			this->spellName[7] = "レズとゲイがありあまる";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "センコウ花火";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "すべてが枯草になる";
			this->spellName[4] = "これフラクタルなんだぜ";
			this->spellName[5] = "開花乱舞";
			this->spellName[6] = "名無し３";
			this->spellName[7] = "大地が見た夢";
		}
		else {
			this->spellName[0] = "名無し１";
			this->spellName[1] = "ミルキーウェイパレード";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "囚われた火鳥";
			this->spellName[4] = "核爆発イリュージョン";
			this->spellName[5] = "イドはリビドーの夢を見るか";
			this->spellName[6] = "スキツォフレニア";
			this->spellName[7] = "クローズドゲートアセンション";
		}
	}
	else{
		if (this->selectNum_stage == 0){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "名刀政宗";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "魔剣武蔵";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "きれいな花が咲きました";
			this->spellName[1] = "トイレで跳ね返るアレ";
			this->spellName[2] = "名無し１";
			this->spellName[3] = "ドッチビーで大乱闘したらこうなる";
			this->spellName[4] = "親方！空から流星群が！";
			this->spellName[5] = "パチモンクオリティ";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "ヘッドリフレクショナルオペアンプ";
			this->spellName[2] = "クロスリザレクション";
			this->spellName[3] = "ミラーボールマン";
			this->spellName[4] = "名無し２";
			this->spellName[5] = "恐怖体験！寝起きの枕";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "掘ラートイレの音姫さん";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "ビッグベンディストラクション";
			this->spellName[4] = "名無し３";
			this->spellName[5] = "三位一体絶叫ビッグベン";
			this->spellName[6] = "名無し４";
			this->spellName[7] = "レズとゲイがありあまる";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "名無し１";
			this->spellName[1] = "センコウ花火";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "すべてが枯草になる";
			this->spellName[4] = "これフラクタルなんだぜ";
			this->spellName[5] = "開花乱舞";
			this->spellName[6] = "名無し３";
			this->spellName[7] = "大地が見た夢";
		}
		else {
			this->spellName[0] = "名無し１";
			this->spellName[1] = "星の降る生誕祭";
			this->spellName[2] = "名無し２";
			this->spellName[3] = "囚われた火鳥";
			this->spellName[4] = "核爆発イリュージョン";
			this->spellName[5] = "イドはリビドーの夢を見るか";
			this->spellName[6] = "スキツォフレニア";
			this->spellName[7] = "クローズドゲートアセンション";
		}
	}
}