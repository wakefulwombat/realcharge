#ifndef _LAZERDIV_
#define _LAZERDIV_
#include "common.h"

struct LazerDiv{
	Point center,before_center;
	double rotate_rad,before_rotate_rad;
	int count;
	bool validated,isTop;
};

#endif