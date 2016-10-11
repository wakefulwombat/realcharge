#ifndef _BOARD_
#define _BOARD_

#include "fixObject.h"
#include "IgetPlayerInfomation.h"
#include "IaddBeatedCount.h"
#include "IgetBoss.h"
#include "IgetBossEventNow.h"

class Board : public FixObject,public IAddBeatedCount{
private:
	IGetPlayerInfomation* getPlayerInfomation;
	IGetBoss* igetBoss;
	IGetBossEventNow* igetBossEvemtNow;
	unsigned long score;
	int beatedCount;
	int score_;//ÉXÉRÉAàÍéûï€ë∂èÍèä
	int playerMode;
public:
	Board(IGetPlayerInfomation *igetPlayerInfomation, IGetBoss* igetBoss, IGetBossEventNow* igetBossEvemtNow, int playerMode);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void addScore(int add);
	void iaddBeatedCount() override;
};

#endif