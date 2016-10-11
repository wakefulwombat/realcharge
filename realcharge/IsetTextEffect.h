#ifndef _ISETTEXTEFFECT_
#define _ISETTEXTEFFECT_

#include "textEffect.h"

class ISetTextEffect{
public:
	virtual void isetTextEffect(TextEffectKind kind) = 0;
};

#endif