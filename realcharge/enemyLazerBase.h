#ifndef _ENEMYLAZERBASE_
#define _ENEMYLAZERBASE_

#include "mover.h"
#include <vector>
#include "shockLazerDiv.h"
#include "bulletBase.h"
#include "isetStandShockLazerEX.h"
using namespace std;

class EnemyLazerBase : public Mover{
protected:
	int divCount;
	const int maxDivNum;//divÇÃêî
	vector<ShockLazerDiv> lazerDiv;
	int disappTime_min;
	BulletColor color;

public:
	EnemyLazerBase(int maxDivNum) : maxDivNum(maxDivNum){ this->size = Size(18, 28); }
	void setInvalid(){ this->validated = false; }
	int getLazerDivSize(){ return this->lazerDiv.size(); }
	Point getLazerDivPosition(int vectorIndex){ return this->lazerDiv[vectorIndex].center; }
	bool getLazerDivValid(int vectorIndex){ return this->lazerDiv[vectorIndex].validated; }
	void setLazerDivInvalid(int vectorIndex){ this->lazerDiv[vectorIndex].validated = false; }
	void setLazerDivIsInColding(int vectorIndex, bool isInColding){ this->lazerDiv[vectorIndex].isInColding = isInColding; }

	virtual void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX){};
	virtual void setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX, Point bossPos){};

	virtual ~EnemyLazerBase(){};
};

#endif