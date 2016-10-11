#ifndef _SOUND_
#define _SOUND_

enum SoundKind{
	Sound_Decide,
	Sound_Cancel,
	Sound_SelectMove,
	Sound_scatteringBomb,
	Sound_ignitionCharging,
	Sound_shotChargingPower,
	Sound_ignitionGo,
	Sound_item,
	Sound_explosion,
	Sound_playerDead,
	Sound_enemyDead,
	Sound_bossat_clear,
	Sound_bossat_fail,
	Sound_extend,
	Sound_PlayerBullet,
	Sound_PlayerLazer,
	Sound_PlayerRecovery,
	Sound_EnemyBullet,
	Sound_EnemyLazer,
	Sound_Collapsar,
	Sound_TimeAlart
};

class Sound{
	static int soundHandle[];
	static bool soundFlag[];
public:
	static void loadSound();
	static void playSound(SoundKind kind);
	static void PlayAll();
};

#endif