#include "SFML/Graphics.hpp"

#include "Object.h"
#include "DynamicObject.h"

#include "Projectile.h"

using namespace game;

void Projectile::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (bActivated)
	{
		if (aWindow != nullptr)
		{
		
		}

		DynamicObject::Update(aWindow, aDeltaTime);
	}
}