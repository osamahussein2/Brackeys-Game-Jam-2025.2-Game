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

void Pointer::UpdatePointer(Vector2& playerPos_, Vector2& target_, Vector2 offset_)
{
	// Set the rotation of the pointer to look at where the target is in relation to the player
	float angle_rad = std::atan2(target_.y - playerPos_.y, target_.x - playerPos_.x);
	float angle_deg = angle_rad * (180 / M_PI);

	// Move and rotate the pointer around
	pointerImage.setPosition(playerPos_.x + offset_.x, playerPos_.y + offset_.y, 0.0f);
	pointerImage.setRotation(0.0f, 0.0f, angle_deg);

	// Find the distance between the player and target to set pointer visibility
	float dx = playerPos_.x - target_.x;
	float dy = playerPos_.y - target_.y;
	float distance = std::sqrtf(dx * dx + dy * dy);

	if (distance > 20.0f)
	{
		if (!pointerImage.isVisible()) pointerImage.setVisible(true);
	}

	else
	{
		if (pointerImage.isVisible()) pointerImage.setVisible(false);
	}
}

void Pointer::HidePointer()
{
	if (pointerImage.isVisible()) pointerImage.setVisible(false); // Make the pointer invisible if needed
}