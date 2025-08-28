#ifndef BULLET_H
#define BULLET_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

enum class BulletType
{
	PistolBullet,
	ShotgunBullet,
	MicroSMGBullet,
	SMGBullet
};

class PlayerBullet
{
public:
	PlayerBullet(BulletType bulletType_, Scene* scene_, Vector3 position_, Vector2 direction_);
	~PlayerBullet();

	void UpdateBullet();

	bool BulletCollision(Vector2& gameObject_, Vector2& size_);

	void HideBullet();

	float GetBulletLifeTime() const { return bulletLifeTime; }

private:
	BulletType bulletType;
	Image bullet;

	float bulletLifeTime;

	Vector3 position;
	Vector2 direction;
};

#endif