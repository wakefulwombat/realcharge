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
	case 0://�G�ǔ�
		this->position = this->igetEnemyPosition->igetPosition();
		break;

	case 1://���i
		this->position.x += this->staticBarrageData->trans_vel*cos(this->staticBarrageData->trans_rad);
		this->position.y += this->staticBarrageData->trans_vel*sin(this->staticBarrageData->trans_rad);
		break;

	case 2://���a50
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
	case 0://�P�����@�_��
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

	case 1://�������@�_�� bar_param1:���x������
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

	case 2://n-way bar_param1:�W�J�p�x
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

	case 3://n-way���� bar_param1:�W�J�p�x bar_param2:�e��  bar_param3:���x������
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

	case 4://�~�`
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

	case 5://�����~�` bar_param1:�e�� bar_param2:���x������
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

	case 6://�L�����@�_��
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

	case 7://�L���������@�_�� bar_param1:���x������
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

	case 8://�L��n-way bar_param1:�W�J�p�x
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

	case 9://�L������n-way bar_param1:�W�J�p�x bar_param2:�e��  bar_param3:���x������
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

	case 10://�Œ�n-way bar_param1:�W�J�p�x
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

	case 11://�Œ�n-way���� bar_param1:�W�J�p�x bar_param2:�e��  bar_param3:���x������
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

	case 12://�~�`�΂�܂�
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

	case 13://���@�_���΂�܂� bar_param1:�W�J�p�x
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

	case 14://�Œ�p�x�΂�܂� bar_param1:�W�J�p�x
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

	case 15://�~�`�����e bar_param1:����p
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

	case 16://�����~�`�����e bar_param1:�e�� bar_param2:���x������ bar_param3:�����p����
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

	case 17://��~�`�e���� bar_param1:��u���b�N�� bar_param2:��u���b�N���e��(%) bar_param3:�����p
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

	case 18://�����^��e bar_param1:�p�x������
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

	case 19://n-way ���E�U��  bar_param1:�W�J�p�x bar_param2:�W�J�p�x�U�� bar_param2:�p���x
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

	case 20://n-way �W�J�p�x�ω� bar_param1:�W�J�p�x bar_param2:�W�J�p�x�ψʐU�� bar_param3:�W�J�p�x�ω��p���x
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
	case 21://���i���[�U�[���@�_���P��(maxDivNum:param1)
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

	case 22://n-way ���i���[�U�[���@�_���P��(small_group:way�� param1:divNumMax param2:�W�J�p�x)
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

	case 23://�~�`���@�_��(param1:divNumMax small_group:way)
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

	case 24://�Œ�n-way
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

	case 25://�Œ�~�`
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

	case 26://���񃌁[�U�[(param1:divNumMax param2:����p)
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

	case 27://�����_���x�W�F//param1:arrival time, param2:divNumMax
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

	case 28://�~�`�����_��
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