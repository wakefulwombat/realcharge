#ifndef _NUMERICALBAR_
#define _NUMERICALBAR_

#include "fixObject.h"
#include "IgetPosition.h"

class NumericalBar : public FixObject{
private:
	bool isCirclePink;
	bool type_int;
	bool invalidAtZero;//•ªq‚ª0‚É‚È‚Á‚Ä‚à”ñ•\¦‚É‚·‚é
	bool isPlayer;
	const double *numer_d,*denom_d;
	const int *numer_i,*denom_i;
	IGetPosition* igetPosition;
public:
	NumericalBar(IGetPosition* igetPosition, const double *numer, const double *denom, bool isCirclePink, bool invalidAtZero, bool isPlayer);
	NumericalBar(IGetPosition* igetPosition, const int *numer, const int *denom, bool isCirclePink, bool invalidAtZero, bool isPlayer);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	bool getIsPlayer(){ return this->isPlayer; }
	void setInvalid(){ this->validated = false; }
};

#endif