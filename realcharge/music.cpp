#include "music.h"

void Music::loadMusic(){
	GGS4AddListFromFileA("bgm\\b1.mid",0,Music_Boss1);
	GGS4AddListFromFileA("bgm\\b2.mid",0,Music_Boss2);
	GGS4AddListFromFileA("bgm\\b3.mid",0,Music_Boss3);
	GGS4AddListFromFileA("bgm\\b4.mid",0,Music_Boss4);
	GGS4AddListFromFileA("bgm\\b5.mid",0,Music_Boss5);
	GGS4AddListFromFileA("bgm\\b6.mid",0,Music_Boss6);
	GGS4AddListFromFileA("bgm\\bex.mid",0,Music_BossEx);
	GGS4AddListFromFileA("bgm\\r1.mid",0,Music_Road1);
	GGS4AddListFromFileA("bgm\\r2.mid",0,Music_Road2);
	GGS4AddListFromFileA("bgm\\r3.mid",0,Music_Road3);
	GGS4AddListFromFileA("bgm\\r4.mid",0,Music_Road4);
	GGS4AddListFromFileA("bgm\\r5.mid",0,Music_Road5);
	GGS4AddListFromFileA("bgm\\r6.mid",0,Music_Road6);
	GGS4AddListFromFileA("bgm\\rex.mid",0,Music_RoadEx);
	GGS4AddListFromFileA("bgm\\op.mid",0,Music_Opening);
	GGS4AddListFromFileA("bgm\\ed.mid",0,Music_Ending);
	GGS4AddListFromFileA("bgm\\tu.mid",0,Music_Tutorial);
}

void Music::playMusic(MusicList music){
	GGS4Play(GGSPLAY_LOOP,music,0,0,0);
}

void Music::playRoadMusic(int stage){
	GGS4Play(GGSPLAY_LOOP,2*stage-1,0,0,0);
}

void Music::playBossMusic(int stage){
	GGS4Play(GGSPLAY_LOOP,2*stage,0,0,0);
}