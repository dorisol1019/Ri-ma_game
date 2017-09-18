#include"stdafx.h"

void DrawSystem::SetChar(char *c, int x, int y) {//不定径注意
	end++;
	drawChar[end].c = c; //表示する文字列
	drawChar[end].x = x; //文字列を表示するx座標
	drawChar[end].y = y; //文字列を表示するy座標
}


void DrawSystem::SetChar2(int a, int x, int y) {//不定径注意
	end++;
	drawChar[end].a = a; //表示する文字列
	drawChar[end].x = x; //文字列を表示するx座標
	drawChar[end].y = y; //文字列を表示するy座標
}


void DrawSystem::DrawChar() {
	/*
	  //char d[50];
	  //sprintf_s(d,"draw:%d,end);
	  //DrawString(10,30,d,GetColor(255,255,255));
	  //(255,255,255)は白
	*/
	for (int i = 0; i <= end; i++) { //0からendまで
		DrawString(drawChar[i].x,drawChar[i].y, drawChar[i].c,GetColor(255, 255, 255));
	}

	end = -1;
}

DrawSystem drawSystem;