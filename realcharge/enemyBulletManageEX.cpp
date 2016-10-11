#include "enemyBulletManageEX.h"
#include "DxLib.h"
#include "bullet.h"
#include "bossBullet.h"
#include "enemyLazer.h"
#include "sound.h"

EnemyBulletManageEX::EnemyBulletManageEX(){
	this->bullet.clear();
	this->lazer.clear();

	this->isClearing = false;
}

void EnemyBulletManageEX::initialize(){
	for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		(*it)->initialize();
	}
	for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
		(*it)->initialize();
	}
}

void EnemyBulletManageEX::initialize(ISetBurnEffect* isetBurnEffect, ISetStandShockLazerEX* isetStandShockLazerEX, IGetIsColding* igetIsColding, IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow){
	this->isetBurnEffect = isetBurnEffect;
	this->isetStandShockLazerEX = isetStandShockLazerEX;
	this->igetIsColding = igetIsColding;
	this->igetBoss = igetBoss;
	this->igetBossEventNow = igetBossEventNow;
}

void EnemyBulletManageEX::update(){
	if (this->isClearing == true){
		this->clearingTimeCount++;
		if (this->clearingTimeCount == this->clearingTime){
			this->isClearing = false;
		}

		double d = 800.0 * this->clearingTimeCount / this->clearingTime;
		for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
			if (this->clearingCenter.y - (*it)->getPosition().y > d) continue;
			if ((*it)->getPosition().y - this->clearingCenter.y > d) continue;
			if (this->clearingCenter.x - (*it)->getPosition().x > d) continue;
			if ((*it)->getPosition().x - this->clearingCenter.x > d) continue;

			if ((((*it)->getPosition().x - this->clearingCenter.x)*((*it)->getPosition().x - this->clearingCenter.x) + ((*it)->getPosition().y - this->clearingCenter.y)*((*it)->getPosition().y - this->clearingCenter.y)) < d*d){
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, (*it)->getPosition(), false);
				(*it)->setInvalid();
			}
		}
		for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
			for (unsigned int i = 0; i < (*it)->getLazerDivSize(); ++i){
				if (this->clearingCenter.y - (*it)->getLazerDivPosition(i).y > d) continue;
				if ((*it)->getLazerDivPosition(i).y - this->clearingCenter.y > d) continue;
				if (this->clearingCenter.x - (*it)->getLazerDivPosition(i).x > d) continue;
				if ((*it)->getLazerDivPosition(i).x - this->clearingCenter.x > d) continue;

				if (((*it)->getLazerDivPosition(i).x - this->clearingCenter.x)*((*it)->getLazerDivPosition(i).x - this->clearingCenter.x) + ((*it)->getLazerDivPosition(i).y - this->clearingCenter.y)*((*it)->getLazerDivPosition(i).y - this->clearingCenter.y) < d*d){
					this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, (*it)->getLazerDivPosition(i), false);
					(*it)->setLazerDivInvalid(i);
				}
			}
		}
	}

	if (this->igetIsColding->igetIsColding() == true){
		for (int i = 0; i < this->bullet.size();){
			if (this->bullet[i]->getValidate() == false){
				delete this->bullet[i];
				this->bullet.erase(this->bullet.begin() + i);
				continue;
			}
			if (this->bullet[i]->getPosition().y - this->coldingCenter.y > this->coldingRadius){
				this->bullet[i]->update();
			}
			else if (this->coldingCenter.y - this->bullet[i]->getPosition().y > this->coldingRadius){
				this->bullet[i]->update();
			}
			else if (this->bullet[i]->getPosition().x - this->coldingCenter.x > this->coldingRadius){
				this->bullet[i]->update();
			}
			else if (this->coldingCenter.x - this->bullet[i]->getPosition().x > this->coldingRadius){
				this->bullet[i]->update();
			}
			else if ((this->bullet[i]->getPosition().x - this->coldingCenter.x)*(this->bullet[i]->getPosition().x - this->coldingCenter.x) + (this->bullet[i]->getPosition().y - this->coldingCenter.y)*(this->bullet[i]->getPosition().y - this->coldingCenter.y) > this->coldingRadius*this->coldingRadius){
				this->bullet[i]->update();
			}
			++i;
		}
		for (int i = 0; i < this->lazer.size();){
			if (this->lazer[i]->getValidate() == false){
				delete this->lazer[i];
				this->lazer.erase(this->lazer.begin() + i);
				continue;
			}
			for (int j = 0; j < this->lazer[i]->getLazerDivSize(); j++){
				if (this->lazer[i]->getLazerDivPosition(j).x - this->coldingCenter.x > this->coldingRadius){
					this->lazer[i]->setLazerDivIsInColding(j, false);
				}
				else if (this->coldingCenter.x - this->lazer[i]->getLazerDivPosition(j).x > this->coldingRadius){
					this->lazer[i]->setLazerDivIsInColding(j, false);
				}
				else if (this->lazer[i]->getLazerDivPosition(j).y - this->coldingCenter.y > this->coldingRadius){
					this->lazer[i]->setLazerDivIsInColding(j, false);
				}
				else if (this->coldingCenter.y - this->lazer[i]->getLazerDivPosition(j).y > this->coldingRadius){
					this->lazer[i]->setLazerDivIsInColding(j, false);
				}
				else if ((this->lazer[i]->getLazerDivPosition(j).x - this->coldingCenter.x)*(this->lazer[i]->getLazerDivPosition(j).x - this->coldingCenter.x) + (this->lazer[i]->getLazerDivPosition(j).y - this->coldingCenter.y)*(this->lazer[i]->getLazerDivPosition(j).y - this->coldingCenter.y) < this->coldingRadius*this->coldingRadius){
					this->lazer[i]->setLazerDivIsInColding(j, true);
				}
				else{
					this->lazer[i]->setLazerDivIsInColding(j, false);
				}
			}
			this->lazer[i]->update();
			++i;
		}
	}
	else{
		for (int i = 0; i < this->bullet.size();){
			if (this->bullet[i]->getValidate() == false){
				delete this->bullet[i];
				this->bullet.erase(this->bullet.begin() + i);
				continue;
			}
			this->bullet[i]->update();
			++i;
		}
		for (int i = 0; i < this->lazer.size();){
			if (this->lazer[i]->getValidate() == false){
				delete this->lazer[i];
				this->lazer.erase(this->lazer.begin() + i);
				continue;
			}
			for (int j = 0; j < this->lazer[i]->getLazerDivSize(); j++){
				this->lazer[i]->setLazerDivIsInColding(j, false);
			}
			this->lazer[i]->update();
			++i;
		}
	}
}

void EnemyBulletManageEX::draw(){
	for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
		(*it)->draw();
	}
	for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		(*it)->draw();
	}
}

void EnemyBulletManageEX::finalize(){
	for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		(*it)->finalize();
	}
	for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
		(*it)->finalize();
	}
}


void EnemyBulletManageEX::isetBullet(StaticBulletData* bulletData, Point position, double trans_vel0, double trans_acc0, double trans_rad0, double rotate_vel0, double rotate_acc0, double rotate_rad0, ISetBullet* isetBullet){
	this->bullet.push_back(new Bullet(bulletData, position, trans_vel0, trans_acc0, trans_rad0, rotate_vel0, rotate_acc0, rotate_rad0, isetBullet));
	Sound::playSound(Sound_EnemyBullet);
}

void EnemyBulletManageEX::isetBossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1, double param2, double param3){
	this->bullet.push_back(new BossBullet(pos, kind, color, movePattern, isetBullet, igetPlayerPosition, trans_vel0, trans_acc, trans_rad0, rotate_vel, disappTime_min, param1, param2, param3));
	Sound::playSound(Sound_EnemyBullet);
}

void EnemyBulletManageEX::isetEnemyLazer(Point start, BulletColor color, int movePattern, int maxDivNum, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1, double param2, double param3){
	this->lazer.push_back(new EnemyLazer(start, color, movePattern, maxDivNum, trans_vel0, trans_acc, trans_rad0, rotate_vel, disappTime_min, param1, param2, param3));
	Sound::playSound(Sound_EnemyLazer);
}

void EnemyBulletManageEX::isetEnemyLazerBezier(BezierInfo info, BulletColor color, int maxDivNum, int disappTime_min){
	this->lazer.push_back(new EnemyLazerBezier(info, color, maxDivNum, disappTime_min));
	Sound::playSound(Sound_EnemyLazer);
}


void EnemyBulletManageEX::isetBulletInvalidAll(Point center, int validTime){
	this->clearingCenter = center;
	this->clearingTime = validTime;
	this->clearingTimeCount = 0;
	this->isClearing = true;
}

void EnemyBulletManageEX::isetInvalidAll(Point center, int validTime){
	this->clearingCenter = center;
	this->clearingTime = validTime;
	this->clearingTimeCount = 0;
	this->isClearing = true;
}

void EnemyBulletManageEX::isetInvalidSubrange(Point center, double r){
	for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		if (center.y - (*it)->getPosition().y > r) continue;
		if ((*it)->getPosition().y - center.y > r) continue;
		if (center.x - (*it)->getPosition().x > r) continue;
		if ((*it)->getPosition().x - center.x > r) continue;

		if ((((*it)->getPosition().x - center.x)*((*it)->getPosition().x - center.x) + ((*it)->getPosition().y - center.y)*((*it)->getPosition().y - center.y)) < r*r){
			this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, (*it)->getPosition(), false);
			(*it)->setInvalid();
		}
	}
	for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
		for (unsigned int i = 0; i < (*it)->getLazerDivSize(); ++i){
			if (center.y - (*it)->getLazerDivPosition(i).y > r) continue;
			if ((*it)->getLazerDivPosition(i).y - center.y > r) continue;
			if (center.x - (*it)->getLazerDivPosition(i).x > r) continue;
			if ((*it)->getLazerDivPosition(i).x - center.x > r) continue;

			if (((*it)->getLazerDivPosition(i).x - center.x)*((*it)->getLazerDivPosition(i).x - center.x) + ((*it)->getLazerDivPosition(i).y - center.y)*((*it)->getLazerDivPosition(i).y - center.y) < r*r){
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, (*it)->getLazerDivPosition(i), false);
				(*it)->setLazerDivInvalid(i);
			}
		}
	}
}

void EnemyBulletManageEX::isetBulletStop(Point center, int r){
	this->coldingCenter = center;
	this->coldingRadius = r;
}

void EnemyBulletManageEX::isetBulletFlex(Point center, int r){
	int d = r*r;
	
	if (this->igetBossEventNow->igetBossFightingNow() == false){
		for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
			if ((((*it)->getPosition().x - center.x)*((*it)->getPosition().x - center.x) + ((*it)->getPosition().y - center.y)*((*it)->getPosition().y - center.y)) < d){
				(*it)->setInvalid();
				this->isetStandShockLazerEX->isetStandShockLazerEX((*it)->getPosition());
				if (this->igetIsColding->igetIsColding() == true){
					if (((*it)->getPosition().x - this->coldingCenter.x)*((*it)->getPosition().x - this->coldingCenter.x) + ((*it)->getPosition().y - this->coldingCenter.y)*((*it)->getPosition().y - this->coldingCenter.y) < this->coldingRadius*this->coldingRadius){
						this->isetStandShockLazerEX->isetStandShockLazerEX((*it)->getPosition());
					}
				}
			}
		}
		for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
			(*it)->setStandFlex(center, r, this->isetStandShockLazerEX);
		}
	}
	else{
		for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
			if ((((*it)->getPosition().x - center.x)*((*it)->getPosition().x - center.x) + ((*it)->getPosition().y - center.y)*((*it)->getPosition().y - center.y)) < d){
				(*it)->setInvalid();
				if ((((*it)->getPosition().x - this->igetBoss->igetBoss(0)->getPosition().x)*((*it)->getPosition().x - this->igetBoss->igetBoss(0)->getPosition().x) + ((*it)->getPosition().y - this->igetBoss->igetBoss(0)->getPosition().y)*((*it)->getPosition().y - this->igetBoss->igetBoss(0)->getPosition().y)) > 10000){
					this->isetStandShockLazerEX->isetStandShockLazerEX((*it)->getPosition());
					if (this->igetIsColding->igetIsColding() == true){
						if (((*it)->getPosition().x - this->coldingCenter.x)*((*it)->getPosition().x - this->coldingCenter.x) + ((*it)->getPosition().y - this->coldingCenter.y)*((*it)->getPosition().y - this->coldingCenter.y) < this->coldingRadius*this->coldingRadius){
							this->isetStandShockLazerEX->isetStandShockLazerEX((*it)->getPosition());
						}
					}
				}
			}
		}
		for (vector<EnemyLazerBase*>::iterator it = this->lazer.begin(); it != this->lazer.end(); ++it){
			(*it)->setStandFlex(center, r, this->isetStandShockLazerEX, this->igetBoss->igetBoss(0)->getPosition());
		}
	}
}

void EnemyBulletManageEX::isetBulletClearAfterStop(){
	if (this->igetIsColding->igetIsColding() == false) return;

	for (int i = 0; i < this->bullet.size();){
		if (this->bullet[i]->getValidate() == false){
			delete this->bullet[i];
			this->bullet.erase(this->bullet.begin() + i);
			continue;
		}
		if ((this->bullet[i]->getPosition().x - this->coldingCenter.x)*(this->bullet[i]->getPosition().x - this->coldingCenter.x) + (this->bullet[i]->getPosition().y - this->coldingCenter.y)*(this->bullet[i]->getPosition().y - this->coldingCenter.y) < this->coldingRadius*this->coldingRadius){
			this->bullet[i]->setInvalid();
			this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, this->bullet[i]->getPosition(), false);
			Sound::playSound(Sound_TimeAlart);
			Sound::playSound(Sound_explosion);
		}
		++i;
	}
	for (int i = 0; i < this->lazer.size();){
		if (this->lazer[i]->getValidate() == false){
			delete this->lazer[i];
			this->lazer.erase(this->lazer.begin() + i);
			continue;
		}
		for (int j = 0; j < this->lazer[i]->getLazerDivSize(); j++){
			if ((this->lazer[i]->getLazerDivPosition(j).x - this->coldingCenter.x)*(this->lazer[i]->getLazerDivPosition(j).x - this->coldingCenter.x) + (this->lazer[i]->getLazerDivPosition(j).y - this->coldingCenter.y)*(this->lazer[i]->getLazerDivPosition(j).y - this->coldingCenter.y) < this->coldingRadius*this->coldingRadius){
				this->lazer[i]->setLazerDivInvalid(j);
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, this->lazer[i]->getLazerDivPosition(j), false);
				Sound::playSound(Sound_explosion);
			}
		}
		++i;
	}
}