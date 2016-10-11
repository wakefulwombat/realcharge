#include "textEffect.h"
#include "DxLib.h"
#include "picture.h"

TextEffect::TextEffect(int pos_y, TextEffectKind kind){
	if (kind == TXT_STAGE_CLEAR) this->position.x = 110;
	if (kind == TXT_BARRAGE_BREAK) this->position.x = 60;
	if (kind == TXT_BOSS_BREAK) this->position.x = 130;
	if (kind == TXT_FAILURE) this->position.x = 150;
	if (kind == TXT_GET_BONUS) this->position.x = 50;

	this->position.y = pos_y;
	this->kind = kind;
	this->movec = 0;
	this->moveFlag = false;
	this->moveDistance = Point(0,0);

	this->count = 0;
	this->validated = true;
}

void TextEffect::initialize(){

}

void TextEffect::update(){
	this->count++;

	if (this->count > 200){
		this->validated = false;
	}

	if (this->moveFlag == true){
		this->movec++;

		this->position.y += (2.0*this->moveDistance.y / 40.0 - 2.0*this->moveDistance.y / 1600.0*this->movec);

		if (this->movec == 40) this->moveFlag = false;
	}
}

void TextEffect::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(100+150.0*sin(this->count*2.0*M_PI/30)));
	DrawGraph(GAME_WINDOW_OFFSET_X + (int)this->position.x, GAME_WINDOW_OFFSET_Y + (int)this->position.y, Picture::getTextEffect(this->kind), true);
}

void TextEffect::finalize(){

}

void TextEffect::moveTo(int newPos_y){
	this->movec = 0;
	this->moveDistance = Point(0,this->position.y-newPos_y);
	this->moveFlag = true;
}

bool TextEffect::isMoving(){
	return this->moveFlag;
}