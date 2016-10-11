#include "player.h"
#include "input.h"
#include "picture.h"
#include "sound.h"
#include "DxLib.h"

Player::Player():ignitionChargingTime(800),scatteringBombTime(400){
	this->chargingPower=100;
	this->ignitionReceiptingNow=false;
	this->ignitionReceiptCount=0;
	this->ignitionChargingNow=false;
	this->ignitionChargingCount=0;
	this->scatteringBombNow=false;
	this->scatteringBombCount=0;
	this->trans_vel = 5.0;
	this->animationDistanceTime = 10;
	this->position.x=GAME_WINDOW_WIDTH/2;
	this->position.y=GAME_WINDOW_HEIGHT*0.85;
	this->size.width=32;
	this->size.height=32;
	this->status = ChStatus_Normal;
	this->life = 20;
	this->prelife = 20;
}

void Player::initialize(){

}

void Player::initialize(ISetShockWave* isetShockWave, ISetNumericalBar* isetNumericalBar, ISetBomb* isetBomb, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow){
	this->isetShockWave = isetShockWave;
	this->isetNumericalBar = isetNumericalBar;
	this->isetBomb=isetBomb;
	this->isetItem = isetItem;
	this->isetBulletInvalid = isetBulletInvalid;
	this->igetBossEventNow = igetBossEventNow;
}

void Player::update(){
	this->count++;

	if (this->life/10 > this->prelife/10){
		Sound::playSound(Sound_extend);
	}
	this->prelife = this->life;

	switch(this->status){
	case ChStatus_Invincible:
		this->invincibleCount++;
		if (this->invincibleCount == 200){
			this->status = ChStatus_Normal;
			this->count = 0;
		}

	case ChStatus_Normal:
		if(this->count%this->animationDistanceTime==0) this->chip_rad+=M_PI/2;
		
		if(this->count%60==0){
			if (this->igetBossEventNow->igetBossEventNow() == false){
				this->chargingPower++;
				if (this->chargingPower > 1000) this->chargingPower = 1000;
			}
		}
		
		////移動
		if(Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove)==1){
			this->position.x += Input::getGridXDown()*this->trans_vel*0.4;
			this->position.y += Input::getGridYDown()*this->trans_vel*0.4;
		}
		else{
			this->position.x += Input::getGridXDown()*this->trans_vel;
			this->position.y += Input::getGridYDown()*this->trans_vel;
		}
		if(this->position.x<this->size.width/2) this->position.x=this->size.width/2;
		if(this->position.x>GAME_WINDOW_WIDTH-this->size.width/2) this->position.x=GAME_WINDOW_WIDTH-this->size.width/2;
		if(this->position.y<this->size.height/2) this->position.y=this->size.height/2;
		if(this->position.y>GAME_WINDOW_HEIGHT-this->size.height/2) this->position.y=GAME_WINDOW_HEIGHT-this->size.height/2;

		if (this->position.y < GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT*0.25)this->isetItem->isetItemStatusRetrieve();

		////起爆
		if(this->ignitionReceiptingNow==true){
			this->ignitionReceiptCount++;
			if(this->ignitionReceiptCount==40){
				this->ignitionReceiptingNow=false;
				this->ignitionChargingNow=true;
				this->ignitionChargingCount=0;
				this->isetNumericalBar->isetNumericalBar(this,&this->ignitionChargingCount,&this->ignitionChargingTime, true, true, true);
			}
		}
		else if (this->igetBossEventNow->igetBossEventNow() == false){
			if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Ignition)==1){
				if(this->ignitionChargingNow==false){
					Sound::playSound(Sound_ignitionCharging);
					this->ignitionReceiptingNow=true;
					this->ignitionReceiptCount=0;
				}
			}
		}

		if(this->ignitionChargingNow==true){
			this->ignitionChargingCount++;
			if (Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove) == 1) this->ignitionChargingCount++;
			if(this->ignitionChargingCount>=this->ignitionChargingTime){
				this->ignitionChargingNow=false;
			}
		}

		////チャージ弾放出
		if(this->chargingPower>=100){
			if (this->igetBossEventNow->igetBossEventNow() == false){
				if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_ReleasePower) == 1){
					this->isetShockWave->isetShockWave(this->chargingPower, this->position);
					this->chargingPower = 0;
				}
			}
		}

		////誘爆ボム生成
		if((this->scatteringBombNow==false)&&(this->igetBossEventNow->igetBossEventNow()==false)){
			if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_ScatterBomb)==1){
				Sound::playSound(Sound_scatteringBomb);
				for(int i=0;i<5;i++){
					this->isetBomb->isetBomb(this->position,M_PI*(i+7)/6,true);
				}
				this->scatteringBombNow=true;
				this->isetNumericalBar->isetNumericalBar(this, &this->scatteringBombCount, &this->scatteringBombTime, false, true, true);
				this->scatteringBombCount=0;
			}
		}

		if(this->scatteringBombNow==true){
			this->scatteringBombCount++;
			if(this->scatteringBombCount==this->scatteringBombTime){
				this->scatteringBombNow=false;
			}
		}
		break;

	case ChStatus_Dying:
		if(this->count==15*this->animationDistanceTime){
			this->count=0;
			this->status = ChStatus_Recovering;
		}
		this->ignitionChargingNow = false;
		this->scatteringBombNow = false;
		this->ignitionChargingCount = 0;
		this->scatteringBombCount = 0;
		this->isetBulletInvalid->isetBulletInvalidAll(this->position, 100);
		break;

	case ChStatus_Recovering:
		this->chip_rad=0.0;
		this->position.x = GAME_WINDOW_WIDTH/2;
		this->position.y = GAME_WINDOW_HEIGHT*0.85 - 20 * (60 - this->count);
		if(this->count==60){
			this->count=0;
			this->status=ChStatus_Invincible;
			this->invincibleCount = 0;
			this->isetItem->isetItemStatusRetrieve();
		}
		break;
	}
}

void Player::draw(){
	switch(this->status){
	case ChStatus_Normal:
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
		DrawRotaGraph2((int)this->position.x+GAME_WINDOW_OFFSET_X,(int)this->position.y+GAME_WINDOW_OFFSET_Y,this->size.width/2,this->size.height/2,1.0,0.0,Picture::getPlayer(this->chip_rad),true);

		if(this->ignitionReceiptingNow==true){
			DrawCircle(GAME_WINDOW_OFFSET_X+Round(this->position.x),GAME_WINDOW_OFFSET_Y+Round(this->position.y),40-this->ignitionReceiptCount,GetColor(255,255,255),false);
		}
		break;

	case ChStatus_Dying:
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
		DrawRotaGraph2((int)this->position.x+GAME_WINDOW_OFFSET_X,(int)this->position.y+GAME_WINDOW_OFFSET_Y,this->size.width/2,this->size.height/2,1.0,0.0,Picture::getExplode((this->count-(this->count%this->animationDistanceTime))/this->animationDistanceTime),true);
		break;

	case ChStatus_Recovering:
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA,180);
		DrawRotaGraph2((int)this->position.x+GAME_WINDOW_OFFSET_X,(int)this->position.y+GAME_WINDOW_OFFSET_Y,this->size.width/2,this->size.height/2,1.0,0.0,Picture::getPlayer(this->chip_rad),true);
		break;

	case ChStatus_Invincible:
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA,100*((this->count-(this->count%5))%5)+140);
		DrawRotaGraph2((int)this->position.x+GAME_WINDOW_OFFSET_X,(int)this->position.y+GAME_WINDOW_OFFSET_Y,this->size.width/2,this->size.height/2,1.0,0.0,Picture::getPlayer(this->chip_rad),true);
		break;
	}

	if (Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove) == 1){
		DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 6, 6, 1.0, 0.0, Picture::getBullet(Bul_Small, Bul_Red), true);
	}
}

void Player::finalize(){

}

void Player::die(){
	this->status = ChStatus_Dying;
	this->life-=10;
	this->count = 0;
}

void Player::addChargingPower(int addVal){
	this->chargingPower += addVal;
	if (this->chargingPower > 1000) this->chargingPower = 1000;
}

void Player::addLife(int addVal){
	this->life += addVal;
	if (this->life > 99) this->life = 99;
}

int Player::igetPlayerChargingPower(){
	return this->chargingPower;
}

int Player::igetPlayerLife(){
	return this->life;
}