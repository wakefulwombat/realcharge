#include "collapsarManage.h"
#include "DxLib.h"
#include "sound.h"

CollapsarManage::CollapsarManage(int difficulty){
	this->collapsar.clear();
	this->count = 0;
	this->isCollapsing = false;

	this->difficulty = difficulty;
}

void CollapsarManage::initialize(){

}

void CollapsarManage::update(){
	for (vector<Collapsar*>::iterator it = this->collapsar.begin(); it != this->collapsar.end();){
		if ((*it)->getValidate() == false){
			delete(*it);
			it = this->collapsar.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}

	if (this->isCollapsing == true){
		this->count++;
		if (this->difficulty == 0){
			if (this->count == 60) this->isCollapsing = false;
		}
		else if (this->difficulty == 1){
			if (this->count == 70) this->isCollapsing = false;
		}
		else{
			if (this->count == 80) this->isCollapsing = false;
		}

		if (this->count % 4 == 0){
			double rad;
			for (;;){
				rad = M_PI*GetRand(360) / 180;
				if (this->center.y + 2.0*this->count*sin(rad) < 0) continue;
				if (this->center.y + 2.0*this->count*sin(rad) > GAME_WINDOW_HEIGHT) continue;
				if (this->center.x + 2.0*this->count*cos(rad) < 0) continue;
				if (this->center.x + 2.0*this->count*cos(rad) > GAME_WINDOW_WIDTH) continue;

				break;
			}

			Sound::playSound(Sound_Collapsar);
			this->collapsar.push_back(new Collapsar(Point(this->center.x + 2.0*this->count*cos(rad), this->center.y + 2.0*this->count*sin(rad))));
		}
	}
}

void CollapsarManage::draw(){
	for (vector<Collapsar*>::iterator it = this->collapsar.begin(); it != this->collapsar.end(); ++it){
		(*it)->draw();
	}
}

void CollapsarManage::finalize(){
	for (vector<Collapsar*>::iterator it = this->collapsar.begin(); it != this->collapsar.end(); ++it){
		delete (*it);
	}
}

void CollapsarManage::istartCollapsar(Point pos){
	this->center = pos;
	this->count = 0;
	this->isCollapsing = true;
}