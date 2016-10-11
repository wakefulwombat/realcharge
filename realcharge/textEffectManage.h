#ifndef _TEXTEFFECTMANAGER_
#define _TEXTEFFECTMANAGER_

#include "taskBase.h"
#include "textEffect.h"
#include "IsetTextEffect.h"
#include <vector>
using namespace std;

class TextEffectManage : public TaskBase, public ISetTextEffect{
private:
	vector<TextEffect*> textEffect;
	int vectorSize_pre;

public:
	TextEffectManage();
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;

	void isetTextEffect(TextEffectKind kind) override;
};

#endif