#include "shockWaveManage.h"
#include "shockWave.h"
#include "shockLazer.h"
#include "DxLib.h"
#include "picture.h"
#include "sound.h"

ShockWaveManage::ShockWaveManage(IGetEnemyInfomation* igetEnemyInfomaton, IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow){
	this->shockWave.clear();
	this->shockLazer.clear();
	this->igetEnemyInfomaton = igetEnemyInfomaton;
	this->igetBoss = igetBoss;
	this->igetBossEventNow = igetBossEventNow;

	this->isBossPractice = false;
}

ShockWaveManage::ShockWaveManage(IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow){
	this->shockWave.clear();
	this->shockLazer.clear();
	this->igetEnemyInfomaton = igetEnemyInfomaton;
	this->igetBoss = igetBoss;
	this->igetBossEventNow = igetBossEventNow;

	this->isBossPractice = true;
}

void ShockWaveManage::initialize(){
	for(vector<ShockWave*>::iterator it=this->shockWave.begin();it!=this->shockWave.end();++it){
		(*it)->initialize();
	}
	for (vector<ShockLazer*>::iterator it = this->shockLazer.begin(); it != this->shockLazer.end(); ++it){
		(*it)->initialize();
	}
}

void ShockWaveManage::update(){
	for(vector<ShockWave*>::iterator it=this->shockWave.begin();it!=this->shockWave.end();){
		if((*it)->getValidate()==false){
			delete(*it);
			it = this->shockWave.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
	for (vector<ShockLazer*>::iterator it = this->shockLazer.begin(); it != this->shockLazer.end();){
		if ((*it)->getValidate() == false){
			delete(*it);
			it = this->shockLazer.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void ShockWaveManage::draw(){
	for (vector<ShockWave*>::iterator it = this->shockWave.begin(); it != this->shockWave.end(); ++it){
		(*it)->draw();
	}
	for (vector<ShockLazer*>::iterator it = this->shockLazer.begin(); it != this->shockLazer.end(); ++it){
		(*it)->draw();
	}
}

void ShockWaveManage::finalize(){
	for (vector<ShockWave*>::iterator it = this->shockWave.begin(); it != this->shockWave.end(); ++it){
		(*it)->finalize();
	}
	for (vector<ShockLazer*>::iterator it = this->shockLazer.begin(); it != this->shockLazer.end(); ++it){
		(*it)->finalize();
	}
}

void ShockWaveManage::isetShockWave(int power,Point position){
	if(power < 150){
		this->shockWave.push_back(new ShockWave(power,0,position));
		Sound::playSound(Sound_shotChargingPower);
	}
	else if(power < 200){
		this->shockWave.push_back(new ShockWave(power, 1, position));
		Sound::playSound(Sound_shotChargingPower);
	}
	else if(power < 300){
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(-60.0, 0.0)));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(-30.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 0, position, 16.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(30.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(60.0, 0.0)));
		Sound::playSound(Sound_shotChargingPower);
	}
	else if(power < 400){
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(-100.0, 0.0)));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(-50.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 1, position, 16.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(50.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(100.0, 0.0)));
		Sound::playSound(Sound_shotChargingPower);
	}
	else{
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(-100.0, 0.0)));
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(-60.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(-50.0, 0.0), 16.0));
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(-30.0, 0.0), 19.0));
		this->shockWave.push_back(new ShockWave(power, 1, position, 22.0));
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(30.0, 0.0), 19.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(50.0, 0.0), 16.0));
		this->shockWave.push_back(new ShockWave(power, 0, position + Point(60.0, 0.0), 13.0));
		this->shockWave.push_back(new ShockWave(power, 1, position + Point(100.0, 0.0)));
		Sound::playSound(Sound_shotChargingPower);
	}
}

void ShockWaveManage::isetStandShockLazerEX(Point pos){
	if (this->igetBossEventNow->igetBossFightingNow() == true){
		int num = this->igetBoss->igetBossSize();
		if (num == 0) this->shockLazer.push_back(new ShockLazer(10, 5.0, pos, Point(GetRand(GAME_WINDOW_WIDTH), GetRand(GAME_WINDOW_HEIGHT))));
		else this->shockLazer.push_back(new ShockLazer(10, 5.0, pos, this->igetBoss->igetBoss(GetRand(num - 1))->getPosition()));
	}
	else{
		if (this->isBossPractice == true){
			this->shockLazer.push_back(new ShockLazer(10, 5.0, pos, Point(GetRand(GAME_WINDOW_WIDTH), GetRand(GAME_WINDOW_HEIGHT))));
		}
		else{
			int num = this->igetEnemyInfomaton->igetEnemyNum();
			if (num == 0) this->shockLazer.push_back(new ShockLazer(10, 5.0, pos, Point(GetRand(GAME_WINDOW_WIDTH), GetRand(GAME_WINDOW_HEIGHT))));
			else this->shockLazer.push_back(new ShockLazer(10, 5.0, pos, this->igetEnemyInfomaton->igetEnemyPositionVectorIndex(GetRand(num - 1))));
		}
	}
}

void ShockWaveManage::isetShockLazerStraight(Point position, bool slowMove){
	if (slowMove == false) this->shockLazer.push_back(new ShockLazer(10, 3.0, position, Point(position.x, 50)));
	else this->shockLazer.push_back(new ShockLazer(10, 3.0, position, Point(position.x, position.y - 350.0)));
}