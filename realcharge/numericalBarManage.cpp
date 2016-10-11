#include "numericalBarManage.h"

NumericalBarManage::NumericalBarManage(){
	this->numaricalBar.clear();
}

void NumericalBarManage::initialize(){
	for(vector<NumericalBar*>::iterator it=this->numaricalBar.begin();it!=this->numaricalBar.end();++it){
		(*it)->initialize();
	}
}

void NumericalBarManage::update(){
	for(vector<NumericalBar*>::iterator it=this->numaricalBar.begin();it!=this->numaricalBar.end();){
		if((*it)->getValidate()==false){
			delete((*it));
			it = this->numaricalBar.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void NumericalBarManage::draw(){
	for(vector<NumericalBar*>::iterator it=this->numaricalBar.begin();it!=this->numaricalBar.end();++it){
		(*it)->draw();
	}
}

void NumericalBarManage::finalize(){
	for(vector<NumericalBar*>::iterator it=this->numaricalBar.begin();it!=this->numaricalBar.end();++it){
		(*it)->finalize();
	}
}

void NumericalBarManage::isetNumericalBar(IGetPosition* igetPosition, const double* numer, const double* denom, bool isPink, bool invalidAtZero, bool isPlayer){
	this->numaricalBar.push_back(new NumericalBar(igetPosition, numer, denom, isPink, invalidAtZero, isPlayer));
}

void NumericalBarManage::isetNumericalBar(IGetPosition* igetPosition, const int* numer, const int* denom, bool isPink, bool invalidAtZero, bool isPlayer){
	this->numaricalBar.push_back(new NumericalBar(igetPosition, numer, denom, isPink, invalidAtZero, isPlayer));
}

void NumericalBarManage::isetNumericalBarClearAroundPlayer(){
	for (vector<NumericalBar*>::iterator it = this->numaricalBar.begin(); it != this->numaricalBar.end(); ++it){
		if ((*it)->getIsPlayer() == true){
			(*it)->setInvalid();
		}
	}
}