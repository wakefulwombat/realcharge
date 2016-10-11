#include "itemManage.h"

ItemManage::ItemManage(){
	this->item.clear();
}

void ItemManage::initialize(){
	for(vector<Item*>::iterator it=this->item.begin();it!=this->item.end();++it){
		(*it)->initialize();
	}
}

void ItemManage::update(){
	for(vector<Item*>::iterator it=this->item.begin();it!=this->item.end();){
		if((*it)->getValidate()==false){
			delete *it;
			it = this->item.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void ItemManage::draw(){
	for(vector<Item*>::iterator it=this->item.begin();it!=this->item.end();++it){
		(*it)->draw();
	}
}

void ItemManage::finalize(){
	for(vector<Item*>::iterator it=this->item.begin();it!=this->item.end();++it){
		(*it)->finalize();
	}
	this->item.clear();
}

int ItemManage::getItemVectorSizeMax(){
	return this->item.size();
}

Point ItemManage::getPosition(int vectorIndex){
	return this->item[vectorIndex]->getPosition();
}

Size ItemManage::getSize(int vectorIndex){
	return this->item[vectorIndex]->getSize();
}

void ItemManage::setInvalid(int vectorIndex){
	this->item[vectorIndex]->setInvalid();
}

ItemKind ItemManage::getKind(int vectorIndex){
	return this->item[vectorIndex]->getKind();
}

ItemColor ItemManage::getColor(int vectorIndex){
	return this->item[vectorIndex]->getColor();
}

void ItemManage::isetItem(Point position,ItemColor color,ItemKind kind,IGetPosition* playerPosition){
	this->item.push_back(new Item(position,color,kind,playerPosition));
}

void ItemManage::isetItemStatusRetrieve(){
	for (vector<Item*>::iterator it = this->item.begin(); it != this->item.end(); ++it){
		(*it)->setStatus(Item_Retrieved);
	}
}