#ifndef _BOSSATTACK_6_
#define _BOSSATTACK_6_

#include "bossAttack.h"

//stage6 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_1_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_1_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_1_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_2_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_2_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_2_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_3_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_3_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_3_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_4_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_4_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_4_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum5 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_5_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_5_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_5_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum6 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_6_Easy : public BossAttack{
private:
	Point start;
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_6_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_6_Normal : public BossAttack{
private:
	Point start;
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_6_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_6_Hard : public BossAttack{
private:
	Point start;
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_6_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum7 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_7_Easy : public BossAttack{
private:
	double ang;

	void move() override;
	void attack() override;
public:
	BossAttack_6_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_7_Normal : public BossAttack{
private:
	double ang;

	void move() override;
	void attack() override;
public:
	BossAttack_6_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_7_Hard : public BossAttack{
private:
	double ang;

	void move() override;
	void attack() override;
public:
	BossAttack_6_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage6 attacknum8 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_6_8_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_8_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_6_8_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_6_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif