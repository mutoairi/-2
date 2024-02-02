#include "Player.h"
#include<Novice.h>

Player::Player() {
	pos_ = { 100,360 };
	speed_ = 10;
	radius_ = 30;
	isAlive_ = true;
	PlayerGH = Novice::LoadTexture("./Resources/Player.png");
	bullet_ = new Bullet;
}
Player::~Player() {
	delete bullet_;
}
void Player::Update(char* keys, char* preKeys,int Alive) {
	isAlive_ = Alive;
	

	if (isAlive_) {
		if (keys[DIK_W]) {
			pos_.y -= speed_;
		}
		if (keys[DIK_S]) {
			pos_.y += speed_;
		}
		if (keys[DIK_A]) {
			pos_.x -= speed_;
		}
		if (keys[DIK_D]) {
			pos_.x += speed_;
		}
		if (pos_.x <= 30) {
			pos_.x = 30;
		}
		if (pos_.y <= 30) {
			pos_.y = 30;
		}

		if (pos_.x >= 1250) {
			pos_.x = 1250;
		}

		if (pos_.y >=690 ) {
			pos_.y = 690;
		}

		if (!bullet_->GetIsHit()) {
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

				bullet_->SetPos(pos_.x, pos_.y);
				bullet_->SetisHit(true);

			}
		}

		bullet_->Update();
	}
}


void Player::SetIsHit(int Alive) {
	bullet_->SetisHit(Alive);
}
void Player::Draw(int Alive) {
	isAlive_ = Alive;
	
	bullet_->Draw();
	if (isAlive_) {
		Novice::DrawSprite(int(pos_.x-radius_*2), int(pos_.y-radius_*2),PlayerGH ,1, 1, 0.0f, 0xFFFFFFFF);
	}
	Novice::ScreenPrintf(100, 100, "%d", bullet_->GetIsHit());

}