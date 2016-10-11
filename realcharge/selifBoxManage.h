#ifndef _SELIFBOXMANAGE_
#define _SELIFBOXMANAGE_

#include "selifBox.h"
#include "IsetSelifBox.h"
#include "taskBase.h"
#include "igetPosition.h"
#include <list>
using namespace std;

class SelifBoxManage : public TaskBase,public ISetSelifBox{
private:
	int count;
	list<SelifBox*> selifBox;
public:
	SelifBoxManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size) override;
	void isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime) override;
	void isetSelifBox(Point centerPosition,string text,Size size) override;
	void isetRemoveSelifBoxAll () override;
	bool isEndSelifBox();
};

#endif