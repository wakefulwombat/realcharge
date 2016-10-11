#include "sceneGameFilm.h"
#include "DxLib.h"
#include "music.h"
#include <stdio.h>
#include <vector>
#include "picture.h"
#include "input.h"
#include "sound.h"

SceneGameFilm::SceneGameFilm(ISetNextScene* changer, ISetDifficulty* isetDifficulty, int difficulty, int mode, int stage, bool doesStartFromBoss, ISetGameClearData* isetGameClearData){
	this->isetNextScene = changer;
	this->difficulty = difficulty;
	this->stage = stage;
	this->isetDifficulty = isetDifficulty;
	this->isetGameClearData = isetGameClearData;
	this->isPausing = false;
	this->isDied = false;
	this->isWaitingNextStage = false;
	this->selectedMode = mode;

	if (mode == 0){//explode
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->selifBoxManage = new SelifBoxManage();
		this->bombManage = new BombManage();
		this->textEffectManage = new TextEffectManage();

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->barrageManage = new BarrageManage(this->enemyBulletManage, this->player, this->enemyBulletManage);
		this->bossManage = new BossManage(this->selifBoxManage, this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, this, this->burnEffectManage, 0);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 0);
		if (doesStartFromBoss == true) this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage, stage);
		else this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage);
		this->shockWaveManage = new ShockWaveManage(this->enemyManage, this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, isetDifficulty,this ,this->backEffectManage, this->bossManage, isetGameClearData);
		this->scenePause = new ScenePause(changer, isetDifficulty, this, this->backEffectManage, this->bossManage, isetGameClearData, false);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->shockWaveManage, this->bombManage, difficulty, false);
	}
	else if (mode == 1){//stand
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->textEffectManage = new TextEffectManage();
		this->selifBoxManage = new SelifBoxManage();
		this->playerBulletManage = new PlayerBulletManagerEX();
		this->textEffectManage = new TextEffectManage();

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->barrageManage = new BarrageManage(this->enemyBulletManage, this->player, this->enemyBulletManage);
		this->bossManage = new BossManage(this->selifBoxManage, this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, this, this->burnEffectManage, 1);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 1);
		if (doesStartFromBoss == true) this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage, stage);
		else this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage);
		this->shockWaveManage = new ShockWaveManage(this->enemyManage, this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, isetDifficulty, this, this->backEffectManage, this->bossManage, isetGameClearData);
		this->scenePause = new ScenePause(changer, isetDifficulty, this, this->backEffectManage, this->bossManage, isetGameClearData, false);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->playerBulletManage, this->enemyBulletManage, difficulty, false);
	}
	else{//absorb
		this->itemManage = new ItemManage();
		this->burnEffectManage = new BurnEffectManage(1);
		this->backEffectManage = new BackEffectManage();
		this->numericalBarManage = new NumericalBarManage();
		this->textEffectManage = new TextEffectManage();
		this->selifBoxManage = new SelifBoxManage();
		this->textEffectManage = new TextEffectManage();
		this->collapsarManage = new CollapsarManage(1);

		this->player = new PlayerEX();
		this->enemyBulletManage = new EnemyBulletManageEX();
		this->barrageManage = new BarrageManage(this->enemyBulletManage, this->player, this->enemyBulletManage);
		this->bossManage = new BossManage(this->selifBoxManage, this->textEffectManage, this->enemyBulletManage, this->enemyBulletManage, this->enemyBulletManage, this->itemManage, this->player, this, this, this->burnEffectManage, 2);
		this->board = new Board(this->player, this->bossManage, this->bossManage, 2);
		if (doesStartFromBoss == true) this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage, stage);
		else this->enemyManage = new EnemyManage(this->barrageManage, this->itemManage, this->player, this->board, this->bossManage, this->bossManage, this->enemyBulletManage, this->burnEffectManage, this->backEffectManage);
		this->shockWaveManage = new ShockWaveManage(this->enemyManage, this->bossManage, this->bossManage);

		this->scenePlayerDead = new ScenePlayerDead(changer, isetDifficulty, this, this->backEffectManage, this->bossManage, isetGameClearData);
		this->scenePause = new ScenePause(changer, isetDifficulty, this, this->backEffectManage, this->bossManage, isetGameClearData, false);

		this->enemyBulletManage->initialize(this->burnEffectManage, this->shockWaveManage, this->player, this->bossManage, this->bossManage);
		this->player->initialize(this->numericalBarManage, this->itemManage, this->enemyBulletManage, this->bossManage, this->shockWaveManage, this->collapsarManage, difficulty, false);
	}
}

void SceneGameFilm::initialize(){
	if (this->selectedMode == 0){//explode
		this->player->initialize();
		this->enemyManage->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->selifBoxManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->bombManage->initialize();
		this->barrageManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}
	else if (this->selectedMode == 1){//stand
		this->player->initialize();
		this->enemyManage->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->playerBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->selifBoxManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->barrageManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}
	else{//absorb
		this->player->initialize();
		this->enemyManage->initialize();
		this->itemManage->initialize();
		this->enemyBulletManage->initialize();
		this->board->initialize();
		this->burnEffectManage->initialize();
		this->backEffectManage->initialize();
		this->numericalBarManage->initialize();
		this->selifBoxManage->initialize();
		this->shockWaveManage->initialize();
		this->textEffectManage->initialize();
		this->barrageManage->initialize();
		this->collapsarManage->initialize();
		this->scenePause->initialize();
		this->scenePlayerDead->initialize();
		this->bossManage->initialize();
	}

	Picture::deletePicture();
	Picture::loadStagePicture();
	this->loadStage();
	Music::playRoadMusic(this->stage);
}

void SceneGameFilm::update(){
	if (this->selectedMode == 0){//explode
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Explode(KeyCodeExplode_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else if (this->isWaitingNextStage == true){
			this->player->update();
			this->selifBoxManage->update();
			this->textEffectManage->update();
			this->board->update();
			this->prepareNextStage();
			this->isWaitingNextStage = false;
		}
		else{
			this->player->update();
			this->enemyManage->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->selifBoxManage->update();
			this->shockWaveManage->update();
			this->bombManage->update();
			this->barrageManage->update();
			this->bossManage->update();
			this->textEffectManage->update();

			this->hitCheckAllObject_Explode();
		}
	}
	else if (this->selectedMode == 1){//stand
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else if (this->isWaitingNextStage == true){
			this->player->update();
			this->selifBoxManage->update();
			this->textEffectManage->update();
			this->board->update();
			this->prepareNextStage();
			this->isWaitingNextStage = false;
		}
		else{
			this->player->update();
			this->playerBulletManage->update();
			this->enemyManage->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->selifBoxManage->update();
			this->shockWaveManage->update();
			this->barrageManage->update();
			this->bossManage->update();
			this->textEffectManage->update();

			this->hitCheckAllObject_Stand();
		}
	}
	else{//absorb
		if (this->isDied == false){
			if (Input::getkeyCodeDownOnce_Stand(KeyCodeStand_Pause) == 1){
				Sound::playSound(Sound_Decide);
				this->isPausing = !this->isPausing;
				this->scenePause->initialize();
			}
		}

		if (this->isDied == true){
			this->scenePlayerDead->update();
		}
		else if (this->isPausing == true){
			this->scenePause->update();
			this->backEffectManage->update();
		}
		else if (this->isWaitingNextStage == true){
			this->player->update();
			this->selifBoxManage->update();
			this->textEffectManage->update();
			this->board->update();
			this->prepareNextStage();
			this->isWaitingNextStage = false;
		}
		else{
			this->player->update();
			this->enemyManage->update();
			this->itemManage->update();
			this->enemyBulletManage->update();
			this->board->update();
			this->burnEffectManage->update();
			this->backEffectManage->update();
			this->numericalBarManage->update();
			this->selifBoxManage->update();
			this->shockWaveManage->update();
			this->barrageManage->update();
			this->bossManage->update();
			this->textEffectManage->update();
			this->collapsarManage->update();

			this->hitCheckAllObject_Absorb();
		}
	}
}

void SceneGameFilm::draw(){
	if (this->selectedMode == 0){//explode
		this->backEffectManage->draw();
		this->numericalBarManage->draw();
		this->player->draw();
		this->enemyManage->draw();
		this->bombManage->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->shockWaveManage->draw();
		this->selifBoxManage->draw();
		this->textEffectManage->draw();
		this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->backEffectManage->draw();
			this->scenePause->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->backEffectManage->draw();
			this->board->draw();
			this->scenePlayerDead->draw();
		}
	}
	else if (this->selectedMode == 1){//stand
		this->backEffectManage->draw();
		this->numericalBarManage->draw();
		this->playerBulletManage->draw();
		this->player->draw();
		this->enemyManage->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->selifBoxManage->draw();
		this->shockWaveManage->draw();
		this->textEffectManage->draw();
		this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->scenePause->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->scenePlayerDead->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
	}
	else{//absorb
		this->backEffectManage->draw();
		this->collapsarManage->draw();
		this->shockWaveManage->draw();
		this->numericalBarManage->draw();
		this->player->draw();
		this->enemyManage->draw();
		this->burnEffectManage->draw();
		this->itemManage->draw();
		this->enemyBulletManage->draw();
		this->selifBoxManage->draw();
		this->textEffectManage->draw();
		this->bossManage->draw();
		this->board->draw();

		if (this->isPausing == true){
			this->scenePause->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
		if (this->isDied == true){
			this->scenePlayerDead->draw();
			this->backEffectManage->draw();
			this->board->draw();
		}
	}
}

void SceneGameFilm::finalize(){
	if (this->selectedMode == 0){
		this->player->finalize();
		this->enemyManage->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->selifBoxManage->finalize();
		this->shockWaveManage->finalize();
		this->bombManage->finalize();
		this->barrageManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->enemyManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->selifBoxManage);
		delete(this->shockWaveManage);
		delete(this->bombManage);
		delete(this->barrageManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
	else if (this->selectedMode == 1){//stand
		this->player->finalize();
		this->enemyManage->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->selifBoxManage->finalize();
		this->shockWaveManage->finalize();
		this->barrageManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();
		this->playerBulletManage->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->enemyManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->selifBoxManage);
		delete(this->shockWaveManage);
		delete(this->barrageManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->playerBulletManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
	else{
		this->player->finalize();
		this->enemyManage->finalize();
		this->itemManage->finalize();
		this->enemyBulletManage->finalize();
		this->board->finalize();
		this->burnEffectManage->finalize();
		this->backEffectManage->finalize();
		this->numericalBarManage->finalize();
		this->selifBoxManage->finalize();
		this->shockWaveManage->finalize();
		this->barrageManage->finalize();
		this->bossManage->finalize();
		this->textEffectManage->finalize();
		this->scenePause->finalize();
		this->scenePlayerDead->finalize();

		delete(this->player);
		delete(this->board);
		delete(this->enemyBulletManage);
		delete(this->enemyManage);
		delete(this->itemManage);
		delete(this->burnEffectManage);
		delete(this->backEffectManage);
		delete(this->numericalBarManage);
		delete(this->selifBoxManage);
		delete(this->shockWaveManage);
		delete(this->barrageManage);
		delete(this->bossManage);
		delete(this->textEffectManage);
		delete(this->scenePause);
		delete(this->scenePlayerDead);
	}
}

static vector<string> splitString(const string &src,const string &delim){
	vector<string> dest;
	string::size_type start = 0;//デリミタを検索するインデクス番号
	while(true){
	    //デリミタが現れる最初のインデクスを求める
	    string::size_type end = src.find(delim, start);
	 
	    //デリミタが見つかった場合
		if(end != string::npos){
	        dest.push_back(src.substr(start, end - start));
	    }
	    //デリミタが見つからなかった場合
	    else{
	        //文末までを格納して返す
	        dest.push_back(src.substr(start, src.length() - start));
	        break;
	    }
	    //次の開始地点へ移動
	    start = end + delim.length();
	}
	return dest;
}

void SceneGameFilm::loadEnemyCSV(){
	char filepath[64];
	
	sprintf_s(filepath,"material\\enemyCSV\\%d\\e%d.csv",this->difficulty,this->stage);
	int fp = FileRead_open(filepath);
	while(FileRead_getc(fp)!='\n');
	
	char input[8];
	int index_x=0;
	StaticEnemyData staticEnemyData;

	for(int i=0;i<8;i++){
		input[i]=FileRead_getc(fp);
		if(input[i]==','){
			input[i]='\0';

			switch(index_x){
			case 0:staticEnemyData.appearTime			= atoi(input);break;
			case 1:staticEnemyData.movePattern			= atoi(input);break;
			case 2:staticEnemyData.startPosition.x		= atof(input);break;
			case 3:staticEnemyData.startPosition.y		= atof(input);break;
			case 4:staticEnemyData.stopPosition.x		= atof(input);break;
			case 5:staticEnemyData.stopPosition.y		= atof(input);break;
			case 6:staticEnemyData.kind					= atoi(input);break;
			case 7:staticEnemyData.movingTime			= atoi(input);break;
			case 8:staticEnemyData.stoppingTime			= atoi(input);break;
			case 9:staticEnemyData.move_trans_vel		= atof(input);break;
			case 10:staticEnemyData.move_trans_acc		= atof(input);break;
			case 11:staticEnemyData.move_trans_rad		= atof(input)*M_PI/180;break;
			case 12:staticEnemyData.move_rotate_vel		= atof(input)*M_PI/180;break;
			case 13:staticEnemyData.itemPattern = atoi(input); break;
			case 14:staticEnemyData.HP_MAX				= atoi(input);break;
			case 15:staticEnemyData.disappearTime_min	= atoi(input);break;
			case 16:staticEnemyData.barrageDataID[0]	= atoi(input);break;
			case 17:staticEnemyData.barrageDataID[1]	= atoi(input);break;
			case 18:staticEnemyData.barrageDataID[2]	= atoi(input);break;
			case 19:staticEnemyData.barrageStartTime[0] = atoi(input);break;
			case 20:staticEnemyData.barrageStartTime[1] = atoi(input);break;
			}

			i=-1;
			index_x++;
			continue;
			
		}
		if(input[i]=='\n'){
			input[i]='\0';
			
			staticEnemyData.barrageStartTime[2]	= atoi(input);
			
			this->enemyManage->setStaticEnemyData(staticEnemyData);

			i=-1;
			index_x=0;
			continue;
		}
		if(input[i]=='/'){
			i=-1;
			index_x=0;
			while(FileRead_getc(fp)!='\n');
			continue;
		}
		if(input[i]==EOF) break;
	}
	FileRead_close(fp);
}

void SceneGameFilm::loadBarrageCSV(){
	char filepath[64];
	sprintf_s(filepath,"material\\barrageCSV\\%d\\b%d.csv",this->difficulty,this->stage);
	int fp = FileRead_open(filepath);
	while(FileRead_getc(fp)!='\n');

	char input[8];
	int index_x=0;
	StaticBarrageData staticBarrageData;

	for(int i=0;i<8;i++){
	 	input[i]=FileRead_getc(fp);
		if(input[i]==','){
			input[i]='\0';

			switch(index_x){
			case 0:staticBarrageData.CSVID								= atoi(input);break;
			case 1:staticBarrageData.barragePattern						= atoi(input);break;
			case 2:staticBarrageData.movePattern						= atoi(input);break;
			case 3:staticBarrageData.staticBulletData.movePattern		= atoi(input);break;
			case 4:staticBarrageData.disappearTime_min					= atoi(input);break;
			case 5:staticBarrageData.staticBulletData.disappearTime_min	= atoi(input);break;
			case 6:staticBarrageData.trans_vel							= atof(input);break;
			case 7:staticBarrageData.trans_rad							= atof(input)*M_PI/180;break;
			case 8:staticBarrageData.rotate_vel							= atof(input)*M_PI/180;break;
			case 9:staticBarrageData.rotate_rad							= atoi(input)*M_PI/180;break;
			case 10:staticBarrageData.staticBulletData.trans_vel		= atof(input);break;
			case 11:staticBarrageData.staticBulletData.trans_acc		= atof(input);break;
			case 12:staticBarrageData.staticBulletData.trans_rad		= atof(input)*M_PI/180;break;
			case 13:staticBarrageData.staticBulletData.rotate_vel		= atof(input)*M_PI/180;break;
			case 14:staticBarrageData.staticBulletData.rotate_rad		= atof(input)*M_PI/180;break;
			case 15:staticBarrageData.staticBulletData.kind				= (BulletKind)atoi(input);break;
			case 16:staticBarrageData.staticBulletData.color			= (BulletColor)atoi(input);break;
			case 17:staticBarrageData.smallGroupBulletNum				= atoi(input);break;
			case 18:staticBarrageData.smallGroupWaitingTime				= atoi(input);break;
			case 19:staticBarrageData.largeGroupBulletNum				= atoi(input);break;
			case 20:staticBarrageData.largeGroupWaitingTime				= atoi(input);break;
			case 21:staticBarrageData.totalGroupNum						= atoi(input);break;
			case 22:staticBarrageData.param1							= atof(input);break;
			case 23:staticBarrageData.param2							= atof(input);break;
			case 24:staticBarrageData.param3							= atof(input);break;
			case 25:staticBarrageData.staticBulletData.param1			= atof(input);break;
			case 26:staticBarrageData.staticBulletData.param2			= atof(input);break;
			}

			i=-1;
			index_x++;
			continue;
		}
		if(input[i]=='\n'){
			input[i]='\0';

			staticBarrageData.staticBulletData.param3 = atof(input);
			this->barrageManage->setStaticBarrageData(staticBarrageData);

			i=-1;
			index_x=0;
			continue;
		}
		if(input[i]=='/'){
			i=-1;
			index_x=0;
			while(FileRead_getc(fp)!='\n');
			continue;
		}
		if(input[i]==EOF)break;
	}
	FileRead_close(fp);
}

void SceneGameFilm::loadBossEventCSV(bool isStartEvent){
	char filepath[64];
	if(isStartEvent==true) sprintf_s(filepath, "material\\boss_talk\\s%d.csv", this->stage);
	else sprintf_s(filepath, "material\\boss_talk\\e%d.csv", this->stage);
	int fp = FileRead_open(filepath);
	while (FileRead_getc(fp) != '\n');

	char input[512];
	int index_x = 0;

	StaticBossEventData dat;

	for (int i = 0; i < 512; i++){
		input[i] = FileRead_getc(fp);
		if (input[i] == ','){
			input[i] = '\0';

			switch (index_x){
			case 0://event_type(talk:0 move:1 music:2)
				dat.eventType = (BossEventType)atoi(input);
				break;
			case 1://who(player:-1, boss:0~)
				dat.bossID = atoi(input);
				if (dat.bossID == -1) dat.isBossEvent = false;
				else dat.isBossEvent = true;
				break;
			case 2://selif
				dat.selif = string(input);
				break;
			case 3://size_x(movingTime)
				dat.boxSize.width = atoi(input);
				break;
			case 4://size_y
				dat.boxSize.height = atoi(input);
				break;
			case 5://diff_x(moveTo_x)
				dat.boxDiff.x = atof(input);
				break;
			case 6://diff_y(moveTo_y)
				dat.boxDiff.y = atof(input);
				break;
			}

			i = -1;
			index_x++;
			continue;
		}
		if (input[i] == '\n'){
			input[i] = '\0';

			dat.boxDiff.y = atof(input);
			this->bossManage->setStaticBossEventData(dat,isStartEvent);

			i = -1;
			index_x = 0;
			continue;
		}
		if (input[i] == '/'){
			i = -1;
			index_x = 0;
			while (FileRead_getc(fp) != '\n');
			continue;
		}
		if (input[i] == EOF)break;
	}
	FileRead_close(fp);
}

void SceneGameFilm::loadStage(){
	ClearDrawScreen();
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL,255);
	LoadGraphScreen(500,500,"material\\select\\NOW LOADING.png",true);
	ScreenFlip();

	this->enemyManage->clearEnemyDataList();
	this->barrageManage->clearBarrageDataList();
	this->bossManage->clearAll();

	this->loadBarrageCSV();
	this->loadEnemyCSV();
	this->loadBossEventCSV(true);
	this->loadBossEventCSV(false);
}

void SceneGameFilm::prepareNextStage(){
	this->stage++;
	this->loadStage();
	this->isPausing = false;
	this->isDied = false;
	this->isWaitingNextStage = false;
	Music::playRoadMusic(this->stage);
	this->isetDifficulty->isetRetryFromBossBattle(false);
	this->bossManage->initialize();
	this->enemyManage->clearBossStartFlag();
	this->enemyManage->initialize();
}

bool SceneGameFilm::isHitPointSquare(Point p_point,Point sq_center,Size sq_size){
	if(p_point.x > sq_center.x-sq_size.width/2){
		if(p_point.x < sq_center.x+sq_size.width/2){
			if(p_point.y > sq_center.y-sq_size.height/2){
				if(p_point.y < sq_center.y+sq_size.height/2){
					return true;
				}
			}
		}
	}
	return false;
}

bool SceneGameFilm::isHitPointCircle(Point p_point,Point ci_center,double r){;
	return ((p_point.x-ci_center.x)*(p_point.x-ci_center.x)+(p_point.y-ci_center.y)*(p_point.y-ci_center.y) < r*r);
}

bool SceneGameFilm::isHitSquareSquare(Point center1,Size size1,Point center2,Size size2){
	if(center1.x+size1.width/2 > center2.x-size2.width/2){
		if(center1.x-size1.width/2 < center2.x+size2.width/2){
			if(center1.y+size1.height/2 > center2.y-size2.height/2){
				if(center1.y-size1.height/2 < center2.y+size2.height/2){
					return true;
				}
			}
		}
	}
	return false;
}

bool SceneGameFilm::isHitCircleCircle(Point center1,double r1,Point center2,double r2){
	return ((center1.x-center2.x)*(center1.x-center2.x)+(center1.y-center2.y)*(center1.y-center2.y) < (r1+r2)*(r1+r2));
}

void SceneGameFilm::hitCheckAllObject_Explode(){
	//プレイヤーと敵
	for (int i = 0; i<this->enemyManage->getEnemyVectorSizeMax(); i++){
		if (this->isHitPointSquare(this->player->getPosition(), this->enemyManage->getEnemyPosition(i)->igetPosition(), this->enemyManage->getEnemySize(i)) == true){
			if (this->player->getCharactorStatus() == ChStatus_Normal) {
				this->player->die();
				Sound::playSound(Sound_playerDead);
			}
			if (this->player->igetPlayerLife() < 0) this->isDied = true;
		}
	}

	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(2);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(6);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->bombManage->isetBomb(this->itemManage->getPosition(i), 0.0, false);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					for (int j = 0; j < 4; j++){
						this->bombManage->isetBomb(this->itemManage->getPosition(i) + Point(60 * sin(M_PI * 2 * j / 4), 60 * cos(M_PI * 2 * j / 4)), 0.0, false);
					}
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					this->board->addScore(100);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->board->addScore(400);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//弾と爆風
	for (int bul = 0; bul < this->enemyBulletManage->getBulletVectorSizeMax(); bul++){
		for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
			if (this->enemyBulletManage->getBulletValid(bul) == false)continue;
			if (this->burnEffectManage->getBurnEffectCount(wind) < 7) continue;
			if (this->burnEffectManage->getBurnEffectCount(wind) > 40) continue;

			if (this->isHitPointCircle(this->enemyBulletManage->getBulletPosition(bul), this->burnEffectManage->getBurnEffectPosition(wind), 0.4*this->enemyBulletManage->getBulletSize(bul).width + 0.3*this->burnEffectManage->getBurnEffectExpand(wind)*this->burnEffectManage->getBurnEffectSize(wind).width) == true){
				this->enemyBulletManage->setBulletInvalid(bul);
				//this->board->addScore(10);
				if (this->burnEffectManage->getBurnEffectExpand(wind) > 0.3){
					this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind) / 1.3, this->enemyBulletManage->getBulletPosition(bul), true);
				}
				else{
					this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), this->burnEffectManage->getBurnEffectExpand(wind), this->enemyBulletManage->getBulletPosition(bul), true);
				}
			}
		}
	}

	//敵と爆風
	if ((this->player->getCharactorStatus() == ChStatus_Normal) || (this->player->getCharactorStatus() == ChStatus_Invincible)){
		for (int enemy = 0; enemy < this->enemyManage->getEnemyVectorSizeMax(); enemy++){
			for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
				if (this->isHitPointCircle(this->enemyManage->getEnemyPosition(enemy)->igetPosition(), this->burnEffectManage->getBurnEffectPosition(wind), 0.5*this->enemyManage->getEnemySize(enemy).width + 0.4*this->burnEffectManage->getBurnEffectSize(wind).width*this->burnEffectManage->getBurnEffectExpand(wind)) == true){
					this->enemyManage->damaged(enemy, 0.1, true, this->burnEffectManage->getBurnEffectExpand(wind));
					this->board->addScore(10);
				}
			}
		}
	}

	//ボムと爆風
	for (int bomb = 0; bomb < this->bombManage->getBombVectorSizeMax(); bomb++){
		for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
			if (this->bombManage->getValid(bomb) == false)continue;

			if (this->isHitPointCircle(this->bombManage->getPosition(bomb), this->burnEffectManage->getBurnEffectPosition(wind), 0.3*this->burnEffectManage->getBurnEffectSize(wind).width*this->burnEffectManage->getBurnEffectExpand(wind))){
				this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), 1.2, this->bombManage->getPosition(bomb), false);
				this->bombManage->setInvalid(bomb);
			}
		}
	}

	//ショックと敵
	for (int e = 0; e < this->enemyManage->getEnemyVectorSizeMax(); e++){
		for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
			if (this->enemyManage->getValidate(e) == false) break;
			if (this->shockWaveManage->getShockWaveValid(s) == false) continue;

			if (this->isHitPointSquare(this->shockWaveManage->getShockWavePosition(s), this->enemyManage->getEnemyPosition(e)->igetPosition(), this->shockWaveManage->getShockWaveSize(s)) == true){
				this->enemyManage->damaged(e, this->shockWaveManage->getShockWaveAttackPower(s), false, 0.5);

				if (this->shockWaveManage->getShockWaveKind(s) == 0){
					this->shockWaveManage->setShockWaveInvalid(s);
				}

				this->board->addScore(10);
			}
		}
	}

	//ショックと弾
	for (int b = 0; b < this->enemyBulletManage->getBulletVectorSizeMax(); b++){
		for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
			if (this->enemyBulletManage->getBulletValid(b) == false) break;
			if (this->shockWaveManage->getShockWaveValid(s) == false) continue;

			if (this->isHitPointSquare(this->shockWaveManage->getShockWavePosition(s), this->enemyBulletManage->getBulletPosition(b), this->shockWaveManage->getShockWaveSize(s)) == true){
				this->enemyBulletManage->setBulletInvalid(b);
				this->board->addScore(10);

				this->burnEffectManage->isetBurnEffect((BurnEffectColor)GetRand(5), 0.3, this->enemyBulletManage->getBulletPosition(b), false);
				if (this->shockWaveManage->getShockWaveKind(s) == 0){
					this->shockWaveManage->setShockWaveInvalid(s);
				}
			}
		}
	}

	//プレイヤーと弾
	if ((this->player->getCharactorStatus() == ChStatus_Normal) || (this->player->getCharactorStatus() == ChStatus_Invincible)){
		if (this->player->isIgnitionReceipting() == true){
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.8*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;
					this->enemyBulletManage->setBulletInvalid(i);

					Sound::playSound(Sound_ignitionGo);
					this->burnEffectManage->isetBurnEffect(Burn_Red, 1.0, this->enemyBulletManage->getBulletPosition(i), false);
					this->player->setIgnitionSuccess();
				}
			}
		}
		else{
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;
					this->enemyBulletManage->setBulletInvalid(i);

					if (this->player->getCharactorStatus() == ChStatus_Normal){
						this->player->die();
						if (this->player->igetPlayerLife() < 0) this->isDied = true;
						Sound::playSound(Sound_playerDead);
					}
				}
			}
		}
	}

	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスと爆風
	for (int wind = 0; wind < this->burnEffectManage->getBurnEffectVectorSizeMax(); wind++){
		for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
			if (this->burnEffectManage->getBurnEffectExpand(wind) < 0.2) continue;
			if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->burnEffectManage->getBurnEffectPosition(wind), 0.5*this->burnEffectManage->getBurnEffectExpand(wind)*this->burnEffectManage->getBurnEffectSize(wind).width + this->bossManage->igetBoss(boss)->getSize().width)){
				this->bossManage->damaged(boss, 0.1);
				this->board->addScore(10);
			}
		}
	}

	//ボスとショック
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int s = 0; s < this->shockWaveManage->getShockWaveVectorSize(); s++){
			if (this->isHitSquareSquare(this->shockWaveManage->getShockWavePosition(s), this->shockWaveManage->getShockWaveSize(s), this->bossManage->igetBoss(boss)->getPosition(), this->bossManage->igetBoss(boss)->getSize()) == true){
				this->bossManage->damaged(boss, this->shockWaveManage->getShockWaveAttackPower(s));

				if (this->shockWaveManage->getShockWaveKind(s) == 0){
					this->shockWaveManage->setShockWaveInvalid(s);
				}

				this->board->addScore(10);
			}
		}
	}
}

void SceneGameFilm::hitCheckAllObject_Stand(){
	//プレイヤーと敵
	for (int i = 0; i<this->enemyManage->getEnemyVectorSizeMax(); i++){
		if (this->isHitPointSquare(this->player->getPosition(), this->enemyManage->getEnemyPosition(i)->igetPosition(), this->enemyManage->getEnemySize(i)) == true){
			if (this->player->getCharactorStatus() == ChStatus_Normal) {
				this->player->die();
				Sound::playSound(Sound_playerDead);
			}
			if (this->player->igetPlayerLife() < 0) this->isDied = true;
		}
	}

	//プレイヤーと弾
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
			if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
				if (this->enemyBulletManage->getBulletValid(i) == false) continue;

				this->player->die();
				if (this->player->igetPlayerLife() < 0) this->isDied = true;
				this->enemyBulletManage->setBulletInvalid(i);
				Sound::playSound(Sound_playerDead);
			}
		}
	}

	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addBulletPower(5);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addBulletPower(20);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addRecoveringTimeStandStop(50);
					this->player->addBulletPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addRecoveringTimeStandStop(300);
					this->player->addBulletPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					this->board->addScore(10);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->board->addScore(40);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//プレイヤーとレーザー
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
			for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.3*this->enemyBulletManage->getLazerSize(l).width) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, d);

					this->player->die();
					if (this->player->igetPlayerLife() < 0) this->isDied = true;
					Sound::playSound(Sound_playerDead);
				}
			}
		}
	}

	//敵と自機弾
	for (int e = 0; e<this->enemyManage->getEnemyVectorSizeMax(); ++e){
		for (int b = 0; b < this->playerBulletManage->getBulletSize(); ++b){
			if (this->isHitPointSquare(this->playerBulletManage->getPosition(b), this->enemyManage->igetEnemyPositionVectorIndex(e), this->enemyManage->getEnemySize(e)) == true){
				this->playerBulletManage->setInvalid(b);
				this->enemyManage->damaged(e, this->playerBulletManage->getAttackPower(b), false, 1.0);
				this->board->addScore(10);
			}
		}
	}

	//ショックレーザーと敵
	for (int e = 0; e < this->enemyManage->getEnemyVectorSizeMax(); e++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->enemyManage->getValidate(e) == false) continue;
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointSquare(this->enemyManage->getEnemyPosition(e)->igetPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), this->enemyManage->getEnemySize(e)) == true){
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
					this->enemyManage->damaged(e, this->shockWaveManage->getShockLazerAttackPower(l), false, 0.3);
					this->board->addScore(1000);
				}
			}
		}
	}

	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスと自機弾
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); ++boss){
		for (int bul = 0; bul < this->playerBulletManage->getBulletSize(); ++bul){
			if (this->playerBulletManage->getValid(bul) == false) continue;

			if (this->isHitPointSquare(this->playerBulletManage->getPosition(bul), this->bossManage->igetBoss(boss)->getPosition(), Size(72, 72)) == true){
				this->bossManage->damaged(boss, this->playerBulletManage->getAttackPower(bul));
				this->playerBulletManage->setInvalid(bul);
				this->board->addScore(10);
			}
		}
	}

	//ボスとショックレーザー
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), 100.0) == true){
					this->bossManage->damaged(boss, this->shockWaveManage->getShockLazerAttackPower(l));
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
					this->board->addScore(10);
				}
			}
		}
	}
}

void SceneGameFilm::hitCheckAllObject_Absorb(){
	//プレイヤーと敵
	for (int i = 0; i < this->enemyManage->getEnemyVectorSizeMax(); i++){
		if (this->isHitPointSquare(this->player->getPosition(), this->enemyManage->getEnemyPosition(i)->igetPosition(), this->enemyManage->getEnemySize(i)) == true){
			if (this->player->getCharactorStatus() == ChStatus_Normal) {
				this->player->die();
				Sound::playSound(Sound_playerDead);
			}
			if (this->player->igetPlayerLife() < 0) this->isDied = true;
		}
	}

	//プレイヤーとアイテム
	for (int i = 0; i < this->itemManage->getItemVectorSizeMax(); i++){
		if (this->isHitPointCircle(this->player->getPosition(), this->itemManage->getPosition(i), this->itemManage->getSize(i).width + this->player->getSize().width)){
			if (this->itemManage->getColor(i) == Item_Red){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Green){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addChargingPower(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addChargingPower(10);
				}
			}
			if (this->itemManage->getColor(i) == Item_Blue){
				if (this->itemManage->getKind(i) == Item_Small){
					this->board->addScore(10);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->board->addScore(40);
				}
			}
			if (this->itemManage->getColor(i) == Item_White){
				if (this->itemManage->getKind(i) == Item_Small){
					this->player->addLife(1);
				}
				if (this->itemManage->getKind(i) == Item_Large){
					this->player->addLife(10);
				}
			}

			Sound::playSound(Sound_item);
			this->itemManage->setInvalid(i);
		}
	}

	//コラプサーと敵
	for (int col = 0; col < this->collapsarManage->getVectorSize(); col++){
		for (int e = 0; e < this->enemyManage->getEnemyVectorSizeMax(); e++){
			if (this->enemyManage->getValidate(e) == false) continue;

			if (this->isHitPointCircle(this->enemyManage->getEnemyPosition(e)->igetPosition(), this->collapsarManage->getPosition(col), 50.0) == true){
				this->enemyManage->damaged(e, 1.0, true, 0.5);
				this->board->addScore(10);
			}
		}
	}

	//コラプサーと弾
	for (int col = 0; col < this->collapsarManage->getVectorSize(); col++){
		for (int b = 0; b < this->enemyBulletManage->getBulletVectorSizeMax(); b++){
			if (this->enemyBulletManage->getBulletValid(b) == false) continue;

			if (this->isHitPointCircle(this->collapsarManage->getPosition(col), this->enemyBulletManage->getBulletPosition(b), 50) == true){
				this->enemyBulletManage->setBulletInvalid(b);
				this->board->addScore(10);
				this->player->addChargingPower(1);
			}
		}
	}

	//コラプサーとレーザー
	for (int col = 0; col < this->collapsarManage->getVectorSize(); col++){
		for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); l++){
			for (int div = 0; div < this->enemyBulletManage->getLazerDivVectorSizeMax(l); div++){
				if (this->enemyBulletManage->getLazerDivValid(l, div) == false) continue;

				if (this->isHitPointCircle(this->collapsarManage->getPosition(col), this->enemyBulletManage->getLazerDivPosition(l, div), 60) == true){
					this->enemyBulletManage->setLazerDivInvalid(l, div);
					this->board->addScore(10);
					this->player->addChargingPower(1);
				}
			}
		}
	}

	//ショックレーザーと敵
	for (int e = 0; e < this->enemyManage->getEnemyVectorSizeMax(); e++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->enemyManage->getValidate(e) == false) continue;
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointSquare(this->enemyManage->getEnemyPosition(e)->igetPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), this->enemyManage->getEnemySize(e)) == true){
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
					this->enemyManage->damaged(e, this->shockWaveManage->getShockLazerAttackPower(l), false, 0.3);
					this->board->addScore(200);
				}
			}
		}
	}

	//プレイヤーと弾
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		if (this->player->isAbsorbReceipting() == true){
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.8*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;

					this->player->addChargingPower(1);
					this->player->decreaseAbsorbRunnningCount(1);

					this->enemyBulletManage->setBulletInvalid(i);
					Sound::playSound(Sound_ignitionGo);
					this->board->addScore(10);
				}
			}
		}
		else{
			for (int i = 0; i < this->enemyBulletManage->getBulletVectorSizeMax(); i++){
				if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getBulletPosition(i), 0.3*this->enemyBulletManage->getBulletSize(i).width) == true){
					if (this->enemyBulletManage->getBulletValid(i) == false) continue;

					this->player->die();
					if (this->player->igetPlayerLife() < 0) this->isDied = true;
					Sound::playSound(Sound_playerDead);
					this->enemyBulletManage->setBulletInvalid(i);
				}
			}
		}
	}

	//プレイヤーとレーザー
	if (this->player->getCharactorStatus() == ChStatus_Normal){
		if (this->player->isAbsorbReceipting() == true){
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.8*this->enemyBulletManage->getLazerSize(l).width) == true){
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						this->player->addChargingPower(1);
						this->player->decreaseAbsorbRunnningCount(1);
						Sound::playSound(Sound_ignitionGo);
						this->board->addScore(10);
					}
				}
			}
		}
		else{
			for (int l = 0; l < this->enemyBulletManage->getLazerVectorSizeMax(); ++l){
				for (int d = 0; d < this->enemyBulletManage->getLazerDivVectorSizeMax(l); ++d){
					if (this->isHitPointCircle(this->player->getPosition(), this->enemyBulletManage->getLazerDivPosition(l, d), 0.3*this->enemyBulletManage->getLazerSize(l).width) == true){
						this->enemyBulletManage->setLazerDivInvalid(l, d);

						this->player->die();
						if (this->player->igetPlayerLife() < 0) this->isDied = true;
						Sound::playSound(Sound_playerDead);
					}
				}
			}
		}
	}


	if (this->bossManage->isBossAttackingNow() == false) return;

	//ボスとショックレーザー
	for (int boss = 0; boss < this->bossManage->getBossVectorSizeMax(); boss++){
		for (int l = 0; l < this->shockWaveManage->getShockLazerVectorSize(); l++){
			for (int d = 0; d < this->shockWaveManage->getShockLazerDivVectorSize(l); d++){
				if (this->shockWaveManage->getShockLazerDivValid(l, d) == false) break;

				if (this->isHitPointCircle(this->bossManage->igetBoss(boss)->getPosition(), this->shockWaveManage->getShockLazerDivPosition(l, d), 64.0) == true){
					this->bossManage->damaged(boss, this->shockWaveManage->getShockLazerAttackPower(l));
					this->shockWaveManage->setShockLazerDivInvalid(l, d);
					this->board->addScore(200);
				}
			}
		}
	}
}

void SceneGameFilm::isetNextStage(){
	if (this->stage == 6){
		if (this->isetGameClearData->igetNoContinueFlag() == true){
			this->isetGameClearData->isetStageClearData(this->difficulty,this->selectedMode);
		}
		this->isetGameClearData->isetNoContinueFlag(true);
		this->isetNextScene->isetNextScene(Scene_Ending);
	}
	else{
		this->isWaitingNextStage = true;
	}
}