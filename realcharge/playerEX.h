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
	bool ignitionReceiptingNow;//�N����t��(true�̂Ƃ��ɔ�e����Ɣ���)
	int ignitionReceiptTime;//�N����t�ő厞��
	int ignitionReceiptCount;//�N����t����o�߂�������
	bool ignitionChargingNow;//�N�����u�̃`���[�W��
	int ignitionChargingCount;//�N�����u�̃`���[�W���ԃJ�E���g
	int ignitionChargingTime_Success;//�N���`���[�W����
	int ignitionChargingTime_Failure;//�N���`���[�W����
	bool scatteringBombNow;//�{�����΂�܂��Ă��邩
	int scatteringBombCount;//�{���`���[�W���ԃJ�E���^
	int scatteringBombTime;//�{���`���[�W����
	bool isIgnitionSuccess;//�N���ɐ���������

	int bulletPower;//�U����
	int shotBulletCount;//�V���b�g�Ɋւ��鎞�ԃJ�E���^
	bool canUseStandFlex, canUseStandStop;
	int chargingStandFlexCount, chargingStandStopCount;
	int standFlexTime;//�t���b�N�X�`���[�W����
	int standStopTime;//�z�[���h�`���[�W����
	bool isGrowingFlexR, isGrowingStopR;//���a��������
	int frexRadius, stopRadius;//�X�^���h�L�����a
	Point stopStandCenter;//�X�g�b�v�̒��S���W
	bool isColding;//�X�g�b�v�̈擀����
	int standStoppingCount;//�����J�E���g
	int standStoppingTime;//�ő哀������
	
	//int chargingPower;//��e��A�C�e���ɂ���Ă��߂��p���[
	int waitingTimeAbsorb;
	int waitingTimeCollapsar;
	int waitingCountAbsorb;
	int waitingCountCollapsar;
	int runningTimeAbsorb;
	int runningCountAbsorb;
	bool canUseAbsorb;
	bool canUseCollapsar;
	bool isNowAbsorbing;

	int invincibleCount;//���G���ԃJ�E���g
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
	void addRecoveringTimeStandStop(int addTime);//�񕜎��Ԃ𑬂߂�
	void decreaseAbsorbRunnningCount(int time);//�A�u�\�[�u�̌o�ߎ��Ԃ�߂�

	bool isAbsorbReceipting(){ return this->isNowAbsorbing; }

	int igetPlayerChargingPower() override { return this->chargingPower; }
	int igetPlayerLife() override { return this->life; };
	int igetPlayerEXShotPower() override { return this->bulletPower; }

	bool igetIsColding() override { return this->isColding; }
};

#endif