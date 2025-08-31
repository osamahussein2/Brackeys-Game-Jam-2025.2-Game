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

void Pointer::UpdatePointer(Vector2& playerPos_, Vector2& target_, float distanceValue_)
{
	// Set the rotation of the pointer to look at where the target is in relation to the player
	float angle_rad = std::atan2(target_.y - playerPos_.y, target_.x - playerPos_.x);
	float angle_deg = angle_rad * (180.0f / M_PI);

	// Move and rotate the pointer around
	pointerImage.setPosition(target_.x, target_.y, 0.0f);
	pointerImage.setRotation(0.0f, 0.0f, angle_deg);

	ClampPointerToScreen(playerPos_, target_);

	// Find the distance between the player and target to set pointer visibility
	float dx = playerPos_.x - target_.x;
	float dy = playerPos_.y - target_.y;
	float distance = std::sqrtf(dx * dx + dy * dy);

	if (distance > distanceValue_)
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

void Pointer::ClampPointerToScreen(Vector2& playerPos_, Vector2& target_)
{
	// Clamp the pointer to be in the screen
	if (pointerImage.getPosition().x >= playerPos_.x + 440.0f)
	{
		if (pointerImage.getPosition().y >= playerPos_.y + 235.0f) // Check if the camera is at the top left of the screen
		{
			pointerImage.setPosition(playerPos_.x + 440.0f, playerPos_.y + 235.0f, 0.0f);
		}

		else if (pointerImage.getPosition().y <= playerPos_.y - 150.0f) // Check if the camera is at the bottom left of the screen
		{
			pointerImage.setPosition(playerPos_.x + 440.0f, playerPos_.y - 150.0f, 0.0f);
		}

		else pointerImage.setPosition(playerPos_.x + 440.0f, target_.y, 0.0f);
	}

	else if (pointerImage.getPosition().x <= playerPos_.x - 330.0f)
	{
		if (pointerImage.getPosition().y >= playerPos_.y + 235.0f) // Check if the camera is at the top right of the screen
		{
			pointerImage.setPosition(playerPos_.x - 330.0f, playerPos_.y + 235.0f, 0.0f);
		}

		else if (pointerImage.getPosition().y <= playerPos_.y - 150.0f) // Check if the camera is at the bottom right of the screen
		{
			pointerImage.setPosition(playerPos_.x - 330.0f, playerPos_.y - 150.0f, 0.0f);
		}

		else pointerImage.setPosition(playerPos_.x - 330.0f, target_.y, 0.0f);
	}
	
	if (pointerImage.getPosition().y >= playerPos_.y + 235.0f)
	{
		// Check if the camera is at the top of the screen only
		if (pointerImage.getPosition().x < playerPos_.x + 440.0f &&
			pointerImage.getPosition().x > playerPos_.x - 330.0f)
		{
			pointerImage.setPosition(target_.x, playerPos_.y + 235.0f, 0.0f);
		}
	}

	else if (pointerImage.getPosition().y <= playerPos_.y - 150.0f)
	{
		// Check if the camera is at the bottom of the screen only
		if (pointerImage.getPosition().x < playerPos_.x + 440.0f &&
			pointerImage.getPosition().x > playerPos_.x - 330.0f)
		{
			pointerImage.setPosition(target_.x, playerPos_.y - 150.0f, 0.0f);
		}
	}
}