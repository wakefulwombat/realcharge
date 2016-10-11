#ifndef _PLAYER_
#define _PLAYER_

#include "charactor.h"
#include "IsetShockWave.h"
#include "IsetNumericalBar.h"
#include "IsetBomb.h"
#include "IgetPlayerInfomation.h"
#include "IsetItem.h"
#include "IsetBulletInvalid.h"
#include "IgetBossEventNow.h"

class Player : public Charactor,public IGetPlayerInfomation{
protected:
	int chargingPower;
	bool ignitionReceiptingNow;//起爆受付中(trueのときに被弾すると爆発)
	int ignitionReceiptCount;//起爆受付から経過した時間
	bool ignitionChargingNow;//起爆装置のチャージ中
	int ignitionChargingCount;//起爆装置のチャージ時間カウント
	const int ignitionChargingTime;
	bool scatteringBombNow;//ボムをばらまいているか
	int scatteringBombCount;//ボムチャージ時間
	const int scatteringBombTime;
	int invincibleCount;//無敵時間カウント

	int prelife;

	ISetShockWave* isetShockWave;
	ISetNumericalBar* isetNumericalBar;
	ISetBomb* isetBomb;
	ISetItem* isetItem;
	ISetBulletInvalid* isetBulletInvalid;
	IGetBossEventNow* igetBossEventNow;

public:
	Player();
	void initialize() override;
	void initialize(ISetShockWave* isetShockWave, ISetNumericalBar* isetNumericalBar, ISetBomb* isetBomb, ISetItem* isetItem, ISetBulletInvalid* isetBulletInvalid, IGetBossEventNow* igetBossEventNow);
	void update() override;
	void draw() override;
	void finalize() override;
	
	void die();
	bool isIgnitionReceipting(){ return this->ignitionReceiptingNow; }
	CharactorStatus getCharactorStatus(){ return this->status; }
	void addChargingPower(int addVal);
	void addLife(int addVal);

	int igetPlayerChargingPower() override;
	int igetPlayerLife() override;
	int igetPlayerEXShotPower() override { return 0; }
};

#endif