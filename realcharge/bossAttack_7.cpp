#include "bossAttack_7.h"
#include "DxLib.h"

////BossAttack_7_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_1::BossAttack_7_1(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 5000;
	this->HP_Max_Stand = 1200;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2000;
	this->attackName = "アマテラスの導き";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_1::move(){
	this->count++;

	int t = this->count % 200;

	if (t<150){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 150){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 150, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_1::attack(){
	int t = this->count % 200;
	
	if (t == 0){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 20; i++){
			this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_Orange, 3, 20, 3.0, 0.0, rad + M_PI * 2 * i / 20, M_PI / 300, 180);
		}
	}
	else if (t == 60){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 20; i++){
			this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_Orange, 3, 20, 3.0, 0.0, rad + M_PI * 2 * i / 20, -M_PI / 300, 180);
		}
	}

	if (t < 150){
		if (t % 50 == 0){
			double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Green, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, rad + M_PI * 2 * i / 20, 0.0);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_2::BossAttack_7_2(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2400;
	this->attackName = "ラララライ麦畑でつかまえて";
	this->initialPosition = Point(258, 120);

	this->rye = new LSystem();
}

void BossAttack_7_2::move(){
	this->count++;

	int t = this->count % 200;

	if (t<150){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 150){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 150, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_2::attack(){
	int t = this->count % 500;

	if (t == 0){
		this->rye->initialize(Point(300, 250), 500, M_PI * 15 / 180, M_PI * 3 / 2, "f");
		this->rye->setRule('f', "[+f][-f]fff[+ff-ff+ff][-ff+ff]");
		this->rye->calculate(2);
		this->rye->sortFromDown();
	}
	else if (t <= 100){
		for (unsigned int i = (t - 1)*this->rye->getResultAllPoint().size() / 100; i <= t*this->rye->getResultAllPoint().size() / 100 -1 ; i++){
			this->isetBullet->isetBossBullet(this->rye->getResultAllPoint()[i], Bul_Crystal, Bul_Yellow, 10, this->isetBullet, this->igetPlayerPosition, 2.0, 0.005, (GetRand(180) + 270)*M_PI / 180, 0.0, 20, 200);
		}
	}
	else if (t < 250){
		//
	}
	else if (t == 250){
		this->rye->initialize(Point(616, 250), 500, M_PI * 15 / 180, M_PI * 3 / 2, "f");
		this->rye->setRule('f', "[+f][-f]fff[+ff-ff+ff][-ff+ff]");
		this->rye->calculate(2);
		this->rye->sortFromDown();
	}
	else if (t <= 350){
		for (unsigned int i = (t - 250 - 1)*this->rye->getResultAllPoint().size() / 100; i <= (t - 250)*this->rye->getResultAllPoint().size() / 100 -1 ; i++){
			this->isetBullet->isetBossBullet(this->rye->getResultAllPoint()[i], Bul_Crystal, Bul_Yellow, 10, this->isetBullet, this->igetPlayerPosition, 2.0, 0.005, (GetRand(180) + 90)*M_PI / 180, 0.0, 20, 200);
		}
	}
	else{
		//
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_3::BossAttack_7_3(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 2500;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1800;
	this->attackName = "高速ナイフシャワー";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_3::move(){
	this->count++;

	int t = this->count % 300;

	if (t<250){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_3::attack(){
	int t = this->count % 300;
	if (t > 250) return;

	for (int i = 0; i < 3; i++){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Knife, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, i + 1, 0.02, M_PI*GetRand(360) / 180, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_4::BossAttack_7_4(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "ワイリー凍結仮説";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_4::move(){
	this->count++;

	int t = this->count % 60;

	if (t<30){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 30){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 30, 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_4::attack(){
	if (this->count % 60 == 0){
		for (int line = 0; line < 3; line++){
			double rad = M_PI*GetRand(180) / 180;
			for (int i = 0; i < 10+5*line; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Oval, Bul_Orange, 65, this->isetBullet, this->igetPlayerPosition, line + 1, 0.0, rad + M_PI * 2 * i / (10 + 5 * line), 0.0, 60);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_5::BossAttack_7_5(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 7000;
	this->HP_Max_Stand = 3000;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2000;
	this->attackName = "彗星の赤いシャア";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_5::move(){
	this->count++;
	int t = this->count % 300;

	if (t<250){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_5::attack(){
	int t = this->count % 300;

	if (t < 250){
		if (t % 80 == 0){
			double rad = M_PI*GetRand(360) / 180;
			for (int i = 0; i < 12; i++){
				this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_Red, 1, 30, 4, 0.02, rad + M_PI * 2 * i / 12, 0.0);
				this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_Red, 5, 20, 5, 0.0, rad + M_PI * 2 * i / 12, M_PI / 30, 20, 30);
				this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_Red, 5, 20, 5, 0.0, rad + M_PI * 2 * i / 12, M_PI / 30, 20, 30, M_PI);
			}
		}
	}
	if (t % 2 == 0){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI*GetRand(360) / 180, 0.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_6::BossAttack_7_6(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1000;
	this->attackName = "リンガディンドン";
	this->initialPosition = Point(258, 200);
}

void BossAttack_7_6::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_7_6::attack(){
	if (this->count % 60 != 0) return;

	double rad = M_PI*GetRand(360) / 180;
	if ((this->count % 60) % 2 == 0){
		for (int way = 0; way < 2; way++){
			for (int i = 0; i < 12; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Fuda, (BulletColor)(Bul_Green + way), 66, this->isetBullet, this->igetPlayerPosition, 0.5, 0.0, rad + M_PI*way, -M_PI / 720, 300, M_PI / 200, 1.5, M_PI*i * 2 / 12);
			}
		}
	}
	else{
		for (int way = 0; way < 2; way++){
			for (int i = 0; i < 12; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Fuda, (BulletColor)(Bul_Green + way), 66, this->isetBullet, this->igetPlayerPosition, 0.5, 0.0, rad + M_PI*way, M_PI / 720, 300, -M_PI / 200, 1.5, M_PI*i * 2 / 12);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_7::BossAttack_7_7(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 800;
	this->limitTime = 800;
	this->attackName = "ジェットスキードリーマー";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_7::move(){
	this->count++;
	int t = this->count % 200;

	if (t<150){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 150){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 150, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_7::attack(){
	if (this->count % 60 == 0){
		this->isetBullet->isetBossBullet(Point(-40, GetRand(GAME_WINDOW_HEIGHT)), Bul_Large, Bul_White, 67, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*(GetRand(180) - 90) / 180, 0.0, 30);
	}
	if (this->count % 60 == 30){
		this->isetBullet->isetBossBullet(Point(556, GetRand(GAME_WINDOW_HEIGHT)), Bul_Large, Bul_White, 67, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*(GetRand(180) + 90) / 180, 0.0, 30);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_8//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_8::BossAttack_7_8(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 1800;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 1500;
	this->attackName = "ミスティックアークアロー";
	this->initialPosition = Point(258, 120);

	this->tmp_rad[0] = 0.0;
	this->tmp_rad[1] = 0.0;
}

void BossAttack_7_8::move(){
	this->count++;
	int t = this->count % 300;

	if (t<250){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(30, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_8::attack(){
	if (this->count % 4 != 0) return;

	this->isetLazer->isetEnemyLazer(Point(100, 100), Bul_WaterBlue, 6, 20, 4.0, 0.0, this->tmp_rad[0], 0.0, 20, 1.0, 0.0);
	this->isetLazer->isetEnemyLazer(Point(416, 100), Bul_WaterBlue, 6, 20, 4.0, 0.0, this->tmp_rad[1], 0.0, 20, 1.0, 0.0);
	this->tmp_rad[0] -= M_PI*8.6 / 180;
	this->tmp_rad[1] += M_PI*8.6 / 180;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_9//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_9::BossAttack_7_9(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 5000;
	this->HP_Max_Stand = 1200;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2000;
	this->attackName = "天高く虹の橋立";
	this->initialPosition = Point(258, 200);

	this->tmp_rad = M_PI*GetRand(360) / 180;
	for (int i = 0; i < 4; i++) this->tmp_t[i] = GetRand(2);
}

void BossAttack_7_9::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_7_9::attack(){
	if (this->count % 6 != this->tmp_t[0]){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, this->tmp_rad, 0.0);
		this->tmp_t[0] = GetRand(2);
	}
	if (this->count % 10 != this->tmp_t[1]){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, this->tmp_rad + M_PI / 2, 0.0);
		this->tmp_t[1] = GetRand(2);
	}
	if (this->count % 15 != this->tmp_t[2]){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, this->tmp_rad + M_PI, 0.0);
		this->tmp_t[2] = GetRand(2);
	}
	if (this->count % 12 != this->tmp_t[3]){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, this->tmp_rad + M_PI * 3 / 2, 0.0);
		this->tmp_t[3] = GetRand(2);
	}

	this->tmp_rad += M_PI / 90;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_10//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_10::BossAttack_7_10(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1700;
	this->limitTime = 2000;
	this->attackName = "スターダストアレイ";
	this->initialPosition = Point(258, 180);
}

void BossAttack_7_10::move(){
	this->count++;
	int t = this->count % 300;

	if (t<350){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(30, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_10::attack(){
	if (this->count % 300 == 0){
		double rad = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Large, Bul_White, 68, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, rad + M_PI*i / 2, M_PI / 180, 200);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_11//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_11::BossAttack_7_11(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 1800;
	this->HP_Max_Absorb = 1800;
	this->limitTime = 2400;
	this->attackName = "びりびりすぱーく";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_11::move(){
	this->count++;
	int t = this->count % 300;

	if (t<250){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_11::attack(){
	int t = this->count % 300;

	if (t < 150){
		if (t % 5 == 0){
			for (int i = -4; i <= 4; i++){
				if (i == 0) continue;
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI * 2 / 45 * t), 50.0*sin(M_PI * 2 / 45 * t)), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, i, 0.0, M_PI * 2 / 45 * t + M_PI / 2, 0.0);
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI * 2 / 45 * t + M_PI), 50.0*sin(M_PI * 2 / 45 * t + M_PI)), Bul_Knife, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, i, 0.0, M_PI * 2 / 45 * t - M_PI / 2, 0.0);
			}
		}
	}
	if (t == 220){
		for (int i = 0; i < 3; i++){
			Point pos = Point(GetRand(GAME_WINDOW_WIDTH - 120) + 60, GetRand(160) + 40);
			double rad;
			for (int j = 0; j < 12; j++){
				rad = M_PI*GetRand(10) / 180;
				this->isetLazer->isetEnemyLazer(pos, Bul_WaterBlue, 5, 15, 5.0, 0.0, M_PI * 2 * j / 12 + rad, M_PI / 30, 20, 30.0, 0.00);
				this->isetLazer->isetEnemyLazer(pos, Bul_WaterBlue, 5, 15, 5.0, 0.0, M_PI * 2 * j / 12 + rad, M_PI / 30, 20, 30.0, M_PI);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_12//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_12::BossAttack_7_12(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 1300;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2800;
	this->attackName = "金のハンマー銀の弾丸";
	this->initialPosition = Point(258, 120);

	this->tmp_rad = M_PI*GetRand(360) / 180;
}

void BossAttack_7_12::move(){
	this->count++;

	int t = this->count % 200;

	if (t<170){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 170){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(150, 50), Point(366, 130));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 170, 30));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_12::attack(){
	if (this->count % 30 == 0){
		for (int way = 0; way < 3; way++){
			for (int i = 0; i < 6; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(30.0*cos(M_PI*i / 3), 30.0*sin(M_PI*i / 3)), Bul_Middle, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, this->tmp_rad + M_PI*way * 2 / 3, 0.0);
			}
		}
		this->tmp_rad += M_PI / 20;
	}
	if (this->count % 5 == 0){
		for (int i = 0; i < 15; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Gun, Bul_White, 69, this->isetBullet, this->igetPlayerPosition, -5.6, 0.04, M_PI*GetRand(360) / 180, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_13//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_13::BossAttack_7_13(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 2800;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2000;
	this->attackName = "雷神グサンタケミカヅチ";
	this->initialPosition = Point(258, 280);
}

void BossAttack_7_13::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_7_13::attack(){
	int t = this->count % 600;
	if (t % 150 == 0){
		double rad = M_PI*GetRand(360) / 180;
		for (int i = 0; i < 20; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Kunai, Bul_Yellow, 70, this->isetBullet, this->igetPlayerPosition, 5.0, -0.05, rad + M_PI * 2 * i / 20, 0.0);
		}
	}
	if (t % 200 == 0){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 10; i++){
			this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition(), Bul_WaterBlue, 5, 15, 3.0, 0.0, rad + M_PI * 2 * i / 10, M_PI / 50, 20, 30.0);
		}
	}
	if (t % 450 == 0){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		double rad_;
		for (int i = 0; i < 20; i++){
			if((this->count/300)%2==0) rad_ = atan2(50.0*sin(rad + M_PI / 2 + M_PI * 2 * i / 20) - 400.0*sin(rad + M_PI * 2 * i / 20), 50.0*cos(rad + M_PI / 2 + M_PI * 2 * i / 20) - 400.0*cos(rad + M_PI * 2 * i / 20));
			else rad_ = atan2(50.0*sin(rad - M_PI / 2 + M_PI * 2 * i / 20) - 400.0*sin(rad + M_PI * 2 * i / 20), 50.0*cos(rad - M_PI / 2 + M_PI * 2 * i / 20) - 400.0*cos(rad + M_PI * 2 * i / 20));
			this->isetLazer->isetEnemyLazer(this->igetBossPosition->igetPosition() + Point(400.0*cos(rad + M_PI * 2 * i / 20), 400.0*sin(rad + M_PI * 2 * i / 20)), Bul_Red, 0, 15, 3.0, 0.0, rad_, 0.0, 200);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_14//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_14::BossAttack_7_14(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 2000;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2400;
	this->attackName = "ウカノミタマウィルス";
	this->initialPosition = Point(258, 160);

	this->tree = new LSystem();
}

void BossAttack_7_14::move(){
	this->count++;
	int t = this->count % 60;

	if (t<40){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 40){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(30, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 40, 20));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_14::attack(){
	if (this->count < 60) return;
	int t = this->count % 120;

	if (t%60 == 0){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int i = 0; i < 20; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.03, rad + M_PI * 2 * i / 20, 0.0);
		}
	}
	
	if (t == 0){
		int type = GetRand(3);
		if (type == 0){
			this->tree->initialize(Point(200.0+GetRand(GAME_WINDOW_WIDTH - 200), 150.0 + GetRand(50)), 300, M_PI * 15 / 180, M_PI * 3 / 2, "f");
			this->tree->setRule('f', "x[-ff]y");
			this->tree->setRule('x', "ff");
			this->tree->setRule('y', "[+f[+f][-f+f]]");
			this->tree->calculate(4);
		}
		if (type == 1){
			this->tree->initialize(Point(200.0+GetRand(GAME_WINDOW_WIDTH - 200), 150.0 + GetRand(50)), 300, M_PI * 15 / 180, M_PI * 3 / 2, "f");
			this->tree->setRule('f', "f[+ff[+f][-f]]f[-ff[+f][-f]]f");
			this->tree->calculate(2);
		}
		if (type == 2){
			this->tree->initialize(Point(200.0+GetRand(GAME_WINDOW_WIDTH - 200), 150.0 + GetRand(50)), 300, M_PI * 15 / 180, M_PI * 3 / 2, "f");
			this->tree->setRule('f', "f[-f+f+f][++f]f-f");
			this->tree->calculate(3);
		}
		if (type == 3){
			this->tree->initialize(Point(200.0+GetRand(GAME_WINDOW_WIDTH - 200), 150.0 + GetRand(50)), 300, M_PI * 15 / 180, M_PI * 3 / 2, "f");
			this->tree->setRule('f', "ff[-f][+f[+f][-f+f]]");
			this->tree->calculate(3);
		}
		this->tree->sortFromCenter();
	}
	else if (t <= 30){
		BulletColor col = (BulletColor)(GetRand(1) + 2);
		for (unsigned int i = (t - 1)*this->tree->getResultAllPoint().size() / 30; i <= t*this->tree->getResultAllPoint().size() / 30 - 1; i++){
			this->isetBullet->isetBossBullet(this->tree->getResultAllPoint()[i], Bul_Crystal, col, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.005, M_PI*GetRand(360) / 180, 0.0, 20, 100);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_15//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_15::BossAttack_7_15(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 1500;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 2500;
	this->attackName = "ロケットゼロテイクオフ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_7_15::move(){
	this->count++;
	int t = this->count % 300;

	if (t<250){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 250){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(60, 50), Point(456, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 250, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_15::attack(){
	int t = this->count % 700;
	if (t < 400){
		if (t % 100 == 0){
			Point center = Point(-150.0, GetRand(400) + 200);
			for (double t = -2.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 5 / 4), 40.0*t*sin(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			for (double t = 0.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(-40.0*cos(M_PI * 5 / 4) - 40.0*t*sin(M_PI * 5 / 4), -40.0*sin(M_PI * 5 / 4) + 40.0*t*cos(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			for (double t = 0.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*cos(M_PI * 5 / 4) - 40.0*t*sin(M_PI * 5 / 4), 40.0*sin(M_PI * 5 / 4) + 40.0*t*cos(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			for (double t = -2.0; t <= -1.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 5 / 4) - 40.0*(t + 2)*sin(M_PI * 5 / 4), 40.0*t*sin(M_PI * 5 / 4) + 40.0*(t + 2)*cos(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			for (double t = 1.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 5 / 4) - 40.0*(2 - t)*sin(M_PI * 5 / 4), 40.0*t*sin(M_PI * 5 / 4) + 40.0*(2 - t)*cos(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			for (double t = -1.0; t <= 1.0; t += 0.08){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 5 / 4) - 40.0*(3 - t*t)*sin(M_PI * 5 / 4), 40.0*t*sin(M_PI * 5 / 4) + 40.0*(3 - t*t)*cos(M_PI * 5 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
			}
			this->isetBullet->isetBossBullet(center, Bul_Small, Bul_WaterBlue, 71, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 7 / 4, 0.0, 150);
		}
		if (t % 100 == 50){
			Point center = Point(666.0, GetRand(400) + 200);
			for (double t = -2.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 3 / 4), 40.0*t*sin(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			for (double t = 0.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(-40.0*cos(M_PI * 3 / 4) - 40.0*t*sin(M_PI * 3 / 4), -40.0*sin(M_PI * 3 / 4) + 40.0*t*cos(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			for (double t = 0.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*cos(M_PI * 3 / 4) - 40.0*t*sin(M_PI * 3 / 4), 40.0*sin(M_PI * 3 / 4) + 40.0*t*cos(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			for (double t = -2.0; t <= -1.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 3 / 4) - 40.0*(t + 2)*sin(M_PI * 3 / 4), 40.0*t*sin(M_PI * 3 / 4) + 40.0*(t + 2)*cos(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			for (double t = 1.0; t <= 2.0; t += 0.1){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 3 / 4) - 40.0*(2 - t)*sin(M_PI * 3 / 4), 40.0*t*sin(M_PI * 3 / 4) + 40.0*(2 - t)*cos(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			for (double t = -1.0; t <= 1.0; t += 0.08){
				this->isetBullet->isetBossBullet(Point(40.0*t*cos(M_PI * 3 / 4) - 40.0*(3 - t*t)*sin(M_PI * 3 / 4), 40.0*t*sin(M_PI * 3 / 4) + 40.0*(3 - t*t)*cos(M_PI * 3 / 4)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
			}
			this->isetBullet->isetBossBullet(center, Bul_Small, Bul_WaterBlue, 71, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI * 5 / 4, 0.0, 150);
		}
	}
	if (t == 500){
		Point center = Point(258.0, -30.0);
		for (double t = -2.0; t <= 2.0; t += 0.1){
			this->isetBullet->isetBossBullet(Point(60.0*t*cos(M_PI), 60.0*t*sin(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		for (double t = 0.0; t <= 2.0; t += 0.1){
			this->isetBullet->isetBossBullet(Point(-60.0*cos(M_PI) - 60.0*t*sin(M_PI), -60.0*sin(M_PI) + 60.0*t*cos(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		for (double t = 0.0; t <= 2.0; t += 0.1){
			this->isetBullet->isetBossBullet(Point(60.0*cos(M_PI) - 60.0*t*sin(M_PI), 60.0*sin(M_PI) + 60.0*t*cos(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		for (double t = -2.0; t <= -1.0; t += 0.1){
			this->isetBullet->isetBossBullet(Point(60.0*t*cos(M_PI) - 60.0*(t + 2)*sin(M_PI), 60.0*t*sin(M_PI) + 60.0*(t + 2)*cos(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		for (double t = 1.0; t <= 2.0; t += 0.1){
			this->isetBullet->isetBossBullet(Point(60.0*t*cos(M_PI) - 60.0*(2 - t)*sin(M_PI), 60.0*t*sin(M_PI) + 60.0*(2 - t)*cos(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		for (double t = -1.0; t <= 1.0; t += 0.08){
			this->isetBullet->isetBossBullet(Point(60.0*t*cos(M_PI) - 60.0*(3 - t*t)*sin(M_PI), 60.0*t*sin(M_PI) + 60.0*(3 - t*t)*cos(M_PI)) + center, Bul_Small, Bul_WaterBlue, 1, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
		}
		this->isetBullet->isetBossBullet(center, Bul_Small, Bul_WaterBlue, 71, this->isetBullet, this->igetPlayerPosition, -3.0, 0.02, M_PI * 3 / 2, 0.0, 150);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_16//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_16::BossAttack_7_16(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 6000;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 4000;
	this->attackName = "ナトリウムが実に面白い";
	this->initialPosition = Point(258, 80);
}

void BossAttack_7_16::move(){
	this->count++;

	int t = this->count % 600;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 80), Point(466, 85));
		this->pos_x[0] = this->moveTo.x;
	}
	else if (t < 30){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 29));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else if (t == 30){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = Point(this->igetPlayerPosition->igetPosition().x, 80.0);
		this->pos_x[1] = this->moveTo.x;
	}
	else if (t < 60){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t-30, 29));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else if (t == 60){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 80), Point(466, 85));
		this->pos_x[2] = this->moveTo.x;
	}
	else if (t < 90){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t-60, 29));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else if (t == 90){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = Point(258.0, 80.0);
	}
	else if (t < 150){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t-90, 59));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_7_16::attack(){
	int t = this->count % 600;
	if ((t > 20) && (t < 100)){
		if (t % 30 == 0){
			for (int i = 0; i < 8; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Gun, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 4.0 + 0.5*i, 0.0, M_PI / 2, 0.0);
			}
		}
	}

	if ((t > 180) && (t < 480)){
		if (t > 240){
			if (t % 15 == 0){
				for (int i = 0; i < 3; i++) this->isetLazer->isetEnemyLazer(Point(this->pos_x[0] - 20 + GetRand(40), GAME_WINDOW_HEIGHT), Bul_Green, 1, 15, 6.0, 0.04, M_PI * 3 / 2, 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[0], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[0], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), M_PI);
			}
			if (t < 320){
				if (t % 10 == 0){
					BezierInfo info;
					info.arriveTime = 100;
					info.start = Point(this->pos_x[0], GAME_WINDOW_HEIGHT);
					info.end = this->igetPlayerPosition->igetPosition();
					info.control1 = Point(GetRand(GAME_WINDOW_WIDTH), 50.0+GetRand(100));
					this->isetLazer->isetEnemyLazerBezier(info, Bul_Blue, 10);
				}
			}
		}
		if (t % 10 == 0){
			for (int i = 0; i < 8; i++) this->isetBullet->isetBossBullet(Point(this->pos_x[0], GAME_WINDOW_HEIGHT), Bul_Middle, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0 + GetRand(70) / 10, 0.02, M_PI*GetRand(60) / 180 + M_PI * 240 / 180, 0.0);
		}
	}
	if ((t > 240) && (t < 540)){
		if (t > 300){
			if (t % 15 == 0){
				for (int i = 0; i < 3; i++) this->isetLazer->isetEnemyLazer(Point(this->pos_x[1] - 20 + GetRand(40), GAME_WINDOW_HEIGHT), Bul_Green, 1, 15, 6.0, 0.04, M_PI * 3 / 2, 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[1], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[1], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), M_PI);
			}
			if (t < 380){
				if (t % 10 == 0){
					BezierInfo info;
					info.arriveTime = 100;
					info.start = Point(this->pos_x[0], GAME_WINDOW_HEIGHT);
					info.end = this->igetPlayerPosition->igetPosition();
					info.control1 = Point(GetRand(GAME_WINDOW_WIDTH), 50.0+GetRand(100));
					this->isetLazer->isetEnemyLazerBezier(info, Bul_Blue, 10);
				}
			}
		}
		if (t % 10 == 0){
			for (int i = 0; i < 8; i++) this->isetBullet->isetBossBullet(Point(this->pos_x[1], GAME_WINDOW_HEIGHT), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 2.0 + GetRand(70) / 10, 0.02, M_PI*GetRand(60) / 180 + M_PI * 240 / 180, 0.0);
		}
	}
	if ((t > 300) && (t < 600)){
		if (t > 360){
			if (t % 15 == 0){
				for (int i = 0; i < 3; i++) this->isetLazer->isetEnemyLazer(Point(this->pos_x[2] - 20 + GetRand(40), GAME_WINDOW_HEIGHT), Bul_Green, 1, 15, 6.0, 0.04, M_PI * 3 / 2, 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[2], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), 0.0);
				this->isetLazer->isetEnemyLazer(Point(this->pos_x[2], GAME_WINDOW_HEIGHT), Bul_Yellow, 5, 15, 8.0, 0.0, M_PI * 3 / 2, M_PI / 60, 20, 20.0 + GetRand(50), M_PI);
			}
			if (t < 440){
				if (t % 10 == 0){
					BezierInfo info;
					info.arriveTime = 100;
					info.start = Point(this->pos_x[0], GAME_WINDOW_HEIGHT);
					info.end = this->igetPlayerPosition->igetPosition();
					info.control1 = Point(GetRand(GAME_WINDOW_WIDTH), 50.0+GetRand(100));
					this->isetLazer->isetEnemyLazerBezier(info, Bul_Blue, 10);
				}
			}
		}
		if (t % 10 == 0){
			for (int i = 0; i < 8; i++) this->isetBullet->isetBossBullet(Point(this->pos_x[2], GAME_WINDOW_HEIGHT), Bul_Middle, Bul_Orange, 1, this->isetBullet, this->igetPlayerPosition, 2.0 + GetRand(70) / 10, 0.02, M_PI*GetRand(60) / 180 + M_PI * 240 / 180, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_17//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_17::BossAttack_7_17(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1800;
	this->attackName = "サークルメイズ";
	this->initialPosition = Point(258, 150);
}

void BossAttack_7_17::move(){
	this->count++;
	int t = this->count % 500;

	if (t<450){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 450){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(80, Point(60, 50), Point(456, 150));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 450, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_7_17::attack(){
	int t = this->count % 500;

	if (t == 0){
		this->tmp_rad = M_PI*GetRand(360) / 180;
	}
	else if (t < 450){
		if (t % 20 < 15){
			for (int i = 0; i < 5; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 2 + M_PI * sin(this->tmp_rad) + M_PI * 2 * i / 5, 0.0);
			}
		}
		this->tmp_rad += M_PI / 180;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_7_18//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_7_18::BossAttack_7_18(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, ISetEnemyLazer* isetLazer, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, isetLazer, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 2000;
	this->HP_Max_Absorb = 2200;
	this->limitTime = 3600;
	this->attackName = "今宵星が見えずとも";
	this->initialPosition = Point(258, 220);
}

void BossAttack_7_18::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_7_18::attack(){
	int t = this->count % 800;
	if (t == 0){
		double rad = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		double theta;
		for (int i = 0; i < 6; i++){
			theta = rad + M_PI * 2 * i / 6;
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Large, Bul_White, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, theta, 0.0);
			if (cos(theta) > 0){
				if (sin(theta) > 0){
					//1
					if (((-this->igetBossPosition->igetPosition().x + GAME_WINDOW_WIDTH) / (4.0*cos(theta))) < ((-this->igetBossPosition->igetPosition().y + GAME_WINDOW_HEIGHT) / (4.0*sin(theta)))){
						this->time[i] = (-this->igetBossPosition->igetPosition().x + GAME_WINDOW_WIDTH) / (4.0*cos(theta));
						this->direction[i] = 2;
						this->pos[i] = Point(GAME_WINDOW_WIDTH, this->igetBossPosition->igetPosition().y + 4.0*sin(theta)*this->time[i]);
					}
					else{
						this->time[i] = (-this->igetBossPosition->igetPosition().y + GAME_WINDOW_HEIGHT) / (4.0*sin(theta));
						this->direction[i] = 3;
						this->pos[i] = Point(this->igetBossPosition->igetPosition().x + 4.0*cos(theta)*this->time[i], GAME_WINDOW_HEIGHT);
					}
				}
				else{
					//4
					if (((-this->igetBossPosition->igetPosition().x + GAME_WINDOW_WIDTH) / (4.0*cos(theta))) < (this->igetBossPosition->igetPosition().y / (-4.0*sin(theta)))){
						this->time[i] = (-this->igetBossPosition->igetPosition().x + GAME_WINDOW_WIDTH) / (4.0*cos(theta));
						this->direction[i] = 2;
						this->pos[i] = Point(GAME_WINDOW_WIDTH, this->igetBossPosition->igetPosition().y + 4.0*sin(theta)*this->time[i]);
					}
					else{
						this->time[i] = (this->igetBossPosition->igetPosition().y / (-4.0*sin(theta)));
						this->direction[i] = 1;
						this->pos[i] = Point(this->igetBossPosition->igetPosition().x + 4.0*cos(theta)*this->time[i], 0);
					}
				}
			}
			else{
				if (sin(theta) > 0){
					//2
					if ((this->igetBossPosition->igetPosition().x / (-4.0*cos(theta))) < ((-this->igetBossPosition->igetPosition().y + GAME_WINDOW_HEIGHT) / (4.0*sin(theta)))){
						this->time[i] = (this->igetBossPosition->igetPosition().x / (-4.0*cos(theta)));
						this->direction[i] = 0;
						this->pos[i] = Point(0, this->igetBossPosition->igetPosition().y + 4.0*sin(theta)*this->time[i]);
					}
					else{
						this->time[i] = (-this->igetBossPosition->igetPosition().y + GAME_WINDOW_HEIGHT) / (4.0*sin(theta));
						this->direction[i] = 3;
						this->pos[i] = Point(this->igetBossPosition->igetPosition().x + 4.0*cos(theta)*this->time[i], GAME_WINDOW_HEIGHT);
					}
				}
				else{
					//3
					if ((this->igetBossPosition->igetPosition().x / (-4.0*cos(theta))) < (this->igetBossPosition->igetPosition().y / (-4.0*sin(theta)))){
						this->time[i] = (this->igetBossPosition->igetPosition().x / (-4.0*cos(theta)));
						this->direction[i] = 0;
						this->pos[i] = Point(0, this->igetBossPosition->igetPosition().y + 4.0*sin(theta)*this->time[i]);
					}
					else{
						this->time[i] = (this->igetBossPosition->igetPosition().y / (-4.0*sin(theta)));
						this->direction[i] = 1;
						this->pos[i] = Point(this->igetBossPosition->igetPosition().x + 4.0*cos(theta)*this->time[i], 0);
					}
				}
			}
		}
	}

	if (t < 500){
		//
	}
	else if (t < 700){
		if (t % 10 == 0){
			BezierInfo info;
			info.arriveTime = 80;
			info.start = this->igetBossPosition->igetPosition();
			info.end = this->igetPlayerPosition->igetPosition();
			info.control1 = Point(GetRand(GAME_WINDOW_WIDTH*2)-GAME_WINDOW_WIDTH/2, GetRand(300)-200);
			this->isetLazer->isetEnemyLazerBezier(info, Bul_Green, 15);
		}
	}

	if (t % 20 == 0){
		for (int i = 0; i < 6; i++){
			if (t < this->time[i]) continue;
			
			if (t < this->time[i] + 200){
				this->isetLazer->isetEnemyLazer(this->pos[i], (BulletColor)GetRand(6), 5, 15, 4.0, 0.0, M_PI*this->direction[i] / 2 + M_PI*GetRand(60) / 180 - M_PI / 6, M_PI / 60, 20, 20.0 + GetRand(40));
			}
			if (t < this->time[i] + 450){
				this->isetBullet->isetBossBullet(this->pos[i], Bul_SmallStar, (BulletColor)GetRand(6), 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI*this->direction[i] / 2 + M_PI*GetRand(120) / 180 - M_PI / 3, 0.0);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////