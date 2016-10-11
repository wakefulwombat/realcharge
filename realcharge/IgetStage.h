#ifndef _IGETSTAGE_
#define _IGETSTAGE_

class IGetStage{
public:
	virtual int igetStage() = 0;
	virtual int igetDifficulty() = 0;
	virtual void isetPauseInvalid() = 0;
};

#endif