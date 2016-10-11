#ifndef _BOSS_
#define _BOSS_

#include "charactor.h"
#include "barrage.h"
#include "bossAttack.h"
#include "IsetItem.h"
#include "IsetSelifBox.h"
#include "IsetBossMoveExternal.h"
#include "IsetBossInfo.h"
#include "IgetBossAttackInfo.h"
#include "IsetNumericalBar.h"
#include "IsetBossDamage.h"

class Boss : public Charactor, public ISetBossMoveExternal, public ISetBossInfo, public ISetBossDamage{
private:
	BossAttack* bossAttack;
	ISetItem* isetItem;
	IGetPosition* igetPlayerPosition;
	IGetBossAttackInfo* igetBossAttackInfo;

	Point moveFrom,moveTo;
	int moveTime;
	int id,charaChip;
	double HP;
	
	Point eventMoveFrom, eventMoveTo;
	int eventCount,eventMoveTime;

	bool isBossPractice;

	void adjustTransRad();
	void getDirectionFromTransRad();

public:
	Boss(int id, int chara_chip, Point initialPos, IGetBossAttackInfo* igetBossAttackInfo, bool isBossPractice = false);
	~Boss();

	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void externalUpdate();

	void initializeAttack();
	void beginAttack();

	void setInterface(ISetItem* isetItem, IGetPosition* igetPlayerPosition);

	int getID(){ return this->id; }
	double getHP(){ return this->HP; }
	CharactorStatus getStatus(){ return this->status; }

	void isetBossMoveExternal(Point moveTo, int movingTime) override;
	void isetBossMoveInternal() override;
	void isetBossInvalid() override;

	void isetPosition(Point pos) override { this->position = pos; }
	void isetTransRad(double trans_rad) override { this->trans_rad = trans_rad; }

	void isetBossDamage(double damage) override;

	void damaged(double damage);

	bool isTimeUp(){ return this->bossAttack->isTimeUp(); }
	bool isAlartTime(){ return this->bossAttack->isAlartTime(); }
};

#endif