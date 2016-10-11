#include "sound.h"
#include "DxLib.h"

int Sound::soundHandle[21];
bool Sound::soundFlag[21];

void Sound::loadSound(){
	for(int i=0;i<21;i++) Sound::soundFlag[i]=false;

	soundHandle[Sound_Decide] = LoadSoundMem("material\\se\\decide.wav");
	soundHandle[Sound_Cancel] = LoadSoundMem("material\\se\\cancel.wav");
	soundHandle[Sound_SelectMove] = LoadSoundMem("material\\se\\sel_move.wav");
	soundHandle[Sound_scatteringBomb] = LoadSoundMem("material\\se\\scattering_bomb.wav");
	soundHandle[Sound_ignitionCharging] = LoadSoundMem("material\\se\\ignition.wav");
	soundHandle[Sound_shotChargingPower] = LoadSoundMem("material\\se\\shot_pow.wav");
	soundHandle[Sound_ignitionGo] = LoadSoundMem("material\\se\\ignition_go.wav");
	soundHandle[Sound_item] = LoadSoundMem("material\\se\\item.wav");
	soundHandle[Sound_explosion] = LoadSoundMem("material\\se\\explosion.wav");
	soundHandle[Sound_playerDead] = LoadSoundMem("material\\se\\pl_dead.wav");
	soundHandle[Sound_enemyDead] = LoadSoundMem("material\\se\\e_death.wav");
	soundHandle[Sound_bossat_clear] = LoadSoundMem("material\\se\\bossat_clear.wav");
	soundHandle[Sound_bossat_fail] = LoadSoundMem("material\\se\\bossat_fail.wav");
	soundHandle[Sound_extend] = LoadSoundMem("material\\se\\pl_lifeup.wav");
	soundHandle[Sound_PlayerBullet] = LoadSoundMem("material\\se\\pl_bullet.wav");
	soundHandle[Sound_PlayerLazer] = LoadSoundMem("material\\se\\pl_lazer.wav");
	soundHandle[Sound_PlayerRecovery] = LoadSoundMem("material\\se\\pl_recovery.wav");
	soundHandle[Sound_EnemyBullet] = LoadSoundMem("material\\se\\e_bullet.wav");
	soundHandle[Sound_EnemyLazer] = LoadSoundMem("material\\se\\e_lazer.wav");
	soundHandle[Sound_Collapsar] = LoadSoundMem("material\\se\\collapsar.wav");
	soundHandle[Sound_TimeAlart] = LoadSoundMem("material\\se\\time_alart.wav");

	for (int i = 0; i < 21; i++){
		ChangeVolumeSoundMem(220, soundHandle[i]);
	}
}

void Sound::playSound(SoundKind kind){
	Sound::soundFlag[kind] = true;
}

void Sound::PlayAll(){
	int tmp;
	for(int i=0;i<21;i++){
		if(Sound::soundFlag[i]==true){
			//PlaySoundMem(Sound::soundHandle[i], DX_PLAYTYPE_BACK);
			tmp = DuplicateSoundMem(Sound::soundHandle[i]);
			PlaySoundMem(tmp, DX_PLAYTYPE_BACK);
			Sound::soundFlag[i]=false;
		}
	}
}