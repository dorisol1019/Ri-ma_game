#include"stdafx.h"
// �V�[���؂�ւ����ǂ����邩
//static bool updateChangeFlag=true;

bool gamenoowari = false;
bool gameclear = false;
//bool GameInit;



Central::Central() {
	//playerbar.BARRAGE(512);
	enemyA = new EnemyA();
	enemyB = new EnemyB();
	enemyC = new EnemyC();

}

void Central::TitleScene() {
	drawSystem.SetChar("Ri-ma_game", 50, 50);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) {
		scene = SELECTSCENE;
	}
}
void Central::SelectScene() {
	drawSystem.SetChar("�Q�[���P�FZ�L�[", 60, 50);
	drawSystem.SetChar("�Q�[���Q�FX�L�[", 70, 100);
	drawSystem.SetChar("�Q�[���R�FC�L�[", 80, 150);

	if (keySystem.Givekey(KEY_INPUT_Z) == 1) { //Z�L�[���������Ƃ�(DxLib)	
		//GameInit = false;
		//GameInit = true;
		//GameInit = false;
		//BULLET::BULLET();    //�������Ӗ��Ȃ�
		//Player::Player();
		scene = GAMESCENE_1;
	}

	if (keySystem.Givekey(KEY_INPUT_X) == 1) { //X�L�[���������Ƃ�(DxLib)

		scene = GAMESCENE_2;
	}

	if (keySystem.Givekey(KEY_INPUT_C) == 1) { //C�L�[���������Ƃ�(DxLib)
		scene = GAMESCENE_3;
	}
}

void Central::GameScene_1() {
	//drawSystem.SetChar("�Q�[���P", 60, 50);
	player.Update();
	enemyA->Update();
	if (gamenoowari) {
		scene = GAMEOVERSCENE;
		gamenoowari = false;
	}
	/*
	if (gameclear) {
		scene = CLEARSCENE;
		gameclear = false;
	}
	*/
}

void Central::GameScene_2() {
	//drawSystem.SetChar("�Q�[���Q", 60, 50);
	player.Update();
	enemyB->Update();
	if (gamenoowari) {
		scene = GAMEOVERSCENE;
		gamenoowari = false;
	}
}

void Central::GameScene_3() {
	//drawSystem.SetChar("�Q�[���R", 60, 50);
	player.Update();
	enemyC->Update();
	if (gamenoowari) {
		scene = GAMEOVERSCENE;
		gamenoowari = false;
	}
}

void Central::GameOverScene() {
	drawSystem.SetChar("�Q�[���I�[�o�[", 250, 200);
	drawSystem.SetChar("Enter�L�[��Select��ʂ�", 250, 300);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) {
		scene = SELECTSCENE;
	}

}

void Central::GameClaerScene() {
	drawSystem.SetChar("�Q�[���N���A", 250, 200);
	drawSystem.SetChar("Enter�L�[��Select��ʂ�", 250, 300);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) {
		scene = SELECTSCENE;
	}
}

bool Central::update() {
	/*//�V�[���؂�ւ�����
	if (updateChangeFlag) {
		if (scene == TITLESCENE) {			//enum�̒��̃^�C�g���V�[���̎�
			//TitleSceneInit(); 			//Title_out.h
		}
		if (scene == SELECTSCENE) {

		}
		if (scene == GAMESCENE) {			//enum�̒��̃^�C�g���V�[���̎�
			//GameSceneInit();//���͊֌W�Ȃ�  //�Q�[���V�[���̏�����
		}
		updateChangeFlag = false;			//enum���������̌J��Ԃ��̊֐��Ăяo����h���t���O
	}
	*/

	switch (scene) {
	case 0:
		TitleScene();  //Title_out.h
		break;

	case 1:
		SelectScene(); //SelectScene.h
		break;

	case 2:
		GameScene_1(); //game_out.h
		break;

	case 3:
		GameScene_2(); //game_out.h
		break;

	case 4:
		GameScene_3(); //game_out.h

	case 5:
		GameOverScene();
		break;

	case 6:
		GameClaerScene();
		break;
	}


	keySystem.Getkey();   //key_out.h
	//BgmLoop();
	drawSystem.DrawChar(); //draw_out.h

	return true; //��������������������������
}

/*
void Central::ChangeScene(SCENE _scene) {

	if (scene == GAMESCENE_1||scene==GAMESCENE_2||scene==GAMESCENE_3) {
		//GameSceneEnd();
	}
	//updateChangeFlag = true;
	scene = _scene;
}
*/

Central central;