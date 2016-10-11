#include "textEffectManage.h"

TextEffectManage::TextEffectManage(){
	this->textEffect.clear();
	this->vectorSize_pre = 0;
}

void TextEffectManage::initialize(){

}

void TextEffectManage::update(){
	if (this->vectorSize_pre != this->textEffect.size()){
		for (int i = 0; i < this->textEffect.size(); i++){
			this->textEffect[i]->moveTo(180 - 30 * (this->textEffect.size() - 1) + 60 * i);
		}
	}
	this->vectorSize_pre = this->textEffect.size();

	for (vector<TextEffect*>::iterator it = this->textEffect.begin(); it != this->textEffect.end(); ){
		if ((*it)->getValidate() == false){
			delete *it;
			it = this->textEffect.erase(it);
			continue;
		}
		(*it)->update();
		++it;
	}
}

void TextEffectManage::draw(){
	for (vector<TextEffect*>::iterator it = this->textEffect.begin(); it != this->textEffect.end(); it++){
		(*it)->draw();
	}
}

void TextEffectManage::finalize(){
	for (vector<TextEffect*>::iterator it = this->textEffect.begin(); it != this->textEffect.end();){
		delete *it;
		it = this->textEffect.erase(it);
	}
}

void TextEffectManage::isetTextEffect(TextEffectKind kind){
	this->textEffect.push_back(new TextEffect(180+30*this->textEffect.size(), kind));
}