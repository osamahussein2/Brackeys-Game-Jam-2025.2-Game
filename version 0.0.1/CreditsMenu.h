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

	void ScrollingCredits();
	void UpdateBackButtonInteraction();

private:
	std::array<Button, 2> backButton; // 0 for normal button, 1 for hightlighted (or hovered) button

	std::array<Text, 7> creditMembersText;

	static constexpr int buttonSizeX = 100;
	static constexpr int buttonSizeY = 100;

	float textPosY;
};

#endif