#ifndef _INPUT_
#define _INPUT_

enum KeyCode_Explode{
	KeyCodeExplode_SlowMove,
	KeyCodeExplode_ScatterBomb,
	KeyCodeExplode_Ignition,
	KeyCodeExplode_ReleasePower,
	KeyCodeExplode_OK,
	KeyCodeExplode_Cancel,
	KeyCodeExplode_Pause
};

enum KeyCode_Stand{
	KeyCodeStand_SlowMove,
	KeyCodeStand_ShotBullet,
	KeyCodeStand_StandFlex,
	KeyCodeStand_StandHold,
	KeyCodeStand_OK,
	KeyCodeStand_Cancel,
	KeyCodeStand_Pause
};

enum KeyCode_Absorb{
	KeyCodeAbsorb_SlowMove,
	KeyCodeAbsorb_Absorb,
	KeyCodeAbsorb_Release,
	KeyCodeAbsorb_Collapsar,
	KeyCodeAbsorb_OK,
	KeyCodeAbsorb_Cancel,
	KeyCodeAbsorb_Pause
};

struct RegistedKeyCode{
	unsigned char keyBoard_Explode[4];
	unsigned int joyPad_Explode[4];
	unsigned char keyBoard_Stand[4];
	unsigned int joyPad_Stand[4];
	unsigned char keyBoard_Absorb[4];
	unsigned int joyPad_Absorb[4];

	unsigned char keyBoardOK;
	unsigned int joyPadOK;
	unsigned char keyBoardCancel;
	unsigned int joyPadCancel;
	unsigned char keyBoardPause;
	unsigned int joyPadPause;
};

class Input{
private:
	static bool joyPadflag;

	static RegistedKeyCode registedKeyCode;

	static int keyBoardState_Explode[];
	static int joyPadState_Explode[];
	static int keyBoardState_Stand[];
	static int joyPadState_Stand[];
	static int keyBoardState_Absorb[];
	static int joyPadState_Absorb[];

	static int keyBoardState_OK;
	static int joyPadState_OK;
	static int keyBoardState_Cancel;
	static int joyPadState_Cancel;
	static int keyBoardState_Pause;
	static int joyPadState_Pause;

	static int directionXKeyState,directionYKeyState;
	static bool fileExistT(char* filepath);//テキスト
	static bool fileExistB(char* filepath);//バイナリ

public:
	static void init();
	static void writeNewKeyConfig();
	static void keyUpdate();

	static int getGridXDown();//x軸方向{-1,0,1}
	static int getGridYDown();//y軸方向{-1,0,1}
	static int getGridXDownOnce();//x軸方向{-1,0,1}
	static int getGridYDownOnce();//y軸方向{-1,0,1}

	static int getkeyCodeDown_Explode(KeyCode_Explode keyCode);
	static int getkeyCodeDownOnce_Explode(KeyCode_Explode keyCode);
	static int getkeyCodeUpOnce_Explode(KeyCode_Explode keyCode);
	static int getkeyCodeDown_Stand(KeyCode_Stand keyCode);
	static int getkeyCodeDownOnce_Stand(KeyCode_Stand keyCode);
	static int getkeyCodeUpOnce_Stand(KeyCode_Stand keyCode);
	static int getkeyCodeDown_Absorb(KeyCode_Absorb keyCode);
	static int getkeyCodeDownOnce_Absorb(KeyCode_Absorb keyCode);
	static int getkeyCodeUpOnce_Absorb(KeyCode_Absorb keyCode);

	static bool getJoyPadFlag();
	static bool isAnyKeyCodeDown();
	
	static unsigned char getRegistedKeyCodeKeyBoard_Explode(KeyCode_Explode keyCode);
	static unsigned int getRegistedKeyCodeJoyPad_Explode(KeyCode_Explode keyCode);
	static void setRegistedKeyCodeKeyBoard_Explode(KeyCode_Explode keyCode, unsigned char registKeyCode);
	static void setRegistedKeyCodeJoyPad_Explode(KeyCode_Explode keyCode, unsigned int registKeyCode);
	
	static unsigned char getRegistedKeyCodeKeyBoard_Stand(KeyCode_Stand keyCode);
	static unsigned int getRegistedKeyCodeJoyPad_Stand(KeyCode_Stand keyCode);
	static void setRegistedKeyCodeKeyBoard_Stand(KeyCode_Stand keyCode, unsigned char registKeyCode);
	static void setRegistedKeyCodeJoyPad_Stand(KeyCode_Stand keyCode, unsigned int registKeyCode);

	static unsigned char getRegistedKeyCodeKeyBoard_Absorb(KeyCode_Absorb keyCode);
	static unsigned int getRegistedKeyCodeJoyPad_Absorb(KeyCode_Absorb keyCode);
	static void setRegistedKeyCodeKeyBoard_Absorb(KeyCode_Absorb keyCode, unsigned char registKeyCode);
	static void setRegistedKeyCodeJoyPad_Absorb(KeyCode_Absorb keyCode, unsigned int registKeyCode);
};


#endif