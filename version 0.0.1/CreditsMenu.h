#ifndef CREDITSMENU_H
#define CREDITSMENU_H

#pragma once

#include "Supernova.h"

#include "MouseCursor.h"

using namespace Supernova;

class CreditsMenu
{
public:
	CreditsMenu(Scene* scene);
	~CreditsMenu();

	void InitializeCreditsMenu();
	void UpdateCreditsMenu();

	void HideCreditsMenu();

private:
	static void GoBackToMain();

	void UpdateBackButtonInteraction();

private:
	std::array<Button, 2> backButton; // 0 for normal button, 1 for hightlighted (or hovered) button

	static constexpr int buttonSizeX = 200;
	static constexpr int buttonSizeY = 100;
};

#endif