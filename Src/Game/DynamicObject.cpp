#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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

			sf::Vector2f movepoint = float(Speed) * Normalize2(MoveDest - Sprite.getPosition()) * aDeltaTime->asSeconds();

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

void DynamicObject::Rotate(float aDegree)
{
	Sprite.rotate(aDegree);
}

bool DynamicObject::IsDestinationReached(const float aFactor)
{
	sf::Vector2f v1, v2;
	v1 = Sprite.getPosition();
	v2 = MoveDest;
	if ( (abs(v1.x - v2.x) <= aFactor) && (abs(v1.y - v2.y) <= aFactor) ) return true;
	else return false;
}