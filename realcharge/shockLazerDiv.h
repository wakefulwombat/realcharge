#ifndef _SHOCKLAZERDIV_
#define _SHOCKLAZERDIV_

#include "common.h"

struct ShockLazerDiv{
	Point center,before_center;
	double rotate_rad,before_rotate_rad;
	int count;
	bool validated;
	bool isInColding;//�X�^���h�̈���ɂ��邩
};

#endif