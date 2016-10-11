#include "sceneMusicRoom.h"
#include "picture.h"
#include "input.h"
#include "DxLib.h"
#include "music.h"
#include "sound.h"

SceneMusicRoom::SceneMusicRoom(ISetNextScene* changer){
	this->isetNextScene = changer;
	this->selectNum=0;
	this->count=0;

	this->loadMusicComment();

	this->backEffectManage = new BackEffectManage();
	this->selifBoxManage = new SelifBoxManage();
}

void SceneMusicRoom::initialize(){

}

void SceneMusicRoom::update(){
	if (this->selectNum < 9){
		if (Input::getGridYDownOnce() == 1){
			this->selectNum = (this->selectNum + 1) % 9;
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectNum = (this->selectNum + 8) % 9;
		}
		if (Input::getGridXDownOnce() != 0){
			if (this->selectNum != 8) this->selectNum += 9;
		}
	}
	else{
		if (Input::getGridYDownOnce() == 1){
			this->selectNum = (this->selectNum - 8) % 8 + 9;
		}
		if (Input::getGridYDownOnce() == -1){
			this->selectNum = (this->selectNum - 2) % 8 + 9;
		}
		if (Input::getGridXDownOnce() != 0){
			this->selectNum -= 9;
		}
	}

	if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK)==1){
		Music::playMusic((MusicList)this->selectNum);
		this->selifBoxManage->isetRemoveSelifBoxAll();
		this->selifBoxManage->isetSelifBox(Point(400, 500), this->musicComment[this->selectNum].theme + "nn" + this->musicComment[this->selectNum].comment, Size(40, 7));
	}
	if(Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel)==1){
		Sound::playSound(Sound_Cancel);
		this->isetNextScene->isetNextScene(Scene_Opening);
	}

	this->count++;
	if(this->count==10){
		this->count=0;
		this->backEffectManage->isetBackEffect(GetRand(5),Point(1.0*GetRand(WINDOW_WIDTH),-100.0));
	}
	this->backEffectManage->update();
	this->selifBoxManage->update();
}

void SceneMusicRoom::draw(){
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	DrawGraph(0,0,Picture::getBack(1),false);
	DrawGraph(50,30,Picture::getSelectText(SEL_MUSICSELECT),true);

	for(int i=0;i<17;i++){
		if(i==this->selectNum)SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
		else SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA,50);

		if (i < 9){
			DrawString(200, 140 + 30 * i, this->musicComment[i].theme.c_str(), GetColor(255, 255, 255));
		}
		else{
			DrawString(450, 140 + 30 * (i - 9), this->musicComment[i].theme.c_str(), GetColor(255, 255, 255));
		}
	}

	this->backEffectManage->draw();
	this->selifBoxManage->draw();
}

void SceneMusicRoom::finalize(){
	delete this->backEffectManage;
	delete this->selifBoxManage;
}

void SceneMusicRoom::loadMusicComment(){
	char filepath[64];

	sprintf_s(filepath, "material\\music_room\\comment.csv");
	int fp = FileRead_open(filepath);
	while (FileRead_getc(fp) != '\n');

	char input[512];
	int index_x = 0,index_y=0;

	for (int i = 0; i<512; i++){
		input[i] = FileRead_getc(fp);
		if (input[i] == ','){
			input[i] = '\0';

			switch (index_x){
			case 1:this->musicComment[index_y].theme = string(input); break;
			case 2:this->musicComment[index_y].comment = string(input); break;
			}

			i = -1;
			index_x++;
			continue;

		}
		if (input[i] == '\n'){
			input[i] = '\0';

			this->musicComment[index_y].comment = string(input);

			i = -1;
			index_x = 0;
			index_y++;
			continue;
		}
		if (input[i] == '/'){
			i = -1;
			index_x = 0;
			while (FileRead_getc(fp) != '\n');
			continue;
		}
		if (input[i] == EOF) break;
	}
	FileRead_close(fp);
}