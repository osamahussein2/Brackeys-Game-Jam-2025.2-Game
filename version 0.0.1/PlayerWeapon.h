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

private:
	WeaponType weaponType;
	Image weapon;

	Text weaponHUDText;

	int clipsInMagazine;
	int maxClips;
	int totalAmmo;
};

#endif