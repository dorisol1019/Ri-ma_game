#include"stdafx.h"

void KeySystem::Getkey() { //�ǂꂾ���̎��ԉ�����Ă��邩���ׂ�֐�(�������Ή�)
	char GetHitkey[256]; //GetHitKeyAll�ɕK�v�Ȋ֐��錾(��^��)
	GetHitKeyStateAll(GetHitkey); //DxLib�֐��L�[�{�[�h�̂��ׂẴL�[�̉�����Ԃ��擾����
	
	for (int i = 0; i < 256; i++) {
		if (GetHitkey[i] == 1) { //i�Ԗڂ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			key[i]++;            //���Z
		}
		else {                   //������Ă����
			key[i] = 0;          //0�ɂ���
		}
	}
}

int KeySystem::Givekey(int keyCode) {
	if (keyCode < 0 || 256 <= keyCode) { 
		return -1; //�L�[�{�[�h�ɂȂ��L�[�������ƃG���[��f��(�L�[�͂��ׂĂ�256�Ȃ̂Ŋ�{�I�ɒ����邱�Ƃ͂Ȃ�(�͂�))
	}
	else {
		return key[keyCode]; //�L�[��������Ă�t���[������n��(1�b��60�t���[��)
	}
}

KeySystem keySystem;