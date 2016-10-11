#include "bossAttack.h"
#include "DxLib.h"

BossAttack::BossAttack(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode){
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetBossPosition = igetBossPosition;
	this->isetBullet = isetBullet;

	this->mode = mode;

	this->count = -1;
}

BossAttack::BossAttack(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, int mode){
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetBossPosition = igetBossPosition;
	this->isetBullet = isetBullet;
	this->isetLazer = isetLazer;

	this->mode = mode;
	this->count = -1;
}

Point BossAttack::getCircleDistanceMovePosition(double r, Point validSquareLeftUp, Point validSquareRightDown){
	Point pos;
	while (1){
		int deg = GetRand(360);
		pos = Point(this->igetBossPosition->igetPosition().x + r*cos(M_PI*deg / 180), this->igetBossPosition->igetPosition().y + r*sin(M_PI*deg / 180));
		if (pos.x < validSquareLeftUp.x)continue;
		if (pos.x > validSquareRightDown.x)continue;
		if (pos.y < validSquareLeftUp.y)continue;
		if (pos.y > validSquareRightDown.y)continue;

		break;
	}
	return pos;
}

Point BossAttack::getSquareRandomMovePosition(Point validSquareLeftUp, Point validSquareRightDown){
	return Point(1.0*GetRand((int)validSquareRightDown.x - (int)validSquareLeftUp.x) + (int)validSquareLeftUp.x, 1.0*GetRand((int)validSquareRightDown.y - (int)validSquareLeftUp.y) + (int)validSquareLeftUp.y);
}

Point BossAttack::getAccelMovePoint(Point from, Point to, int t, int t_max){
	if (t < 0) return from;
	if (t > t_max) return to;
	return Point(1.0*from.x + 2.0*(to.x - from.x)*t / t_max - 1.0*(to.x - from.x)*t*t / t_max / t_max, 1.0*from.y + 2.0*(to.y - from.y)*t / t_max - 1.0*(to.y - from.y)*t*t / t_max / t_max);
}

int BossAttack::getHPMax(){
	if (this->mode == 0) return this->HP_Max_Explode;
	else if (this->mode == 1) return this->HP_Max_Stand;
	else return this->HP_Max_Absorb;
}