#include "enemyManage.h"
#include "sound.h"
#include "DxLib.h"

EnemyManage::EnemyManage(ISetBarrage* isetBarrage, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IAddBeatedCount* iaddBeatedCount, ISetBoss* isetBoss, IGetBossEventNow* igetBossEventNow, ISetBulletInvalid* isetBulletInvalid, ISetBurnEffect* isetBurnEffect, ISetBackEffect* isetBackEffect, int stageNumStartFromBoss){
	this->isetBarrage = isetBarrage;
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
	this->iaddBeatedCount = iaddBeatedCount;
	this->isetBoss = isetBoss;
	this->igetBossEventNow = igetBossEventNow;
	this->isetBulletInvalid = isetBulletInvalid;
	this->isetBurnEffect = isetBurnEffect;
	this->isetBackEffect = isetBackEffect;

	this->stageNumStartFromBoss = stageNumStartFromBoss;
	this->count = 0;

	this->enemy.clear();
}

void EnemyManage::initialize(){
	for(vector<Enemy*>::iterator it=this->enemy.begin();it!=this->enemy.end();++it){
		(*it)->initialize();
	}

	this->enemy.clear();
	this->count = 0;

	if (this->stageNumStartFromBoss != -1){
		switch (this->stageNumStartFromBoss){
		case 1: this->count = 4900; break;
		case 2: this->count = 4500; break;
		case 3: this->count = 5100; break;
		case 4: this->count = 8700; break;
		case 5: this->count = 6400; break;
		case 6: this->count = 5900; break;
		case 7: this->count = 14900; break;
		}
	}
}

void EnemyManage::update(){
	this->count++;
	for(int i=0;i!=this->enemyCSV.size();i++){
		if (this->enemyCSV[i].appearTime == (this->count+30)){
			this->isetBackEffect->isetBackEffect(GetRand(4), this->enemyCSV[i].startPosition,30);
		}
		if(this->enemyCSV[i].appearTime==this->count){
			if (this->enemyCSV[i].movePattern == 100){
				this->isetBoss->isetBeginBossStartEvent();
				for (vector<Enemy*>::iterator it = this->enemy.begin(); it != this->enemy.end(); ++it) (*it)->damaged(10000, false, 1.0);
				this->isetBulletInvalid->isetBulletInvalidAll(this->igetPlayerPosition->igetPosition(), 120);
			}
			else {
				this->enemy.push_back(new Enemy(&this->enemyCSV[i], i, this->isetBarrage, this->isetItem, this->igetPlayerPosition,this->isetBurnEffect));
			}
		}
	}

	for(vector<Enemy*>::iterator it=this->enemy.begin();it!=this->enemy.end();){
		if((*it)->getValidate()==false){
			if (((*it)->getLife() < 0)&&(this->igetBossEventNow->igetBossEventNow()==false)) this->iaddBeatedCount->iaddBeatedCount();
			this->isetBarrage->isetBarrageInvalidated((*it)->getCSVIndex());
			delete *it;
			it = this->enemy.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void EnemyManage::draw(){
	for(vector<Enemy*>::iterator it=this->enemy.begin();it!=this->enemy.end();++it){
		(*it)->draw();
	}
}

void EnemyManage::finalize(){
	for(vector<Enemy*>::iterator it=this->enemy.begin();it!=this->enemy.end();++it){
		(*it)->finalize();
	}
	this->enemy.clear();
}

int EnemyManage::igetEnemyNum(){
	int i=this->enemy.size();
	return i;
}

Point EnemyManage::igetEnemyPosition(int CSVIndex){
	for(vector<Enemy*>::iterator it=this->enemy.begin();it!=this->enemy.end();++it){
		if((*it)->getCSVIndex()==CSVIndex){
			return (*it)->getPosition();
		}
	}
	return Point(0.0,0.0);
}

Point EnemyManage::igetEnemyPositionVectorIndex(int vectorIndex){
	return this->enemy[vectorIndex]->getPosition();
}

void EnemyManage::clearEnemyDataList(){
	this->enemyCSV.clear();
}

void EnemyManage::setStaticEnemyData(StaticEnemyData staticEnemyData){
	this->enemyCSV.push_back(staticEnemyData);
}

IGetPosition* EnemyManage::getEnemyPosition(int vectorIndex){
	return this->enemy[vectorIndex];
}

Size EnemyManage::getEnemySize(int vectorIndex){
	return this->enemy[vectorIndex]->getSize();
}

int EnemyManage::getEnemyVectorSizeMax(){
	return this->enemy.size();
}

void EnemyManage::setEnemyInvalid(int vectorIndex){
	this->enemy[vectorIndex]->setInvalid();
}

void EnemyManage::damaged(int vectorIndex, double damage, bool isBurnEffect, double expand){
	this->enemy[vectorIndex]->damaged(damage, isBurnEffect, expand);
}

ISetEnemyDamage* EnemyManage::getISetEnemyDamage(int vectorIndex){
	return this->enemy[vectorIndex]->getThis();
}