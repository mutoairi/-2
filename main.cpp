#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1B_28_ムトウアイリ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	
	int PlayerIsAlive = true;
	int EnemyIsAlive = true;
	Player* player = new Player;
	Enemy* enemy = new Enemy;


	float PlayerD1Enemey = 0;
	float PlayerD2Enemy = 0;
	float PlayerD3Enemy = 0;
	float radiusDistance1 = 0;
	
	/*弾と敵*/
	float BulletD1Enemey =0;
	float BulletD2Enemy = 0;
	float BulletD3Enemy = 0;
	float radiusDistance2 =0;
	
	//シーン
	int TitleGh;
	int backGroundGh;
	int GameOverGH;
	int ClearGH;

	TitleGh = Novice::LoadTexture("./Resources/BallTitle.png");
	backGroundGh= Novice::LoadTexture("./Resources/Play.png");
	GameOverGH = Novice::LoadTexture("./Resources/BallGameOver.png");
	ClearGH = Novice::LoadTexture("./Resources/BallClear.png");


	//背景の座標
	float backGroundPosX1 = 0;
	float backGroundPosY1 = 0;
	float backGroundPosX2 = -1280;
	float backGroundPosY2 = 0;
	//スクロールの速さ
	float scrollSpeed = 5;

	int scene = 0;
	enum SCENE {
		Title,
		Game,
		Clear,
		GameOver
	};
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		switch (scene)
		{
		case Title:
			PlayerIsAlive = true;
			EnemyIsAlive = true;
			player = new Player;
			enemy = new Enemy;

			Novice::DrawSprite(0, 0, TitleGh, 1, 1, 0.0f, 0XFFFFFFFF);
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = Game;
			}
			break;
		case Game:

		/// 当たり判定
		/// 
		/*プレイヤーと敵*/
		 PlayerD1Enemey = enemy->GetposX() - player->GetposX();
		 PlayerD2Enemy = enemy->GetposY() - player->GetposY();
		 PlayerD3Enemy = sqrtf(PlayerD1Enemey * PlayerD1Enemey + PlayerD2Enemy * PlayerD2Enemy);
		 radiusDistance1 = enemy->GetRadius() + player->GetRadius();
		if (radiusDistance1 >= PlayerD3Enemy) {
			PlayerIsAlive = false;
		}
		/*弾と敵*/
		 BulletD1Enemey = enemy->GetposX() - player->BulletGetposX();
		 BulletD2Enemy = enemy->GetposY() - player->BulletGetposY();
		 BulletD3Enemy = sqrtf(BulletD1Enemey * BulletD1Enemey + BulletD2Enemy * BulletD2Enemy);
	     radiusDistance2 = enemy->GetRadius() + player->BulletGetRadius();
		if (radiusDistance2 >= BulletD3Enemy) {
			EnemyIsAlive = false;
			player->SetIsHit(false);
		}


		/// 
		player->Update(keys, preKeys,PlayerIsAlive);
		enemy->Update(EnemyIsAlive);

		//背景
		backGroundPosX1 += scrollSpeed;
		backGroundPosX2 += scrollSpeed;
		if (backGroundPosX1 >=1280) {
			backGroundPosX1 = backGroundPosX2 - 1280;
		}
		if (backGroundPosX2 >=1280) {
			backGroundPosX2 = backGroundPosX1- 1280;
		}
		Novice::DrawSprite(int(backGroundPosX1), int(backGroundPosY1), backGroundGh, 1, 1, 0.0f, 0xFFFFFFFF);
		Novice::DrawSprite(int(backGroundPosX2), int(backGroundPosY2), backGroundGh, 1, 1, 0.0f, 0xFFFFFFFF);



		player->Draw( PlayerIsAlive);
		enemy->Draw(EnemyIsAlive);
		if (!PlayerIsAlive) {
			scene = GameOver;
		}
		if (!EnemyIsAlive) {
			scene = Clear;
		}
		break;
		case GameOver:
			Novice::DrawSprite(0, 0, GameOverGH, 1, 1, 0.0f, 0XFFFFFFFF);
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = Title;
			}
			break;
		case Clear:
			Novice::DrawSprite(0, 0, ClearGH, 1, 1, 0.0f, 0XFFFFFFFF);
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = Title;
			}
			break;
	
		default:
			break;
		}

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
