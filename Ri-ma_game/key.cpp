#include"stdafx.h"

void KeySystem::Getkey() { //どれだけの時間押されているか調べる関数(長押し対応)
	char GetHitkey[256]; //GetHitKeyAllに必要な関数宣言(定型句)
	GetHitKeyStateAll(GetHitkey); //DxLib関数キーボードのすべてのキーの押下状態を取得する
	
	for (int i = 0; i < 256; i++) {
		if (GetHitkey[i] == 1) { //i番目のキーコードに対応するキーが押されていたら
			key[i]++;            //加算
		}
		else {                   //押されていれば
			key[i] = 0;          //0にする
		}
	}
}

int KeySystem::Givekey(int keyCode) {
	if (keyCode < 0 || 256 <= keyCode) { 
		return -1; //キーボードにないキーを押すとエラーを吐く(キーはすべてで256なので基本的に超えることはない(はず))
	}
	else {
		return key[keyCode]; //キーが押されてるフレーム数を渡す(1秒に60フレーム)
	}
}

KeySystem keySystem;