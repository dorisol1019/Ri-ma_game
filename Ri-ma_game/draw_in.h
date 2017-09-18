#pragma once
struct DRAWCHAR {
	char *c;
	int a;
	int x;
	int y;
}; //•`‰æ‚·‚é•¶š‚Ìî•ñ‚ğ•Û‚·‚é\‘¢‘Ì

class DrawSystem {
public:
	DRAWCHAR drawChar[500];
	int end = -1;//drawChar‚Ég—p‚³‚ê‚éƒƒ‚ƒŠ‚ÌÅŒã”ö

	void SetChar(char *c, int x, int y); //draw.cpp 
	void SetChar2(int a, int x, int y);

	void DrawChar(); //draw.cpp
};

extern DrawSystem drawSystem;