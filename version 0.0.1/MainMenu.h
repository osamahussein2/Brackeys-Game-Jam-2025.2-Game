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

	void HideMainMenu();

	void StopMenuMusic();

	void CleanMainMenuComponents();

private:
	static void PlayGame();
	static void Credits();
	static void QuitGame();

	void UpdatePlayButtonInteraction();
	void UpdateCreditsButtonInteraction();
	void UpdateQuitButtonInteraction();

	void SwitchBetweenMenuOption();

	void HandleInput();

private:
	std::array<Button, 2> playButton; // 0 for normal button, 1 for hightlighted (or hovered) button
	std::array<Button, 2> creditsButton; // 0 for normal button, 1 for hightlighted (or hovered) button
	std::array<Button, 2> quitButton; // 0 for normal button, 1 for hightlighted (or hovered) button

	Audio menuMusic;

	bool musicPlaying;

	static constexpr int buttonSizeX = 150;
	static constexpr int buttonSizeY = 75;

	int selectedOption;

	bool keyPressed;

	static bool firstTimePlaying;
};

#endif