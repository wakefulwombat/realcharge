#ifndef _IGETENEMYINFOMATION_
#define _IGETENEMYINFOMATION_

#include "common.h"

class IGetEnemyInfomation{
public:
	virtual int igetEnemyNum()=0;//�L���ȓG�̑���
	virtual Point igetEnemyPosition(int enemyCSVIndex)=0;
	virtual Point igetEnemyPositionVectorIndex(int vectorIndex)=0;
};

#endif