#ifndef _ISETNUMERICALBAR_
#define _ISETNUMERICALBAR_

#include "IgetPosition.h"

class ISetNumericalBar{
public:
	virtual void isetNumericalBar(IGetPosition* igetPosition, const double* numer, const double* denom, bool isPink, bool invalidAtZero, bool isPlayer) = 0;
	virtual void isetNumericalBar(IGetPosition* igetPosition, const int* numer, const int* denom, bool isPink, bool invalidAtZero, bool isPlayer) = 0;
	virtual void isetNumericalBarClearAroundPlayer() = 0;
};

#endif