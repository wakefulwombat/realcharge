#include "bossAttack_5.h"
#include "DxLib.h"

////BossAttack_5_1//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_1_Easy::BossAttack_5_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 1500;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_1_Easy::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t <= 380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_1_Easy::attack(){
	int t = this->count % 400;

	if (t == 0){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 2, 0.0);
		}
	}
	else if (t == 40){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 7 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 7 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);
		}
	}
	else if (t == 80){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, 0.0, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, 0.0, 0.0);
		}
	}
	else if (t == 120){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0);
		}
	}
	else if (t == 160){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 2, 0.0);
		}
	}
	else if (t == 200){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0);
		}
	}
	else if (t == 240){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI, 0.0);
		}
	}
	else if (t == 280){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 5 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(3);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 5 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
		}
	}
}

BossAttack_5_1_Normal::BossAttack_5_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 1400;
	this->limitTime = 1500;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_1_Normal::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if (t <= 380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_1_Normal::attack(){
	int t = this->count % 400;

	if (t == 0){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 2, 0.0);
		}
	}
	else if (t == 40){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 7 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 7 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);
		}
	}
	else if (t == 80){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, 0.0, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, 0.0, 0.0);
		}
	}
	else if (t == 120){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0);
		}
	}
	else if (t == 160){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 2, 0.0);
		}
	}
	else if (t == 200){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0);
		}
	}
	else if (t == 240){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI, 0.0);
		}
	}
	else if (t == 280){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 5 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 5 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
		}
	}
}

BossAttack_5_1_Hard::BossAttack_5_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1200;
	this->HP_Max_Stand = 1400;
	this->HP_Max_Absorb = 1600;
	this->limitTime = 1500;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_1_Hard::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 180));
	}
	else if(t<=380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_1_Hard::attack(){
	int t = this->count % 400;

	if (t == 0){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 2, 0.0);
		}
	}
	else if (t == 40){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI*7/4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 7 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 7 / 4, 0.0);
		}
	}
	else if (t == 80){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, 0.0, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, 0.0, 0.0);
		}
	}
	else if (t == 120){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 4, 0.0);
		}
	}
	else if (t == 160){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI / 2 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI / 2, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 2, 0.0);
		}
	}
	else if (t == 200){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 3 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 3 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 3 / 4, 0.0);
		}
	}
	else if (t == 240){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI, 0.0);
		}
	}
	else if (t == 280){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 3, M_PI * 5 / 4 + M_PI / 6, "A");
		this->fractal->setRule('A', "B-A-B");
		this->fractal->setRule('B', "A+B+A");
		this->fractal->calculate(4);

		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 1.4, 0.0, M_PI * 5 / 4, 0.0);
		}

		this->fractal->extractionKeyList('B');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Kunai, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI * 5 / 4, 0.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_2//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_2_Easy::BossAttack_5_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1200;
	this->limitTime = 2400;
	this->attackName = "センコウ花火";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_2_Easy::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 180));
	}
	else if (t <= 380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_2_Easy::attack(){
	int t = this->count % 800;

	if (t == 60){
		this->fractal->initialize(Point(248.0 + GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('O', "-MA++NA[+++OA++PA]-");
		this->fractal->setRule('P', "--OA++++MA[+PA++++NA]--NA");
		this->fractal->setRule('A', "");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.0, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.0, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.0, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.0, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.0, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
	}
	else if (t == 320){
		this->fractal->initialize(Point(248.0 + GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('P', "--OA+++++MA[+PA++++NA]--NA");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.01, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.01, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 0, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0);
		}
	}
	else if (t == 440){
		this->isetBullet->isetBossBullet(Point(88.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 2.0, 12.0);
	}
	else if (t == 460){
		this->isetBullet->isetBossBullet(Point(258.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 2.0, 12.0);
	}
	else if (t == 480){
		this->isetBullet->isetBossBullet(Point(428.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 2.0, 12.0);
	}
}

BossAttack_5_2_Normal::BossAttack_5_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 700;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 2400;
	this->attackName = "センコウ花火";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_2_Normal::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 180));
	}
	else if (t <= 380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_2_Normal::attack(){
	int t = this->count % 800;

	if (t == 60){
		this->fractal->initialize(Point(248.0 + GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('O', "-MA++NA[+++OA++PA]-");
		this->fractal->setRule('P', "--OA++++MA[+PA++++NA]--NA");
		this->fractal->setRule('A', "");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
	}
	else if (t == 320){
		this->fractal->initialize(Point(248.0 + GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('P', "--OA+++++MA[+PA++++NA]--NA");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 9, this->isetBullet, this->igetPlayerPosition, 2.0*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
	}
	else if (t == 440){
		this->isetBullet->isetBossBullet(Point(88.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 15.0);
	}
	else if (t == 460){
		this->isetBullet->isetBossBullet(Point(258.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 15.0);
	}
	else if (t == 480){
		this->isetBullet->isetBossBullet(Point(428.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 15.0);
	}
}

BossAttack_5_2_Hard::BossAttack_5_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 500;
	this->HP_Max_Stand = 700;
	this->HP_Max_Absorb = 1400;
	this->limitTime = 2400;
	this->attackName = "センコウ花火";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_2_Hard::move(){
	this->count++;

	int t = (this->count % 400);
	if (t < 280){
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
	else if (t == 280){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 180));
	}
	else if (t <= 380){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t - 280, 100));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_2_Hard::attack(){
	int t = this->count % 560;

	if (t == 60){
		this->fractal->initialize(Point(248.0+GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('O', "-MA++NA[+++OA++PA]-");
		this->fractal->setRule('P', "--OA++++MA[+PA++++NA]--NA");
		this->fractal->setRule('A', "");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
	}
	else if (t == 260){
		this->fractal->initialize(Point(248.0 + GetRand(40), 220.0), 200, M_PI / 5, M_PI*GetRand(180) / 180, "[N]++[N]++[N]++[N]++[N]");
		this->fractal->setRule('M', "OA++PA----NA[-OA----MA]++");
		this->fractal->setRule('N', "+OA--PA[---MA--NA]+");
		this->fractal->setRule('P', "--OA+++++MA[+PA++++NA]--NA");
		this->fractal->calculate(2);

		this->fractal->extractionKeyList('M');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x-258.0,2.0)+pow(it->y-220.0,2.0))/10000), 0.02, atan2(it->y-220.0,it->x-258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('N');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('P');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('O');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_Green, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
		this->fractal->extractionKeyList('A');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Snow, Bul_WaterBlue, 9, this->isetBullet, this->igetPlayerPosition, 2.4*sqrt((pow(it->x - 258.0, 2.0) + pow(it->y - 220.0, 2.0)) / 10000), 0.02, atan2(it->y - 220.0, it->x - 258.0), 0.0, 20, 80.0);
		}
	}
	else if (t == 320){
		this->isetBullet->isetBossBullet(Point(88.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 20.0);
	}
	else if (t == 340){
		this->isetBullet->isetBossBullet(Point(258.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 20.0);
	}
	else if (t == 360){
		this->isetBullet->isetBossBullet(Point(428.0, 250.0), Bul_Middle, Bul_White, 56, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI * 3 / 2, 0.0, 20, 3.0, 20.0);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_3//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_3_Easy::BossAttack_5_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 800;
	this->HP_Max_Stand = 800;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_3_Easy::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 130), Point(416, 250));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_3_Easy::attack(){
	if (this->count < 150) return;

	int t = this->count % 600;

	if (t < 170){
		for (unsigned int i = (t + 10 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t + 10)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 190){
		//
	}
	else if (t == 190){
		this->fractal->initialize(this->igetBossPosition->igetPosition()+Point(0,100), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F");
		this->fractal->setRule('F', "F++F--F-F+F");
		this->fractal->calculate(3);
	}
	else if (t < 370){
		for (unsigned int i = (t - 190 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 190)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 390){
		//
	}
	else if (t == 390){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "-F");
		this->fractal->setRule('F', "F+F-F-F+F");
		this->fractal->calculate(3);
	}
	else if (t < 570){
		for (unsigned int i = (t - 390 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 390)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 590){
		//
	}
	else if (t == 590){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "FX");
		this->fractal->setRule('X', "X+YF+");
		this->fractal->setRule('Y', "-FX-Y");
		this->fractal->calculate(6);
	}
	else{
		for (unsigned int i = (t - 590 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 590)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}

BossAttack_5_3_Normal::BossAttack_5_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2500;
	this->HP_Max_Stand = 1200;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_3_Normal::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 130), Point(416, 250));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_3_Normal::attack(){
	if (this->count < 150) return;

	int t = this->count % 600;

	if (t < 170){
		for (unsigned int i = (t + 10 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t + 10)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 190){
		//
	}
	else if (t == 190){
		this->fractal->initialize(this->igetBossPosition->igetPosition() + Point(0, 100), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F");
		this->fractal->setRule('F', "F++F--F-F+F");
		this->fractal->calculate(4);
	}
	else if (t < 370){
		for (unsigned int i = (t - 190 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 190)*this->fractal->getResultAllPoint().size() / 180; i++){
			if (i % 2 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 390){
		//
	}
	else if (t == 390){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "-F");
		this->fractal->setRule('F', "F+F-F-F+F");
		this->fractal->calculate(3);
	}
	else if (t < 570){
		for (unsigned int i = (t - 390 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 390)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 590){
		//
	}
	else if (t == 590){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "FX");
		this->fractal->setRule('X', "X+YF+");
		this->fractal->setRule('Y', "-FX-Y");
		this->fractal->calculate(7);
	}
	else{
		for (unsigned int i = (t - 590 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 590)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}

BossAttack_5_3_Hard::BossAttack_5_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 2500;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 2400;
	this->attackName = "";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_3_Hard::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 130), Point(416, 250));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_3_Hard::attack(){
	if (this->count < 150) return;

	int t = this->count % 600;

	if (t < 170){
		for (unsigned int i = (t + 10 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t + 10)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 190){
		//
	}
	else if (t == 190){
		this->fractal->initialize(this->igetBossPosition->igetPosition() + Point(0, 100), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F");
		this->fractal->setRule('F', "F++F--F-F+F");
		this->fractal->calculate(4);
	}
	else if (t < 370){
		for (unsigned int i = (t - 190 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 190)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 390){
		//
	}
	else if (t == 390){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "-F");
		this->fractal->setRule('F', "F+F-F-F+F");
		this->fractal->calculate(4);
	}
	else if (t < 570){
		for (unsigned int i = (t - 390 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 390)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 590){
		//
	}
	else if (t == 590){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "FX");
		this->fractal->setRule('X', "X+YF+");
		this->fractal->setRule('Y', "-FX-Y");
		this->fractal->calculate(8);
	}
	else{
		for (unsigned int i = (t - 590 - 1)*this->fractal->getResultAllPoint().size() / 180; i < (t - 590)*this->fractal->getResultAllPoint().size() / 180; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_4//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_4_Easy::BossAttack_5_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 2400;
	this->attackName = "すべてが枯草になる";
	this->initialPosition = Point(258, 120);

	for (int i = 0; i < 3; i++) this->waterweed[i] = new LSystem();
}

void BossAttack_5_4_Easy::move(){
	this->count++;

	int t = this->count % 60;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(200, 100), Point(316, 200));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_4_Easy::attack(){
	int t = this->count % 1000;

	if (t == 0){
		this->waterweed[0]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 12, M_PI * 3 / 2, "F");
		this->waterweed[0]->setRule('F', "X[-FF]Y");
		this->waterweed[0]->setRule('X', "FF");
		this->waterweed[0]->setRule('Y', "[+F[+F][-F+F]]");
		this->waterweed[0]->calculate(3);
	}
	else if (t < 250){
		for (unsigned int i = (t - 1)*this->waterweed[0]->getResultAllPoint().size() / 250; i < t*this->waterweed[0]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[0]->getResultAllPoint()[i], Bul_Small, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 300){
		//
	}
	else if (t == 300){
		this->waterweed[1]->initialize(this->igetBossPosition->igetPosition() + Point(200.0, 0.0), 500, M_PI / 6, M_PI * 3 / 2, "-F");
		this->waterweed[1]->setRule('F', "FF[-F++F][+F--F]++F--F");
		this->waterweed[1]->calculate(2);
	}
	else if (t < 550){
		for (unsigned int i = (t - 300 - 1)*this->waterweed[1]->getResultAllPoint().size() / 250; i < (t - 300)*this->waterweed[1]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[1]->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 600){
		//
	}
	else if (t == 600){
		this->waterweed[2]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 6, M_PI * 3 / 2, "F");
		this->waterweed[2]->setRule('F', "FF-[-F+F+F]+[+F-F-F]");
		this->waterweed[2]->calculate(2);
	}
	else if (t < 850){
		for (unsigned int i = (t - 600 - 1)*this->waterweed[2]->getResultAllPoint().size() / 250; i < (t - 600)*this->waterweed[2]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[2]->getResultAllPoint()[i], Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t % 50 == 0){
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(Point(-40.0, 300.0 + 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI * 2 * i / 9, 0.0, 100);
		}
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(Point(556.0, 300.0 - 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI * 2 * i / 9, 0.0, 100);
		}
	}
}

BossAttack_5_4_Normal::BossAttack_5_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 600;
	this->HP_Max_Absorb = 1300;
	this->limitTime = 2400;
	this->attackName = "すべてが枯草になる";
	this->initialPosition = Point(258, 120);

	for (int i = 0; i < 3; i++) this->waterweed[i] = new LSystem();
}

void BossAttack_5_4_Normal::move(){
	this->count++;

	int t = this->count % 60;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(200, 100), Point(316, 200));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_4_Normal::attack(){
	int t = this->count % 1000;

	if (t == 0){
		this->waterweed[0]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 12, M_PI * 3 / 2, "F");
		this->waterweed[0]->setRule('F', "X[-FF]Y");
		this->waterweed[0]->setRule('X', "FF");
		this->waterweed[0]->setRule('Y', "[+F[+F][-F+F]]");
		this->waterweed[0]->calculate(4);
	}
	else if (t < 250){
		for (unsigned int i = (t - 1)*this->waterweed[0]->getResultAllPoint().size() / 250; i < t*this->waterweed[0]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[0]->getResultAllPoint()[i], Bul_Small, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 300){
		//
	}
	else if (t == 300){
		this->waterweed[1]->initialize(this->igetBossPosition->igetPosition() + Point(200.0, 0.0), 500, M_PI / 6, M_PI * 3 / 2, "-F");
		this->waterweed[1]->setRule('F', "FF[-F++F][+F--F]++F--F");
		this->waterweed[1]->calculate(3);
	}
	else if (t < 550){
		for (unsigned int i = (t - 300 - 1)*this->waterweed[1]->getResultAllPoint().size() / 250; i < (t - 300)*this->waterweed[1]->getResultAllPoint().size() / 250; i++){
			if (i % 2 == 0) this->isetBullet->isetBossBullet(this->waterweed[1]->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 600){
		//
	}
	else if (t == 600){
		this->waterweed[2]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 6, M_PI * 3 / 2, "F");
		this->waterweed[2]->setRule('F', "FF-[-F+F+F]+[+F-F-F]");
		this->waterweed[2]->calculate(3);
	}
	else if (t < 850){
		for (unsigned int i = (t - 600 - 1)*this->waterweed[2]->getResultAllPoint().size() / 250; i < (t - 600)*this->waterweed[2]->getResultAllPoint().size() / 250; i++){
			if (i % 2 == 0) this->isetBullet->isetBossBullet(this->waterweed[2]->getResultAllPoint()[i], Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t % 50 == 0){
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(Point(-40.0, 300.0 + 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI*2*i / 9, 0.0, 100);
		}
		for (int i = 0; i < 4; i++){
			this->isetBullet->isetBossBullet(Point(556.0, 300.0 - 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI*2*i / 9, 0.0, 100);
		}
	}
}

BossAttack_5_4_Hard::BossAttack_5_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 2000;
	this->HP_Max_Stand = 1200;
	this->HP_Max_Absorb = 1600;
	this->limitTime = 2400;
	this->attackName = "すべてが枯草になる";
	this->initialPosition = Point(258, 120);

	for (int i = 0; i < 3; i++) this->waterweed[i] = new LSystem();
}

void BossAttack_5_4_Hard::move(){
	this->count++;

	int t = this->count % 60;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(200, 100), Point(316, 200));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_4_Hard::attack(){
	int t = this->count % 1000;

	if (t == 0){
		this->waterweed[0]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 12, M_PI * 3 / 2, "F");
		this->waterweed[0]->setRule('F', "X[-FF]Y");
		this->waterweed[0]->setRule('X', "FF");
		this->waterweed[0]->setRule('Y', "[+F[+F][-F+F]]");
		this->waterweed[0]->calculate(4);
	}
	else if (t < 250){
		for (unsigned int i = (t - 1)*this->waterweed[0]->getResultAllPoint().size() / 250; i < t*this->waterweed[0]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[0]->getResultAllPoint()[i], Bul_Small, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 300){
		//
	}
	else if (t == 300){
		this->waterweed[1]->initialize(this->igetBossPosition->igetPosition()+Point(200.0,0.0), 500, M_PI / 6, M_PI * 3 / 2, "-F");
		this->waterweed[1]->setRule('F', "FF[-F++F][+F--F]++F--F");
		this->waterweed[1]->calculate(3);
	}
	else if (t < 550){
		for (unsigned int i = (t - 300 - 1)*this->waterweed[1]->getResultAllPoint().size() / 250; i < (t - 300)*this->waterweed[1]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[1]->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t < 600){
		//
	}
	else if (t == 600){
		this->waterweed[2]->initialize(this->igetBossPosition->igetPosition(), 500, M_PI / 6, M_PI * 3 / 2, "F");
		this->waterweed[2]->setRule('F', "FF-[-F+F+F]+[+F-F-F]");
		this->waterweed[2]->calculate(3);
	}
	else if (t < 850){
		for (unsigned int i = (t - 600 - 1)*this->waterweed[2]->getResultAllPoint().size() / 250; i < (t - 600)*this->waterweed[2]->getResultAllPoint().size() / 250; i++){
			this->isetBullet->isetBossBullet(this->waterweed[2]->getResultAllPoint()[i], Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 12 + M_PI*GetRand(150) / 180, 0.0, 110, 90.0);
		}
	}

	if (t % 30 == 0){
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(Point(-40.0, 300.0 + 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI*i / 6, 0.0, 100);
		}
		for (int i = 0; i < 5; i++){
			this->isetBullet->isetBossBullet(Point(556.0, 300.0 - 100.0*sin(M_PI / 120 * this->count)), Bul_Middle, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI + M_PI / 6 * sin(M_PI / 150 * this->count) + M_PI*i / 6, 0.0, 100);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_5//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_5_Easy::BossAttack_5_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 600;
	this->HP_Max_Stand = 400;
	this->HP_Max_Absorb = 1500;
	this->limitTime = 2400;
	this->attackName = "これフラクタルなんだぜ";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_5_Easy::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 100), Point(416, 200));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_5_Easy::attack(){
	if (this->count < 350) return;

	int t = this->count % 1200;

	if (t < 340){
		for (unsigned int i = (t + 20 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t + 20)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 380){
		//
	}
	else if (t == 380){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-F-F+F");
		this->fractal->calculate(2);
	}
	else if (t < 740){
		for (unsigned int i = (t - 380 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 380)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 780){
		//
	}
	else if (t == 780){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-FF");
		this->fractal->calculate(2);
	}
	else if (t < 1140){
		for (unsigned int i = (t - 780 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 780)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 1180){
		//
	}
	else if (t == 1180){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "F-FF--F-F");
		this->fractal->calculate(2);
	}
	else{
		for (unsigned int i = (t - 1180 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 1180)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}

BossAttack_5_5_Normal::BossAttack_5_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1600;
	this->HP_Max_Stand = 1200;
	this->HP_Max_Absorb = 1700;
	this->limitTime = 2400;
	this->attackName = "これフラクタルなんだぜ";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_5_Normal::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 100), Point(416, 200));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_5_Normal::attack(){
	if (this->count < 350) return;

	int t = this->count % 1540;

	if (t < 340){
		for (unsigned int i = (t + 140 - 1)*this->fractal->getResultAllPoint().size() / 480; i < (t + 140)*this->fractal->getResultAllPoint().size() / 480; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 380){
		//
	}
	else if (t == 380){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-F-F+F");
		this->fractal->calculate(3);
	}
	else if (t < 860){
		for (unsigned int i = (t - 380 - 1)*this->fractal->getResultAllPoint().size() / 480; i < (t - 380)*this->fractal->getResultAllPoint().size() / 480; i++){
			if (i % 3 != 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 900){
		//
	}
	else if (t == 900){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-FF");
		this->fractal->calculate(3);
	}
	else if (t < 1380){
		for (unsigned int i = (t - 900 - 1)*this->fractal->getResultAllPoint().size() / 480; i < (t - 900)*this->fractal->getResultAllPoint().size() / 480; i++){
			if (i % 3 != 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 1420){
		//
	}
	else if (t == 1420){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "F-FF--F-F");
		this->fractal->calculate(3);
	}
	else{
		for (unsigned int i = (t - 1420 - 1)*this->fractal->getResultAllPoint().size() / 480; i < (t - 1420)*this->fractal->getResultAllPoint().size() / 480; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}

BossAttack_5_5_Hard::BossAttack_5_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 2400;
	this->HP_Max_Absorb = 1800;
	this->limitTime = 3000;
	this->attackName = "これフラクタルなんだぜ";
	this->initialPosition = Point(258, 120);

	this->fractal = new LSystem();
}

void BossAttack_5_5_Hard::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 100), Point(416, 200));
	}
	else if (t < 180){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 180));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_5_Hard::attack(){
	if (this->count < 350) return;

	int t = this->count % 1200;

	if (t < 340){
		for (unsigned int i = (t + 20 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t + 20)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 380){
		//
	}
	else if (t == 380){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-F-F+F");
		this->fractal->calculate(3);
	}
	else if (t < 740){
		for (unsigned int i = (t - 380 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 380)*this->fractal->getResultAllPoint().size() / 360; i++){
			if (i % 2 == 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Red, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 780){
		//
	}
	else if (t == 780){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "FF-F-F-F-FF");
		this->fractal->calculate(3);
	}
	else if (t < 1140){
		for (unsigned int i = (t - 780 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 780)*this->fractal->getResultAllPoint().size() / 360; i++){
			if (i % 3 == 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
	else if (t < 1180){
		//
	}
	else if (t == 1180){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 400, M_PI / 2, atan2(this->igetPlayerPosition->igetPosition().y - this->igetBossPosition->igetPosition().y, this->igetPlayerPosition->igetPosition().x - this->igetBossPosition->igetPosition().x), "F-F-F-F");
		this->fractal->setRule('F', "F-FF--F-F");
		this->fractal->calculate(3);
	}
	else{
		for (unsigned int i = (t - 1180 - 1)*this->fractal->getResultAllPoint().size() / 360; i < (t - 1180)*this->fractal->getResultAllPoint().size() / 360; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Fuda, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 140, 120.0);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_6//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_6_Easy::BossAttack_5_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 500;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 2400;
	this->attackName = "開花乱舞";
	this->initialPosition = Point(258, 220);

	this->fractal = new LSystem();
}

void BossAttack_5_6_Easy::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_5_6_Easy::attack(){
	int t = this->count % 600;

	if (t < 120){
		//
	}
	else if (t == 120){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 180, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);
		this->fractal->sortFromCenter();
	}
	else if (t < 180){
		for (unsigned int i = (t - 120 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 120)*this->fractal->getResultAllPoint().size() / 60; i++){
			if (t % 3 != 0)this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 0.2 + 2.0*(t - 120) / 60, 0.01, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
	else if (t < 300){
		//
	}
	else if (t == 300){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 300, M_PI * 2 / 5, M_PI*GetRand(360) / 180, "F-F-F-F-F");
		this->fractal->setRule('F', "F-F++F+F-F-F");
		this->fractal->calculate(2);
		this->fractal->sortFromCenter();
	}
	else if (t < 360){
		for (unsigned int i = (t - 300 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 300)*this->fractal->getResultAllPoint().size() / 60; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 0.3 + 2.0*(t - 300) / 60, 0.02, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
	else  if (t < 480){
		//
	}
	else if (t == 480){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 450, M_PI / 2, M_PI*GetRand(360) / 180, "F-F-F-F");
		this->fractal->setRule('F', "F+FF-FF-F-F+F+FF-F-F+F+FF+FF-F");
		this->fractal->calculate(1);
		this->fractal->sortFromCenter();
	}
	else if (t < 540){
		for (unsigned int i = (t - 480 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 480)*this->fractal->getResultAllPoint().size() / 60; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_White, 11, this->isetBullet, this->igetPlayerPosition, 0.3 + 2.7*(t - 480) / 60, 0.05, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
}

BossAttack_5_6_Normal::BossAttack_5_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 8000;
	this->HP_Max_Stand = 2000;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 2700;
	this->attackName = "開花乱舞";
	this->initialPosition = Point(258, 220);

	this->fractal = new LSystem();
}

void BossAttack_5_6_Normal::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_5_6_Normal::attack(){
	int t = this->count % 900;

	if (t < 120){
		//
	}
	else if (t == 120){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 180, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);
		this->fractal->sortFromCenter();
	}
	else if (t < 180){
		for (unsigned int i = (t - 120 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 120)*this->fractal->getResultAllPoint().size() / 60; i++){
			if (i % 3 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 0.2 + 2.0*(t - 120) / 60, 0.01, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
			if (i % 3 == 1) this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, -0.2 - 2.0*(t - 120) / 60, -0.01, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
	else if (t < 300){
		//
	}
	else if (t == 300){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 300, M_PI * 2 / 5, M_PI*GetRand(360) / 180, "F-F-F-F-F");
		this->fractal->setRule('F', "F-F++F+F-F-F");
		this->fractal->calculate(3);
		this->fractal->sortFromCenter();
	}
	else if (t < 360){
		for (unsigned int i = (t - 300 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 300)*this->fractal->getResultAllPoint().size() / 60; i++){
			if (i % 3 == 0)this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 0.3 + 2.0*(t - 300) / 60, 0.02, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
			if (i % 3 == 1)this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, -0.3 - 2.0*(t - 300) / 60, -0.02, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
	else  if (t < 480){
		//
	}
	else if (t == 480){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 450, M_PI / 2, M_PI*GetRand(360) / 180, "F-F-F-F");
		this->fractal->setRule('F', "F+FF-FF-F-F+F+FF-F-F+F+FF+FF-F");
		this->fractal->calculate(2);
		this->fractal->sortFromCenter();
	}
	else if (t < 540){
		for (unsigned int i = (t - 480 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 480)*this->fractal->getResultAllPoint().size() / 60; i++){
			if (i % 3 == 0)this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_White, 11, this->isetBullet, this->igetPlayerPosition, 0.3 + 2.0*(t - 480) / 60, 0.05, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
			if (i % 3 == 1)this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_White, 11, this->isetBullet, this->igetPlayerPosition, -0.3 - 2.0*(t - 480) / 60, -0.05, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 560.0 - t);
		}
	}
}

BossAttack_5_6_Hard::BossAttack_5_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 30000;
	this->HP_Max_Stand = 6000;
	this->HP_Max_Absorb = 3500;
	this->limitTime = 2400;
	this->attackName = "開花乱舞";
	this->initialPosition = Point(258, 220);

	this->fractal = new LSystem();
}

void BossAttack_5_6_Hard::move(){
	this->count++;
	this->isetBossInfo->isetTransRad(M_PI / 2);
}

void BossAttack_5_6_Hard::attack(){
	int t = this->count % 500;

	if (t < 100){
		//
	}
	else if (t == 100){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 180, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);
		this->fractal->sortFromCenter();
	}
	else if (t < 150){
		for (unsigned int i = (t - 100 - 1)*this->fractal->getResultAllPoint().size() / 60; i < (t - 100)*this->fractal->getResultAllPoint().size() / 50; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 0.2 + 2.0*(t - 100) / 50, 0.01, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 460.0 - t);
		}
	}
	else if (t < 230){
		//
	}
	else if (t == 230){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 300, M_PI * 2 / 5, M_PI*GetRand(360) / 180, "F-F-F-F-F");
		this->fractal->setRule('F', "F-F++F+F-F-F");
		this->fractal->calculate(3);
		this->fractal->sortFromCenter();
	}
	else if (t < 280){
		for (unsigned int i = (t - 230 - 1)*this->fractal->getResultAllPoint().size() / 50; i < (t - 230)*this->fractal->getResultAllPoint().size() / 50; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_Blue, 11, this->isetBullet, this->igetPlayerPosition, 0.3 + 2.0*(t - 230) / 50, 0.02, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 460.0 - t);
		}
	}
	else  if (t < 360){
		//
	}
	else if (t == 360){
		this->fractal->initialize(this->igetBossPosition->igetPosition(), 450, M_PI / 2, M_PI*GetRand(360) / 180, "F-F-F-F");
		this->fractal->setRule('F', "F+FF-FF-F-F+F+FF-F-F+F+FF+FF-F");
		this->fractal->calculate(2);
		this->fractal->sortFromCenter();
	}
	else if (t < 410){
		for (unsigned int i = (t - 360 - 1)*this->fractal->getResultAllPoint().size() / 50; i < (t - 360)*this->fractal->getResultAllPoint().size() / 50; i++){
			this->isetBullet->isetBossBullet(this->fractal->getResultAllPoint()[i], Bul_Small, Bul_White, 11, this->isetBullet, this->igetPlayerPosition, 0.3+2.7*(t-360)/50, 0.05, atan2(this->fractal->getResultAllPoint()[i].y - this->igetBossPosition->igetPosition().y, this->fractal->getResultAllPoint()[i].x - this->igetBossPosition->igetPosition().x), 0.0, 140, 460.0 - t);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_7//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_7_Easy::BossAttack_5_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 200;
	this->HP_Max_Stand = 200;
	this->HP_Max_Absorb = 600;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 180);

	this->fractal = new LSystem();
}

void BossAttack_5_7_Easy::move(){
	this->count++;

	int t = this->count % 180;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 250));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_7_Easy::attack(){
	int t = this->count % 600;

	if (t == 0){
		this->fractal->initialize(Point(258.0, 291.0), 1400, M_PI / 3, M_PI*GetRand(360) / 180, "F++F++F");
		this->fractal->setRule('F', "F-F++F-F");
		this->fractal->calculate(2);

		for (vector<Point>::iterator it = this->fractal->getResultAllPoint().begin(); it != this->fractal->getResultAllPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - it->y, this->igetPlayerPosition->igetPosition().x - it->x), 0.0, 200);
		}
	}
	else if (t == 300){
		this->fractal->initialize(Point(258.0, 291.0), 1400, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);

		this->fractal->extractionKeyList('X');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 4 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
		this->fractal->extractionKeyList('Y');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 4 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
		this->fractal->extractionKeyList('F');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 4 == 0)this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
	}
}

BossAttack_5_7_Normal::BossAttack_5_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 800;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 180);

	this->fractal = new LSystem();
}

void BossAttack_5_7_Normal::move(){
	this->count++;

	int t = this->count % 120;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 250));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_7_Normal::attack(){
	int t = this->count % 850;

	if (t == 0){
		this->fractal->initialize(Point(258.0, 291.0), 1400, M_PI / 3, M_PI*GetRand(360) / 180, "F++F++F");
		this->fractal->setRule('F', "F-F++F-F");
		this->fractal->calculate(3);

		for (vector<Point>::iterator it = this->fractal->getResultAllPoint().begin(); it != this->fractal->getResultAllPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - it->y, this->igetPlayerPosition->igetPosition().x - it->x), 0.0, 200);
		}
	}
	else if (t == 400){
		this->fractal->initialize(Point(258.0, 291.0), 1400, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);

		this->fractal->extractionKeyList('X');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 2 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
		this->fractal->extractionKeyList('Y');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 2 == 0) this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
		this->fractal->extractionKeyList('F');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size(); i++){
			if (i % 3 != 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 1.5, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
	}
}

BossAttack_5_7_Hard::BossAttack_5_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 400;
	this->HP_Max_Stand = 300;
	this->HP_Max_Absorb = 1000;
	this->limitTime = 1800;
	this->attackName = "";
	this->initialPosition = Point(258, 180);

	this->fractal = new LSystem();
}

void BossAttack_5_7_Hard::move(){
	this->count++;

	int t = this->count % 120;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(100, 80), Point(416, 250));
	}
	else if (t < 50){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 50));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_7_Hard::attack(){
	int t = this->count % 600;
	
	if (t == 0){
		this->fractal->initialize(Point(258.0,291.0), 1400, M_PI / 3, M_PI*GetRand(360) / 180, "F++F++F");
		this->fractal->setRule('F', "F-F++F-F");
		this->fractal->calculate(3);

		for (vector<Point>::iterator it = this->fractal->getResultAllPoint().begin(); it != this->fractal->getResultAllPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - it->y, this->igetPlayerPosition->igetPosition().x - it->x), 0.0, 200);
		}
	}
	else if (t == 300){
		this->fractal->initialize(Point(258.0, 291.0), 1400, M_PI / 2, M_PI*GetRand(360) / 180, "XYXYXYX+XYXYXYX+XYXYXYX+XYXYXYX");
		this->fractal->setRule('F', "");
		this->fractal->setRule('X', "FX+FX+FXFY-FY-");
		this->fractal->setRule('Y', "+FX+FXFY-FY-FY");
		this->fractal->calculate(1);

		this->fractal->extractionKeyList('X');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - it->y, this->igetPlayerPosition->igetPosition().x - it->x), 0.0, 500);
		}
		this->fractal->extractionKeyList('Y');
		for (vector<Point>::iterator it = this->fractal->getResultKeyPoint().begin(); it != this->fractal->getResultKeyPoint().end(); ++it){
			this->isetBullet->isetBossBullet(*it, Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - it->y, this->igetPlayerPosition->igetPosition().x - it->x), 0.0, 500);
		}
		this->fractal->extractionKeyList('F');
		for (unsigned int i = 0; i < this->fractal->getResultKeyPoint().size();i++){
			if (i % 2 == 0) continue;
			this->isetBullet->isetBossBullet(this->fractal->getResultKeyPoint()[i], Bul_Niddle, (BulletColor)GetRand(7), 0, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, atan2(this->igetPlayerPosition->igetPosition().y - this->fractal->getResultKeyPoint()[i].y, this->igetPlayerPosition->igetPosition().x - this->fractal->getResultKeyPoint()[i].x), 0.0, 500);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////BossAttack_5_8//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BossAttack_5_8_Easy::BossAttack_5_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 1000;
	this->HP_Max_Stand = 1000;
	this->HP_Max_Absorb = 2000;
	this->limitTime = 6400;
	this->attackName = "大地が見た夢";
	this->initialPosition = Point(258, 120);

	this->tree[0] = new LSystem();
	this->tree[1] = new LSystem();
	this->flower = new LSystem();
}

void BossAttack_5_8_Easy::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 250));
	}
	else if (t < 40){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 40));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_8_Easy::attack(){
	int t = this->count % 3200;

	//雨
	if (t < 500){
		if (GetRand(3) == 0) this->isetBullet->isetBossBullet(Point(GetRand(1.5*GAME_WINDOW_WIDTH), -40.0) + Point(-0.5*GAME_WINDOW_WIDTH, 0.0), Bul_Crystal, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 3 + M_PI*GetRand(10) / 180, 0.0, 200);
	}

	//春
	if (t < 150){
		//
	}
	else if (t == 150){
		this->tree[0]->initialize(Point(258.0, 300.0), 400, M_PI / 6, M_PI * 3 / 2, "FX");
		this->tree[0]->setRule('F', "FF-[-A+A]+[+A-A]");
		this->tree[0]->setRule('A', "FF-[-F+F]+[+F-F]");
		this->tree[0]->setRule('X', "X=FF+[+F]+[-F]");
		this->tree[0]->calculate(2);
		this->tree[0]->extractionKeyList('A');

		this->tree[1]->initialize(Point(258.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "FF-[-F+A+A]+[+F-A-A]");
		this->tree[1]->setRule('A', "FF-[-F+F+F]+[+F-F-F]");
		this->tree[1]->calculate(2);
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);

		this->flower->initialize(Point(258.0, 250.0), 500, M_PI / 6, M_PI * 5 / 3, "F");
		this->flower->setRule('F', "FF[-F++A][+F--F]++F--F");
		this->flower->setRule('A', "FF[-F++A][+F--F]++F--F");
		this->flower->calculate(2);
		this->flower->extractionKeyList('A');
	}
	else if (t <= 460){
		if (t <= 400){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 150 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 150)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 900 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Yellow, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 500 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}

		for (unsigned int i = (t - 150 - 1)*this->flower->getResultAllPoint().size() / 310; i < (t - 150)*this->flower->getResultAllPoint().size() / 310; i++){
			this->isetBullet->isetBossBullet(this->flower->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1250 - t + 200 + i / this->flower->getResultAllPoint().size());
		}
		for (unsigned int i = (t - 150 - 1)*this->flower->getResultKeyPoint().size() / 310; i < (t - 150)*this->flower->getResultKeyPoint().size() / 310; i++){
			this->isetBullet->isetBossBullet(this->flower->getResultKeyPoint()[i], Bul_Middle, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1200 - t + 100 + i / this->flower->getResultAllPoint().size());
		}
	}

	//冬
	if ((t > 1500) && (t < 2000)){
		if (GetRand(4) == 0) {
			this->isetBullet->isetBossBullet(Point(GetRand(1.2*GAME_WINDOW_WIDTH), -40.0) + Point(-0.1*GAME_WINDOW_WIDTH, 0.0), Bul_Snow, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 3 + M_PI*GetRand(60) / 180, (50.0 + 1.0*GetRand(100)) / 100, 100, 10.0);
		}
	}

	if (t < 1400){

	}
	else if (t == 1400){
		this->tree[0]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "X");
		this->tree[0]->setRule('F', "FF");
		this->tree[0]->setRule('X', "F-[[X]+X]+F[+FX]-X");
		this->tree[0]->calculate(3);
		this->tree[0]->sortFromDown();
		this->tree[0]->extractionKeyList('X');

		this->tree[1]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "+-FF[+FA][-A]F[-A]");
		this->tree[1]->setRule('A', "+-FF[+FF][-F]F[-F]");
		this->tree[1]->calculate(2);
		this->tree[1]->sortFromDown();
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);
	}
	else if (t < 1710){
		if (t < 1650){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 1400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 2600 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1650 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 1650)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					if ((this->tree_kind[(i + 1) / 2] == 0) && (j % 2 == 0)) continue;
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 2100 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}
	}
}

BossAttack_5_8_Normal::BossAttack_5_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 3000;
	this->HP_Max_Stand = 2500;
	this->HP_Max_Absorb = 2500;
	this->limitTime = 6400;
	this->attackName = "大地が見た夢";
	this->initialPosition = Point(258, 120);

	this->tree[0] = new LSystem();
	this->tree[1] = new LSystem();
	this->flower = new LSystem();
}

void BossAttack_5_8_Normal::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(50, 50), Point(466, 250));
	}
	else if (t < 40){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 40));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_8_Normal::attack(){
	int t = this->count % 3200;

	//雨
	if (t < 500){
		if (GetRand(2) == 0) this->isetBullet->isetBossBullet(Point(GetRand(1.5*GAME_WINDOW_WIDTH), -40.0) + Point(-0.5*GAME_WINDOW_WIDTH, 0.0), Bul_Crystal, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 3 + M_PI*GetRand(10) / 180, 0.0, 200);
	}

	//春
	if (t < 150){
		//
	}
	else if (t == 150){
		this->tree[0]->initialize(Point(258.0, 300.0), 400, M_PI / 6, M_PI * 3 / 2, "FX");
		this->tree[0]->setRule('F', "FF-[-A+A]+[+A-A]");
		this->tree[0]->setRule('A', "FF-[-F+F]+[+F-F]");
		this->tree[0]->setRule('X', "X=FF+[+F]+[-F]");
		this->tree[0]->calculate(3);
		this->tree[0]->extractionKeyList('A');

		this->tree[1]->initialize(Point(258.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "FF-[-F+A+A]+[+F-A-A]");
		this->tree[1]->setRule('A', "FF-[-F+F+F]+[+F-F-F]");
		this->tree[1]->calculate(3);
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);

		this->flower->initialize(Point(258.0, 250.0), 500, M_PI / 6, M_PI * 5 / 3, "F");
		this->flower->setRule('F', "FF[-F++A][+F--F]++F--F");
		this->flower->setRule('A', "FF[-F++A][+F--F]++F--F");
		this->flower->calculate(3);
		this->flower->extractionKeyList('A');
	}
	else if (t <= 460){
		if (t <= 400){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 150 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 150)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					if (j % 3 == 0) this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 900 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					if (j % 3 != 0) continue;
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Yellow, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 500 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}

		for (unsigned int i = (t - 150 - 1)*this->flower->getResultAllPoint().size() / 310; i < (t - 150)*this->flower->getResultAllPoint().size() / 310; i++){
			if (i % 4 != 1) this->isetBullet->isetBossBullet(this->flower->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1250 - t + 200 + i / this->flower->getResultAllPoint().size());
		}
		for (unsigned int i = (t - 150 - 1)*this->flower->getResultKeyPoint().size() / 310; i < (t - 150)*this->flower->getResultKeyPoint().size() / 310; i++){
			if (i % 3 != 1) this->isetBullet->isetBossBullet(this->flower->getResultKeyPoint()[i], Bul_Middle, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1200 - t + 100 + i / this->flower->getResultAllPoint().size());
		}
	}

	//冬
	if ((t > 1500) && (t < 2000)){
		if (GetRand(4) == 0) {
			this->isetBullet->isetBossBullet(Point(GetRand(1.2*GAME_WINDOW_WIDTH), -40.0) + Point(-0.1*GAME_WINDOW_WIDTH, 0.0), Bul_Snow, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 3 + M_PI*GetRand(60) / 180, (50.0 + 1.0*GetRand(100)) / 100, 100, 30.0);
		}
	}

	if (t < 1400){

	}
	else if (t == 1400){
		this->tree[0]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "X");
		this->tree[0]->setRule('F', "FF");
		this->tree[0]->setRule('X', "F-[[X]+X]+F[+FX]-X");
		this->tree[0]->calculate(4);
		this->tree[0]->sortFromDown();
		this->tree[0]->extractionKeyList('X');

		this->tree[1]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "+-FF[+FA][-A]F[-A]");
		this->tree[1]->setRule('A', "+-FF[+FF][-F]F[-F]");
		this->tree[1]->calculate(3);
		this->tree[1]->sortFromDown();
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);
	}
	else if (t < 1710){
		if (t < 1650){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 1400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					if (j % 4 != 0) this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 2600 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1650 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 1650)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					if (j % 6 != 0) continue;
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 2100 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}
	}
}

BossAttack_5_8_Hard::BossAttack_5_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBossBullet, int mode) : BossAttack(igetPlayerPosition, igetBossPosition, isetBossBullet, mode){
	this->HP_Max_Explode = 6000;
	this->HP_Max_Stand = 3500;
	this->HP_Max_Absorb = 3000;
	this->limitTime = 6400;
	this->attackName = "大地が見た夢";
	this->initialPosition = Point(258, 120);

	this->tree[0] = new LSystem();
	this->tree[1] = new LSystem();
	this->flower = new LSystem();
}

void BossAttack_5_8_Hard::move(){
	this->count++;

	int t = this->count % 200;
	if (t == 0){
		this->moveFrom = this->igetBossPosition->igetPosition();
		this->moveTo = this->getSquareRandomMovePosition(Point(120, 120), Point(396, 250));
	}
	else if (t < 40){
		this->isetBossInfo->isetPosition(this->getAccelMovePoint(this->moveFrom, this->moveTo, t, 40));
		this->isetBossInfo->isetTransRad(atan2(this->moveTo.y - this->moveFrom.y, this->moveTo.x - this->moveFrom.x));
	}
	else{
		this->isetBossInfo->isetTransRad(M_PI / 2);
	}
}

void BossAttack_5_8_Hard::attack(){
	int t = this->count % 3200;

	//雨
	if (t < 500){
		if(GetRand(1)==0) this->isetBullet->isetBossBullet(Point(GetRand(1.5*GAME_WINDOW_WIDTH), -40.0) + Point(-0.5*GAME_WINDOW_WIDTH, 0.0), Bul_Crystal, Bul_Blue, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, M_PI / 3 + M_PI*GetRand(10) / 180, 0.0, 200);
	}

	//春
	if (t < 150){
		//
	}
	else if (t == 150){
		this->tree[0]->initialize(Point(258.0, 300.0), 400, M_PI / 6, M_PI * 3 / 2, "FX");
		this->tree[0]->setRule('F', "FF-[-A+A]+[+A-A]");
		this->tree[0]->setRule('A', "FF-[-F+F]+[+F-F]");
		this->tree[0]->setRule('X', "X=FF+[+F]+[-F]");
		this->tree[0]->calculate(3);
		this->tree[0]->extractionKeyList('A');

		this->tree[1]->initialize(Point(258.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "FF-[-F+A+A]+[+F-A-A]");
		this->tree[1]->setRule('A', "FF-[-F+F+F]+[+F-F-F]");
		this->tree[1]->calculate(3);
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);

		this->flower->initialize(Point(258.0, 250.0), 500, M_PI / 6, M_PI * 5 / 3, "F");
		this->flower->setRule('F', "FF[-F++A][+F--F]++F--F");
		this->flower->setRule('A', "FF[-F++A][+F--F]++F--F");
		this->flower->calculate(3);
		this->flower->extractionKeyList('A');
	}
	else if (t <= 460){
		if (t <= 400){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 150 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 150)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 900 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					if (j % 2 == 0) continue;
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Yellow, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 500 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}
		
		for (unsigned int i = (t - 150 - 1)*this->flower->getResultAllPoint().size() / 310; i < (t - 150)*this->flower->getResultAllPoint().size() / 310; i++){
			this->isetBullet->isetBossBullet(this->flower->getResultAllPoint()[i], Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1250 - t + 200 + i / this->flower->getResultAllPoint().size());
		}
		for (unsigned int i = (t - 150 - 1)*this->flower->getResultKeyPoint().size() / 310; i < (t - 150)*this->flower->getResultKeyPoint().size() / 310; i++){
			this->isetBullet->isetBossBullet(this->flower->getResultKeyPoint()[i], Bul_Middle, Bul_Purple, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.02, M_PI*GetRand(360) / 180, 0.0, 20, 1200 - t + 100 + i / this->flower->getResultAllPoint().size());
		}
	}

	//冬
	if ((t > 1500) && (t < 2000)){
		if (GetRand(3) == 0) {
			this->isetBullet->isetBossBullet(Point(GetRand(1.2*GAME_WINDOW_WIDTH), -40.0) + Point(-0.1*GAME_WINDOW_WIDTH, 0.0), Bul_Snow, Bul_White, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, M_PI / 3 + M_PI*GetRand(60) / 180, (50.0+1.0*GetRand(100))/100, 100, 100.0);
		}
	}

	if (t < 1400){

	}
	else if (t == 1400){
		this->tree[0]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "X");
		this->tree[0]->setRule('F', "FF");
		this->tree[0]->setRule('X', "F-[[X]+X]+F[+FX]-X");
		this->tree[0]->calculate(4);
		this->tree[0]->sortFromDown();
		this->tree[0]->extractionKeyList('X');

		this->tree[1]->initialize(Point(358.0, 240.0), 400, M_PI / 6, M_PI * 3 / 2, "F");
		this->tree[1]->setRule('F', "+-FF[+FA][-A]F[-A]");
		this->tree[1]->setRule('A', "+-FF[+FF][-F]F[-F]");
		this->tree[1]->calculate(3);
		this->tree[1]->sortFromDown();
		this->tree[1]->extractionKeyList('A');

		this->tree_kind[0] = GetRand(1);
		this->tree_kind[1] = GetRand(1);
	}
	else if (t < 1710){
		if (t < 1650){
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1400 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j < (t - 1400)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size() / 250; j++){
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint()[j] + Point(120.0*i, 0.0), Bul_Small, Bul_Orange, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI*GetRand(360) / 180, 0.0, 20, 2600 - t + 450 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultAllPoint().size());
				}
			}
		}
		else{
			for (int i = -1; i <= 1; i += 2){
				for (unsigned int j = (t - 1650 - 1)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j < (t - 1650)*this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size() / 60; j++){
					if (j % 2 == 0) continue;
					this->isetBullet->isetBossBullet(this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint()[j] + Point(120.0*i, 0.0), Bul_Middle, Bul_Green, 11, this->isetBullet, this->igetPlayerPosition, 2.0, 0.01, M_PI / 6 + M_PI*GetRand(120) / 180, 0.0, 20, 2100 - t + 350 * j / this->tree[this->tree_kind[(i + 1) / 2]]->getResultKeyPoint().size());
				}
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////