#ifndef _BOSSATTACK_5_
#define _BOSSATTACK_5_

#include "bossAttack.h"
#include "lsystem.h"

//stage5 attacknum1 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_1_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_1_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_1_Easy(){ delete this->fractal; }
};

class BossAttack_5_1_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_1_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_1_Normal(){ delete this->fractal; }
};

class BossAttack_5_1_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_1_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_1_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum2 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_2_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_2_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_2_Easy(){ delete this->fractal; }
};

class BossAttack_5_2_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_2_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_2_Normal(){ delete this->fractal; }
};

class BossAttack_5_2_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_2_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_2_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum3 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_3_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_3_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_3_Easy(){ delete this->fractal; }
};

class BossAttack_5_3_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_3_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_3_Normal(){ delete this->fractal; }
};

class BossAttack_5_3_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_3_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_3_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum4 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_4_Easy : public BossAttack{
private:
	LSystem* waterweed[3];
	
	void move() override;
	void attack() override;
public:
	BossAttack_5_4_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_4_Easy(){ for (int i = 0; i < 3; i++) delete this->waterweed[i]; };
};

class BossAttack_5_4_Normal : public BossAttack{
private:
	LSystem* waterweed[3];

	void move() override;
	void attack() override;
public:
	BossAttack_5_4_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_4_Normal(){ for (int i = 0; i < 3; i++) delete this->waterweed[i]; };
};

class BossAttack_5_4_Hard : public BossAttack{
private:
	LSystem* waterweed[3];

	void move() override;
	void attack() override;
public:
	BossAttack_5_4_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_4_Hard(){ for (int i = 0; i < 3;i++) delete this->waterweed[i]; };
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum5 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_5_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_5_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_5_Easy(){ delete this->fractal; }
};

class BossAttack_5_5_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_5_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_5_Normal(){ delete this->fractal; }
};

class BossAttack_5_5_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_5_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_5_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum6 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_6_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_6_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_6_Easy(){ delete this->fractal; }
};

class BossAttack_5_6_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_6_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_6_Normal(){ delete this->fractal; }
};

class BossAttack_5_6_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_6_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_6_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum7 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_7_Easy : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_7_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_7_Easy(){ delete this->fractal; }
};

class BossAttack_5_7_Normal : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_7_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_7_Normal(){ delete this->fractal; }
};

class BossAttack_5_7_Hard : public BossAttack{
private:
	LSystem* fractal;

	void move() override;
	void attack() override;
public:
	BossAttack_5_7_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_7_Hard(){ delete this->fractal; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//stage5 attacknum8 boss0////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class BossAttack_5_8_Easy : public BossAttack{
private:
	LSystem* tree[2];
	int tree_kind[2];
	LSystem* flower;

	void move() override;
	void attack() override;
public:
	BossAttack_5_8_Easy(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_8_Easy(){ for (int i = 0; i < 2; i++) delete this->tree[i]; delete this->flower; }
};

class BossAttack_5_8_Normal : public BossAttack{
private:
	LSystem* tree[2];
	int tree_kind[2];
	LSystem* flower;

	void move() override;
	void attack() override;
public:
	BossAttack_5_8_Normal(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_8_Normal(){ for (int i = 0; i < 2; i++) delete this->tree[i]; delete this->flower; }
};

class BossAttack_5_8_Hard : public BossAttack{
private:
	LSystem* tree[2];
	int tree_kind[2];
	LSystem* flower;

	void move() override;
	void attack() override;
public:
	BossAttack_5_8_Hard(IGetPosition* igetPlayerPosition, IGetPosition* igetBossPosition, ISetBullet* isetBullet, int mode);
	~BossAttack_5_8_Hard(){ for (int i = 0; i < 2; i++) delete this->tree[i]; delete this->flower; }
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif