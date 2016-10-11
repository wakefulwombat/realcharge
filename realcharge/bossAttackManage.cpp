#include "bossAttackManage.h"
#include "bossAttack_1.h"
#include "bossAttack_2.h"
#include "bossAttack_3.h"
#include "bossAttack_4.h"
#include "bossAttack_5.h"
#include "bossAttack_6.h"
#include "bossAttack_7.h"

BossAttackManage::BossAttackManage(IGetStage* igetStage, IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetBullet* isetBullet, int playerMode){
	this->igetStage = igetStage;
	this->igetBoss = igetBoss;
	this->igetPlayerPosition = igetPlayerPosition;
	this->isetBullet = isetBullet;
	this->playerMode = playerMode;

	this->attackNumCount = 0;
}

BossAttackManage::BossAttackManage(IGetStage* igetStage, IGetBoss* igetBoss, IGetPosition* igetPlayerPosition, ISetBullet* isetBullet, ISetEnemyLazer* isetLazer, int playerMode){
	this->igetStage = igetStage;
	this->igetBoss = igetBoss;
	this->igetPlayerPosition = igetPlayerPosition;
	this->isetBullet = isetBullet;
	this->isetLazer = isetLazer;
	this->playerMode = playerMode;

	this->attackNumCount = 0;
}

bool BossAttackManage::isAllAttackOfStageEnd(){
	switch (this->igetStage->igetStage()){
	case 1:
		if (this->attackNumCount != 4) return false;
		else return true;
		break;

	case 2:
		if (this->attackNumCount != 6) return false;
		else return true;
		break;

	case 3:
		if (this->attackNumCount != 6) return false;
		else return true;
		break;

	case 4:
		if (this->attackNumCount != 8) return false;
		else return true;
		break;

	case 5:
		if (this->attackNumCount != 8) return false;
		else return true;
		break;

	case 6:
		if (this->attackNumCount != 8) return false;
		else return true;
		break;

	case 7:
		if (this->attackNumCount != 18) return false;
		else return true;
		break;
	}
	return true;
}

int BossAttackManage::getHowManyBossAttackInBattle(){
	switch (this->igetStage->igetStage()){
	case 1:
		return 4;
		break;

	case 2:
		return 6;
		break;

	case 3:
		return 6;
		break;

	case 4:
		return 8;
		break;

	case 5:
		return 8;
		break;

	case 6:
		return 8;
		break;

	case 7:
		return 18;
		break;
	}
	return -1;
}

int BossAttackManage::getHowManyBossActorInBattle(){
	switch (this->igetStage->igetStage()){
	case 1:
		return 1;
		break;

	case 2:
		return 1;
		break;

	case 3:
		return 1;
		break;

	case 4:
		return 1;
		break;

	case 5:
		return 1;
		break;

	case 6:
		return 1;
		break;

	case 7:
		return 1;
		break;
	}
	return -1;
}

BossAttack* BossAttackManage::igetBossAttack(int id){
	switch (this->igetStage->igetStage())
	{
	case 1:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_1_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_1_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_1_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_1_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_1_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_1_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_1_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_1_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_1_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_1_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_1_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_1_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;
		}
		break;

	case 2:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 4:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_5_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_5_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_5_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 5:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_2_6_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_2_6_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_2_6_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;
		}
		break;

	case 3:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 4:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_5_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_5_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_5_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 5:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_3_6_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_3_6_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_3_6_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;
		}
		break;

	case 4:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 4:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_5_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_5_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_5_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 5:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_6_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_6_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_6_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 6:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_7_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_7_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_7_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 7:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_4_8_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_4_8_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_4_8_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;
		}
		break;

	case 5:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 4:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_5_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_5_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_5_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 5:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_6_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_6_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_6_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 6:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_7_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_7_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_7_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 7:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_5_8_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_5_8_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_5_8_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		}
		break;

	case 6:
		switch (this->attackNumCount)
		{
		case 0:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_1_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_1_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_1_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 1:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_2_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_2_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_2_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 2:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_3_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_3_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_3_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 3:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_4_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_4_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_4_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 4:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_5_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_5_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_5_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 5:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_6_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_6_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_6_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 6:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_7_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_7_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_7_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		case 7:
			if (this->igetStage->igetDifficulty() == 0){
				if (id == 0) return (new BossAttack_6_8_Easy(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 1){
				if (id == 0) return (new BossAttack_6_8_Normal(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			if (this->igetStage->igetDifficulty() == 2){
				if (id == 0) return (new BossAttack_6_8_Hard(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->playerMode));
			}
			break;

		}
		break;

	case 7:
		switch (this->attackNumCount)
		{
		case 0:
			if (id == 0) return (new BossAttack_7_1(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 1:
			if (id == 0) return (new BossAttack_7_2(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 2:
			if (id == 0) return (new BossAttack_7_3(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 3:
			if (id == 0) return (new BossAttack_7_4(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 4:
			if (id == 0) return (new BossAttack_7_5(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 5:
			if (id == 0) return (new BossAttack_7_6(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 6:
			if (id == 0) return (new BossAttack_7_7(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 7:
			if (id == 0) return (new BossAttack_7_8(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 8:
			if (id == 0) return (new BossAttack_7_9(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 9:
			if (id == 0) return (new BossAttack_7_10(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 10:
			if (id == 0) return (new BossAttack_7_11(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 11:
			if (id == 0) return (new BossAttack_7_12(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 12:
			if (id == 0) return (new BossAttack_7_13(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 13:
			if (id == 0) return (new BossAttack_7_14(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 14:
			if (id == 0) return (new BossAttack_7_15(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 15:
			if (id == 0) return (new BossAttack_7_16(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 16:
			if (id == 0) return (new BossAttack_7_17(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;

		case 17:
			if (id == 0) return (new BossAttack_7_18(this->igetPlayerPosition, this->igetBoss->igetBoss(0), this->isetBullet, this->isetLazer, this->playerMode));
			break;
		}
		break;
	}

	return NULL;
}