#include "playerEX.h"
#include "input.h"
#include "picture.h"
#include "sound.h"
#include "DxLib.h"

PlayerEX::PlayerEX(){
	this->trans_vel = 5.0;
	this->animationDistanceTime = 10;
	this->position.x = GAME_WINDOW_WIDTH / 2;
	this->position.y = GAME_WINDOW_HEIGHT*0.85;
	this->size.width = 32;
	this->size.height = 32;
	this->status = ChStatus_Normal;
	this->life = 20;
	this->prelife = 20;

	this->shotBulletCount = 0;
	this->bulletPower = 0;
	this->canUseStandFlex = true;
	this->canUseStandStop = true;
	this->chargingStandFlexCount = 0;
	this->chargingStandStopCount = 0;

	this->ignitionReceiptingNow = false;
	this->ignitionReceiptCount = 0;
	this->ignitionChargingNow = false;
	this->ignitionChargingCount = 0;
	this->scatteringBombNow = false;
	this->scatteringBombCount = 0;
	this->isIgnitionSuccess = false;
	this->isColding = false;
	this->standStoppingCount = 0;

	this->waitingCountAbsorb = 0;
	this->waitingCountCollapsar = 0;
	this->runningCountAbsorb = 0;
	this->canUseAbsorb = true;
	this->canUseCollapsar = true;
	this->isNowAbsorbing = false;
}

void PlayerEX::initialize(){
	this->trans_vel = 5.0;
	this->animationDistanceTime = 10;
	this->position.x = GAME_WINDOW_WIDTH / 2;
	this->position.y = GAME_WINDOW_HEIGHT*0.85;
	this->size.width = 32;
	this->size.height = 32;
	this->status = ChStatus_Normal;
	this->prelife = 20;

	this->shotBulletCount = 0;
	this->canUseStandFlex = true;
	this->canUseStandStop = true;
	this->chargingStandFlexCount = 0;
	this->chargingStandStopCount = 0;

	this->ignitionReceiptingNow = false;
	this->ignitionReceiptCount = 0;
	this->ignitionChargingNow = false;
	this->ignitionChargingCount = 0;
	this->scatteringBombNow = false;
	this->scatteringBombCount = 0;
	this->isColding = false;
	this->standStoppingCount = 0;
}

void PlayerEX::initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetShockWave* isetShockWave, ISetBomb* isetBomb, int difficulty, bool isBossPractice){
	this->isetNumericalBar = isetNumericalBar;
	this->isetItem = isetItem;
	this->isetBulletInvalid = isetBulletInvalid;
	this->igetBossEventNow = igetBossEventNow;
	this->isetShockWave = isetShockWave;
	this->isetBomb = isetBomb;

	this->mode = 0;//explode

	if (difficulty == 0){
		this->ignitionChargingTime_Success = 400;
		this->ignitionChargingTime_Failure = 100;
		this->ignitionReceiptTime = 90;
		this->scatteringBombTime = 300;
	}
	else if (difficulty == 1){
		this->ignitionChargingTime_Success = 800;
		this->ignitionChargingTime_Failure = 300;
		this->ignitionReceiptTime = 60;
		this->scatteringBombTime = 400;
	}
	else{
		this->ignitionChargingTime_Success = 1200;
		this->ignitionChargingTime_Failure = 600;
		this->ignitionReceiptTime = 40;
		this->scatteringBombTime = 400;
	}

	if (isBossPractice == true){
		this->life = 0;
		this->chargingPower = 0;
	}
	else {
		this->life = 20;
		this->chargingPower = 100;
	}
}

void PlayerEX::initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetPlayerBulletEX* isetPlayerBulletEX, ISetStandBulletEX* isetStandBulletEX, int difficulty, bool isBossPractice){
	this->isetNumericalBar = isetNumericalBar;
	this->isetItem = isetItem;
	this->isetBulletInvalid = isetBulletInvalid;
	this->igetBossEventNow = igetBossEventNow;
	this->isetPlayerBulletEX = isetPlayerBulletEX;
	this->isetStandBulletEX = isetStandBulletEX;

	this->mode = 1;//stand

	if (difficulty == 0){
		this->standFlexTime = 80;
		this->standStopTime = 360;
		this->standStoppingTime = 120;
	}
	else if (difficulty == 1){
		this->standFlexTime = 140;
		this->standStopTime = 480;
		this->standStoppingTime = 240;
	}
	else{
		this->standFlexTime = 200;
		this->standStopTime = 600;
		this->standStoppingTime = 360;
	}

	if (isBossPractice == true){
		this->life = 0;
		this->bulletPower = 0;
	}
	else{
		this->life = 20;
		this->bulletPower = 200;
	}
}

void PlayerEX::initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetShockWave* isetShockWave, ISetCollapsar* isetCollapsar, int difficulty, bool isBossPractice){
	this->isetNumericalBar = isetNumericalBar;
	this->isetItem = isetItem;
	this->isetBulletInvalid = isetBulletInvalid;
	this->igetBossEventNow = igetBossEventNow;
	this->isetShockWave = isetShockWave;
	this->isetCollapsar = isetCollapsar;

	this->mode = 2;//absorb

	if (difficulty == 0){
		this->waitingTimeAbsorb = 300;
		this->waitingTimeCollapsar = 600;
		this->runningTimeAbsorb = 60;
	}
	else if (difficulty == 1){
		this->waitingTimeAbsorb = 800;
		this->waitingTimeCollapsar = 1000;
		this->runningTimeAbsorb = 70;
	}
	else{
		this->waitingTimeAbsorb = 1200;
		this->waitingTimeCollapsar = 1400;
		this->runningTimeAbsorb = 80;
	}

	if (isBossPractice == true){
		this->life = 0;
		this->chargingPower = 0;
	}
	else {
		this->life = 20;
		this->chargingPower = 50;
	}
}

void PlayerEX::update(){
	this->count++;

	if (this->life / 10 > this->prelife / 10){
		Sound::playSound(Sound_extend);
	}
	this->prelife = this->life;

	if (this->mode == 0){//explode
		switch (this->status){
		case ChStatus_Invincible:
			this->invincibleCount++;
			if (this->invincibleCount == 200){
				this->status = ChStatus_Normal;
				this->count = 0;
			}

		case ChStatus_Normal:
			if (this->count%this->animationDistanceTime == 0) this->chip_rad += M_PI / 2;

			if (this->count % 60 == 0){
				if (this->igetBossEventNow->igetBossEventNow() == false){
					this->chargingPower++;
					if (this->chargingPower > 500) this->chargingPower = 500;
				}
			}

			////移動
			if (Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove) == 1){
				this->position.x += Input::getGridXDown()*this->trans_vel*0.4;
				this->position.y += Input::getGridYDown()*this->trans_vel*0.4;
			}
			else{
				this->position.x += Input::getGridXDown()*this->trans_vel;
				this->position.y += Input::getGridYDown()*this->trans_vel;
			}
			if (this->position.x<this->size.width / 2) this->position.x = this->size.width / 2;
			if (this->position.x>GAME_WINDOW_WIDTH - this->size.width / 2) this->position.x = GAME_WINDOW_WIDTH - this->size.width / 2;
			if (this->position.y<this->size.height / 2) this->position.y = this->size.height / 2;
			if (this->position.y>GAME_WINDOW_HEIGHT - this->size.height / 2) this->position.y = GAME_WINDOW_HEIGHT - this->size.height / 2;

			if (this->position.y < GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT*0.25)this->isetItem->isetItemStatusRetrieve();

			////起爆
			if (this->ignitionReceiptingNow == true){
				this->ignitionReceiptCount++;
				if (this->ignitionReceiptCount == this->ignitionReceiptTime){
					this->ignitionReceiptingNow = false;
					this->ignitionChargingNow = true;
					this->ignitionChargingCount = 0;
					this->isetNumericalBar->isetNumericalBar(this, &this->ignitionChargingCount, &this->ignitionChargingTime_Failure, true, true, true);
				}
			}
			else if (this->igetBossEventNow->igetBossEventNow() == false){
				if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Ignition) == 1){
					if (this->ignitionChargingNow == false){
						Sound::playSound(Sound_ignitionCharging);
						this->ignitionReceiptingNow = true;
						this->ignitionReceiptCount = 0;
						this->isIgnitionSuccess = false;
					}
				}
			}

			if (this->ignitionChargingNow == true){
				this->ignitionChargingCount++;
				if (Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove) == 1) this->ignitionChargingCount++;
				if (this->isIgnitionSuccess == true){
					if (this->ignitionChargingCount >= this->ignitionChargingTime_Success){
						this->ignitionChargingNow = false;
					}
				}
				else{
					if (this->ignitionChargingCount >= this->ignitionChargingTime_Failure){
						this->ignitionChargingNow = false;
					}
				}
			}

			////チャージ弾放出
			if (this->igetBossEventNow->igetBossEventNow() == false){
				if (this->chargingPower >= 100){
					if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_ReleasePower) == 1){
						this->isetShockWave->isetShockWave(this->chargingPower, this->position);
						this->chargingPower = 0;
					}
				}
			}

			////誘爆ボム生成
			if ((this->scatteringBombNow == false) && (this->igetBossEventNow->igetBossEventNow() == false)){
				if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_ScatterBomb) == 1){
					Sound::playSound(Sound_scatteringBomb);
					for (int i = 0; i<5; i++){
						this->isetBomb->isetBomb(this->position, M_PI*(i + 7) / 6, true);
					}
					this->scatteringBombNow = true;
					this->isetNumericalBar->isetNumericalBar(this, &this->scatteringBombCount, &this->scatteringBombTime, false, true, true);
					this->scatteringBombCount = 0;
				}
			}

			if (this->scatteringBombNow == true){
				this->scatteringBombCount++;
				if (this->scatteringBombCount == this->scatteringBombTime){
					this->scatteringBombNow = false;
				}
			}
			break;

		case ChStatus_Dying:
			if (this->count == 15 * this->animationDistanceTime/2){
				this->count = 0;
				this->status = ChStatus_Recovering;
				Sound::playSound(Sound_PlayerRecovery);
			}			
			this->isetBulletInvalid->isetBulletInvalidAll(this->position, 70);
			break;

		case ChStatus_Recovering:
			this->chip_rad = 0.0;
			this->position.x = GAME_WINDOW_WIDTH / 2;
			this->position.y = GAME_WINDOW_HEIGHT*0.85;
			if (this->count == 10 * this->animationDistanceTime / 2){
				this->count = 0;
				this->status = ChStatus_Invincible;
				this->invincibleCount = 0;
				this->isetItem->isetItemStatusRetrieve();

				this->ignitionChargingNow = false;
				this->scatteringBombNow = false;
				this->ignitionChargingCount = 0;
				this->scatteringBombCount = 0;
				this->ignitionReceiptCount = 0;
			}
			break;
		}
	}
	else if(this->mode==1){//stand
		switch (this->status){
		case ChStatus_Invincible:
			this->invincibleCount++;
			if (this->invincibleCount == 200){
				this->status = ChStatus_Normal;
				this->count = 0;
			}

		case ChStatus_Normal:
			if (this->count%this->animationDistanceTime == 0) this->chip_rad += M_PI / 2;

			////移動
			if (Input::getkeyCodeDown_Stand(KeyCodeStand_SlowMove) == 1){
				this->position.x += Input::getGridXDown()*this->trans_vel*0.4;
				this->position.y += Input::getGridYDown()*this->trans_vel*0.4;
			}
			else{
				this->position.x += Input::getGridXDown()*this->trans_vel;
				this->position.y += Input::getGridYDown()*this->trans_vel;
			}
			if (this->position.x < this->size.width / 2) this->position.x = this->size.width / 2;
			if (this->position.x > GAME_WINDOW_WIDTH - this->size.width / 2) this->position.x = GAME_WINDOW_WIDTH - this->size.width / 2;
			if (this->position.y < this->size.height / 2) this->position.y = this->size.height / 2;
			if (this->position.y > GAME_WINDOW_HEIGHT - this->size.height / 2) this->position.y = GAME_WINDOW_HEIGHT - this->size.height / 2;

			if (this->position.y < GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT*0.25)this->isetItem->isetItemStatusRetrieve();

			//弾発射
			if (this->igetBossEventNow->igetBossEventNow() == false){
				this->shotBulletCount++;
				if (Input::getkeyCodeDown_Stand(KeyCodeStand_ShotBullet) == 1){
					if (this->shotBulletCount > 5){
						this->shotBulletCount = 0;

						if (Input::getkeyCodeDown_Stand(KeyCodeStand_SlowMove) == 1){
							if (this->bulletPower > 400){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.6 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27,4 / 18);
							}
							if (this->bulletPower > 300){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.7 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.3 / 18);
							}
							if (this->bulletPower > 200){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.8 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.2 / 18);
							}
							if (this->bulletPower > 100){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.9 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.1 / 18);
							}
						}
						else{
							if (this->bulletPower > 400){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.2 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.8 / 18);
							}
							if (this->bulletPower > 300){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.4 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.6 / 18);
							}
							if (this->bulletPower > 200){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.6 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.4 / 18);
							}
							if (this->bulletPower > 100){
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 26.8 / 18);
								this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Knife, Bul_White, 1, 0.1, 12.0, 0.2, M_PI * 27.2 / 18);
							}
						}
						this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(-12.0, -10.0), Bul_Fuda, Bul_Red, 0, 0.3, 15.0, 0.0, M_PI * 3 / 2);
						this->isetPlayerBulletEX->isetPlayerBulletEX(this->position + Point(12.0, -10.0), Bul_Fuda, Bul_Red, 0, 0.3, 15.0, 0.0, M_PI * 3 / 2);

						Sound::playSound(Sound_PlayerBullet);
					}
				}
			}

			//フレックス
			if (this->canUseStandFlex == true){
				if (this->igetBossEventNow->igetBossEventNow() == false){
					if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_StandFlex) == 1){
						this->isGrowingFlexR = true;
						this->frexRadius = 70;
					}
				}
				if (Input::getkeyCodeUpOnce_Stand(KeyCodeStand_StandFlex) == 1){
					if (this->isGrowingFlexR == true){
						this->chargingStandFlexCount = 0;
						this->isetNumericalBar->isetNumericalBar(this, &this->chargingStandFlexCount, &this->standFlexTime, false, false, true);
						this->canUseStandFlex = false;
						this->isGrowingFlexR = false;
						this->isetStandBulletEX->isetBulletFlex(this->position, this->frexRadius);
						Sound::playSound(Sound_PlayerLazer);
					}
				}
			}
			else{
				this->chargingStandFlexCount++;
				if (this->chargingStandFlexCount == this->standFlexTime){
					this->canUseStandFlex = true;
				}
			}

			if (this->isGrowingFlexR == true){
				this->frexRadius++;
				if (this->frexRadius > 120){
					this->frexRadius = 120;
				}
			}

			//ホールド
			if (this->canUseStandStop == true){
				if (this->igetBossEventNow->igetBossEventNow() == false){
					if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_StandHold) == 1){
						this->isGrowingStopR = true;
						this->stopRadius = 0;
					}
				}
				if (Input::getkeyCodeUpOnce_Stand(KeyCodeStand_StandHold) == 1){
					if (this->isGrowingStopR == true){
						this->chargingStandStopCount = 0;
						this->isetNumericalBar->isetNumericalBar(this, &this->chargingStandStopCount, &this->standStopTime, true, false, true);
						this->canUseStandStop = false;
						this->isGrowingStopR = false;
						this->isetStandBulletEX->isetBulletStop(this->position, this->stopRadius);
						this->isColding = true;
						this->stopStandCenter = this->position;
						this->standStoppingCount = 0;
						Sound::playSound(Sound_ignitionGo);
					}
				}
			}
			else{
				this->chargingStandStopCount++;
				if (this->chargingStandStopCount == this->standStopTime){
					this->canUseStandStop = true;
				}
			}

			if (this->isGrowingStopR == true){
				this->stopRadius++;
				if (this->stopRadius > 50){
					this->stopRadius = 50;
				}
			}

			if (this->isColding == true){
				this->standStoppingCount++;
				if (this->standStoppingCount >= this->standStoppingTime){
					this->isetStandBulletEX->isetBulletClearAfterStop();
					this->isColding = false;
				}
			}

			break;

		case ChStatus_Dying:
			if (this->count == 15 * this->animationDistanceTime/2){
				this->count = 0;
				this->status = ChStatus_Recovering;
				Sound::playSound(Sound_PlayerRecovery);
			}
			this->canUseStandFlex = true;
			this->canUseStandStop = true;
			this->isGrowingFlexR = false;
			this->isGrowingStopR = false;
			this->chargingStandFlexCount = 0;
			this->chargingStandStopCount = 0;
			this->isetBulletInvalid->isetBulletInvalidAll(this->position, 70);

			break;

		case ChStatus_Recovering:
			this->chip_rad = 0.0;
			this->position.x = GAME_WINDOW_WIDTH / 2;
			this->position.y = GAME_WINDOW_HEIGHT*0.85;
			if (this->count == 10 * this->animationDistanceTime / 2){
				this->count = 0;
				this->status = ChStatus_Invincible;
				this->invincibleCount = 0;
				this->isetItem->isetItemStatusRetrieve();
			}
			break;
		}
	}
	else{//absorb
		switch (this->status){
		case ChStatus_Invincible:
			this->invincibleCount++;
			if (this->invincibleCount == 200){
				this->status = ChStatus_Normal;
				this->count = 0;
			}

		case ChStatus_Normal:
			if (this->count%this->animationDistanceTime == 0) this->chip_rad += M_PI / 2;

			////移動
			if (Input::getkeyCodeDown_Stand(KeyCodeStand_SlowMove) == 1){
				this->position.x += Input::getGridXDown()*this->trans_vel*0.4;
				this->position.y += Input::getGridYDown()*this->trans_vel*0.4;
			}
			else{
				this->position.x += Input::getGridXDown()*this->trans_vel;
				this->position.y += Input::getGridYDown()*this->trans_vel;
			}
			if (this->position.x < this->size.width / 2) this->position.x = this->size.width / 2;
			if (this->position.x > GAME_WINDOW_WIDTH - this->size.width / 2) this->position.x = GAME_WINDOW_WIDTH - this->size.width / 2;
			if (this->position.y < this->size.height / 2) this->position.y = this->size.height / 2;
			if (this->position.y > GAME_WINDOW_HEIGHT - this->size.height / 2) this->position.y = GAME_WINDOW_HEIGHT - this->size.height / 2;

			if (this->position.y < GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT*0.25)this->isetItem->isetItemStatusRetrieve();

			//アブソーブ
			if (this->canUseAbsorb == true){
				if (this->igetBossEventNow->igetBossEventNow() == false){
					if (Input::getkeyCodeDownOnce_Absorb(KeyCodeAbsorb_Absorb) == 1){
						this->runningCountAbsorb = 0;
						this->isNowAbsorbing = true;
						this->canUseAbsorb = false;
					}
				}
			}
			else{
				if (this->isNowAbsorbing == false){
					this->waitingCountAbsorb++;
					if (this->waitingCountAbsorb == this->waitingTimeAbsorb){
						this->canUseAbsorb = true;
					}
				}
			}

			if (this->isNowAbsorbing == true){
				this->runningCountAbsorb++;
				if (this->runningCountAbsorb == this->runningTimeAbsorb-2){
					this->isetBulletInvalid->isetInvalidSubrange(this->position, 100.0);
					Sound::playSound(Sound_TimeAlart);
				}
				if (this->runningCountAbsorb == this->runningTimeAbsorb){
					this->canUseAbsorb = false;
					this->isNowAbsorbing = false;
					this->waitingCountAbsorb = 0;
					this->isetNumericalBar->isetNumericalBar(this, &this->waitingCountAbsorb, &this->waitingTimeAbsorb, true, false, true);
				}
			}

			//リリース
			if (this->igetBossEventNow->igetBossEventNow() == false){
				if (Input::getkeyCodeDown_Absorb(KeyCodeAbsorb_Release) == 1){
					if (this->chargingPower > 0){
						if (this->count % 6 == 0){
							this->chargingPower--;
							Sound::playSound(Sound_PlayerLazer);
						}
						if (Input::getkeyCodeDown_Stand(KeyCodeStand_SlowMove) == 1) this->isetShockWave->isetShockLazerStraight(this->position, true);
						else this->isetShockWave->isetShockLazerStraight(this->position, false);
					}
				}
			}

			//コラプサー
			if (this->canUseCollapsar == true){
				if (this->igetBossEventNow->igetBossEventNow() == false){
					if (Input::getkeyCodeDownOnce_Absorb(KeyCodeAbsorb_Collapsar) == 1){
						this->isetCollapsar->istartCollapsar(this->position);
						this->canUseCollapsar = false;
						this->waitingCountCollapsar = 0;
						this->isetNumericalBar->isetNumericalBar(this, &this->waitingCountCollapsar, &this->waitingTimeCollapsar, false, false, true);
					}
				}
			}
			else{
				this->waitingCountCollapsar++;
				if (this->waitingCountCollapsar == this->waitingTimeCollapsar){
					this->canUseCollapsar = true;
				}
			}

			break;

		case ChStatus_Dying:
			if (this->count == 15 * this->animationDistanceTime / 2){
				this->count = 0;
				this->status = ChStatus_Recovering;
				Sound::playSound(Sound_PlayerRecovery);
			}
			this->waitingCountAbsorb = 0;
			this->waitingCountCollapsar = 0;
			this->canUseAbsorb = true;
			this->canUseCollapsar = true;
			this->isNowAbsorbing = false;
			this->isetBulletInvalid->isetBulletInvalidAll(this->position, 70);

			break;

		case ChStatus_Recovering:
			this->chip_rad = 0.0;
			this->position.x = GAME_WINDOW_WIDTH / 2;
			this->position.y = GAME_WINDOW_HEIGHT*0.85;
			if (this->count == 10 * this->animationDistanceTime / 2){
				this->count = 0;
				this->status = ChStatus_Invincible;
				this->invincibleCount = 0;
				this->isetItem->isetItemStatusRetrieve();
			}
			break;
		}
	}
}

void PlayerEX::draw(){
	if (this->mode == 0){//explode
		switch (this->status){
		case ChStatus_Normal:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);

			if (this->ignitionReceiptingNow == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->ignitionReceiptTime - this->ignitionReceiptCount, GetColor(255, 255, 255), false);
			}
			break;

		case ChStatus_Dying:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 24, 24, 2.0, 0.0, Picture::getExplode((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Recovering:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 60, 60, 3.0, 0.0, Picture::getPlayerRecovery((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Invincible:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);

			if (this->ignitionReceiptingNow == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->ignitionReceiptTime - this->ignitionReceiptCount, GetColor(255, 255, 255), false);
			}
			break;
		}

		if (Input::getkeyCodeDown_Explode(KeyCodeExplode_SlowMove) == 1){
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 6, 6, 1.0, 0.0, Picture::getBullet(Bul_Small, Bul_Red), true);
		}
	}
	else if(this->mode==1){//stand
		switch (this->status){
		case ChStatus_Normal:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);

			if (this->isGrowingFlexR == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->frexRadius, GetColor(100, 255, 100), false);
			}
			if (this->isGrowingStopR == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->stopRadius, GetColor(255, 100, 100), false);
			}
			if (this->isColding == true){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 30.0*(this->standStoppingTime - this->standStoppingCount) / this->standStoppingTime + 10);
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->stopStandCenter.x), GAME_WINDOW_OFFSET_Y + Round(this->stopStandCenter.y), this->stopRadius, GetColor(100, 100, 255), true);
			}
			break;

		case ChStatus_Dying:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 24, 24, 2.0, 0.0, Picture::getExplode((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Recovering:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 60, 60, 3.0, 0.0, Picture::getPlayerRecovery((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Invincible:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);
			
			if (this->isGrowingFlexR == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->frexRadius, GetColor(0, 255, 0), false);
			}
			if (this->isGrowingStopR == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->stopRadius, GetColor(255, 0, 0), false);
			}
			if (this->isColding == true){
				SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 30.0*(this->standStoppingTime - this->standStoppingCount) / this->standStoppingTime + 10);
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->stopStandCenter.x), GAME_WINDOW_OFFSET_Y + Round(this->stopStandCenter.y), this->stopRadius, GetColor(100, 100, 255), true);
			}
			break;
		}

		if (Input::getkeyCodeDown_Stand(KeyCodeStand_SlowMove) == 1){
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 6, 6, 1.0, 0.0, Picture::getBullet(Bul_Small, Bul_Red), true);
		}
	}
	else{//absorb
		switch (this->status){
		case ChStatus_Normal:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);
			
			if (this->isNowAbsorbing == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->runningTimeAbsorb - this->runningCountAbsorb, GetColor(255, 255, 255), false);
			}
			break;

		case ChStatus_Dying:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 24, 24, 2.0, 0.0, Picture::getExplode((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Recovering:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 255);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 60, 60, 3.0, 0.0, Picture::getPlayerRecovery((this->count - (this->count % (this->animationDistanceTime / 2))) * 2 / this->animationDistanceTime), true);
			break;

		case ChStatus_Invincible:
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, 1.0, 0.0, Picture::getPlayer(this->chip_rad), true);
			
			if (this->isNowAbsorbing == true){
				DrawCircle(GAME_WINDOW_OFFSET_X + Round(this->position.x), GAME_WINDOW_OFFSET_Y + Round(this->position.y), this->runningTimeAbsorb - this->runningCountAbsorb, GetColor(255, 255, 255), false);
			}
			break;
		}

		if (Input::getkeyCodeDown_Absorb(KeyCodeAbsorb_SlowMove) == 1){
			DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, 6, 6, 1.0, 0.0, Picture::getBullet(Bul_Small, Bul_Red), true);
		}
	}
}

void PlayerEX::finalize(){

}

void PlayerEX::die(){
	if (this->status != ChStatus_Normal) return;

	this->status = ChStatus_Dying;
	this->life -= 10;
	this->count = 0;

	if (this->mode == 0){
		if (this->chargingPower < 100) this->chargingPower = 100;
	}
	else if (this->mode == 1){
		if (this->bulletPower > 300) this->bulletPower -= 100;
		else this->bulletPower = 200;
	}
	else{
		if (this->chargingPower < 50) this->chargingPower = 50;
	}

	this->isetNumericalBar->isetNumericalBarClearAroundPlayer();
}

void PlayerEX::addLife(int addVal){
	this->life += addVal;
	if (this->life > 99) this->life = 99;
}

void PlayerEX::addChargingPower(int addVal){
	this->chargingPower += addVal;
	if (this->chargingPower > 1000) this->chargingPower = 1000;
}

void PlayerEX::addBulletPower(int addVal){
	this->bulletPower += addVal;
	if (this->bulletPower > 500) this->bulletPower = 500;
}

void PlayerEX::addRecoveringTimeStandStop(int addTime){
	if (this->canUseStandStop == true) return;

	this->standStoppingCount += addTime;
	if (this->standStoppingCount > this->standStoppingTime) this->standStoppingCount = this->standStoppingTime;
}

void PlayerEX::decreaseAbsorbRunnningCount(int time){
	this->runningCountAbsorb -= time;
	if (this->runningCountAbsorb < 0) this->runningCountAbsorb = 0;
}

void PlayerEX::setIgnitionSuccess(){
	if (this->ignitionChargingNow == true) return;

	this->isIgnitionSuccess = true;
	this->ignitionReceiptingNow = false;
	this->ignitionChargingNow = true;
	this->ignitionChargingCount = 0;
	this->isetNumericalBar->isetNumericalBar(this, &this->ignitionChargingCount, &this->ignitionChargingTime_Success, true, true, true);

	this->invincibleCount = 190;
	this->status = ChStatus_Invincible;
}