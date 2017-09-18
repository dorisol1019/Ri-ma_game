#pragma once
#define W 500 //�ύX�\
#define H 480 //�ύX�\
#define PI 3.14159


struct XY {
	double x; //int�ł͂��߂Ȃ̂��H
	double y; //int�ł͂��߂Ȃ̂��H
};


class CHARA {
public:
	XY xy;
	XY addxy;
	double speed; 
	bool colFlag; //�Փ˃t���O
	int hp;
}; //�L�����N�^�[



class BULLET {
public:
	BULLET();
	XY xy;
	double angle;//�p�x
	bool colFlag;//�Փ˃t���O
	double speed;//�X�s�[�h
	double r;   //�e�����a
	int gHandle;//�摜�p�n���h��
	void update();
	int wait;  //���ˎ���
	//�v���C���[�̓����蔻��pvector�̃C���f�b�N�X
	int playerIndex;
	bool Hit; //�A�^������
	int Damage;
	bool Beatoff;
};  //�e�e

class NOZZLE {
protected:
	std::vector<BULLET *>bullets; //�e�q
public:
	XY xy;  //�e���ʒu
	double angle; //�e���p�x
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
	int end; //�g�p����Ă��郁�����̍Ō��
}BARRAG; //�e��
*/

/*
class BARRAGE {
public:

	BULLET *bu_p;
	int end; 
	//�g�p����Ă��郁�����̍Ō��
	BARRAGE();

	//BARRAGE��������
	//BARRAGE(int size);  //�R���X�g���N�^
	//BARRAGE���J���H
	//void Barrageremove(BARRAGE *bar_p);
	//BARRAGE��BULLET��ǉ��H
	//void AddBullet(BARRAGE *bar_p, BULLET bu);
	//BARRAGE�́A����ꏊ��BULLET���폜
	//void RemoveBullet(BARRAGE *bar_p, int i);
};
*/

//extern CHARA player;
//extern BARRAGE playerbar; //���@�e�Ǘ��\���́H

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
extern char hps[30];//HP��\�����邽�߂̕�����


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