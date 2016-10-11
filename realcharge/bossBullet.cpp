#include "bossBullet.h"
#include "DxLib.h"
#include "picture.h"

BossBullet::BossBullet(Point pos, BulletKind kind, BulletColor color, int movePattern, ISetBullet* isetBullet, IGetPosition* igetPlayerPosition, double trans_vel0, double trans_acc, double trans_rad0, double rotate_vel, int disappTime_min, double param1, double param2, double param3){
	this->kind = kind;
	this->color = color;
	this->movePattern = movePattern;
	this->isetBullet = isetBullet;
	this->igetPlayerPosition = igetPlayerPosition;
	this->trans_vel = trans_vel0;
	this->trans_acc = trans_acc;
	this->trans_rad = trans_rad0;
	this->rotate_rad = trans_rad0;
	this->rotate_vel = rotate_vel;
	this->disappearTime_min = disappTime_min;
	this->param1 = param1;
	this->param2 = param2;
	this->param3 = param3;

	this->count = 0;
	this->position = pos;
	this->validated = true;

	switch (kind){
	case 0: this->size = Size(11, 19); break;
	case 1: this->size = Size(18, 20); break;
	case 2: this->size = Size(11, 19); break;
	case 3: this->size = Size(17, 15); break;
	case 4: this->size = Size(13, 22); break;
	case 5: this->size = Size(64, 64); break;
	case 6: this->size = Size(18, 28); break;
	case 7: this->size = Size(30, 30); break;
	case 8: this->size = Size(19, 18); break;
	case 9: this->size = Size(6, 14); break;
	case 10: this->size = Size(20, 38); break;
	case 11: this->size = Size(12, 12); break;
	case 12: this->size = Size(16, 16); break;
	case 13: this->size = Size(32, 32); break;
	case 14: this->size = Size(20, 20); break;
	}
}

void BossBullet::initialize(){

}

void BossBullet::update(){
	if (this->count >= this->disappearTime_min){
		if ((this->position.x<-this->size.width) || (this->position.y<-this->size.height) || (this->position.x>GAME_WINDOW_WIDTH + this->size.width) || (this->position.y>GAME_WINDOW_HEIGHT + this->size.height)){
			this->validated = false;
		}
	}

	this->move();

	this->count++;
}

void BossBullet::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 200);
	DrawRotaGraph2(GAME_WINDOW_OFFSET_X + (int)this->position.x, GAME_WINDOW_OFFSET_Y + (int)this->position.y, this->size.width / 2, this->size.height / 2, 1.0, this->rotate_rad, Picture::getBullet(this->kind, this->color), true);
}

void BossBullet::finalize(){

}

void BossBullet::move(){
	switch (this->movePattern){
	case 0://“™‘¬’¼i
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 1://‰Á‘¬’¼i
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 2://Œ¸‘¬->Ä‰Á‘¬
		this->position.x += abs(this->trans_vel)*cos(this->trans_rad);
		this->position.y += abs(this->trans_vel)*sin(this->trans_rad);
		this->trans_vel -= abs(this->trans_acc);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 3://‰ñ“](”¼Œa•ûŒü‚Í“™‘¬ ‰ñ“]Šp‘¬“x‚ªˆê’è) ”¼Œa•ûŒü‘¬“x:trans_vel  Úü•ûŒüŠp‘¬“x:rotate_vel
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->trans_vel*this->count*this->rotate_vel*sin(this->trans_rad));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->trans_vel*this->count*this->rotate_vel*cos(this->trans_rad));
		this->trans_rad += this->rotate_vel;
		this->rotate_rad = this->trans_rad;
		break;

	case 4://‰ñ“](”¼Œa•ûŒü‚Í“™‘¬@‰ñ“]‘¬“x‚ªˆê’è) ”¼Œa•ûŒü‘¬“x:trans_vel  Úü•ûŒü‘¬“x:rotate_vel
		this->position.x += (this->trans_vel*cos(this->trans_rad) + this->rotate_vel*cos(this->trans_rad + M_PI / 2));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->rotate_vel*sin(this->trans_rad + M_PI / 2));
		this->trans_rad += atan2(this->rotate_vel, this->trans_vel*(this->count + 1));
		this->rotate_rad = this->trans_rad;
		break;

	case 5://‰ñ“](”¼Œa•ûŒü‚Í‰Á‘¬ ‰ñ“]Šp‘¬“x‚ªˆê’è) ”¼Œa•ûŒü‘¬“x:trans_vel  Úü•ûŒüŠp‘¬“x:rotate_vel
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->trans_vel*this->count*this->rotate_vel*sin(this->trans_rad));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->trans_vel*this->count*this->rotate_vel*cos(this->trans_rad));
		this->trans_rad += this->rotate_vel;
		this->trans_vel += this->trans_acc;
		this->rotate_rad = this->trans_rad;
		break;

	case 6://‰ñ“](”¼Œa•ûŒü‚Í‰Á‘¬@‰ñ“]‘¬“x‚ªˆê’è) ”¼Œa•ûŒü‘¬“x:trans_vel  Úü•ûŒü‘¬“x:rotate_vel
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->rotate_vel*sin(this->trans_rad));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->rotate_vel*cos(this->trans_rad));
		this->trans_rad += (this->rotate_vel / this->trans_vel / this->count);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = this->trans_rad;
		break;

	case 7://’¼iC•Ç‚Å”½ŽË
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		if ((this->position.x < 0) || (this->position.x > GAME_WINDOW_WIDTH)) this->trans_rad = M_PI - this->trans_rad;
		if (this->position.y < 0) this->trans_rad = M_PI * 2 - this->trans_rad;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 8://x•ûŒü‚É‚Ì‚Ý‰Á‘¬“x
	{
		double vx, vy;
		vx = this->trans_vel*cos(this->trans_rad);
		vy = this->trans_vel*sin(this->trans_rad);
		vx += this->trans_acc;
		this->trans_vel = sqrt(vx*vx + vy*vy);
		this->position.x += vx;
		this->position.y += vy;
		this->trans_rad = atan2(vy, vx);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;
	}

	case 9://y•ûŒü‚É‚Ì‚Ý‰Á‘¬“x
	{
		double vx, vy;
		vx = this->trans_vel*cos(this->trans_rad);
		vy = this->trans_vel*sin(this->trans_rad);
		vy += this->trans_acc;
		this->trans_vel = sqrt(vx*vx + vy*vy);
		this->position.x += vx;
		this->position.y += vy;
		this->trans_rad = atan2(vy, vx);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;
	}

	case 10://ŽžŠÔ‚Ü‚Å’âŽ~A‚»‚ÌŒã‰Á‘¬(’âŽ~ŽžŠÔ:param1)
		if (this->count < (int)this->param1) break;

		this->position.x += this->trans_acc*(this->count - (int)this->param1)*cos(this->trans_rad);
		this->position.y += this->trans_acc*(this->count - (int)this->param1)*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 11://ŽžŠÔ‚Ü‚Å’âŽ~A‚»‚ÌŒãÅ‘å‘¬“x‚Ü‚Å‰Á‘¬(’âŽ~ŽžŠÔ:param1 Å‘å‘¬“x:trans_vel)
		if (this->count < (int)this->param1) break;

		if (abs(this->trans_acc)*(this->count - (int)this->param1) < abs(this->trans_vel)){
			this->position.x += this->trans_acc*(this->count - (int)this->param1)*cos(this->trans_rad);
			this->position.y += this->trans_acc*(this->count - (int)this->param1)*sin(this->trans_rad);
		}
		else{
			this->position.x += this->trans_vel*cos(this->trans_rad);
			this->position.y += this->trans_vel*sin(this->trans_rad);
		}
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 12://sin”g(r:param1 omega:rotate_vel)
		this->position.x += cos(this->trans_rad)*this->trans_vel - sin(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count);
		this->position.y += sin(this->trans_rad)*this->trans_vel + cos(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count);
		this->rotate_rad = atan2(sin(trans_rad)*this->trans_vel + cos(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count), cos(this->trans_rad)*this->trans_vel - sin(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count)) + M_PI / 2;
		break;

		//ˆÈ‰º“ÁŽêˆÚ“®//////////////////////////////////////////////////////////////////////////////////////////////////////////
	case 50://2-4
		this->position.x += (this->trans_vel*cos(this->trans_rad) - 50.0*this->rotate_vel*sin(this->param1));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + 50.0*this->rotate_vel*cos(this->param1));
		this->param1 += this->rotate_vel;
		break;

	case 51://3-2
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);

		if (this->position.x < 0){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, this->trans_rad + M_PI, this->rotate_rad + M_PI);
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, M_PI - this->trans_rad, M_PI - this->rotate_rad);
			this->validated = false;
		}
		if (this->position.x > GAME_WINDOW_WIDTH){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, this->trans_rad + M_PI, this->rotate_rad + M_PI);
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, M_PI - this->trans_rad, M_PI - this->rotate_rad);
			this->validated = false;
		}
		if (this->position.y < 0){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, this->trans_rad + M_PI, this->rotate_rad + M_PI);
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 9, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.01, M_PI * 2 - this->trans_rad, M_PI * 2 - this->rotate_rad);
			this->validated = false;
		}
		break;

	case 52://3-3
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->param1*this->rotate_vel*sin(this->param2));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->param1*this->rotate_vel*cos(this->param2));
		this->param2 += this->rotate_vel;
		break;

	case 53://3-6
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		if (this->trans_vel < 0.1){
			double angle = M_PI*GetRand(360) / 180;
			for (int i = 0; i < 3; i++){
				this->isetBullet->isetBossBullet(this->position, Bul_Niddle, Bul_Blue, 12, this->isetBullet, this->igetPlayerPosition, 2.0, 0.0, angle + M_PI * 2 * i / 3, 2, 20, this->param1);
			}
			this->validated = false;
		}
		break;

	case 54://3-6
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->param1*this->param2*sin(this->trans_rad)*cos(this->param2*this->count) - 50.0*this->rotate_vel*sin(this->rotate_vel*this->count + this->param3));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->param1*this->param2*cos(this->trans_rad)*cos(this->param2*this->count) + 50.0*this->rotate_vel*cos(this->rotate_vel*this->count + this->param3));
		this->rotate_rad = this->rotate_vel*this->count + this->param3;
		break;

	case 55://4-2
		if (this->count < 200){
			this->position.x += (this->trans_vel*cos(this->trans_rad + M_PI) + this->rotate_vel*cos(this->trans_rad + M_PI / 2));
			this->position.y += (this->trans_vel*sin(this->trans_rad + M_PI) + this->rotate_vel*sin(this->trans_rad + M_PI / 2));
			this->param1 -= this->trans_vel;
			this->trans_rad += atan2(this->rotate_vel, this->param1);
			this->rotate_rad = this->trans_rad + M_PI / 2;
		}
		else{
			this->validated = false;
			for (int i = 0; i < 3; i++) this->isetBullet->isetBossBullet(this->position, Bul_Small, Bul_WaterBlue, 9, this->isetBullet, this->igetPlayerPosition, 6.0, 0.07, M_PI * 255 / 180 + M_PI*GetRand(290) / 1800, 0.0, 120);
		}
		break;

	case 56://5-2
		if (this->count < 60){
			this->position.x += this->trans_vel*cos(this->trans_rad);
			this->position.y += this->trans_vel*sin(this->trans_rad);
			this->trans_vel += this->trans_acc;
			this->rotate_rad = (this->trans_rad + M_PI / 2);
			break;
		}
		else if (this->count == 60){
			for (int line = 0; line < (int)this->param1; line++){
				for (int i = 0; i < (int)this->param2; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Money, Bul_Yellow, 9, this->isetBullet, this->igetPlayerPosition, 1.0 + 0.4*line, 0.01, M_PI * 2 * i / this->param2 + M_PI*GetRand(10) / 180, 0.0);
				}
			}
			for (int i = 0; i < (int)this->param2; i++){
				this->isetBullet->isetBossBullet(this->position, Bul_LargeStar, Bul_Orange, 9, this->isetBullet, this->igetPlayerPosition, 2.2, 0.01, M_PI * 2 * i / this->param2 + M_PI*GetRand(10) / 180, 0.0);
			}
			this->validated = false;
		}
		break;

	case 57://6-2
		this->position.x += (this->trans_vel*cos(this->trans_rad) - this->param1*this->rotate_vel*sin(this->rotate_vel*this->count + this->param2));
		this->position.y += (this->trans_vel*sin(this->trans_rad) + this->param1*this->rotate_vel*cos(this->rotate_vel*this->count + this->param2));
		break;

	case 58://6-3
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);

		if (this->position.x < 0){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Yellow, 59, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.0, M_PI - this->trans_rad, 0.0);
			this->validated = false;
		}
		if (this->position.x > GAME_WINDOW_WIDTH){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Yellow, 59, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.0, M_PI - this->trans_rad, 0.0);
			this->validated = false;
		}
		if (this->position.y < 0){
			this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Yellow, 59, this->isetBullet, this->igetPlayerPosition, this->trans_vel, 0.0, M_PI * 2 - this->trans_rad, 0.0);
			this->validated = false;
		}
		break;

	case 59://6-3
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->rotate_rad = (this->trans_rad + M_PI / 2);

		if ((this->position.x < 0) || (this->position.x > GAME_WINDOW_WIDTH) || (this->position.y < 0)){
			if (this->position.y < 300.0){
				if (GetRand(1) == 0)this->isetBullet->isetBossBullet(this->position, this->kind, Bul_Red, 1, this->isetBullet, this->igetPlayerPosition, 0.5, 0.008, atan2(this->igetPlayerPosition->igetPosition().y - this->position.y, this->igetPlayerPosition->igetPosition().x - this->position.x), 0.0);
			}
			this->validated = false;
		}
		break;

	case 60://6-5
		if (this->count <= 60){
			this->position.x += this->trans_vel*cos(this->trans_rad);
			this->position.y += this->trans_vel*sin(this->trans_rad);
			this->trans_vel += this->trans_acc;
			this->rotate_rad = (this->trans_rad + M_PI / 2);
		}
		else if (this->count < 70){
			
		}
		else if (this->count == 70){
			double angle = M_PI*GetRand(360) / 180;
			for (int i = 0; i < (int)this->param1; i++){
				this->isetBullet->isetBossBullet(this->position, Bul_Middle, Bul_Yellow, 61, this->isetBullet, this->igetPlayerPosition, 3.0, 0.03, angle + M_PI * 2 * i / (int)this->param1, 0.0, 20, 1.0);
			}
			this->validated = false;
		}
		break;

	case 61://6-5
		if (this->param1 > this->trans_vel - this->trans_acc*this->count){
			this->position.x += this->param1*cos(this->trans_rad);
			this->position.y += this->param1*sin(this->trans_rad);
		}
		else {
			this->position.x += (this->trans_vel - this->trans_acc*this->count)*cos(this->trans_rad);
			this->position.y += (this->trans_vel - this->trans_acc*this->count)*sin(this->trans_rad);
		}
		break;

	case 62://6-6
		if (this->position.y > 0.0){
			this->position.x += cos(this->trans_rad)*this->trans_vel - sin(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count);
			this->position.y += sin(this->trans_rad)*this->trans_vel + cos(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count);
			this->rotate_rad = atan2(sin(trans_rad)*this->trans_vel + cos(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count), cos(this->trans_rad)*this->trans_vel - sin(this->trans_rad)*this->param1*(this->rotate_vel*M_PI / 180)*cos((this->rotate_vel*M_PI / 180)*this->count)) + M_PI / 2;
		}
		else {
			double angle = M_PI*GetRand(360) / 180;
			for (int line = 0; line < (int)this->param2; line++){
				for (int i = 0; i < 30; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Kunai, Bul_White, 0, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.0, angle + M_PI*i / 15, 0.0, 2);
				}
			}

			for (int i = 0; i < (int)this->param3; i++){
				this->isetBullet->isetBossBullet(this->position, Bul_Knife, Bul_White, 0, this->isetBullet, this->igetPlayerPosition, 2.0 + 0.5*i, 0.0, M_PI / 2, 0.0, 2);
			}
			this->validated = false;
		}
		break;

	case 63://6-7
		if (this->count < this->param1){
			this->position.x += (this->trans_vel*cos(this->trans_rad) + this->rotate_vel*cos(this->trans_rad + M_PI / 2));
			this->position.y += (this->trans_vel*sin(this->trans_rad) + this->rotate_vel*sin(this->trans_rad + M_PI / 2));
			this->trans_rad += atan2(this->rotate_vel, this->trans_vel*(this->count + 1));
			this->rotate_rad = this->trans_rad;
		}
		else if (this->count == (int)this->param1){
			this->trans_rad = this->trans_rad + atan2(this->rotate_vel, this->trans_vel);
		}
		else{
			this->position.x += abs(this->rotate_vel)*cos(this->trans_rad);
			this->position.y += abs(this->rotate_vel)*sin(this->trans_rad);
			this->rotate_rad = (this->trans_rad + M_PI / 2);
		}
		break;

	case 64://6-7
		if (this->trans_vel + this->trans_acc*this->count < this->param1){
			this->position.x += abs(this->trans_vel + this->trans_acc*this->count)*cos(this->trans_rad);
			this->position.y += abs(this->trans_vel + this->trans_acc*this->count)*sin(this->trans_rad);
		}
		else{
			this->position.x += this->param1*cos(this->trans_rad);
			this->position.y += this->param1*sin(this->trans_rad);
		}
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		break;

	case 65://7-4
		if (this->count < 60){
			this->position.x += this->trans_vel*cos(this->trans_rad);
			this->position.y += this->trans_vel*sin(this->trans_rad);
			this->rotate_rad = (this->trans_rad + M_PI / 2);
		}
		else{
			this->validated = false;
			this->isetBullet->isetBossBullet(this->position, Bul_Crystal, Bul_Blue, 1, this->isetBullet, this->igetPlayerPosition, 1.0, 0.005, atan2(this->igetPlayerPosition->igetPosition().y - this->position.y + this->trans_vel*this->count*sin(this->trans_rad), this->igetPlayerPosition->igetPosition().x - this->position.x + this->trans_vel*this->count*cos(this->trans_rad)), 0.0, 60);
		}
		break;

	case 66://7-6
		this->position.x += this->trans_vel*cos(this->param1*this->count + this->trans_rad) - this->trans_vel*this->count*this->param1*sin(this->param1*this->count + this->trans_rad) + this->param2*cos(this->rotate_vel*this->count + this->param3) - this->param2*this->count*this->rotate_vel*sin(this->rotate_vel*this->count + this->param3);
		this->position.y += this->trans_vel*sin(this->param1*this->count + this->trans_rad) + this->trans_vel*this->count*this->param1*cos(this->param1*this->count + this->trans_rad) + this->param2*sin(this->rotate_vel*this->count + this->param3) + this->param2*this->count*this->rotate_vel*cos(this->rotate_vel*this->count + this->param3);
		break;

	case 67://7-7
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		if (this->count % 60 == 0){
			BulletColor col = (BulletColor)GetRand(6);
			for (int i = -3; i <= 3; i++){
				if (i == 0) continue;
				this->isetBullet->isetBossBullet(this->position, Bul_Fuda, col, 1, this->isetBullet, this->igetPlayerPosition, 0.6*abs(i), 0.01, this->trans_rad + (M_PI*i / abs(i) / 2), 0.0);
			}
		}
		if (this->count > 40){
			if (this->position.x < 0){
				for (int i = 0; i < 4; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Middle, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI*i / 4 - M_PI / 2, 0.0);
				}
				this->validated = false;
			}
			if (this->position.x > GAME_WINDOW_WIDTH){
				for (int i = 0; i < 4; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Middle, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI*i / 4 + M_PI / 2, 0.0);
				}
				this->validated = false;
			}
			if (this->position.y < 0){
				for (int i = 0; i < 4; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Middle, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI*i / 4, 0.0);
				}
				this->validated = false;
			}
			if (this->position.y > GAME_WINDOW_HEIGHT){
				for (int i = 0; i < 4; i++){
					this->isetBullet->isetBossBullet(this->position, Bul_Middle, Bul_Yellow, 0, this->isetBullet, this->igetPlayerPosition, 1.0, 0.0, M_PI*i / 4 + M_PI, 0.0);
				}
				this->validated = false;
			}
		}
		break;

	case 68://7-10
		if (this->count < 150){
			this->position.x += (this->trans_vel*cos(this->trans_rad) - this->trans_vel*this->count*this->rotate_vel*sin(this->trans_rad));
			this->position.y += (this->trans_vel*sin(this->trans_rad) + this->trans_vel*this->count*this->rotate_vel*cos(this->trans_rad));
			this->trans_rad += this->rotate_vel;
			this->rotate_rad = this->trans_rad;
			if (this->count % 20 == 0){
				BulletColor col = (BulletColor)GetRand(6);
				double r;
				for (int i = 0; i < 16; i++){
					r = 1.0*GetRand(300) / 10 + 20.0;
					this->isetBullet->isetBossBullet(this->position + Point(40.0*cos(M_PI * 2 * i / 16), 40.0*sin(M_PI * 2 * i / 16)), (BulletKind)(7 * (GetRand(1) + 1)), col, 10, this->isetBullet, this->igetPlayerPosition, 0.0, 0.006*r / 50, M_PI * 2 * i / 16, 0.0, 0, 100 - this->count);
				}
			}
		}
		else {
			this->validated = false;
		}
		break;

	case 69://7-12
		if (this->count < 150){
			this->position.x += abs(this->trans_vel)*cos(this->trans_rad);
			this->position.y += abs(this->trans_vel)*sin(this->trans_rad);
			this->trans_vel += this->trans_acc;
		}
		else{
			this->color = Bul_Blue;
			this->position.x += cos(this->trans_rad);
			this->position.y += sin(this->trans_rad);
		}
		this->rotate_rad = this->trans_rad + M_PI / 2;
		break;

	case 70://7-13
		if (this->count < 100){
			this->position.x += this->trans_vel*cos(this->trans_rad);
			this->position.y += this->trans_vel*sin(this->trans_rad);
			this->trans_vel += this->trans_acc;
			this->rotate_rad = this->trans_rad + M_PI / 2;
		}
		else{
			this->validated = false;
			for (int line = 0; line < 3; line++){
				this->isetBullet->isetBossBullet(this->position, Bul_Small, Bul_Green, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02, this->trans_rad + M_PI / 4, 0.0);
				this->isetBullet->isetBossBullet(this->position, Bul_Small, Bul_Green, 1, this->isetBullet, this->igetPlayerPosition, 1.0 + line, 0.02, this->trans_rad - M_PI / 4, 0.0);
			}
		}
		break;

	case 71://7-15
		this->position.x += this->trans_vel*cos(this->trans_rad);
		this->position.y += this->trans_vel*sin(this->trans_rad);
		this->trans_vel += this->trans_acc;
		this->rotate_rad = (this->trans_rad + M_PI / 2);
		if (this->count % 5 == 0){
			for (int i = 0; i < 4; i++){
				this->isetBullet->isetBossBullet(this->position, Bul_Knife, Bul_Purple, 0, this->isetBullet, this->igetPlayerPosition, 3.0, 0.0, this->trans_rad - M_PI + M_PI*GetRand(150) / 180 - M_PI * 5 / 12, 0.0, 0);
			}
		}
		break;

	}
}