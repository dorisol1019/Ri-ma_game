#include"stdafx.h"
int Damage=0;
//BARRAGE::BARRAGE() {}

//
//BARRAGE::BARRAGE(BARRAGE *bar_p, int size) { //コンストラクタ BARRAGEを初期化
//	do {
//		(*bar_p).bu_p = new BULLET();  //メモリ割り当て
//	} while ((*bar_p).bu_p == nullptr); //NULLになるまでloop
//	(*bar_p).end = -1;
//}

//void BARRAGE::Barrageremove(BARRAGE *bar_p) { //BARRAGEを開放
//	delete (*bar_p).bu_p; //BULLETメモリ解放
//}

//void BARRAGE::AddBullet(BARRAGE *bar_p, BULLET bu) { //BARRAGEにBULLETを追加？
//	(*bar_p).end++; //なんか増えてる
//	(*bar_p).bu_p[(*bar_p).end] = bu;
//}

//void BARRAGE::RemoveBullet(BARRAGE *bar_p, int i) {
//	(*bar_p).bu_p[i] = (*bar_p).bu_p[(*bar_p).end];
//	(*bar_p).end--;  //なんか減ってる
//}

/*
void Player::Shot() {
	static int count = 0; //弾の発射頻度を調節する用?
	count++;

	if (count % 15 != 0) { //countを15で割って余りが0の時　15,30,45… にしか撃てないのかな？
		return;
	}

	//BULLET bullet[2];         //自機の撃つ弾幕が2個？
	//bullet[0].xy = player.xy; //プレイヤーの場所
	//bullet[1].xy = player.xy; //プレイヤーの場所　//二つとも同じでいいのかな
	//bullet[0].conFlag = false; //当たり判定
	//bullet[1].conFlag = false; //当たり判定
	//bullet[0].xy.x += 16;      //プレイヤーから16離れた座標から弾幕を放つ？
	//bullet[1].xy.x += -16;     //プレイヤーから-16離れたところから弾幕を放つ?
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


//初期化-------------------------------------
Player::Player() {
	player.xy.x = W / 2;  //プレイヤー自機の初期x座標　　変更可能
	player.xy.y = H - 20; //プレイヤー自機の初期y座標　　変更可能
	player.speed = 5;     //プレイヤー自機のスピード 変更可能
	player.hp = 5;        //プレイヤー自機の残り命　 変更可能
	nozzle = new PlayerNozzle(*this);

	//BARRAGE::BARRAGE(&playerbar, 50); //playerbarを初期化
}

//終了処理-------------------------------
//Player::~Player() {
//	playerbar.Barrageremove(&playerbar);
//}

//プレイヤー情報更新
void Player::Update() {
		if (player.hp <= 0) {            //HPが0の時ゲームオーバー(それはそう)
			//central.ChangeScene(Central::GAMEOVERSCENE); //central.h(ChangeScene,enum GAMEOVER)
			//central.scene = Central::GAMEOVER;
		}
		player.addxy.x = 0; //CHARA型　xの加算の初期化　//必要か？　//コンストラクタにしたい
		player.addxy.y = 0; //CHARA型　yの加算の初期化　//必要か？

		//矢印キー(上下左右)で移動-----------------------------------------
		//上移動
		if (keySystem.Givekey(KEY_INPUT_UP) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.y = -1;          //上矢印で座標を一個上に
		}
		//下移動
		if (keySystem.Givekey(KEY_INPUT_DOWN) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.y = 1;          //下矢印で座標を一個上に
		}
		//左移動
		if (keySystem.Givekey(KEY_INPUT_LEFT) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.x = -1;          //左矢印で座標を一個上に
		}
		//右移動
		if (keySystem.Givekey(KEY_INPUT_RIGHT) != 0) { //key_out.h(keySystem.Givekey) 
			player.addxy.x = 1;          //右矢印で座標を一個上に
		}

		if (player.addxy.x != 0 || player.addxy.y != 0) { //要するに方向キーを押したとき
			double distance = sqrt(player.addxy.x*player.addxy.x + player.addxy.y*player.addxy.y); //√(x^2+y^2) 三平方の定理　斜めの距離？ 
			player.xy.x += player.addxy.x / distance*player.speed; //プレイヤーのx座標＝移動回数×移動スピード/距離 
			player.xy.y += player.addxy.y / distance*player.speed; //プレイヤーのy座標＝移動回数×移動スピード/距離

			//画面からのはみ出し制限
			//x座標
			if (player.xy.x > W - 16) {
				player.xy.x = W - 16;  //一定数以上は一定になる(日本語)  //これは自分の画面の大きさに合わせて変更しなければならない　//このために後で画面の大きさを決めよう
			}
			if (player.xy.x < 0) {
				player.xy.x = 0;   //DxLibの座標は一番左上に原点があるのでこっちは変更しなくてよい
			}

			//y座標
			if (player.xy.y > H - 16) {
				player.xy.y = H - 16; //一定以上は一定になる
			}
			if (player.xy.y < 0) {
				player.xy.y = 0;  //Dxlibの原点
			}
		}

		//ショット-------------------------------------
		//if (keySystem.Givekey(KEY_INPUT_Z) != 0) {  //Zを押したとき自機はショットを撃つ
		//	Shot();     //直下に定義あります
		//}

		//HP表示
		//sprintf_s(hps, "HP:%d", player.hp);  //ちょっとこの関数知らない
		//drawSystem.SetChar(hps, 10, 400);//draw_out.h (文字列,表示するx座標,表示するｙ座標 )
		
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

	

		//プレイヤー表示-------------------------
		drawSystem.SetChar("自", player.xy.x, player.xy.y);
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



void BULLET::update() {//自分の座標に画像を表示

	drawSystem.SetChar("Enemy HP", 0, 0);
	DrawFormatString(0, 16, GetColor(255, 255, 255), "%d", Damage);
	
	DrawRotaGraph(xy.x, xy.y, 1, angle, gHandle, true);
	xy.x += speed*cos(angle*PI/180);
	xy.y += speed*sin(angle*PI/180);
	drawSystem.SetChar("弾", xy.x, xy.y);

	//x座標 消滅
	if (xy.x < 0 || xy.x>500) {
		colFlag = true;
	}
	//y座標 消滅
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
	for (int i = 0; i < bullets.size();) {//現在のbulletの要素の数が帰って来る

		if (frameCount>bullets[i]->wait) {    //frameCountを超えたら
			bullets[i]->update();    //発射
		}
		else {
			bullets[i]->angle += deltaAngle;
			bullets[i]->speed += deltaSpeed;
		}

		if (bullets[i]->colFlag == true) {     //衝突フラグがtrueの時、弾幕消滅
			delete bullets[i];                 //bulletsのメモリ解放
			bullets.erase(bullets.begin() + i);  //vectorのコンテナの消去
			continue;
		}
		i++;
	}
	if (bullets.size() == 0) {
		end = true;
	}
}


void Player::Myplayer() {   //自機からの弾幕 //うーん、動かない
	//nozzle = new PlayerNozzle(*this);
	//if (keySystem.Givekey(KEY_INPUT_Z) == 1) { //Zが押されてるとき
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
	drawSystem.SetChar("敵", xy.x, xy.y);
}

//hファイルデexternで宣言した変数・関数は、cppファイル内デ改めて宣言する
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

	for (int i = 0; i < bullets.size();) {//現在のbulletの要素の数が帰って来る

		if (frameCount>bullets[i]->wait) {    //frameCountを超えたら
			bullets[i]->update();    //発射
		}
		else {
			bullets[i]->angle += deltaAngle;
			bullets[i]->speed += deltaSpeed;
		}

		if (bullets[i]->colFlag == true) {     //衝突フラグがtrueの時、弾幕消滅
			delete bullets[i];                 //bulletsのメモリ解放
			bullets.erase(bullets.begin() + i);  //vectorのコンテナの消去
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