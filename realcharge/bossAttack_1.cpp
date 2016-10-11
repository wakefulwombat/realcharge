#include "bossAttack_1.h"
#include "DxLib.h"

////BossAttack_1_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_1_1_Easy::BossAttack_1_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 400;
	this->limitTime = 800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_1_Easy::move(){
	this->count++;

	int t = (this->count % (50 + 300));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_1_Easy::attack(){
	int t = (this->count % (50 + 300));
	if (t % 50 != 0) return;

	double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	for (int way = 0; way < 3; way++){
		for (int line = 0; line < 6; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
				0.5 + 0.5*line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 2, 0.0);
		}
	}
}


BossAttack_1_1_Normal::BossAttack_1_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 400;
	this->limitTime = 800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_1_Normal::move(){
	this->count++;

	int t = (this->count % (50 + 300));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_1_Normal::attack(){
	int t = (this->count % (50 + 300));
	if (t % 50 != 0) return;

	double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	for (int way = 0; way < 5; way++){
		for (int line = 0; line < 8; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
				1.0 + 0.5*line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 4, 0.0);
		}
	}
}


BossAttack_1_1_Hard::BossAttack_1_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 700;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1200;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_1_Hard::move(){
	this->count++;

	int t = (this->count % (50 + 300));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_1_Hard::attack(){
	int t = (this->count % (50 + 300));
	if (t % 50 != 0) return;

	double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	for (int way = 0; way < 7; way++){
		for (int line = 0; line < 10; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
				1.0 + 0.5*line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 6, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_1_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_1_2_Easy::BossAttack_1_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 100;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "–À“­@";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_2_Easy::move(){
	this->count++;

	int t = (this->count % (100 + 100 + 100 + 200));
	if (t == 300){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if ((t >= 325) && (t <= 475)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 325, 150));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_2_Easy::attack(){
	int t = (this->count % (100 + 100 + 100 + 200));
	if (t % 2 != 0) return;

	if (t == 0){
		for (int i = 0; i < 4; i++){
			this->cp[i] = Point(GetRand(416) + 50, GetRand(130) + 50);
		}
	}
	else if (t < 100){
		Point pos = Point(this->cp[0].x + 2.0*(this->cp[1].x - this->cp[0].x)*t / 100 - (this->cp[1].x - this->cp[0].x)*t*t / 100 / 100, this->cp[0].y + 2.0*(this->cp[1].y - this->cp[0].y)*t / 100 - (this->cp[1].y - this->cp[0].y)*t*t / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * t / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * t / 50, 0.0);
	}
	else if (t < 200){
		Point pos = Point(this->cp[1].x + 2.0*(this->cp[2].x - this->cp[1].x)*(t - 100) / 100 - (this->cp[2].x - this->cp[1].x)*(t - 100)*(t - 100) / 100 / 100, this->cp[1].y + 2.0*(this->cp[2].y - this->cp[1].y)*(t - 100) / 100 - (this->cp[2].y - this->cp[1].y)*(t - 100)*(t - 100) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 100) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 100) / 50, 0.0);
	}
	else if (t < 300){
		Point pos = Point(this->cp[2].x + 2.0*(this->cp[3].x - this->cp[2].x)*(t - 200) / 100 - (this->cp[3].x - this->cp[2].x)*(t - 200)*(t - 200) / 100 / 100, this->cp[2].y + 2.0*(this->cp[3].y - this->cp[2].y)*(t - 200) / 100 - (this->cp[3].y - this->cp[2].y)*(t - 200)*(t - 200) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 200) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 200) / 50, 0.0);
	}
}


BossAttack_1_2_Normal::BossAttack_1_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 250;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1800;
	this->attackName = "–À“­@";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_2_Normal::move(){
	this->count++;

	int t = (this->count % (100 + 100 + 100 + 200));
	if (t == 300){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if ((t >= 325) && (t <= 475)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 325, 150));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_2_Normal::attack(){
	int t = (this->count % (100 + 100 + 100 + 200));
	if (t % 2 != 0) return;

	if (t == 0){
		for (int i = 0; i < 4; i++){
			this->cp[i] = Point(GetRand(416) + 50, GetRand(130) + 50);
		}
	}
	else if (t < 100){
		Point pos = Point(this->cp[0].x + 2.0*(this->cp[1].x - this->cp[0].x)*t / 100 - (this->cp[1].x - this->cp[0].x)*t*t / 100 / 100, this->cp[0].y + 2.0*(this->cp[1].y - this->cp[0].y)*t / 100 - (this->cp[1].y - this->cp[0].y)*t*t / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * t / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * t / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * t / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * t / 12.5, 0.0);
	}
	else if (t < 200){
		Point pos = Point(this->cp[1].x + 2.0*(this->cp[2].x - this->cp[1].x)*(t - 100) / 100 - (this->cp[2].x - this->cp[1].x)*(t - 100)*(t - 100) / 100 / 100, this->cp[1].y + 2.0*(this->cp[2].y - this->cp[1].y)*(t - 100) / 100 - (this->cp[2].y - this->cp[1].y)*(t - 100)*(t - 100) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * (t - 100) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 100) / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 100) / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * (t - 100) / 12.5, 0.0);
	}
	else if (t < 300){
		Point pos = Point(this->cp[2].x + 2.0*(this->cp[3].x - this->cp[2].x)*(t - 200) / 100 - (this->cp[3].x - this->cp[2].x)*(t - 200)*(t - 200) / 100 / 100, this->cp[2].y + 2.0*(this->cp[3].y - this->cp[2].y)*(t - 200) / 100 - (this->cp[3].y - this->cp[2].y)*(t - 200)*(t - 200) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * (t - 200) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 200) / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 200) / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * (t - 200) / 12.5, 0.0);
	}
}


BossAttack_1_2_Hard::BossAttack_1_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1800;
	this->attackName = "–¼“­@";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_2_Hard::move(){
	this->count++;

	int t = (this->count % (40 + 40 + 40 + 120));
	if (t == 120){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if ((t >= 135) && (t <= 225)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 135, 90));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_2_Hard::attack(){
	int t = (this->count % (100 + 100 + 100 + 200));
	if (t % 2 != 0) return;

	if (t == 0){
		for (int i = 0; i < 4; i++){
			this->cp[i] = Point(GetRand(416) + 50, GetRand(130) + 50);
		}
	}
	else if (t < 100){
		Point pos = Point(this->cp[0].x + 2.0*(this->cp[1].x - this->cp[0].x)*t / 100 - (this->cp[1].x - this->cp[0].x)*t*t / 100 / 100, this->cp[0].y + 2.0*(this->cp[1].y - this->cp[0].y)*t / 100 - (this->cp[1].y - this->cp[0].y)*t*t / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * t / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * t / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * t / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * t / 12.5, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.5, 0.0, M_PI * 2 * t / 6.25, 0.0);
	}
	else if (t < 200){
		Point pos = Point(this->cp[1].x + 2.0*(this->cp[2].x - this->cp[1].x)*(t - 100) / 100 - (this->cp[2].x - this->cp[1].x)*(t - 100)*(t - 100) / 100 / 100, this->cp[1].y + 2.0*(this->cp[2].y - this->cp[1].y)*(t - 100) / 100 - (this->cp[2].y - this->cp[1].y)*(t - 100)*(t - 100) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * (t - 100) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 100) / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 100) / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * (t - 100) / 12.5, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.5, 0.0, M_PI * 2 * (t - 100) / 6.25, 0.0);
	}
	else if (t < 300){
		Point pos = Point(this->cp[2].x + 2.0*(this->cp[3].x - this->cp[2].x)*(t - 200) / 100 - (this->cp[3].x - this->cp[2].x)*(t - 200)*(t - 200) / 100 / 100, this->cp[2].y + 2.0*(this->cp[3].y - this->cp[2].y)*(t - 200) / 100 - (this->cp[3].y - this->cp[2].y)*(t - 200)*(t - 200) / 100 / 100);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, M_PI * 2 * (t - 200) / 100, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI * 2 * (t - 200) / 50, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 2 * (t - 200) / 25, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 * (t - 200) / 12.5, 0.0);
		this->isetBullet->isetBossBullet(pos, Bul_Small, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.5, 0.0, M_PI * 2 * (t - 200) / 6.25, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_1_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_1_3_Easy::BossAttack_1_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 350;
	this->HP_Max_Stand = 350;
	this->HP_Max_Absorb = 450;
	this->limitTime = 800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_3_Easy::move(){
	this->count++;

	int t = (this->count % (50 + 300));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_3_Easy::attack(){
	int t = (this->count % (80 + 320));
	if (t % 80 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int way = 0; way < 3; way++){
			for (int line = 0; line < 3; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
					0.5 + line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 2, 0.0);
			}
		}
	}

	if (t % 40 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);

		if ((t % 80) % 2 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, angle + M_PI * 2 * way / 8, M_PI * 2 * 0.1 / 360, 100);

			}
		}
		else{
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, angle + M_PI * 2 * way / 8, -M_PI * 2 * 0.1 / 360, 100);

			}
		}
	}
}


BossAttack_1_3_Normal::BossAttack_1_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 450;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 550;
	this->limitTime = 800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_3_Normal::move(){
	this->count++;

	int t = (this->count % (80 + 320));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 80){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_3_Normal::attack(){
	int t = (this->count % (80 + 320));
	if (t % 80 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int way = 0; way < 5; way++){
			for (int line = 0; line < 4; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
					1.0 + 0.8*line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 4, 0.0);
			}
		}
	}

	if (t % 40 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);

		if ((t % 80) % 2 == 0){
			for (int way = 0; way < 10; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
						2.0 + line, 0.0, angle + M_PI * 2 * way / 10, M_PI * 2 * 0.2 / 360, 100);
				}
			}
		}
		else{
			for (int way = 0; way < 10; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
						2.0 + line, 0.0, angle + M_PI * 2 * way / 10, -M_PI * 2 * 0.2 / 360, 100);
				}
			}
		}
	}
}


BossAttack_1_3_Hard::BossAttack_1_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1700;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_3_Hard::move(){
	this->count++;

	int t = (this->count % (50 + 300));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_3_Hard::attack(){
	int t = (this->count % (50 + 300));
	if (t % 40 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int way = 0; way < 5; way++){
			for (int line = 0; line < 6; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition,
					1.0 + 0.8*line, 0.0, angle - M_PI * 80 / 360 + M_PI * 2 * way * 80 / 360 / 4, 0.0);
			}
		}
	}

	if (t % 20 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);

		if ((t % 40) % 2 == 0){
			for (int way = 0; way < 12; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
						2.0 + line, 0.0, angle + M_PI * 2 * way / 12, M_PI * 2 * 0.2 / 360, 100);
				}
			}
		}
		else{
			for (int way = 0; way < 12; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 5, this->isetBullet, this->igetPlayerPosition,
						2.0 + line, 0.0, angle + M_PI * 2 * way / 12, -M_PI * 2 * 0.2 / 360, 100);
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_1_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_1_4_Easy::BossAttack_1_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 700;
	this->limitTime = 1800;
	this->attackName = "”éŒ••‘ ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_4_Easy::move(){
	this->count++;
	int t = this->count % (60 + 240);

	if (t == 220){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(70, Point(80, 50), Point(436, 150));
	}
	if ((t > 220) && (t < 250)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 220), 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_4_Easy::attack(){
	int t = this->count % (60 + 240);

	if (t == 0){
		this->angle = 0.0;
	}
	else if (t < 60){
		if (t % 8 != 0) return;
		double a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).x);
		for (int line = 0; line < 2; line++){
			for (int way = 0; way < 4; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 4, 0.0);
			}
		}
		a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).x);
		for (int line = 0; line < 2; line++){
			for (int way = 0; way < 4; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 4, 0.0);
			}
		}
	}
	else if (t == 60){
		double a = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 2; line++){
			for (int way = 0; way < 4; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 2.0 + 0.8*line, 0.02,
					a + M_PI*2.0*way * 120 / 3 / 360 - M_PI*2.0 * 60 / 360, 0.0);
			}
		}
	}
	else if (t <= 180){
		if (t % 30 != 0) return;
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle + M_PI, 0.0);

		}
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle + M_PI, 0.0);
		}
	}
}


BossAttack_1_4_Normal::BossAttack_1_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 2000;
	this->attackName = "”éŒ••‘ ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_1_4_Normal::move(){
	this->count++;
	int t = this->count % (60 + 240);

	if (t == 220){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(70, Point(80, 50), Point(436, 150));
	}
	if ((t > 220) && (t < 250)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 220), 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_4_Normal::attack(){
	int t = this->count % (60 + 240);

	if (t == 0){
		this->angle = M_PI*2.0*(GetRand(20) - 10) / 360;
	}
	else if (t < 60){
		if (t % 6 != 0) return;
		double a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).x);
		for (int line = 0; line < 3; line++){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 8, 0.0);
			}
		}
		a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).x);
		for (int line = 0; line < 3; line++){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 8, 0.0);
			}
		}
	}
	else if (t == 60){
		double a = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 4; line++){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 2.0 + 0.6*line, 0.02,
					a + M_PI*2.0*way * 120 / 5 / 360 - M_PI*2.0 * 60 / 360, 0.0);
			}
		}
	}
	else if (t <= 180){
		if (t % 20 != 0) return;
		for (int line = 0; line < 3; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(angle), 50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle + M_PI, 0.0);

		}
		for (int line = 0; line < 3; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-50.0*cos(angle), -50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02+ 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-50.0*cos(angle), -50.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02 + 0.01*line,
				angle + M_PI, 0.0);
		}
	}
}


BossAttack_1_4_Hard::BossAttack_1_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2500;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 2000;
	this->attackName = "–‚Œ••‘ ";
	this->initialPosition = Point(258, 120);

	this->angle = 0.0;
}

void BossAttack_1_4_Hard::move(){
	this->count++;
	int t = this->count % (60 + 240);

	if (t == 220){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(70, Point(80, 50), Point(436, 150));
	}
	if ((t > 220) && (t < 250)){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 220), 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_1_4_Hard::attack(){
	int t = this->count % (60 + 240);

	if (t == 0){
		this->angle = M_PI*2.0*(GetRand(20) - 10) / 360;
	}
	else if (t < 60){
		if (t % 4 != 0) return;
		double a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle))).x);
		for (int line = 0; line < 3; line++){
			for (int way = 0; way < 10; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(4.5*t*cos(angle), 4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 10, 0.0);
			}
		}
		a = atan2(this->igetPlayerPosition->igetPosition().y - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).y, this->igetPlayerPosition->igetPosition().x - (this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle))).x);
		for (int line = 0; line < 3; line++){
			for (int way = 0; way < 10; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-4.5*t*cos(angle), -4.5*t*sin(angle)), Bul_Gun, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + line, 0.0,
					a + M_PI*2.0*way / 10, 0.0);
			}
		}
	}
	else if (t == 60){
		double a = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 6; line++){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 2.0 + 0.6*line, 0.02,
					a + M_PI*2.0*way * 120 / 7 / 360 - M_PI*2.0 * 60 / 360, 0.0);
			}
		}
	}
	else if (t <= 180){
		if (t % 15 != 0) return;
		for (int line = 0; line < 3; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(100.0*cos(angle), 100.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.03 + 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(100.0*cos(angle), 100.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.03 + 0.01*line,
				angle + M_PI, 0.0);

		}
		for (int line = 0; line < 3; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-100.0*cos(angle), -100.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.03 + 0.01*line,
				angle, 0.0);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(-100.0*cos(angle), -100.0*sin(angle)) + Point(4 * (t - 60)*cos(angle + M_PI / 2), 4 * (t - 60)*sin(angle + M_PI / 2)), Bul_Fuda, Bul_Purple, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.03 + 0.01*line,
				angle + M_PI, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
