#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#pragma once

#include "Supernova.h"

#include "MouseCursor.h"

using namespace Supernova;

class PauseMenu
{
public:
	PauseMenu(Scene* scene);
	~PauseMenu();

	void InitializePauseMenu();
	void UpdatePauseMenu();

	void HidePauseMenu();

private:
	static void ResumeGame();
	static void QuitToMain();

	void UpdateResumeButtonInteraction();
	void UpdateQuitButtonInteraction();

	void SwitchBetweenMenuOption();

	void HandleInput();

private:
	Text pauseTitleText;

	std::array<Button, 2> resumeButton; // 0 for normal button, 1 for hightlighted (or hovered) button
	std::array<Button, 2> quitButton; // 0 for normal button, 1 for hightlighted (or hovered) button

	static constexpr int buttonSizeX = 150;
	static constexpr int buttonSizeY = 75;

	int selectedOption;

	bool keyPressed;
};

#endif