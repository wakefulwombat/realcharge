#ifndef _ITEM_
#define _ITEM_

#include "mover.h"
#include "IgetPosition.h"

enum ItemKind{
	Item_Small,
	Item_Large
};

enum ItemColor{
	Item_Red,
	Item_Green,
	Item_Blue,
	Item_White
};

enum ItemStatus{
	Item_Appearing,
	Item_Falling,
	Item_Retrieved
};

class Item : public Mover{
private:
	ItemKind kind;
	ItemColor color;
	ItemStatus status;
	IGetPosition* playerPosition;
public:
	Item(Point position,ItemColor color,ItemKind kind,IGetPosition* playerPosition);
	void initialize() override ;
	void update() override ;
	void draw() override ;
	void finalize() override ;

	void setStatus(ItemStatus status);
	void setInvalid(){ this->validated = false; };
	ItemKind getKind(){ return this->kind; };
	ItemColor getColor(){ return this->color; };
};

#endif