#include"stdafx.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetMainWindowText("Ri-ma_game");
	//�E�B���h�E�̃^�C�g����ύX����
	
	//SetGraphMode(); 
	//��ʃ��[�h�̕ύX SetGraphMode(int SizeX(��ʂ̉𑜓x) ,int SizeY(��ʂ̉𑜓x),int ColorBitNum(�J���[�r�b�g��))
	
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	//�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	
	//Load();
	//�����f�[�^�����炩���߃������Ƀ_�C�����[�h���č���������

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	//������Ɏg�p����t�H���g�̃^�C�v��ύX����

	//���C�����[�v
	//Central()�Ŏ��ۂ̃Q�[���������s��
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//aaaa();//�����͂�
		central.update();
	}
	DxLib_End();//DX���C�u�����I������
	return 0;
}