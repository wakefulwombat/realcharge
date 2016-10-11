#include "lazer.h"
#include "DxLib.h"
#include "input.h"


Lazer::Lazer(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0){
	this->bulletData = bulletData;
	this->position = position;

	this->trans_vel = trans_vel0;
	this->trans_acc = trans_acc0;
	this->trans_rad = trans_rad0;
	this->rotate_vel = rotate_vel0;
	this->rotate_acc = rotate_acc0;
	this->rotate_rad = rotate_rad0;

	this->count=0;
	this->validated=true;
}

void Lazer::initialize(){

}

void Lazer::update(){

}

void Lazer::draw(){

}

void Lazer::finalize(){

}