#ifndef _COLLAPSARMANAGE_
#define _COLLAPSARMANAGE_

#include "taskBase.h"
#include "vector"
#include "collapsar.h"
#include "IsetCollapsar.h"
using namespace std;

class CollapsarManage: public TaskBase, public ISetCollapsar{
private:
	vector<Collapsar*> collapsar;
	
	int count;
	int difficulty;
	Point center;
	bool isCollapsing;

public:
	CollapsarManage(int difficulty);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	Size getSize(){ return Size(120, 120); }
	int getVectorSize(){ return this->collapsar.size(); }
	Point getPosition(int vectorIndex){ return this->collapsar[vectorIndex]->getPosition(); }

	void istartCollapsar(Point center) override;
};

#endif