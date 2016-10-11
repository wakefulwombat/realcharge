#include "shockLazer.h"
#include "DxLib.h"
#include "picture.h"
#include <math.h>

ShockLazer::ShockLazer(const int maxNum,double power,Point start,Point end):maxDivNum(maxNum){
	this->power=power;
	this->start=start;
	this->end=end;

	if(GetRand(2)==0) this->control1 = Point(-1.0*GetRand(500)+100.0,GAME_WINDOW_HEIGHT+-1.0*GetRand(500)+100.0);
	else this->control1 = Point(GAME_WINDOW_WIDTH+1.0*GetRand(500)-100.0,GAME_WINDOW_HEIGHT+1.0*GetRand(500)-100.0);

	this->count=0;
	this->divCount=0;
	this->validated=true;
	this->size = Size(18,28);
}

void ShockLazer::initialize(){

}

void ShockLazer::update(){
	if(this->divCount<this->maxDivNum){
		ShockLazerDiv tmp;
		tmp.count=0;
		tmp.validated=true;
		tmp.center=this->start;
		tmp.before_center=this->start;
		tmp.rotate_rad=0.0;
		tmp.before_rotate_rad=0.0;

		this->shockLazerDiv.push_back(tmp);
		this->divCount++;
	}

	int sum=0;
	for(unsigned int i=0;i<this->shockLazerDiv.size();i++){
		if(this->shockLazerDiv[i].validated==false) continue;
		else sum++;

		if((this->shockLazerDiv[i].count>80)&&(this->isVisivle(i)==false)){
			this->shockLazerDiv[i].validated=false;
			continue;
		}

		this->shockLazerDiv[i].count++;
		if(i==0){
			this->shockLazerDiv[0].before_center = this->shockLazerDiv[0].center;
			this->shockLazerDiv[0].center = this->getBezierNextPos(this->shockLazerDiv[0].count);
			this->shockLazerDiv[0].before_rotate_rad = this->shockLazerDiv[0].rotate_rad;
			this->shockLazerDiv[0].rotate_rad = atan2(this->shockLazerDiv[0].before_center.y-this->shockLazerDiv[0].center.y,this->shockLazerDiv[0].before_center.x-this->shockLazerDiv[0].center.x)+M_PI/2;
		}
		else{
			if(this->shockLazerDiv[i-1].validated==false){
				this->shockLazerDiv[i].before_center = this->shockLazerDiv[i].center;
				this->shockLazerDiv[i].center = this->getBezierNextPos(this->shockLazerDiv[i].count);
				this->shockLazerDiv[i].before_rotate_rad = this->shockLazerDiv[i].rotate_rad;
				this->shockLazerDiv[i].rotate_rad = atan2(this->shockLazerDiv[i].before_center.y-this->shockLazerDiv[i].center.y,this->shockLazerDiv[i].before_center.x-this->shockLazerDiv[i].center.x)+M_PI/2;
			}
			else{
				this->shockLazerDiv[i].before_center = this->shockLazerDiv[i].center;
				this->shockLazerDiv[i].center = this->shockLazerDiv[i-1].before_center;
				this->shockLazerDiv[i].before_rotate_rad = this->shockLazerDiv[i].rotate_rad;
				this->shockLazerDiv[i].rotate_rad = this->shockLazerDiv[i-1].before_rotate_rad;
			}
		}
	}

	if((this->shockLazerDiv.size()!=0)&&(sum==0)) this->validated=false;
}

void ShockLazer::draw(){
	for(unsigned int i=0;i<this->shockLazerDiv.size();i++){
		if(this->shockLazerDiv[i].validated==false)continue;

		if(this->shockLazerDiv[i].count<7) SetDrawBlendMode(DX_BLENDMODE_ADD, 5);
		else SetDrawBlendMode(DX_BLENDMODE_ADD, 30);
		DrawRotaGraph3(GAME_WINDOW_OFFSET_X+Round(this->shockLazerDiv[i].center.x),GAME_WINDOW_OFFSET_Y+Round(this->shockLazerDiv[i].center.y)
			,this->size.width/2,this->size.height/2,1.0,3.5,this->shockLazerDiv[i].rotate_rad,Picture::getBullet(Bul_Lazer,Bul_Blue),true);
	}
}

void ShockLazer::finalize(){

}

bool ShockLazer::isVisivle(int index){
	if(this->shockLazerDiv[index].center.x<-30) return false;
	if(this->shockLazerDiv[index].center.y<-30) return false;
	if(this->shockLazerDiv[index].center.x>GAME_WINDOW_WIDTH+30) return false;
	if(this->shockLazerDiv[index].center.y>GAME_WINDOW_HEIGHT+30) return false;

	return true;
}

Point ShockLazer::getBezierNextPos(int count){
	Point pos;
	double t = 1.0*count/60;
	pos.x = this->start.x*(1.0-t)*(1.0-t) + 2.0*this->control1.x*t*(1.0-t) + this->end.x*t*t;
	pos.y = this->start.y*(1.0-t)*(1.0-t) + 2.0*this->control1.y*t*(1.0-t) + this->end.y*t*t;
	return pos;
}