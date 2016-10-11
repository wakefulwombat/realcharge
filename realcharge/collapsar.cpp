#include "collapsar.h"
#include "DxLib.h"
#include "picture.h"

Collapsar::Collapsar(Point pos){
	this->position = pos;
	this->count = 0;
	this->size = Size(120, 120);
	this->validated = true;
}

void Collapsar::initialize(){

}

void Collapsar::update(){
	this->count++;

	if (this->count == 10 * 8 - 1) this->validated = false;
}

void Collapsar::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 240);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X + this->position.x, GAME_WINDOW_OFFSET_Y + this->position.y, this->size.width / 2, this->size.height / 2, 2.0, M_PI*GetRand(360) / 180, Picture::getCollapsar((this->count - (this->count % 8)) / 8), true);
}

void Collapsar::finalize(){

}