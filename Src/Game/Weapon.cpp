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
	_Effect->update(0.2, atLoc.x, atLoc.y);
}

void Weapon::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (_Effect != nullptr) _Effect->update(aDeltaTime->asSeconds(), 540, 600);
	}

	Object::Update(aWindow, aDeltaTime);
}