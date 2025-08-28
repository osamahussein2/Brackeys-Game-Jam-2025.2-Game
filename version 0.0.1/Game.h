#ifndef GAME_H
#define GAME_H

#pragma once

#include "Supernova.h"
#include "Pointer.h"
#include "AmmoDrop.h"
#include "PlayerWeapon.h"
#include "PlayerBullet.h"

#include "MouseCursor.h"

// Include standard libraries
#include <vector>

using namespace Supernova;

class Game
{
public:
	Game(Scene* gameScene, Scene* UI_scene);
	~Game();

	void InitializeGame();
	void UpdateGame();

	void HideGame();

	void ResetGame();

	Vector2 GetPlayerCenterPoint() const;

	void CleanGame();

private:
	void HandlePlayerInput();

	void IterateThroughVisibleAmmo();

	void HandleWeapons();
	void SwitchBetweenWeapons();

	void HandleAmmoCollisions();

	void UpdatePlayerBullets();

private:
	Camera camera;

	float x, y;
	float velocityX, velocityY;

	Pointer pointer;

	Audio gameMusic;

	bool musicPlaying;

	std::array<AmmoDrop, 4> ammoDrops;

	std::array<PlayerWeapon, 4> playerWeapons;

	float shootDelay;

	int weaponIndex;

	bool keyPressed;
	bool switchWeaponKeyPressed;

	std::vector<std::unique_ptr<PlayerBullet>> playerBullets;

	Sprite player;

	int frameX;

	static constexpr int playerSizeX = 64;
	static constexpr int playerSizeY = 80;
};

#endif