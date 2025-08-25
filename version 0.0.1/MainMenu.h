#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include "Supernova.h"
#include "sokol_app.h"

#include "MouseCursor.h"

using namespace Supernova;

class MainMenu
{
public:
	MainMenu(Scene* scene);
	~MainMenu();

	void InitializeMainMenu();
	void UpdateMainMenu();

	std::string GetGameState() const;

private:
	static void PlayGame();
	static void Credits();
	static void QuitGame();

	void UpdatePlayButtonInteraction();
	void UpdateQuitButtonInteraction();

private:
	std::array<Button, 2> playButton; // 0 for normal button, 1 for hightlighted (or hovered) button
	Button creditsButton;
	std::array<Button, 2> quitButton; // 0 for normal button, 1 for hightlighted (or hovered) button

	static std::string gameState;

	bool mouseHovered;
};

#endif