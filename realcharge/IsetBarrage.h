#ifndef _ISETBARRAGE_
#define _ISETBARRAGE_

#include "barrage.h"
#include "IgetPlayerInfomation.h"
#include "IgetEnemyInfomation.h"
#include "IgetPosition.h"
#include "IsetBullet.h"

class ISetBarrage{
public:
	virtual void isetBarrage(int barrageCSVID,int enemyCSVIndex,Point position,IGetPosition* igetEnemyPosition)=0;
	virtual void isetBarrageInvalidated(int enemyCSVIndex)=0;
};

#endif