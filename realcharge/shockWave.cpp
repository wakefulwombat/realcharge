#include "shockWave.h"
#include <math.h>
#include "DxLib.h"
#include "picture.h"

ShockWave::ShockWave(int power,int kind,Point position,double trans_vel){
	this->power=power;
	this->kind=kind;
	this->position = position;
	this->rotate_rad=M_PI*3/2;
	this->trans_rad=M_PI*3/2;
	this->trans_vel = trans_vel;
	this->count=0;
	this->chipCount=0;
	this->validated=true;

	if(kind==0) this->size=Size(56,56);
	if(kind==1) this->size=Size(70,70);
}

void ShockWave::initialize(){

}

void ShockWave::update(){
	if(this->position.y<-this->size.height) this->validated=false;

	this->position.y+=this->trans_vel*sin(this->trans_rad);

	this->count++;
	if(this->count%3==0)this->chipCount++;

	if(this->kind==0){//small
		if(this->chipCount==8) this->chipCount=0;
	}
	if(this->kind==1){//large
		if(this->chipCount==4) this->chipCount=0;
	}
}

void ShockWave::draw(){
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	if(this->kind==0){
		DrawRotaGraph2(GAME_WINDOW_OFFSET_X+Round(this->position.x),GAME_WINDOW_OFFSET_Y+Round(this->position.y),this->size.width/2,this->size.height/2,1.0,this->rotate_rad,Picture::getShockWave_s(this->chipCount),true);
	}
	if(this->kind==1){
		DrawRotaGraph2(GAME_WINDOW_OFFSET_X+Round(this->position.x),GAME_WINDOW_OFFSET_Y+Round(this->position.y),this->size.width/2,this->size.height/2,1.0,this->rotate_rad,Picture::getShockWave_l(this->chipCount),true);
	}
}

void ShockWave::finalize(){

}