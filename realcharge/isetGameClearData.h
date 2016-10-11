#ifndef _ISETGAMECLEARDATA_
#define _ISETGAMECLEARDATA_

class ISetGameClearData{
public:
	virtual void isetStageClearData(int difficulty, int mode) = 0;
	virtual void isetStageEXClearData(int mode) = 0;
	virtual void isetBossAttackClearData(int stageNum, int difficulty, int attackNum, int mode) = 0;
	virtual void isetNoContinueFlag(bool flag) = 0;
	virtual bool igetNoContinueFlag() = 0;
};

#endif