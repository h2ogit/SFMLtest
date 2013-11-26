#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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
	Projectile* lProj = dynamic_cast<Projectile*>(_Game->Spawn(new Projectile(*_Projectile), "red_dot.png", true, this, Sprite.getPosition(), Sprite.getRotation()));
	lProj->Fire(atLoc);
	Sound.play();
}

void Weapon::Destroy()
{
	if (_Projectile != nullptr)
	{
		delete _Projectile;
		_Projectile =  nullptr;
	}

	Object::Destroy();
}