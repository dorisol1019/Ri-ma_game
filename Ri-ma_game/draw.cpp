#include"stdafx.h"

void DrawSystem::SetChar(char *c, int x, int y) {//�s��a����
	end++;
	drawChar[end].c = c; //�\�����镶����
	drawChar[end].x = x; //�������\������x���W
	drawChar[end].y = y; //�������\������y���W
}


void DrawSystem::SetChar2(int a, int x, int y) {//�s��a����
	end++;
	drawChar[end].a = a; //�\�����镶����
	drawChar[end].x = x; //�������\������x���W
	drawChar[end].y = y; //�������\������y���W
}


void DrawSystem::DrawChar() {
	/*
	  //char d[50];
	  //sprintf_s(d,"draw:%d,end);
	  //DrawString(10,30,d,GetColor(255,255,255));
	  //(255,255,255)�͔�
	*/
	for (int i = 0; i <= end; i++) { //0����end�܂�
		DrawString(drawChar[i].x,drawChar[i].y, drawChar[i].c,GetColor(255, 255, 255));
	}

	end = -1;
}

DrawSystem drawSystem;