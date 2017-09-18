#pragma once

class Myplayer;
class EnemyA;
class EnemyB;
class EnemyC;

class Central {
public:
	enum SCENE {
		TITLESCENE, //タイトルシーン
		SELECTSCENE,  //セレクトシーン
		GAMESCENE_1,    //ゲーム1
		GAMESCENE_2,   //ゲーム2
		GAMESCENE_3,  //ゲーム3
		GAMEOVERSCENE,//ゲームオーバーシーン
		CLEARSCENE   //クリアーシーン
	};

	//現在のシーン
	SCENE scene;
	//Enemy *enemy;
	Myplayer *myplayer;
	EnemyA *enemyA;
	EnemyB *enemyB;
	EnemyC *enemyC;

	bool update();

	Central();
	//void ChangeScene(SCENE _scene);

private:

	void TitleScene();
	void SelectScene();
	void GameScene_1();
	void GameScene_2();
	void GameScene_3();
	void GameOverScene();
	void GameClaerScene();
};

extern Central central;

extern bool gamenoowari;
extern bool gameclear;
extern bool GameInit;