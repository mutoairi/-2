#pragma once
#include "Vector2.h"
class Bullet
{
private:
	Vector2 pos_;
	float speed_;
	float radius_;
	int isHit_;
	int BulletGH;
public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
	float GetposX() { return pos_.x; }
	float GetposY() { return pos_.y; }
	float GetRadius() { return radius_; }
	int GetIsHit() { return isHit_; }
	void SetPos(float,float);
	void SetisHit(int);
	
};

