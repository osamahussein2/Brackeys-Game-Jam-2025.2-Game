#include "AmmoDrop.h"
#include "Global.h"

AmmoDrop::AmmoDrop(Scene* scene_) : ammo(scene_), ammoHiddenTime(0.0f), ammoType(), hideAmmo(false)
{
}

AmmoDrop::~AmmoDrop()
{
}

void AmmoDrop::InitializeAmmoDrop(AmmoType ammoType_, Vector3 position_)
{
	ammoType = ammoType_;

	switch (ammoType_)
	{
	case AmmoType::PistolAmmo:
		ammo.setTexture("Ammo/PistolAmmo.png");
		ammo.setSize(60, 60);
		ammo.setPosition(position_);
		ammo.setVisible(false);
		break;

	case AmmoType::ShotgunAmmo:
		ammo.setTexture("Ammo/ShotgunAmmo.png");
		ammo.setSize(60, 60);
		ammo.setPosition(position_);
		ammo.setVisible(false);
		break;

	case AmmoType::MicroSMGAmmo:
		ammo.setTexture("Ammo/MicroSMGAmmo.png");
		ammo.setSize(60, 60);
		ammo.setPosition(position_);
		ammo.setVisible(false);
		break;

	case AmmoType::SMGAmmo:
		ammo.setTexture("Ammo/SMGAmmo.png");
		ammo.setSize(60, 60);
		ammo.setPosition(position_);
		ammo.setVisible(false);
		break;

	default:
		break;
	}
}

void AmmoDrop::UpdateAmmoDrop()
{
	// Set ammo's visibility depending on current state
	if (!ammo.isVisible() && !hideAmmo) ammo.setVisible(true);
	else if (ammo.isVisible() && hideAmmo) ammo.setVisible(false);

	// Start the ammo hidden timer to respawn more ammo after the max time is reached
	if (hideAmmo)
	{
		ammoHiddenTime += 0.016f;

		if (ammoHiddenTime >= 10.0f)
		{
			ammoHiddenTime = 0.0f;
			hideAmmo = false;
		}
	}
}

bool AmmoDrop::AmmoDropCollision(Vector2& player_, Vector2& size_)
{
	// Make sure the collision occurs between the ammo and player while the ammo isn't hidden yet
	if (ammo.getPosition().x + 60.0f >= player_.x && ammo.getPosition().x <= player_.x + size_.x &&
		ammo.getPosition().y + 60.0f >= player_.y && ammo.getPosition().y <= player_.y + size_.y && !hideAmmo)
	{
		return true;
	}

	return false;
}

void AmmoDrop::HideAmmoDrop()
{
	ammo.setVisible(false);
}

void AmmoDrop::SetHideAmmo()
{
	hideAmmo = true;
}

void AmmoDrop::ResetAmmoDropValues()
{
	hideAmmo = false;
	ammoHiddenTime = 0.0f;
}
