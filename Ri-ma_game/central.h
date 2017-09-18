#pragma once

class Myplayer;
class EnemyA;
class EnemyB;
class EnemyC;

class Central {
public:
	enum SCENE {
		TITLESCENE, //�^�C�g���V�[��
		SELECTSCENE,  //�Z���N�g�V�[��
		GAMESCENE_1,    //�Q�[��1
		GAMESCENE_2,   //�Q�[��2
		GAMESCENE_3,  //�Q�[��3
		GAMEOVERSCENE,//�Q�[���I�[�o�[�V�[��
		CLEARSCENE   //�N���A�[�V�[��
	};

	//���݂̃V�[��
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