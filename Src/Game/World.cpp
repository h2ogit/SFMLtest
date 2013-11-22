#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"

#include "World.h"

using namespace game;

void World:: Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void World:: StartWorld()
{
	_Background = _Game->Spawn(new Object(), _Game->_Settings->WorldBackgroundTexture, false);
	_Background->SetSpriteOrigin(0,0);


}

void World:: InitPlayer(Player* aPlayer)
{
	aPlayer->SetHealth(_Game->_Settings->PlayerHealth);
	aPlayer->SetSpeed(_Game->_Settings->PlayerSpeed);
	Weapon* lWeapon = dynamic_cast<Weapon*>(_Game->Spawn(new Weapon(), _Game->_Settings->Weapon1Texture));
	aPlayer->SetWeapon(lWeapon, false);
	aPlayer->GetWeapon()->SetDamage(_Game->_Settings->Weapon1Damage);
	aPlayer->GetWeapon()->SetFireRate(_Game->_Settings->Weapon1FireRate);
	aPlayer->GetWeapon()->SetWeaponType(Weapon::EWeaponType::EWT_Gun);
	Projectile* lProjectile = dynamic_cast<Projectile*>(_Game->Spawn(new Projectile(), _Game->_Settings->Weapon1ProjectileTexture));
	aPlayer->GetWeapon()->SetProjectile(lProjectile);
	aPlayer->GetWeapon()->GetProjectile()->SetSpeed(_Game->_Settings->Weapon1ProjectileSpeed);

}