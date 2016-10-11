#include "burnEffectManage.h"

BurnEffectManage::BurnEffectManage(int difficulty) : difficulty(difficulty){
	this->burnEffect.clear();
	this->burnEffect.reserve(2048);
	this->validCount = 0;
	this->isCounting = false;
}

void BurnEffectManage::initialize(){
	for(vector<BurnEffect*>::iterator it=this->burnEffect.begin();it!=this->burnEffect.end();++it){
		(*it)->initialize();
	}
}

void BurnEffectManage::update(){
	for(vector<BurnEffect*>::iterator it=this->burnEffect.begin();it!=this->burnEffect.end();){
		if((*it)->getValidate()==false){
			delete(*it);
			it = this->burnEffect.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}

	if (this->isCounting == true) this->validCount++;
}

void BurnEffectManage::draw(){
	for(vector<BurnEffect*>::iterator it=this->burnEffect.begin();it!=this->burnEffect.end();++it){
		(*it)->draw();
	}
}

void BurnEffectManage::finalize(){
	for(vector<BurnEffect*>::iterator it=this->burnEffect.begin();it!=this->burnEffect.end();++it){
		(*it)->finalize();
	}
}

int BurnEffectManage::getBurnEffectVectorSizeMax(){
	return this->burnEffect.size();
}

Point BurnEffectManage::getBurnEffectPosition(int vectorIndex){
	return this->burnEffect[vectorIndex]->getPosition();
}

double BurnEffectManage::getBurnEffectExpand(int vectorIndex){
	return this->burnEffect[vectorIndex]->getExpand();
}

Size BurnEffectManage::getBurnEffectSize(int vectorIndex){
	return this->burnEffect[vectorIndex]->getSize();
}

int BurnEffectManage::getBurnEffectCount(int vectorIndex){
	return this->burnEffect[vectorIndex]->getCount();
}

void BurnEffectManage::isetBurnEffect(BurnEffectColor color, double expand, Point position, bool isFromEnemyOrBullet){
	if (isFromEnemyOrBullet == false){
		if (this->burnEffect.size() == 0){
			this->validCount = 0;
			this->isCounting = true;
		}
		this->burnEffect.push_back(new BurnEffect(color, expand, position));
	}
	else{
		if (this->difficulty == 0){
			if (this->validCount < 60){
				this->burnEffect.push_back(new BurnEffect(color, expand, position));
			}
			else {
				this->isCounting = false;
			}
		}
		else if (this->difficulty == 1){
			if (this->validCount < 40){
				this->burnEffect.push_back(new BurnEffect(color, expand, position));
			}
			else {
				this->isCounting = false;
			}
		}
		else{
			if (this->validCount < 20){
				this->burnEffect.push_back(new BurnEffect(color, expand, position));
			}
			else {
				this->isCounting = false;
			}
		}
	}
}