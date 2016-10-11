#ifndef _ISETNEXTSCENE_
#define _ISETNEXTSCENE_

enum SceneKind{
	Scene_Opening,
	Scene_SelectDifficulty,
	Scene_GameFilm,
	Scene_Ending,
	Scene_MusicRoom,
	Scene_KeyConfig,
	Scene_SelectModeExtra,
	Scene_GameExtra,
	Scene_SelectBossPractice,
	Scene_BossPractice,
	Scene_StagePractice,
	Scene_SelectPracticeStage,
	Scene_None
};

class ISetNextScene{
public:
	virtual ~ISetNextScene(){};
	virtual void isetNextScene(SceneKind nextScene)=0;
};

#endif