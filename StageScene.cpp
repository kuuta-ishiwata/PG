#include "StageScene.h"
#include "Novice.h"

void StageScene::Initialize() 
{
	player_ = std::make_unique<Player>();
	player_->Initialize(keys_, prekeys_);

	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update() 
{
	Novice::ScreenPrintf(640, 500, "StageScene");

	if (enemy_->IsActive()) {
		sceneNo = Clear;
	}

	player_->Update();
	enemy_->Update();

	CheckOnCollision();
}

void StageScene::Draw() 
{
	player_->Draw();
	enemy_->Draw();
}

void StageScene::CheckOnCollision() 
{
	const std::list<PlayerBullet*>& PlayerBullets = player_->GetBullet();

	Vector2 PosA, PosB, PosC, RadiusA, RadiusB;

	PosC = player_->GetPosition();

	PosB = enemy_->GetPosition();

	RadiusB = enemy_->GetRadius();

	for (PlayerBullet* Bullet : PlayerBullets) {

		PosA = Bullet->GetPosition();

		RadiusA = Bullet->GetRadius();

		if (PosA.x <= PosB.x + RadiusB.x && PosB.x <= PosA.x + RadiusA.x &&
		    PosA.y <= PosB.y + RadiusB.y && PosB.y <= PosA.y + RadiusA.y) {
			Bullet->OnCollision(PosC);

			enemy_->OnCollision();
		}
	}
}
