#ifndef AMMODROP_H
#define AMMODROP_H

#pragma once

#include "Supernova.h"

using namespace Supernova;

enum class AmmoType
{
	PistolAmmo,
	ShotgunAmmo,
	MicroSMGAmmo,
	SMGAmmo
};

class AmmoDrop
{
public:
	AmmoDrop(Scene* scene_);
	~AmmoDrop();

	void InitializeAmmoDrop(AmmoType ammoType_, Vector3 position_);
	void UpdateAmmoDrop();

	bool AmmoDropCollision(Vector2& player_);

	void HideAmmoDrop();

	float GetAmmoHiddenTime() const { return ammoHiddenTime; }

	bool GetHideAmmo() const { return hideAmmo; }
	void SetHideAmmo();

	Vector3 GetAmmoPosition() const { return ammo.getPosition(); }

	void ResetAmmoDropValues();

private:
	AmmoType ammoType;
	Image ammo;

	bool hideAmmo;

	float ammoHiddenTime;
};

#endif