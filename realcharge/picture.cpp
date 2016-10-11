#include "picture.h"
#include "DxLib.h"
#include <math.h>
#include "charactor.h"
#include "burnEffect.h"
#include "bullet.h"

int Picture::player[3];
int Picture::enemy[25][24];
int Picture::board[4];
int Picture::bullet[15][8];
int Picture::burnEffect[6][14];
int Picture::backEffect[5];
int Picture::textEffect[5];
int Picture::selectText[32];
int Picture::numbers[4][10];
int Picture::item[2][4];
int Picture::windowBase[9];
int Picture::back[2];
int Picture::explode[15];
int Picture::shockwave_l[4];
int Picture::shockwave_s[8];
int Picture::bossBarrage=0;
int Picture::bossMarker=0;
int Picture::dot=0;
int Picture::enemyLife[2];
int Picture::playerBomb=0;
int Picture::slash=0;
int Picture::modeExplainText[3];
int Picture::playerRecovery[10];
int Picture::collapsar[10];
int Picture::title[5];
int Picture::subtitle=0;


void Picture::loadAllPicture(){
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	LoadDivGraph("material\\player.png",3,3,1,32,32,Picture::player);
	LoadDivGraph("material\\windowBase.png",9,3,3,10,10,Picture::windowBase);
	LoadDivGraph("material\\explode.png",15,5,3,48,48,Picture::explode);
	LoadDivGraph("material\\shockwave_l.png",4,4,1,70,70,Picture::shockwave_l);
	LoadDivGraph("material\\shockwave_s.png",8,8,1,56,56,Picture::shockwave_s);
	LoadDivGraph("material\\player_recovery.png", 10, 10, 1, 120, 120, Picture::playerRecovery);
	LoadDivGraph("material\\collapsar.png", 10, 10, 1, 120, 120, Picture::collapsar);

	Picture::dot = LoadGraph("material\\numbers\\dot.png");
	Picture::slash = LoadGraph("material\\numbers\\slash.png");
	Picture::playerBomb = LoadGraph("material\\player_bomb.png");
	Picture::bossBarrage = LoadGraph("material\\boss_barrage.png");
	Picture::bossMarker = LoadGraph("material\\boss_mark.png");
	Picture::enemyLife[0] = LoadGraph("material\\life.png");
	Picture::enemyLife[1] = LoadGraph("material\\life2.png");

	Picture::board[dir_down] = LoadGraph("material\\board\\board_down.png");
	Picture::board[dir_left] = LoadGraph("material\\board\\board_left.png");
	Picture::board[dir_right] = LoadGraph("material\\board\\board_right4.png");
	Picture::board[dir_up] = LoadGraph("material\\board\\board_up.png");

	Picture::backEffect[0] = LoadGraph("material\\effect\\leaf1.png");
	Picture::backEffect[1] = LoadGraph("material\\effect\\leaf2.png");
	Picture::backEffect[2] = LoadGraph("material\\effect\\leaf3.png");
	Picture::backEffect[3] = LoadGraph("material\\effect\\leaf4.png");
	Picture::backEffect[4] = LoadGraph("material\\effect\\leaf5.png");

	Picture::textEffect[0] = LoadGraph("material\\text\\text1.png");
	Picture::textEffect[1] = LoadGraph("material\\text\\text2.png");
	Picture::textEffect[2] = LoadGraph("material\\text\\text3.png");
	Picture::textEffect[3] = LoadGraph("material\\text\\text4.png");
	Picture::textEffect[4] = LoadGraph("material\\text\\text5.png");

	Picture::selectText[SEL_QUIT] = LoadGraph("material\\select\\QUIT.png");
	Picture::selectText[SEL_KEYCONFIG] = LoadGraph("material\\select\\KEY CONFIG.png");
	Picture::selectText[SEL_MUSICROOM] = LoadGraph("material\\select\\MUSIC ROOM.png");
	Picture::selectText[SEL_GAMESTART] = LoadGraph("material\\select\\GAME START.png");
	Picture::selectText[SEL_EASY] = LoadGraph("material\\select\\EASY.png");
	Picture::selectText[SEL_NORMAL] = LoadGraph("material\\select\\NORMAL.png");
	Picture::selectText[SEL_HARD] = LoadGraph("material\\select\\HARD.png");
	Picture::selectText[SEL_EXTRASTAGE] = LoadGraph("material\\select\\EXTRA START.png");
	Picture::selectText[SEL_BOSSPRACTICE] = LoadGraph("material\\select\\BOSS PRACTICE.png");
	Picture::selectText[SEL_STAGEPRACTICE] = LoadGraph("material\\select\\STAGE PRACTICE.png");
	Picture::selectText[SEL_RETURN] = LoadGraph("material\\select\\RETURN.png");
	Picture::selectText[SEL_REBOSS] = LoadGraph("material\\select\\Re BOSS.png");
	Picture::selectText[SEL_RESTAGE] = LoadGraph("material\\select\\Re STAGE.png");
	Picture::selectText[SEL_REGAME] = LoadGraph("material\\select\\Re GAME.png");
	Picture::selectText[SEL_STAGE1] = LoadGraph("material\\select\\STAGE1.png");
	Picture::selectText[SEL_STAGE2] = LoadGraph("material\\select\\STAGE2.png");
	Picture::selectText[SEL_STAGE3] = LoadGraph("material\\select\\STAGE3.png");
	Picture::selectText[SEL_STAGE4] = LoadGraph("material\\select\\STAGE4.png");
	Picture::selectText[SEL_STAGE5] = LoadGraph("material\\select\\STAGE5.png");
	Picture::selectText[SEL_STAGE6] = LoadGraph("material\\select\\STAGE6.png");
	Picture::selectText[SEL_STAGEEXTRA] = LoadGraph("material\\select\\STAGEEXTRA.png");
	Picture::selectText[SEL_TITLE] = LoadGraph("material\\select\\TITLE.png");
	Picture::selectText[SEL_EXPLAINEATTACKING] = LoadGraph("material\\select\\explain_attacking.png");
	Picture::selectText[SEL_EXPLAINNEUTRAL] = LoadGraph("material\\select\\explain_neutral.png");
	Picture::selectText[SEL_EXPLAINDEFENSIVE] = LoadGraph("material\\select\\explain_defensive.png");
	Picture::selectText[SEL_ATTACKSELECT] = LoadGraph("material\\select\\ATTACK SELECT.png");
	Picture::selectText[SEL_MODESELECT] = LoadGraph("material\\select\\MODE SELECT.png");
	Picture::selectText[SEL_STAGESELECT] = LoadGraph("material\\select\\STAGE SELECT.png");
	Picture::selectText[SEL_RANKSELECT] = LoadGraph("material\\select\\RANK SELECT.png");
	Picture::selectText[SEL_MUSICSELECT] = LoadGraph("material\\select\\MUSIC SELECT.png");
	Picture::selectText[SEL_KEYSELECT] = LoadGraph("material\\select\\KEY SELECT.png");
	Picture::selectText[SEL_CLEAR] = LoadGraph("material\\select\\CLEAR.png");

	Picture::modeExplainText[0] = LoadGraph("material\\mode_explode.png");
	Picture::modeExplainText[1] = LoadGraph("material\\mode_stand.png");
	Picture::modeExplainText[2] = LoadGraph("material\\mode_absorb.png");

	Picture::title[0] = LoadGraph("material\\title\\title0.png");
	Picture::title[1] = LoadGraph("material\\title\\title1.png");
	Picture::title[2] = LoadGraph("material\\title\\title2.png");
	Picture::title[3] = LoadGraph("material\\title\\title3.png");
	Picture::title[4] = LoadGraph("material\\title\\title4.png");

	Picture::subtitle = LoadGraph("material\\title\\subtitle.png");

	LoadDivGraph("material\\burn_effect\\ef(1).png",14,14,1,240,240,Picture::burnEffect[Burn_Red]);
	LoadDivGraph("material\\burn_effect\\ef(2).png",14,14,1,240,240,Picture::burnEffect[Burn_Blue]);
	LoadDivGraph("material\\burn_effect\\ef(3).png",14,14,1,240,240,Picture::burnEffect[Burn_Yellow]);
	LoadDivGraph("material\\burn_effect\\ef(4).png",14,14,1,240,240,Picture::burnEffect[Burn_Green]);
	LoadDivGraph("material\\burn_effect\\ef(5).png",14,14,1,240,240,Picture::burnEffect[Burn_WaterBlue]);
	LoadDivGraph("material\\burn_effect\\ef(6).png",14,14,1,240,240,Picture::burnEffect[Burn_Orange]);

	LoadDivGraph("material\\item_s.png",4,4,1,8,8,Picture::item[0]);
	LoadDivGraph("material\\item_l.png",4,4,1,12,12,Picture::item[1]);

	LoadDivGraph("material\\bullet\\eb_crystal.png",8,8,1,11,19,Picture::bullet[Bul_Crystal]);
	LoadDivGraph("material\\bullet\\eb_fuda.png",8,8,1,18,20,Picture::bullet[Bul_Fuda]);
	LoadDivGraph("material\\bullet\\eb_gun.png",8,8,1,11,19,Picture::bullet[Bul_Gun]);
	LoadDivGraph("material\\bullet\\eb_knife.png",8,8,1,17,15,Picture::bullet[Bul_Knife]);
	LoadDivGraph("material\\bullet\\eb_kunai.png",8,8,1,13,24,Picture::bullet[Bul_Kunai]);
	LoadDivGraph("material\\bullet\\eb_large.png",8,8,1,64,64,Picture::bullet[Bul_Large]);
	LoadDivGraph("material\\bullet\\eb_lazer.png",8,8,1,18,28,Picture::bullet[Bul_Lazer]);
	LoadDivGraph("material\\bullet\\eb_middle.png",8,8,1,30,30,Picture::bullet[Bul_Middle]);
	LoadDivGraph("material\\bullet\\eb_money.png",8,8,1,19,18,Picture::bullet[Bul_Money]);
	LoadDivGraph("material\\bullet\\eb_niddle.png",8,8,1,6,18,Picture::bullet[Bul_Niddle]);
	LoadDivGraph("material\\bullet\\eb_oval.png",8,8,1,20,38,Picture::bullet[Bul_Oval]);
	LoadDivGraph("material\\bullet\\eb_small.png",8,8,1,12,12,Picture::bullet[Bul_Small]);
	LoadDivGraph("material\\bullet\\eb_snow.png",8,8,1,16,16,Picture::bullet[Bul_Snow]);
	LoadDivGraph("material\\bullet\\eb_star_l.png",8,8,1,32,32,Picture::bullet[Bul_LargeStar]);
	LoadDivGraph("material\\bullet\\eb_star_s.png",8,8,1,20,20,Picture::bullet[Bul_SmallStar]);

	Picture::back[0] = LoadGraph("material\\opening.png");
	Picture::back[1] = LoadGraph("material\\opening2.png");

	Picture::numbers[0][0] = LoadGraph("material\\numbers\\blue\\b0.png");
	Picture::numbers[0][1] = LoadGraph("material\\numbers\\blue\\b1.png");
	Picture::numbers[0][2] = LoadGraph("material\\numbers\\blue\\b2.png");
	Picture::numbers[0][3] = LoadGraph("material\\numbers\\blue\\b3.png");
	Picture::numbers[0][4] = LoadGraph("material\\numbers\\blue\\b4.png");
	Picture::numbers[0][5] = LoadGraph("material\\numbers\\blue\\b5.png");
	Picture::numbers[0][6] = LoadGraph("material\\numbers\\blue\\b6.png");
	Picture::numbers[0][7] = LoadGraph("material\\numbers\\blue\\b7.png");
	Picture::numbers[0][8] = LoadGraph("material\\numbers\\blue\\b8.png");
	Picture::numbers[0][9] = LoadGraph("material\\numbers\\blue\\b9.png");

	Picture::numbers[1][0] = LoadGraph("material\\numbers\\green\\g0.png");
	Picture::numbers[1][1] = LoadGraph("material\\numbers\\green\\g1.png");
	Picture::numbers[1][2] = LoadGraph("material\\numbers\\green\\g2.png");
	Picture::numbers[1][3] = LoadGraph("material\\numbers\\green\\g3.png");
	Picture::numbers[1][4] = LoadGraph("material\\numbers\\green\\g4.png");
	Picture::numbers[1][5] = LoadGraph("material\\numbers\\green\\g5.png");
	Picture::numbers[1][6] = LoadGraph("material\\numbers\\green\\g6.png");
	Picture::numbers[1][7] = LoadGraph("material\\numbers\\green\\g7.png");
	Picture::numbers[1][8] = LoadGraph("material\\numbers\\green\\g8.png");
	Picture::numbers[1][9] = LoadGraph("material\\numbers\\green\\g9.png");

	Picture::numbers[2][0] = LoadGraph("material\\numbers\\red\\r0.png");
	Picture::numbers[2][1] = LoadGraph("material\\numbers\\red\\r1.png");
	Picture::numbers[2][2] = LoadGraph("material\\numbers\\red\\r2.png");
	Picture::numbers[2][3] = LoadGraph("material\\numbers\\red\\r3.png");
	Picture::numbers[2][4] = LoadGraph("material\\numbers\\red\\r4.png");
	Picture::numbers[2][5] = LoadGraph("material\\numbers\\red\\r5.png");
	Picture::numbers[2][6] = LoadGraph("material\\numbers\\red\\r6.png");
	Picture::numbers[2][7] = LoadGraph("material\\numbers\\red\\r7.png");
	Picture::numbers[2][8] = LoadGraph("material\\numbers\\red\\r8.png");
	Picture::numbers[2][9] = LoadGraph("material\\numbers\\red\\r9.png");

	Picture::numbers[3][0] = LoadGraph("material\\numbers\\white\\w0.png");
	Picture::numbers[3][1] = LoadGraph("material\\numbers\\white\\w1.png");
	Picture::numbers[3][2] = LoadGraph("material\\numbers\\white\\w2.png");
	Picture::numbers[3][3] = LoadGraph("material\\numbers\\white\\w3.png");
	Picture::numbers[3][4] = LoadGraph("material\\numbers\\white\\w4.png");
	Picture::numbers[3][5] = LoadGraph("material\\numbers\\white\\w5.png");
	Picture::numbers[3][6] = LoadGraph("material\\numbers\\white\\w6.png");
	Picture::numbers[3][7] = LoadGraph("material\\numbers\\white\\w7.png");
	Picture::numbers[3][8] = LoadGraph("material\\numbers\\white\\w8.png");
	Picture::numbers[3][9] = LoadGraph("material\\numbers\\white\\w9.png");


	/*int tmp[22];
	LoadDivGraph("material\\enemy.png",22,22,1,96,256,tmp);
	for(int i=0;i<22;i++){
		for(int j=0;j<24;j++){
			Picture::enemy[i][j] = DerivationGraph(32*(j%3),32*(j-(j%3))/3,32,32,tmp[i]);
		}
	}*/

	LoadDivGraph("material\\enemyChip\\e(1).png", 24, 3, 8, 24, 40, Picture::enemy[0]);
	LoadDivGraph("material\\enemyChip\\e(2).png", 24, 3, 8, 24, 40, Picture::enemy[1]);
	LoadDivGraph("material\\enemyChip\\e(3).png", 24, 3, 8, 22, 38, Picture::enemy[2]);
	LoadDivGraph("material\\enemyChip\\e(4).png", 24, 3, 8, 28, 36, Picture::enemy[3]);
	LoadDivGraph("material\\enemyChip\\e(5).png", 24, 3, 8, 26, 40, Picture::enemy[4]);
	LoadDivGraph("material\\enemyChip\\e(6).png", 24, 3, 8, 24, 42, Picture::enemy[5]);
	LoadDivGraph("material\\enemyChip\\e(7).png", 24, 3, 8, 26, 40, Picture::enemy[6]);
	LoadDivGraph("material\\enemyChip\\e(8).png", 24, 3, 8, 28, 38, Picture::enemy[7]);
	LoadDivGraph("material\\enemyChip\\e(9).png", 24, 3, 8, 28, 40, Picture::enemy[8]);
	LoadDivGraph("material\\enemyChip\\e(10).png", 24, 3, 8, 24, 40, Picture::enemy[9]);
	LoadDivGraph("material\\enemyChip\\e(11).png", 24, 3, 8, 24, 40, Picture::enemy[10]);
	LoadDivGraph("material\\enemyChip\\e(12).png", 24, 3, 8, 28, 40, Picture::enemy[11]);
	LoadDivGraph("material\\enemyChip\\e(13).png", 24, 3, 8, 24, 40, Picture::enemy[12]);
	LoadDivGraph("material\\enemyChip\\e(14).png", 24, 3, 8, 28, 42, Picture::enemy[13]);
	LoadDivGraph("material\\enemyChip\\e(15).png", 24, 3, 8, 28, 44, Picture::enemy[14]);
	LoadDivGraph("material\\enemyChip\\e(16).png", 24, 3, 8, 26, 42, Picture::enemy[15]);
	LoadDivGraph("material\\enemyChip\\e(17).png", 24, 3, 8, 24, 40, Picture::enemy[16]);
	LoadDivGraph("material\\enemyChip\\e(18).png", 24, 3, 8, 24, 42, Picture::enemy[17]);
	LoadDivGraph("material\\enemyChip\\e(19).png", 24, 3, 8, 26, 40, Picture::enemy[18]);
	LoadDivGraph("material\\enemyChip\\e(20).png", 24, 3, 8, 24, 42, Picture::enemy[19]);
	LoadDivGraph("material\\enemyChip\\e(21).png", 24, 3, 8, 24, 42, Picture::enemy[20]);
	LoadDivGraph("material\\enemyChip\\e(22).png", 24, 3, 8, 26, 40, Picture::enemy[21]);
	LoadDivGraph("material\\enemyChip\\e(23).png", 24, 3, 8, 24, 40, Picture::enemy[22]);
	LoadDivGraph("material\\enemyChip\\e(24).png", 24, 3, 8, 26, 40, Picture::enemy[23]);
	LoadDivGraph("material\\enemyChip\\e(25).png", 24, 3, 8, 26, 40, Picture::enemy[24]);

}

void Picture::loadOpeningPicture(){
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	LoadDivGraph("material\\windowBase.png",9,3,3,10,10,Picture::windowBase);

	Picture::backEffect[0] = LoadGraph("material\\effect\\leaf1.png");
	Picture::backEffect[1] = LoadGraph("material\\effect\\leaf2.png");
	Picture::backEffect[2] = LoadGraph("material\\effect\\leaf3.png");
	Picture::backEffect[3] = LoadGraph("material\\effect\\leaf4.png");
	Picture::backEffect[4] = LoadGraph("material\\effect\\leaf5.png");

	Picture::selectText[SEL_QUIT] = LoadGraph("material\\select\\QUIT.png");
	Picture::selectText[SEL_KEYCONFIG] = LoadGraph("material\\select\\KEY CONFIG.png");
	Picture::selectText[SEL_MUSICROOM] = LoadGraph("material\\select\\MUSIC ROOM.png");
	Picture::selectText[SEL_GAMESTART] = LoadGraph("material\\select\\GAME START.png");
	Picture::selectText[SEL_EASY] = LoadGraph("material\\select\\EASY.png");
	Picture::selectText[SEL_NORMAL] = LoadGraph("material\\select\\NORMAL.png");
	Picture::selectText[SEL_HARD] = LoadGraph("material\\select\\HARD.png");
	Picture::selectText[SEL_EXTRASTAGE] = LoadGraph("material\\select\\EXTRA START.png");
	Picture::selectText[SEL_BOSSPRACTICE] = LoadGraph("material\\select\\BOSS PRACTICE.png");
	Picture::selectText[SEL_STAGEPRACTICE] = LoadGraph("material\\select\\STAGE PRACTICE.png");
	Picture::selectText[SEL_STAGE1] = LoadGraph("material\\select\\STAGE1.png");
	Picture::selectText[SEL_STAGE2] = LoadGraph("material\\select\\STAGE2.png");
	Picture::selectText[SEL_STAGE3] = LoadGraph("material\\select\\STAGE3.png");
	Picture::selectText[SEL_STAGE4] = LoadGraph("material\\select\\STAGE4.png");
	Picture::selectText[SEL_STAGE5] = LoadGraph("material\\select\\STAGE5.png");
	Picture::selectText[SEL_STAGE6] = LoadGraph("material\\select\\STAGE6.png");
	Picture::selectText[SEL_STAGEEXTRA] = LoadGraph("material\\select\\STAGEEXTRA.png");
	Picture::selectText[SEL_EXPLAINEATTACKING] = LoadGraph("material\\select\\explain_attacking.png");
	Picture::selectText[SEL_EXPLAINNEUTRAL] = LoadGraph("material\\select\\explain_neutral.png");
	Picture::selectText[SEL_EXPLAINDEFENSIVE] = LoadGraph("material\\select\\explain_defensive.png");
	Picture::selectText[SEL_ATTACKSELECT] = LoadGraph("material\\select\\ATTACK SELECT.png");
	Picture::selectText[SEL_MODESELECT] = LoadGraph("material\\select\\MODE SELECT.png");
	Picture::selectText[SEL_STAGESELECT] = LoadGraph("material\\select\\STAGE SELECT.png");
	Picture::selectText[SEL_RANKSELECT] = LoadGraph("material\\select\\RANK SELECT.png");
	Picture::selectText[SEL_MUSICSELECT] = LoadGraph("material\\select\\MUSIC SELECT.png");
	Picture::selectText[SEL_KEYSELECT] = LoadGraph("material\\select\\KEY SELECT.png");
	Picture::selectText[SEL_CLEAR] = LoadGraph("material\\select\\CLEAR.png");

	Picture::back[0] = LoadGraph("material\\opening.png");
	Picture::back[1] = LoadGraph("material\\opening2.png");

	Picture::modeExplainText[0] = LoadGraph("material\\mode_explode.png");
	Picture::modeExplainText[1] = LoadGraph("material\\mode_stand.png");
	Picture::modeExplainText[2] = LoadGraph("material\\mode_absorb.png");

	Picture::title[0] = LoadGraph("material\\title\\title0.png");
	Picture::title[1] = LoadGraph("material\\title\\title1.png");
	Picture::title[2] = LoadGraph("material\\title\\title2.png");
	Picture::title[3] = LoadGraph("material\\title\\title3.png");
	Picture::title[4] = LoadGraph("material\\title\\title4.png");

	Picture::subtitle = LoadGraph("material\\title\\subtitle.png");
}

void Picture::loadStagePicture(){
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	LoadDivGraph("material\\player.png",3,3,1,32,32,Picture::player);
	LoadDivGraph("material\\windowBase.png",9,3,3,10,10,Picture::windowBase);
	LoadDivGraph("material\\explode.png",15,5,3,48,48,Picture::explode);
	LoadDivGraph("material\\shockwave_l.png",4,4,1,70,70,Picture::shockwave_l);
	LoadDivGraph("material\\shockwave_s.png",8,8,1,56,56,Picture::shockwave_s);
	LoadDivGraph("material\\player_recovery.png", 10, 10, 1, 120, 120, Picture::playerRecovery);
	LoadDivGraph("material\\collapsar.png", 10, 10, 1, 120, 120, Picture::collapsar);

	Picture::dot = LoadGraph("material\\numbers\\dot.png");
	Picture::slash = LoadGraph("material\\numbers\\slash.png");
	Picture::playerBomb = LoadGraph("material\\player_bomb.png");
	Picture::bossBarrage = LoadGraph("material\\boss_barrage.png");
	Picture::bossMarker = LoadGraph("material\\boss_mark.png");
	Picture::enemyLife[0] = LoadGraph("material\\life.png");
	Picture::enemyLife[1] = LoadGraph("material\\life2.png");

	Picture::board[dir_down] = LoadGraph("material\\board\\board_down.png");
	Picture::board[dir_left] = LoadGraph("material\\board\\board_left.png");
	Picture::board[dir_right] = LoadGraph("material\\board\\board_right4.png");
	Picture::board[dir_up] = LoadGraph("material\\board\\board_up.png");

	Picture::backEffect[0] = LoadGraph("material\\effect\\leaf1.png");
	Picture::backEffect[1] = LoadGraph("material\\effect\\leaf2.png");
	Picture::backEffect[2] = LoadGraph("material\\effect\\leaf3.png");
	Picture::backEffect[3] = LoadGraph("material\\effect\\leaf4.png");
	Picture::backEffect[4] = LoadGraph("material\\effect\\leaf5.png");

	Picture::textEffect[0] = LoadGraph("material\\text\\text1.png");
	Picture::textEffect[1] = LoadGraph("material\\text\\text2.png");
	Picture::textEffect[2] = LoadGraph("material\\text\\text3.png");
	Picture::textEffect[3] = LoadGraph("material\\text\\text4.png");
	Picture::textEffect[4] = LoadGraph("material\\text\\text5.png");

	Picture::selectText[SEL_RETURN] = LoadGraph("material\\select\\RETURN.png");
	Picture::selectText[SEL_REBOSS] = LoadGraph("material\\select\\Re BOSS.png");
	Picture::selectText[SEL_RESTAGE] = LoadGraph("material\\select\\Re STAGE.png");
	Picture::selectText[SEL_REGAME] = LoadGraph("material\\select\\Re GAME.png");
	Picture::selectText[SEL_TITLE] = LoadGraph("material\\select\\TITLE.png");

	LoadDivGraph("material\\burn_effect\\ef(1).png",14,14,1,240,240,Picture::burnEffect[Burn_Red]);
	LoadDivGraph("material\\burn_effect\\ef(2).png",14,14,1,240,240,Picture::burnEffect[Burn_Blue]);
	LoadDivGraph("material\\burn_effect\\ef(3).png",14,14,1,240,240,Picture::burnEffect[Burn_Yellow]);
	LoadDivGraph("material\\burn_effect\\ef(4).png",14,14,1,240,240,Picture::burnEffect[Burn_Green]);
	LoadDivGraph("material\\burn_effect\\ef(5).png",14,14,1,240,240,Picture::burnEffect[Burn_WaterBlue]);
	LoadDivGraph("material\\burn_effect\\ef(6).png",14,14,1,240,240,Picture::burnEffect[Burn_Orange]);

	LoadDivGraph("material\\item_s.png",4,4,1,8,8,Picture::item[0]);
	LoadDivGraph("material\\item_l.png",4,4,1,12,12,Picture::item[1]);

	LoadDivGraph("material\\bullet\\eb_crystal.png",8,8,1,11,19,Picture::bullet[Bul_Crystal]);
	LoadDivGraph("material\\bullet\\eb_fuda.png",8,8,1,18,20,Picture::bullet[Bul_Fuda]);
	LoadDivGraph("material\\bullet\\eb_gun.png",8,8,1,11,19,Picture::bullet[Bul_Gun]);
	LoadDivGraph("material\\bullet\\eb_knife.png",8,8,1,17,15,Picture::bullet[Bul_Knife]);
	LoadDivGraph("material\\bullet\\eb_kunai.png",8,8,1,13,24,Picture::bullet[Bul_Kunai]);
	LoadDivGraph("material\\bullet\\eb_large.png",8,8,1,64,64,Picture::bullet[Bul_Large]);
	LoadDivGraph("material\\bullet\\eb_lazer.png",8,8,1,18,28,Picture::bullet[Bul_Lazer]);
	LoadDivGraph("material\\bullet\\eb_middle.png",8,8,1,30,30,Picture::bullet[Bul_Middle]);
	LoadDivGraph("material\\bullet\\eb_money.png",8,8,1,19,18,Picture::bullet[Bul_Money]);
	LoadDivGraph("material\\bullet\\eb_niddle.png",8,8,1,6,18,Picture::bullet[Bul_Niddle]);
	LoadDivGraph("material\\bullet\\eb_oval.png",8,8,1,20,38,Picture::bullet[Bul_Oval]);
	LoadDivGraph("material\\bullet\\eb_small.png",8,8,1,12,12,Picture::bullet[Bul_Small]);
	LoadDivGraph("material\\bullet\\eb_snow.png",8,8,1,16,16,Picture::bullet[Bul_Snow]);
	LoadDivGraph("material\\bullet\\eb_star_l.png",8,8,1,32,32,Picture::bullet[Bul_LargeStar]);
	LoadDivGraph("material\\bullet\\eb_star_s.png",8,8,1,20,20,Picture::bullet[Bul_SmallStar]);

	Picture::numbers[0][0] = LoadGraph("material\\numbers\\blue\\b0.png");
	Picture::numbers[0][1] = LoadGraph("material\\numbers\\blue\\b1.png");
	Picture::numbers[0][2] = LoadGraph("material\\numbers\\blue\\b2.png");
	Picture::numbers[0][3] = LoadGraph("material\\numbers\\blue\\b3.png");
	Picture::numbers[0][4] = LoadGraph("material\\numbers\\blue\\b4.png");
	Picture::numbers[0][5] = LoadGraph("material\\numbers\\blue\\b5.png");
	Picture::numbers[0][6] = LoadGraph("material\\numbers\\blue\\b6.png");
	Picture::numbers[0][7] = LoadGraph("material\\numbers\\blue\\b7.png");
	Picture::numbers[0][8] = LoadGraph("material\\numbers\\blue\\b8.png");
	Picture::numbers[0][9] = LoadGraph("material\\numbers\\blue\\b9.png");

	Picture::numbers[1][0] = LoadGraph("material\\numbers\\green\\g0.png");
	Picture::numbers[1][1] = LoadGraph("material\\numbers\\green\\g1.png");
	Picture::numbers[1][2] = LoadGraph("material\\numbers\\green\\g2.png");
	Picture::numbers[1][3] = LoadGraph("material\\numbers\\green\\g3.png");
	Picture::numbers[1][4] = LoadGraph("material\\numbers\\green\\g4.png");
	Picture::numbers[1][5] = LoadGraph("material\\numbers\\green\\g5.png");
	Picture::numbers[1][6] = LoadGraph("material\\numbers\\green\\g6.png");
	Picture::numbers[1][7] = LoadGraph("material\\numbers\\green\\g7.png");
	Picture::numbers[1][8] = LoadGraph("material\\numbers\\green\\g8.png");
	Picture::numbers[1][9] = LoadGraph("material\\numbers\\green\\g9.png");

	Picture::numbers[2][0] = LoadGraph("material\\numbers\\red\\r0.png");
	Picture::numbers[2][1] = LoadGraph("material\\numbers\\red\\r1.png");
	Picture::numbers[2][2] = LoadGraph("material\\numbers\\red\\r2.png");
	Picture::numbers[2][3] = LoadGraph("material\\numbers\\red\\r3.png");
	Picture::numbers[2][4] = LoadGraph("material\\numbers\\red\\r4.png");
	Picture::numbers[2][5] = LoadGraph("material\\numbers\\red\\r5.png");
	Picture::numbers[2][6] = LoadGraph("material\\numbers\\red\\r6.png");
	Picture::numbers[2][7] = LoadGraph("material\\numbers\\red\\r7.png");
	Picture::numbers[2][8] = LoadGraph("material\\numbers\\red\\r8.png");
	Picture::numbers[2][9] = LoadGraph("material\\numbers\\red\\r9.png");

	Picture::numbers[3][0] = LoadGraph("material\\numbers\\white\\w0.png");
	Picture::numbers[3][1] = LoadGraph("material\\numbers\\white\\w1.png");
	Picture::numbers[3][2] = LoadGraph("material\\numbers\\white\\w2.png");
	Picture::numbers[3][3] = LoadGraph("material\\numbers\\white\\w3.png");
	Picture::numbers[3][4] = LoadGraph("material\\numbers\\white\\w4.png");
	Picture::numbers[3][5] = LoadGraph("material\\numbers\\white\\w5.png");
	Picture::numbers[3][6] = LoadGraph("material\\numbers\\white\\w6.png");
	Picture::numbers[3][7] = LoadGraph("material\\numbers\\white\\w7.png");
	Picture::numbers[3][8] = LoadGraph("material\\numbers\\white\\w8.png");
	Picture::numbers[3][9] = LoadGraph("material\\numbers\\white\\w9.png");

	Picture::title[0] = LoadGraph("material\\title\\title0.png");
	Picture::title[1] = LoadGraph("material\\title\\title1.png");
	Picture::title[2] = LoadGraph("material\\title\\title2.png");
	Picture::title[3] = LoadGraph("material\\title\\title3.png");
	Picture::title[4] = LoadGraph("material\\title\\title4.png");

	Picture::subtitle = LoadGraph("material\\title\\subtitle.png");

	/*int tmp[22];
	LoadDivGraph("material\\enemy.png",22,22,1,96,256,tmp);
	for(int i=0;i<22;i++){
		for(int j=0;j<24;j++){
			Picture::enemy[i][j] = DerivationGraph(32*(j%3),32*(j-(j%3))/3,32,32,tmp[i]);
		}
	}*/

	LoadDivGraph("material\\enemyChip\\e(1).png", 24, 3, 8, 24, 40, Picture::enemy[0]);
	LoadDivGraph("material\\enemyChip\\e(2).png", 24, 3, 8, 24, 40, Picture::enemy[1]);
	LoadDivGraph("material\\enemyChip\\e(3).png", 24, 3, 8, 22, 38, Picture::enemy[2]);
	LoadDivGraph("material\\enemyChip\\e(4).png", 24, 3, 8, 28, 36, Picture::enemy[3]);
	LoadDivGraph("material\\enemyChip\\e(5).png", 24, 3, 8, 26, 40, Picture::enemy[4]);
	LoadDivGraph("material\\enemyChip\\e(6).png", 24, 3, 8, 24, 42, Picture::enemy[5]);
	LoadDivGraph("material\\enemyChip\\e(7).png", 24, 3, 8, 26, 40, Picture::enemy[6]);
	LoadDivGraph("material\\enemyChip\\e(8).png", 24, 3, 8, 28, 38, Picture::enemy[7]);
	LoadDivGraph("material\\enemyChip\\e(9).png", 24, 3, 8, 28, 40, Picture::enemy[8]);
	LoadDivGraph("material\\enemyChip\\e(10).png", 24, 3, 8, 24, 40, Picture::enemy[9]);
	LoadDivGraph("material\\enemyChip\\e(11).png", 24, 3, 8, 24, 40, Picture::enemy[10]);
	LoadDivGraph("material\\enemyChip\\e(12).png", 24, 3, 8, 28, 40, Picture::enemy[11]);
	LoadDivGraph("material\\enemyChip\\e(13).png", 24, 3, 8, 24, 40, Picture::enemy[12]);
	LoadDivGraph("material\\enemyChip\\e(14).png", 24, 3, 8, 28, 42, Picture::enemy[13]);
	LoadDivGraph("material\\enemyChip\\e(15).png", 24, 3, 8, 28, 44, Picture::enemy[14]);
	LoadDivGraph("material\\enemyChip\\e(16).png", 24, 3, 8, 26, 42, Picture::enemy[15]);
	LoadDivGraph("material\\enemyChip\\e(17).png", 24, 3, 8, 24, 40, Picture::enemy[16]);
	LoadDivGraph("material\\enemyChip\\e(18).png", 24, 3, 8, 24, 42, Picture::enemy[17]);
	LoadDivGraph("material\\enemyChip\\e(19).png", 24, 3, 8, 26, 40, Picture::enemy[18]);
	LoadDivGraph("material\\enemyChip\\e(20).png", 24, 3, 8, 24, 42, Picture::enemy[19]);
	LoadDivGraph("material\\enemyChip\\e(21).png", 24, 3, 8, 24, 42, Picture::enemy[20]);
	LoadDivGraph("material\\enemyChip\\e(22).png", 24, 3, 8, 26, 40, Picture::enemy[21]);
	LoadDivGraph("material\\enemyChip\\e(23).png", 24, 3, 8, 24, 40, Picture::enemy[22]);
	LoadDivGraph("material\\enemyChip\\e(24).png", 24, 3, 8, 26, 40, Picture::enemy[23]);
	LoadDivGraph("material\\enemyChip\\e(25).png", 24, 3, 8, 26, 40, Picture::enemy[24]);
}

void Picture::loadEndingPicture(){

}

void Picture::deletePicture(){
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	InitGraph();
}


int Picture::getPlayer(double chip_rad){
	return Picture::player[1+Round(sin(chip_rad))];
}

int Picture::getEnemy(int kind,Direction dir,double chip_rad){
	if((kind >= 25)||(kind < 0)) return 0;
	return Picture::enemy[kind][3*dir + Round(sin(chip_rad)) + 1];
}

int Picture::getBoard(Direction dir){
	if((dir >= 4)||(dir<0)) return 0;
	return Picture::board[dir];
}

int Picture::getBullet(BulletKind kind,BulletColor color){
	return Picture::bullet[kind][color];
}

int Picture::getBurnEffect(BurnEffectColor color,int num){
	return Picture::burnEffect[color][num];
}

int Picture::getBackEffect(int kind){
	if((kind >= 5)||(kind<0)) return 0;
	return Picture::backEffect[kind];
}

int Picture::getTextEffect(TextEffectKind kind){
	return Picture::textEffect[kind];
}

int Picture::getSelectText(TextPictureKind kind){
	return Picture::selectText[kind];
}

int Picture::getNumbers(NumbersColor color,int num){
	if((num >= 10)||(num < 0)) return 0;
	return Picture::numbers[(int)color][num];
}

int Picture::getDot(){
	return Picture::dot;
}

int Picture::getSlash(){
	return Picture::slash;
}

int Picture::getPlayerBomb(){
	return Picture::playerBomb;
}

int Picture::getBossBarrage(){
	return Picture::bossBarrage;
}

int Picture::getBossMarker(){
	return Picture::bossMarker;
}

int Picture::getItem(ItemKind kind,ItemColor color){
	return Picture::item[kind][color];
}

int Picture::getEnemyLife(bool isPink){
	if(isPink==true) return Picture::enemyLife[0];
	else return Picture::enemyLife[1];
}

int Picture::getWindowBase(WindowBaseLocation location){
	return Picture::windowBase[location];
}

int Picture::getBack(int kind){
	if((kind!=0)&&(kind!=1)) return 0;
	return Picture::back[kind];
}

int Picture::getExplode(int count){
	return Picture::explode[count];
}

int Picture::getShockWave_l(int count){
	return Picture::shockwave_l[count];
}

int Picture::getShockWave_s(int count){
	return Picture::shockwave_s[count];
}

int Picture::getPlayerModeExplain(int type){
	if (type == 0) return Picture::modeExplainText[0];
	else if (type == 1) return Picture::modeExplainText[1];
	else return Picture::modeExplainText[2];
}

int Picture::getPlayerRecovery(int count){
	return Picture::playerRecovery[count];
}

int Picture::getCollapsar(int count){
	return Picture::collapsar[count];
}

int Picture::getTitle(int count){
	return Picture::title[count];
}

int Picture::getSubTitle(){
	return Picture::subtitle;
}