#include "enemyLazer.h"
#include "DxLib.h"
#include "picture.h"

EnemyLazer::EnemyLazer(Point start, BulletColor color, int movePattern, int maxDivNum, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1, double param2, double param3) : EnemyLazerBase(maxDivNum){
	this->count = 0;
	this->divCount = 0;
	this->lazerDiv.clear();

	this->start = start;
	this->color = color;
	this->movePattern = movePattern;
	this->trans_vel = trans_vel0;
	this->trans_acc = trans_acc;
	this->trans_rad = trans_rad0;
	this->rotate_vel = rotate_vel;
	this->disappTime_min = disappTime_min;
	this->param1 = param1;
	this->param2 = param2;
	this->param3 = param3;
}

void EnemyLazer::initialize(){
	this->count = 0;
	this->divCount = 0;
	this->lazerDiv.clear();
}

void EnemyLazer::update(){
	if (this->divCount<this->maxDivNum){
		ShockLazerDiv tmp;
		tmp.count = 0;
		tmp.validated = true;
		tmp.center = this->start;
		tmp.before_center = this->start;
		tmp.rotate_rad = 0.0;
		tmp.before_rotate_rad = 0.0;

		this->lazerDiv.push_back(tmp);
		this->divCount++;
	}

	int sum = 0;
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;
		sum++;

		if (this->lazerDiv[i].count > this->disappTime_min){
			if (this->lazerDiv[i].center.x < -this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.y < -this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.x > GAME_WINDOW_WIDTH + this->size.height) this->lazerDiv[i].validated = false;
			if (this->lazerDiv[i].center.y > GAME_WINDOW_HEIGHT + this->size.height) this->lazerDiv[i].validated = false;
		}

		if (this->lazerDiv[i].isInColding == true){
			if (i != 0){
				if (this->lazerDiv[i - 1].isInColding == false){
					this->lazerDiv[i - 1].validated = false;
				}
			}
			continue;
		}

		this->lazerDiv[i].count++;
		if (i == 0){
			this->lazerDiv[0].before_center = this->lazerDiv[0].center;
			this->lazerDiv[0].center = this->getMoveNextPos(this->lazerDiv[0].center, this->lazerDiv[0].count);
			this->lazerDiv[0].before_rotate_rad = this->lazerDiv[0].rotate_rad;
			this->lazerDiv[0].rotate_rad = atan2(this->lazerDiv[0].before_center.y - this->lazerDiv[0].center.y, this->lazerDiv[0].before_center.x - this->lazerDiv[0].center.x) + M_PI / 2;
		}
		else{
			if (this->lazerDiv[i - 1].validated == false){
				this->lazerDiv[i].before_center = this->lazerDiv[i].center;
				this->lazerDiv[i].center = this->getMoveNextPos(this->lazerDiv[i].center, this->lazerDiv[i].count);
				this->lazerDiv[i].before_rotate_rad = this->lazerDiv[i].rotate_rad;
				this->lazerDiv[i].rotate_rad = atan2(this->lazerDiv[i].before_center.y - this->lazerDiv[i].center.y, this->lazerDiv[i].before_center.x - this->lazerDiv[i].center.x) + M_PI / 2;
			}
			else{
				this->lazerDiv[i].before_center = this->lazerDiv[i].center;
				this->lazerDiv[i].center = this->lazerDiv[i - 1].before_center;
				this->lazerDiv[i].before_rotate_rad = this->lazerDiv[i].rotate_rad;
				this->lazerDiv[i].rotate_rad = this->lazerDiv[i - 1].before_rotate_rad;
			}
		}
	}
	if (this->lazerDiv.size() != 0){
		if (sum == 0) this->validated = false;
	}
}

void EnemyLazer::draw(){
	SetDrawBlendMode(DX_BLENDMODE_ADD, 30);
	for (unsigned int i = 0; i<this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false)continue;
		DrawRotaGraph3(GAME_WINDOW_OFFSET_X + Round(this->lazerDiv[i].center.x), GAME_WINDOW_OFFSET_Y + Round(this->lazerDiv[i].center.y)
			, this->size.width / 2, this->size.height / 2, 1.0, 3.5, this->lazerDiv[i].rotate_rad, Picture::getBullet(Bul_Lazer, this->color), true);
	}
}

void EnemyLazer::finalize(){

}

Point EnemyLazer::getMoveNextPos(Point pos,int count){
	Point tmp;
	switch (this->movePattern){
	case 0://’¼i
		tmp.x = pos.x + this->trans_vel*cos(this->trans_rad);
		tmp.y = pos.y + this->trans_vel*sin(this->trans_rad);
		break;

	case 1://’¼i‰Á‘¬
		tmp.x = pos.x + (this->trans_vel + this->trans_acc*count)*cos(this->trans_rad);
		tmp.y = pos.y + (this->trans_vel + this->trans_acc*count)*sin(this->trans_rad);
		break;

	case 2://â‘Î’l’¼i‰Á‘¬
		tmp.x = pos.x + abs((this->trans_vel + this->trans_acc*count))*cos(this->trans_rad);
		tmp.y = pos.y + abs((this->trans_vel + this->trans_acc*count))*sin(this->trans_rad);
		break;

	case 3://‰ñ“](”¼Œa•ûŒü“™‘¬AÚü•ûŒüŠp‘¬“xˆê’è) ”¼Œa•ûŒü‘¬“x:trans_vel  Úü•ûŒü‘¬“x:rotate_vel ‰ŠúŠp“x:trans_rad
		tmp.x = pos.x + this->trans_vel*cos(this->rotate_vel*count + this->trans_rad) - this->trans_vel*this->rotate_vel*count*sin(this->rotate_vel*count + this->trans_rad);
		tmp.y = pos.y + this->trans_vel*sin(this->rotate_vel*count + this->trans_rad) + this->trans_vel*this->rotate_vel*count*cos(this->rotate_vel*count + this->trans_rad);
		break;

	case 4://y•ûŒü‚É‰Á‘¬“x trans_rad(‰ŠúŠp“x)
		tmp.x = pos.x + this->trans_vel*cos(this->trans_rad);
		tmp.y = pos.y + this->trans_acc*count + this->trans_vel*sin(this->trans_rad);
		break;

	case 5://sin(r:param1 omega:rotate_vel, ‰ŠúŠp“x:param2)
		tmp.x = pos.x + cos(this->trans_rad)*this->trans_vel - sin(this->trans_rad)*this->param1*(this->rotate_vel)*cos((this->rotate_vel)*count + this->param2);
		tmp.y = pos.y + sin(this->trans_rad)*this->trans_vel + cos(this->trans_rad)*this->param1*(this->rotate_vel)*cos((this->rotate_vel)*count + this->param2);
		break;

	case 6://x•Ç”½ŽË(param1:Å‘å”½ŽË‰ñ”: param2:”½ŽË‰ñ”ƒJƒEƒ“ƒ^0‚Å‰Šú‰»)
		if ((int)this->param2 < (int)this->param1){
			if (pos.x < 0){
				this->trans_rad = M_PI - this->trans_rad;
				this->param2 += 1.0;
			}
			if (pos.x > GAME_WINDOW_WIDTH){
				this->trans_rad = M_PI - this->trans_rad;
				this->param2 += 1.0;
			}
		}
		tmp.x = pos.x + this->trans_vel*cos(this->trans_rad);
		tmp.y = pos.y + this->trans_vel*sin(this->trans_rad);
		break;
	}
	return tmp;
}

void EnemyLazer::setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX){
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;

		if ((this->lazerDiv[i].center.x - center.x)*(this->lazerDiv[i].center.x - center.x) + (this->lazerDiv[i].center.y - center.y)*(this->lazerDiv[i].center.y - center.y) < r*r){
			this->lazerDiv[i].validated = false;
			isetStandShockLazerEX->isetStandShockLazerEX(this->lazerDiv[i].center);
		}
	}
}

void EnemyLazer::setStandFlex(Point center, int r, ISetStandShockLazerEX* isetStandShockLazerEX, Point bossPos){
	for (unsigned int i = 0; i < this->lazerDiv.size(); i++){
		if (this->lazerDiv[i].validated == false) continue;

		if ((this->lazerDiv[i].center.x - center.x)*(this->lazerDiv[i].center.x - center.x) + (this->lazerDiv[i].center.y - center.y)*(this->lazerDiv[i].center.y - center.y) < r*r){
			this->lazerDiv[i].validated = false;
			if ((this->lazerDiv[i].center.x - bossPos.x)*(this->lazerDiv[i].center.x - bossPos.x) + (this->lazerDiv[i].center.y - bossPos.y)*(this->lazerDiv[i].center.y - bossPos.y) > 10000){
				isetStandShockLazerEX->isetStandShockLazerEX(this->lazerDiv[i].center);
			}
		}
	}
}