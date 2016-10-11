#include "playerBulletEX.h"
#include <math.h>
#include "DxLib.h"
#include "picture.h"

PlayerBulletEX::PlayerBulletEX(Point pos, BulletKind kind, BulletColor color, int movePattern, double attackPower, double trans_vel0, double trans_acc, double trans_rad0, int disappTime_min){
	this->position = pos;
	this->kind = kind;
	this->color = color;
	this->movePattern = movePattern;
	this->attackPower = attackPower;
	this->trans_vel = trans_vel0;
	this->trans_acc = trans_acc;
	this->trans_rad = trans_rad0;
	this->disappTime_min = disappTime_min;

	switch (kind){
	case 0: this->size = Size(11, 19); break;
	case 1: this->size = Size(18, 20); break;
	case 2: this->size = Size(11, 19); break;
	case 3: this->size = Size(17, 15); break;
	case 4: this->size = Size(13, 22); break;
	case 5: this->size = Size(64, 64); break;
	case 6: this->size = Size(18, 28); break;
	case 7: this->size = Size(30, 30); break;
	case 8: this->size = Size(19, 18); break;
	case 9: this->size = Size(6, 14); break;
	case 10: this->size = Size(20, 38); break;
	case 11: this->size = Size(12, 12); break;
	case 12: this->size = Size(16, 16); break;
	case 13: this->size = Size(32, 32); break;
	case 14: this->size = Size(20, 20); break;
	}
}

void PlayerBulletEX::initialize(){

}

void PlayerBulletEX::update(){
	this->count++;

	switch (this->movePattern){
	case 0://’¼i
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		break;

	case 1://‰Á‘¬’¼i
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		break;

	case 2://y•ûŒü‚É‰Á‘¬
	{
		double vx, vy;
		vx = this->trans_vel*cos(this->trans_rad);
		vy = this->trans_vel*sin(this->trans_rad);
		this->position.x += vx;
		this->position.y += vy;
		vy += this->trans_acc;
		this->trans_vel = sqrt(vx*vx + vy*vy);
		this->trans_rad = atan2(vy, vx);
	}
	}
	this->rotate_rad = this->trans_rad - M_PI / 2;

	if (this->count > this->disappTime_min){
		if (this->position.y < -this->size.height) this->validated = false;
		if (this->position.x < -this->size.width) this->validated = false;
		if (this->position.x > GAME_WINDOW_WIDTH + this->size.width) this->validated = false;
	}
}

void PlayerBulletEX::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 150);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X + (int)this->position.x, GAME_WINDOW_OFFSET_Y + (int)this->position.y, this->size.width / 2, this->size.height / 2, 1.0, this->rotate_rad, Picture::getBullet(this->kind, this->color), true);
}

void PlayerBulletEX::finalize(){

}