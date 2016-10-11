#include "item.h"
#include "picture.h"
#include "DxLib.h"

Item::Item(Point position, ItemColor color, ItemKind kind, IGetPosition* playerPosition){
	this->count=0;
	this->rotate_rad=0;
	this->trans_rad=M_PI/2;
	this->rotate_vel=M_PI/12.5;
	this->trans_vel=-2.0;
	this->position = position;
	this->kind = kind;
	this->color = color;
	this->validated = true;
	this->status = Item_Appearing;
	this->playerPosition = playerPosition;

	if (kind == Item_Small)this->size = Size(8,8);
	else this->size = Size(12, 12);
}

void Item::initialize(){

}

void Item::update(){
	this->count++;
	if (this->status == Item_Appearing){
		this->rotate_rad += this->rotate_vel;
		this->position.y += this->trans_vel;
		this->trans_vel += 0.02;

		if (this->count == 200){
			this->count = 0;
			this->rotate_rad = 0.00;
			this->status = Item_Falling;
		}
	}
	if (this->status == Item_Falling){
		this->position.y += this->trans_vel;
		if (((this->position.x - this->playerPosition->igetPosition().x)*(this->position.x - this->playerPosition->igetPosition().x) + (this->position.y - this->playerPosition->igetPosition().y)*(this->position.y - this->playerPosition->igetPosition().y)) < 2500)this->status = Item_Retrieved;
	}
	if (this->status == Item_Retrieved){
		this->rotate_rad = 0.0;
		this->trans_vel = 10.0;
		this->trans_rad = atan2(this->playerPosition->igetPosition().y - this->position.y, this->playerPosition->igetPosition().x - this->position.x);
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
	}
	
	if(this->position.y>GAME_WINDOW_HEIGHT+this->size.height) this->validated = false;
}

void Item::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	DrawRotaGraph2((int)this->position.x+GAME_WINDOW_OFFSET_X,(int)this->position.y+GAME_WINDOW_OFFSET_Y,this->size.width/2,this->size.height/2,1.0,
		this->rotate_rad,Picture::getItem(this->kind,this->color),true);
}

void Item::finalize(){

}

void Item::setStatus(ItemStatus status){
	this->status = status;
}