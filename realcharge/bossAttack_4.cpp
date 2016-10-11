#include "bossAttack_4.h"
#include "DxLib.h"

////BossAttack_4_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_1_Easy::BossAttack_4_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_1_Easy::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t < 80){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_1_Easy::attack(){
	if (this->count % 30 == 0){
		for (int way = 0; way < 12; way++){
			for (int i = 0; i < 4; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0
					, this->angle + M_PI * 2 * way / 12 + M_PI * 2 * 0.5*i / 36, 0.0);
			}
		}
		this->angle += M_PI * 4 / 180;
	}
}

BossAttack_4_1_Normal::BossAttack_4_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1200;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_1_Normal::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t < 80){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_1_Normal::attack(){
	if (this->count % 30 == 0){
		for (int way = 0; way < 16; way++){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0
					, this->angle + M_PI * 2 * way / 16 + M_PI*2*0.5*i / 64, 0.0);
			}
		}
		this->angle += M_PI * 5 / 180;
	}
}

BossAttack_4_1_Hard::BossAttack_4_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_1_Hard::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t < 80){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_1_Hard::attack(){
	if (this->count % 25 == 0){
		for (int way = 0; way < 20; way++){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0
					, this->angle + M_PI * 2 * way / 20 + M_PI*i / 80, 0.0);
			}
		}
		this->angle += M_PI * 5 / 180;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_2_Easy::BossAttack_4_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 100;
	this->HP_Max_Absorb = 600;
	this->limitTime = 3600;
	this->attackName = "掘ラートイレの音姫さん";
	this->initialPosition = Point(258, 240);
}

void BossAttack_4_2_Easy::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_2_Easy::attack(){
	int t = this->count % 1800;
	if (t % 15 != 0) return;

	if (t < 500){
		double ang = M_PI*GetRand(360) / 180;
		Point p = Point(400.0*cos(ang), 400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, 2.0, 100, 400.0);
	}
	if ((t>700) && (t<800)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 3; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI * 2 * i / 3, 0.0);
		}
	}

	if ((t > 900) && (t < 1400)){
		double ang = M_PI*GetRand(360) / 180;
		Point p = Point(400.0*cos(ang), 400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, -2.0, 100, 400.0);
	}
	if ((t > 1600) && (t < 1700)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 3; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI * 2 * i / 3, 0.0);
		}
	}
}

BossAttack_4_2_Normal::BossAttack_4_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 250;
	this->HP_Max_Stand = 120;
	this->HP_Max_Absorb = 700;
	this->limitTime = 3600;
	this->attackName = "掘ラートイレの音姫さん";
	this->initialPosition = Point(258, 240);
}

void BossAttack_4_2_Normal::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_2_Normal::attack(){
	int t = this->count % 1800;
	if (t % 9 != 0) return;

	if (t < 500){
		double ang = M_PI*GetRand(300) / 180 + M_PI * 20 / 180;
		Point p = Point(400.0*cos(ang), 400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, 3.0, 100, 400.0);
	}
	if ((t>700) && (t<800)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI * 2 * i / 5, 0.0);
		}
	}

	if ((t > 900) && (t < 1400)){
		double ang = M_PI*GetRand(300) / 180 - M_PI * 80 / 180;
		Point p = Point(400.0*cos(ang), 400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, -3.0, 100, 400.0);
	}
	if ((t > 1600) && (t < 1700)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI * 2 * i / 5, 0.0);
		}
	}
}

BossAttack_4_2_Hard::BossAttack_4_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 150;
	this->HP_Max_Absorb = 900;
	this->limitTime = 3600;
	this->attackName = "掘ラートイレの音姫さん";
	this->initialPosition = Point(258, 240);
}

void BossAttack_4_2_Hard::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_2_Hard::attack(){
	int t = this->count % 1800;
	if (t % 5 != 0) return;

	if (t < 500){
		double ang = M_PI*GetRand(300) / 180 + M_PI * 20 / 180;
		Point p = Point(400.0*cos(ang),400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, 3.0, 100, 400.0);
	}
	if ((t>700) && (t<800)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 6; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI*2*i / 6, 0.0);
		}
	}

	if ((t > 900) && (t < 1400)){
		double ang = M_PI*GetRand(300) / 180 - M_PI * 80 / 180;
		Point p = Point(400.0*cos(ang), 400.0*sin(ang)) + Point(258, 240);
		this->isetBullet->isetBossBullet(p, Bul_Snow, Bul_Blue, 55, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, ang, -3.0, 100, 400.0);
	}
	if ((t > 1600) && (t < 1700)){
		double ang = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 6; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.05, ang + M_PI*2*i / 6, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_3_Easy::BossAttack_4_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1100;
	this->HP_Max_Stand = 350;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_3_Easy::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 200));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_4_3_Easy::attack(){
	if (this->count % 50 == 0){
		for (int way = 0; way < 12; way++){
			for (int i = 0; i < 4; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0007*i
					, this->angle + M_PI * 2 * way / 12 + M_PI * 2 * 0.5*i / 36, 0.0);
			}
		}
		this->angle += M_PI * 4 / 180;
	}
}

BossAttack_4_3_Normal::BossAttack_4_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 450;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1200;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_3_Normal::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 200));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_4_3_Normal::attack(){
	if (this->count % 50 == 0){
		for (int way = 0; way < 16; way++){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.001*i
					, this->angle + M_PI * 2 * way / 16 + M_PI * 2 * 0.5*i / 64, 0.0);
			}
		}
		this->angle += M_PI * 5 / 180;
	}
}

BossAttack_4_3_Hard::BossAttack_4_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1800;
	this->HP_Max_Stand = 650;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->angle = M_PI*GetRand(360) / 180;
}

void BossAttack_4_3_Hard::move(){
	this->count++;

	int t = (this->count % 200);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 200));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_4_3_Hard::attack(){
	if (this->count % 40 == 0){
		for (int way = 0; way < 20; way++){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.001*i
					, this->angle + M_PI * 2 * way / 20 + M_PI*i / 80, 0.0);
			}
		}
		this->angle += M_PI * 5 / 180;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_4_Easy::BossAttack_4_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 600;
	this->limitTime = 3000;
	this->attackName = "ビッグベンフォーリンダウン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_4_Easy::move(){
	this->count++;

	int t = this->count % 500;

	if (t < 300){
		if (t % 50 == 0){
			this->moveFrom = this->igetBossPosition->igetPosition();
			this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
		}
		else{
			this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t % 50, 50));
			this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
		}
	}
	else if (t == 300){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = Point(258.0, 120.0);
	}
	else if (t <= 360){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 300, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_4_Easy::attack(){
	int t = this->count % 500;

	if (t < 360){
		if (t % 60 == 0){
			int x = GetRand(GAME_WINDOW_WIDTH - 100) + 50;
			double d = M_PI*GetRand(360) / 180;
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(Point(x, 260.0*i / 14 + 30), Bul_Money, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 19 * i / 180 + d, 0.0);
			}
		}
	}
	else if (t == 360){
		Point pos;
		for (int i = 0; i < 40; i++){
			pos = Point(50.0*(1 + cos(M_PI * 2 * i / 40))*sin(M_PI * 2 * i / 40), -50.0*(1 + cos(M_PI * 2 * i / 40))*cos(M_PI * 2 * i / 40)) + Point(258.0, 130.0);
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 2 * i / 40 - M_PI / 2, 0.0, 120, 100.0);
		}
	}
	else if (t < 460){
		if (t % 2 == 0) this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
	}
}

BossAttack_4_4_Normal::BossAttack_4_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 800;
	this->limitTime = 3000;
	this->attackName = "ビッグベンフォーリンダウン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_4_Normal::move(){
	this->count++;

	int t = this->count % 500;

	if (t < 300){
		if (t % 50 == 0){
			this->moveFrom = this->igetBossPosition->igetPosition();
			this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
		}
		else{
			this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t % 50, 50));
			this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
		}
	}
	else if (t == 300){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = Point(258.0, 120.0);
	}
	else if (t <= 360){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 300, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_4_Normal::attack(){
	int t = this->count % 500;

	if (t < 360){
		if (t % 40 == 0){
			int x = GetRand(GAME_WINDOW_WIDTH - 100) + 50;
			double d = M_PI*GetRand(360) / 180;
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(Point(x, 320.0*i / 20 + 30), Bul_Money, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 19 * i / 180 + d, 0.0);
			}
		}
	}
	else if (t == 360){
		Point pos;
		for (int i = 0; i < 60; i++){
			pos = Point(60.0*(1 + cos(M_PI * 2 * i / 60))*sin(M_PI * 2 * i / 60), -60.0*(1 + cos(M_PI * 2 * i / 60))*cos(M_PI * 2 * i / 60)) + Point(258.0, 130.0);
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 2 * i / 60 - M_PI / 2, 0.0, 120, 100.0);
		}
	}
	else if (t < 460){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
	}
}

BossAttack_4_4_Hard::BossAttack_4_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1200;
	this->HP_Max_Stand = 360;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 3000;
	this->attackName = "ビッグベンディストラクション";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_4_Hard::move(){
	this->count++;

	int t = this->count % 500;

	if (t < 300){
		if (t % 50 == 0){
			this->moveFrom = this->igetBossPosition->igetPosition();
			this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
		}
		else{
			this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t%50, 50));
			this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
		}
	}
	else if (t == 300){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = Point(258.0,120.0);
	}
	else if (t <= 360){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t-300, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_4_Hard::attack(){
	int t = this->count % 500;

	if (t < 360){
		if (t % 30 == 0){
			int x = GetRand(GAME_WINDOW_WIDTH-100) + 50;
			double d = M_PI*GetRand(360) / 180;
			for (int i = 0; i < 24; i++){
				this->isetBullet->isetBossBullet(Point(x, 320.0*i / 24 + 30), Bul_Money, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 19 * i / 180 + d, 0.0);
			}
		}
	}
	else if (t == 360){
		Point pos;
		for (int i = 0; i < 70; i++){
			pos = Point(70.0*(1 + cos(M_PI * 2 * i / 70))*sin(M_PI * 2 * i / 70), -70.0*(1 + cos(M_PI * 2 * i / 70))*cos(M_PI * 2 * i / 70)) + Point(258.0,140.0);
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 2 * i / 70 - M_PI / 2, 0.0, 120, 100.0);
		}
	}
	else if (t < 460){
		if (t % 3 != 0) this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_5_Easy::BossAttack_4_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1200;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1200;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_5_Easy::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_5_Easy::attack(){
	if (this->count % 24 == 0){
		double vx, vy;
		for (int i = 0; i < 18; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 24))*cos(M_PI * 2 * i / 18) - 3.0*sin(M_PI / 15 * (this->count / 24))*sin(M_PI * 2 * i / 18);
			vy = 4.0*sin(M_PI / 15 * (this->count / 24))*cos(M_PI * 2 * i / 18) + 3.0*cos(M_PI / 15 * (this->count / 24))*sin(M_PI * 2 * i / 18);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.75*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}

BossAttack_4_5_Normal::BossAttack_4_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 1100;
	this->limitTime = 1200;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_5_Normal::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_5_Normal::attack(){
	if (this->count % 18 == 0){
		double vx, vy;
		for (int i = 0; i < 24; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 24) - 3.0*sin(M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 24);
			vy = 4.0*sin(M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 24) + 3.0*cos(M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 24);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.9*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}

BossAttack_4_5_Hard::BossAttack_4_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1700;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 1600;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_5_Hard::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_5_Hard::attack(){
	if (this->count % 12 == 0){
		double vx, vy;
		for (int i = 0; i < 30; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) - 3.0*sin(M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			vy = 4.0*sin(M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) + 3.0*cos(M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_6_Easy::BossAttack_4_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 2800;
	this->attackName = "三位一体絶叫ビッグベン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_6_Easy::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_6_Easy::attack(){
	int t = this->count % 300;

	if (t == 0){
		int r = GetRand(30);
		double rad = M_PI*GetRand(360) / 180;
		this->center = Point(r*cos(rad), r*sin(rad)) + Point(258.0, 200.0);
		this->distance = GetRand(80) + 70;
		this->tilt = M_PI * 3 / 4 + M_PI*GetRand(90) / 180;
	}
	if (t == 10){
		Point pos;
		for (int i = 0; i < 40; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 40))*sin(M_PI * 2 * i / 40), -80.0*(1 + cos(M_PI * 2 * i / 40))*cos(M_PI * 2 * i / 40)) + this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 40 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 40){
		Point pos;
		for (int i = 0; i < 40; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 40))*sin(M_PI * 2 * i / 40), -80.0*(1 + cos(M_PI * 2 * i / 40))*cos(M_PI * 2 * i / 40)) + this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 40 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 70){
		Point pos;
		for (int i = 0; i < 40; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 40))*sin(M_PI * 2 * i / 40), -80.0*(1 + cos(M_PI * 2 * i / 40))*cos(M_PI * 2 * i / 40)) + this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 40 - M_PI / 2, 0.0, 170, 150.0);
		}
	}

	if ((t > 60) && (t < 160)){
		if (t % 10 == 0){
			Point pos = this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 90) && (t < 190)){
		if (t % 6 == 0){
			Point pos = this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 120) && (t < 220)){
		if (t % 10 == 0){
			Point pos = this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
}

BossAttack_4_6_Normal::BossAttack_4_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 2800;
	this->attackName = "三位一体絶叫ビッグベン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_6_Normal::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_6_Normal::attack(){
	int t = this->count % 300;

	if (t == 0){
		int r = GetRand(30);
		double rad = M_PI*GetRand(360) / 180;
		this->center = Point(r*cos(rad), r*sin(rad)) + Point(258.0, 200.0);
		this->distance = GetRand(80) + 70;
		this->tilt = M_PI * 3 / 4 + M_PI*GetRand(90) / 180;
	}
	if (t == 10){
		Point pos;
		for (int i = 0; i < 50; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 50))*sin(M_PI * 2 * i / 50), -80.0*(1 + cos(M_PI * 2 * i / 50))*cos(M_PI * 2 * i / 50)) + this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 50 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 40){
		Point pos;
		for (int i = 0; i < 50; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 50))*sin(M_PI * 2 * i / 50), -80.0*(1 + cos(M_PI * 2 * i / 50))*cos(M_PI * 2 * i / 50)) + this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 50 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 70){
		Point pos;
		for (int i = 0; i < 50; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 50))*sin(M_PI * 2 * i / 50), -80.0*(1 + cos(M_PI * 2 * i / 50))*cos(M_PI * 2 * i / 50)) + this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 50 - M_PI / 2, 0.0, 170, 150.0);
		}
	}

	if ((t > 60) && (t < 160)){
		if (t % 6 == 0){
			Point pos = this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 2.4, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 90) && (t < 190)){
		if (t % 6 == 0){
			Point pos = this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 120) && (t < 220)){
		if (t % 6 == 0){
			Point pos = this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 2.4, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
}

BossAttack_4_6_Hard::BossAttack_4_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1400;
	this->limitTime = 2800;
	this->attackName = "三位一体絶叫ビッグベン";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_6_Hard::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_6_Hard::attack(){
	int t = this->count % 300;

	if (t == 0){
		int r = GetRand(30);
		double rad = M_PI*GetRand(360) / 180;
		this->center = Point(r*cos(rad), r*sin(rad)) + Point(258.0, 200.0);
		this->distance = GetRand(80) + 70;
		this->tilt = M_PI * 3 / 4 + M_PI*GetRand(90) / 180;
	}
	if (t == 10){
		Point pos;
		for (int i = 0; i < 60; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 60))*sin(M_PI * 2 * i / 60), -80.0*(1 + cos(M_PI * 2 * i / 60))*cos(M_PI * 2 * i / 60)) + this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 60 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 40){
		Point pos;
		for (int i = 0; i < 60; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 60))*sin(M_PI * 2 * i / 60), -80.0*(1 + cos(M_PI * 2 * i / 60))*cos(M_PI * 2 * i / 60)) + this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 60 - M_PI / 2, 0.0, 170, 150.0);
		}
	}
	if (t == 70){
		Point pos;
		for (int i = 0; i < 60; i++){
			pos = Point(80.0*(1 + cos(M_PI * 2 * i / 60))*sin(M_PI * 2 * i / 60), -80.0*(1 + cos(M_PI * 2 * i / 60))*cos(M_PI * 2 * i / 60)) + this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Middle, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 1.5, 0.02, M_PI * 2 * i / 60 - M_PI / 2, 0.0, 170, 150.0);
		}
	}

	if ((t > 60) && (t < 160)){
		if (t % 4 == 0){
			Point pos = this->center + Point(this->distance*cos(this->tilt), this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 90) && (t < 190)){
		if (t % 3 == 0){
			Point pos = this->center;
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
	if ((t > 120) && (t < 220)){
		if (t % 4 == 0){
			Point pos = this->center + Point(-this->distance*cos(this->tilt), -this->distance*sin(this->tilt));
			this->isetBullet->isetBossBullet(pos, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_7_Easy::BossAttack_4_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1200;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1300;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_7_Easy::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_7_Easy::attack(){
	if (this->count % 40 == 0){
		double vx, vy;
		for (int i = 0; i < 20; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 20))*cos(M_PI * 2 * i / 20) - 3.0*sin(M_PI / 15 * (this->count / 20))*sin(M_PI * 2 * i / 20);
			vy = 4.0*sin(M_PI / 15 * (this->count / 20))*cos(M_PI * 2 * i / 20) + 3.0*cos(M_PI / 15 * (this->count / 20))*sin(M_PI * 2 * i / 20);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.75*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
	if (this->count % 40 == 20){
		double vx, vy;
		for (int i = 0; i < 20; i++){
			vx = 4.0*cos(-M_PI / 15 * (this->count / 20))*cos(M_PI * 2 * i / 20) - 3.0*sin(-M_PI / 15 * (this->count / 20))*sin(M_PI * 2 * i / 20);
			vy = 4.0*sin(-M_PI / 15 * (this->count / 20))*cos(M_PI * 2 * i / 20) + 3.0*cos(-M_PI / 15 * (this->count / 20))*sin(M_PI * 2 * i / 20);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.75*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}

BossAttack_4_7_Normal::BossAttack_4_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 1100;
	this->limitTime = 1600;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_7_Normal::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_7_Normal::attack(){
	if (this->count % 36 == 0){
		double vx, vy;
		for (int i = 0; i < 26; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 26) - 3.0*sin(M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 26);
			vy = 4.0*sin(M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 26) + 3.0*cos(M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 26);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.9*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
	if (this->count % 36 == 18){
		double vx, vy;
		for (int i = 0; i < 26; i++){
			vx = 4.0*cos(-M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 26) - 3.0*sin(-M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 26);
			vy = 4.0*sin(-M_PI / 15 * (this->count / 18))*cos(M_PI * 2 * i / 26) + 3.0*cos(-M_PI / 15 * (this->count / 18))*sin(M_PI * 2 * i / 26);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, 0.9*sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}

BossAttack_4_7_Hard::BossAttack_4_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1700;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_4_7_Hard::move(){
	this->count++;

	int t = this->count % 100;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else if (t<60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_4_7_Hard::attack(){
	if (this->count % 24 == 0){
		double vx, vy;
		for (int i = 0; i < 30; i++){
			vx = 4.0*cos(M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) - 3.0*sin(M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			vy = 4.0*sin(M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) + 3.0*cos(M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
	if (this->count % 24 == 12){
		double vx, vy;
		for (int i = 0; i < 30; i++){
			vx = 4.0*cos(-M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) - 3.0*sin(-M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			vy = 4.0*sin(-M_PI / 15 * (this->count / 12))*cos(M_PI * 2 * i / 30) + 3.0*cos(-M_PI / 15 * (this->count / 12))*sin(M_PI * 2 * i / 30);
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
				, sqrt(vx*vx + vy*vy), 0.0, atan2(vy, vx), 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_4_8//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_4_8_Easy::BossAttack_4_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 3600;
	this->attackName = "レズとゲイがありあまる";
	this->initialPosition = Point(258, 200);
}

void BossAttack_4_8_Easy::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_8_Easy::attack(){
	int t = this->count % 300;

	if (t == 0){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos, temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 22; i+=2){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 22), 50.0*sin(M_PI * 2 * i / 22));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -2; i <= 10; i+=2){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -4; i <= 10; i+=2){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -4; i <= 10; i+=2){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 22; i+=2){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 22), 50.0*sin(M_PI * 2 * i / 22));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -2; i <= 10; i+=2){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -4; i <= 10; i+=2){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -4; i <= 10; i+=2){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
	}
	if (t == 150){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos, temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 22; i+=2){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 22), 50.0*sin(M_PI * 2 * i / 22));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i+=2){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -14; i <= 4; i+=2){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 22; i+=2){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 22), 50.0*sin(M_PI * 2 * i / 22));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i+=2){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -14; i <= 4; i+=2){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
	}
}

BossAttack_4_8_Normal::BossAttack_4_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2200;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 3600;
	this->attackName = "レズとゲイがありあまる";
	this->initialPosition = Point(258, 200);
}

void BossAttack_4_8_Normal::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_8_Normal::attack(){
	int t = this->count % 240;

	if (t == 0){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos, temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 36; i++){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 36), 50.0*sin(M_PI * 2 * i / 36));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -3; i <= 10; i++){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 36; i++){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 36), 50.0*sin(M_PI * 2 * i / 36));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -3; i <= 10; i++){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
	}
	if (t == 120){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos, temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 36; i++){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 36), 50.0*sin(M_PI * 2 * i / 36));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i++){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -15; i <= 5; i++){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 36; i++){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 36), 50.0*sin(M_PI * 2 * i / 36));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i++){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
		for (int i = -15; i <= 5; i++){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*2.2 / 100, 0.01, angle, 0.0, 100, 100.0);
		}
	}
}

BossAttack_4_8_Hard::BossAttack_4_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2500;
	this->HP_Max_Stand = 1500;
	this->HP_Max_Absorb = 1800;
	this->limitTime = 3600;
	this->attackName = "レズとゲイがありあまる";
	this->initialPosition = Point(258, 200);
}

void BossAttack_4_8_Hard::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_4_8_Hard::attack(){
	int t = this->count % 240;

	if (t == 0){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos,temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 40; i++){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 40), 50.0*sin(M_PI * 2 * i / 40));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -3; i <= 10; i++){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 40; i++){
			temp = Point(-50.0, 50.0) + Point(50.0*cos(M_PI * 2 * i / 40), 50.0*sin(M_PI * 2 * i / 40));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -3; i <= 10; i++){
			temp = Point(5.0*i, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(5.0*i, -50.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -5; i <= 10; i++){
			temp = Point(50.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
	}
	if (t == 120){
		Point cent = this->getSquareRandomMovePosition(Point(70, 70), Point(446, 240));
		Point pos, temp;
		double distance;
		double angle;
		double rot = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 40; i++){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 40), 50.0*sin(M_PI * 2 * i / 40));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i++){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -15; i <= 5; i++){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}

		angle = M_PI*GetRand(360) / 180;
		rot = M_PI*GetRand(360) / 180;
		cent = cent + Point(30.0*cos(angle), 30.0 + sin(angle));
		for (int i = 0; i < 40; i++){
			temp = Point(0.0, -75.0) + Point(50.0*cos(M_PI * 2 * i / 40), 50.0*sin(M_PI * 2 * i / 40));
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -10; i <= 10; i++){
			temp = Point(5.0*i, 0.0);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
		for (int i = -15; i <= 5; i++){
			temp = Point(0.0, -5.0*i);
			pos.x = temp.x*cos(rot) - temp.y*sin(rot);
			pos.y = temp.x*sin(rot) + temp.y*cos(rot);
			pos = pos + cent;
			distance = sqrt((pos.x - cent.x)*(pos.x - cent.x) + (pos.y - cent.y)*(pos.y - cent.y));
			angle = atan2(pos.y - cent.y, pos.x - cent.x);
			this->isetBullet->isetBossBullet(pos, Bul_Money, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, distance*3.0 / 100, 0.02, angle, 0.0, 100, 100.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
