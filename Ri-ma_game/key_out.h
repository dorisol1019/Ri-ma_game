#pragma once

class KeySystem {
public:
	//ƒL[“ü—Í‚ğæ“¾‚·‚éŠÖ”
	void Getkey();

	//Œ‹‰Ê‚ğ•Ô‚·ŠÖ”
	int Givekey(int keyCode);

	int key[256];
};

extern KeySystem keySystem;