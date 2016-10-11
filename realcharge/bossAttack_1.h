#ifndef _BOSSATTACK_1_
#define _BOSSATTACK_1_

#include "bossAttack.h"

//stage1 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_1_1_Easy :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_1_Normal :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_1_Hard :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage1 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_1_2_Easy :public BossAttack{
private:
	Point cp[4];
	void move() override;
	void attack() override;
public:
	BossAttack_1_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_2_Normal :public BossAttack{
private:
	Point cp[4];
	void move() override;
	void attack() override;
public:
	BossAttack_1_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_2_Hard :public BossAttack{
private:
	Point cp[4];
	void move() override;
	void attack() override;
public:
	BossAttack_1_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage1 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_1_3_Easy :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_3_Normal :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_3_Hard :public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_1_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage1 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_1_4_Easy :public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_1_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_4_Normal :public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_1_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_1_4_Hard :public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_1_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif