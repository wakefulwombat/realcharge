#ifndef _PLAYERBULLETMANAGEREX_
#define _PLAYERBULLETMANAGEREX_

#include "taskBase.h"
#include "playerBulletEX.h"
#include "isetPlayerBulletEX.h"
#include <vector>
using namespace std;

class PlayerBulletManagerEX : public TaskBase, public ISetPlayerBulletEX{
private:
	vector<PlayerBulletEX*> bullet;

public:
	PlayerBulletManagerEX();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getBulletSize(){ return this->bullet.size();}
	Point getPosition(int vectorIndex){ return this->bullet[vectorIndex]->getPosition(); }
	bool getValid(int vectorIndex){ return this->bullet[vectorIndex]->getValidate(); }
	void setInvalid(int vectorIndex){ this->bullet[vectorIndex]->setInvalid(); }
	double getAttackPower(int vectorIndex){ return this->bullet[vectorIndex]->getAttackPower(); }

	void isetPlayerBulletEX(Point pos, BulletKind kind, BulletColor color, int movePattern, double attackPower, double trans_vel0, double trans_acc, double trans_rad0, int disappTime_min = 0) override;
};

#endif