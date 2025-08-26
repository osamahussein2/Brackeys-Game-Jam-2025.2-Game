#include "Global.h"

GameState Global::gameState = GameState::SupernovaEngine;
bool Global::escapeKeyPressed = false;
bool Global::enterKeyPressed = false;

Supernova::Scene Global::scene;
Supernova::Scene Global::UI_scene;