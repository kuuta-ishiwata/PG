#include "Player.h"
#include"Novice.h"
#include"MATH.h"

Player::~Player() 
{
	for (PlayerBullet* bullet : playerbullets_)
	{
		delete bullet;
	}
}

void Player::Initialize(const char* keys, const char* preKeys) {
	
	Pos_ = {540.0f, 400.0f};

	radius_ = {40.0f, 40.0f};

	speed_ = 4.0f;

	keys_ = keys;

	preKeys_ = preKeys;

	
}

void Player::Update() 
{
	if (keys_[DIK_D]) {
		Pos_.x += speed_;
	} 
	if (keys_[DIK_A]) {
		Pos_.x -= speed_;
	}
	

	if (keys_[DIK_S]) {
		Pos_.y -= speed_;
	}
	if (keys_[DIK_W]) {
		Pos_.y -= speed_;
	}

	Attack();
	for (PlayerBullet* bullet : playerbullets_) 
	{
		bullet->Update(Pos_);
	}
}

void Player::Draw()
{
	Novice::DrawBox((int)Pos_.x, (int)Pos_.y, (int)radius_.x, (int)radius_.y, 0.0f, BLACK, kFillModeSolid);

	for (PlayerBullet* bullet : playerbullets_) {
		bullet->Draw();
	}
}

void Player::Attack()
{
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE])
	{

		const float bulletspeed = 8.0f;
		PlayerBullet* newbullet = new PlayerBullet();
		newbullet->Initialize(bulletspeed, Pos_, keys_, preKeys_);

		playerbullets_.push_back(newbullet);
	}
}

Vector2 Player::GetPosition() 
{
	Vector2 pos;

	pos.x = Pos_.x;
	pos.y = Pos_.y;
	return pos;
}