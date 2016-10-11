#include "selifBox.h"
#include "input.h"
#include "picture.h"
#include "DxLib.h"
#include <list>

static list<string> splitString(const string &src,const string &delim){
	list<string> dest;
	string::size_type start = 0;//デリミタを検索するインデクス番号
	while(true){
	    //デリミタが現れる最初のインデクスを求める
	    string::size_type end = src.find(delim, start);
	 
	    //デリミタが見つかった場合
		if(end != string::npos){
	        dest.push_back(src.substr(start, end - start));
	    }
	    //デリミタが見つからなかった場合
	    else{
	        //文末までを格納して返す
	        dest.push_back(src.substr(start, src.length() - start));
	        break;
	    }
	    //次の開始地点へ移動
	    start = end + delim.length();
	}
	return dest;
}

SelifBox::SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size){
	this->igetPosition = igetPosition;
	this->posDiff = diff;
	this->text = text;
	this->size.width = size.width*2+2;
	this->size.height = size.height*2+2;
	this->timer = -1;

	this->validated = true;
	this->boxType = SelifBox_Auto;
}

SelifBox::SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime){
	this->igetPosition = igetPosition;
	this->posDiff = diff;
	this->text = text;
	this->size.width = size.width * 2 + 2;
	this->size.height = size.height * 2 + 2;
	this->timer = removeTime;

	this->validated = true;
	this->boxType = SelifBox_Timer;
}

SelifBox::SelifBox(Point position,string text,Size size){
	this->position = position;
	this->text = text;
	this->size.width = size.width * 2 + 2;
	this->size.height = size.height * 2 + 2;
	this->timer = -1;

	this->validated = true;
	this->boxType = SelifBox_Fixed;
}

void SelifBox::initialize(){

}

void SelifBox::update(){
	this->count++;
	if (this->boxType == SelifBox_Auto){
		if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1) this->validated = false;
	}
	if (this->boxType == SelifBox_Timer){
		if (this->count == this->timer) this->validated = false;
	}
}

void SelifBox::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	Point cp;
	if (this->boxType == SelifBox_Auto) cp = Point(this->igetPosition->igetPosition().x + this->posDiff.x, this->igetPosition->igetPosition().y + this->posDiff.y);
	if (this->boxType == SelifBox_Timer) cp = Point(this->igetPosition->igetPosition().x + this->posDiff.x, this->igetPosition->igetPosition().y + this->posDiff.y);
	if (this->boxType == SelifBox_Fixed) cp = this->position;
	for(int w=0;w<this->size.width;w++){
		for(int h=0;h<this->size.height;h++){
			if(w==0){
				if(h==0){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_LeftUp),true);
				}
				else if(h==this->size.height-1){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_LeftDown),true);
				}
				else{
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_Left),true);
				}
			}
			else if(w==this->size.width-1){
				if(h==0){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_RightUp),true);
				}
				else if(h==this->size.height-1){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_RightDown),true);
				}
				else{
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_Right),true);
				}
			}
			else{
				if(h==0){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_Up),true);
				}
				else if(h==this->size.height-1){
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_Down),true);
				}
				else{
					DrawGraph(GAME_WINDOW_OFFSET_X+(int)cp.x-this->size.width*10/2+w*10,GAME_WINDOW_OFFSET_Y+(int)cp.y-this->size.height*10/2+h*10,Picture::getWindowBase(Window_Center),true);
				}
			}
		}
	}
	
	list<string> text_s = splitString(this->text,"nn");
	int i=0;
	for(list<string>::iterator it = text_s.begin();it!=text_s.end();it++){
		DrawString(GAME_WINDOW_OFFSET_X+(int)cp.x-5*(this->size.width-1),GAME_WINDOW_OFFSET_Y+(int)cp.y-5*(this->size.height-1)+20*i,it->c_str(),GetColor(255,255,255));
		i++;
	}
}

void SelifBox::finalize(){

}

void SelifBox::setInvalid(){
	this->validated = false;
}