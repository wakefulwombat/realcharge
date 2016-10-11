#include "DxLib.h"
#include "common.h"
#include "picture.h"
#include "input.h"
#include "sceneManager.h"
#include "music.h"
#include "sound.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	SetOutApplicationLogValidFlag(FALSE);
	SetUseDXArchiveFlag(TRUE);
	SetDXArchiveExtension("dat");
	if (MessageBox(NULL, "フルスクリーンで起動しますか？", "起動オプション", MB_YESNO) == IDYES){
		ChangeWindowMode(0);
	}
	else{
		ChangeWindowMode(1);
	}
	SetGraphMode(WINDOW_WIDTH,WINDOW_HEIGHT,16);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetWindowText("現充爆奇譚 Real Charge Explosion ver1.00");

	if( DxLib_Init() == -1 ) return -1;

	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	SetDrawScreen( DX_SCREEN_BACK ) ;
	Picture::loadOpeningPicture();

	GGS4OpenDevice(GGSDEVICE_DIRECTMUSIC,NULL);
	Music::loadMusic();

	Input::init();
	Sound::loadSound();

	SceneManager *scene = new SceneManager();
	scene->initialize();

	while (1) {
		ClearDrawScreen()	;
		
		Input::keyUpdate();

		scene->update();
		scene->draw();

		Sound::PlayAll();

		ScreenFlip()	;

		if(scene->getQuit()==true) break;
		if (ProcessMessage() == -1 ) break	;
	}

	scene->finalize();
	delete scene;

	GGS4CloseDevice();

#ifndef _DEBUG
	DxLib_End();
#endif
	return 0;
}

int Round(double x){
	return (int)( x < 0.0 ? x-0.4999 : x+0.4999);
}