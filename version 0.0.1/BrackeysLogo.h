#ifndef BRACKEYSLOGO_H
#define BRACKEYSLOGO_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

class BrackeysLogo
{
public:
	BrackeysLogo(Scene* scene);
	~BrackeysLogo();

	void InitializeBrackeysLogo();
	void UpdateBrackeysLogo();

	void CleanBrackeysLogo();

private:
	void HideBrackeysLogo();

private:
	Sprite brackeysLogo;

	bool animationStarted;

	float frameNumber;

	static constexpr float animationSpeed = 6.0f;
};

#endif