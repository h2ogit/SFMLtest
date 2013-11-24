#include "SFML/Graphics.hpp"

#include "Game.h"

#include "Object.h"
#include "DynamicObject.h"

#include "Weapon.h"

#include "Actor.h"

using namespace game;

void Actor::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (_Weapon != nullptr) _Weapon->SetLocation(Sprite.getPosition());
	}

	DynamicObject::Update(aWindow, aDeltaTime);
}

void Actor:: SetWeapon(Weapon* aWeapon, const bool ShouldShowWeapon)
{
	_Weapon = aWeapon; 
	_Weapon->ShowWeapon(ShouldShowWeapon);
}

void Actor:: TakeDamage(int aDamage)
{
	Health -= aDamage;
	if (Health <=0 ) Killed();
}

void Actor:: Killed()
{
	Destroy();
}

void Actor::Destroy()
{
	Health = 0;

	delete _Weapon;
	_Weapon = nullptr;

	DynamicObject::Destroy();
}