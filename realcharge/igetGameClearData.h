#ifndef _IGETGAMECLEARDATA_
#define _IGETGAMECLEARDATA_

class IGetGameClearData{
public:
	virtual bool igetStageClearData(int difficulty, int mode) = 0;
	virtual bool igetStageEXClearData(int mode) = 0;
	virtual bool igetBossAttackClearData(int stageNum, int difficulty, int attackNum) = 0;
	virtual bool igetBossAttackClearDataDetail(int stageNum, int difficulty, int attackNum, int mode) = 0;
};

#endif