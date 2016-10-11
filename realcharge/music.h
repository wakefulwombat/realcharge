#ifndef _MUSIC_
#define _MUSIC_

#include "GuruGuruSMF4_C_Static.h"

enum MusicList{
	Music_Opening,
	Music_Road1,
	Music_Boss1,
	Music_Road2,
	Music_Boss2,
	Music_Road3,
	Music_Boss3,
	Music_Road4,
	Music_Boss4,
	Music_Road5,
	Music_Boss5,
	Music_Road6,
	Music_Boss6,
	Music_RoadEx,
	Music_BossEx,
	Music_Ending,
	Music_Tutorial
};

class Music{
private:
public:
	static void loadMusic();
	static void playMusic(MusicList music);
	static void playRoadMusic(int stage);
	static void playBossMusic(int stage);
};

#endif