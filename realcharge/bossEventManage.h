#ifndef _BOSSEVENTMANAGE_
#define _BOSSEVENTMANAGE_

#include <vector>
#include "bossEvent.h"
#include "IsetSelifBox.h"
#include "IsetBossMoveExternal.h"
#include "IgetBoss.h"
#include "IsetSelifBox.h"
#include "IgetStage.h"
using namespace std;

class BossEventManage{
private:
	vector<BossEvent*> startEvent;
	vector<BossEvent*> endEvent;
	vector<StaticBossEventData> staticStartBossEventData;
	vector<StaticBossEventData> staticEndBossEventData;
	int eventNumCount;

	IGetBoss* igetBoss;
	IGetPosition* igetPlayerPosition;
	ISetSelifBox* isetSelifBox;
	IGetStage* igetStage;

public:
	BossEventManage(IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetSelifBox* isetSelifBox, IGetStage* igetStage);

	void clearAllEvent();
	void clearAllStaticEventData();
	bool isAllEventEnd(bool isStartEvent);
	void update(bool isStartEvent);

	int getHowManyBossActorInEvent(bool isStartEvent);
	int getBossActorCharaChip(int id, bool isStartEvent);
	Point getBossActorInitialPosition(int id, bool isStartEvent);

	int getHowManyStaticEventExist(bool isStartEvent);
	StaticBossEventData* getStaticBossEventData(int num, bool isStartEvent);

	void setStaticBossEventData(StaticBossEventData dat,bool isStartEvent);

	void setBossEventBossTalk(ISetSelifBox* isetSelifBox, IGetPosition* igetPosition, Point diff, string text, Size size, bool isStartEvent);
	void setBossEventBossMove(ISetBossMoveExternal* isetBossMoveExternal, Point moveTo, int movingTime, bool isStartEvent);
	void setBossEventMusicChange(int stage);

	void beginEvent(bool isStartEvent);
};

#endif