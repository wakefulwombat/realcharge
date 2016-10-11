#ifndef _LAZER_
#define _LAZER_

#include "mover.h"
#include "bullet.h"
#include "lazerDiv.h"
#include <vector>
using namespace std;

class Lazer : public Mover{
private:
	StaticBulletData* bulletData;
	double trans_acc,rotate_acc;
	int divNum;
	vector<	LazerDiv> lazerDiv;
public:
	Lazer(StaticBulletData* bulletData,Point position,double trans_vel0,double trans_acc0,double trans_rad0,double rotate_vel0,double rotate_acc0,double rotate_rad0);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif