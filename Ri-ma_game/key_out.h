#pragma once

class KeySystem {
public:
	//�L�[���͂��擾����֐�
	void Getkey();

	//���ʂ�Ԃ��֐�
	int Givekey(int keyCode);

	int key[256];
};

extern KeySystem keySystem;