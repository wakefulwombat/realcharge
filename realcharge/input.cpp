#include "input.h"
#include "DxLib.h"
#include <stdio.h>

bool Input::joyPadflag=false;
RegistedKeyCode Input::registedKeyCode;
/*
unsigned int Input::registedKeyCodeJoyPad_Explode[4];
unsigned char Input::registedKeyCodeKeyBoard_Explode[4];
unsigned int Input::registedKeyCodeJoyPad_Stand[4];
unsigned char Input::registedKeyCodeKeyBoard_Stand[4];
unsigned int Input::registedKeyCodeJoyPad_Absorb[4];
unsigned char Input::registedKeyCodeKeyBoard_Absorb[4];

unsigned char Input::registedOKKeyBoard;
unsigned int Input::registedOKJoyPad;
unsigned char Input::registedCancelKeyBoard;
unsigned int Input::registedCancelJoyPad;
unsigned char Input::registedPauseKeyBoard;
unsigned int Input::registedPauseJoyPad;*/

int Input::keyBoardState_Explode[4];
int Input::joyPadState_Explode[4];
int Input::keyBoardState_Stand[4];
int Input::joyPadState_Stand[4]; 
int Input::keyBoardState_Absorb[4];
int Input::joyPadState_Absorb[4];

int Input::keyBoardState_OK;
int Input::joyPadState_OK;
int Input::keyBoardState_Cancel;
int Input::joyPadState_Cancel;
int Input::keyBoardState_Pause;
int Input::joyPadState_Pause;

int Input::directionXKeyState = 0;
int Input::directionYKeyState = 0;


bool Input::fileExistT(char* filepath){
	FILE* fp;
	if((fp=fopen(filepath,"r"))==NULL){
		return false;
	}
	fclose(fp);
	return true;
}

bool Input::fileExistB(char* filepath){
	FILE* fp;
	if((fp=fopen(filepath,"rb"))==NULL){
		return false;
	}
	fclose(fp);
	return true;
}

void Input::init(){
	if(Input::fileExistB("config.dat")==true){
		FILE* fp = fopen("config.dat","rb");

		/*
		fread(&Input::registedKeyCodeJoyPad[KeyCode_SlowMove],sizeof(unsigned int),1,fp);
		fread(&Input::registedKeyCodeJoyPad[KeyCode_ScatterBomb],sizeof(unsigned int),1,fp);
		fread(&Input::registedKeyCodeJoyPad[KeyCode_Ignition],sizeof(unsigned int),1,fp);
		fread(&Input::registedKeyCodeJoyPad[KeyCode_ReleasePower],sizeof(unsigned int),1,fp);

		fread(&Input::registedKeyCodeKeyBoard[KeyCode_SlowMove],sizeof(unsigned char),1,fp);
		fread(&Input::registedKeyCodeKeyBoard[KeyCode_ScatterBomb],sizeof(unsigned char),1,fp);
		fread(&Input::registedKeyCodeKeyBoard[KeyCode_Ignition],sizeof(unsigned char),1,fp);
		fread(&Input::registedKeyCodeKeyBoard[KeyCode_ReleasePower],sizeof(unsigned char),1,fp);

		fread(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_SlowMove], sizeof(unsigned int), 1, fp);
		fread(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_ShotBullet], sizeof(unsigned int), 1, fp);
		fread(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_StandFlex], sizeof(unsigned int), 1, fp);
		fread(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_StandStop], sizeof(unsigned int), 1, fp);

		fread(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_SlowMove], sizeof(unsigned char), 1, fp);
		fread(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_ShotBullet], sizeof(unsigned char), 1, fp);
		fread(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_StandFlex], sizeof(unsigned char), 1, fp);
		fread(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_StandStop], sizeof(unsigned char), 1, fp);

		fread(&Input::registedOKJoyPad, sizeof(unsigned int), 1, fp);
		fread(&Input::registedOKKeyBoard, sizeof(unsigned int), 1, fp);
		fread(&Input::registedCancelJoyPad, sizeof(unsigned int), 1, fp);
		fread(&Input::registedCancelKeyBoard, sizeof(unsigned int), 1, fp);
		fread(&Input::registedPauseJoyPad, sizeof(unsigned int), 1, fp);
		fread(&Input::registedPauseKeyBoard, sizeof(unsigned int), 1, fp);*/

		fread(&Input::registedKeyCode, sizeof(RegistedKeyCode), 1, fp);

		fclose(fp);
	}
	else{
		Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_SlowMove] = KEY_INPUT_LSHIFT;
		Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_ScatterBomb] = KEY_INPUT_Z;
		Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_Ignition] = KEY_INPUT_X;
		Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_ReleasePower] = KEY_INPUT_C;

		Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_SlowMove] = PAD_INPUT_1;
		Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_ScatterBomb] = PAD_INPUT_2;
		Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_Ignition] = PAD_INPUT_3;
		Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_ReleasePower] = PAD_INPUT_4;

		Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_SlowMove] = KEY_INPUT_LSHIFT;
		Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_ShotBullet] = KEY_INPUT_Z;
		Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_StandFlex] = KEY_INPUT_X;
		Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_StandHold] = KEY_INPUT_C;

		Input::registedKeyCode.joyPad_Stand[KeyCodeStand_SlowMove] = PAD_INPUT_1;
		Input::registedKeyCode.joyPad_Stand[KeyCodeStand_ShotBullet] = PAD_INPUT_2;
		Input::registedKeyCode.joyPad_Stand[KeyCodeStand_StandFlex] = PAD_INPUT_3;
		Input::registedKeyCode.joyPad_Stand[KeyCodeStand_StandHold] = PAD_INPUT_4;

		Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_SlowMove] = KEY_INPUT_LSHIFT;
		Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Absorb] = KEY_INPUT_Z;
		Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Release] = KEY_INPUT_X;
		Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Collapsar] = KEY_INPUT_C;

		Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_SlowMove] = PAD_INPUT_1;
		Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Absorb] = PAD_INPUT_2;
		Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Release] = PAD_INPUT_3;
		Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Collapsar] = PAD_INPUT_4;

		Input::registedKeyCode.joyPadOK = PAD_INPUT_1;
		Input::registedKeyCode.keyBoardOK = KEY_INPUT_Z;
		Input::registedKeyCode.joyPadCancel = PAD_INPUT_2;
		Input::registedKeyCode.keyBoardCancel = KEY_INPUT_X;
		Input::registedKeyCode.joyPadPause = PAD_INPUT_5;
		Input::registedKeyCode.keyBoardPause = KEY_INPUT_P;
	}
}

void Input::writeNewKeyConfig(){
	FILE* fp = fopen("config.dat", "wb");

	/*
	fwrite(&Input::registedKeyCodeJoyPad[KeyCode_SlowMove], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPad[KeyCode_ScatterBomb], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPad[KeyCode_Ignition], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPad[KeyCode_ReleasePower], sizeof(unsigned int), 1, fp);

	fwrite(&Input::registedKeyCodeKeyBoard[KeyCode_SlowMove], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoard[KeyCode_ScatterBomb], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoard[KeyCode_Ignition], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoard[KeyCode_ReleasePower], sizeof(unsigned char), 1, fp);

	fwrite(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_SlowMove], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_ShotBullet], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_StandFlex], sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedKeyCodeJoyPadEX[KeyCodeEX_StandStop], sizeof(unsigned int), 1, fp);

	fwrite(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_SlowMove], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_ShotBullet], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_StandFlex], sizeof(unsigned char), 1, fp);
	fwrite(&Input::registedKeyCodeKeyBoardEX[KeyCodeEX_StandStop], sizeof(unsigned char), 1, fp);

	fwrite(&Input::registedOKJoyPad, sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedOKKeyBoard, sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedCancelJoyPad, sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedCancelKeyBoard, sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedPauseJoyPad, sizeof(unsigned int), 1, fp);
	fwrite(&Input::registedPauseKeyBoard, sizeof(unsigned int), 1, fp);*/

	fwrite(&Input::registedKeyCode, sizeof(RegistedKeyCode), 1, fp);

	fclose(fp);
}

void Input::keyUpdate(){
	if(GetJoypadNum()==0) Input::joyPadflag=false;
	else Input::joyPadflag=true;

	if(Input::joyPadflag==true){//ゲームパッド
		int joyInput = GetJoypadInputState(DX_INPUT_PAD1);

		
		if ((joyInput&Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_SlowMove]) != 0) Input::joyPadState_Explode[KeyCodeExplode_SlowMove]++;
		else if (Input::joyPadState_Explode[KeyCodeExplode_SlowMove] > 0) Input::joyPadState_Explode[KeyCodeExplode_SlowMove] = -1;
		else Input::joyPadState_Explode[KeyCodeExplode_SlowMove] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_ScatterBomb]) != 0) Input::joyPadState_Explode[KeyCodeExplode_ScatterBomb]++;
		else if (Input::joyPadState_Explode[KeyCodeExplode_ScatterBomb] > 0) Input::joyPadState_Explode[KeyCodeExplode_ScatterBomb] = -1;
		else Input::joyPadState_Explode[KeyCodeExplode_ScatterBomb] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_Ignition]) != 0) Input::joyPadState_Explode[KeyCodeExplode_Ignition]++;
		else if (Input::joyPadState_Explode[KeyCodeExplode_Ignition] > 0) Input::joyPadState_Explode[KeyCodeExplode_Ignition] = -1;
		else Input::joyPadState_Explode[KeyCodeExplode_Ignition] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Explode[KeyCodeExplode_ReleasePower]) != 0) Input::joyPadState_Explode[KeyCodeExplode_ReleasePower]++;
		else if (Input::joyPadState_Explode[KeyCodeExplode_ReleasePower] > 0) Input::joyPadState_Explode[KeyCodeExplode_ReleasePower] = -1;
		else Input::joyPadState_Explode[KeyCodeExplode_ReleasePower] = 0;

		
		if ((joyInput&Input::registedKeyCode.joyPad_Stand[KeyCodeStand_SlowMove]) != 0) Input::joyPadState_Stand[KeyCodeStand_SlowMove]++;
		else if (Input::joyPadState_Stand[KeyCodeStand_SlowMove] > 0) Input::joyPadState_Stand[KeyCodeStand_SlowMove] = -1;
		else Input::joyPadState_Stand[KeyCodeStand_SlowMove] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Stand[KeyCodeStand_ShotBullet]) != 0) Input::joyPadState_Stand[KeyCodeStand_ShotBullet]++;
		else if (Input::joyPadState_Stand[KeyCodeStand_ShotBullet] > 0) Input::joyPadState_Stand[KeyCodeStand_ShotBullet] = -1;
		else Input::joyPadState_Stand[KeyCodeStand_ShotBullet] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Stand[KeyCodeStand_StandFlex]) != 0) Input::joyPadState_Stand[KeyCodeStand_StandFlex]++;
		else if (Input::joyPadState_Stand[KeyCodeStand_StandFlex] > 0) Input::joyPadState_Stand[KeyCodeStand_StandFlex] = -1;
		else Input::joyPadState_Stand[KeyCodeStand_StandFlex] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Stand[KeyCodeStand_StandHold]) != 0) Input::joyPadState_Stand[KeyCodeStand_StandHold]++;
		else if (Input::joyPadState_Stand[KeyCodeStand_StandHold] > 0) Input::joyPadState_Stand[KeyCodeStand_StandHold] = -1;
		else Input::joyPadState_Stand[KeyCodeStand_StandHold] = 0;


		if ((joyInput&Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_SlowMove]) != 0) Input::joyPadState_Absorb[KeyCodeAbsorb_SlowMove]++;
		else if (Input::joyPadState_Absorb[KeyCodeAbsorb_SlowMove] > 0) Input::joyPadState_Absorb[KeyCodeAbsorb_SlowMove] = -1;
		else Input::joyPadState_Absorb[KeyCodeAbsorb_SlowMove] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Absorb]) != 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Absorb]++;
		else if (Input::joyPadState_Absorb[KeyCodeAbsorb_Absorb] > 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Absorb] = -1;
		else Input::joyPadState_Absorb[KeyCodeAbsorb_Absorb] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Release]) != 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Release]++;
		else if (Input::joyPadState_Absorb[KeyCodeAbsorb_Release] > 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Release] = -1;
		else Input::joyPadState_Absorb[KeyCodeAbsorb_Release] = 0;

		if ((joyInput&Input::registedKeyCode.joyPad_Absorb[KeyCodeAbsorb_Collapsar]) != 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Collapsar]++;
		else if (Input::joyPadState_Absorb[KeyCodeAbsorb_Collapsar] > 0) Input::joyPadState_Absorb[KeyCodeAbsorb_Collapsar] = -1;
		else Input::joyPadState_Absorb[KeyCodeAbsorb_Collapsar] = 0;



		if ((joyInput&Input::registedKeyCode.joyPadOK) != 0){
			Input::joyPadState_OK++;
		}
		else{
			if (Input::joyPadState_OK > 0) Input::joyPadState_OK = -1;
			else Input::joyPadState_OK = 0;
		}

		if ((joyInput&Input::registedKeyCode.joyPadCancel) != 0){
			Input::joyPadState_Cancel++;
		}
		else{
			if (Input::joyPadState_Cancel > 0) Input::joyPadState_Cancel = -1;
			else Input::joyPadState_Cancel = 0;
			
		}

		if ((joyInput&Input::registedKeyCode.joyPadPause) != 0){
			Input::joyPadState_Pause++;
		}
		else{
			if (Input::joyPadState_Pause > 0) Input::joyPadState_Pause = -1;
			else Input::joyPadState_Pause = 0;
		}


		DINPUT_JOYSTATE input;
		GetJoypadDirectInputState( DX_INPUT_PAD1, &input ) ;

		if(((input.POV[0]>=22500)&&(input.POV[0]<=31500))||(input.X<=-500)){
			if(Input::directionXKeyState>0) Input::directionXKeyState=0;
			Input::directionXKeyState--;
		}
		else if(((input.POV[0]>=4500 )&&(input.POV[0]<=13500))||(input.X>=500 )){
			if(Input::directionXKeyState<0) Input::directionXKeyState=0;
			Input::directionXKeyState++;
		}
		else{
			Input::directionXKeyState = 0;
		}


		if(((input.POV[0]>=13500 )&&(input.POV[0]<=22500))||(input.Y>=500)){
			if(Input::directionYKeyState<0) Input::directionYKeyState=0;
			Input::directionYKeyState++;
		}
		else if((input.POV[0]==0)||(input.POV[0]==4500)||(input.POV[0]==31500)||(input.Y<=-500)){
			if(Input::directionYKeyState>0) Input::directionYKeyState=0;
			Input::directionYKeyState--;
		}
		else{
			Input::directionYKeyState = 0;
		}
	}
	else{//キーボード
		char tmp[256];
		GetHitKeyStateAll(tmp);


		if (tmp[Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_SlowMove]] == 1) Input::keyBoardState_Explode[KeyCodeExplode_SlowMove]++;
		else if (Input::keyBoardState_Explode[KeyCodeExplode_SlowMove] > 0) Input::keyBoardState_Explode[KeyCodeExplode_SlowMove] = -1;
		else Input::keyBoardState_Explode[KeyCodeExplode_SlowMove] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_ScatterBomb]] == 1) Input::keyBoardState_Explode[KeyCodeExplode_ScatterBomb]++;
		else if (Input::keyBoardState_Explode[KeyCodeExplode_ScatterBomb] > 0) Input::keyBoardState_Explode[KeyCodeExplode_ScatterBomb] = -1;
		else Input::keyBoardState_Explode[KeyCodeExplode_ScatterBomb] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_Ignition]] == 1) Input::keyBoardState_Explode[KeyCodeExplode_Ignition]++;
		else if (Input::keyBoardState_Explode[KeyCodeExplode_Ignition] > 0) Input::keyBoardState_Explode[KeyCodeExplode_Ignition] = -1;
		else Input::keyBoardState_Explode[KeyCodeExplode_Ignition] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Explode[KeyCodeExplode_ReleasePower]] == 1) Input::keyBoardState_Explode[KeyCodeExplode_ReleasePower]++;
		else if (Input::keyBoardState_Explode[KeyCodeExplode_ReleasePower] > 0) Input::keyBoardState_Explode[KeyCodeExplode_ReleasePower] = -1;
		else Input::keyBoardState_Explode[KeyCodeExplode_ReleasePower] = 0;


		if (tmp[Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_SlowMove]] == 1) Input::keyBoardState_Stand[KeyCodeStand_SlowMove]++;
		else if (Input::keyBoardState_Stand[KeyCodeStand_SlowMove] > 0) Input::keyBoardState_Stand[KeyCodeStand_SlowMove] = -1;
		else Input::keyBoardState_Stand[KeyCodeStand_SlowMove] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_ShotBullet]] == 1) Input::keyBoardState_Stand[KeyCodeStand_ShotBullet]++;
		else if (Input::keyBoardState_Stand[KeyCodeStand_ShotBullet] > 0) Input::keyBoardState_Stand[KeyCodeStand_ShotBullet] = -1;
		else Input::keyBoardState_Stand[KeyCodeStand_ShotBullet] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_StandHold]] == 1) Input::keyBoardState_Stand[KeyCodeStand_StandHold]++;
		else if (Input::keyBoardState_Stand[KeyCodeStand_StandHold] > 0) Input::keyBoardState_Stand[KeyCodeStand_StandHold] = -1;
		else Input::keyBoardState_Stand[KeyCodeStand_StandHold] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Stand[KeyCodeStand_StandFlex]] == 1) Input::keyBoardState_Stand[KeyCodeStand_StandFlex]++;
		else if (Input::keyBoardState_Stand[KeyCodeStand_StandFlex] > 0)	Input::keyBoardState_Stand[KeyCodeStand_StandFlex] = -1;
		else Input::keyBoardState_Stand[KeyCodeStand_StandFlex] = 0;


		if (tmp[Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_SlowMove]] == 1) Input::keyBoardState_Absorb[KeyCodeAbsorb_SlowMove]++;
		else if (Input::keyBoardState_Absorb[KeyCodeAbsorb_SlowMove] > 0) Input::keyBoardState_Absorb[KeyCodeAbsorb_SlowMove] = -1;
		else Input::keyBoardState_Absorb[KeyCodeAbsorb_SlowMove] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Absorb]] == 1) Input::keyBoardState_Absorb[KeyCodeAbsorb_Absorb]++;
		else if (Input::keyBoardState_Absorb[KeyCodeAbsorb_Absorb] > 0) Input::keyBoardState_Absorb[KeyCodeAbsorb_Absorb] = -1;
		else Input::keyBoardState_Absorb[KeyCodeAbsorb_Absorb] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Release]] == 1) Input::keyBoardState_Absorb[KeyCodeAbsorb_Release]++;
		else if (Input::keyBoardState_Absorb[KeyCodeAbsorb_Release] > 0) Input::keyBoardState_Absorb[KeyCodeAbsorb_Release] = -1;
		else Input::keyBoardState_Absorb[KeyCodeAbsorb_Release] = 0;

		if (tmp[Input::registedKeyCode.keyBoard_Absorb[KeyCodeAbsorb_Collapsar]] == 1) Input::keyBoardState_Absorb[KeyCodeAbsorb_Collapsar]++;
		else if (Input::keyBoardState_Absorb[KeyCodeAbsorb_Collapsar] > 0)	Input::keyBoardState_Absorb[KeyCodeAbsorb_Collapsar] = -1;
		else Input::keyBoardState_Absorb[KeyCodeAbsorb_Collapsar] = 0;

		
		if (tmp[Input::registedKeyCode.keyBoardOK] == 1){
			Input::keyBoardState_OK++;
		}
		else{
			if (Input::keyBoardState_OK > 0) Input::keyBoardState_OK = -1;
			else Input::keyBoardState_OK = 0;
		}

		if (tmp[Input::registedKeyCode.keyBoardCancel] == 1){
			Input::keyBoardState_Cancel++;
		}
		else{
			if (Input::keyBoardState_Cancel > 0) Input::keyBoardState_Cancel = -1;
			else Input::keyBoardState_Cancel = 0;
		}

		if (tmp[Input::registedKeyCode.keyBoardPause] == 1){
			Input::keyBoardState_Pause++;
		}
		else{
			if (Input::keyBoardState_Pause > 0) Input::keyBoardState_Pause = -1;
			else Input::keyBoardState_Pause = 0;
		}


		if((tmp[KEY_INPUT_RIGHT]!=1)&&(tmp[KEY_INPUT_LEFT]!=1)) Input::directionXKeyState=0;
		else{
			if(tmp[KEY_INPUT_RIGHT]==1){
				if(Input::directionXKeyState<0)Input::directionXKeyState=0;
				Input::directionXKeyState++;
			}
			if(tmp[KEY_INPUT_LEFT]==1){
				if(Input::directionXKeyState>0)Input::directionXKeyState=0;
				Input::directionXKeyState--;
			}
		}

		if((tmp[KEY_INPUT_UP]!=1)&&(tmp[KEY_INPUT_DOWN]!=1)) Input::directionYKeyState=0;
		else{
			if(tmp[KEY_INPUT_UP]==1){
				if(Input::directionYKeyState>0) Input::directionYKeyState=0;
				Input::directionYKeyState--;
			}
			if(tmp[KEY_INPUT_DOWN]==1){
				if(Input::directionYKeyState<0) Input::directionYKeyState=0;
				Input::directionYKeyState++;
			}
		}
	}
}

int Input::getGridXDown(){
	int i;
	if(Input::directionXKeyState>0) i=1;
	else if(Input::directionXKeyState<0) i=-1;
	else i=0;
	return i;
}

int Input::getGridXDownOnce(){
	int i=0;
	if(Input::directionXKeyState==1)i=1;
	else if(Input::directionXKeyState==-1)i=-1;

	return i;
}

int Input::getGridYDown(){
	int i;
	if(Input::directionYKeyState>0) i=1;
	else if(Input::directionYKeyState<0) i=-1;
	else i=0;
	return i;
}

int Input::getGridYDownOnce(){
	int i=0;
	if(Input::directionYKeyState==1)i=1;
	else if(Input::directionYKeyState==-1)i=-1;

	return i;
}

int Input::getkeyCodeDown_Explode(KeyCode_Explode keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Explode[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::joyPadState_OK > 0) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::joyPadState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::joyPadState_Pause > 0) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Explode[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::keyBoardState_OK > 0) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::keyBoardState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::keyBoardState_Pause > 0) return 1; }
	}
	return 0;
}

int Input::getkeyCodeDownOnce_Explode(KeyCode_Explode keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Explode[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::joyPadState_OK == 1) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::joyPadState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::joyPadState_Pause == 1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Explode[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::keyBoardState_OK == 1) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::keyBoardState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::keyBoardState_Pause == 1) return 1; }
	}
	return 0;
}

int Input::getkeyCodeUpOnce_Explode(KeyCode_Explode keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Explode[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::joyPadState_OK == -1) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::joyPadState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::joyPadState_Pause == -1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Explode[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeExplode_OK) { if (Input::keyBoardState_OK == -1) return 1; }
		else if (keyCode == KeyCodeExplode_Cancel) { if (Input::keyBoardState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeExplode_Pause) { if (Input::keyBoardState_Pause == -1) return 1; }
	}
	return 0;
}


int Input::getkeyCodeDown_Stand(KeyCode_Stand keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Stand[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::joyPadState_OK > 0) return 1; }
		else if (keyCode == KeyCodeStand_Cancel){ if (Input::joyPadState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::joyPadState_Pause > 0) return 1; }
	}
	else{
		if (keyCode < 4){ if (Input::keyBoardState_Stand[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::keyBoardState_OK > 0) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::keyBoardState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::keyBoardState_Pause > 0) return 1; }
	}
	return 0;
}

int Input::getkeyCodeDownOnce_Stand(KeyCode_Stand keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Stand[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::joyPadState_OK == 1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::joyPadState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::joyPadState_Pause == 1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Stand[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::keyBoardState_OK == 1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::keyBoardState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeStand_Pause){ if (Input::keyBoardState_Pause == 1) return 1; }
	}
	return 0;
}

int Input::getkeyCodeUpOnce_Stand(KeyCode_Stand keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4) { if (Input::joyPadState_Stand[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::joyPadState_OK == -1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::joyPadState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::joyPadState_Pause == -1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Stand[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::keyBoardState_OK == -1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::keyBoardState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::keyBoardState_Pause == -1) return 1; }
	}
	return 0;
}


int Input::getkeyCodeDown_Absorb(KeyCode_Absorb keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4){ if (Input::joyPadState_Absorb[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeAbsorb_OK) { if (Input::joyPadState_OK > 0) return 1; }
		else if (keyCode == KeyCodeAbsorb_Cancel) { if (Input::joyPadState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeAbsorb_Pause) { if (Input::joyPadState_Pause > 0) return 1; }
	}
	else{
		if (keyCode < 4){ if (Input::keyBoardState_Absorb[keyCode]>0) return 1; }
		else if (keyCode == KeyCodeAbsorb_OK){ if (Input::keyBoardState_OK > 0) return 1; }
		else if (keyCode == KeyCodeAbsorb_Cancel){ if (Input::keyBoardState_Cancel > 0) return 1; }
		else if (keyCode == KeyCodeAbsorb_Pause) { if (Input::keyBoardState_Pause > 0) return 1; }
	}
	return 0;
}

int Input::getkeyCodeDownOnce_Absorb(KeyCode_Absorb keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4){ if (Input::joyPadState_Absorb[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_OK){ if (Input::joyPadState_OK == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_Cancel){ if (Input::joyPadState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_Pause) { if (Input::joyPadState_Pause == 1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Absorb[keyCode] == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_OK) { if (Input::keyBoardState_OK == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_Cancel) { if (Input::keyBoardState_Cancel == 1) return 1; }
		else if (keyCode == KeyCodeAbsorb_Pause) { if (Input::keyBoardState_Pause == 1) return 1; }
	}
	return 0;
}

int Input::getkeyCodeUpOnce_Absorb(KeyCode_Absorb keyCode){
	if (Input::joyPadflag == true){
		if (keyCode < 4){ if (Input::joyPadState_Absorb[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeStand_OK){ if (Input::joyPadState_OK == -1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel){ if (Input::joyPadState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::joyPadState_Pause == -1) return 1; }
	}
	else{
		if (keyCode < 4) { if (Input::keyBoardState_Absorb[keyCode] == -1) return 1; }
		else if (keyCode == KeyCodeStand_OK) { if (Input::keyBoardState_OK == -1) return 1; }
		else if (keyCode == KeyCodeStand_Cancel) { if (Input::keyBoardState_Cancel == -1) return 1; }
		else if (keyCode == KeyCodeStand_Pause) { if (Input::keyBoardState_Pause == -1) return 1; }
	}
	return 0;
}


bool Input::getJoyPadFlag(){
	return Input::joyPadflag;
}

bool Input::isAnyKeyCodeDown(){
	if (Input::joyPadflag == false){//キーボード
		for (int i = 0; i < 4; i++){
			if (Input::keyBoardState_Explode[i] > 0) return true;
			if (Input::keyBoardState_Stand[i] > 0) return true;
			if (Input::keyBoardState_Absorb[i] > 0) return true;
		}
		if (Input::keyBoardState_OK > 0) return true;
		if (Input::keyBoardState_Cancel > 0) return true;
		if (Input::keyBoardState_Pause > 0) return true;
		return false;
	}
	else{
		for (int i = 0; i < 4; i++){
			if (Input::joyPadState_Explode[i] > 0) return true;
			if (Input::joyPadState_Stand[i] > 0) return true;
			if (Input::joyPadState_Absorb[i] > 0) return true;
		}
		if (Input::joyPadState_OK > 0) return true;
		if (Input::joyPadState_Cancel > 0) return true;
		if (Input::joyPadState_Pause > 0) return true;
		return false;
	}
}

unsigned char Input::getRegistedKeyCodeKeyBoard_Explode(KeyCode_Explode keyCode){
	if (keyCode == KeyCodeExplode_OK) return Input::registedKeyCode.keyBoardOK;
	else if (keyCode == KeyCodeExplode_Cancel) return Input::registedKeyCode.keyBoardCancel;
	else if (keyCode == KeyCodeExplode_Pause) return Input::registedKeyCode.keyBoardPause;
	else return Input::registedKeyCode.keyBoard_Explode[keyCode];
}

unsigned int Input::getRegistedKeyCodeJoyPad_Explode(KeyCode_Explode keyCode){
	if (keyCode == KeyCodeExplode_OK) return Input::registedKeyCode.joyPadOK;
	else if (keyCode == KeyCodeExplode_Cancel) return Input::registedKeyCode.joyPadCancel;
	else if (keyCode == KeyCodeExplode_Pause) return Input::registedKeyCode.joyPadPause;
	else return Input::registedKeyCode.joyPad_Explode[keyCode];
}

void Input::setRegistedKeyCodeKeyBoard_Explode(KeyCode_Explode keyCode, unsigned char registKeyCode){
	if (keyCode == KeyCodeExplode_OK) Input::registedKeyCode.keyBoardOK = registKeyCode;
	else if (keyCode == KeyCodeExplode_Cancel) Input::registedKeyCode.keyBoardCancel = registKeyCode;
	else if (keyCode == KeyCodeExplode_Pause) Input::registedKeyCode.keyBoardPause = registKeyCode;
	else Input::registedKeyCode.keyBoard_Explode[keyCode] = registKeyCode;
}

void Input::setRegistedKeyCodeJoyPad_Explode(KeyCode_Explode keyCode, unsigned int registKeyCode){
	if (keyCode == KeyCodeExplode_OK) Input::registedKeyCode.joyPadOK = registKeyCode;
	else if (keyCode == KeyCodeExplode_Cancel) Input::registedKeyCode.joyPadCancel = registKeyCode;
	else if (keyCode == KeyCodeExplode_Pause) Input::registedKeyCode.joyPadPause = registKeyCode;
	else Input::registedKeyCode.joyPad_Explode[keyCode] = registKeyCode;
}


unsigned char Input::getRegistedKeyCodeKeyBoard_Stand(KeyCode_Stand keyCode){
	if (keyCode == KeyCodeStand_OK) return Input::registedKeyCode.keyBoardOK;
	else if (keyCode == KeyCodeStand_Cancel) return Input::registedKeyCode.keyBoardCancel;
	else if (keyCode == KeyCodeStand_Pause) return Input::registedKeyCode.keyBoardPause;
	else return Input::registedKeyCode.keyBoard_Stand[keyCode];
}

unsigned int Input::getRegistedKeyCodeJoyPad_Stand(KeyCode_Stand keyCode){
	if (keyCode == KeyCodeStand_OK) return Input::registedKeyCode.joyPadOK;
	else if (keyCode == KeyCodeStand_Cancel) return Input::registedKeyCode.joyPadCancel;
	else if (keyCode == KeyCodeStand_Pause) return Input::registedKeyCode.joyPadPause;
	else return Input::registedKeyCode.joyPad_Stand[keyCode];
}

void Input::setRegistedKeyCodeKeyBoard_Stand(KeyCode_Stand keyCode, unsigned char registKeyCode){
	if (keyCode == KeyCodeStand_OK) Input::registedKeyCode.keyBoardOK = registKeyCode;
	else if (keyCode == KeyCodeStand_Cancel) Input::registedKeyCode.keyBoardCancel = registKeyCode;
	else if (keyCode == KeyCodeStand_Pause) Input::registedKeyCode.keyBoardPause = registKeyCode;
	else Input::registedKeyCode.keyBoard_Stand[keyCode] = registKeyCode;
}

void Input::setRegistedKeyCodeJoyPad_Stand(KeyCode_Stand keyCode, unsigned int registKeyCode){
	if (keyCode == KeyCodeStand_OK) Input::registedKeyCode.keyBoardOK = registKeyCode;
	else if (keyCode == KeyCodeStand_Cancel) Input::registedKeyCode.keyBoardCancel = registKeyCode;
	else if (keyCode == KeyCodeStand_Pause) Input::registedKeyCode.keyBoardPause = registKeyCode;
	else Input::registedKeyCode.joyPad_Stand[keyCode] = registKeyCode;
}


unsigned char Input::getRegistedKeyCodeKeyBoard_Absorb(KeyCode_Absorb keyCode){
	if (keyCode == KeyCodeAbsorb_OK) return Input::registedKeyCode.keyBoardOK;
	else if (keyCode == KeyCodeAbsorb_Cancel) return Input::registedKeyCode.keyBoardCancel;
	else if (keyCode == KeyCodeAbsorb_Pause) return Input::registedKeyCode.keyBoardPause;
	else return Input::registedKeyCode.keyBoard_Absorb[keyCode];
}

unsigned int Input::getRegistedKeyCodeJoyPad_Absorb(KeyCode_Absorb keyCode){
	if (keyCode == KeyCodeAbsorb_OK) return Input::registedKeyCode.joyPadOK;
	else if (keyCode == KeyCodeAbsorb_Cancel) return Input::registedKeyCode.joyPadCancel;
	else if (keyCode == KeyCodeAbsorb_Pause) return Input::registedKeyCode.joyPadPause;
	else return Input::registedKeyCode.joyPad_Absorb[keyCode];
}

void Input::setRegistedKeyCodeKeyBoard_Absorb(KeyCode_Absorb keyCode, unsigned char registKeyCode){
	if (keyCode == KeyCodeAbsorb_OK) Input::registedKeyCode.keyBoardOK = registKeyCode;
	else if (keyCode == KeyCodeAbsorb_Cancel) Input::registedKeyCode.keyBoardCancel = registKeyCode;
	else if (keyCode == KeyCodeAbsorb_Pause) Input::registedKeyCode.keyBoardPause = registKeyCode;
	else Input::registedKeyCode.keyBoard_Absorb[keyCode] = registKeyCode;
}

void Input::setRegistedKeyCodeJoyPad_Absorb(KeyCode_Absorb keyCode, unsigned int registKeyCode){
	if (keyCode == KeyCodeAbsorb_OK) Input::registedKeyCode.keyBoardOK = registKeyCode;
	else if (keyCode == KeyCodeAbsorb_Cancel) Input::registedKeyCode.keyBoardCancel = registKeyCode;
	else if (keyCode == KeyCodeAbsorb_Pause) Input::registedKeyCode.keyBoardPause = registKeyCode;
	else Input::registedKeyCode.joyPad_Absorb[keyCode] = registKeyCode;
}