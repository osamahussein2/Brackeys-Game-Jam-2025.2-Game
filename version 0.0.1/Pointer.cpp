#include "Pointer.h"

Pointer::Pointer(Scene* scene) : pointerImage(scene)
{
}

Pointer::~Pointer()
{
}

void Pointer::InitializePointer(std::string filePath_)
{
	// Set up the pointer image
	pointerImage.setTexture(filePath_);
	pointerImage.setSize(pointerSizeX, pointerSizeY);

	pointerImage.setVisible(false);
}

void Pointer::UpdatePointer(Vector2& playerPos_, Vector2& target_)
{
	// Set the rotation of the pointer to look at where the target is in relation to the player
	float angle_rad = std::atan2(target_.y - playerPos_.y, target_.x - playerPos_.x);
	float angle_deg = angle_rad * (180 / M_PI);

	// Move the pointer around
	pointerImage.setPosition(target_.x - playerPos_.x, target_.y - playerPos_.y, 0.0f);
	pointerImage.setRotation(0.0f, 0.0f, angle_deg);

	// Clamp the pointer to be in the screen
	/*if (target_.x - playerPos_.x <= 100.0f) pointerImage.setPosition(100.0f, target_.y - playerPos_.y, 0.0f);
	
	else if (target_.x - playerPos_.x + pointerSizeX >= 950.0f)
	{
		pointerImage.setPosition(850.0f, target_.y - playerPos_.y, 0.0f);
	}

	if (target_.y - playerPos_.y <= 70.0f) pointerImage.setPosition(target_.x - playerPos_.x, 70.0f, 0.0f);
	
	else if (target_.y - playerPos_.y + pointerSizeY >= 550.0f)
	{
		pointerImage.setPosition(target_.x - playerPos_.x, 500.0f, 0.0f);
	}*/

	// Find the distance between the player and target to set pointer visibility
	float dx = playerPos_.x - target_.x;
	float dy = playerPos_.y - target_.y;
	float distance = std::sqrtf(dx * dx + dy * dy);

	if (distance <= 10.0f)
	{
		if (pointerImage.isVisible()) pointerImage.setVisible(false);
	}

	else
	{
		if (!pointerImage.isVisible()) pointerImage.setVisible(true);
	}
}

void Pointer::HidePointer()
{
	if (pointerImage.isVisible()) pointerImage.setVisible(false); // Make the pointer invisible if needed
}
