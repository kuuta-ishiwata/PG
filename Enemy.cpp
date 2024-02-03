#include "Enemy.h"
#include"Novice.h"
#include "MATH.h"

Vector2 Enemy::GetRadius()
{
	Vector2 radius;

	radius.x = radius_.x;
	radius.y = radius_.y;
	return radius;
}

Vector2 Enemy::GetPosition() {
	Vector2 pos;

	pos.x = Pos_.x;
	pos.y = Pos_.y;
	return pos;
}

void Enemy::Initialize()
{
	Pos_ = {600.0f, 150.0f};

	radius_ = {40.0f, 40.0f};

	speed_ = 3.0f;
}

void Enemy::Update() {

	Pos_.x = Pos_.x += speed_;

	if (Pos_.x + radius_.x >= 1280 || Pos_.x <= 0) {
		speed_ = speed_ * -1;
	}
}

void Enemy::Draw() 
{

	Novice::DrawBox((int)Pos_.x, (int)Pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, BLUE, kFillModeSolid);
}

void Enemy::OnCollision()
{ 
	isActive_ = true;
}
