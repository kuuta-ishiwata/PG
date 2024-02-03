#include "PlayerBullet.h"
#include "Novice.h"


void PlayerBullet::Initialize(
    float speed, Vector2& position, const char* keys, const char* preKeys) {
	Pos_ = position;

	SavePosition_ = position;

	radius_ = {40.0f, 40.0f};

	keys_ = keys;

	preKeys_ = preKeys;

	speed_ = speed;
}

void PlayerBullet::Update(Vector2& position) {
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		isShot = true;
	}

	if (isShot == true) {
		Pos_.y = Pos_.y - speed_;
	}

	if (Pos_.y + radius_.y <= -150) {
		Pos_ = position;
		isShot = false;
	}
}

void PlayerBullet::Draw() {
	if (isShot == true)
	{
		Novice::DrawBox( (int)Pos_.x, (int)Pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, WHITE,kFillModeSolid);
	
	}
}

void PlayerBullet::OnCollision(Vector2& position) {
	Pos_ = position;
	isShot = false;
}

Vector2 PlayerBullet::GetRadius() {
	Vector2 radius;

	radius.x = radius_.x;
	radius.y = radius_.y;
	return radius;
}

Vector2 PlayerBullet::GetPosition() {
	Vector2 pos;

	pos.x = Pos_.x;
	pos.y = Pos_.y;
	return pos;
}
