#include "bullet.h"
#include "DxLib.h"
#include "picture.h"
#include "item.h"

Bullet::Bullet(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0,ISetBullet* isetBullet){
	this->bulletData = bulletData;
	this->position = position;
	this->isetBullet = isetBullet;

	this->trans_vel = trans_vel0;
	this->trans_acc = trans_acc0;
	this->trans_rad = trans_rad0;
	this->rotate_vel = rotate_vel0;
	this->rotate_acc = rotate_acc0;
	this->rotate_rad = rotate_rad0;

	this->count=0;
	this->validated=true;

	switch(bulletData->kind){
	case 0: this->size = Size(11,19);break;
	case 1: this->size = Size(18,20);break;
	case 2: this->size = Size(11,19);break;
	case 3: this->size = Size(17,15);break;
	case 4: this->size = Size(13,22);break;
	case 5: this->size = Size(64,64);break;
	case 6: this->size = Size(18,28);break;
	case 7: this->size = Size(30,30);break;
	case 8: this->size = Size(19,18);break;
	case 9: this->size = Size(6,14);break;
	case 10: this->size = Size(20,38);break;
	case 11: this->size = Size(12,12);break;
	case 12: this->size = Size(16,16);break;
	case 13: this->size = Size(32,32);break;
	case 14: this->size = Size(20,20);break;
	}
}

void Bullet::initialize(){
	
}

void Bullet::update(){
	this->count++;

	if(this->count>=this->bulletData->disappearTime_min){
		if((this->position.x<-this->size.width)||(this->position.y<-this->size.height)||(this->position.x>GAME_WINDOW_WIDTH+this->size.width)||(this->position.y>GAME_WINDOW_HEIGHT+this->size.height)){
			this->validated = false;
		}
	}

	this->move();
}

void Bullet::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA,200);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X+(int)this->position.x,GAME_WINDOW_OFFSET_Y+(int)this->position.y,this->size.width/2,this->size.height/2,1.0,this->rotate_rad,
		Picture::getBullet(this->bulletData->kind,this->bulletData->color),true);
}

void Bullet::finalize(){

}

void Bullet::move(){
	switch(this->bulletData->movePattern){
	case 0:
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;
	
	case 1:
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;
	
	case 2:
		this->position.x += abs(this->trans_vel)*cos(this->trans_rad);
		this->position.y += abs(this->trans_vel)*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;
	}
}