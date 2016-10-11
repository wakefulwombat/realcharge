#include "sceneEnding.h"
#include "music.h"
#include "picture.h"
#include "DxLib.h"
#include "sound.h"
#include "input.h"

SceneEnding::SceneEnding(ISetNextScene* changer){
	this->isetNextScene = changer;
	this->count=0;
}

void SceneEnding::initialize(){
	this->loadCSV();
	Music::playMusic(Music_Ending);
}

void SceneEnding::update(){
	this->count++;

	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_OK) == 1){
		Sound::playSound(Sound_Decide);
	}

	if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Cancel) == 1){
		Picture::deletePicture();
		Picture::loadOpeningPicture();
		Music::playMusic(Music_Opening);
		this->isetNextScene->isetNextScene(Scene_Opening);
	}

	if (this->count > 3550){
		Picture::deletePicture();
		Picture::loadOpeningPicture();
		Music::playMusic(Music_Opening);
		this->isetNextScene->isetNextScene(Scene_Opening);
	}
}

void SceneEnding::draw(){
	for (vector<EndText>::iterator it = this->textList.begin(); it != this->textList.end(); ++it){
		if (this->count < it->app_time) continue;
		if (this->count > it->dis_time + 60) continue;

		if (this->count < it->app_time + 60){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255.0*(this->count-it->app_time)/60);
			DrawString(it->pos.x + 80.0 - 80.0*cos(M_PI*(it->app_time + 60 - this->count) / 120), it->pos.y, it->text.c_str(), GetColor(255, 255, 255));
		}
		else if (this->count < it->dis_time){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255);
			DrawString(it->pos.x, it->pos.y, it->text.c_str(), GetColor(255, 255, 255));
		}
		else if (this->count < it->dis_time + 60){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255.0*(it->dis_time + 60 - this->count) / 60);
			DrawString(it->pos.x + 80.0 - 80.0*sin(M_PI*(it->dis_time + 60 - this->count) / 120), it->pos.y, it->text.c_str(), GetColor(255, 255, 255));
		}
	}
}

void SceneEnding::finalize(){

}

void SceneEnding::loadCSV(){
	int fp = FileRead_open("material\\ending\\endroll.csv");
	while(FileRead_getc(fp)!='\n');
	
	char input[256],inputChar;
	int inputIndex=0;
	int index_x=0,index_y=0;

	EndText temp;

	while(inputChar=FileRead_getc(fp),inputChar!=EOF){
		if(inputChar==','){
			input[inputIndex]='\0';

			switch (index_x){
			case 0:
				temp.app_time = atoi(input);
				break;

			case 1:
				temp.dis_time = atoi(input);
				break;
			
			case 2:
				temp.pos.x = atof(input);
				break;

			case 3:
				temp.pos.y = atof(input);
				break;

			case 4:
				temp.text = input;
				break;
			}

			inputIndex=0;
			index_x++;
		}
		else if(inputChar=='\n'){
			input[inputIndex]='\0';

			temp.text = input;
			this->textList.push_back(temp);

			inputIndex=0;
			index_x=0;
			index_y++;
		}
		else{
			input[inputIndex]=inputChar;

			inputIndex++;
		}
	}

	FileRead_close(fp);
}