#ifndef _SCENEKEYCONFIG_
#define _SCENEKEYCONFIG_

#include "sceneBase.h"
#include "backEffectManage.h"



class SceneKeyConfig : public SceneBase{
	int selectNum;
	int selectingMode;//0:other, 1:explode, 2:stand, 3:absorb

	unsigned char registedKeyBoardCode_explode[4];
	unsigned int registedJoyPadCode_explode[4];
	unsigned char registedKeyBoardCode_stand[4];
	unsigned int registedJoyPadCode_stand[4];
	unsigned char registedKeyBoardCode_absorb[4];
	unsigned int registedJoyPadCode_absorb[4];

	unsigned char registedKeyBoardCode_OK;
	unsigned int registedJoyPadCode_OK;
	unsigned char registedKeyBoardCode_cancel;
	unsigned int registedJoyPadCode_cancel;
	unsigned char registedKeyBoardCode_pause;
	unsigned int registedJoyPadCode_pause;

	Selection other[4];//ok,cancel,pause,exit
	Selection explode[5];//slow,bomb,igni,charge,exit
	Selection stand[5];//slow,shot,flex,hold,exit
	Selection absorb[5];//slow,abso,relea,colle,exit

	BackEffectManage* backEffectManager;
	int bfCount;

	void inputNewKeyConfig();

	void initPosOutOfScreen_Other();
	void initPosOutOfScreen_Explode();
	void initPosOutOfScreen_Stand();
	void initPosOutOfScreen_Absorb();
public:
	SceneKeyConfig(ISetNextScene* changer);
	void initialize() override;
	void update() override;
	void draw() override;
	void finalize() override;
};

#endif