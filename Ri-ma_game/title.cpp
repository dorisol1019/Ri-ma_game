#include"stdafx.h"

void TitleScene() {
	SetChar("�����V���[�e�B���O", 50, 50);
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) { //�G���^�[�L�[���������Ƃ�(DxLib)
		
		central.ChangeScene(SELECTSCENE); 
	}
}

/*
//����������
void TitleSceneInit() {
	StopBgm();
	PlayBgm(TITLE_BGM);
}
*/