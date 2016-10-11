#ifndef _BOSSATTACK_2_
#define _BOSSATTACK_2_

#include "bossAttack.h"

//stage2 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_1_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_1_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_1_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage2 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_2_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_2_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_2_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage2 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_3_Easy : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_3_Normal : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_3_Hard : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage2 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_4_Easy : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_4_Normal : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_4_Hard : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_2_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage2 attacknum5 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_5_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_5_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_5_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_2_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage2 attacknum6 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_2_6_Easy : public BossAttack{
private:
	double angle;
	double omega;

	void move() override;
	void attack() override;
public:
	BossAttack_2_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_6_Normal : public BossAttack{
private:
	double angle;
	double omega;

	void move() override;
	void attack() override;
public:
	BossAttack_2_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_2_6_Hard : public BossAttack{
private:
	double angle;
	double omega;

	void move() override;
	void attack() override;
public:
	BossAttack_2_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif