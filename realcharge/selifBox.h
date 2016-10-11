#ifndef _SERIFBOX_
#define _SERIFBOX_

#include "fixObject.h"
#include "igetPosition.h"
#include <string>
using namespace std;

enum WindowBaseLocation{
	Window_LeftUp,
	Window_Up,
	Window_RightUp,
	Window_Left,
	Window_Center,
	Window_Right,
	Window_LeftDown,
	Window_Down,
	Window_RightDown
};

enum SelifBoxType{
	SelifBox_Auto,
	SelifBox_Timer,
	SelifBox_Fixed
};

class SelifBox : public FixObject{
private:
	IGetPosition* igetPosition;
	Point posDiff;//座標差分
	string text;
	SelifBoxType boxType;
	int timer;
public:
	SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size);//戦闘前ボス会話を想定
	SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime);//道中敵の発言を想定
	SelifBox(Point position,string text,Size size);//音楽室での説明などを想定
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setInvalid();
};


#endif