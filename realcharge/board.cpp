#include "board.h"
#include "picture.h"
#include "DxLib.h"

Board::Board(IGetPlayerInfomation *igetPlayerInfomation, IGetBoss* igetBoss, IGetBossEventNow* igetBossEvemtNow, int playerMode){
	this->getPlayerInfomation = igetPlayerInfomation;
	this->igetBoss = igetBoss;
	this->igetBossEvemtNow = igetBossEvemtNow;
	this->playerMode = playerMode;

	this->score=0;
	this->score_=0;
	this->beatedCount=0;
	this->count=0;
	this->validated=true;
}

void Board::initialize(){

}

void Board::update(){
	if (this->score_ >= 10000){
		this->score += 10000;
		this->score_ -= 10000;
	}
	if (this->score_ >= 1000){
		this->score += 1000;
		this->score_ -= 1000;
	}
	if(this->score_>=100){
		this->score+=100;
		this->score_-=100;
	}
	if(this->score_>=10){
		this->score+=10;
		this->score_-=10;
	}
	if(this->score_>0){
		this->score+=1;
		this->score_-=1;
	}
}

void Board::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	DrawGraph(0,0,Picture::getBoard(dir_up),false);
	DrawGraph(0,GAME_WINDOW_OFFSET_Y,Picture::getBoard(dir_left),false);
	DrawGraph(0,GAME_WINDOW_OFFSET_Y+GAME_WINDOW_HEIGHT,Picture::getBoard(dir_down),false);
	DrawGraph(GAME_BOARD_OFFSET_X,0,Picture::getBoard(dir_right),false);

	//スコア表示
	int score=this->score;
	if(score==0){
		DrawGraph(GAME_BOARD_OFFSET_X + 246, 43, Picture::getNumbers(Number_White, 0), true);
	}
	else{
		for(int i=0;score!=0;score/=10){
			DrawGraph(GAME_BOARD_OFFSET_X + 246 - 20 * i, 43, Picture::getNumbers(Number_White, score % 10), true);
			i++;
		}
	}

	//撃破数表示
	int beatedCount0 = this->beatedCount;
	if(beatedCount0==0){
		DrawGraph(GAME_BOARD_OFFSET_X+200,205,Picture::getNumbers(Number_Blue,0),true);
	}
	else{
		for(int i=0;beatedCount0!=0;beatedCount0/=10){
			DrawGraph(GAME_BOARD_OFFSET_X+200-21*i,205,Picture::getNumbers(Number_Blue,beatedCount0%10),true);
			i++;
		}
	}

	//ライフ表示
	int life = this->getPlayerInfomation->igetPlayerLife();
	int life_ = life%10;//小数
	life = (life-life_)/10;//整数
	if(life==0){
		DrawGraph(GAME_BOARD_OFFSET_X+130,150,Picture::getNumbers(Number_Green,0),true);
	}
	else{
		for(int i=0;life!=0;life/=10){
			DrawGraph(GAME_BOARD_OFFSET_X+130-21*i,150,Picture::getNumbers(Number_Green,life),true);
			i++;
		}
	}
	DrawGraph(GAME_BOARD_OFFSET_X+180,150,Picture::getNumbers(Number_Green,life_),true);
	DrawGraph(GAME_BOARD_OFFSET_X+200,150,Picture::getSlash(),true);
	DrawGraph(GAME_BOARD_OFFSET_X+220,150,Picture::getNumbers(Number_Green,1),true);
	DrawGraph(GAME_BOARD_OFFSET_X+240,150,Picture::getNumbers(Number_Green,0),true);

	//パワー表示
	if (this->playerMode == 0){//explode
		int pow = this->getPlayerInfomation->igetPlayerChargingPower();
		if (pow == 0){
			DrawGraph(GAME_BOARD_OFFSET_X + 200, 97, Picture::getNumbers(Number_Red, 0), true);
		}
		else{
			for (int i = 0; pow != 0; pow /= 10){
				DrawGraph(GAME_BOARD_OFFSET_X + 200 - 21 * i, 97, Picture::getNumbers(Number_Red, pow % 10), true);
				i++;
			}
		}
	}
	else if(this->playerMode==1){//stand
		DrawGraph(WINDOW_WIDTH - 120, 97, Picture::getSlash(), true);
		DrawGraph(WINDOW_WIDTH - 100, 97, Picture::getNumbers(Number_Red, 5), true);
		DrawGraph(WINDOW_WIDTH - 80, 97, Picture::getDot(), true);
		DrawGraph(WINDOW_WIDTH - 60, 97, Picture::getNumbers(Number_Red, 0), true);
		DrawGraph(WINDOW_WIDTH - 40, 97, Picture::getNumbers(Number_Red, 0), true);

		DrawGraph(WINDOW_WIDTH - 140, 97, Picture::getNumbers(Number_Red, this->getPlayerInfomation->igetPlayerEXShotPower() % 10), true);
		DrawGraph(WINDOW_WIDTH - 160, 97, Picture::getNumbers(Number_Red, (this->getPlayerInfomation->igetPlayerEXShotPower() / 10) % 10), true);
		DrawGraph(WINDOW_WIDTH - 180, 97, Picture::getDot(), true);
		DrawGraph(WINDOW_WIDTH - 200, 97, Picture::getNumbers(Number_Red, (this->getPlayerInfomation->igetPlayerEXShotPower() / 100) % 10), true);
	}
	else{//absorb
		int pow = this->getPlayerInfomation->igetPlayerChargingPower();
		if (pow == 0){
			DrawGraph(GAME_BOARD_OFFSET_X + 200, 97, Picture::getNumbers(Number_Red, 0), true);
		}
		else{
			for (int i = 0; pow != 0; pow /= 10){
				DrawGraph(GAME_BOARD_OFFSET_X + 200 - 21 * i, 97, Picture::getNumbers(Number_Red, pow % 10), true);
				i++;
			}
		}
	}

	//ボスマーク
	if (this->igetBossEvemtNow->igetBossFightingNow() == true){
		DrawGraph(GAME_WINDOW_OFFSET_X + this->igetBoss->igetBoss(0)->getPosition().x - 16, GAME_WINDOW_OFFSET_Y + GAME_WINDOW_HEIGHT + 4, Picture::getBossMarker(), true);
	}
}

void Board::finalize(){

}

void Board::addScore(int add){
	this->score_+=add;
}

void Board::iaddBeatedCount(){
	this->beatedCount++;
}