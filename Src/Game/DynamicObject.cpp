#include "SFML/Graphics.hpp"

#include "Object.h"

#include "DynamicObject.h"

using namespace game;

void DynamicObject::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (bMoving)
		{
			sf::Vector2f movepoint = Normalize2(MoveDest - Sprite.getPosition()) * aDeltaTime->asSeconds() ;
			SetLocation(movepoint);
		}
		Object::Update(aWindow, aDeltaTime);
	}
}