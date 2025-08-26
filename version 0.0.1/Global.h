#ifndef GLOBAL_H
#define GLOBAL_H

#pragma once

#include "Enums.h"
#include "Supernova.h"

struct Global
{
	static GameState gameState;
	static bool escapeKeyPressed;
	static bool enterKeyPressed;

	// Create scene instances
	static Supernova::Scene scene;
	static Supernova::Scene UI_scene;
};

#endif