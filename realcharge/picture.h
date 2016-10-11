#ifndef _PICTURE_
#define _PICTURE_

#include "charactor.h"
#include "Item.h"
#include "bullet.h"
#include "textEffect.h"
#include "burnEffect.h"
#include "selifBox.h"

enum NumbersColor{
	Number_Blue,
	Number_Green,
	Number_Red,
	Number_White
};

enum TextPictureKind{
	SEL_GAMESTART,
	SEL_EXTRASTAGE,
	SEL_STAGEPRACTICE,
	SEL_BOSSPRACTICE,
	SEL_MUSICROOM,
	SEL_KEYCONFIG,
	SEL_QUIT,
	SEL_EASY,
	SEL_NORMAL,
	SEL_HARD,
	SEL_RETURN,
	SEL_REBOSS,
	SEL_RESTAGE,
	SEL_REGAME,
	SEL_TITLE,
	SEL_STAGE1,
	SEL_STAGE2,
	SEL_STAGE3,
	SEL_STAGE4,
	SEL_STAGE5,
	SEL_STAGE6,
	SEL_STAGEEXTRA,
	SEL_EXPLAINEATTACKING,
	SEL_EXPLAINNEUTRAL,
	SEL_EXPLAINDEFENSIVE,
	SEL_ATTACKSELECT,
	SEL_STAGESELECT,
	SEL_MODESELECT,
	SEL_RANKSELECT,
	SEL_MUSICSELECT,
	SEL_KEYSELECT,
	SEL_CLEAR
};


class Picture{
private:
	static int player[];//[chip]
	static int enemy[][24];//[kind][chip]
	static int board[];//[direction]
	static int bullet[][8];//[kind][color]
	static int burnEffect[][14];//[color][count]
	static int backEffect[];//[kind]
	static int textEffect[];//[kind]
	static int selectText[];//[kind]
	static int numbers[][10];//[color][number]
	static int dot,slash;
	static int playerBomb,bossBarrage,bossMarker;
	static int item[][4];//[size][color]
	static int enemyLife[2];
	static int windowBase[];
	static int back[];
	static int explode[];
	static int shockwave_l[],shockwave_s[];
	static int modeExplainText[];
	static int playerRecovery[];
	static int collapsar[];
	static int title[];
	static int subtitle;

public:
	static void loadAllPicture();
	static void loadOpeningPicture();
	static void loadStagePicture();
	static void loadEndingPicture();
	static void deletePicture();

	static int getPlayer(double chip_rad);
	static int getEnemy(int kind,Direction dir,double chip_rad);
	static int getBoard(Direction dir);
	static int getBullet(BulletKind kind,BulletColor color);
	static int getBurnEffect(BurnEffectColor color,int num);
	static int getBackEffect(int kind);
	static int getTextEffect(TextEffectKind kind);
	static int getSelectText(TextPictureKind kind);
	static int getNumbers(NumbersColor color,int num);
	static int getDot();
	static int getSlash();
	static int getPlayerBomb();
	static int getBossBarrage();
	static int getBossMarker();
	static int getItem(ItemKind kind,ItemColor color);
	static int getEnemyLife(bool isPink = true);
	static int getWindowBase(WindowBaseLocation location);
	static int getBack(int kind);
	static int getExplode(int count);
	static int getShockWave_l(int count);
	static int getShockWave_s(int count);
	static int getPlayerModeExplain(int type);
	static int getPlayerRecovery(int count);
	static int getCollapsar(int count);
	static int getTitle(int count);
	static int getSubTitle();
};


#endif