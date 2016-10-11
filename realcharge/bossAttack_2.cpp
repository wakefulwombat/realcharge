#include "bossAttack_2.h"
#include "DxLib.h"

////BossAttack_2_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_1_Easy::BossAttack_2_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 700;
	this->limitTime = 1300;
	this->attackName = "きれいな花が咲きました";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_1_Easy::move(){
	this->count++;
	int t = this->count % 420;

	if (t < 320){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 320){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else {
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 320), 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_2_1_Easy::attack(){
	int t = this->count % 420;

	if (t < 60){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 + M_PI*t / 150, 0.0);
			}
		}
	}
	else if (t < 120){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 - M_PI*(t - 60) / 150, 0.0);
			}
		}
	}
	else if (t < 180){
		//none
	}
	else if (t < 210){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 + M_PI*(t - 180) / 150, 0.0);
			}
		}
	}
	else if (t < 240){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 - M_PI*(t - 210) / 150, 0.0);
			}
		}
	}
	else if (t < 270){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 + M_PI*(t - 180) / 240, 0.0);
			}
		}
	}
	else if (t < 300){
		if (t % 6 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 14 - M_PI*(t - 270) / 150, 0.0);
			}
		}
	}
}

BossAttack_2_1_Normal::BossAttack_2_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2500;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1500;
	this->attackName = "きれいな花が咲きました";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_1_Normal::move(){
	this->count++;
	int t = this->count % 420;

	if (t < 320){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 320){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else {
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 320), 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_2_1_Normal::attack(){
	int t = this->count % 420;

	if (t < 60){
		if (t % 60 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*t / 150, 0.0);
			}
		}
	}
	else if (t < 120){
		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 60) / 150, 0.0);
			}
		}
	}
	else if (t < 180){
		//none
	}
	else if (t < 210){
		if (t % 60 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 2; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*(t - 180) / 150, 0.0);
			}
		}
	}
	else if (t < 240){
		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 210) / 150, 0.0);
			}
		}
	}
	else if (t < 270){
		if (t % 60 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 5; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*(t - 180) / 240, 0.0);
			}
		}
	}
	else if (t < 300){
		if (t % 6 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 270) / 150, 0.0);
			}
		}
	}
}

BossAttack_2_1_Hard::BossAttack_2_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 4000;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 1500;
	this->attackName = "きれいな花が咲きました";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_1_Hard::move(){
	this->count++;
	int t = this->count % 420;

	if (t < 320){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 320){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else {
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, (t - 320), 80));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_2_1_Hard::attack(){
	int t = this->count % 420;

	if (t < 60){
		if (t % 20 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 5; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*t / 150, 0.0);
			}
		}
	}
	else if (t < 120){
		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 60) / 150, 0.0);
			}
		}
	}
	else if (t < 180){
		//none
	}
	else if (t < 210){
		if (t % 20 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 5; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*(t - 180) / 150, 0.0);
			}
		}
	}
	else if (t < 240){
		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 210) / 150, 0.0);
			}
		}
	}
	else if (t < 270){
		if (t % 20 == 1){
			double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
			for (int way = 0; way < 5; way++){
				for (int line = 0; line < 5; line++){
					this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_White, 0, this->isetBullet, this->igetPlayerPosition,
						0.7*line + 1.0, 0.02, angle + M_PI*way / 6 - M_PI / 3, 0.0);
				}
			}
		}

		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 + M_PI*(t - 180) / 240, 0.0);
			}
		}
	}
	else if (t < 300){
		if (t % 4 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition,
					2.0, 0.0, M_PI*2.0*i / 20 - M_PI*(t - 270) / 150, 0.0);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_2_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_2_Easy::BossAttack_2_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 70;
	this->HP_Max_Stand = 140;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1000;
	this->attackName = "トイレで跳ね返るアレ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_2_Easy::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_2_2_Easy::attack(){
	int t = this->count % 20;

	if (t == 0){
		this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.04, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0, 20);
	}
	if (t == 10){
		this->isetBullet->isetBossBullet(Point(-40.0, 1.0*GetRand(GAME_WINDOW_HEIGHT) - 80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI / 8 + M_PI*GetRand(10) / 180, 0.0, 20);
		this->isetBullet->isetBossBullet(Point(556.2, 1.0*GetRand(GAME_WINDOW_HEIGHT) - 80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 7 / 8 - M_PI*GetRand(10) / 180, 0.0, 20);
	}

	if (this->count > 100){
		if (t == 0){
			this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), 622.0), Bul_Crystal, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 3.0, 0.02, M_PI * 3 / 2 + M_PI*GetRand(10) / 180 - M_PI * 5 / 180, 0.0, 20);
		}
	}
}

BossAttack_2_2_Normal::BossAttack_2_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 120;
	this->HP_Max_Stand = 250;
	this->HP_Max_Absorb = 700;
	this->limitTime = 1000;
	this->attackName = "トイレで跳ね返るアレ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_2_Normal::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_2_2_Normal::attack(){
	int t = this->count % 12;

	if (t == 0){
		this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.04, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0, 20);
	}
	if (t == 6){
		this->isetBullet->isetBossBullet(Point(-40.0, 1.0*GetRand(GAME_WINDOW_HEIGHT) - 80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI / 8 + M_PI*GetRand(10) / 180, 0.0, 20);
		this->isetBullet->isetBossBullet(Point(556.2, 1.0*GetRand(GAME_WINDOW_HEIGHT) - 80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 7 / 8 - M_PI*GetRand(10) / 180, 0.0, 20);
	}

	if (this->count > 100){
		if (t == 0){
			this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), 622.0), Bul_Crystal, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 3.0, 0.02, M_PI * 3 / 2 + M_PI*GetRand(10) / 180 - M_PI * 5 / 180, 0.0, 20);
		}
	}
}

BossAttack_2_2_Hard::BossAttack_2_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 320;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "トイレで跳ね返るアレ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_2_Hard::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_2_2_Hard::attack(){
	int t = this->count % 4;

	if (t == 0){
		this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), -40.0), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.05, M_PI / 4 + M_PI*GetRand(90) / 180, 0.0, 20);
	}
	if (t == 2){
		this->isetBullet->isetBossBullet(Point(-40.0, 1.0*GetRand(GAME_WINDOW_HEIGHT)-80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.03, M_PI / 8 + M_PI*GetRand(10) / 180, 0.0, 20);
		this->isetBullet->isetBossBullet(Point(556.2, 1.0*GetRand(GAME_WINDOW_HEIGHT)-80), Bul_Oval, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0, 0.03, M_PI*7 / 8 - M_PI*GetRand(10) / 180, 0.0, 20);
	}

	if (this->count > 100){
		if (t == 0){
			this->isetBullet->isetBossBullet(Point(1.0*GetRand(GAME_WINDOW_WIDTH), 622.0), Bul_Crystal, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 4.0, 0.02, M_PI *3/ 2 + M_PI*GetRand(10) / 180 - M_PI*5/180, 0.0, 20);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_2_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_3_Easy::BossAttack_2_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 180;
	this->HP_Max_Absorb = 500;
	this->limitTime = 1400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_3_Easy::move(){
	this->count++;

	int t = (this->count % (50 + 200));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_3_Easy::attack(){
	int t = this->count % 500;

	if (t < 50){

	}
	else if (t < 250){
		if (t % 20 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 6 + M_PI * 5.8 * (t - 50) / 180, M_PI*0.15 / 180);
			}
		}
		if (t % 24 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 7 - M_PI * 4.2 * (t - 50) / 180, -M_PI*0.2 / 180);
			}
		}
	}
	else if (t < 300){

	}
	else if (t < 500){
		if (t % 20 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 6 - M_PI * 5.8 * (t - 700) / 180, -M_PI*0.15 / 180);
			}
		}
		if (t % 24 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 7 + M_PI * 4.2 * (t - 700) / 180, M_PI*0.2 / 180);
			}
		}
	}
}

BossAttack_2_3_Normal::BossAttack_2_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 450;
	this->HP_Max_Absorb = 900;
	this->limitTime = 1400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_3_Normal::move(){
	this->count++;

	int t = (this->count % (50 + 200));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_3_Normal::attack(){
	int t = this->count % 500;

	if (t < 50){

	}
	else if (t < 250){
		if (t % 5 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 6 + M_PI * 5.8 * (t - 50) / 180, M_PI*0.15 / 180);
			}
		}
		if (t % 6 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 7 + M_PI * 4.2 * (t - 50) / 180, -M_PI*0.2 / 180);
			}
		}
	}
	else if (t < 300){

	}
	else if (t < 500){
		if (t % 5 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 6 - M_PI * 5.8 * (t - 700) / 180, -M_PI*0.15 / 180);
			}
		}
		if (t % 6 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 7 - M_PI * 4.2 * (t - 700) / 180, M_PI*0.2 / 180);
			}
		}
	}
}

BossAttack_2_3_Hard::BossAttack_2_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1400;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1100;
	this->limitTime = 1400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_3_Hard::move(){
	this->count++;

	int t = (this->count % (50 + 600));
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_3_Hard::attack(){
	int t = this->count % 1300;

	if (t < 50){

	}
	else if (t < 650){
		if (t % 5 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 6 + M_PI * 5.8 * (t-50) / 180, M_PI*0.15 / 180);
			}
		}
		if (t % 6 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle + M_PI*2.0*way / 7 + M_PI * 4.2 * (t-50) / 180, -M_PI*0.2 / 180);
			}
		}
	}
	else if (t < 700){

	}
	else if (t < 1300){
		if (t % 5 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 6 - M_PI * 5.8 * (t - 700) / 180, -M_PI*0.15 / 180);
			}
		}
		if (t % 6 == 2){
			for (int way = 0; way < 7; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Blue, 3, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0,
					this->angle - M_PI*2.0*way / 7 - M_PI * 4.2 * (t - 700) / 180, M_PI*0.2 / 180);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_2_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_4_Easy::BossAttack_2_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 2400;
	this->attackName = "ドッチビーで大乱闘したらこうなる";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_4_Easy::move(){
	this->count++;

	int t = (this->count % (50 + 550));
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

void BossAttack_2_4_Easy::attack(){
	int t = this->count % 600;

	if (t < 50){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t < 300){
		if (t % 12 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(30.0*cos(M_PI*way / 4), 30.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle + M_PI*8.5 * (t - 50) / 180, M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(30.0*cos(M_PI*way / 3), 30.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle + M_PI*12.5 * (t - 50) / 180, M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
	else if (t < 350){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else{
		if (t % 12 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(30.0*cos(M_PI*way / 4), 30.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle - M_PI*8.5 * (t - 350) / 180, -M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(30.0*cos(M_PI*way / 3), 30.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle - M_PI*12.5 * (t - 350) / 180, -M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
}

BossAttack_2_4_Normal::BossAttack_2_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1100;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1100;
	this->limitTime = 2400;
	this->attackName = "ドッチビーで大乱闘したらこうなる";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_4_Normal::move(){
	this->count++;

	int t = (this->count % (50 + 550));
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

void BossAttack_2_4_Normal::attack(){
	int t = this->count % 1200;

	if (t < 50){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t < 600){
		if (t % 8 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 4), 50.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle + M_PI*6.5 * (t - 50) / 180, M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 3), 50.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle + M_PI*9.5 * (t - 50) / 180, M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
	else if (t < 650){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else{
		if (t % 8 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 4), 50.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle - M_PI*6.5 * (t - 650) / 180, -M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 3), 50.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle - M_PI*9.5 * (t - 650) / 180, -M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
}

BossAttack_2_4_Hard::BossAttack_2_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1400;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1700;
	this->limitTime = 2400;
	this->attackName = "ドッチビーで大乱闘したらこうなる";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_4_Hard::move(){
	this->count++;

	int t = (this->count % (50 + 550));
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

void BossAttack_2_4_Hard::attack(){
	int t = this->count % 1200;

	if (t < 50){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else if (t < 600){
		if (t % 6 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 4), 50.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle + M_PI*7.0 * (t - 50) / 180, M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 3), 50.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle + M_PI*8.5 * (t - 50) / 180, M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
	else if (t < 650){
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
	}
	else{
		if (t % 6 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 4), 50.0*sin(M_PI*way / 4)), Bul_Middle, Bul_Purple, 50, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle - M_PI*7.0 * (t - 650) / 180, -M_PI / 180, 100, M_PI*way / 4);
			}
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition() + Point(50.0*cos(M_PI*way / 3), 50.0*sin(M_PI*way / 3)), Bul_Middle, Bul_Blue, 50, this->isetBullet, this->igetPlayerPosition
					, 3.5, 0.0, this->angle - M_PI*8.5 * (t - 650) / 180, -M_PI * 0.5 / 180, 100, M_PI*way / 3);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_2_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_5_Easy::BossAttack_2_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 80;
	this->HP_Max_Stand = 150;
	this->HP_Max_Absorb = 500;
	this->limitTime = 1200;
	this->attackName = "親方！空から星屑が！";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_5_Easy::move(){
	this->count++;

	int t = (this->count % 300);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if(t < 100){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_5_Easy::attack(){
	if (this->count % 10 == 0){
		this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH * 3 / 4), -40.0), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
		this->isetBullet->isetBossBullet(Point(556.0, GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 4) - GAME_WINDOW_WIDTH / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 3.0 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
		this->isetBullet->isetBossBullet(Point(556.0, GetRand(GAME_WINDOW_HEIGHT * 3 / 4) + GAME_WINDOW_HEIGHT / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
	}
	
}

BossAttack_2_5_Normal::BossAttack_2_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 160;
	this->HP_Max_Stand = 120;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1500;
	this->attackName = "親方！空から流れ星が！";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_5_Normal::move(){
	this->count++;

	int t = (this->count % 300);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t < 100){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_5_Normal::attack(){
	int t = this->count % 400;

	if (t < 200){
		if (t % 10 == 0){
			this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH * 3 / 4), -40.0), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.5 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(556.0, GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 4) - GAME_WINDOW_WIDTH / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 3.5 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(556.0, GetRand(GAME_WINDOW_HEIGHT * 3 / 4) + GAME_WINDOW_HEIGHT / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.5 + 1.0*GetRand(20) / 10, 0.0, M_PI * 3 / 4, 0.0);
		}
	}
	else{
		if (t % 10 == 0){
			this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH * 3 / 4) + GAME_WINDOW_WIDTH / 4, -40.0), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.5 + 1.0*GetRand(20) / 10, 0.0, M_PI / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(-40.0, GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 4) - GAME_WINDOW_WIDTH / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 3.5 + 1.0*GetRand(20) / 10, 0.0, M_PI / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(-40.0, GetRand(GAME_WINDOW_HEIGHT * 3 / 4) + GAME_WINDOW_HEIGHT / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.5 + 1.0*GetRand(20) / 10, 0.0, M_PI / 4, 0.0);
		}
	}
}

BossAttack_2_5_Hard::BossAttack_2_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 150;
	this->HP_Max_Stand = 120;
	this->HP_Max_Absorb = 700;
	this->limitTime = 1200;
	this->attackName = "親方！空から流星群が！";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_5_Hard::move(){
	this->count++;

	int t = (this->count % 300);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t < 100){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_5_Hard::attack(){
	int t = this->count % 600;

	if (t < 300){
		if (t % 5 == 0){
			this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH*3/4),-40.0), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 5.5 + 1.0*GetRand(20)/10, 0.0, M_PI * 3 / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(556.0, GetRand((GAME_WINDOW_WIDTH+GAME_WINDOW_HEIGHT)/4)-GAME_WINDOW_WIDTH/4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.5 + 1.0*GetRand(20)/10, 0.0, M_PI * 3 / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(556.0, GetRand(GAME_WINDOW_HEIGHT * 3 / 4) + GAME_WINDOW_HEIGHT / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 3.5 + 1.0*GetRand(20)/10, 0.0, M_PI * 3 / 4, 0.0);
		}
	}
	else{
		if (t % 5 == 0){
			this->isetBullet->isetBossBullet(Point(GetRand(GAME_WINDOW_WIDTH * 3 / 4) + GAME_WINDOW_WIDTH/4, -40.0), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 5.5 + 1.0*GetRand(20)/10, 0.0, M_PI / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(-40.0, GetRand((GAME_WINDOW_WIDTH + GAME_WINDOW_HEIGHT) / 4) - GAME_WINDOW_WIDTH / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.5 + 1.0*GetRand(20)/10, 0.0, M_PI / 4, 0.0);
			this->isetBullet->isetBossBullet(Point(-40.0, GetRand(GAME_WINDOW_HEIGHT * 3 / 4) + GAME_WINDOW_HEIGHT / 4), Bul_LargeStar, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 3.5 + 1.0*GetRand(20)/10, 0.0, M_PI / 4, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_2_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_2_6_Easy::BossAttack_2_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 250;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 3700;
	this->attackName = "パチモンクオリティ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_6_Easy::move(){
	this->count++;

	int t = this->count % 1250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		this->omega = -M_PI * 2;
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_6_Easy::attack(){
	int t = this->count % 1250;

	if (t > 50){
		if (t % 4 == 0){
			for (int way = 0; way < 5; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Gun, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle + M_PI * 2 * way / 5, 0.0);
			}
		}
		this->angle += this->omega;
		this->omega += M_PI * 4 / 36000;
	}
}

BossAttack_2_6_Normal::BossAttack_2_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1500;
	this->HP_Max_Stand = 350;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 3700;
	this->attackName = "パチモンクオリティ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_6_Normal::move(){
	this->count++;

	int t = this->count % 1250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		this->omega = -M_PI * 2;
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_6_Normal::attack(){
	int t = this->count % 1250;

	if (t > 50){
		if (t % 3 == 0){
			for (int way = 0; way < 6; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Gun, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, this->angle + M_PI * 2 * way / 6, 0.0);
			}
		}
		this->angle += this->omega;
		this->omega += M_PI * 4 / 36000;
	}
}

BossAttack_2_6_Hard::BossAttack_2_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1800;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 3700;
	this->attackName = "パチモンクオリティ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_2_6_Hard::move(){
	this->count++;

	int t = this->count % 1250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(50, 50), Point(466, 180));
		this->angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		this->omega = -M_PI * 2;
	}
	else if (t <= 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_2_6_Hard::attack(){
	int t = this->count % 1250;
	
	if (t > 50){
		if (t % 3 == 0){
			for (int way = 0; way < 8; way++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Gun, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition
					, 4.0, 0.0, this->angle + M_PI * 2 * way / 8, 0.0);
			}
		}
		this->angle += this->omega;
		this->omega += M_PI * 4 / 36000;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
