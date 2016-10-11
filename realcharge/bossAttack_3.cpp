#include "bossAttack_3.h"
#include "DxLib.h"

////BossAttack_3_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_1_Easy::BossAttack_3_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 120;
	this->HP_Max_Stand = 120;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_1_Easy::move(){
	this->count++;

	int t = (this->count % 80);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 50), Point(416, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 70));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_1_Easy::attack(){
	int t = this->count % 800;

	if (t == 0){
		this->pos[0] = this->igetBossPosition->igetPosition();
		this->angle[0] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[0] < M_PI / 4) || (this->angle[0] > M_PI * 3 / 2)) this->angle[0] = M_PI / 4;
		if ((this->angle[0] > M_PI * 3 / 4) && (this->angle[0] < M_PI * 3 / 2)) this->angle[0] = M_PI * 3 / 4;
	}
	if ((t >= 0) && (t <= 180)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[0] + M_PI / 2), 104.0*i*sin(this->angle[0] + M_PI / 2)) + this->pos[0], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[0], 0.0, 100);
			}
		}
	}

	if (t == 60){
		this->pos[1] = this->igetBossPosition->igetPosition();
		this->angle[1] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[1] < M_PI / 4) || (this->angle[1] > M_PI * 3 / 2)) this->angle[1] = M_PI / 4;
		if ((this->angle[1] > M_PI * 3 / 4) && (this->angle[1] < M_PI * 3 / 2)) this->angle[1] = M_PI * 3 / 4;
	}
	if ((t >= 60) && (t <= 240)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[1] + M_PI / 2), 104.0*i*sin(this->angle[1] + M_PI / 2)) + this->pos[1], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[1], 0.0, 100);
			}
		}
	}

	if (t == 120){
		this->pos[2] = this->igetBossPosition->igetPosition();
		this->angle[2] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[2] < M_PI / 4) || (this->angle[2] > M_PI * 3 / 2)) this->angle[2] = M_PI / 4;
		if ((this->angle[2] > M_PI * 3 / 4) && (this->angle[2] < M_PI * 3 / 2)) this->angle[2] = M_PI * 3 / 4;
	}
	if ((t >= 120) && (t <= 300)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[2] + M_PI / 2), 104.0*i*sin(this->angle[2] + M_PI / 2)) + this->pos[2], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[2], 0.0, 100);
			}
		}
	}

	if (t == 180){
		this->pos[3] = this->igetBossPosition->igetPosition();
		this->angle[3] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[3] < M_PI / 4) || (this->angle[3] > M_PI * 3 / 2)) this->angle[3] = M_PI / 4;
		if ((this->angle[3] > M_PI * 3 / 4) && (this->angle[3] < M_PI * 3 / 2)) this->angle[3] = M_PI * 3 / 4;
	}
	if ((t >= 180) && (t <= 360)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[3] + M_PI / 2), 104.0*i*sin(this->angle[3] + M_PI / 2)) + this->pos[3], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[3], 0.0, 100);
			}
		}
	}

	if (t == 240){
		this->pos[4] = this->igetBossPosition->igetPosition();
		this->angle[4] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[4] < M_PI / 4) || (this->angle[4] > M_PI * 3 / 2)) this->angle[4] = M_PI / 4;
		if ((this->angle[4] > M_PI * 3 / 4) && (this->angle[4] < M_PI * 3 / 2)) this->angle[4] = M_PI * 3 / 4;
	}
	if ((t >= 240) && (t <= 420)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[4] + M_PI / 2), 104.0*i*sin(this->angle[4] + M_PI / 2)) + this->pos[4], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[4], 0.0, 100);
			}
		}
	}

	if (t == 300){
		this->pos[5] = this->igetBossPosition->igetPosition();
		this->angle[5] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[5] < M_PI / 4) || (this->angle[5] > M_PI * 3 / 2)) this->angle[5] = M_PI / 4;
		if ((this->angle[5] > M_PI * 3 / 4) && (this->angle[5] < M_PI * 3 / 2)) this->angle[5] = M_PI * 3 / 4;
	}
	if ((t >= 300) && (t <= 480)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[5] + M_PI / 2), 104.0*i*sin(this->angle[5] + M_PI / 2)) + this->pos[5], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[5], 0.0, 100);
			}
		}
	}

	if (t == 360){
		this->pos[6] = this->igetBossPosition->igetPosition();
		this->angle[6] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[6] < M_PI / 4) || (this->angle[6] > M_PI * 3 / 2)) this->angle[6] = M_PI / 4;
		if ((this->angle[6] > M_PI * 3 / 4) && (this->angle[6] < M_PI * 3 / 2)) this->angle[6] = M_PI * 3 / 4;
	}
	if ((t >= 360) && (t <= 540)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[6] + M_PI / 2), 104.0*i*sin(this->angle[6] + M_PI / 2)) + this->pos[6], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[6], 0.0, 100);
			}
		}
	}

	if (t == 420){
		this->pos[7] = this->igetBossPosition->igetPosition();
		this->angle[7] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[7] < M_PI / 4) || (this->angle[7] > M_PI * 3 / 2)) this->angle[7] = M_PI / 4;
		if ((this->angle[7] > M_PI * 3 / 4) && (this->angle[7] < M_PI * 3 / 2)) this->angle[7] = M_PI * 3 / 4;
	}
	if ((t >= 420) && (t <= 600)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[7] + M_PI / 2), 104.0*i*sin(this->angle[7] + M_PI / 2)) + this->pos[7], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[7], 0.0, 100);
			}
		}
	}

	if (t == 480){
		this->pos[8] = this->igetBossPosition->igetPosition();
		this->angle[8] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[8] < M_PI / 4) || (this->angle[8] > M_PI * 3 / 2)) this->angle[8] = M_PI / 4;
		if ((this->angle[8] > M_PI * 3 / 4) && (this->angle[8] < M_PI * 3 / 2)) this->angle[8] = M_PI * 3 / 4;
	}
	if ((t >= 480) && (t <= 660)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[8] + M_PI / 2), 104.0*i*sin(this->angle[8] + M_PI / 2)) + this->pos[8], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[8], 0.0, 100);
			}
		}
	}

	if (t == 540){
		this->pos[9] = this->igetBossPosition->igetPosition();
		this->angle[9] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[9] < M_PI / 4) || (this->angle[9] > M_PI * 3 / 2)) this->angle[9] = M_PI / 4;
		if ((this->angle[9] > M_PI * 3 / 4) && (this->angle[9] < M_PI * 3 / 2)) this->angle[9] = M_PI * 3 / 4;
	}
	if ((t >= 540) && (t <= 720)){
		if (t % 24 == 0){
			for (int i = -5; i <= 5; i++){
				this->isetBullet->isetBossBullet(Point(104.0*i*cos(this->angle[9] + M_PI / 2), 104.0*i*sin(this->angle[9] + M_PI / 2)) + this->pos[9], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[9], 0.0, 100);
			}
		}
	}
}

BossAttack_3_1_Normal::BossAttack_3_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 220;
	this->HP_Max_Stand = 420;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_1_Normal::move(){
	this->count++;

	int t = (this->count % 80);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 50), Point(416, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 70));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_1_Normal::attack(){
	int t = this->count % 800;

	if (t == 0){
		this->pos[0] = this->igetBossPosition->igetPosition();
		this->angle[0] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[0] < M_PI / 4) || (this->angle[0] > M_PI * 3 / 2)) this->angle[0] = M_PI / 4;
		if ((this->angle[0] > M_PI * 3 / 4) && (this->angle[0] < M_PI * 3 / 2)) this->angle[0] = M_PI * 3 / 4;
	}
	if ((t >= 0) && (t <= 180)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[0] + M_PI / 2), 84.0*i*sin(this->angle[0] + M_PI / 2)) + this->pos[0], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[0], 0.0, 100);
			}
		}
	}

	if (t == 60){
		this->pos[1] = this->igetBossPosition->igetPosition();
		this->angle[1] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[1] < M_PI / 4) || (this->angle[1] > M_PI * 3 / 2)) this->angle[1] = M_PI / 4;
		if ((this->angle[1] > M_PI * 3 / 4) && (this->angle[1] < M_PI * 3 / 2)) this->angle[1] = M_PI * 3 / 4;
	}
	if ((t >= 60) && (t <= 240)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[1] + M_PI / 2), 84.0*i*sin(this->angle[1] + M_PI / 2)) + this->pos[1], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[1], 0.0, 100);
			}
		}
	}

	if (t == 120){
		this->pos[2] = this->igetBossPosition->igetPosition();
		this->angle[2] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[2] < M_PI / 4) || (this->angle[2] > M_PI * 3 / 2)) this->angle[2] = M_PI / 4;
		if ((this->angle[2] > M_PI * 3 / 4) && (this->angle[2] < M_PI * 3 / 2)) this->angle[2] = M_PI * 3 / 4;
	}
	if ((t >= 120) && (t <= 300)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[2] + M_PI / 2), 84.0*i*sin(this->angle[2] + M_PI / 2)) + this->pos[2], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[2], 0.0, 100);
			}
		}
	}

	if (t == 180){
		this->pos[3] = this->igetBossPosition->igetPosition();
		this->angle[3] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[3] < M_PI / 4) || (this->angle[3] > M_PI * 3 / 2)) this->angle[3] = M_PI / 4;
		if ((this->angle[3] > M_PI * 3 / 4) && (this->angle[3] < M_PI * 3 / 2)) this->angle[3] = M_PI * 3 / 4;
	}
	if ((t >= 180) && (t <= 360)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[3] + M_PI / 2), 84.0*i*sin(this->angle[3] + M_PI / 2)) + this->pos[3], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[3], 0.0, 100);
			}
		}
	}

	if (t == 240){
		this->pos[4] = this->igetBossPosition->igetPosition();
		this->angle[4] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[4] < M_PI / 4) || (this->angle[4] > M_PI * 3 / 2)) this->angle[4] = M_PI / 4;
		if ((this->angle[4] > M_PI * 3 / 4) && (this->angle[4] < M_PI * 3 / 2)) this->angle[4] = M_PI * 3 / 4;
	}
	if ((t >= 240) && (t <= 420)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[4] + M_PI / 2), 84.0*i*sin(this->angle[4] + M_PI / 2)) + this->pos[4], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[4], 0.0, 100);
			}
		}
	}

	if (t == 300){
		this->pos[5] = this->igetBossPosition->igetPosition();
		this->angle[5] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[5] < M_PI / 4) || (this->angle[5] > M_PI * 3 / 2)) this->angle[5] = M_PI / 4;
		if ((this->angle[5] > M_PI * 3 / 4) && (this->angle[5] < M_PI * 3 / 2)) this->angle[5] = M_PI * 3 / 4;
	}
	if ((t >= 300) && (t <= 480)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[5] + M_PI / 2), 84.0*i*sin(this->angle[5] + M_PI / 2)) + this->pos[5], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[5], 0.0, 100);
			}
		}
	}

	if (t == 360){
		this->pos[6] = this->igetBossPosition->igetPosition();
		this->angle[6] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[6] < M_PI / 4) || (this->angle[6] > M_PI * 3 / 2)) this->angle[6] = M_PI / 4;
		if ((this->angle[6] > M_PI * 3 / 4) && (this->angle[6] < M_PI * 3 / 2)) this->angle[6] = M_PI * 3 / 4;
	}
	if ((t >= 360) && (t <= 540)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[6] + M_PI / 2), 84.0*i*sin(this->angle[6] + M_PI / 2)) + this->pos[6], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[6], 0.0, 100);
			}
		}
	}

	if (t == 420){
		this->pos[7] = this->igetBossPosition->igetPosition();
		this->angle[7] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[7] < M_PI / 4) || (this->angle[7] > M_PI * 3 / 2)) this->angle[7] = M_PI / 4;
		if ((this->angle[7] > M_PI * 3 / 4) && (this->angle[7] < M_PI * 3 / 2)) this->angle[7] = M_PI * 3 / 4;
	}
	if ((t >= 420) && (t <= 600)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[7] + M_PI / 2), 84.0*i*sin(this->angle[7] + M_PI / 2)) + this->pos[7], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[7], 0.0, 100);
			}
		}
	}

	if (t == 480){
		this->pos[8] = this->igetBossPosition->igetPosition();
		this->angle[8] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[8] < M_PI / 4) || (this->angle[8] > M_PI * 3 / 2)) this->angle[8] = M_PI / 4;
		if ((this->angle[8] > M_PI * 3 / 4) && (this->angle[8] < M_PI * 3 / 2)) this->angle[8] = M_PI * 3 / 4;
	}
	if ((t >= 480) && (t <= 660)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[8] + M_PI / 2), 84.0*i*sin(this->angle[8] + M_PI / 2)) + this->pos[8], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[8], 0.0, 100);
			}
		}
	}

	if (t == 540){
		this->pos[9] = this->igetBossPosition->igetPosition();
		this->angle[9] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[9] < M_PI / 4) || (this->angle[9] > M_PI * 3 / 2)) this->angle[9] = M_PI / 4;
		if ((this->angle[9] > M_PI * 3 / 4) && (this->angle[9] < M_PI * 3 / 2)) this->angle[9] = M_PI * 3 / 4;
	}
	if ((t >= 540) && (t <= 720)){
		if (t % 18 == 0){
			for (int i = -6; i <= 6; i++){
				this->isetBullet->isetBossBullet(Point(84.0*i*cos(this->angle[9] + M_PI / 2), 84.0*i*sin(this->angle[9] + M_PI / 2)) + this->pos[9], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[9], 0.0, 100);
			}
		}
	}
}

BossAttack_3_1_Hard::BossAttack_3_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 700;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_1_Hard::move(){
	this->count++;

	int t = (this->count % 80);
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 50), Point(416, 180));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 70));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_1_Hard::attack(){
	int t = this->count % 800;
	if (t % 12 != 0) return;

	if (t == 0){
		this->pos[0] = this->igetBossPosition->igetPosition();
		this->angle[0] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[0] < M_PI / 4) || (this->angle[0] > M_PI * 3 / 2)) this->angle[0] = M_PI / 4;
		if ((this->angle[0] > M_PI * 3 / 4) && (this->angle[0] < M_PI * 3 / 2)) this->angle[0] = M_PI * 3 / 4;
	}
	if ((t >= 0) && (t <= 180)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[0] + M_PI / 2), 64.0*i*sin(this->angle[0] + M_PI / 2)) + this->pos[0], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[0], 0.0, 100);
		}
	}

	if (t == 60){
		this->pos[1] = this->igetBossPosition->igetPosition();
		this->angle[1] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[1] < M_PI / 4) || (this->angle[1] > M_PI * 3 / 2)) this->angle[1] = M_PI / 4;
		if ((this->angle[1] > M_PI * 3 / 4) && (this->angle[1] < M_PI * 3 / 2)) this->angle[1] = M_PI * 3 / 4;
	}
	if ((t >= 60) && (t <= 240)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[1] + M_PI / 2), 64.0*i*sin(this->angle[1] + M_PI / 2)) + this->pos[1], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[1], 0.0, 100);
		}
	}

	if (t == 120){
		this->pos[2] = this->igetBossPosition->igetPosition();
		this->angle[2] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[2] < M_PI / 4) || (this->angle[2] > M_PI * 3 / 2)) this->angle[2] = M_PI / 4;
		if ((this->angle[2] > M_PI * 3 / 4) && (this->angle[2] < M_PI * 3 / 2)) this->angle[2] = M_PI * 3 / 4;
	}
	if ((t >= 120) && (t <= 300)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[2] + M_PI / 2), 64.0*i*sin(this->angle[2] + M_PI / 2)) + this->pos[2], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[2], 0.0, 100);
		}
	}

	if (t == 180){
		this->pos[3] = this->igetBossPosition->igetPosition();
		this->angle[3] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[3] < M_PI / 4) || (this->angle[3] > M_PI * 3 / 2)) this->angle[3] = M_PI / 4;
		if ((this->angle[3] > M_PI * 3 / 4) && (this->angle[3] < M_PI * 3 / 2)) this->angle[3] = M_PI * 3 / 4;
	}
	if ((t >= 180) && (t <= 360)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[3] + M_PI / 2), 64.0*i*sin(this->angle[3] + M_PI / 2)) + this->pos[3], Bul_Fuda, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[3], 0.0, 100);
		}
	}

	if (t == 240){
		this->pos[4] = this->igetBossPosition->igetPosition();
		this->angle[4] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[4] < M_PI / 4) || (this->angle[4] > M_PI * 3 / 2)) this->angle[4] = M_PI / 4;
		if ((this->angle[4] > M_PI * 3 / 4) && (this->angle[4] < M_PI * 3 / 2)) this->angle[4] = M_PI * 3 / 4;
	}
	if ((t >= 240) && (t <= 420)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[4] + M_PI / 2), 64.0*i*sin(this->angle[4] + M_PI / 2)) + this->pos[4], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[4], 0.0, 100);
		}
	}

	if (t == 300){
		this->pos[5] = this->igetBossPosition->igetPosition();
		this->angle[5] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[5] < M_PI / 4) || (this->angle[5] > M_PI * 3 / 2)) this->angle[5] = M_PI / 4;
		if ((this->angle[5] > M_PI * 3 / 4) && (this->angle[5] < M_PI * 3 / 2)) this->angle[5] = M_PI * 3 / 4;
	}
	if ((t >= 300) && (t <= 480)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[5] + M_PI / 2), 64.0*i*sin(this->angle[5] + M_PI / 2)) + this->pos[5], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[5], 0.0, 100);
		}
	}

	if (t == 360){
		this->pos[6] = this->igetBossPosition->igetPosition();
		this->angle[6] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[6] < M_PI / 4) || (this->angle[6] > M_PI * 3 / 2)) this->angle[6] = M_PI / 4;
		if ((this->angle[6] > M_PI * 3 / 4) && (this->angle[6] < M_PI * 3 / 2)) this->angle[6] = M_PI * 3 / 4;
	}
	if ((t >= 360) && (t <= 540)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[6] + M_PI / 2), 64.0*i*sin(this->angle[6] + M_PI / 2)) + this->pos[6], Bul_Fuda, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[6], 0.0, 100);
		}
	}

	if (t == 420){
		this->pos[7] = this->igetBossPosition->igetPosition();
		this->angle[7] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[7] < M_PI / 4) || (this->angle[7] > M_PI * 3 / 2)) this->angle[7] = M_PI / 4;
		if ((this->angle[7] > M_PI * 3 / 4) && (this->angle[7] < M_PI * 3 / 2)) this->angle[7] = M_PI * 3 / 4;
	}
	if ((t >= 420) && (t <= 600)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[7] + M_PI / 2), 64.0*i*sin(this->angle[7] + M_PI / 2)) + this->pos[7], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[7], 0.0, 100);
		}
	}

	if (t == 480){
		this->pos[8] = this->igetBossPosition->igetPosition();
		this->angle[8] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[8] < M_PI / 4) || (this->angle[8] > M_PI * 3 / 2)) this->angle[8] = M_PI / 4;
		if ((this->angle[8] > M_PI * 3 / 4) && (this->angle[8] < M_PI * 3 / 2)) this->angle[8] = M_PI * 3 / 4;
	}
	if ((t >= 480) && (t <= 660)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[8] + M_PI / 2), 64.0*i*sin(this->angle[8] + M_PI / 2)) + this->pos[8], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[8], 0.0, 100);
		}
	}

	if (t == 540){
		this->pos[9] = this->igetBossPosition->igetPosition();
		this->angle[9] = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		if ((this->angle[9] < M_PI / 4) || (this->angle[9] > M_PI * 3 / 2)) this->angle[9] = M_PI / 4;
		if ((this->angle[9] > M_PI * 3 / 4) && (this->angle[9] < M_PI * 3 / 2)) this->angle[9] = M_PI * 3 / 4;
	}
	if ((t >= 540) && (t <= 720)){
		for (int i = -7; i <= 7; i++){
			this->isetBullet->isetBossBullet(Point(64.0*i*cos(this->angle[9] + M_PI / 2), 64.0*i*sin(this->angle[9] + M_PI / 2)) + this->pos[9], Bul_Fuda, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 4.0, 0.0, this->angle[9], 0.0, 100);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_3_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_2_Easy::BossAttack_3_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 150;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "ハゲアンプ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_2_Easy::move(){
	this->count++;

	int t = this->count % 650;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_2_Easy::attack(){
	int t = this->count % 650;

	if (t < 50){
		//
	}
	else if (t < 150){
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI*(t - 50) / 100, 0.0);
		}
	}
	else if (t < 250){
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 - M_PI*(t - 150) / 100, 0.0);
		}
	}
	else if (t == 250){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 2; line++){
			for (int i = 0; i < 8; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 8, 0.0);
			}
		}
	}
	else if (t < 350){
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI*(t - 250) / 100, 0.0);
		}
	}
	else if (t < 450){
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 - M_PI*(t - 350) / 100, 0.0);
		}
	}
	else if (t == 450){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 2; line++){
			for (int i = 0; i < 8; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 8, 0.0);
			}
		}
	}
	else if (t < 550){
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI*(t - 450) / 100, 0.0);
		}
	}
	else {
		if (t % 14 == 0){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI * 2 - M_PI*(t - 550) / 100, 0.0);
		}
	}
}

BossAttack_3_2_Normal::BossAttack_3_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1800;
	this->attackName = "ヘッドリフレクショナルオペアンプ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_2_Normal::move(){
	this->count++;

	int t = this->count % 650;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_2_Normal::attack(){
	int t = this->count % 650;

	if (t < 50){
		//
	}
	else if (t < 150){
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 50) / 100, 0.0);
			}
		}
	}
	else if (t < 250){
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 150) / 100, 0.0);
			}
		}
	}
	else if (t == 250){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 2; line++){
			for (int i = 0; i < 8; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 8, 0.0);
			}
		}
	}
	else if (t < 350){
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 250) / 100, 0.0);
			}
		}
	}
	else if (t < 450){
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 350) / 100, 0.0);
			}
		}
	}
	else if (t == 450){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 2; line++){
			for (int i = 0; i < 8; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 8, 0.0);
			}
		}
	}
	else if (t < 550){
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 450) / 100, 0.0);
			}
		}
	}
	else {
		if (t % 14 == 0){
			for (int line = 0; line < 2; line++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 550) / 100, 0.0);
			}
		}
	}
}

BossAttack_3_2_Hard::BossAttack_3_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 900;
	this->limitTime = 1800;
	this->attackName = "ヘッドリフレクショナルオペアンプ";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_2_Hard::move(){
	this->count++;

	int t = this->count % 650;
	if (t==0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_2_Hard::attack(){
	int t = this->count % 650;
	if (t % 10 != 0) return;

	if (t < 50){
		//
	}
	else if (t < 150){
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 50) / 100, 0.0);
		}
	}
	else if (t < 250){
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 150) / 100, 0.0);
		}
	}
	else if (t == 250){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 3; line++){
			for (int i = 0; i < 10; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 10, 0.0);
			}
		}
	}
	else if (t < 350){
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 250) / 100, 0.0);
		}
	}
	else if (t < 450){
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 350) / 100, 0.0);
		}
	}
	else if (t == 450){
		double angle = atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x);
		for (int line = 0; line < 3; line++){
			for (int i = 0; i < 10; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_WaterBlue, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, angle + M_PI * 2 * i / 10, 0.0);
			}
		}
	}
	else if (t < 550){
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI + M_PI*(t - 450) / 100, 0.0);
		}
	}
	else {
		for (int line = 0; line < 2; line++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Crystal, Bul_Yellow, 51, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.5*line, 0.0, M_PI * 2 - M_PI*(t - 550) / 100, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_3_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_3_Easy::BossAttack_3_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1000;
	this->attackName = "オレンジクロスパープルクロス";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_3_Easy::move(){
	this->count++;

	int t = this->count % 250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_3_Easy::attack(){
	int t = this->count % 50;
	if (t == 0){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 2; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Orange, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, M_PI / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
	else if (t == 25){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 2; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Purple, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, -M_PI / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
}

BossAttack_3_3_Normal::BossAttack_3_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 250;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1000;
	this->attackName = "オレンジクロスパープルクロス";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_3_Normal::move(){
	this->count++;

	int t = this->count % 250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_3_Normal::attack(){
	int t = this->count % 50;
	if (t == 0){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 3; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Orange, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, M_PI * 2 / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
	else if (t == 25){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 3; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Purple, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, -M_PI * 2 / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
}

BossAttack_3_3_Hard::BossAttack_3_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1000;
	this->attackName = "クロスリザレクション";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_3_Hard::move(){
	this->count++;

	int t = this->count % 250;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(100, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_3_Hard::attack(){
	int t = this->count % 30;
	if (t == 0){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 3; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Orange, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, M_PI * 2 / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
	else if (t == 15){
		double x = 1.0*GetRand(1.5*GAME_WINDOW_WIDTH) - 0.25*GAME_WINDOW_WIDTH;
		double angle = M_PI*GetRand(100) / 50;
		double rad = M_PI / 4 + M_PI*GetRand(90) / 180;

		for (int line = 0; line < 3; line++){
			for (int cir = 0; cir < 4; cir++){
				this->isetBullet->isetBossBullet(Point(x + 25.0*(line + 1)*cos(angle + M_PI*cir / 2), -60.0 + 25.0*(line + 1)*sin(angle + M_PI*cir / 2)), Bul_Middle, Bul_Purple, 52, this->isetBullet, this->igetPlayerPosition
					, 3.0, 0.0, rad, -M_PI * 2 / 180, 200, 25.0*(line + 1), angle + M_PI*cir / 2);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_3_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_4_Easy::BossAttack_3_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 250;
	this->HP_Max_Stand = 150;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1500;
	this->attackName = "ミラーボールマン";
	this->initialPosition = Point(258, 280);
}

void BossAttack_3_4_Easy::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_3_4_Easy::attack(){
	if (this->count % 10 != 0) return;

	int t = this->count % 600;

	if ((t < 360) || (t > 540)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, 1.2);
		}
	}
	if ((t > 240) || (t < 60)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, -1.2);
		}
	}
}

BossAttack_3_4_Normal::BossAttack_3_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 350;
	this->HP_Max_Stand = 250;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1800;
	this->attackName = "ミラーボールマン";
	this->initialPosition = Point(258, 280);
}

void BossAttack_3_4_Normal::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_3_4_Normal::attack(){
	if (this->count % 10 != 0) return;

	int t = this->count % 600;

	if ((t < 360) || (t > 540)){
		for (int i = 0; i < 3; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, 1.4);
		}
	}
	if ((t > 240) || (t < 60)){
		for (int i = 0; i < 3; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, -1.4);
		}
	}
}

BossAttack_3_4_Hard::BossAttack_3_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1800;
	this->attackName = "ミラーボールマン";
	this->initialPosition = Point(258, 280);
}

void BossAttack_3_4_Hard::move(){
	this->count++;

	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_3_4_Hard::attack(){
	if (this->count % 10 != 0) return;

	int t = this->count % 600;

	if ((t < 360)||(t > 540)){
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, 2.0);
		}
	}
	if ((t > 240)||(t < 60)){
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Snow, Bul_White, 4, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*GetRand(360) / 180, -2.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_3_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_5_Easy::BossAttack_3_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_5_Easy::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(60, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_5_Easy::attack(){
	int t = this->count % 400;

	if ((t >= 50) && (t < 170)){
		if (t % 22 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 14 + M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 140) && (t < 200)){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
	}

	if ((t >= 250) && (t < 370)){
		if (t % 22 == 0){
			for (int i = 0; i < 14; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 14 - M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 340) && (t < 400)){
		this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
	}
}

BossAttack_3_5_Normal::BossAttack_3_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_5_Normal::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(60, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_5_Normal::attack(){
	int t = this->count % 400;

	if ((t >= 50) && (t < 170)){
		if (t % 18 == 0){
			for (int i = 0; i < 16; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 16 + M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 140) && (t < 200)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
		}
	}

	if ((t >= 250) && (t < 370)){
		if (t % 18 == 0){
			for (int i = 0; i < 16; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 16 - M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 340) && (t < 400)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
		}
	}
}

BossAttack_3_5_Hard::BossAttack_3_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1800;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1000;
	this->attackName = "";
	this->initialPosition = Point(258, 120);
}

void BossAttack_3_5_Hard::move(){
	this->count++;
	int t = this->count % 200;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(60, Point(80, 50), Point(436, 200));
	}
	else if (t<50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else {
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_3_5_Hard::attack(){
	int t = this->count % 400;

	if ((t >= 50) && (t < 170)){
		if (t % 12 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 20 + M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 140) && (t < 200)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
		}
	}

	if ((t >= 250) && (t < 370)){
		if (t % 12 == 0){
			for (int i = 0; i < 20; i++){
				this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Money, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI*2.0*i / 20 - M_PI*2.0 * 2 * (this->count - 50) / 12 / 180, 0.0);
			}
		}
	}
	if ((t >= 340) && (t < 400)){
		for (int i = 0; i < 2; i++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Middle, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 0.2 + 1.0*GetRand(60) / 100, 0.03, M_PI*GetRand(360) / 180, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_3_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_3_6_Easy::BossAttack_3_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 150;
	this->HP_Max_Absorb = 800;
	this->limitTime = 3000;
	this->attackName = "恐怖体験！寝起きの枕";
	this->initialPosition = Point(258, 120);

	this->angle = 0.0;
}

void BossAttack_3_6_Easy::move(){
	this->count++;
	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_6_Easy::attack(){
	if (this->count % 30 == 0){
		for (int way = 0; way < 2; way++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_White, 53, this->isetBullet, this->igetPlayerPosition, 3.0, -1.0 / 25, this->angle + M_PI * 2 * way / 2, 0.0, 20, 10.0);
		}
		this->angle += M_PI / 90;
	}

	if (this->count % 80 == 0){
		Point cent = Point(GetRand(GAME_WINDOW_WIDTH), -60.0);
		double angle = M_PI*GetRand(60) / 180 + M_PI / 3;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(cent, Bul_SmallStar, Bul_WaterBlue, 54, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle, M_PI / 180, 300, 30.0, M_PI * 2 / 180, M_PI * 2 * i / 8);
		}
	}
}

BossAttack_3_6_Normal::BossAttack_3_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 300;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 3000;
	this->attackName = "恐怖体験！寝起きの枕";
	this->initialPosition = Point(258, 120);

	this->angle = 0.0;
}

void BossAttack_3_6_Normal::move(){
	this->count++;
	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_6_Normal::attack(){
	if (this->count % 25 == 0){
		for (int way = 0; way < 2; way++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_White, 53, this->isetBullet, this->igetPlayerPosition, 3.0, -1.0 / 25, this->angle + M_PI * 2 * way / 2, 0.0, 20, 30);
		}
		this->angle += M_PI / 90;
	}

	if (this->count % 60 == 0){
		Point cent = Point(GetRand(GAME_WINDOW_WIDTH), -60.0);
		double angle = M_PI*GetRand(60) / 180 + M_PI / 3;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(cent, Bul_SmallStar, Bul_WaterBlue, 54, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle, M_PI / 180, 300, 30.0, M_PI * 2 / 180, M_PI * 2 * i / 8);
		}
	}
}

BossAttack_3_6_Hard::BossAttack_3_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 240;
	this->HP_Max_Stand = 250;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 3000;
	this->attackName = "恐怖体験！寝起きの枕";
	this->initialPosition = Point(258, 120);

	this->angle = 0.0;
}

void BossAttack_3_6_Hard::move(){
	this->count++;
	int t = this->count % 60;

	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getCircleDistanceMovePosition(50, Point(80, 50), Point(436, 200));
	}
	else{
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 60));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
}

void BossAttack_3_6_Hard::attack(){
	if (this->count % 15 == 0){
		for (int way = 0; way < 2; way++){
			this->isetBullet->isetBossBullet(this->igetBossPosition->igetPosition(), Bul_Small, Bul_White, 53, this->isetBullet, this->igetPlayerPosition, 3.0, -1.0 / 25, this->angle + M_PI * 2 * way / 2, 0.0, 20, 50.0);
		}
		this->angle += M_PI / 90;
	}

	if (this->count % 45 == 0){
		Point cent = Point(GetRand(GAME_WINDOW_WIDTH), -60.0);
		double angle = M_PI*GetRand(60) / 180 + M_PI / 3;
		for (int i = 0; i < 8; i++){
			this->isetBullet->isetBossBullet(cent, Bul_SmallStar, Bul_WaterBlue, 54, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle, M_PI / 180, 300, 50.0 , M_PI*2/180, M_PI * 2 * i / 8);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
