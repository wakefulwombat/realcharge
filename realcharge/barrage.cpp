#include "barrage.h"
#include "bullet.h"
#include <math.h>
#include "DxLib.h"

Barrage::Barrage(StaticBarrageData* staticBarrageData,int enemyCSVIndex,int barrageCSVID,Point position,ISetBullet* isetBullet,IGetPosition* igetPlayerPosition,IGetPosition* igetEnemyPosition){
	this->staticBarrageData = staticBarrageData;
	this->enemyCSVIndex = enemyCSVIndex;
	this->barrageCSVID = barrageCSVID;
	this->position = position;
	this->isetBullet = isetBullet;
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetEnemyPosition = igetEnemyPosition;

	this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-position.y,this->igetPlayerPosition->igetPosition().x-position.x);
	this->rotate_rad = 0.0;

	this->small_group_num_c=0;
	this->small_group_time_c=staticBarrageData->smallGroupWaitingTime;
	this->large_group_num_c=0;
	this->large_group_time_c=0;
	this->total_group_num_c=0;
}

Barrage::Barrage(StaticBarrageData* staticBarrageData, int enemyCSVIndex, int barrageCSVID, Point position, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, IGetPosition* igetEnemyPosition, ISetEnemyLazer* isetEnemyLazer){
	this->staticBarrageData = staticBarrageData;
	this->enemyCSVIndex = enemyCSVIndex;
	this->barrageCSVID = barrageCSVID;
	this->position = position;
	this->isetBullet = isetBullet;
	this->isetEnemyLazer = isetEnemyLazer;
	this->igetPlayerPosition = igetPlayerPosition;
	this->igetEnemyPosition = igetEnemyPosition;

	this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y - position.y, this->igetPlayerPosition->igetPosition().x - position.x);
	this->rotate_rad = 0.0;

	this->small_group_num_c = 0;
	this->small_group_time_c = staticBarrageData->smallGroupWaitingTime;
	this->large_group_num_c = 0;
	this->large_group_time_c = 0;
	this->total_group_num_c = 0;
}

void Barrage::initialize(){

}

void Barrage::update(){
	if (this->validated == false) return;

	if(this->total_group_num_c >= this->staticBarrageData->totalGroupNum){
		this->validated=false;
		return;
	}

	if (this->count > this->staticBarrageData->disappearTime_min){
		if ((this->position.x<-10.0) || (this->position.x>GAME_WINDOW_WIDTH + 10.0) || (this->position.y<-10.0) || (this->position.y>GAME_WINDOW_HEIGHT + 10.0)){
			this->validated = false;
			return;
		}
	}

	this->move();
	this->shotBullet();
}

void Barrage::finalize(){

}

void Barrage::move(){
	switch(this->staticBarrageData->movePattern){
	case 0://敵追尾
		this->position = this->igetEnemyPosition->igetPosition();
		break;

	case 1://直進
		this->position.x += this->staticBarrageData->trans_vel*cos(this->staticBarrageData->trans_rad);
		this->position.y += this->staticBarrageData->trans_vel*sin(this->staticBarrageData->trans_rad);
		break;

	case 2://半径50
		this->position = this->igetEnemyPosition->igetPosition();
		this->position.x += 50.0*cos(this->rotate_rad);
		this->position.y += 50.0*sin(this->rotate_rad);
		this->rotate_rad += this->staticBarrageData->rotate_vel;
		break;
	}
}

void Barrage::shotBullet(){
	if(this->total_group_num_c >= this->staticBarrageData->totalGroupNum){
		this->validated = false;
		return;
	}

	switch(this->staticBarrageData->barragePattern){
	case 0://単発自機狙い
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
					this->position,
					this->staticBarrageData->staticBulletData.trans_vel,
					this->staticBarrageData->staticBulletData.trans_acc,
					atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x),
					this->staticBarrageData->staticBulletData.rotate_vel,
					0.0,
					atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x)+M_PI/2,
					this->isetBullet);
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 1://複数自機狙い bar_param1:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param1*i,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x),
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x)+M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 2://n-way bar_param1:展開角度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 3://n-way複数 bar_param1:展開角度 bar_param2:弾数  bar_param3:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param2);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(
							&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param3*i,
							this->staticBarrageData->staticBulletData.trans_acc,
							atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
							this->isetBullet
						);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 4://円形
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + M_PI*2.0*i/this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + M_PI*2.0*i/this->staticBarrageData->smallGroupBulletNum + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 5://複数円形 bar_param1:弾数 bar_param2:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param1);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param2*i,
							this->staticBarrageData->staticBulletData.trans_acc,
							atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + M_PI*2.0*j/this->staticBarrageData->smallGroupBulletNum,
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + M_PI*2.0*j/this->staticBarrageData->smallGroupBulletNum + M_PI/2,
							this->isetBullet);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 6://記憶自機狙い
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
					this->position,
					this->staticBarrageData->staticBulletData.trans_vel,
					this->staticBarrageData->staticBulletData.trans_acc,
					this->tmp_shot_rad,
					this->staticBarrageData->staticBulletData.rotate_vel,
					0.0,
					this->tmp_shot_rad+M_PI/2,
					this->isetBullet);
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 7://記憶複数自機狙い bar_param1:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param1*i,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->tmp_shot_rad,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->tmp_shot_rad + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 8://記憶n-way bar_param1:展開角度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->tmp_shot_rad + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->tmp_shot_rad + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 9://記憶複数n-way bar_param1:展開角度 bar_param2:弾数  bar_param3:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param2);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(
							&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param1*i,
							this->staticBarrageData->staticBulletData.trans_acc,
							this->tmp_shot_rad + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							this->tmp_shot_rad + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
							this->isetBullet
						);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 10://固定n-way bar_param1:展開角度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->staticBarrageData->staticBulletData.trans_rad + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->staticBarrageData->staticBulletData.trans_rad + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 11://固定n-way複数 bar_param1:展開角度 bar_param2:弾数  bar_param3:速度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param2);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(
							&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param3*i,
							this->staticBarrageData->staticBulletData.trans_acc,
							this->staticBarrageData->staticBulletData.trans_rad + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2,
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							this->staticBarrageData->staticBulletData.trans_rad + this->staticBarrageData->param1*M_PI/180*j/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + M_PI/2,
							this->isetBullet
						);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 12://円形ばらまき
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->tmp_shot_rad = 1.0*GetRand(Round(M_PI*20000))/10000.0;
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->tmp_shot_rad,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->tmp_shot_rad + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 13://自機狙いばらまき bar_param1:展開角度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->tmp_shot_rad = 1.0*GetRand(Round(M_PI*this->staticBarrageData->param1/180*20000))/10000.0;
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->tmp_shot_rad - M_PI*this->staticBarrageData->param1/360,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->tmp_shot_rad - M_PI*this->staticBarrageData->param1/360 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 14://固定角度ばらまき bar_param1:展開角度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->tmp_shot_rad = 1.0*GetRand(Round(M_PI*this->staticBarrageData->param1/180*20000))/10000.0;
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->staticBarrageData->staticBulletData.trans_rad + this->tmp_shot_rad - M_PI*this->staticBarrageData->param1/360,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->staticBarrageData->staticBulletData.trans_rad + this->tmp_shot_rad - M_PI*this->staticBarrageData->param1/360 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 15://円形螺旋弾 bar_param1:旋回角
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->tmp_shot_rad + M_PI*2.0*i/this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						this->tmp_shot_rad + M_PI*2.0*i/this->staticBarrageData->smallGroupBulletNum + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
				this->tmp_shot_rad += this->staticBarrageData->param1*M_PI/180;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 16://複数円形螺旋弾 bar_param1:弾数 bar_param2:速度増加分 bar_param3:螺旋角増加
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param1);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel+this->staticBarrageData->param2*i,
							this->staticBarrageData->staticBulletData.trans_acc,
							this->tmp_shot_rad + M_PI*2.0*j/this->staticBarrageData->smallGroupBulletNum,
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							this->tmp_shot_rad + M_PI*2.0*j/this->staticBarrageData->smallGroupBulletNum + M_PI/2,
							this->isetBullet);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
				this->tmp_shot_rad += this->staticBarrageData->param3*M_PI/180;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 17://塊円形弾螺旋 bar_param1:塊ブロック数 bar_param2:塊ブロック内弾率(%) bar_param3:螺旋角
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<Round(this->staticBarrageData->param1);i++){
					for(int j=0;j<this->staticBarrageData->smallGroupBulletNum;j++){
						this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
							this->position,
							this->staticBarrageData->staticBulletData.trans_vel,
							this->staticBarrageData->staticBulletData.trans_acc,
							this->tmp_shot_rad + M_PI*2.0*i/Round(this->staticBarrageData->param1) + M_PI*2.0*(100.0-this->staticBarrageData->param2)/200.0/Round(this->staticBarrageData->param1) + M_PI*2.0*j*this->staticBarrageData->param2/100.0/this->staticBarrageData->smallGroupBulletNum/Round(this->staticBarrageData->param1) - M_PI/Round(this->staticBarrageData->param1),
							this->staticBarrageData->staticBulletData.rotate_vel,
							0.0,
							this->tmp_shot_rad + M_PI*2.0*i/Round(this->staticBarrageData->param1) + M_PI*2.0*(100.0-this->staticBarrageData->param2)/200.0/Round(this->staticBarrageData->param1) + M_PI*2.0*j*this->staticBarrageData->param2/100.0/this->staticBarrageData->smallGroupBulletNum/Round(this->staticBarrageData->param1) - M_PI/Round(this->staticBarrageData->param1) + M_PI/2,
							this->isetBullet);
					}
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
				this->tmp_shot_rad += this->staticBarrageData->param3*M_PI/180;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 18://増加型扇弾 bar_param1:角度増加分
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				if(this->small_group_num_c==0) this->small_group_num_c=1;
				for(int i=0;i<this->small_group_num_c;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i - this->staticBarrageData->param1*M_PI/180*(this->small_group_num_c-1)/2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i - this->staticBarrageData->param1*M_PI/180*(this->small_group_num_c-1)/2+M_PI/2,
						this->isetBullet);
				}
				this->small_group_num_c++;
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
				this->small_group_num_c=0;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 19://n-way 左右振り  bar_param1:展開角度 bar_param2:展開角度振幅 bar_param2:角速度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + this->staticBarrageData->param2*M_PI/180*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c),
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + this->staticBarrageData->param1*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - this->staticBarrageData->param1*M_PI/180/2 + this->staticBarrageData->param2*M_PI/180*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c) + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 20://n-way 展開角度変化 bar_param1:展開角度 bar_param2:展開角度変位振幅 bar_param3:展開角度変化角速度
		if(this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if(this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for(int i=0;i<this->staticBarrageData->smallGroupBulletNum;i++){
					this->isetBullet->isetBullet(&this->staticBarrageData->staticBulletData,
						this->position,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + (this->staticBarrageData->param1+this->staticBarrageData->param2*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c))*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - (this->staticBarrageData->param1+this->staticBarrageData->param2*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c))*M_PI/180/2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						0.0,
						atan2(this->igetPlayerPosition->igetPosition().y-this->position.y,this->igetPlayerPosition->igetPosition().x-this->position.x) + (this->staticBarrageData->param1+this->staticBarrageData->param2*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c))*M_PI/180*i/(this->staticBarrageData->smallGroupBulletNum-1) - (this->staticBarrageData->param1+this->staticBarrageData->param2*sin(this->staticBarrageData->param3*M_PI/180*this->large_group_num_c))*M_PI/180/2 + M_PI/2,
						this->isetBullet);
				}
				//////////////////////////////////////////////
				this->small_group_time_c=0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if(this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c=0;
				this->large_group_num_c=0;
				this->total_group_num_c++;
				this->small_group_time_c=this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	//for EXTRA//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 21://直進レーザー自機狙い単発(maxDivNum:param1)
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				this->isetEnemyLazer->isetEnemyLazer(this->position,
					this->staticBarrageData->staticBulletData.color,
					this->staticBarrageData->staticBulletData.movePattern,
					this->staticBarrageData->param1,
					this->staticBarrageData->staticBulletData.trans_vel,
					this->staticBarrageData->staticBulletData.trans_acc,
					atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x),
					this->staticBarrageData->staticBulletData.rotate_vel,
					this->staticBarrageData->staticBulletData.disappearTime_min,
					this->staticBarrageData->staticBulletData.param1,
					this->staticBarrageData->staticBulletData.param2,
					this->staticBarrageData->staticBulletData.param3);
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 22://n-way 直進レーザー自機狙い単発(small_group:way数 param1:divNumMax param2:展開角度)
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x) + this->staticBarrageData->param2*M_PI / 180 * i / (this->staticBarrageData->smallGroupBulletNum - 1) - this->staticBarrageData->param2*M_PI / 180 / 2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 23://円形自機狙い(param1:divNumMax small_group:way)
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x) + M_PI * 2 * i / this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 24://固定n-way
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->staticBarrageData->staticBulletData.trans_rad + this->staticBarrageData->param2*M_PI / 180 * i / (this->staticBarrageData->smallGroupBulletNum - 1) - this->staticBarrageData->param2*M_PI / 180 / 2,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 25://固定円形
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->staticBarrageData->staticBulletData.trans_rad + M_PI * 2 * i / this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 26://旋回レーザー(param1:divNumMax param2:旋回角)
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						this->tmp_shot_rad + M_PI*2.0*i / this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
				this->tmp_shot_rad += this->staticBarrageData->param2*M_PI / 180;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 27://ランダムベジェ//param1:arrival time, param2:divNumMax
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				BezierInfo info;
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					info.start = this->igetEnemyPosition->igetPosition();
					info.end = this->igetPlayerPosition->igetPosition();
					info.arriveTime = (int)this->staticBarrageData->param1;
					info.control1 = Point(GetRand(2 * GAME_WINDOW_WIDTH) - GAME_WINDOW_WIDTH / 2, GetRand(GAME_WINDOW_HEIGHT - 100) - 100);
					this->isetEnemyLazer->isetEnemyLazerBezier(info, this->staticBarrageData->staticBulletData.color, this->staticBarrageData->param2, this->staticBarrageData->staticBulletData.disappearTime_min);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
				this->tmp_shot_rad += this->staticBarrageData->param2*M_PI / 180;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
				this->tmp_shot_rad = atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x);
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;

	case 28://円形ランダム
		if (this->large_group_num_c < this->staticBarrageData->largeGroupBulletNum){
			if (this->small_group_time_c >= this->staticBarrageData->smallGroupWaitingTime){
				//////////////////////////////////////////////
				double rad = M_PI*GetRand(360) / 180;
				for (int i = 0; i < this->staticBarrageData->smallGroupBulletNum; i++){
					this->isetEnemyLazer->isetEnemyLazer(this->position,
						this->staticBarrageData->staticBulletData.color,
						this->staticBarrageData->staticBulletData.movePattern,
						this->staticBarrageData->param1,
						this->staticBarrageData->staticBulletData.trans_vel,
						this->staticBarrageData->staticBulletData.trans_acc,
						rad + M_PI * 2 * i / this->staticBarrageData->smallGroupBulletNum,
						this->staticBarrageData->staticBulletData.rotate_vel,
						this->staticBarrageData->staticBulletData.disappearTime_min,
						this->staticBarrageData->staticBulletData.param1,
						this->staticBarrageData->staticBulletData.param2,
						this->staticBarrageData->staticBulletData.param3);
				}
				//////////////////////////////////////////////
				this->small_group_time_c = 0;
				this->large_group_num_c++;
			}
			else{
				this->small_group_time_c++;
			}
		}
		else{
			if (this->large_group_time_c >= this->staticBarrageData->largeGroupWaitingTime){
				this->large_group_time_c = 0;
				this->large_group_num_c = 0;
				this->total_group_num_c++;
				this->small_group_time_c = this->staticBarrageData->smallGroupWaitingTime;
			}
			else{
				this->large_group_time_c++;
			}
		}
		break;
	}
}