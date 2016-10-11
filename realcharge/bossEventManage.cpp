#include "bossEventManage.h"

BossEventManage::BossEventManage(IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetSelifBox* isetSelifBox, IGetStage* igetStage){
	this->startEvent.clear();
	this->endEvent.clear();
	this->staticStartBossEventData.clear();
	this->staticEndBossEventData.clear();
	this->eventNumCount = 0;

	this->igetBoss = igetBoss;
	this->igetPlayerPosition = igetPlayerPosition;
	this->isetSelifBox = isetSelifBox;
	this->igetStage = igetStage;
}

void BossEventManage::clearAllEvent(){
	this->startEvent.clear();
	this->endEvent.clear();
	this->eventNumCount = 0;
}

void BossEventManage::clearAllStaticEventData(){
	this->staticStartBossEventData.clear();
	this->staticEndBossEventData.clear();
}

bool BossEventManage::isAllEventEnd(bool isStartEvent){
	if (isStartEvent == true){
		if (this->startEvent.size() == 0) return true;
		else{
			if (this->eventNumCount >= this->startEvent.size()) return true;
		}
		return false;
	}
	else{
		if (this->endEvent.size() == 0) return true;
		else{
			if (this->eventNumCount >= this->endEvent.size()) return true;
		}
		return false;
	}
}

void BossEventManage::update(bool isStartEvent){
	if (isStartEvent == true){
		if (this->eventNumCount >= this->startEvent.size()) return;

		if (this->startEvent[this->eventNumCount]->getValid() == false){
			this->eventNumCount++;
			if (this->eventNumCount == this->startEvent.size()) return;
			this->startEvent[this->eventNumCount]->startEvent();
		}

		this->startEvent[this->eventNumCount]->checkEndTrigger();
	}
	else{
		if(this->eventNumCount >= this->endEvent.size()) return;

		if (this->endEvent[this->eventNumCount]->getValid() == false){
			this->eventNumCount++;
			if (this->eventNumCount == this->endEvent.size()) return;
			this->endEvent[this->eventNumCount]->startEvent();
		}

		this->endEvent[this->eventNumCount]->checkEndTrigger();
	}

	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) != 0){
		if (isStartEvent == true){
			for (int i = this->eventNumCount; i < this->startEvent.size(); i++){
				this->startEvent[i]->skipEvent();
			}
			this->eventNumCount = this->startEvent.size();
		}
		else{
			for (int i = this->eventNumCount; i < this->endEvent.size(); i++){
				this->endEvent[i]->skipEvent();
			}
			this->eventNumCount = this->endEvent.size();
		}
		this->isetSelifBox->isetRemoveSelifBoxAll();
	}
}

int BossEventManage::getHowManyStaticEventExist(bool isStartEvent){
	if (isStartEvent == true){
		return this->staticStartBossEventData.size();
	}
	else{
		return this->staticEndBossEventData.size();
	}
}

StaticBossEventData* BossEventManage::getStaticBossEventData(int num, bool isStartEvent){
	if (isStartEvent == true){
		return &(this->staticStartBossEventData[num]);
	}
	else {
		return &(this->staticEndBossEventData[num]);
	}
}

void BossEventManage::setStaticBossEventData(StaticBossEventData dat, bool isStartEvent){
	if (isStartEvent == true){
		this->staticStartBossEventData.push_back(dat);
	}
	else{
		this->staticEndBossEventData.push_back(dat);
	}
}

void BossEventManage::setBossEventBossTalk(ISetSelifBox* isetSelifBox, IGetPosition* igetPosition, Point diff, string text, Size size, bool isStartEvent){
	if (isStartEvent == true) this->startEvent.push_back(new BossEvent(isetSelifBox, igetPosition, diff, text, size));
	else this->endEvent.push_back(new BossEvent(isetSelifBox, igetPosition, diff, text, size));
}

void BossEventManage::setBossEventBossMove(ISetBossMoveExternal* isetBossMoveExternal, Point moveTo, int movingTime, bool isStartEvent){
	if(isStartEvent==true) this->startEvent.push_back(new BossEvent(isetBossMoveExternal, moveTo, movingTime));
	else this->endEvent.push_back(new BossEvent(isetBossMoveExternal, moveTo, movingTime));
}

void BossEventManage::setBossEventMusicChange(int stage){
	this->startEvent.push_back(new BossEvent(stage));
}

int BossEventManage::getHowManyBossActorInEvent(bool isStartEvent){
	if (isStartEvent == true){
		switch (this->igetStage->igetStage()){
		case 1:return 1;
		case 2:return 1;
		case 3:return 1;
		case 4:return 1;
		case 5:return 1;
		case 6:return 1;
		case 7:return 1;
		}
	}
	else{
		switch (this->igetStage->igetStage()){
		case 1:return 1;
		case 2:return 1;
		case 3:return 1;
		case 4:return 1;
		case 5:return 1;
		case 6:return 1;
		case 7:return 1;
		}
	}
	return -1;
}

int BossEventManage::getBossActorCharaChip(int id, bool isStartEvent){
	if (isStartEvent == true){
		switch (this->igetStage->igetStage()){
		case 1:
			switch (id){
			case 0:return 23;
			}
			break;

		case 2:
			switch (id){
			case 0:return 7;
			}
			break;

		case 3:
			switch (id){
			case 0:return 4;
			}
			break;

		case 4:
			switch (id){
			case 0:return 11;
			}
			break;

		case 5:
			switch (id){
			case 0:return 21;
			}
			break;

		case 6:
			switch (id){
			case 0:return 9;
			}
			break;

		case 7:
			switch (id){
			case 0:return 24;
			}
			break;
		}
	}
	else{
		switch (this->igetStage->igetStage()){
		case 1:
			switch (id){
			case 0:return 23;
			}
			break;

		case 2:
			switch (id){
			case 0:return 7;
			}
			break;

		case 3:
			switch (id){
			case 0:return 4;
			}
			break;

		case 4:
			switch (id){
			case 0:return 11;
			}
			break;

		case 5:
			switch (id){
			case 0:return 21;
			}
			break;

		case 6:
			switch (id){
			case 0:return 9;
			}
			break;

		case 7:
			switch (id){
			case 0:return 24;
			}
			break;
		}
	}
	return -1;
}

Point BossEventManage::getBossActorInitialPosition(int id, bool isStartEvent){
	if (isStartEvent == true){
		switch (this->igetStage->igetStage()){
		case 1:
			switch (id){
			case 0:return Point(-40,-40);
			}
			break;

		case 2:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 3:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 4:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 5:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 6:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 7:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;
		}
	}
	else{
		switch (this->igetStage->igetStage()){
		case 1:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 2:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 3:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 4:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 5:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 6:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;

		case 7:
			switch (id){
			case 0:return Point(-40, -40);
			}
			break;
		}
	}
	return Point(-40,-40);
}

void BossEventManage::beginEvent(bool isStartEvent){
	if (isStartEvent == true){
		this->startEvent[0]->startEvent();
		this->eventNumCount = 0;
	}
	else{
		this->endEvent[0]->startEvent();
		this->eventNumCount = 0;
	}
}