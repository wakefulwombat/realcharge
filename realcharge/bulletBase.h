#ifndef _BULLETBASE_
#define _BULLETBASE_

#include "mover.h"
#include "IsetBullet.h"

enum BulletKind{
	Bul_Crystal,
	Bul_Fuda,
	Bul_Gun,
	Bul_Knife,
	Bul_Kunai,
	Bul_Large,
	Bul_Lazer,
	Bul_Middle,
	Bul_Money,
	Bul_Niddle,
	Bul_Oval,
	Bul_Small,
	Bul_Snow,
	Bul_LargeStar,
	Bul_SmallStar,
};

enum BulletColor{
	Bul_Red,
	Bul_Orange,
	Bul_Yellow,
	Bul_Green,
	Bul_WaterBlue,
	Bul_Blue,
	Bul_Purple,
	Bul_White,
};

class BulletBase : public Mover{
protected:
	ISetBullet* isetBullet;

public:
	void setInvalid(){ this->validated = false; }
	int getCount(){ return this->count; }
};

#endif