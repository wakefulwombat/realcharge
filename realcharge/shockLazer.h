#ifndef _SHOCKLAZER_
#define _SHOCKLAZER_

#include "shockLazerDiv.h"
#include "mover.h"
#include "IsetBurnEffect.h"
#include <vector>
using namespace std;

class ShockLazer : public Mover{
private:
	const int maxDivNum;//divÇÃêî
	int divCount;
	vector<ShockLazerDiv> shockLazerDiv;
	Point start,control1,end;
	double power;

	bool isVisivle(int index);
	Point getBezierNextPos(int count);
public:
	ShockLazer(const int maxNum,double power,Point start,Point end);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getVectorSize(){ return this->shockLazerDiv.size(); }
	Point getDivPosition(int divIndex){ return this->shockLazerDiv[divIndex].center; }
	Size getSize(){ return this->size; }

	bool getDivValid(int divIndex){ return this->shockLazerDiv[divIndex].validated; }
	void setDivInvalid(int divIndex){ this->shockLazerDiv[divIndex].validated = false; }
	double getDivAttackPower(){ return this->power; }
};

#endif