#include"stdafx.h"

void TitleScene() {
	SetChar("文字シューティング", 50, 50);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) { //エンターキーを押したとき(DxLib)
		
		central.ChangeScene(SELECTSCENE); 
	}
}

/*
//初期化処理
void TitleSceneInit() {
	StopBgm();
	PlayBgm(TITLE_BGM);
}
*/