#include "bombManage.h"

BombManage::BombManage(){
	this->bomb.clear();
}

void BombManage::initialize(){

}

void BombManage::update(){
	for(vector<Bomb*>::iterator it=this->bomb.begin();it!=this->bomb.end();){
		if((*it)->getValidate()==false){
			delete(*it);
			it = this->bomb.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void BombManage::draw(){
	for(vector<Bomb*>::iterator it=this->bomb.begin();it!=this->bomb.end();++it){
		(*it)->draw();
	}
}

void BombManage::finalize(){

}

int BombManage::getBombVectorSizeMax(){
	return this->bomb.size();
}

Point BombManage::getPosition(int vectorIndex){
	return this->bomb[vectorIndex]->getPosition();
}

Size BombManage::getSize(int vectorIndex){
	return this->bomb[vectorIndex]->getSize();
}

void BombManage::setInvalid(int vectorIndex){
	this->bomb[vectorIndex]->setInvalid();
}

bool BombManage::getValid(int vectorIndex){
	return this->bomb[vectorIndex]->getValidate();
}

void BombManage::isetBomb(Point position,double trans_rad,bool isMove){
	this->bomb.push_back(new Bomb(position,trans_rad,isMove));
}