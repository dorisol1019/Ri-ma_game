#include"stdafx.h"
int Damage=0;
//BARRAGE::BARRAGE() {}

//
//BARRAGE::BARRAGE(BARRAGE *bar_p, int size) { //�R���X�g���N�^ BARRAGE��������
//	do {
//		(*bar_p).bu_p = new BULLET();  //���������蓖��
//	} while ((*bar_p).bu_p == nullptr); //NULL�ɂȂ�܂�loop
//	(*bar_p).end = -1;
//}

//void BARRAGE::Barrageremove(BARRAGE *bar_p) { //BARRAGE���J��
//	delete (*bar_p).bu_p; //BULLET���������
//}

//void BARRAGE::AddBullet(BARRAGE *bar_p, BULLET bu) { //BARRAGE��BULLET��ǉ��H
//	(*bar_p).end++; //�Ȃ񂩑����Ă�
//	(*bar_p).bu_p[(*bar_p).end] = bu;
//}

//void BARRAGE::RemoveBullet(BARRAGE *bar_p, int i) {
//	(*bar_p).bu_p[i] = (*bar_p).bu_p[(*bar_p).end];
//	(*bar_p).end--;  //�Ȃ񂩌����Ă�
//}

/*
void Player::Shot() {
	static int count = 0; //�e�̔��˕p�x�𒲐߂���p?
	count++;

	if (count % 15 != 0) { //count��15�Ŋ����ė]�肪0�̎��@15,30,45�c �ɂ������ĂȂ��̂��ȁH
		return;
	}

	//BULLET bullet[2];         //���@�̌��e����2�H
	//bullet[0].xy = player.xy; //�v���C���[�̏ꏊ
	//bullet[1].xy = player.xy; //�v���C���[�̏ꏊ�@//��Ƃ������ł����̂���
	//bullet[0].conFlag = false; //�����蔻��
	//bullet[1].conFlag = false; //�����蔻��
	//bullet[0].xy.x += 16;      //�v���C���[����16���ꂽ���W����e������H
	//bullet[1].xy.x += -16;     //�v���C���[����-16���ꂽ�Ƃ��납��e�������?
	BULLET *bullet;
	bullet = new BULLET();
	bullet->xy = player.xy;
	bullet->colFlag = false;
	bullet->xy.x += 16;
	playerbar.AddBullet(&playerbar, *bullet);
	bullet = new BULLET();
	bullet->xy = player.xy;
	bullet->colFlag = false;
	bullet->xy.x -= 16;
	playerbar.AddBullet(&playerbar, *bullet);
	/*playerbar.AddBullet(&playerbar, bullet[0]);
	playerbar.AddBullet(&playerbar, bullet[1]);
}
*/


//������-------------------------------------
Player::Player() {
	player.xy.x = W / 2;  //�v���C���[���@�̏���x���W�@�@�ύX�\
	player.xy.y = H - 20; //�v���C���[���@�̏���y���W�@�@�ύX�\
	player.speed = 5;     //�v���C���[���@�̃X�s�[�h �ύX�\
	player.hp = 5;        //�v���C���[���@�̎c�薽�@ �ύX�\
	nozzle = new PlayerNozzle(*this);

	//BARRAGE::BARRAGE(&playerbar, 50); //playerbar��������
}

//�I������-------------------------------
//Player::~Player() {
//	playerbar.Barrageremove(&playerbar);
//}

//�v���C���[���X�V
void Player::Update() {
		if (player.hp <= 0) {            //HP��0�̎��Q�[���I�[�o�[(����͂���)
			//central.ChangeScene(Central::GAMEOVERSCENE); //central.h(ChangeScene,enum GAMEOVER)
			//central.scene = Central::GAMEOVER;
		}
		player.addxy.x = 0; //CHARA�^�@x�̉��Z�̏������@//�K�v���H�@//�R���X�g���N�^�ɂ�����
		player.addxy.y = 0; //CHARA�^�@y�̉��Z�̏������@//�K�v���H

		//���L�[(�㉺���E)�ňړ�-----------------------------------------
		//��ړ�
		if (keySystem.Givekey(KEY_INPUT_UP) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.y = -1;          //����ō��W������
		}
		//���ړ�
		if (keySystem.Givekey(KEY_INPUT_DOWN) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.y = 1;          //�����ō��W������
		}
		//���ړ�
		if (keySystem.Givekey(KEY_INPUT_LEFT) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.x = -1;          //�����ō��W������
		}
		//�E�ړ�
		if (keySystem.Givekey(KEY_INPUT_RIGHT) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.x = 1;          //�E���ō��W������
		}

		if (player.addxy.x != 0 || player.addxy.y != 0) { //�v����ɕ����L�[���������Ƃ�
			double distance = sqrt(player.addxy.x*player.addxy.x + player.addxy.y*player.addxy.y); //��(x^2+y^2) �O�����̒藝�@�΂߂̋����H 
			player.xy.x += player.addxy.x / distance*player.speed; //�v���C���[��x���W���ړ��񐔁~�ړ��X�s�[�h/���� 
			player.xy.y += player.addxy.y / distance*player.speed; //�v���C���[��y���W���ړ��񐔁~�ړ��X�s�[�h/����

			//��ʂ���̂͂ݏo������
			//x���W
			if (player.xy.x > W - 16) {
				player.xy.x = W - 16;  //��萔�ȏ�͈��ɂȂ�(���{��)  //����͎����̉�ʂ̑傫���ɍ��킹�ĕύX���Ȃ���΂Ȃ�Ȃ��@//���̂��߂Ɍ�ŉ�ʂ̑傫�������߂悤
			}
			if (player.xy.x < 0) {
				player.xy.x = 0;   //DxLib�̍��W�͈�ԍ���Ɍ��_������̂ł������͕ύX���Ȃ��Ă悢
			}

			//y���W
			if (player.xy.y > H - 16) {
				player.xy.y = H - 16; //���ȏ�͈��ɂȂ�
			}
			if (player.xy.y < 0) {
				player.xy.y = 0;  //Dxlib�̌��_
			}
		}

		//�V���b�g-------------------------------------
		//if (keySystem.Givekey(KEY_INPUT_Z) != 0) {  //Z���������Ƃ����@�̓V���b�g������
		//	Shot();     //�����ɒ�`����܂�
		//}

		//HP�\��
		//sprintf_s(hps, "HP:%d", player.hp);  //������Ƃ��̊֐��m��Ȃ�
		//drawSystem.SetChar(hps, 10, 400);//draw_out.h (������,�\������x���W,�\�����邙���W )
		
		Myplayer();

		//Shot
		nozzle->update(xy);
		/*for (int i = 0; i < nozzles.size();) {
			nozzles[i]->update();
			if (nozzles[i]->end) {
				delete nozzles[i];
				nozzles.erase(nozzles.begin() + i);
				continue;
			}
			i++;
		}*/

	

		//�v���C���[�\��-------------------------
		drawSystem.SetChar("��", player.xy.x, player.xy.y);
		if (player.colFlag) {
			player.colFlag = false; player.hp--;
		}
		//SetCollision(player.xy, 3, &player.colFlag, PLAYER);
	
}



void NOZZLE::addbullet(BULLET *bullet) {
	bullets.push_back(bullet);
}

BULLET::BULLET() {
	xy.x = 0;
	xy.y = 0;
	angle = 0;
	colFlag = false;
	speed = 1;
	r = 10;
	wait = 0;
	Hit = false;
	Beatoff = false;
}



void BULLET::update() {//�����̍��W�ɉ摜��\��

	drawSystem.SetChar("Enemy HP", 0, 0);
	DrawFormatString(0, 16, GetColor(255, 255, 255), "%d", Damage);
	
	DrawRotaGraph(xy.x, xy.y, 1, angle, gHandle, true);
	xy.x += speed*cos(angle*PI/180);
	xy.y += speed*sin(angle*PI/180);
	drawSystem.SetChar("�e", xy.x, xy.y);

	//x���W ����
	if (xy.x < 0 || xy.x>500) {
		colFlag = true;
	}
	//y���W ����
	if (xy.y < 0 || xy.y>480) {
		colFlag = true;
	}
	if (sqrt(pow(xy.x - player.xy.x, 2) + pow(xy.y - player.xy.y, 2) < r)) {
		drawSystem.SetChar("Hit", 0, 0);
		Hit = true;
		//GameInit = false;
		//GameInit = true;
		//GameInit = false;
		//BULLET::BULLET();
		gamenoowari = Hit;

	}

	if (sqrt(pow(xy.x - central.enemyA->xy.x, 2) + pow(xy.y - central.enemyA->xy.y, 2) < r)) {
		Damage++;
		
		if (Damage > 5) {
			Damage = 0;
			Beatoff = true;
			gameclear = Beatoff;
		}
	}
}

NOZZLE::NOZZLE() {
	angle = 0;
	end = false;
	deltaAngle = 0;
	deltaSpeed = 0;
}

void NOZZLE::update() {
	frameCount++;
	for (int i = 0; i < bullets.size();) {//���݂�bullet�̗v�f�̐����A���ė���

		if (frameCount>bullets[i]->wait) {    //frameCount�𒴂�����
			bullets[i]->update();    //����
		}
		else {
			bullets[i]->angle += deltaAngle;
			bullets[i]->speed += deltaSpeed;
		}

		if (bullets[i]->colFlag == true) {     //�Փ˃t���O��true�̎��A�e������
			delete bullets[i];                 //bullets�̃��������
			bullets.erase(bullets.begin() + i);  //vector�̃R���e�i�̏���
			continue;
		}
		i++;
	}
	if (bullets.size() == 0) {
		end = true;
	}
}


void Player::Myplayer() {   //���@����̒e�� //���[��A�����Ȃ�
	//nozzle = new PlayerNozzle(*this);
	//if (keySystem.Givekey(KEY_INPUT_Z) == 1) { //Z��������Ă�Ƃ�
	//	//xy.x = player.xy.x;
	//	//xy.y = player.xy.y;
	//	for (int i = 0; i < 2; i++) {
	//		WayNozzle *wayNozzle = new WayNozzle(xy.x, xy.y, -90, 100, 1, 60, 4, 8);
	//		wayNozzle->deltaAngle = 0;
	//		nozzles.push_back(wayNozzle);
	//	}
	//}
}


Enemy::Enemy(){
	xy.x = 250;
	xy.y = 80;

	//WayNozzle *wayNozzle = new WayNozzle(xy.x, xy.y,0, 30, 20, 360, 8, 4);
}

EnemyA::EnemyA() {
	for (int i = 0; i < 4; i++) {
		WayNozzle *wayNozzle = new WayNozzle(xy.x, xy.y, 90 * i, 300, 3, 30, 4, 8);
		wayNozzle->deltaAngle = 2;
		nozzles.push_back(wayNozzle);
	}

}
EnemyB::EnemyB() {
	for (int i = 0; i < 5; i++) {
		WayNozzle *wayNozzle = new WayNozzle(xy.x, xy.y, 90, 300, 5, 60, 4, 8);
		wayNozzle->deltaAngle = 0;
		nozzles.push_back(wayNozzle);
		//WayNozzle *wayNozzle1 = new WayNozzle(xy.x, xy.y, 90, 300, 2, 90, 2, 8);
	}
}

EnemyC::EnemyC() {

}

/*
void Myplayer::Update() {
	for (int i = 0; i < nozzles.size();) {
		nozzles[i]->update();
		if (nozzles[i]->end) {
			delete nozzles[i];
			nozzles.erase(nozzles.begin() + i);
		}
		i++;
	}
}
*/


void Enemy::Update() {
	for (int i = 0; i < nozzles.size();) {
		nozzles[i]->update();
		if (nozzles[i]->end) {
			delete nozzles[i];
			nozzles.erase(nozzles.begin() + i);
		}
		i++;
	}
	drawSystem.SetChar("�G", xy.x, xy.y);
}

//h�t�@�C���fextern�Ő錾�����ϐ��E�֐��́Acpp�t�@�C�����f���߂Đ錾����
//CHARA player;
Player player;
//BARRAGE playerbar;
char hps[30];

WayNozzle::WayNozzle(int setX,int setY,double pibotAngle,int row,int col,int totalAngle,int span,double speed) {
	xy.x = setX;
	xy.y = setY;
	angle = pibotAngle;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			BULLET *tmp = new BULLET();
			tmp->xy = xy;
			if (col == 1)col = 2;
			tmp->angle = angle - totalAngle / 2 + j * (totalAngle / (col - 1));
			tmp->speed = speed;
			tmp->wait = span * i;
			addbullet(tmp);
		}
	}
}

PlayerNozzle::PlayerNozzle(Player player) {
	xy = player.xy;
	angle = -90;
	deltaAngle = 0;
	deltaSpeed = 0.1;

}

void PlayerNozzle::update(XY playerXY) {
	frameCount++;
	if (CheckHitKey(KEY_INPUT_Z)) {
		BULLET *bullet = new BULLET();
		bullet->xy = playerXY;
		bullet->angle = angle;
		bullet->speed = 8;
		bullet->r = 15;

		addbullet(bullet);
	}

	for (int i = 0; i < bullets.size();) {//���݂�bullet�̗v�f�̐����A���ė���

		if (frameCount>bullets[i]->wait) {    //frameCount�𒴂�����
			bullets[i]->update();    //����
		}
		else {
			bullets[i]->angle += deltaAngle;
			bullets[i]->speed += deltaSpeed;
		}

		if (bullets[i]->colFlag == true) {     //�Փ˃t���O��true�̎��A�e������
			delete bullets[i];                 //bullets�̃��������
			bullets.erase(bullets.begin() + i);  //vector�̃R���e�i�̏���
			continue;
		}
		i++;
	}
}

/*
void WayNozzle::WayNozzle1(int setX, int setY, double pibotAngle, int row, int col, int totalAngle, int span, double speed) {
	xy.x = setX;
	xy.y = setY;
	angle = pibotAngle;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			BULLET *tmp = new BULLET();
			tmp->xy = xy;
			tmp->angle = angle - totalAngle / 2 + j * (totalAngle / (col - 1));
			tmp->speed = speed;
			tmp->wait = span * i;
			addbullet(tmp);
		}
	}
}
*/