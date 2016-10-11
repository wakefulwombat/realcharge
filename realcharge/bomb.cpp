#include "bomb.h"
#include <math.h>
#include "DxLib.h"
#include "picture.h"

Bomb::Bomb(Point position,double trans_rad,bool isMove){
	if (isMove == true)	this->trans_vel=16.0;
	else this->trans_vel = 0.0;
	this->isMove = isMove;
	this->rotate_rad=0.0;
	this->rotate_vel = 1.0*GetRand(100)/1000+0.05;
	this->position = position;
	this->trans_rad=trans_rad;
	this->size=Size(24,24);
}

void Bomb::initialize(){

}

void Bomb::update(){
	if (this->isMove == true){
		this->trans_vel -= 1.0;
		if (this->trans_vel < 0.5) this->trans_vel = 0.5;
	}

	if((this->position.x<-20)||(this->position.y<-20)||(this->position.x>GAME_WINDOW_WIDTH+20)||(this->position.y>GAME_WINDOW_HEIGHT+20)) this->validated=false;

	this->position.x += this->trans_vel*cos(this->trans_rad);
	this->position.y += this->trans_vel*sin(this->trans_rad);

	this->rotate_rad+=this->rotate_vel;
}

void Bomb::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X+Round(this->position.x),GAME_WINDOW_OFFSET_Y+Round(this->position.y),this->size.width/2,this->size.height/2,1.0,this->rotate_rad,Picture::getPlayerBomb(),true);
}

void Bomb::finalize(){

}