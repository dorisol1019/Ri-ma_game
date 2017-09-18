#include"stdafx.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	SetMainWindowText("Ri-ma_game");
	//ウィンドウのタイトルを変更する
	
	//SetGraphMode(); 
	//画面モードの変更 SetGraphMode(int SizeX(画面の解像度) ,int SizeY(画面の解像度),int ColorBitNum(カラービット数))
	
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); 
	//ウィンドウモード変更と初期化と裏画面設定
	
	//Load();
	//音声データをあらかじめメモリにダインロードして高速化する

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	//文字列に使用するフォントのタイプを変更する

	//メインループ
	//Central()で実際のゲーム処理を行う
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//aaaa();//実装はよ
		central.update();
	}
	DxLib_End();//DXライブラリ終了処理
	return 0;
}