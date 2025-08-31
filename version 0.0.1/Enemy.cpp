#include "Enemy.h"

Enemy::Enemy(Scene* scene) : enemy(scene), health(maxHealth), isDead(false), enemySpeed(0.0f), startPosition(), frameX(0),
enemyType(), directionPath(), enemySizeX(0.0f), enemySizeY(0.0f)
{
}

Enemy::~Enemy()
{
}

void Enemy::InitializeEnemy(EnemyType enemyType_, Vector3 startPosition_)
{
	enemyType = enemyType_;

	startPosition = startPosition_;

	switch (enemyType_)
	{
	case EnemyType::RedEnemy:

		enemy.setTexture("Sprites/PlayerSprite.png");

		for (int j = 0; j < 8; j++)
		{
			enemy.addFrame(j, "", Rect(0.0 / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));
		}

		enemySizeX = 60.0f;
		enemySizeY = 80.0f;

		enemy.setFrame(0);
		enemy.setPosition(startPosition_);
		enemy.setName("Player");
		enemy.setSize(enemySizeX, enemySizeY);

		enemy.setColor(1.0f, 0.0f, 0.0f);

		enemySpeed = 3.0f;

		enemy.startAnimation(0, 7, 150, true);
		enemy.setVisible(false);

		break;

	case EnemyType::GreenEnemy:

		enemy.setTexture("Sprites/PlayerSprite.png");

		for (int j = 0; j < 8; j++)
		{
			enemy.addFrame(j, "", Rect(0.0 / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));
		}

		enemySizeX = 30.0f;
		enemySizeY = 50.0f;

		enemy.setFrame(0);
		enemy.setPosition(startPosition_);
		enemy.setName("Player");
		enemy.setSize(enemySizeX, enemySizeY);

		enemy.setColor(0.0f, 1.0f, 0.0f);

		enemySpeed = 2.0f;

		enemy.startAnimation(0, 7, 150, true);
		enemy.setVisible(false);

		break;

	case EnemyType::YellowEnemy:

		enemy.setTexture("Sprites/PlayerSprite.png");

		for (int j = 0; j < 8; j++)
		{
			enemy.addFrame(j, "", Rect(0.0 / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));
		}

		enemySizeX = 40.0f;
		enemySizeY = 60.0f;

		enemy.setFrame(0);
		enemy.setPosition(startPosition_);
		enemy.setName("Player");
		enemy.setSize(enemySizeX, enemySizeY);

		enemy.setColor(1.0f, 1.0f, 0.0f);

		enemySpeed = 1.5f;

		enemy.startAnimation(0, 7, 150, true);
		enemy.setVisible(false);

		break;

	case EnemyType::BlueEnemy:

		enemy.setTexture("Sprites/PlayerSprite.png");

		for (int j = 0; j < 8; j++)
		{
			enemy.addFrame(j, "", Rect(0.0 / 7, (j + 1.0) / 8, 1.0 / 7, 1.0 / 8));
		}

		enemySizeX = 50.0f;
		enemySizeY = 70.0f;

		enemy.setFrame(0);
		enemy.setPosition(startPosition_);
		enemy.setName("Player");
		enemy.setSize(enemySizeX, enemySizeY);

		enemy.setColor(0.0f, 0.0f, 1.0f);

		enemySpeed = 4.0f;

		enemy.startAnimation(0, 7, 150, true);
		enemy.setVisible(false);

		break;

	default:
		break;
	}
}

void Enemy::UpdateEnemy(Vector3 goToPath_)
{
	switch (enemyType)
	{
	case EnemyType::RedEnemy:
		
		if (!isDead)
		{
			if (!enemy.isVisible()) enemy.setVisible(true);

			directionPath.x += (goToPath_.x - enemy.getPosition().x) * enemySpeed * 0.016f;
			directionPath.y += (goToPath_.y - enemy.getPosition().y) * enemySpeed * 0.016f;
			directionPath.z += (goToPath_.z - enemy.getPosition().z) * enemySpeed * 0.016f;

			float dx = goToPath_.x - enemy.getPosition().x;
			float dy = goToPath_.y - enemy.getPosition().y;
			float distance = std::sqrtf(dx * dx + dy * dy);

			if (distance > 300.0f)
			{
				enemy.setPosition(Vector3(directionPath));
			}

			if (health <= 0.0f) isDead = true;
		}

		else
		{
			if (enemy.isVisible()) enemy.setVisible(false);
		}

		break;

	case EnemyType::GreenEnemy:

		if (!isDead)
		{
			if (!enemy.isVisible()) enemy.setVisible(true);

			directionPath.x += (goToPath_.x - enemy.getPosition().x) * enemySpeed * 0.016f;
			directionPath.y += (goToPath_.y - enemy.getPosition().y) * enemySpeed * 0.016f;
			directionPath.z += (goToPath_.z - enemy.getPosition().z) * enemySpeed * 0.016f;

			float dx = goToPath_.x - enemy.getPosition().x;
			float dy = goToPath_.y - enemy.getPosition().y;
			float distance = std::sqrtf(dx * dx + dy * dy);

			if (distance > 300.0f)
			{
				enemy.setPosition(Vector3(directionPath));
			}

			if (health <= 0.0f) isDead = true;
		}

		else
		{
			if (enemy.isVisible()) enemy.setVisible(false);
		}

		break;

	case EnemyType::YellowEnemy:

		if (!isDead)
		{
			if (!enemy.isVisible()) enemy.setVisible(true);

			directionPath.x += (goToPath_.x - enemy.getPosition().x) * enemySpeed * 0.016f;
			directionPath.y += (goToPath_.y - enemy.getPosition().y) * enemySpeed * 0.016f;
			directionPath.z += (goToPath_.z - enemy.getPosition().z) * enemySpeed * 0.016f;

			float dx = goToPath_.x - enemy.getPosition().x;
			float dy = goToPath_.y - enemy.getPosition().y;
			float distance = std::sqrtf(dx * dx + dy * dy);

			if (distance > 300.0f)
			{
				enemy.setPosition(Vector3(directionPath));
			}

			if (health <= 0.0f) isDead = true;
		}

		else
		{
			if (enemy.isVisible()) enemy.setVisible(false);
		}

		break;

	case EnemyType::BlueEnemy:

		if (!isDead)
		{
			if (!enemy.isVisible()) enemy.setVisible(true);

			directionPath.x += (goToPath_.x - enemy.getPosition().x) * enemySpeed * 0.016f;
			directionPath.y += (goToPath_.y - enemy.getPosition().y) * enemySpeed * 0.016f;
			directionPath.z += (goToPath_.z - enemy.getPosition().z) * enemySpeed * 0.016f;

			float dx = goToPath_.x - enemy.getPosition().x;
			float dy = goToPath_.y - enemy.getPosition().y;
			float distance = std::sqrtf(dx * dx + dy * dy);

			if (distance > 300.0f)
			{
				enemy.setPosition(Vector3(directionPath));
			}

			if (health <= 0.0f) isDead = true;
		}

		else
		{
			if (enemy.isVisible()) enemy.setVisible(false);
		}

		break;

	default:
		break;
	}
}

void Enemy::CleanEnemy()
{
	enemy.clearInstances();
}

void Enemy::ResetEnemy()
{
	switch (enemyType)
	{
	case EnemyType::RedEnemy:

		if (health != maxHealth) health = maxHealth;
		if (isDead != false) isDead = false;

		enemy.setPosition(startPosition);

		break;

	case EnemyType::GreenEnemy:

		if (health != maxHealth) health = maxHealth;
		if (isDead != false) isDead = false;

		enemy.setPosition(startPosition);

		break;

	case EnemyType::YellowEnemy:

		if (health != maxHealth) health = maxHealth;
		if (isDead != false) isDead = false;

		enemy.setPosition(startPosition);

		break;

	case EnemyType::BlueEnemy:

		if (health != maxHealth) health = maxHealth;
		if (isDead != false) isDead = false;

		enemy.setPosition(startPosition);

		break;

	default:
		break;
	}
}

void Enemy::HideEnemy()
{
	if (enemy.isVisible()) enemy.setVisible(false);
}

Vector2 Enemy::GetEnemyPosition() const
{
	return Vector2(enemy.getPosition().x, enemy.getPosition().y);
}

Vector2 Enemy::GetEnemySize() const
{
	return Vector2(enemySizeX, enemySizeY);
}

Vector2 Enemy::GetEnemyCenterPoint() const
{
	return Vector2(enemy.getPosition().x + (enemySizeX / 2.0f), enemy.getPosition().y + (enemySizeY / 2.0f));
}

bool Enemy::GetEnemyCollided(Vector2& entityPos_, Vector2& entitySize_)
{
	switch (enemyType)
	{
	case EnemyType::RedEnemy:

		if (enemy.getPosition().x + enemySizeX >= entityPos_.x && enemy.getPosition().x <= entityPos_.x + entitySize_.x &&
			enemy.getPosition().y + enemySizeY >= entityPos_.y && enemy.getPosition().y <= entityPos_.y + entitySize_.y && 
			!isDead)
		{
			return true;
		}

		break;

	case EnemyType::GreenEnemy:

		if (enemy.getPosition().x + enemySizeX >= entityPos_.x && enemy.getPosition().x <= entityPos_.x + entitySize_.x &&
			enemy.getPosition().y + enemySizeY >= entityPos_.y && enemy.getPosition().y <= entityPos_.y + entitySize_.y &&
			!isDead)
		{
			return true;
		}

		break;

	case EnemyType::YellowEnemy:

		if (enemy.getPosition().x + enemySizeX >= entityPos_.x && enemy.getPosition().x <= entityPos_.x + entitySize_.x &&
			enemy.getPosition().y + enemySizeY >= entityPos_.y && enemy.getPosition().y <= entityPos_.y + entitySize_.y &&
			!isDead)
		{
			return true;
		}

		break;

	case EnemyType::BlueEnemy:

		if (enemy.getPosition().x + enemySizeX >= entityPos_.x && enemy.getPosition().x <= entityPos_.x + entitySize_.x &&
			enemy.getPosition().y + enemySizeY >= entityPos_.y && enemy.getPosition().y <= entityPos_.y + entitySize_.y &&
			!isDead)
		{
			return true;
		}

		break;

	default:
		break;
	}

	return false;
}
