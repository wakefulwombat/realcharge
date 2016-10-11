#include "numericalBar.h"
#include "DxLib.h"
#include "picture.h"


NumericalBar::NumericalBar(IGetPosition* igetPosition, const double* numer, const double* denom, bool isCirclePink, bool invalidAtZero, bool isPlayer){
	this->validated=true;
	this->numer_d = numer;
	this->denom_d = denom;
	this->igetPosition = igetPosition;
	this->type_int=false;
	this->isCirclePink = isCirclePink;
	this->invalidAtZero = invalidAtZero;
	this->isPlayer = isPlayer;
}

NumericalBar::NumericalBar(IGetPosition* igetPosition, const int* numer, const int* denom, bool isCirclePink, bool invalidAtZero, bool isPlayer){
	this->validated=true;
	this->numer_i = numer;
	this->denom_i = denom;
	this->igetPosition = igetPosition;
	this->type_int=true;
	this->isCirclePink = isCirclePink;
	this->invalidAtZero = invalidAtZero;
	this->isPlayer = isPlayer;
}

void NumericalBar::initialize(){

}

void NumericalBar::update(){
	if(this->type_int==false){
		if((*this->numer_d)>=(*this->denom_d)){
			this->validated=false;
		}
		if (this->invalidAtZero == true){
			if ((*this->numer_d) <= 0){
				this->validated = false;
			}
		}
	}
	else{
		if((*this->numer_i)>=(*this->denom_i)){
			this->validated=false;
		}
		if (this->invalidAtZero == true){
			if ((*this->numer_i) <= 0){
				this->validated = false;
			}
		}
	}
}

void NumericalBar::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,100);
	if(this->type_int==false){
		double percent = *this->numer_d/(*this->denom_d);
		DrawCircleGauge(GAME_WINDOW_OFFSET_X + (int)this->igetPosition->igetPosition().x, GAME_WINDOW_OFFSET_Y + (int)this->igetPosition->igetPosition().y, 100.0*percent, Picture::getEnemyLife(this->isCirclePink));
	}
	else{
		double percent = 100.0*(*this->numer_i)/(*this->denom_i);
		DrawCircleGauge(GAME_WINDOW_OFFSET_X+(int)this->igetPosition->igetPosition().x,GAME_WINDOW_OFFSET_Y+(int)this->igetPosition->igetPosition().y,percent,Picture::getEnemyLife(this->isCirclePink));
	}
}

void NumericalBar::finalize(){

}