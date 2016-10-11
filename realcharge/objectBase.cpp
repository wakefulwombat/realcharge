#include "objectBase.h"

ObjectBase::ObjectBase(){
	this->count=0;
	this->validated=true;
	this->visible=false;
	this->position.x=0.0;
	this->position.y=0.0;
	this->size.height=0;
	this->size.width=0;
}

void ObjectBase::update(){

}

void ObjectBase::draw(){

}