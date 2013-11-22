#include "SFML/Graphics.hpp"

#include "Object.h"
#include "DynamicObject.h"
#include "Projectile.h"

#include "Game.h"

#include "Weapon.h"

using namespace game;

void Weapon:: ShowWeapon(const bool ShouldShowWeapon)
{
	if (ShouldShowWeapon) Sprite.setScale(sf::Vector2f(1,1));
		else Sprite.setScale(sf::Vector2f(0,0));
}

void Weapon:: Fire(sf::Vector2f atLoc)
{
	Projectile* lProj = dynamic_cast<Projectile*>(_Game->Spawn(new Projectile(*_Projectile), "red_dot.png", true, "", Sprite.getPosition(), Sprite.getRotation()));
	lProj->SetOwner(this);
	lProj->Fire(atLoc);
}