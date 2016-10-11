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
	if (this->selectingType == 0){//�X�e�[�W�I��
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//����
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

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//�L�����Z��
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
	else if (this->selectingType == 1){//��Փx�I��
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//����
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

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//�L�����Z��
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
	else if (this->selectingType == 2){//�X�y���I��
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//����
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

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//�L�����Z��
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
	else{//���[�h�I��
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){//����
			Sound::playSound(Sound_Decide);

			this->isetDifficulty->isetStageNum(this->selectNum_stage);
			this->isetDifficulty->isetDifficulty(this->selectNum_level);
			this->isetDifficulty->isetBossAttackNum(this->selectNum_spell);
			this->isetDifficulty->isetModeEX(this->selectNum_mode);
			this->isetNextScene->isetNextScene(Scene_BossPractice);
			Music::playMusic(Music_Tutorial);
		}

		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){//�L�����Z��
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
		this->spellName[0] = "�A�}�e���X�̓���";
		this->spellName[1] = "���������C�����ł��܂���";
		this->spellName[2] = "�����i�C�t�V�����[";
		this->spellName[3] = "���C���[��������";
		this->spellName[4] = "�a���̐Ԃ��V���A";
		this->spellName[5] = "�����K�f�B���h��";
		this->spellName[6] = "�W�F�b�g�X�L�[�h���[�}�[";
		this->spellName[7] = "�~�X�e�B�b�N�A�[�N�A���[";
		this->spellName[8] = "�V�������̋���";
		this->spellName[9] = "�X�^�[�_�X�g�A���C";
		this->spellName[10] = "�т�т肷�ρ[��";
		this->spellName[11] = "���̃n���}�[��̒e��";
		this->spellName[12] = "���_�O�T���^�P�~�J�d�`";
		this->spellName[13] = "�E�J�m�~�^�}�E�B���X";
		this->spellName[14] = "���P�b�g�[���e�C�N�I�t";
		this->spellName[15] = "�i�g���E�������ɖʔ���";
		this->spellName[16] = "�T�[�N�����C�Y";
		this->spellName[17] = "���������������Ƃ�";
		return;
	}

	if (this->selectNum_level == 0){
		if (this->selectNum_stage == 0){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�������@";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "�錕����";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "���ꂢ�ȉԂ��炫�܂���";
			this->spellName[1] = "�g�C���Œ��˕Ԃ�A��";
			this->spellName[2] = "�������P";
			this->spellName[3] = "�h�b�`�r�[�ő嗐�������炱���Ȃ�";
			this->spellName[4] = "�e���I�󂩂琯�����I";
			this->spellName[5] = "�p�`�����N�I���e�B";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�n�Q�A���v";
			this->spellName[2] = "�I�����W�N���X�p�[�v���N���X";
			this->spellName[3] = "�~���[�{�[���}��";
			this->spellName[4] = "�������Q";
			this->spellName[5] = "���|�̌��I�Q�N���̖�";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�@���[�g�C���̉��P����";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "�r�b�O�x���t�H�[�����_�E��";
			this->spellName[4] = "�������R";
			this->spellName[5] = "�O�ʈ�̐⋩�r�b�O�x��";
			this->spellName[6] = "�������S";
			this->spellName[7] = "���Y�ƃQ�C�����肠�܂�";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�Z���R�E�ԉ�";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "���ׂĂ��͑��ɂȂ�";
			this->spellName[4] = "����t���N�^���Ȃ񂾂�";
			this->spellName[5] = "�J�ԗ���";
			this->spellName[6] = "�������R";
			this->spellName[7] = "��n��������";
		}
		else {
			this->spellName[0] = "�������P";
			this->spellName[1] = "�~���L�[�E�F�C�p���[�h";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "����ꂽ�Β�";
			this->spellName[4] = "�j�����C�����[�W����";
			this->spellName[5] = "�C�h�̓��r�h�[�̖������邩";
			this->spellName[6] = "�X�L�c�H�t���j�A";
			this->spellName[7] = "�N���[�Y�h�Q�[�g�A�Z���V����";
		}
	}
	else if (this->selectNum_level == 1){
		if (this->selectNum_stage == 0){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�������@";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "�錕����";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "���ꂢ�ȉԂ��炫�܂���";
			this->spellName[1] = "�g�C���Œ��˕Ԃ�A��";
			this->spellName[2] = "�������P";
			this->spellName[3] = "�h�b�`�r�[�ő嗐�������炱���Ȃ�";
			this->spellName[4] = "�e���I�󂩂痬�ꐯ���I";
			this->spellName[5] = "�p�`�����N�I���e�B";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�w�b�h���t���N�V���i���I�y�A���v";
			this->spellName[2] = "�I�����W�N���X�p�[�v���N���X";
			this->spellName[3] = "�~���[�{�[���}��";
			this->spellName[4] = "�������Q";
			this->spellName[5] = "���|�̌��I�Q�N���̖�";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�@���[�g�C���̉��P����";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "�r�b�O�x���t�H�[�����_�E��";
			this->spellName[4] = "�������R";
			this->spellName[5] = "�O�ʈ�̐⋩�r�b�O�x��";
			this->spellName[6] = "�������S";
			this->spellName[7] = "���Y�ƃQ�C�����肠�܂�";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�Z���R�E�ԉ�";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "���ׂĂ��͑��ɂȂ�";
			this->spellName[4] = "����t���N�^���Ȃ񂾂�";
			this->spellName[5] = "�J�ԗ���";
			this->spellName[6] = "�������R";
			this->spellName[7] = "��n��������";
		}
		else {
			this->spellName[0] = "�������P";
			this->spellName[1] = "�~���L�[�E�F�C�p���[�h";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "����ꂽ�Β�";
			this->spellName[4] = "�j�����C�����[�W����";
			this->spellName[5] = "�C�h�̓��r�h�[�̖������邩";
			this->spellName[6] = "�X�L�c�H�t���j�A";
			this->spellName[7] = "�N���[�Y�h�Q�[�g�A�Z���V����";
		}
	}
	else{
		if (this->selectNum_stage == 0){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�������@";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "��������";
		}
		else if (this->selectNum_stage == 1){
			this->spellName[0] = "���ꂢ�ȉԂ��炫�܂���";
			this->spellName[1] = "�g�C���Œ��˕Ԃ�A��";
			this->spellName[2] = "�������P";
			this->spellName[3] = "�h�b�`�r�[�ő嗐�������炱���Ȃ�";
			this->spellName[4] = "�e���I�󂩂痬���Q���I";
			this->spellName[5] = "�p�`�����N�I���e�B";
		}
		else if (this->selectNum_stage == 2){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�w�b�h���t���N�V���i���I�y�A���v";
			this->spellName[2] = "�N���X���U���N�V����";
			this->spellName[3] = "�~���[�{�[���}��";
			this->spellName[4] = "�������Q";
			this->spellName[5] = "���|�̌��I�Q�N���̖�";
		}
		else if (this->selectNum_stage == 3){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�@���[�g�C���̉��P����";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "�r�b�O�x���f�B�X�g���N�V����";
			this->spellName[4] = "�������R";
			this->spellName[5] = "�O�ʈ�̐⋩�r�b�O�x��";
			this->spellName[6] = "�������S";
			this->spellName[7] = "���Y�ƃQ�C�����肠�܂�";
		}
		else if (this->selectNum_stage == 4){
			this->spellName[0] = "�������P";
			this->spellName[1] = "�Z���R�E�ԉ�";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "���ׂĂ��͑��ɂȂ�";
			this->spellName[4] = "����t���N�^���Ȃ񂾂�";
			this->spellName[5] = "�J�ԗ���";
			this->spellName[6] = "�������R";
			this->spellName[7] = "��n��������";
		}
		else {
			this->spellName[0] = "�������P";
			this->spellName[1] = "���̍~�鐶�a��";
			this->spellName[2] = "�������Q";
			this->spellName[3] = "����ꂽ�Β�";
			this->spellName[4] = "�j�����C�����[�W����";
			this->spellName[5] = "�C�h�̓��r�h�[�̖������邩";
			this->spellName[6] = "�X�L�c�H�t���j�A";
			this->spellName[7] = "�N���[�Y�h�Q�[�g�A�Z���V����";
		}
	}
}