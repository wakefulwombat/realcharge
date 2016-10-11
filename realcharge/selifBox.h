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
	Point posDiff;//���W����
	string text;
	SelifBoxType boxType;
	int timer;
public:
	SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size);//�퓬�O�{�X��b��z��
	SelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime);//�����G�̔�����z��
	SelifBox(Point position,string text,Size size);//���y���ł̐����Ȃǂ�z��
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void setInvalid();
};


#endif