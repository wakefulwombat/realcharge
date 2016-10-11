#ifndef _BOSSATTACK_4_
#define _BOSSATTACK_4_

#include "bossAttack.h"

//stage4 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_1_Easy : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_1_Normal : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_1_Hard : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_2_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_2_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_2_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_3_Easy : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_3_Normal : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_3_Hard : public BossAttack{
private:
	double angle;

	void move() override;
	void attack() override;
public:
	BossAttack_4_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_4_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_4_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_4_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum5 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_5_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_5_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_5_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum6 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_6_Easy : public BossAttack{
private:
	double tilt;
	int distance;
	Point center;

	void move() override;
	void attack() override;
public:
	BossAttack_4_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_6_Normal : public BossAttack{
private:
	double tilt;
	int distance;
	Point center;

	void move() override;
	void attack() override;
public:
	BossAttack_4_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_6_Hard : public BossAttack{
private:
	double tilt;
	int distance;
	Point center;

	void move() override;
	void attack() override;
public:
	BossAttack_4_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum7 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_7_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_7_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_7_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage4 attacknum8 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_4_8_Easy : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_8_Normal : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};

class BossAttack_4_8_Hard : public BossAttack{
private:
	void move() override;
	void attack() override;
public:
	BossAttack_4_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#endif