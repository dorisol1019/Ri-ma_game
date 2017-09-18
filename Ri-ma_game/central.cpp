#include"stdafx.h"
// シーン切り替えをどうするか
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
	drawSystem.SetChar("ゲーム１：Zキー", 60, 50);
	drawSystem.SetChar("ゲーム２：Xキー", 70, 100);
	drawSystem.SetChar("ゲーム３：Cキー", 80, 150);

	if (keySystem.Givekey(KEY_INPUT_Z) == 1) { //Zキーを押したとき(DxLib)	
		//GameInit = false;
		//GameInit = true;
		//GameInit = false;
		//BULLET::BULLET();    //初期化意味なし
		//Player::Player();
		scene = GAMESCENE_1;
	}

	if (keySystem.Givekey(KEY_INPUT_X) == 1) { //Xキーを押したとき(DxLib)

		scene = GAMESCENE_2;
	}

	if (keySystem.Givekey(KEY_INPUT_C) == 1) { //Cキーを押したとき(DxLib)
		scene = GAMESCENE_3;
	}
}

void Central::GameScene_1() {
	//drawSystem.SetChar("ゲーム１", 60, 50);
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
	//drawSystem.SetChar("ゲーム２", 60, 50);
	player.Update();
	enemyB->Update();
	if (gamenoowari) {
		scene = GAMEOVERSCENE;
		gamenoowari = false;
	}
}

void Central::GameScene_3() {
	//drawSystem.SetChar("ゲーム３", 60, 50);
	player.Update();
	enemyC->Update();
	if (gamenoowari) {
		scene = GAMEOVERSCENE;
		gamenoowari = false;
	}
}

void Central::GameOverScene() {
	drawSystem.SetChar("ゲームオーバー", 250, 200);
	drawSystem.SetChar("EnterキーでSelect画面へ", 250, 300);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) {
		scene = SELECTSCENE;
	}

}

void Central::GameClaerScene() {
	drawSystem.SetChar("ゲームクリア", 250, 200);
	drawSystem.SetChar("EnterキーでSelect画面へ", 250, 300);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) {
		scene = SELECTSCENE;
	}
}

bool Central::update() {
	/*//シーン切り替え処理
	if (updateChangeFlag) {
		if (scene == TITLESCENE) {			//enumの中のタイトルシーンの時
			//TitleSceneInit(); 			//Title_out.h
		}
		if (scene == SELECTSCENE) {

		}
		if (scene == GAMESCENE) {			//enumの中のタイトルシーンの時
			//GameSceneInit();//今は関係ない  //ゲームシーンの初期化
		}
		updateChangeFlag = false;			//enumが同じ時の繰り返しの関数呼び出しを防ぐフラグ
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

	return true; //直しあああああああああああ
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