#include"stdafx.h"

void SelectScene() {
	//�㉺���őI�����ăG���^�[�������
	//
	if (keySystem.Givekey(KEY_INPUT_RETURN) == 1) { //�G���^�[�L�[���������Ƃ�(DxLib)

		//�����L�[�őI��������֐�

		central.ChangeScene(GAMESCENE_1);
		central.ChangeScene(GAMESCENE_2);
		central.ChangeScene(GAMESCENE_3);
	}
}