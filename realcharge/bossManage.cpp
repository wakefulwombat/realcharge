#include "bossManage.h"
#include "sound.h"
#include "DxLib.h"

BossManage::BossManage(ISetSelifBox* isetSelifBox, ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, ISetNextStage* isetNextStage, ISetBurnEffect* isetBurnEffect, int playerMode){
	this->boss.clear();

	this->isetSelifBox = isetSelifBox;
	this->isetTextEffect = isetTextEffect;
	this->isetBullet = isetBullet;
	this->isetBulletInvalid = isetBulletInvalid;
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetStage = igetStage;
	this->isetNextStage = isetNextStage;
	this->isetBurnEffect = isetBurnEffect;

	this->bossEventManage = new BossEventManage(this,igetPlayerPosition,isetSelifBox,igetStage);
	this->bossAttackManage = new BossAttackManage(this->igetStage, this, this->igetPlayerPosition, this->isetBullet, 0);

	this->status = BMStatus_None;
	this->isBossPractice = false;

	this->count = 0;
}

BossManage::BossManage(ISetSelifBox* isetSelifBox, ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, ISetNextStage* isetNextStage, ISetBurnEffect* isetBurnEffect, int playerMode){
	this->boss.clear();

	this->isetSelifBox = isetSelifBox;
	this->isetTextEffect = isetTextEffect;
	this->isetBullet = isetBullet;
	this->isetLazer = isetLazer;
	this->isetBulletInvalid = isetBulletInvalid;
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetStage = igetStage;
	this->isetNextStage = isetNextStage;
	this->isetBurnEffect = isetBurnEffect;

	this->bossEventManage = new BossEventManage(this, igetPlayerPosition, isetSelifBox, igetStage);
	this->bossAttackManage = new BossAttackManage(this->igetStage, this, this->igetPlayerPosition, this->isetBullet, this->isetLazer, playerMode);

	this->status = BMStatus_None;
	this->isBossPractice = false;

	this->count = 0;
}

BossManage::BossManage(ISetTextEffect* isetTextEffect, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, ISetBulletInvalid* isetBulletInvalid, ISetItem* isetItem, IGetPosition* igetPlayerPosition, IGetStage* igetStage, int stageNum, int difficulty, int attackNum, ISetBossPracticeBossDeadFlag* isetBossPracticeBossDeadFlag, ISetBurnEffect* isetBurnEffect, int playerMode){
	this->boss.clear();

	this->isetTextEffect = isetTextEffect;
	this->isetBullet = isetBullet;
	this->isetLazer = isetLazer;
	this->isetBulletInvalid = isetBulletInvalid;
	this->isetItem = isetItem;
	this->igetPlayerPosition = igetPlayerPosition;
	this->isetBurnEffect = isetBurnEffect;

	this->isetBossPracticeBossDeadFlag = isetBossPracticeBossDeadFlag;

	this->bossAttackManage = new BossAttackManage(igetStage, this, this->igetPlayerPosition, this->isetBullet, this->isetLazer, playerMode);

	this->status = BMStatus_Fighting;
	this->isBossPractice = true;

	this->boss.push_back(new Boss(0, 17, Point(-40, -40), this->bossAttackManage, true));
	this->isBossPractice = true;
	this->bossAttackManage->initAttackNumCount(attackNum);
	for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
		(*it)->initializeAttack();
		(*it)->beginAttack();
		(*it)->setInterface(this->isetItem, this->igetPlayerPosition);
	}

	this->count = 0;
}

void BossManage::initialize(){
	for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
		(*it)->initialize();
	}

	if (this->isBossPractice == false){
		this->status = BMStatus_None;
	}
	else{
		this->status = BMStatus_Fighting;
	}
	this->count = 0;
}

void BossManage::update(){
	switch (this->status){
	case BMStatus_OpeningEvent:
		this->bossEventManage->update(true);
		if (this->bossEventManage->isAllEventEnd(true) == true){
			this->status = BMStatus_Fighting;
			this->bossAttackManage->initAttackNumCount();
			for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
				(*it)->initializeAttack();
				(*it)->beginAttack();
				(*it)->setInterface(this->isetItem, this->igetPlayerPosition);
			}
		}

		for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
			(*it)->externalUpdate();
		}
		break;

	case BMStatus_Fighting:
		if (this->isBossPractice == false){
			if ((this->boss[0]->getHP() < 0) && (this->boss[0]->getStatus() == ChStatus_Normal)){
				this->isetTextEffect->isetTextEffect(TXT_BARRAGE_BREAK);
				Sound::playSound(Sound_bossat_clear);
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 2.0, this->boss[0]->getPosition(), false);
				this->bossAttackManage->setNextAttack();
				this->isetBulletInvalid->isetBulletInvalidAll(this->boss[0]->getPosition(), 60);
				if (this->bossAttackManage->isAllAttackOfStageEnd() == true){
					this->status = BMStatus_EndingEvent;
					this->setBeginBossEndEvent();
					this->isetItem->isetItem(this->boss[0]->getPosition(), Item_White, Item_Large, this->igetPlayerPosition);
				}
				else{
					for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
						this->isetItem->isetItem((*it)->getPosition(), Item_White, Item_Small, this->igetPlayerPosition);
						(*it)->initializeAttack();
						(*it)->beginAttack();
					}
				}
			}
			if (this->boss[0]->isTimeUp() == true){
				this->isetTextEffect->isetTextEffect(TXT_FAILURE);
				Sound::playSound(Sound_bossat_fail);
				this->bossAttackManage->setNextAttack();
				this->isetBulletInvalid->isetBulletInvalidAll(this->boss[0]->getPosition(), 100);
				if (this->bossAttackManage->isAllAttackOfStageEnd() == true){
					this->status = BMStatus_EndingEvent;
					this->setBeginBossEndEvent();
				}
				else{
					for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
						(*it)->initializeAttack();
						(*it)->beginAttack();
						this->isetItem->isetItem((*it)->getPosition(), Item_Red, Item_Large, this->igetPlayerPosition);
					}
				}
			}
			if (this->boss[0]->isAlartTime() == true) Sound::playSound(Sound_TimeAlart);
		}
		else{//BossPractice
			if ((this->boss[0]->getHP() < 0) && (this->boss[0]->getStatus() == ChStatus_Normal)){
				this->isetTextEffect->isetTextEffect(TXT_STAGE_CLEAR);
				Sound::playSound(Sound_bossat_clear);
				this->isetBulletInvalid->isetBulletInvalidAll(this->boss[0]->getPosition(), 60);
				this->isetBurnEffect->isetBurnEffect((BurnEffectColor)GetRand(5), 2.0, this->boss[0]->getPosition(), false);
				this->isetBossPracticeBossDeadFlag->isetBossPracticeBossDeadFlag();
			}
		}

		for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
			(*it)->update();
		}

		break;

	case BMStatus_EndingEvent:
		this->bossEventManage->update(false);
		if (this->bossEventManage->isAllEventEnd(false) == true){
			this->status = BMStatus_End;
			this->isetTextEffect->isetTextEffect(TXT_STAGE_CLEAR);
		}

		for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
			(*it)->externalUpdate();
		}
		break;

	case BMStatus_End:
		if (this->count < 200) {
			this->count++;
			break;
		}

		for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end();){
			delete *it;
			it = this->boss.erase(it);
		}
		this->bossAttackManage->initAttackNumCount();
		this->bossEventManage->clearAllEvent();
		this->bossEventManage->clearAllStaticEventData();

		this->isetNextStage->isetNextStage();
		break;

	case BMStatus_None:
		
		break;
	}
}

void BossManage::draw(){
	if (this->status == BMStatus_None) return;

	for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
		(*it)->draw();
	}
}

void BossManage::finalize(){
	for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); ++it){
		(*it)->finalize();
	}
}

void BossManage::setStaticBossEventData(StaticBossEventData dat, bool isStartEvent){
	this->bossEventManage->setStaticBossEventData(dat,isStartEvent);
}

void BossManage::isetBeginBossStartEvent(){
	this->status = BMStatus_OpeningEvent;
	for (int i = 0; i < this->bossEventManage->getHowManyBossActorInEvent(true); i++){
		this->boss.push_back(new Boss(i, this->bossEventManage->getBossActorCharaChip(i, true), this->bossEventManage->getBossActorInitialPosition(i, true),this->bossAttackManage));
	}
	for (int i = 0; i < this->bossEventManage->getHowManyStaticEventExist(true); i++){
		StaticBossEventData* sbed = this->bossEventManage->getStaticBossEventData(i, true);
		if (sbed->eventType == BET_TALK){
			if (sbed->isBossEvent == true){
				this->bossEventManage->setBossEventBossTalk(this->isetSelifBox, this->boss[sbed->bossID], sbed->boxDiff, sbed->selif, sbed->boxSize, true);
			}
			else{
				this->bossEventManage->setBossEventBossTalk(this->isetSelifBox, this->igetPlayerPosition, sbed->boxDiff, sbed->selif, sbed->boxSize, true);
			}
		}
		else if (sbed->eventType == BET_MOVE){
			this->bossEventManage->setBossEventBossMove(this->boss[sbed->bossID], sbed->boxDiff, sbed->boxSize.width, true);
		}
		else if(sbed->eventType==BET_MUSICCHANGE){
			this->bossEventManage->setBossEventMusicChange(this->igetStage->igetStage());
		}
		else{}
	}
	this->bossEventManage->beginEvent(true);
}

void BossManage::setBeginBossEndEvent(){
	for (int i = (int)this->boss.size() - 1; i < this->bossEventManage->getHowManyBossActorInEvent(false); i++){
		this->boss.push_back(new Boss(i, this->bossEventManage->getBossActorCharaChip(i, false), this->bossEventManage->getBossActorInitialPosition(i, false),this->bossAttackManage));
	}
	for (int i = 0; i < this->bossEventManage->getHowManyStaticEventExist(false); i++){
		StaticBossEventData* sbed = this->bossEventManage->getStaticBossEventData(i, false);
		if (sbed->eventType == BET_TALK){
			if (sbed->isBossEvent == true){
				this->bossEventManage->setBossEventBossTalk(this->isetSelifBox, this->boss[sbed->bossID], sbed->boxDiff, sbed->selif, sbed->boxSize, false);
			}
			else{
				this->bossEventManage->setBossEventBossTalk(this->isetSelifBox, this->igetPlayerPosition, sbed->boxDiff, sbed->selif, sbed->boxSize, false);
			}
		}
		else if (sbed->eventType == BET_MOVE){
			this->bossEventManage->setBossEventBossMove(this->boss[sbed->bossID], sbed->boxDiff, sbed->boxSize.width, false);
		}
		else{
			this->bossEventManage->setBossEventMusicChange(this->igetStage->igetStage());
		}
	}
	this->bossEventManage->beginEvent(false);
}

int BossManage::igetBossSize(){
	return this->boss.size();
}

Boss* BossManage::igetBoss(int vectorIndex){
	return this->boss[vectorIndex];
}

bool BossManage::igetBossEventNow(){
	return ((this->status == BMStatus_OpeningEvent) || (this->status == BMStatus_EndingEvent));
}

bool BossManage::igetBossFightingNow(){
	return (this->status == BMStatus_Fighting);
}

void BossManage::clearAll(){
	for (vector<Boss*>::iterator it = this->boss.begin(); it != this->boss.end(); it++){
		delete (*it);
	}
	this->boss.clear();

	this->bossEventManage->clearAllEvent();
	this->bossEventManage->clearAllStaticEventData();
}

bool BossManage::isBossAttackingNow(){
	if (this->status != BMStatus_Fighting) return false;
	if (this->boss[0]->getStatus() != ChStatus_Normal) return false;

	return true;
}

BossManage::~BossManage(){
	if (this->isBossPractice == false) delete this->bossEventManage;
}