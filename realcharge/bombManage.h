#ifndef _BOMBMANAGE_
#define _BOMBMANAGE_

#include "bomb.h"
#include "IsetBomb.h"
#include "taskBase.h"
#include <vector>
using namespace std;

class BombManage : public TaskBase,public ISetBomb{
private:
	vector<Bomb*> bomb;
public:
	BombManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getBombVectorSizeMax();
	Point getPosition(int vectorIndex);
	Size getSize(int vectorIndex);
	void setInvalid(int vectorIndex);
	bool getValid(int vectorIndex);

	void isetBomb(Point position,double trans_rad,bool isMove) override;
};

#endif