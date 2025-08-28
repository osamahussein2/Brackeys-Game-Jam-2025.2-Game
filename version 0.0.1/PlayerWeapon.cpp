#include "PlayerWeapon.h"
#include "Global.h"

PlayerWeapon::PlayerWeapon(Scene* scene) : weapon(scene), weaponHUDText(scene), weaponType(), clipsInMagazine(0),
maxClips(0), totalAmmo(0), ammoHUDs{ {{scene, scene}, {scene, scene}} }
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
		weaponHUDText.setPositionXOffset(-40.0f);
		weaponHUDText.setPositionYOffset(110.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 8;
		clipsInMagazine = maxClips;

		totalAmmo = 0;

		ammoHUDs[0].clear();
		ammoHUDs[1].clear();

		ammoHUDs[0].reserve(maxClips);
		ammoHUDs[1].reserve(maxClips);

		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			ammoHUDs[0][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[0][i].setPositionXOffset(-90.0f + (i * 10.0f));
			ammoHUDs[0][i].setPositionYOffset(80.0f);
			ammoHUDs[0][i].setTexture("Ammo/AmmoEmptyUI.png");
			ammoHUDs[0][i].setSize(5, 20);
			ammoHUDs[0][i].setVisible(false);
		}

		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			ammoHUDs[1][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[1][i].setPositionXOffset(-90.0f + (i * 10.0f));
			ammoHUDs[1][i].setPositionYOffset(80.0f);
			ammoHUDs[1][i].setTexture("Ammo/AmmoUI.png");
			ammoHUDs[1][i].setSize(5, 20);
			ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::Shotgun:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/Shotgun.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-40.0f);
		weaponHUDText.setPositionYOffset(110.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 4;
		clipsInMagazine = 0;

		totalAmmo = 0;

		totalAmmo = 0;

		ammoHUDs[0].clear();
		ammoHUDs[1].clear();

		ammoHUDs[0].reserve(maxClips);
		ammoHUDs[1].reserve(maxClips);

		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			ammoHUDs[0][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[0][i].setPositionXOffset(-65.0f + (i * 10.0f));
			ammoHUDs[0][i].setPositionYOffset(80.0f);
			ammoHUDs[0][i].setTexture("Ammo/AmmoEmptyUI.png");
			ammoHUDs[0][i].setSize(5, 20);
			ammoHUDs[0][i].setVisible(false);
		}

		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			ammoHUDs[1][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[1][i].setPositionXOffset(-65.0f + (i * 10.0f));
			ammoHUDs[1][i].setPositionYOffset(80.0f);
			ammoHUDs[1][i].setTexture("Ammo/AmmoUI.png");
			ammoHUDs[1][i].setSize(5, 20);
			ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::MicroSMG:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/MicroSMG.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-40.0f);
		weaponHUDText.setPositionYOffset(110.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 25;
		clipsInMagazine = 0;

		totalAmmo = 0;

		ammoHUDs[0].clear();
		ammoHUDs[1].clear();

		ammoHUDs[0].reserve(maxClips);
		ammoHUDs[1].reserve(maxClips);

		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			ammoHUDs[0][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[0][i].setPositionXOffset(-130.0f + (i * 5.0f));
			ammoHUDs[0][i].setPositionYOffset(80.0f);
			ammoHUDs[0][i].setTexture("Ammo/AmmoEmptyUI.png");
			ammoHUDs[0][i].setSize(1, 20);
			ammoHUDs[0][i].setVisible(false);
		}

		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			ammoHUDs[1][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[1][i].setPositionXOffset(-130.0f + (i * 5.0f));
			ammoHUDs[1][i].setPositionYOffset(80.0f);
			ammoHUDs[1][i].setTexture("Ammo/AmmoUI.png");
			ammoHUDs[1][i].setSize(1, 20);
			ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::SMG:
		weapon.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weapon.setPositionXOffset(-20.0f);
		weapon.setPositionYOffset(10.0f);
		weapon.setTexture("Weapons/SMG.png");
		weapon.setSize(60, 60);
		weapon.setVisible(false);

		weaponHUDText.setAnchorPreset(AnchorPreset::TOP_RIGHT);
		weaponHUDText.setPositionXOffset(-40.0f);
		weaponHUDText.setPositionYOffset(110.0f);
		weaponHUDText.setFontSize(25);
		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));
		weaponHUDText.setVisible(false);

		maxClips = 30;
		clipsInMagazine = 0;

		totalAmmo = 0;

		ammoHUDs[0].clear();
		ammoHUDs[1].clear();

		ammoHUDs[0].reserve(maxClips);
		ammoHUDs[1].reserve(maxClips);

		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);
		ammoHUDs[0].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			ammoHUDs[0][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[0][i].setPositionXOffset(-140.0f + (i * 4.5f));
			ammoHUDs[0][i].setPositionYOffset(80.0f);
			ammoHUDs[0][i].setTexture("Ammo/AmmoEmptyUI.png");
			ammoHUDs[0][i].setSize(1, 20);
			ammoHUDs[0][i].setVisible(false);
		}

		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);
		ammoHUDs[1].emplace_back(&Global::UI_scene);

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			ammoHUDs[1][i].setAnchorPreset(AnchorPreset::TOP_RIGHT);
			ammoHUDs[1][i].setPositionXOffset(-140.0f + (i * 4.5f));
			ammoHUDs[1][i].setPositionYOffset(80.0f);
			ammoHUDs[1][i].setTexture("Ammo/AmmoUI.png");
			ammoHUDs[1][i].setSize(1, 20);
			ammoHUDs[1][i].setVisible(false);
		}

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

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (!ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(true);
		}

		UpdatePistolAmmoHUD();

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 48) totalAmmo = 48; // Set max ammo for pistol

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::Shotgun:
		
		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 24) totalAmmo = 24; // Set max ammo for shotgun

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (!ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(true);
		}

		UpdateShotgunAmmoHUD();

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::MicroSMG:
		
		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 100) totalAmmo = 100; // Set max ammo for micro SMG

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (!ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(true);
		}

		UpdateMicroSMGAmmoHUD();

		weaponHUDText.setText(std::to_string(clipsInMagazine) + "-" + std::to_string(totalAmmo));

		break;

	case WeaponType::SMG:

		if (!weapon.isVisible()) weapon.setVisible(true);
		if (!weaponHUDText.isVisible()) weaponHUDText.setVisible(true);

		if (totalAmmo < 0) totalAmmo = 0;
		else if (totalAmmo > 120) totalAmmo = 120; // Set max ammo for SMG

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (!ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(true);
		}

		UpdateSMGAmmoHUD();

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

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(false);
		}

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			if (ammoHUDs[1][i].isVisible()) ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::Shotgun:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(false);
		}

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			if (ammoHUDs[1][i].isVisible()) ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::MicroSMG:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(false);
		}

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			if (ammoHUDs[1][i].isVisible()) ammoHUDs[1][i].setVisible(false);
		}

		break;

	case WeaponType::SMG:

		if (weapon.isVisible()) weapon.setVisible(false);
		if (weaponHUDText.isVisible()) weaponHUDText.setVisible(false);

		for (int i = 0; i < ammoHUDs[0].size(); i++)
		{
			if (ammoHUDs[0][i].isVisible()) ammoHUDs[0][i].setVisible(false);
		}

		for (int i = 0; i < ammoHUDs[1].size(); i++)
		{
			if (ammoHUDs[1][i].isVisible()) ammoHUDs[1][i].setVisible(false);
		}

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

void PlayerWeapon::ClearAmmoHUDs()
{
	switch (weaponType)
	{
	case WeaponType::Pistol:

		if (!ammoHUDs[0].empty()) ammoHUDs[0].clear();
		if (!ammoHUDs[1].empty()) ammoHUDs[1].clear();

		break;

	case WeaponType::Shotgun:

		if (!ammoHUDs[0].empty()) ammoHUDs[0].clear();
		if (!ammoHUDs[1].empty()) ammoHUDs[1].clear();

		break;

	case WeaponType::MicroSMG:

		if (!ammoHUDs[0].empty()) ammoHUDs[0].clear();
		if (!ammoHUDs[1].empty()) ammoHUDs[1].clear();

		break;

	case WeaponType::SMG:

		if (!ammoHUDs[0].empty()) ammoHUDs[0].clear();
		if (!ammoHUDs[1].empty()) ammoHUDs[1].clear();

		break;

	default:
		break;
	}
}

void PlayerWeapon::UpdatePistolAmmoHUD()
{
	switch (clipsInMagazine)
	{
	case 0:
		if (ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(false);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 1:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 2:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 3:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 4:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 5:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 6:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 7:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		break;

	case 8:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		break;

	default:
		break;
	}
}

void PlayerWeapon::UpdateShotgunAmmoHUD()
{
	switch (clipsInMagazine)
	{
	case 0:
		if (ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(false);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		break;

	case 1:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		break;

	case 2:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		break;

	case 3:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		break;

	case 4:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		break;

	default:
		break;
	}
}

void PlayerWeapon::UpdateMicroSMGAmmoHUD()
{
	switch (clipsInMagazine)
	{
	case 0:
		if (ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(false);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 1:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 2:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 3:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 4:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 5:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 6:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 7:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 8:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 9:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 10:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 11:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 12:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 13:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 14:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 15:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 16:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 17:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 18:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 19:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 20:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 21:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 22:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 23:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 24:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		break;

	case 25:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		break;

	default:
		break;
	}
}

void PlayerWeapon::UpdateSMGAmmoHUD()
{
	switch (clipsInMagazine)
	{
	case 0:
		if (ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(false);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 1:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(false);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 2:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(false);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 3:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(false);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 4:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(false);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 5:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(false);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 6:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(false);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 7:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(false);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 8:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(false);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 9:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(false);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 10:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(false);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 11:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(false);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 12:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(false);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 13:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(false);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 14:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(false);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 15:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(false);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 16:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(false);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 17:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(false);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 18:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(false);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 19:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(false);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 20:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(false);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 21:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(false);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 22:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(false);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 23:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(false);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 24:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(false);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 25:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(false);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 26:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (!ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(true);
		if (ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(false);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 27:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (!ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(true);
		if (!ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(true);
		if (ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(false);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 28:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (!ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(true);
		if (!ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(true);
		if (!ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(true);
		if (ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(false);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 29:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (!ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(true);
		if (!ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(true);
		if (!ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(true);
		if (!ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(true);
		if (ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(false);
		break;

	case 30:
		if (!ammoHUDs[1][0].isVisible()) ammoHUDs[1][0].setVisible(true);
		if (!ammoHUDs[1][1].isVisible()) ammoHUDs[1][1].setVisible(true);
		if (!ammoHUDs[1][2].isVisible()) ammoHUDs[1][2].setVisible(true);
		if (!ammoHUDs[1][3].isVisible()) ammoHUDs[1][3].setVisible(true);
		if (!ammoHUDs[1][4].isVisible()) ammoHUDs[1][4].setVisible(true);
		if (!ammoHUDs[1][5].isVisible()) ammoHUDs[1][5].setVisible(true);
		if (!ammoHUDs[1][6].isVisible()) ammoHUDs[1][6].setVisible(true);
		if (!ammoHUDs[1][7].isVisible()) ammoHUDs[1][7].setVisible(true);
		if (!ammoHUDs[1][8].isVisible()) ammoHUDs[1][8].setVisible(true);
		if (!ammoHUDs[1][9].isVisible()) ammoHUDs[1][9].setVisible(true);
		if (!ammoHUDs[1][10].isVisible()) ammoHUDs[1][10].setVisible(true);
		if (!ammoHUDs[1][11].isVisible()) ammoHUDs[1][11].setVisible(true);
		if (!ammoHUDs[1][12].isVisible()) ammoHUDs[1][12].setVisible(true);
		if (!ammoHUDs[1][13].isVisible()) ammoHUDs[1][13].setVisible(true);
		if (!ammoHUDs[1][14].isVisible()) ammoHUDs[1][14].setVisible(true);
		if (!ammoHUDs[1][15].isVisible()) ammoHUDs[1][15].setVisible(true);
		if (!ammoHUDs[1][16].isVisible()) ammoHUDs[1][16].setVisible(true);
		if (!ammoHUDs[1][17].isVisible()) ammoHUDs[1][17].setVisible(true);
		if (!ammoHUDs[1][18].isVisible()) ammoHUDs[1][18].setVisible(true);
		if (!ammoHUDs[1][19].isVisible()) ammoHUDs[1][19].setVisible(true);
		if (!ammoHUDs[1][20].isVisible()) ammoHUDs[1][20].setVisible(true);
		if (!ammoHUDs[1][21].isVisible()) ammoHUDs[1][21].setVisible(true);
		if (!ammoHUDs[1][22].isVisible()) ammoHUDs[1][22].setVisible(true);
		if (!ammoHUDs[1][23].isVisible()) ammoHUDs[1][23].setVisible(true);
		if (!ammoHUDs[1][24].isVisible()) ammoHUDs[1][24].setVisible(true);
		if (!ammoHUDs[1][25].isVisible()) ammoHUDs[1][25].setVisible(true);
		if (!ammoHUDs[1][26].isVisible()) ammoHUDs[1][26].setVisible(true);
		if (!ammoHUDs[1][27].isVisible()) ammoHUDs[1][27].setVisible(true);
		if (!ammoHUDs[1][28].isVisible()) ammoHUDs[1][28].setVisible(true);
		if (!ammoHUDs[1][29].isVisible()) ammoHUDs[1][29].setVisible(true);
		break;

	default:
		break;
	}
}
