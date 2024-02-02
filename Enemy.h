#pragma once
#include"Vector2.h"
class Enemy
{
private:
	Vector2 pos_;
	float radius;
	int speed;
	int speed1;
	int EnemyGH;
	

public:
	Enemy();
	~Enemy();
	void Update(int );
	void Draw(int);
	float GetposX() { return pos_.x; }
	float GetposY() { return pos_.y; }
	float GetRadius() { return radius; }
};

