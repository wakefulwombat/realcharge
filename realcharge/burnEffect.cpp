#include "burnEffect.h"
#include "DxLib.h"
#include "picture.h"
#include "sound.h"

BurnEffect::BurnEffect(BurnEffectColor color,double expand,Point position){
	this->count=0;
	this->animationDistanceTime=5;
	this->color = color;
	this->expand = expand;
	this->position = position;
	this->validated=true;
	this->size.width=240;
	this->size.height=240;

	Sound::playSound(Sound_explosion);
}

void BurnEffect::initialize(){

}

void BurnEffect::update(){
	this->count++;
	if(this->count >= this->animationDistanceTime*14 - 1 ){
		this->validated=false;
	}
}

void BurnEffect::draw(){
	if (this->validated == false) return;

	SetDrawMode(DX_DRAWMODE_NEAREST);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	int c = (this->count-(this->count%this->animationDistanceTime))/this->animationDistanceTime;
	DrawRotaGraph2((int)this->position.x + GAME_WINDOW_OFFSET_X, (int)this->position.y + GAME_WINDOW_OFFSET_Y, this->size.width / 2-1, this->size.height / 2-1, this->expand, 0.0, Picture::getBurnEffect(this->color, c), true);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
}

void BurnEffect::finalize(){

}