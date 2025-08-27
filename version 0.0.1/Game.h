#ifndef GAME_H
#define GAME_H

#pragma once

#include "Supernova.h"
#include "Pointer.h"
#include "AmmoDrop.h"

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



private:
	void HandlePlayerInput();

	void IterateThroughVisibleAmmo();

private:
	Camera camera;

	float x, y;

	Pointer pointer;

	Audio gameMusic;

	bool musicPlaying;

	std::array<AmmoDrop, 4> ammoDrops;
};

#endif