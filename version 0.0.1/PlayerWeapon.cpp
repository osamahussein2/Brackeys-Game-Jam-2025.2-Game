#include "PlayerWeapon.h"

PlayerWeapon::PlayerWeapon(Scene* scene) : weapon(scene), weaponHUDText(scene), weaponType(), clipsInMagazine(0),
maxClips(0), totalAmmo(0)
{
}

PlayerWeapon::~PlayerWeapon()
{
}

void PlayerWeapon::InitializeWeapon(WeaponType weaponType_)
{
	weaponType = weaponType_;

	switch (weaponType_)
	{
	case WeaponType::Pistol:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/Pistol.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-30.0f);
		weaponHUDText.setPositionYOffset(75.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 8;
		clipsInMagazine = maxClips;

		totalAmmo = 0;

		break;

	case WeaponType::Shotgun:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/Shotgun.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-30.0f);
		weaponHUDText.setPositionYOffset(75.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 4;
		clipsInMagazine = 0;

		totalAmmo = 0;
		break;

	case WeaponType::MicroSMG:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/MicroSMG.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-30.0f);
		weaponHUDText.setPositionYOffset(75.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 25;
		clipsInMagazine = 0;

		totalAmmo = 0;
		break;

	case WeaponType::SMG:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/SMG.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-30.0f);
		weaponHUDText.setPositionYOffset(75.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 30;
		clipsInMagazine = 0;

		totalAmmo = 0;
		break;

	default:
		break;
	}
}

void PlayerWeapon::UpdateWeapon()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:
		
		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 48) totalAmmo = 48; // Set max ammo for pistol

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::Shotgun:
		
		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 24) totalAmmo = 24; // Set max ammo for shotgun

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::MicroSMG:
		
		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 100) totalAmmo = 100; // Set max ammo for micro SMG

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::SMG:

		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 120) totalAmmo = 120; // Set max ammo for SMG

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	default:
		break;
	}
}

void PlayerWeapon::HideWeapons()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		break;

	case WeaponType::Shotgun:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		break;

	case WeaponType::MicroSMG:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		break;

	case WeaponType::SMG:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		break;

	default:
		break;
	}
}

void PlayerWeapon::ResetWeapons()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:

		if (maxClips != 8) maxClips = 8;
		if (clipsInMagazine != maxClips) clipsInMagazine = maxClips;

		if (totalAmmo != 0) totalAmmo = 0;

		break;

	case WeaponType::Shotgun:

		if (maxClips != 4) maxClips = 4;
		if (clipsInMagazine != 0) clipsInMagazine = 0;

		if (totalAmmo != 0) totalAmmo = 0;

		break;

	case WeaponType::MicroSMG:

		if (maxClips != 25) maxClips = 25;
		if (clipsInMagazine != 0) clipsInMagazine = 0;

		if (totalAmmo != 0) totalAmmo = 0;

		break;

	case WeaponType::SMG:
		
		if (maxClips != 30) maxClips = 30;
		if (clipsInMagazine != 0) clipsInMagazine = 0;

		if (totalAmmo != 0) totalAmmo = 0;

		break;

	default:
		break;
	}
}

void PlayerWeapon::ShootWeapon()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:

		if (clipsInMagazine > 0) clipsInMagazine -= 1;

		break;

	case WeaponType::Shotgun:

		if (clipsInMagazine > 0) clipsInMagazine -= 1;

		break;

	case WeaponType::MicroSMG:

		if (clipsInMagazine > 0) clipsInMagazine -= 1;

		break;

	case WeaponType::SMG:

		if (clipsInMagazine > 0) clipsInMagazine -= 1;

		break;

	default:
		break;
	}
}

void PlayerWeapon::ReloadWeapon()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:
		
		if (clipsInMagazine < maxClips && totalAmmo > 0)
		{
			totalAmmo -= maxClips - clipsInMagazine;
			clipsInMagazine = maxClips;
		}

		break;

	case WeaponType::Shotgun:

		if (clipsInMagazine < maxClips && totalAmmo > 0)
		{
			totalAmmo -= maxClips - clipsInMagazine;
			clipsInMagazine = maxClips;
		}

		break;

	case WeaponType::MicroSMG:

		if (clipsInMagazine < maxClips && totalAmmo > 0)
		{
			totalAmmo -= maxClips - clipsInMagazine;
			clipsInMagazine = maxClips;
		}

		break;

	case WeaponType::SMG:

		if (clipsInMagazine < maxClips && totalAmmo > 0)
		{
			totalAmmo -= maxClips - clipsInMagazine;
			clipsInMagazine = maxClips;
		}

		break;

	default:
		break;
	}
}

void PlayerWeapon::IncreaseAmmo(int ammoValue_)
{
	// Give the player more ammo if their ammo is either above 0 or is 0 but have at least 1 clip left
	if (totalAmmo > 0 || totalAmmo <= 0 && clipsInMagazine > 0) totalAmmo += ammoValue_;

	// Instead, give the player the maximum amount of clips in the magazine when they run out of ammo
	else if (totalAmmo <= 0 && clipsInMagazine <= 0) clipsInMagazine = maxClips;
}