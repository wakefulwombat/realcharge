#ifndef _TEXTEFFECT_
#define _TEXTEFFECT_

#include "fixObject.h"

enum TextEffectKind{
	TXT_STAGE_CLEAR,
	TXT_BARRAGE_BREAK,
	TXT_BOSS_BREAK,
	TXT_FAILURE,
	TXT_GET_BONUS
};

class TextEffect : public FixObject{
private:
	TextEffectKind kind;
	int movec;
	bool moveFlag;
	Point moveDistance;

public:
	TextEffect(int pos_y, TextEffectKind kind);

	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void moveTo(int newPos_y);
	bool isMoving();
};


#endif