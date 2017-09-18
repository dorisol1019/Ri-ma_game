#pragma once
#define W 500 //変更可能
#define H 480 //変更可能
#define PI 3.14159


struct XY {
	double x; //intではだめなのか？
	double y; //intではだめなのか？
};


class CHARA {
public:
	XY xy;
	XY addxy;
	double speed; 
	bool colFlag; //衝突フラグ
	int hp;
}; //キャラクター



class BULLET {
public:
	BULLET();
	XY xy;
	double angle;//角度
	bool colFlag;//衝突フラグ
	double speed;//スピード
	double r;   //弾幕半径
	int gHandle;//画像用ハンドル
	void update();
	int wait;  //発射時刻
	//プレイヤーの当たり判定用vectorのインデックス
	int playerIndex;
	bool Hit; //アタリ判定
	int Damage;
	bool Beatoff;
};  //銃弾

class NOZZLE {
protected:
	std::vector<BULLET *>bullets; //弾倉
public:
	XY xy;  //銃口位置
	double angle; //銃口角度
	void addbullet(BULLET *bullet);
	void update();
	int frameCount;
	bool end;
	double deltaAngle;
	double deltaSpeed;
	NOZZLE();
};

/*
class Myplayer : public CHARA {
public:
	//std::vector<NOZZLE *>nozzles;
	Myplayer();
	//void Update();
};
*/

class Enemy : public CHARA {
public:
	std::vector<NOZZLE *>nozzles;
	Enemy();
	void Update();
};

class EnemyA : public Enemy {
public:
	EnemyA();
};

class EnemyB : public Enemy {
public:
	EnemyB();
};

class EnemyC : public Enemy {
public:
	EnemyC();
};



/*
typedef struct {
	BULLET *bu_p;
	int end; //使用されているメモリの最後尾
}BARRAG; //弾幕
*/

/*
class BARRAGE {
public:

	BULLET *bu_p;
	int end; 
	//使用されているメモリの最後尾
	BARRAGE();

	//BARRAGEを初期化
	//BARRAGE(int size);  //コンストラクタ
	//BARRAGEを開放？
	//void Barrageremove(BARRAGE *bar_p);
	//BARRAGEにBULLETを追加？
	//void AddBullet(BARRAGE *bar_p, BULLET bu);
	//BARRAGEの、ある場所のBULLETを削除
	//void RemoveBullet(BARRAGE *bar_p, int i);
};
*/

//extern CHARA player;
//extern BARRAGE playerbar; //自機弾管理構造体？

class PlayerNozzle;

class Player:public CHARA {
public:
	//void Shot();
	PlayerNozzle *nozzle;
	Player();
	//~Player();
	void Myplayer();
	void Update();
};

extern Player player;

//
//extern void PlayerShot();
//
//extern void InitPlayer();
//
//extern void EndPlayer();
//
//extern void Player();
//
extern char hps[30];//HPを表示するための文字列


//way
class WayNozzle : public NOZZLE {
public:
	WayNozzle(int setX,int setY,double pibotAngle,int row,int col, int totalAngle, int span,double speed);
	//void WayNozzle1(int setX, int setY, double pibotAngle, int row, int col, int totalAngle, int span, double speed);
};

class PlayerNozzle : public NOZZLE {
public:
	PlayerNozzle(Player player);
	void update(XY playerXY);
};

extern int Damage;