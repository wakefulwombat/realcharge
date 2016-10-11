#ifndef _ISETITEM_
#define _ISETITEM_

#include "item.h"
#include "IgetPosition.h"

class ISetItem{
public:
	virtual void isetItem(Point position,ItemColor color,ItemKind kind,IGetPosition* playerPosition)=0;
	virtual void isetItemStatusRetrieve() = 0;
};

#endif