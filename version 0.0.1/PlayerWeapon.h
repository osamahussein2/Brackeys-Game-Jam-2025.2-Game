#ifndef PLAYERWEAPON_H
#define PLAYERWEAPON_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

enum class WeaponType
{
	Pistol,
	Shotgun,
	MicroSMG,
	SMG
};

class PlayerWeapon
{
public:
	PlayerWeapon(Scene* scene);
	~PlayerWeapon();

	void InitializeWeapon(WeaponType weaponType_);
	void UpdateWeapon();

	void HideWeapons();
	void ResetWeapons();

	void ShootWeapon();
	void ReloadWeapon();

	int GetClipInMagazine() const { return clipsInMagazine; }
	int GetTotalAmmo() const { return totalAmmo; }

	void IncreaseAmmo(int ammoValue_);

	void ClearAmmoHUDs();

private:
	void UpdatePistolAmmoHUD();
	void UpdateShotgunAmmoHUD();
	void UpdateMicroSMGAmmoHUD();
	void UpdateSMGAmmoHUD();

private:
	WeaponType weaponType;

	Image weapon;
	std::array<std::vector<Image>, 2> ammoHUDs;

	Text weaponHUDText;

	int clipsInMagazine;
	int maxClips;
	int totalAmmo;
};

#endif