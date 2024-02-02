#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	pos_.x = 800;
	pos_.y = 100;
	radius = 50;
	speed = 20;
	speed1 = 10;
	EnemyGH = Novice::LoadTexture("./Resources/Enemy.png");
}

Enemy::~Enemy() {};

void Enemy::Update(int Alive) {
	if (Alive) {
		pos_.y += speed;
		pos_.x += speed1;
		if (pos_.x - radius <= 0 || pos_.x + radius >= 1280) {
			speed1 *= -1;
		}
		if (pos_.y - radius <= 0 || pos_.y + radius >= 720) {
			speed *= -1;
		}

	}

}
void Enemy::Draw(int Alive) {
	if (Alive) {
		Novice::DrawSprite(int(pos_.x-radius*2), int(pos_.y-radius*2), EnemyGH,1, 1, 0.0f, 0xFFFFFFFF);

	}
}
	

