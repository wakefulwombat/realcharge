#ifndef _ISETENEMYDAMAGE_
#define _ISETENEMYDAMAGE_

class ISetEnemyDamage{
public:
	virtual void isetEnemyDamage(int damage, bool isBurnEffect, double expand) = 0;
};

#endif