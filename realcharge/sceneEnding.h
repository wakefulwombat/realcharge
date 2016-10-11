#ifndef _SCENEENDING_
#define _SCENEENDING_

#include "sceneBase.h"
#include "common.h"
#include <vector>
#include <string>
using namespace std;

struct EndText{
	Point pos;
	int app_time,dis_time;
	bool valid;
	string text;
};

class SceneEnding : public SceneBase{
private:
	int count;
	vector<EndText> textList;

	void loadCSV();
public:
	SceneEnding(ISetNextScene* changer);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif