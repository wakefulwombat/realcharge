#include "barrageManage.h"

BarrageManage::BarrageManage(ISetBullet* isetBullet,IGetPosition* igetPlayerPosition){
	this->isetBullet = isetBullet;
	this->igetPlayerPosition = igetPlayerPosition;
	this->barrage.clear();
	this->staticBarrageData.clear();

	this->isExtra = false;
}

BarrageManage::BarrageManage(ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, ISetEnemyLazer* isetEnemyLazer){
	this->isetBullet = isetBullet;
	this->isetEnemyLazer = isetEnemyLazer;
	this->igetPlayerPosition = igetPlayerPosition;
	this->barrage.clear();
	this->staticBarrageData.clear();

	this->isExtra = true;
}

void BarrageManage::initialize(){

}

void BarrageManage::update(){
	for(vector<Barrage*>::iterator it=this->barrage.begin();it!=this->barrage.end();){
		if((*it)->getValidate()==false){
			delete(*it);
			it = this->barrage.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void BarrageManage::finalize(){

}

void BarrageManage::clearBarrageDataList(){
	this->staticBarrageData.clear();
}

void BarrageManage::isetBarrage(int barrageCSVID,int enemyCSVIndex,Point position,IGetPosition* igetEnemyPosition){
	if (this->isExtra == false){
		for (vector<StaticBarrageData>::iterator it = this->staticBarrageData.begin(); it != this->staticBarrageData.end(); it++){
			if (it->CSVID == barrageCSVID){
				this->barrage.push_back(new Barrage(&(*it), enemyCSVIndex, barrageCSVID, position, this->isetBullet, this->igetPlayerPosition, igetEnemyPosition));
				break;
			}
		}
	}
	else{
		for (vector<StaticBarrageData>::iterator it = this->staticBarrageData.begin(); it != this->staticBarrageData.end(); it++){
			if (it->CSVID == barrageCSVID){
				this->barrage.push_back(new Barrage(&(*it), enemyCSVIndex, barrageCSVID, position, this->isetBullet, this->igetPlayerPosition, igetEnemyPosition, this->isetEnemyLazer));
				break;
			}
		}
	}
}

void BarrageManage::isetBarrageInvalidated(int EnemyCSVIndex){
	for(unsigned int i=0;i<this->barrage.size();i++){
		if(this->barrage[i]->getEnemyCSVIndex()==EnemyCSVIndex) this->barrage[i]->setInvalidated();
	}
}

void BarrageManage::setStaticBarrageData(StaticBarrageData staticBarrageData){
	this->staticBarrageData.push_back(staticBarrageData);
}

void BarrageManage::setBarrageInvalidated(int enemyCSVIndex){
	for(unsigned int i=0;i<this->barrage.size();i++){
		if(this->barrage[i]->getEnemyCSVIndex()==enemyCSVIndex) this->barrage[i]->setInvalidated();
		break;
	}
}