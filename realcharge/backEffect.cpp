#include "backEffect.h"
#include "DxLib.h"
#include "picture.h"
#include <math.h>

BackEffect::BackEffect(int kind, Point position, BackEffectMoveType type){
	this->kind = kind;
	this->position = position;
	this->type = type;
	this->count = 0;

	this->trans_vel = 1.0*GetRand(30)/10 + 1.0;
	this->trans_rad = M_PI/4 + M_PI*GetRand(90)/180;
	this->rotate_rad = 0.0;
	this->rotate_vel = 1.0*GetRand(100)/500 - 0.1;
	this->size = Size(64,64);
	this->expand=0.3 + 1.0*GetRand(10)/10;
}

BackEffect::BackEffect(int kind, Point position, BackEffectMoveType type, int validTime){
	this->kind = kind;
	this->position = position;
	this->type = type;
	this->validTime = validTime;
	this->count = 0;

	this->trans_vel = 0;
	this->trans_rad = 0;
	this->rotate_rad = 0.0;
	this->rotate_vel = M_PI * 1 / 18;
	this->size = Size(64, 64);
	this->expand = 1.5;
}

void BackEffect::initialize(){

}

void BackEffect::update(){
	this->count++;

	switch (this->type){
	case BackEffect_Falling:
		this->position.x += (this->trans_vel*cos(this->trans_rad));
		this->position.y += (this->trans_vel*sin(this->trans_rad));

		this->rotate_rad += this->rotate_vel;

		if (this->count > 60){
			if ((this->position.x<-this->size.width) || (this->position.x>WINDOW_WIDTH + this->size.width) || (this->position.y<-(this->size.height)) || (this->position.y>WINDOW_HEIGHT + this->size.height)){
				this->validated = false;
			}
		}

		break;

	case BackEffect_EnemyAppear:
		this->expand = 1.5*(this->validTime - this->count) / this->validTime;
		this->rotate_rad += this->rotate_vel;

		if (this->count > this->validTime)this->validated = false;
		break;
	}
}

void BackEffect::draw(){
	if (this->type == BackEffect_Falling) SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 60);
	if (this->type == BackEffect_EnemyAppear) SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 220);
	DrawRotaGraph2(Round(this->position.x) + GAME_WINDOW_OFFSET_X, Round(this->position.y) + GAME_WINDOW_OFFSET_Y, this->size.width / 2, this->size.height / 2, this->expand, this->rotate_rad, Picture::getBackEffect(this->kind), true);
}

void BackEffect::finalize(){

}