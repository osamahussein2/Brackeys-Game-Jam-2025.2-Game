#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

class SplashScreen
{
public:
	SplashScreen(Scene* scene);
	~SplashScreen();

	void InitializeSplashScreen();
	void UpdateSplashScreen();

private:
	bool SplashScreenFinished();

private:
	Image supernovaLogo;

	float alpha;
	float timeUntilSwitchImages;
	float whenToShowImage;

	bool alphaStateChanged;
};

#endif