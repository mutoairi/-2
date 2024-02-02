#pragma once
#include "Vector2.h"
#include "Bullet.h"
class Player
{
private:
	Vector2 pos_; 
	float speed_;
	float radius_;
	int isAlive_;
	int PlayerGH;
	Bullet* bullet_;
public:
	Player();
	~Player();
	void Update(char*keys,char*preKeys,int);
	void Draw(int);
	float GetposX() { return pos_.x; }
	float GetposY() { return pos_.y; }
	float GetRadius() { return radius_; }
	float BulletGetposX() { return bullet_->GetposX(); }
	float BulletGetposY() { return bullet_->GetposY(); }
	float BulletGetRadius() { return bullet_->GetRadius(); }
	int GetIsHit() { return bullet_->GetIsHit(); }
	void SetIsHit(int);

};

