#include "enemyLazerBezier.h"
#include "DxLib.h"
#include "picture.h"

EnemyLazerBezier::EnemyLazerBezier(BezierInfo info, BulletColor color, int maxDivNum, int disappTime_min) :EnemyLazerBase(maxDivNum){
	this->bezierInfo = info;
	this->color = color;
	this->disappTime_min = disappTime_min;

	this->count = 0;
	this->divCount = 0;
	this->lazerDiv.clear();
}

void EnemyLazerBezier::initialize(){
	this->count = 0;
	this->divCount = 0;
	this->lazerDiv.clear();
}

void EnemyLazerBezier::update(){
	if (this->divCount<this->maxDivNum){
		ShockLazerDiv tmp;
		tmp.count = 0;
		tmp.validated = true;
		tmp.center = this->bezierInfo.start;
		tmp.before_center = this->bezierInfo.start;
		tmp.rotate_rad = 0.0;
		tmp.before_rotate_rad = 0.0;

		this->lazerDiv.push_back(tmp);
		this->divCount++;
	}

	int sum = 0;
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;
		sum++;

		if (this->lazerDiv[i].count > this->disappTime_min){
			if (this->lazerDiv[i].center.x < -this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.y < -this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.x > GAME_WINDOW_WIDTH + this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.y > GAME_WINDOW_HEIGHT + this->size.height) this->lazerDiv[i].validated = false;
		}

		if (this->lazerDiv[i].isInColding == true){
			if (i != 0){
				if (this->lazerDiv[i - 1].isInColding == false){
					this->lazerDiv[i - 1].validated = false;
				}
			}
			continue;
		}

		this->lazerDiv[i].count++;
		if (i == 0){
			this->lazerDiv[0].before_center = this->lazerDiv[0].center;
			this->lazerDiv[0].center = this->getBezierNextPos(this->lazerDiv[0].count);
			this->lazerDiv[0].before_rotate_rad = this->lazerDiv[0].rotate_rad;
			this->lazerDiv[0].rotate_rad = atan2(this->lazerDiv[0].before_center.y - this->lazerDiv[0].center.y, this->lazerDiv[0].before_center.x - this->lazerDiv[0].center.x) + M_PI / 2;
		}
		else{
			if (this->lazerDiv[i - 1].validated == true){
				this->lazerDiv[i].before_center = this->lazerDiv[i].center;
				this->lazerDiv[i].center = this->lazerDiv[i - 1].before_center;
				this->lazerDiv[i].before_rotate_rad = this->lazerDiv[i].rotate_rad;
				this->lazerDiv[i].rotate_rad = this->lazerDiv[i - 1].before_rotate_rad;
			}
			else{
				this->lazerDiv[i].before_center = this->lazerDiv[i].center;
				this->lazerDiv[i].center = this->getBezierNextPos(this->lazerDiv[i].count);
				this->lazerDiv[i].before_rotate_rad = this->lazerDiv[i].rotate_rad;
				this->lazerDiv[i].rotate_rad = atan2(this->lazerDiv[i].before_center.y - this->lazerDiv[i].center.y, this->lazerDiv[i].before_center.x - this->lazerDiv[i].center.x) + M_PI / 2;
			}
		}
	}
	if (this->lazerDiv.size() != 0){
		if (sum == 0) this->validated = false;
	}
}

void EnemyLazerBezier::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ADD, 30);
	for (unsigned int i = 0; i<this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false)continue;
		DrawRotaGraph3(GAME_WINDOW_OFFSET_X + Round(this->lazerDiv[i].center.x), GAME_WINDOW_OFFSET_Y + Round(this->lazerDiv[i].center.y)
			, this->size.width / 2, this->size.height / 2, 1.0, 3.5, this->lazerDiv[i].rotate_rad, Picture::getBullet(Bul_Lazer, this->color), true);
	}
}

void EnemyLazerBezier::finalize(){

}

Point EnemyLazerBezier::getBezierNextPos(int count){
	Point pos;
	double t = 1.0*count / this->bezierInfo.arriveTime;
	pos.x = this->bezierInfo.start.x*(1.0 - t)*(1.0 - t) + 2.0*this->bezierInfo.control1.x*t*(1.0 - t) + this->bezierInfo.end.x*t*t;
	pos.y = this->bezierInfo.start.y*(1.0 - t)*(1.0 - t) + 2.0*this->bezierInfo.control1.y*t*(1.0 - t) + this->bezierInfo.end.y*t*t;
	return pos;
}

void EnemyLazerBezier::setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX){
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;
		
		if ((this->lazerDiv[i].center.x - center.x)*(this->lazerDiv[i].center.x - center.x) + (this->lazerDiv[i].center.y - center.y)*(this->lazerDiv[i].center.y - center.y) < r*r){
			this->lazerDiv[i].validated = false;
			isetStandShockLazerEX->isetStandShockLazerEX(this->lazerDiv[i].center);
		}
	}
}

void EnemyLazerBezier::setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX, Point bossPos){
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;

		if ((this->lazerDiv[i].center.x - center.x)*(this->lazerDiv[i].center.x - center.x) + (this->lazerDiv[i].center.y - center.y)*(this->lazerDiv[i].center.y - center.y) < r*r){
			this->lazerDiv[i].validated = false;
			if ((this->lazerDiv[i].center.x - bossPos.x)*(this->lazerDiv[i].center.x - bossPos.x) + (this->lazerDiv[i].center.y - bossPos.y)*(this->lazerDiv[i].center.y - bossPos.y) > 10000){
				isetStandShockLazerEX->isetStandShockLazerEX(this->lazerDiv[i].center);
			}
		}
	}
}