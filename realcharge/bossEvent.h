#ifndef _BOSSEVENT_
#define _BOSSEVENT_

#include "input.h"
#include "IsetSelifBox.h"
#include "IsetBossMoveExternal.h"
#include "IgetPosition.h"
#include "common.h"
#include <string>
#include "music.h"
using namespace std;

enum BossEventEndTrigger{
	BEET_INPUTKEY,
	BEET_TIMER,
	BEET_NOW
};

enum BossEventType{
	BET_TALK,
	BET_MOVE,
	BET_MUSICCHANGE
};

struct StaticBossEventData{
	bool isBossEvent;
	int bossID;
	string selif;
	Size boxSize;
	Point boxDiff;
	BossEventType eventType;
};

class BossEvent{
private:
	int count;
	bool valid;
	int triggerTime;
	KeyCode_Explode triggerKey;
	BossEventEndTrigger endTrigger;
	BossEventType type;
	Point diff;
	string text;
	Size size;

	ISetSelifBox* isetSelifBox;
	IGetPosition* igetPosition;
	ISetBossMoveExternal* isetBossMoveExternal;

public:
	BossEvent(ISetSelifBox* isetSelifBox, IGetPosition* igetPosition, Point diff, string text, Size size);
	BossEvent(ISetBossMoveExternal* isetBossMoveExternal, Point moveTo, int movingTime);
	BossEvent(int stage);

	void startEvent();
	void skipEvent();
	void checkEndTrigger();
	bool getValid(){ return this->valid; }
};

#endif