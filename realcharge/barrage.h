#ifndef _BARRAGE_
#define _BARRAGE_

#include "mover.h"
#include "bullet.h"
#include "IsetBullet.h"
#include "IgetPosition.h"

#include "isetEnemyLazer.h"

struct StaticBarrageData{
	int CSVID;
	int barragePattern;
	int movePattern;
	int disappearTime_min;
	int smallGroupBulletNum,largeGroupBulletNum,totalGroupNum;
	int smallGroupWaitingTime,largeGroupWaitingTime;
	double trans_vel,trans_rad,rotate_vel,rotate_rad;
	double param1,param2,param3;
	StaticBulletData staticBulletData;
};

class Barrage : public Mover{
private:
	StaticBarrageData* staticBarrageData;
	int small_group_num_c,small_group_time_c;
	int large_group_num_c,large_group_time_c;
	int total_group_num_c;
	double tmp_shot_rad;
	ISetBullet* isetBullet;
	IGetPosition* igetPlayerPosition;
	IGetPosition* igetEnemyPosition;

	ISetEnemyLazer* isetEnemyLazer;

	int enemyCSVIndex;
	int barrageCSVID;

	void move();
	void shotBullet();
public:
	Barrage(StaticBarrageData* staticBarrageData, int enemyCSVIndex, int barrageCSVID, Point position, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, IGetPosition* igetEnemyPosition);
	Barrage(StaticBarrageData* staticBarrageData, int enemyCSVIndex, int barrageCSVID, Point position, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, IGetPosition* igetEnemyPosition, ISetEnemyLazer* isetEnemyLazer);

	void initialize() override;
	void update() override;
	void draw() override {};
	void finalize() override;

	void setInvalidated(){this->validated=false;};
	int getEnemyCSVIndex(){return this->enemyCSVIndex;};
	int getBarrageCSVID(){return this->barrageCSVID;};
};

#endif