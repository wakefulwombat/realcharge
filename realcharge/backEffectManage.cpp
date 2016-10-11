#include "backEffectManage.h"

BackEffectManage::BackEffectManage(){
	this->backEffect.clear();
}

void BackEffectManage::initialize(){
	for(list<BackEffect*>::iterator it=this->backEffect.begin();it!=this->backEffect.end();++it){
		(*it)->initialize();
	}
}

void BackEffectManage::update(){
	for(list<BackEffect*>::iterator it=this->backEffect.begin();it!=this->backEffect.end();){
		if((*it)->getValidate()==false){
			delete(*it);
			it = this->backEffect.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void BackEffectManage::draw(){
	for(list<BackEffect*>::iterator it=this->backEffect.begin();it!=this->backEffect.end();++it){
		(*it)->draw();
	}
}

void BackEffectManage::finalize(){
	for(list<BackEffect*>::iterator it=this->backEffect.begin();it!=this->backEffect.end();++it){
		(*it)->finalize();
	}
}

void BackEffectManage::isetBackEffect(int kind,Point position){
	this->backEffect.push_back(new BackEffect(kind,position,BackEffect_Falling));
}

void BackEffectManage::isetBackEffect(int kind, Point position, int validTime){
	this->backEffect.push_back(new BackEffect(kind, position, BackEffect_EnemyAppear, validTime));
}

void BackEffectManage::isetBackEffectClearAll(){
	this->backEffect.clear();
}