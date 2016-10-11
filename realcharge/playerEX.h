#ifndef _PLAYEREX_
#define _PLAYEREX_

#include "charactor.h"
#include "isetPlayerBulletEX.h"
#include "IgetPlayerInfomation.h"
#include "IsetNumericalBar.h"

#include "IsetShockWave.h"
#include "IsetBomb.h"
#include "IsetItem.h"
#include "IsetBulletInvalid.h"
#include "IgetBossEventNow.h"
#include "isetStandBulletEX.h"
#include "IsetCollapsar.h"
#include "igetIsColding.h"

class PlayerEX : public Charactor, public IGetPlayerInfomation, public IGetIsColding{
private:
	int mode;//0:explode,1:stand,2:absorb

	int chargingPower;
	bool ignitionReceiptingNow;//起爆受付中(trueのときに被弾すると爆発)
	int ignitionReceiptTime;//起爆受付最大時間
	int ignitionReceiptCount;//起爆受付から経過した時間
	bool ignitionChargingNow;//起爆装置のチャージ中
	int ignitionChargingCount;//起爆装置のチャージ時間カウント
	int ignitionChargingTime_Success;//起爆チャージ時間
	int ignitionChargingTime_Failure;//起爆チャージ時間
	bool scatteringBombNow;//ボムをばらまいているか
	int scatteringBombCount;//ボムチャージ時間カウンタ
	int scatteringBombTime;//ボムチャージ時間
	bool isIgnitionSuccess;//起爆に成功したか

	int bulletPower;//攻撃力
	int shotBulletCount;//ショットに関する時間カウンタ
	bool canUseStandFlex, canUseStandStop;
	int chargingStandFlexCount, chargingStandStopCount;
	int standFlexTime;//フレックスチャージ時間
	int standStopTime;//ホールドチャージ時間
	bool isGrowingFlexR, isGrowingStopR;//半径増加中か
	int frexRadius, stopRadius;//スタンド有効半径
	Point stopStandCenter;//ストップの中心座標
	bool isColding;//ストップ領域凍結中
	int standStoppingCount;//凍結カウント
	int standStoppingTime;//最大凍結時間
	
	//int chargingPower;//被弾やアイテムによってためたパワー
	int waitingTimeAbsorb;
	int waitingTimeCollapsar;
	int waitingCountAbsorb;
	int waitingCountCollapsar;
	int runningTimeAbsorb;
	int runningCountAbsorb;
	bool canUseAbsorb;
	bool canUseCollapsar;
	bool isNowAbsorbing;

	int invincibleCount;//無敵時間カウント
	int prelife;

	ISetNumericalBar* isetNumericalBar;
	ISetItem* isetItem;
	ISetBulletInvalid* isetBulletInvalid;
	IGetBossEventNow* igetBossEventNow;

	ISetPlayerBulletEX* isetPlayerBulletEX;
	ISetStandBulletEX* isetStandBulletEX;

	ISetShockWave* isetShockWave;
	ISetBomb* isetBomb;
	ISetCollapsar* isetCollapsar;

public:
	PlayerEX();
	void initialize() override;
	void initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetPlayerBulletEX* isetPlayerBulletEX, ISetStandBulletEX* isetStandBulletEX, int difficulty, bool isBossPractice = false);
	void initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetShockWave* isetShockWave, ISetBomb* isetBomb, int difficulty, bool isBossPractice = false);
	void initialize(ISetNumericalBar* isetNumericalBar, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow, ISetShockWave* isetShockWave, ISetCollapsar* isetCollapsar, int difficulty, bool isBossPractice = false);
	void update() override;
	void draw() override;
	void finalize() override;

	void die();
	CharactorStatus getCharactorStatus(){ return this->status; }
	void addLife(int addVal);

	bool isIgnitionReceipting(){ return this->ignitionReceiptingNow; }
	void addChargingPower(int addVal);
	void setIgnitionSuccess();

	void addBulletPower(int addVal);
	void addRecoveringTimeStandStop(int addTime);//回復時間を速める
	void decreaseAbsorbRunnningCount(int time);//アブソーブの経過時間を戻す

	bool isAbsorbReceipting(){ return this->isNowAbsorbing; }

	int igetPlayerChargingPower() override { return this->chargingPower; }
	int igetPlayerLife() override { return this->life; };
	int igetPlayerEXShotPower() override { return this->bulletPower; }

	bool igetIsColding() override { return this->isColding; }
};

#endif