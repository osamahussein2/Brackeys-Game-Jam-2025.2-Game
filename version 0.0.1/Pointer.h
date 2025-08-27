#ifndef POINTER_H
#define POINTER_H

#pragma once

#include "Supernova.h"

#include <cmath>
#include <math.h>

using namespace Supernova;

class Pointer
{
public:
	Pointer(Scene* scene);
	~Pointer();

	void InitializePointer(std::string filePath_);
	void UpdatePointer(Vector2& playerPos_, Vector2& target_, Vector2 offset_);

	void HidePointer();

private:
	

private:
	Image pointerImage;

	static constexpr int pointerSizeX = 100;
	static constexpr int pointerSizeY = 50;
};

#endif