#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(BulletType bulletType_, Scene* scene_, Vector3 position_, Vector2 direction_) : bulletType(), bullet(scene_),
bulletLifeTime(0.0f), bulletFireSound(scene_)
{
	bulletType = bulletType_;
	position = position_;
	direction = direction_;

	switch (bulletType_)
	{
	case BulletType::PistolBullet:
		bullet.setTexture("Bullets/PistolBullet.png");
		bullet.setSize(30, 30);
		bullet.setPosition(position_);
		bullet.setVisible(true);

		// Initialize bullet fire sound
		bulletFireSound.loadAudio("Sounds/Gunfire.wav");
		bulletFireSound.setSound3D(false);
		bulletFireSound.play();
		break;

	case BulletType::ShotgunBullet:
		bullet.setTexture("Bullets/ShotgunBullet.png");
		bullet.setSize(30, 30);
		bullet.setPosition(position_);
		bullet.setVisible(true);

		// Initialize bullet fire sound
		bulletFireSound.loadAudio("Sounds/Gunfire.wav");
		bulletFireSound.setSound3D(false);
		bulletFireSound.play();
		break;

	case BulletType::MicroSMGBullet:
		bullet.setTexture("Bullets/MicroSMGBullet.png");
		bullet.setSize(30, 30);
		bullet.setPosition(position_);
		bullet.setVisible(true);

		// Initialize bullet fire sound
		bulletFireSound.loadAudio("Sounds/Gunfire.wav");
		bulletFireSound.setSound3D(false);
		bulletFireSound.play();
		break;

	case BulletType::SMGBullet :
		bullet.setTexture("Bullets/SMGBullet.png");
		bullet.setSize(30, 30);
		bullet.setPosition(position_);
		bullet.setVisible(true);

		// Initialize bullet fire sound
		bulletFireSound.loadAudio("Sounds/Gunfire.wav");
		bulletFireSound.setSound3D(false);
		bulletFireSound.play();
		break;

	default:
		break;
	}
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::UpdateBullet()
{
	bullet.setVisible(true);

	bulletLifeTime += 0.016f;

	direction += direction;

	bullet.setPosition(Vector3(position.x + direction.x, position.y + direction.y, position.z));
}

bool PlayerBullet::BulletCollision(Vector2& gameObject_, Vector2& size_)
{
	if (bullet.getPosition().x + 30.0f >= gameObject_.x && bullet.getPosition().x <= gameObject_.x + size_.x &&
		bullet.getPosition().y + 30.0f >= gameObject_.y && bullet.getPosition().y <= gameObject_.y + size_.y)
	{
		return true;
	}

	return false;
}

void PlayerBullet::HideBullet()
{
	bullet.setVisible(false);
}

void PlayerBullet::DestroyBulletComponents()
{
	bulletFireSound.destroyAudio();
}
