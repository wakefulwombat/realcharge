#ifndef _ISETSELIFBOX_
#define _ISETSELIFBOX_

#include "igetPosition.h"
#include <string>
using namespace std;

class ISetSelifBox{
public:
	virtual void isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size)=0;
	virtual void isetSelifBox(IGetPosition* igetPosition,Point diff,string text,Size size,int removeTime)=0;
	virtual void isetSelifBox(Point centerPosition,string text,Size size)=0;
	virtual void isetRemoveSelifBoxAll()=0;
};

#endif