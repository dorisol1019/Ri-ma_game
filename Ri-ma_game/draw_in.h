#pragma once
struct DRAWCHAR {
	char *c;
	int a;
	int x;
	int y;
}; //�`�悷�镶���̏���ێ�����\����

class DrawSystem {
public:
	DRAWCHAR drawChar[500];
	int end = -1;//drawChar�Ɏg�p����郁�����̍Ō��

	void SetChar(char *c, int x, int y); //draw.cpp 
	void SetChar2(int a, int x, int y);

	void DrawChar(); //draw.cpp
};

extern DrawSystem drawSystem;