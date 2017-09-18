#include"stdafx.h"

void SelectScene() {
	//上下矢印で選択してエンター押すやつ
	//
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) { //エンターキーを押したとき(DxLib)

		//方向キーで選択をする関数

		central.ChangeScene(GAMESCENE_1);
		central.ChangeScene(GAMESCENE_2);
		central.ChangeScene(GAMESCENE_3);
	}
}