#ifndef _BARRAGEMANAGE_
#define _BARRAGEMANAGE_

#include "taskBase.h"
#include "barrage.h"
#include "IsetBarrage.h"
#include "IsetBullet.h"
#include "IgetPosition.h"

#include "isetEnemyLazer.h"

#include <vector>
using namespace std;

class BarrageManage : public TaskBase,public ISetBarrage{
private:
	bool isExtra;

	vector<Barrage*> barrage;
	vector<StaticBarrageData> staticBarrageData;
	ISetBullet* isetBullet;
	IGetPosition* igetPlayerPosition;

	ISetEnemyLazer* isetEnemyLazer;
public:
	BarrageManage(ISetBullet* isetBullet, IGetPosition* igetPlayerPosition);
	BarrageManage(ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, ISetEnemyLazer* isetEnemyLazer);
	void initialize() override;
	void update() override;
	void draw() override {};
	void finalize() override;

	void clearBarrageDataList();

	void isetBarrage(int barrageCSVID,int enemyCSVIndex,Point position,IGetPosition* igetEnemyPosition) override;
	void isetBarrageInvalidated(int EnemyCSVIndex) override;

	void setStaticBarrageData(StaticBarrageData staticBarrageData);
	void setBarrageInvalidated(int CSVID);
};

#endif