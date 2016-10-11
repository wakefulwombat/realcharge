#ifndef _NUMERICALBARMANAGE_
#define _NUMERICALBARMANAGE_

#include "numericalBar.h"
#include "IsetNumericalBar.h"
#include "taskBase.h"
#include <vector>
using namespace std;

class NumericalBarManage : public TaskBase,public ISetNumericalBar{
private:
	vector<NumericalBar*> numaricalBar;
public:
	NumericalBarManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetNumericalBar(IGetPosition* igetPosition, const double* numer, const double* denom, bool isPink, bool invalidAtZero, bool isPlayer) override;
	void isetNumericalBar(IGetPosition* igetPosition, const int* numer, const int* denom, bool isPink, bool invalidAtZero, bool isPlayer) override;
	void isetNumericalBarClearAroundPlayer() override;
};

#endif