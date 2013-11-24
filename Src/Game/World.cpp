#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "Object.h"
#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"

#include "EnemySpawner.h"

#include "World.h"

using namespace game;

void World:: Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void World:: StartWorld()
{
	_Background = new Object();
	_Background->Init(_Game);
	_Background->SetTexture(_Game->_Settings->WorldBackgroundTexture);
	_Background->SetSpriteOrigin(0,0);
	_Background->SetCollision(false);

	_EnemySpawner = new EnemySpawner();
	_EnemySpawner->Init(_Game);
}

void World:: UpdateWorld(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (_Background != nullptr) _Background->Update(aWindow, aDeltaTime);
		if (_EnemySpawner != nullptr) _EnemySpawner->Update(aDeltaTime);
	}
}

void World:: InitPlayer(Player* aPlayer)
{
	aPlayer->Init(_Game);
	aPlayer->SetTexture(_Game->_Settings->AimTexture);
	aPlayer->SetCollision(false);
	aPlayer->SetHealth(_Game->_Settings->PlayerHealth);
	aPlayer->SetSpeed(_Game->_Settings->PlayerSpeed);
	Weapon* lWeapon = dynamic_cast<Weapon*>(_Game->Spawn(new Weapon(), _Game->_Settings->Weapon1Texture, false));
	lWeapon->SetDamage(_Game->_Settings->Weapon1Damage);
	lWeapon->SetFireRate(_Game->_Settings->Weapon1FireRate);
	lWeapon->SetWeaponType(Weapon::EWeaponType::EWT_Gun);
	lWeapon->SetOwner(aPlayer);
	Projectile* lProjectileTemplate = new Projectile();
	lProjectileTemplate->Init(_Game);
	lProjectileTemplate->SetCollision(false);
	lProjectileTemplate->SetDamage(lWeapon->GetDamage());
	lProjectileTemplate->SetTexture(_Game->_Settings->Weapon1ProjectileTexture);
	lProjectileTemplate->SetSpeed(_Game->_Settings->Weapon1ProjectileSpeed);
	lProjectileTemplate->SetOwner(lWeapon);
	lProjectileTemplate->SetInstantHit(true);
	lWeapon->SetProjectile(lProjectileTemplate);
	aPlayer->SetWeapon(lWeapon, false);
}