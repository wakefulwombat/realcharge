#include "playerBulletManagerEX.h"

PlayerBulletManagerEX::PlayerBulletManagerEX(){
	this->bullet.clear();
}

void PlayerBulletManagerEX::initialize(){

}

void PlayerBulletManagerEX::update(){
	for (vector<PlayerBulletEX*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ){
		if ((*it)->getValidate() == false){
			delete(*it);
			it = this->bullet.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void PlayerBulletManagerEX::draw(){
	for (vector<PlayerBulletEX*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		(*it)->draw();
	}
}

void PlayerBulletManagerEX::finalize(){
	for (vector<PlayerBulletEX*>::iterator it = this->bullet.begin(); it != this->bullet.end(); ++it){
		(*it)->finalize();
		delete (*it);
	}
}

void PlayerBulletManagerEX::isetPlayerBulletEX(Point pos, BulletKind kind, BulletColor color, int movePattern, double attackPower, double trans_vel0, double trans_acc, double trans_rad0, int disappTime_min){
	this->bullet.push_back(new PlayerBulletEX(pos, kind, color, movePattern, attackPower, trans_vel0, trans_acc, trans_rad0, disappTime_min));
}