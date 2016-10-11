#include "bulletManage.h"
#include "DxLib.h"
#include "bullet.h"
#include "bossBullet.h"

BulletManage::BulletManage(ISetBurnEffect* isetBurnEffect){
	this->bullet.clear();

	this->isetBurnEffect = isetBurnEffect;
}

void BulletManage::initialize(){
	for(vector<BulletBase*>::iterator it=this->bullet.begin();it!=this->bullet.end();++it){
		(*it)->initialize();
	}
}

void BulletManage::update(){
	if (this->isClearing == true){
		this->clearingTimeCount++;
		if (this->clearingTimeCount == this->clearingTime){
			this->isClearing = false;
		}
		double d = 800.0 * this->clearingTimeCount / this->clearingTime;
		for (vector<BulletBase*>::iterator it = this->bullet.begin(); it != this->bullet.end();++it){
			if (this->clearingCenter.y - (*it)->getPosition().y > d) continue;
			if ((*it)->getPosition().y - this->clearingCenter.y > d) continue;
			if (this->clearingCenter.x - (*it)->getPosition().x > d) continue;
			if ((*it)->getPosition().x - this->clearingCenter.x > d) continue;

			if ((((*it)->getPosition().x - this->clearingCenter.x)*((*it)->getPosition().x - this->clearingCenter.x) + ((*it)->getPosition().y - this->clearingCenter.y)*((*it)->getPosition().y - this->clearingCenter.y)) < d*d){
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 0.1, (*it)->getPosition(), false);
				(*it)->setInvalid();
			}
		}
	}

	for (int i = 0; i < this->bullet.size();){
		if (this->bullet[i]->getValidate() == false){
			delete this->bullet[i];
			this->bullet.erase(this->bullet.begin()+i);
			continue;
		}
		this->bullet[i]->update();
		++i;
	}
}

void BulletManage::draw(){
	for(vector<BulletBase*>::iterator it=this->bullet.begin();it!=this->bullet.end();++it){
		(*it)->draw();
	}
}

void BulletManage::finalize(){
	for(vector<BulletBase*>::iterator it=this->bullet.begin();it!=this->bullet.end();++it){
		(*it)->finalize();
	}
}

void BulletManage::isetBullet(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0,ISetBullet* isetBullet){
	this->bullet.push_back(new Bullet(bulletData,position,trans_vel0,trans_acc0,trans_rad0,rotate_vel0,rotate_acc0,rotate_rad0,isetBullet));
}

void BulletManage::isetBossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1, double param2, double param3){
	this->bullet.push_back(new BossBullet(pos, kind, color, movePattern, isetBullet, igetPlayerPosition, trans_vel0, trans_acc, trans_rad0, rotate_vel, disappTime_min, param1, param2, param3));
}

int BulletManage::getBulletVectorSizeMax(){
	return this->bullet.size();
}

Point BulletManage::getBulletPosition(int vectorIndex){
	return this->bullet[vectorIndex]->getPosition();
}

Size BulletManage::getBulletSize(int vecotrIndex){
	return this->bullet[vecotrIndex]->getSize();
}

void BulletManage::setInvalid(int vectorIndex){
	this->bullet[vectorIndex]->setInvalid();
}

bool BulletManage::getValid(int vectorIndex){
	return this->bullet[vectorIndex]->getValidate();
}

void BulletManage::isetBulletInvalid(int vectorIndex){
	this->bullet[vectorIndex]->setInvalid();
}

void BulletManage::isetBulletInvalidAll(Point center, int validTime){
	this->clearingCenter = center;
	this->clearingTime = validTime;
	this->clearingTimeCount = 0;
	this->isClearing = true;
}