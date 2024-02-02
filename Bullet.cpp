#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	pos_={ -400,-400 };
	radius_ = 10;
	speed_ = 20;
	isHit_ = false;
	BulletGH = Novice::LoadTexture("./Resources/Bullet.png");
}

Bullet::~Bullet() {};


void Bullet::Update() {
	if (isHit_) {
		pos_.x += speed_;
	}
	if (pos_.x >= 1290) {
		isHit_ = false;
	}
}

void Bullet::SetPos(float posx,float posy) {
	pos_.x = posx;
	pos_.y = posy;
}

void Bullet::SetisHit(int Alive) {
	isHit_ = Alive;
}

void Bullet::Draw() {
	if (isHit_) {
		Novice::DrawSprite(int(pos_.x-radius_*2), int(pos_.y-radius_*2),BulletGH, 0.5f, 0.5f, 0.0f, 0xFFFFFFFF);
	}
}