#ifndef _SHOCKWAVEMANAGE_
#define _SHOCKWAVEMANAGE_

#include "taskBase.h"
#include "shockWave.h"
#include "shockLazer.h"
#include "IsetShockWave.h"
#include "IgetEnemyInfomation.h"
#include "IsetBurnEffect.h"
#include "IgetBoss.h"
#include "IgetBossEventNow.h"
#include "IsetBossDamage.h"
#include "isetStandShockLazerEX.h"
#include "bulletBase.h"
#include <vector>
using namespace std;

class ShockWaveManage : public TaskBase,public ISetShockWave ,public ISetStandShockLazerEX{
private:
	vector<ShockWave*> shockWave;
	vector<ShockLazer*> shockLazer;
	IGetEnemyInfomation* igetEnemyInfomaton;
	IGetBoss* igetBoss;
	IGetBossEventNow* igetBossEventNow;
	bool isBossPractice;

public:
	ShockWaveManage(IGetEnemyInfomation* igetEnemyInfomaton, IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow);
	ShockWaveManage(IGetBoss* igetBoss, IGetBossEventNow* igetBossEventNow);//ボスプラクティス用
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getShockWaveVectorSize(){ return this->shockWave.size(); }
	int getShockLazerVectorSize(){ return this->shockLazer.size(); }
	int getShockLazerDivVectorSize(int lazerVector){ return this->shockLazer[lazerVector]->getVectorSize(); }
	
	Point getShockWavePosition(int vectorIndex){ return this->shockWave[vectorIndex]->getPosition(); }
	Size getShockWaveSize(int vectorIndex){ return this->shockWave[vectorIndex]->getSize(); }
	int getShockWaveKind(int vectorIndex){ return this->shockWave[vectorIndex]->getKind(); }
	bool getShockWaveValid(int vectorIndex){ return this->shockWave[vectorIndex]->getValidate(); }
	void setShockWaveInvalid(int vectorIndex){ this->shockWave[vectorIndex]->setInvalid(); }
	double getShockWaveAttackPower(int vectorIndex){ return this->shockWave[vectorIndex]->getAttackPower(); }

	Point getShockLazerDivPosition(int vectorIndex, int divIndex){ return this->shockLazer[vectorIndex]->getDivPosition(divIndex); }
	Size getShockLazerDivSize(int vectorIndex){ return this->shockLazer[vectorIndex]->getSize(); }
	bool getShockLazerDivValid(int vectorIndex, int divIndex){ return this->shockLazer[vectorIndex]->getDivValid(divIndex); }
	void setShockLazerDivInvalid(int vectorIndex, int divIndex){ this->shockLazer[vectorIndex]->setDivInvalid(divIndex); }
	double getShockLazerAttackPower(int vectorIndex){ return this->shockLazer[vectorIndex]->getDivAttackPower(); }

	void isetShockWave(int power,Point position) override;
	void isetShockLazerStraight(Point position, bool slowMove) override;

	void isetStandShockLazerEX(Point pos) override;
};

#endif