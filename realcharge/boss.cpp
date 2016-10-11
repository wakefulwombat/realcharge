#include "boss.h"
#include "DxLib.h"
#include "picture.h"
#include "item.h"

Boss::Boss(int id, int chara_chip, Point initialPos, IGetBossAttackInfo* igetBossAttackInfo, bool isBossPractice){
	this->id = id;
	this->charaChip = chara_chip;
	this->position = initialPos;
	this->HP = 1;
	this->igetBossAttackInfo = igetBossAttackInfo;
	this->trans_rad = 0.0;
	this->status = ChStatus_Waiting;

	this->bossAttack = NULL;

	this->isBossPractice = isBossPractice;

	this->animationDistanceTime = 15;
	this->chip_rad = 0.0;
	this->trans_rad = 0.0;
	this->rotate_rad = 0;
	this->count = 0;

	switch (chara_chip){
	case 0:this->size = Size(24, 40); break;
	case 1:this->size = Size(24, 40); break;
	case 2:this->size = Size(22, 38); break;
	case 3:this->size = Size(28, 36); break;
	case 4:this->size = Size(26, 40); break;
	case 5:this->size = Size(24, 42); break;
	case 6:this->size = Size(26, 40); break;
	case 7:this->size = Size(28, 38); break;
	case 8:this->size = Size(28, 40); break;
	case 9:this->size = Size(24, 40); break;
	case 10:this->size = Size(24, 40); break;
	case 11:this->size = Size(28, 40); break;
	case 12:this->size = Size(24, 40); break;
	case 13:this->size = Size(28, 42); break;
	case 14:this->size = Size(28, 44); break;
	case 15:this->size = Size(26, 42); break;
	case 16:this->size = Size(24, 40); break;
	case 17:this->size = Size(24, 42); break;
	case 18:this->size = Size(26, 40); break;
	case 19:this->size = Size(24, 42); break;
	case 20:this->size = Size(24, 42); break;
	case 21:this->size = Size(26, 40); break;
	case 22:this->size = Size(24, 40); break;
	case 23:this->size = Size(26, 40); break;
	case 24:this->size = Size(26, 40); break;
	}
}

void Boss::initialize(){

}

void Boss::update(){
	this->count++;
	if (this->count%this->animationDistanceTime == 0)this->chip_rad += M_PI / 2;

	switch (this->status){
	case ChStatus_Normal://UŒ‚
	
		this->bossAttack->move();
		this->bossAttack->attack();

		if (this->count % 60 == 0){
			this->isetItem->isetItem(this->position+Point(GetRand(100)-50,GetRand(100)-50), (ItemColor)GetRand(1), Item_Small, this->igetPlayerPosition);
		}

		break;
	
	case ChStatus_Preparing://ŸUŒ‚‚Ì‚½‚ß‚ÌˆÚ“®
	
		this->position.x = this->moveFrom.x + 2.0*(this->moveTo.x - this->moveFrom.x)*this->count / this->moveTime - (this->moveTo.x - this->moveFrom.x)*this->count*this->count / this->moveTime / this->moveTime;
		this->position.y = this->moveFrom.y + 2.0*(this->moveTo.y - this->moveFrom.y)*this->count / this->moveTime - (this->moveTo.y - this->moveFrom.y)*this->count*this->count / this->moveTime / this->moveTime;
		this->trans_rad = atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x);

		if (this->count == 60){
			this->count = 0;
			this->status = ChStatus_Recovering;
			this->trans_rad = M_PI / 2;
			this->direction = dir_down;
		}

		break;

	case ChStatus_Recovering://‘Ì—ÍƒQ[ƒW‚ğ‚½‚ß‚é
		
		this->HP = this->count * this->bossAttack->getHPMax() / 240;

		if (this->count == 240){
			this->count = 0;
			this->status = ChStatus_Normal;
		}
		break;

	case ChStatus_Waiting:
		this->direction = dir_down;
		break;
	}

	this->adjustTransRad();
	this->getDirectionFromTransRad();

}

void Boss::externalUpdate(){
	this->eventCount++;
	if (this->eventCount%this->animationDistanceTime == 0)this->chip_rad += M_PI / 2;

	if (this->eventCount < this->eventMoveTime){
		this->position.x = this->eventMoveFrom.x + 2.0*(this->eventMoveTo.x - this->eventMoveFrom.x)*this->eventCount / this->eventMoveTime - (this->eventMoveTo.x - this->eventMoveFrom.x)*this->eventCount*this->eventCount / this->eventMoveTime / this->eventMoveTime;
		this->position.y = this->eventMoveFrom.y + 2.0*(this->eventMoveTo.y - this->eventMoveFrom.y)*this->eventCount / this->eventMoveTime - (this->eventMoveTo.y - this->eventMoveFrom.y)*this->eventCount*this->eventCount / this->eventMoveTime / this->eventMoveTime;
		this->trans_rad = atan2(this->eventMoveTo.y - this->eventMoveFrom.y, this->eventMoveTo.x - this->eventMoveFrom.x);
		
		this->adjustTransRad();
		this->getDirectionFromTransRad();
	}
	else{
		this->direction = dir_down;
	}
}

void Boss::draw(){
	if ((this->status == ChStatus_Normal) || (this->status == ChStatus_Recovering)){
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
		double percent = 1.0*this->HP / this->bossAttack->getHPMax();
		DrawCircleGauge(GAME_WINDOW_OFFSET_X + (int)this->position.x, GAME_WINDOW_OFFSET_Y + (int)this->position.y, 100.0*percent, Picture::getEnemyLife());
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X + (int)this->position.x, GAME_WINDOW_OFFSET_Y + (int)this->position.y, this->size.width / 2-1, this->size.height / 2-1, 1.0, 0.0, Picture::getEnemy(this->charaChip, this->direction, this->chip_rad), true);

	if ((this->status == ChStatus_Normal) || (this->status == ChStatus_Recovering)){
		if (this->isBossPractice == false){
			for (int i = 0; i < this->igetBossAttackInfo->igetHowManyBossAttackInBattle() - this->igetBossAttackInfo->igetAttackNumCount(); i++){
				if (i < 8) DrawRotaGraph2(GAME_WINDOW_OFFSET_X + 12 * i + 6, GAME_WINDOW_OFFSET_Y + 6, 6, 6, 1.0, 0.0, Picture::getBossBarrage(), true);
				else if (i < 16) DrawRotaGraph2(GAME_WINDOW_OFFSET_X + 12 * (i - 8) + 6, GAME_WINDOW_OFFSET_Y + 18, 6, 6, 1.0, 0.0, Picture::getBossBarrage(), true);
				else DrawRotaGraph2(GAME_WINDOW_OFFSET_X + 12 * (i - 16) + 6, GAME_WINDOW_OFFSET_Y + 30, 6, 6, 1.0, 0.0, Picture::getBossBarrage(), true);
			}
		}
	}

	if (this->status == ChStatus_Normal){
		if (this->isBossPractice == false){
			char tmp[4];
			if (this->bossAttack->getLimitTime() - this->count > 0) sprintf_s(tmp, "%02d", (this->bossAttack->getLimitTime() - this->count) / 60);
			else sprintf_s(tmp, "00");
			DrawString(GAME_BOARD_OFFSET_X - 25, GAME_BOARD_OFFSET_Y + 6, tmp, GetColor(255, 255, 255));
			DrawString(GAME_BOARD_OFFSET_X - strlen(this->bossAttack->getAttackName().c_str()) * 10 + 10, GAME_BOARD_OFFSET_Y + 22, this->bossAttack->getAttackName().c_str(), GetColor(250, 250, 250));
		}
		else{
			DrawString(GAME_BOARD_OFFSET_X - 25, GAME_BOARD_OFFSET_Y + 6, "99", GetColor(255, 255, 255));
			DrawString(GAME_BOARD_OFFSET_X - strlen(this->bossAttack->getAttackName().c_str()) * 10 + 10, GAME_BOARD_OFFSET_Y + 22, this->bossAttack->getAttackName().c_str(), GetColor(250, 250, 250));
		}
	}
}

void Boss::finalize(){

}

void Boss::adjustTransRad(){
	while (this->trans_rad<0.0) this->trans_rad += M_PI * 2;
	while (this->trans_rad>M_PI * 2) this->trans_rad -= M_PI * 2;
}

void Boss::getDirectionFromTransRad(){
	if (this->trans_rad<M_PI / 8){
		this->direction = dir_right;
	}
	else if (this->trans_rad<M_PI * 3 / 8){
		this->direction = dir_rightdown;
	}
	else if (this->trans_rad<M_PI * 5 / 8){
		this->direction = dir_down;
	}
	else if (this->trans_rad<M_PI * 7 / 8){
		this->direction = dir_leftdown;
	}
	else if (this->trans_rad<M_PI * 9 / 8){
		this->direction = dir_left;
	}
	else if (this->trans_rad<M_PI * 11 / 8){
		this->direction = dir_leftup;
	}
	else if (this->trans_rad<M_PI * 13 / 8){
		this->direction = dir_up;
	}
	else if (this->trans_rad<M_PI * 15 / 8){
		this->direction = dir_rightup;
	}
	else{
		this->direction = dir_right;
	}
}

void Boss::initializeAttack(){
	this->status = ChStatus_Preparing;
	if(this->bossAttack!=NULL) delete(this->bossAttack);
	this->bossAttack = this->igetBossAttackInfo->igetBossAttack(this->id);
	this->bossAttack->setBossInfo(this);
	this->moveFrom = this->position;
	this->moveTo = this->bossAttack->getInitialPosition();
	this->moveTime = 60;
	this->HP = 0;
}

void Boss::beginAttack(){
	this->status = ChStatus_Preparing;
	this->count = 0;
}

void Boss::setInterface(ISetItem* isetItem, IGetPosition* igetPlayerPosition){
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
}

void Boss::isetBossMoveExternal(Point moveTo, int movingTime){
	this->eventCount = 0;
	this->eventMoveFrom = this->position;
	this->eventMoveTo = moveTo;
	this->eventMoveTime = movingTime;
	this->status = ChStatus_Waiting;
}

void Boss::isetBossMoveInternal(){
	this->status = ChStatus_Preparing;
	this->count = 0;
	this->direction = dir_down;
}

void Boss::isetBossInvalid(){
	this->validated = false;
}

void Boss::isetBossDamage(double damage){
	this->HP -= damage;
	if (this->HP < 0){
		this->validated = false;
	}
}

void Boss::damaged(double damage){
	this->HP -= damage;
	if (this->HP < 0){
		this->validated = false;
	}
}

Boss::~Boss(){
	delete this->bossAttack;
}