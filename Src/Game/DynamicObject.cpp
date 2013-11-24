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
			if (IsDestinationReached())
			{
				bMoving = false;
				bMoveFinished = true;
			}

			sf::Vector2f movepoint = Speed * Normalize2(MoveDest - Sprite.getPosition()) * aDeltaTime->asSeconds();

			Move(movepoint);
		}
		Object::Update(aWindow, aDeltaTime);
	}
}

void DynamicObject::Destroy()
{
	Speed = 0;
	bMoving = false;

	Object::Destroy();
}

void DynamicObject::Move(sf::Vector2f aLoc)
{
	Sprite.move(aLoc);
}

bool DynamicObject::IsDestinationReached()
{
	sf::Vector2f v1, v2;
	v1 = Sprite.getPosition();
	v2 = MoveDest;
	if ( (abs(v1.x - v2.x) <= 5) && (abs(v1.y - v2.y) <= 5) ) return true;
	else return false;
}