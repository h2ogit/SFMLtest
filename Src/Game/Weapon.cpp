#include "SFML/Graphics.hpp"

#include "Object.h"
#include "DynamicObject.h"
#include "Projectile.h"

#include "Effect.hpp"

#include "Weapon.h"

using namespace game;

void Weapon:: ShowWeapon(const bool ShouldShowWeapon)
{
	if (ShouldShowWeapon) Sprite.setScale(sf::Vector2f(1,1));
		else Sprite.setScale(sf::Vector2f(0,0));
}

void Weapon:: Fire(sf::Vector2f atLoc)
{
	_Effect = new StormBlink();
	_Effect->load();
	_Effect->update(clock.getElapsedTime().asSeconds(), x, y);
}