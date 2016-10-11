#ifndef _ISETDIFFICULTY_
#define _ISETDIFFICULTY_

class ISetDifficulty{
public:
	virtual void isetDifficulty(int difficulty) = 0;
	virtual void isetStageNum(int stageNum) = 0;
	virtual void isetModeEX(int mode) = 0;
	virtual void isetRetryFromBossBattle(bool flag) = 0;
	virtual void isetBossAttackNum(int attackNum) = 0;
};

#endif