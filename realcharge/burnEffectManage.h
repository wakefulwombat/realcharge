#ifndef _BURNEFFECTMANAGE_
#define _BURNEFFECTMANAGE_

#include "taskBase.h"
#include "burnEffect.h"
#include "IsetBurnEffect.h"
#include <vector>
using namespace std;

class BurnEffectManage : public TaskBase,public ISetBurnEffect{
private:
	vector<BurnEffect*> burnEffect;
	int validCount;
	bool isCounting;
	const int difficulty;

public:
	BurnEffectManage(int difficulty);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getBurnEffectVectorSizeMax();
	Point getBurnEffectPosition(int vectorIndex);
	double getBurnEffectExpand(int vectorIndex);
	Size getBurnEffectSize(int vectorIndex);
	int getBurnEffectCount(int vectorIndex);

	void isetBurnEffect(BurnEffectColor color, double expand, Point position, bool isFromEnemyOrBullet) override;
};

#endif