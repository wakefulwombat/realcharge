#include "enemy.h"
#include "DxLib.h"
#include "picture.h"
#include "sound.h"

Enemy::Enemy(StaticEnemyData* staticData, int CSVIndex, ISetBarrage* isetBarrage, ISetItem* isetItem, IGetPosition* igetPlayerPosition, ISetBurnEffect* isetBurnEffect){
	this->validated=true;
	this->staticData = staticData;
	this->CSVIndex = CSVIndex;
	this->isetBarrage = isetBarrage;
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
	this->isetBurnEffect = isetBurnEffect;

	this->life = staticData->HP_MAX;
	this->position = staticData->startPosition;

	this->count=0;
	this->animationDistanceTime=10;
	//this->size=Size(32,32);
	this->chip_rad=0.0;
	this->trans_rad=0.0;
	this->rotate_rad=0;

	switch (staticData->kind){
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

void Enemy::initialize(){
	
}

void Enemy::update(){
	this->count++;

	if(this->count>this->staticData->disappearTime_min){
		if((this->position.x<-this->size.width)||(this->position.y<-this->size.height)||(this->position.x>GAME_WINDOW_WIDTH+this->size.width)||(this->position.y>GAME_WINDOW_HEIGHT+this->size.height)){
			this->validated=false;
			for(int i=0;i<3;i++){
				if(this->staticData->barrageDataID[i]!=-1) this->isetBarrage->isetBarrageInvalidated(this->CSVIndex);
			}
		}
	}
	if(this->count%this->animationDistanceTime==0) this->chip_rad+=M_PI/2;

	this->movePattern();

	this->adjustTransRad();
	this->getDirectionFromTransRad();

	for(int i=0;i<3;i++){
		if(this->staticData->barrageDataID[i]==-1) break;
		if(this->count==this->staticData->barrageStartTime[i]){
			this->isetBarrage->isetBarrage(this->staticData->barrageDataID[i],this->CSVIndex,this->position,this);
		}
	}
}

void Enemy::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,200);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X+Round(this->position.x),GAME_WINDOW_OFFSET_Y+Round(this->position.y),this->size.width/2-1,this->size.height/2-1,1.0,0.0,Picture::getEnemy(this->staticData->kind,this->direction,this->chip_rad),true);
}

void Enemy::finalize(){

}

void Enemy::adjustTransRad(){
	while(this->trans_rad<0.0) this->trans_rad+=M_PI*2;
	while(this->trans_rad>M_PI*2) this->trans_rad-=M_PI*2;
}

void Enemy::getDirectionFromTransRad(){
	if(this->trans_rad<M_PI/8){
		this->direction = dir_right;
	}
	else if(this->trans_rad<M_PI*3/8){
		this->direction = dir_rightdown;
	}
	else if(this->trans_rad<M_PI*5/8){
		this->direction = dir_down;
	}
	else if(this->trans_rad<M_PI*7/8){
		this->direction = dir_leftdown;
	}
	else if(this->trans_rad<M_PI*9/8){
		this->direction = dir_left;
	}
	else if(this->trans_rad<M_PI*11/8){
		this->direction = dir_leftup;
	}
	else if(this->trans_rad<M_PI*13/8){
		this->direction = dir_up;
	}
	else if(this->trans_rad<M_PI*15/8){
		this->direction = dir_rightup;
	}
	else{
		this->direction = dir_right;
	}
}

void Enemy::movePattern(){
	double vx, vy;

	switch (this->staticData->movePattern){
	case 0://“™‘¬’¼ü
		this->position.x += this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
		this->position.y += this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
		this->trans_rad = this->staticData->move_trans_rad;
		break;

	case 1://“™‘¬’¼üˆê’â~
		if (this->count < this->staticData->movingTime){
			this->position.x += (this->staticData->stopPosition.x - this->staticData->startPosition.x) / this->staticData->movingTime;
			this->position.y += (this->staticData->stopPosition.y - this->staticData->startPosition.y) / this->staticData->movingTime;
			this->trans_rad = atan2(this->staticData->stopPosition.y - this->staticData->startPosition.y, this->staticData->stopPosition.x - this->staticData->startPosition.x);
		}
		else if (this->count > this->staticData->movingTime + this->staticData->stoppingTime){
			this->position.x += this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
			this->position.y += this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
			this->trans_rad = this->staticData->move_trans_rad;
		}
		else{
			this->trans_rad = M_PI / 2;
		}
		break;

	case 2://•Ï‘¬’¼üˆê’â~
		if (this->count < this->staticData->movingTime){
			this->position.x = this->staticData->startPosition.x + 2.0*(this->staticData->stopPosition.x - this->staticData->startPosition.x)*(1.0*this->count / this->staticData->movingTime) - (this->staticData->stopPosition.x - this->staticData->startPosition.x)*(1.0*this->count / this->staticData->movingTime)*(1.0*this->count / this->staticData->movingTime);
			this->position.y = this->staticData->startPosition.y + 2.0*(this->staticData->stopPosition.y - this->staticData->startPosition.y)*(1.0*this->count / this->staticData->movingTime) - (this->staticData->stopPosition.y - this->staticData->startPosition.y)*(1.0*this->count / this->staticData->movingTime)*(1.0*this->count / this->staticData->movingTime);
			this->trans_rad = atan2(this->staticData->stopPosition.y - this->staticData->startPosition.y, this->staticData->stopPosition.x - this->staticData->startPosition.x);
			this->trans_vel = 0.0;
		}
		else if (this->count > this->staticData->movingTime + this->staticData->stoppingTime){
			if (this->trans_vel < this->staticData->move_trans_vel) this->trans_vel += this->staticData->move_trans_acc;
			this->position.x += this->trans_vel*cos(this->staticData->move_trans_rad);
			this->position.y += this->trans_vel*sin(this->staticData->move_trans_rad);
			this->trans_rad = this->staticData->move_trans_rad;
		}
		else{
			this->trans_rad = M_PI / 2;
		}
		break;

	case 3://sin”g stopPos.x=r,stopPos.y=w
		this->position.x += cos(this->staticData->move_trans_rad)*this->staticData->move_trans_vel - sin(this->staticData->move_trans_rad)*this->staticData->stopPosition.x*(this->staticData->stopPosition.y*M_PI / 180)*cos((this->staticData->stopPosition.y*M_PI / 180)*this->count);
		this->position.y += sin(this->staticData->move_trans_rad)*this->staticData->move_trans_vel + cos(this->staticData->move_trans_rad)*this->staticData->stopPosition.x*(this->staticData->stopPosition.y*M_PI / 180)*cos((this->staticData->stopPosition.y*M_PI / 180)*this->count);
		this->trans_rad = atan2(sin(this->staticData->move_trans_rad)*this->staticData->move_trans_vel + cos(this->staticData->move_trans_rad)*this->staticData->stopPosition.x*(this->staticData->stopPosition.y*M_PI / 180)*cos((this->staticData->stopPosition.y*M_PI / 180)*this->count), cos(this->staticData->move_trans_rad)*this->staticData->move_trans_vel - sin(this->staticData->move_trans_rad)*this->staticData->stopPosition.x*(this->staticData->stopPosition.y*M_PI / 180)*cos((this->staticData->stopPosition.y*M_PI / 180)*this->count));
		break;

	case 4://Œv‰~‰^“® stopPos.x=r,stopPos.y=rad_max
		if (this->count < this->staticData->movingTime){
			this->position.x += this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
			this->position.y += this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
			this->trans_rad = this->staticData->move_trans_rad;
			this->rotate_rad = 0.0;
		}
		else{
			if (this->rotate_rad < this->staticData->stopPosition.y*M_PI / 180){
				this->rotate_rad += this->staticData->move_trans_vel / this->staticData->stopPosition.x;
				this->trans_rad += this->staticData->move_trans_vel / this->staticData->stopPosition.x;
				this->position.x -= this->staticData->move_trans_vel*sin(this->trans_rad - M_PI / 2);
				this->position.y += this->staticData->move_trans_vel*cos(this->trans_rad - M_PI / 2);
			}
			else{
				this->position.x += this->staticData->move_trans_vel*cos(this->trans_rad);
				this->position.y += this->staticData->move_trans_vel*sin(this->trans_rad);
			}
		}
		break;

	case 5://”½Œv‰~‰^“® stopPos.x=r,stopPos.y=rad_max
		if (this->count < this->staticData->movingTime){
			this->position.x += this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
			this->position.y += this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
			this->trans_rad = this->staticData->move_trans_rad;
			this->rotate_rad = 0.0;
		}
		else{
			if (this->rotate_rad < this->staticData->stopPosition.y*M_PI / 180){
				this->rotate_rad += this->staticData->move_trans_vel / this->staticData->stopPosition.x;
				this->trans_rad -= this->staticData->move_trans_vel / this->staticData->stopPosition.x;
				this->position.x -= this->staticData->move_trans_vel*sin(this->trans_rad - M_PI / 2);
				this->position.y += this->staticData->move_trans_vel*cos(this->trans_rad - M_PI / 2);
			}
			else{
				this->position.x += this->staticData->move_trans_vel*cos(this->trans_rad);
				this->position.y += this->staticData->move_trans_vel*sin(this->trans_rad);
			}
		}
		break;

	case 6://‰E•ûŒü‚Ö‰Á‘¬“x
		vx = this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
		vy = this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
		
		vx += this->staticData->move_trans_acc;
		this->position.x += vx;
		this->position.y += vy;

		this->staticData->move_trans_vel = sqrt(vx*vx + vy*vy);
		this->staticData->move_trans_rad = atan2(vy, vx);
		this->trans_rad = this->staticData->move_trans_rad;
		break;

	case 7://¶•ûŒü‚Ö‰Á‘¬“x
		vx = this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
		vy = this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
		
		vx -= this->staticData->move_trans_acc;
		this->position.x += vx;
		this->position.y += vy;

		this->staticData->move_trans_vel = sqrt(vx*vx + vy*vy);
		this->staticData->move_trans_rad = atan2(vy, vx);
		this->trans_rad = this->staticData->move_trans_rad;
		break;

	case 8://‰º•ûŒü‚Ö‰Á‘¬“x
		vx = this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
		vy = this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
		
		vy += this->staticData->move_trans_acc;
		this->position.x += vx;
		this->position.y += vy;

		this->staticData->move_trans_vel = sqrt(vx*vx + vy*vy);
		this->staticData->move_trans_rad = atan2(vy, vx);
		this->trans_rad = this->staticData->move_trans_rad;
		break;

	case 9://ã•ûŒü‚Ö‰Á‘¬“x
		vx = this->staticData->move_trans_vel*cos(this->staticData->move_trans_rad);
		vy = this->staticData->move_trans_vel*sin(this->staticData->move_trans_rad);
		
		vy -= this->staticData->move_trans_acc;
		this->position.x += vx;
		this->position.y += vy;

		this->staticData->move_trans_vel = sqrt(vx*vx + vy*vy);
		this->staticData->move_trans_rad = atan2(vy, vx);
		this->trans_rad = this->staticData->move_trans_rad;
		break;
	}
}

void Enemy::itemPattern(){
	switch(this->staticData->itemPattern){
	case 0://¬Ô2
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 1://¬Ô1,¬Â1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Small, this->igetPlayerPosition);
		break;

	case 2://¬Ô1,¬—Î1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Small, this->igetPlayerPosition);
		break;

	case 3://¬—Î1,¬Â1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Small, this->igetPlayerPosition);
		break;

	case 4://¬Ô3
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 5://¬Ô2 ¬Â1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Small, this->igetPlayerPosition);
		break;

	case 6://¬Ô2 ¬—Î1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Small, this->igetPlayerPosition);
		break;

	case 7://‘åÔ1 ¬Ô1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		break;

	case 8://‘åÔ1,¬Â1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		break;

	case 9://‘åÔ1,¬—Î1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		break;

	case 10://‘åÂ1,¬Ô1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 11://‘å—Î1,¬Ô1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 12://‘åÂ1,¬Ô2
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 13://‘å—Î1,¬Ô2
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Small, this->igetPlayerPosition);
		break;

	case 14://‘åÔ2
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		break;

	case 15://‘åÔ1,‘åÂ1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Blue, Item_Large, this->igetPlayerPosition);
		break;

	case 16://‘åÔ1,‘å—Î1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Red, Item_Large, this->igetPlayerPosition);
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_Green, Item_Large, this->igetPlayerPosition);
		break;

	case 17://¬”’1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_White, Item_Small, this->igetPlayerPosition);
		break;

	case 18://‘å”’1
		this->isetItem->isetItem(this->position + Point(GetRand(50) - 25, GetRand(50) - 25), Item_White, Item_Large, this->igetPlayerPosition);
		break;

	}
}

void Enemy::setInvalid(){
	this->validated = false;
}

void Enemy::damaged(double decreaceHP, bool isBurnEffect, double expand){
	if (this->validated == false) return;
	this->life -= decreaceHP;

	if (this->life < 0){
		this->validated = false;
		this->isetBarrage->isetBarrageInvalidated(this->CSVIndex);
		this->itemPattern();
		if (isBurnEffect == true) this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), expand / 2.0, this->position, true);
		else this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.5, this->position, true);
		Sound::playSound(Sound_enemyDead);
	}
}

void Enemy::isetEnemyDamage(int damage, bool isBurnEffect, double expand){
	if (this->validated == false) return;
	this->life -= damage;

	if (this->life < 0){
		this->validated = false;
		this->isetBarrage->isetBarrageInvalidated(this->CSVIndex);
		this->itemPattern();
		if (isBurnEffect == true) this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), expand / 2.0, this->position, true);
		else this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.5, this->position, true);
		Sound::playSound(Sound_enemyDead);
	}
}