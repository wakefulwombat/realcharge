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
	bool ignitionReceiptingNow;//�N����t��(true�̂Ƃ��ɔ�e����Ɣ���)
	int ignitionReceiptCount;//�N����t����o�߂�������
	bool ignitionChargingNow;//�N�����u�̃`���[�W��
	int ignitionChargingCount;//�N�����u�̃`���[�W���ԃJ�E���g
	const int ignitionChargingTime;
	bool scatteringBombNow;//�{�����΂�܂��Ă��邩
	int scatteringBombCount;//�{���`���[�W����
	const int scatteringBombTime;
	int invincibleCount;//���G���ԃJ�E���g

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