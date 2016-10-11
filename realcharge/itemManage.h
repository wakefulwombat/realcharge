#ifndef _ITEMMANAGE_
#define _ITEMMANAGE_

#include "taskBase.h"
#include "item.h"
#include "IsetItem.h"
#include <vector>
using namespace std;

class ItemManage : public TaskBase,public ISetItem{
private:
	vector<Item*> item;
public:
	ItemManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	int getItemVectorSizeMax();
	Point getPosition(int vectorIndex);
	Size getSize(int vectorIndex);
	void setInvalid(int vectorIndex);
	ItemKind getKind(int vectorIndex);
	ItemColor getColor(int vectorIndex);

	void isetItem(Point position,ItemColor color,ItemKind kind,IGetPosition* playerPosition) override;
	void isetItemStatusRetrieve() override;
};

#endif