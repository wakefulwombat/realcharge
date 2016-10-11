#ifndef _BOSSATTACK_3_
#define _BOSSATTACK_3_

#include "bossAttack.h"
#include "common.h"

//stage3 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_1_Easy : public BossAttack{
private:
	double angle[10];
	Point pos[10];

	void move() override;
	void attack() override;
public:
	BossAttack_3_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_1_Normal : public BossAttack{
private:
	double angle[10];
	Point pos[10];

	void move() override;
	void attack() override;
public:
	BossAttack_3_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_1_Hard : public BossAttack{
private:
	double angle[10];
	Point pos[10];

	void move() override;
	void attack() override;
public:
	BossAttack_3_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage3 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_2_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_2_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_2_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage3 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_3_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_3_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_3_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage3 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_4_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_4_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_4_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage3 attacknum5 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_5_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_5_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_5_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_3_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage3 attacknum6 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_3_6_Easy : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_3_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_6_Normal : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_3_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_3_6_Hard : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_3_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif