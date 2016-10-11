#include "selifBoxManage.h"


SelifBoxManage::SelifBoxManage(){
	this->selifBox.clear();
	this->count = 0;
}

void SelifBoxManage::initialize(){

}

void SelifBoxManage::update(){
	this->count++;

	if(this->selifBox.size()==0)return;
	for (list<SelifBox*>::iterator it = this->selifBox.begin(); it != this->selifBox.end();){
		if ((*it)->getValidate() == false){
			delete *it;
			it = this->selifBox.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void SelifBoxManage::draw(){
	if(this->selifBox.size()==0)return;
	for (list<SelifBox*>::iterator it = this->selifBox.begin(); it != this->selifBox.end(); ++it){
		(*it)->draw();
	}
}

void SelifBoxManage::finalize(){

}

void SelifBoxManage::isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size){
	this->selifBox.push_back(new SelifBox(igetPosition,diff,text,size));
}

void SelifBoxManage::isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime){
	this->selifBox.push_back(new SelifBox(igetPosition,diff,text,size,removeTime));
}

void SelifBoxManage::isetSelifBox(Point centerPosition,string text,Size size){
	this->selifBox.push_back(new SelifBox(centerPosition,text,size));
}

void SelifBoxManage::isetRemoveSelifBoxAll(){
	for(list<SelifBox*>::iterator it=this->selifBox.begin();it!=this->selifBox.end();it++){
		(*it)->setInvalid();
	}
}

bool SelifBoxManage::isEndSelifBox(){
	if(this->selifBox.size()==0) return true;
	else return false;
}