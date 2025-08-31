#ifndef ENEMY_H
#define ENEMY_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

enum class EnemyType
{
	RedEnemy,
	GreenEnemy,
	YellowEnemy,
	BlueEnemy
};

class Enemy
{
public:
	Enemy(Scene* scene);
	~Enemy();

	void InitializeEnemy(EnemyType enemyType_, Vector3 startPosition_);
	void UpdateEnemy(Vector3 goToPath_);

	void CleanEnemy();

	void SetDamaged(float damageValue) { health -= damageValue; }

	void ResetEnemy();

	void HideEnemy();

	Vector2 GetEnemyPosition() const;
	Vector2 GetEnemySize() const;

	Vector2 GetEnemyCenterPoint() const;

	bool GetEnemyCollided(Vector2& entityPos_, Vector2& entitySize_);

	bool IsDead() const { return isDead; }

private:
	Sprite enemy;

	EnemyType enemyType;

	static constexpr float maxHealth = 100.0f;

	float health;
	float enemySpeed;

	bool isDead;

	Vector3 startPosition;
	Vector3 directionPath;
	
	float enemySizeX;
	float enemySizeY;

	int frameX;
};

#endif