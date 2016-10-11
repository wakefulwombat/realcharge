#include "bossAttack_6.h"
#include "DxLib.h"

////BossAttack_6_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_1_Easy::BossAttack_6_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 1600;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_1_Easy::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_1_Easy::attack(){
	int t = this->count % 15;

	if (t != 0) return;

	for (int i = 0; i < 10; i++){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
	}
}

BossAttack_6_1_Normal::BossAttack_6_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 4000;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_1_Normal::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_1_Normal::attack(){
	int t = this->count % 10;

	if (t != 0) return;

	for (int i = 0; i < 14; i++){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.5 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
	}
}

BossAttack_6_1_Hard::BossAttack_6_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 6000;
	this->HP_Max_Stand = 2000;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_1_Hard::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_1_Hard::attack(){
	int t = this->count % 8;

	if (t != 0) return;

	for (int i = 0; i < 20; i++){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260), 50.0*sin(M_PI*this->count / 260)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.3*i, 0.0, M_PI*this->count / 260 + M_PI / 2, 0.0);
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*this->count / 260 + M_PI), 50.0*sin(M_PI*this->count / 260 + M_PI)), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.3*i, 0.0, M_PI*this->count / 260 - M_PI / 2, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_2_Easy::BossAttack_6_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 2400;
	this->attackName = "ミルキーウェイパレード";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_2_Easy::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_2_Easy::attack(){
	if (this->count % 120 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_SmallStar, Bul_Red, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 4, 10.0, 20, 3.0);
		}
	}

	if (this->count % 40 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 70.0);
		for (int i = 0; i < 10; i++){
			this->isetBullet->isetBossBullet(Point(70.0, 100.0), Bul_Gun, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 1.2, -0.02, angle + M_PI*i / 5, 0.0, 100);
		}
	}
	if (this->count % 60 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 446.0);
		for (int i = 0; i < 3; i++){
			this->isetBullet->isetBossBullet(Point(446.0, 100.0), Bul_Oval, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, angle + M_PI*i / 3 - M_PI / 3, 0.0);
		}
	}
	if (this->count % 240 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 50.0, this->igetPlayerPosition->igetPosition().x - 258.0);
		for (int way = 0; way < 5; way++){
			double dir = 2.0*GetRand(1) - 1.0;
			for (int i = 0; i < 6; i++){
				this->isetBullet->isetBossBullet(Point(258.0, 50.0) + Point(30.0*cos(M_PI*i / 3), 30.0*sin(M_PI*i / 3)), Bul_Middle, Bul_Green, 57, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*way / 6 - M_PI / 3, M_PI * dir / 240, 20, 30.0, M_PI*i / 3);
			}
		}
	}
	if (this->count % 30 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_LargeStar, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 2 + M_PI*GetRand(30) / 180 - M_PI / 12, 0.0);
	}
}

BossAttack_6_2_Normal::BossAttack_6_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 2400;
	this->attackName = "ミルキーウェイパレード";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_2_Normal::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_2_Normal::attack(){
	if (this->count % 80 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 10; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_SmallStar, Bul_Red, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 5, 10.0, 20, 10.0);
		}
	}

	if (this->count % 40 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 70.0);
		for (int i = 0; i < 16; i++){
			this->isetBullet->isetBossBullet(Point(70.0, 100.0), Bul_Gun, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 1.8, -0.04, angle + M_PI*i / 8, 0.0, 80);
		}
	}
	if (this->count % 60 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 446.0);
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(Point(446.0, 100.0), Bul_Oval, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, angle + M_PI*i / 8 - M_PI / 4, 0.0);
		}
	}
	if (this->count % 180 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 50.0, this->igetPlayerPosition->igetPosition().x - 258.0);
		for (int way = 0; way < 5; way++){
			double dir = 2.0*GetRand(1) - 1.0;
			for (int i = 0; i < 6; i++){
				this->isetBullet->isetBossBullet(Point(258.0, 50.0) + Point(30.0*cos(M_PI*i / 3), 30.0*sin(M_PI*i / 3)), Bul_Middle, Bul_Green, 57, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*way / 6 - M_PI / 3, M_PI * dir / 240, 20, 30.0, M_PI*i / 3);
			}
		}
	}
	if (this->count % 15 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_LargeStar, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 2 + M_PI*GetRand(30) / 180 - M_PI / 12, 0.0);
	}
}

BossAttack_6_2_Hard::BossAttack_6_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1400;
	this->limitTime = 2400;
	this->attackName = "星の降る生誕祭";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_2_Hard::move(){
	this->count++;

	int t = this->count % 180;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 120){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 120));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_2_Hard::attack(){
	if (this->count % 60 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 12; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_SmallStar, Bul_Red, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i/6, 10.0, 20, 10.0);
		}
	}

	if (this->count % 25 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 70.0);
		for (int i = 0; i < 20; i++){
			this->isetBullet->isetBossBullet(Point(70.0, 100.0), Bul_Gun, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 1.8, -0.04, angle + M_PI*i / 10, 0.0, 80);
		}
	}
	if (this->count % 45 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 100.0, this->igetPlayerPosition->igetPosition().x - 446.0);
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(Point(446.0, 100.0), Bul_Oval, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, angle + M_PI*i / 12 - M_PI / 6, 0.0);
		}
	}
	if (this->count % 150 == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - 50.0, this->igetPlayerPosition->igetPosition().x - 258.0);
		for (int way = 0; way < 5; way++){
			double dir = 2.0*GetRand(1) - 1.0;
			for (int i = 0; i < 6; i++){
				this->isetBullet->isetBossBullet(Point(258.0, 50.0) + Point(30.0*cos(M_PI*i / 3), 30.0*sin(M_PI*i / 3)), Bul_Middle, Bul_Green, 57, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*way / 6 - M_PI / 3, M_PI * dir / 240, 20, 30.0, M_PI*i / 3);
			}
		}
	}
	if (this->count % 10 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_LargeStar, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 2 + M_PI*GetRand(30) / 180 - M_PI / 12, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_3_Easy::BossAttack_6_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 1100;
	this->limitTime = 1500;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_3_Easy::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_3_Easy::attack(){
	int t = this->count % 60;

	if (this->count % 360 == 0)return;

	if (t == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int block = 0; block < 4; block++){
			for (int i = 0; i < 3; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Green, 58, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*block / 2 + 0.65*M_PI*i / 8, 0.0);
			}
		}
	}
}

BossAttack_6_3_Normal::BossAttack_6_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 1600;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_3_Normal::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_3_Normal::attack(){
	int t = this->count % 60;

	if (this->count % 360 == 0)return;

	if (t == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int block = 0; block < 6; block++){
			for (int i = 0; i < 4; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Green, 58, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*block / 3 + 0.65*M_PI*i / 9, 0.0);
			}
		}
	}
}

BossAttack_6_3_Hard::BossAttack_6_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_3_Hard::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_3_Hard::attack(){
	int t = this->count % 60;

	if (this->count % 360 == 0)return;

	if (t == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int block = 0; block < 8; block++){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Green, 58, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*block / 4 + 0.65*M_PI*i / 16, 0.0);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_4_Easy::BossAttack_6_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 10000;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 3000;
	this->attackName = "囚われた火鳥";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_4_Easy::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(120, Point(80, 40), Point(436, 180));
	}
	else if (t <= 300){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 300));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_4_Easy::attack(){
	int t = this->count % 120;

	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*t / 30), 60.0*sin(M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 + 1.0*t / 30)), 60.0*sin(M_PI*(0.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 + 1.0*t / 30)), 60.0*sin(M_PI*(1.0 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 + 1.0*t / 30)), 60.0*sin(M_PI*(1.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(-M_PI*t / 30), 60.0*sin(-M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, -M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 - 1.0*t / 30)), 60.0*sin(M_PI*(0.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 - 1.0*t / 30)), 60.0*sin(M_PI*(1.0 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 - 1.0*t / 30)), 60.0*sin(M_PI*(1.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 - 1.0*t / 30), 0.0, 20, 40.0);


	if (t == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 23; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.8, 0.0, angle + M_PI*i * 8 / 9 / 22 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
	else if (t == 60){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 17; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.8, 0.0, angle + M_PI*i * 8 / 9 / 16 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
}

BossAttack_6_4_Normal::BossAttack_6_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 12000;
	this->HP_Max_Absorb = 3200;
	this->limitTime = 3200;
	this->attackName = "囚われた火鳥";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_4_Normal::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(70, Point(80, 40), Point(436, 180));
	}
	else if (t <= 300){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 300));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_4_Normal::attack(){
	int t = this->count % 80;

	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*t / 30), 60.0*sin(M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 + 1.0*t / 30)), 60.0*sin(M_PI*(0.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 + 1.0*t / 30)), 60.0*sin(M_PI*(1.0 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 + 1.0*t / 30)), 60.0*sin(M_PI*(1.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(-M_PI*t / 30), 60.0*sin(-M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, -M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 - 1.0*t / 30)), 60.0*sin(M_PI*(0.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 - 1.0*t / 30)), 60.0*sin(M_PI*(1.0 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 - 1.0*t / 30)), 60.0*sin(M_PI*(1.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 - 1.0*t / 30), 0.0, 20, 40.0);


	if (t == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 28; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.8, 0.0, angle + M_PI*i * 8 / 9 / 27 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
	else if (t == 40){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 23; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.8, 0.0, angle + M_PI*i * 8 / 9 / 22 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
}

BossAttack_6_4_Hard::BossAttack_6_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1300;
	this->HP_Max_Stand = 10000;
	this->HP_Max_Absorb = 3200;
	this->limitTime = 2800;
	this->attackName = "囚われた火鳥";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_4_Hard::move(){
	this->count++;

	int t = this->count % 360;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(70, Point(80, 40), Point(436, 140));
	}
	else if (t <= 300){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 300));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_4_Hard::attack(){
	int t = this->count % 40;

	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*t / 30), 60.0*sin(M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 + 1.0*t / 30)), 60.0*sin(M_PI*(0.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 + 1.0*t / 30)), 60.0*sin(M_PI*(1.0 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 + 1.0*t / 30)), 60.0*sin(M_PI*(1.5 + 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 + 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(-M_PI*t / 30), 60.0*sin(-M_PI*t / 30)), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, -M_PI*t / 30, 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(0.5 - 1.0*t / 30)), 60.0*sin(M_PI*(0.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(0.5 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.0 - 1.0*t / 30)), 60.0*sin(M_PI*(1.0 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.0 - 1.0*t / 30), 0.0, 20, 40.0);
	this->isetBullet->isetBossBullet(this->igetPlayerPosition->igetPosition() + Point(60.0*cos(M_PI*(1.5 - 1.0*t / 30)), 60.0*sin(M_PI*(1.5 - 1.0*t / 30))), Bul_Small, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 10.0, 2.0, M_PI*(1.5 - 1.0*t / 30), 0.0, 20, 40.0);


	if (t == 0){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 32; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.6, 0.0, angle + M_PI*i * 8 / 9 / 31 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
	else if (t == 20){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 27; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.6, 0.0, angle + M_PI*i * 8 / 9 / 26 - M_PI * 4 / 9 + M_PI*GetRand(20) / 1800 - M_PI / 180, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_5_Easy::BossAttack_6_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 450;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 1800;
	this->attackName = "核爆発イリュージョン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_5_Easy::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 30){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_5_Easy::attack(){
	int t = this->count % 200;

	if (t == 70){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Large, Bul_Orange, 60, this->isetBullet, this->igetPlayerPosition, 4.0, -1.0 / 15, angle + M_PI*i / 4.0, 0.0, 20, 10.0);
		}
	}
}

BossAttack_6_5_Normal::BossAttack_6_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 2200;
	this->limitTime = 1800;
	this->attackName = "核爆発イリュージョン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_5_Normal::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 30){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_5_Normal::attack(){
	int t = this->count % 200;

	if (t == 70){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 12; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Large, Bul_Orange, 60, this->isetBullet, this->igetPlayerPosition, 4.0, -1.0 / 15, angle + M_PI*i / 6, 0.0, 20, 12.0);
		}
	}
}

BossAttack_6_5_Hard::BossAttack_6_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 2000;
	this->attackName = "核爆発イリュージョン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_5_Hard::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t <= 30){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_5_Hard::attack(){
	int t = this->count % 200;

	if (t == 70){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 16; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Large, Bul_Orange, 60, this->isetBullet, this->igetPlayerPosition, 4.0, -1.0/15, angle + M_PI*i / 8, 0.0, 20, 16.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_6_Easy::BossAttack_6_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 3600;
	this->attackName = "イドはリビドーの夢を見るか";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_6_Easy::move(){
	this->count++;

	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 20){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 20));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_6_Easy::attack(){
	int t = this->count % 60;

	if (t == 0){
		if (GetRand(1) == 0){
			this->start = Point(-80.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		else{
			this->start = Point(596.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 62, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle, 10.0, 20.0, 30.0, 1.0, 10.0);
	}
	else if (t < 15){
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle, 10.0, 20.0, 30.0);
	}
}

BossAttack_6_6_Normal::BossAttack_6_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 3600;
	this->attackName = "イドはリビドーの夢を見るか";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_6_Normal::move(){
	this->count++;

	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 20){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 20));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_6_Normal::attack(){
	int t = this->count % 60;

	if (t == 0){
		if (GetRand(1) == 0){
			this->start = Point(-80.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		else{
			this->start = Point(596.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 62, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle, 10.0, 20.0, 30.0, 2.0, 20.0);
	}
	else if (t < 15){
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle, 10.0, 20.0, 30.0);
	}
}

BossAttack_6_6_Hard::BossAttack_6_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 700;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1400;
	this->limitTime = 3600;
	this->attackName = "イドはリビドーの夢を見るか";
	this->initialPosition = Point(258, 120);
}

void BossAttack_6_6_Hard::move(){
	this->count++;

	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t <= 20){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 20));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_6_6_Hard::attack(){
	int t = this->count % 50;

	if (t == 0){
		if (GetRand(1) == 0){
			this->start = Point(-80.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		else{
			this->start = Point(596.0, 0.1*GAME_WINDOW_HEIGHT + GetRand(0.9*GAME_WINDOW_HEIGHT));
			this->angle = atan2(-40.0 - this->start.y, GetRand(GAME_WINDOW_WIDTH) - this->start.x);
		}
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 62, this->isetBullet, this->igetPlayerPosition, 5.0, 0.0, this->angle, 10.0, 20.0, 30.0, 3.0, 30.0);
	}
	else if (t < 15){
		this->isetBullet->isetBossBullet(this->start, Bul_Large, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 5.0, 0.0, this->angle, 10.0, 20.0, 30.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_7_Easy::BossAttack_6_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 3600;
	this->attackName = "スキツォフレニア";
	this->initialPosition = Point(258, 150);
}

void BossAttack_6_7_Easy::move(){
	this->count++;
}

void BossAttack_6_7_Easy::attack(){
	if (this->count % 60 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 2, 1.0, 100, 100.0);
		}
		angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 2, -1.0, 100, 100.0);
		}
	}

	if (this->count % 100 == 0){
		this->ang = M_PI*GetRand(360) / 180;
	}
	if (this->count % 200 < 60){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 6; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(4 + line), 64, this->isetBullet, this->igetPlayerPosition, -2.0, 0.02, this->ang + M_PI*block / 3 + M_PI*(this->count % 200) / 360, 0.0, 20, 0.8*(1.0 + line));
				}
			}
		}
	}

	if (this->count % 200 < 100){
		//
	}
	else if (this->count % 200 < 160){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 6; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(1 + line), 64, this->isetBullet, this->igetPlayerPosition, -2.0, 0.02, this->ang + M_PI*block / 3 - M_PI*(this->count % 200) / 360, 0.0, 20, 0.8*(1.0 + line));
				}
			}
		}
	}
}

BossAttack_6_7_Normal::BossAttack_6_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 1500;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 3600;
	this->attackName = "スキツォフレニア";
	this->initialPosition = Point(258, 150);
}

void BossAttack_6_7_Normal::move(){
	this->count++;
}

void BossAttack_6_7_Normal::attack(){
	if (this->count % 60 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 4, 2.0, 100, 100.0);
		}
		angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 4, -2.0, 100, 100.0);
		}
	}

	if (this->count % 100 == 0){
		this->ang = M_PI*GetRand(360) / 180;
	}
	if (this->count % 200 < 60){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 10; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(4 + line), 64, this->isetBullet, this->igetPlayerPosition, -3.0, 0.03, this->ang + M_PI*block / 5 + M_PI*(this->count % 200) / 360, 0.0, 20, 1.0 + line);
				}
			}
		}
	}

	if (this->count % 200 < 100){
		//
	}
	else if (this->count % 200 < 160){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 10; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(1 + line), 64, this->isetBullet, this->igetPlayerPosition, -3.0, 0.03, this->ang + M_PI*block / 5 - M_PI*(this->count % 200) / 360, 0.0, 20, 1.0 + line);
				}
			}
		}
	}
}

BossAttack_6_7_Hard::BossAttack_6_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 1600;
	this->HP_Max_Absorb = 3500;
	this->limitTime = 3600;
	this->attackName = "スキツォフレニア";
	this->initialPosition = Point(258, 150);
}

void BossAttack_6_7_Hard::move(){
	this->count++;
}

void BossAttack_6_7_Hard::attack(){
	if (this->count % 60 == 0){
		double angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 10; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 5, 2.5, 100, 100.0);
		}
		angle = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 10; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 63, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI*i / 5, -2.5, 100, 100.0);
		}
	}

	if (this->count % 100 == 0){
		this->ang = M_PI*GetRand(360) / 180;
	}
	if (this->count % 200 < 60){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 12; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(4 + line), 64, this->isetBullet, this->igetPlayerPosition, -3.0, 0.03, this->ang + M_PI*block / 6 + M_PI*(this->count % 200) / 360, 0.0, 20, 1.0 + line);
				}
			}
		}
	}

	if (this->count % 200 < 100){
		//
	}
	else if (this->count % 200 < 160){
		if (this->count % 6 == 0){
			for (int line = 0; line < 2; line++){
				for (int block = 0; block < 12; block++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, (BulletColor)(1 + line), 64, this->isetBullet, this->igetPlayerPosition, -3.0, 0.03, this->ang + M_PI*block / 6 - M_PI*(this->count % 200) / 360, 0.0, 20, 1.0 + line);
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_6_8//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_6_8_Easy::BossAttack_6_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 5000;
	this->attackName = "クローズドゲートアセンション";
	this->initialPosition = Point(258, 290);
}

void BossAttack_6_8_Easy::move(){
	this->count++;
}

void BossAttack_6_8_Easy::attack(){
	if (this->count % 30 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), GAME_WINDOW_HEIGHT + 40), Bul_Snow, Bul_WaterBlue, 12, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, M_PI * 3 / 2, 1.0, 200, 30.0);
	}

	if (this->count % 40 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), GAME_WINDOW_HEIGHT + 40), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
		this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH + 40, GetRand(GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
	}

	if (this->count % 200 == 0){
		int c_p = GetRand(100) - 30;
		for (int i = -4; i < 4; i++){
			for (int line = 0; line < 12; line++){
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 160 * i, c_p - 100 - 160 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 160 * i, c_p - 100 - 160 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
			}
		}
	}
	if (this->count % 200 == 100){
		int c_p = GetRand(100) - 30;
		for (int i = -4; i < 4; i++){
			for (int line = 0; line < 12; line++){
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 160 * i, c_p - 100 - 160 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 160 * i, c_p - 100 - 160 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);

			}
		}
	}
}

BossAttack_6_8_Normal::BossAttack_6_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 900;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 5000;
	this->attackName = "クローズドゲートアセンション";
	this->initialPosition = Point(258, 290);
}

void BossAttack_6_8_Normal::move(){
	this->count++;
}

void BossAttack_6_8_Normal::attack(){
	if (this->count % 20 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), GAME_WINDOW_HEIGHT + 40), Bul_Snow, Bul_WaterBlue, 12, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, M_PI * 3 / 2, 1.0, 200, 30.0);
	}

	if (this->count % 30 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), GAME_WINDOW_HEIGHT + 40), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
		this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH + 40, GetRand(GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
	}

	if (this->count % 200 == 0){
		int c_p = GetRand(100) - 30;
		for (int i = -4; i < 4; i++){
			for (int line = 0; line < 12; line++){
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 160 * i, c_p - 100 - 160 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 160 * i, c_p - 100 - 160 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
			}
		}
	}
	if (this->count % 200 == 100){
		int c_p = GetRand(100) - 30;
		for (int i = -4; i < 4; i++){
			for (int line = 0; line < 12; line++){
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 160 * i, c_p - 100 - 160 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 160 * i, c_p - 100 - 160 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);

			}
		}
	}
}

BossAttack_6_8_Hard::BossAttack_6_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 5000;
	this->attackName = "クローズドゲートアセンション";
	this->initialPosition = Point(258, 290);
}

void BossAttack_6_8_Hard::move(){
	this->count++;
}

void BossAttack_6_8_Hard::attack(){
	if (this->count % 20 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH), GAME_WINDOW_HEIGHT + 40), Bul_Snow, Bul_WaterBlue, 12, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, M_PI * 3 / 2, 1.0, 200, 30.0);
	}

	if (this->count % 20 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), GAME_WINDOW_HEIGHT + 40), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
		this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH + 40, GetRand(GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 2), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 5 / 4, 0.0, 100);
	}

	if (this->count % 200 == 0){
		int c_p = GetRand(100) - 30;
		for (int i = -3; i < 3; i++){
			for (int line = 0; line < 16; line++){
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 200 * i, c_p - 100 - 200 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(c_p - 100 + 200 * i, c_p - 100 - 200 * i) + Point(10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
			}
		}
	}
	if (this->count % 200 == 100){
		int c_p = GetRand(100) - 30;
		for (int i = -3; i < 3; i++){
			for (int line = 0; line < 16; line++){
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 200 * i, c_p - 100 - 200 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0, 300);
				this->isetBullet->isetBossBullet(Point(GAME_WINDOW_WIDTH - c_p + 100 - 200 * i, c_p - 100 - 200 * i) + Point(-10 * line, -10 * line), Bul_Middle, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);

			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////