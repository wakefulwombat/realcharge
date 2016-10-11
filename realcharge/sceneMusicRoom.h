#ifndef _SCENEMUSICROOM_
#define _SCENEMUSICROOM_

#include "sceneBase.h"
#include "backEffectManage.h"
#include "selifBoxManage.h"
#include <string>
using namespace std;

struct MusicComment{
	string theme;
	string comment;
};

class SceneMusicRoom : public SceneBase{
	int selectNum;
	BackEffectManage* backEffectManage;
	SelifBoxManage* selifBoxManage;
	MusicComment musicComment[17];
	int count;

	void loadMusicComment();

public:
	SceneMusicRoom(ISetNextScene* changer);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif