#include "bossEvent.h"

void BossEvent::startEvent(){
	switch (this->type)
	{
	case BET_TALK:
		this->isetSelifBox->isetSelifBox(this->igetPosition, this->diff, this->text, this->size);
		break;

	case BET_MOVE:
		this->isetBossMoveExternal->isetBossMoveExternal(this->diff, this->size.width);
		break;

	case BET_MUSICCHANGE:
		Music::playBossMusic(this->size.width);
		break;

	default:
		break;
	}
}

void BossEvent::skipEvent(){
	switch (this->type)
	{
	case BET_TALK:
		this->valid = false;
		break;

	case BET_MOVE:
		this->valid = false;
		break;

	case BET_MUSICCHANGE:
		Music::playBossMusic(this->size.width);
		break;

	default:
		break;
	}
}

void BossEvent::checkEndTrigger(){
	this->count++;

	switch (this->endTrigger)
	{
	case BEET_INPUTKEY:
		if (Input::getkeyCodeDownOnce_Explode(this->triggerKey) == 1){
			this->valid = false;
			this->isetSelifBox->isetRemoveSelifBoxAll();
		}
		break;

	case BEET_TIMER:
		if (this->count == this->triggerTime){
			this->valid = false;
			this->isetBossMoveExternal->isetBossMoveInternal();
		}
		break;

	case BEET_NOW:
		this->valid = false;
		break;

	default:
		break;
	}
}

BossEvent::BossEvent(ISetSelifBox* isetSelifBox, IGetPosition* igetPosition, Point diff, string text, Size size){
	this->count = 0;
	this->valid = true;
	this->endTrigger = BEET_INPUTKEY;
	this->type = BET_TALK;
	this->triggerKey = KeyCodeExplode_OK;
	this->isetSelifBox = isetSelifBox;
	this->igetPosition = igetPosition;
	this->diff = diff;
	this->text = text;
	this->size = size;
	//isetSelifBox->isetSelifBox(igetPosition, diff, text, size);
}

BossEvent::BossEvent(ISetBossMoveExternal* isetBossMoveExternal, Point moveTo, int movingTime){
	this->count = 0;
	this->valid = true;
	this->endTrigger = BEET_TIMER;
	this->type = BET_MOVE;
	this->triggerTime = movingTime;
	this->isetBossMoveExternal = isetBossMoveExternal;
	this->diff = moveTo;
	this->size.width = movingTime;
	//isetBossMoveExternal->isetBossMoveExternal(moveTo, movingTime);
}

BossEvent::BossEvent(int stage){
	this->count = 0;
	this->valid = true;
	this->endTrigger = BEET_NOW;
	this->type = BET_MUSICCHANGE;
	this->size.width = stage;
	//Music::playBossMusic(stage);
}