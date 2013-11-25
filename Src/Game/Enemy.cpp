#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"

#include "Enemy.h"

#include <math.h>

using namespace game;

void Enemy:: Init(Game* aGamePtr)
{
	Actor::Init(aGamePtr);
	wW = _Game->_Settings->wWidh;
	wH = _Game->_Settings->wHeight;

	words.push_back("read a c++ book");
	words.push_back("use smart pointers");
	words.push_back("learn c++");
	words.push_back("it is c+ basics!");
	words.push_back("use vectors");
	words.push_back("steammancer is pure");
	words.push_back("preproduction neded");
	words.push_back("style is shit");
	words.push_back("i changed engine again");
	//words.push_back("");
}
	
sf::Vector2f Enemy:: GetRandomLocation()
{
	float x = rand() % wW;
	float y = rand() % wH;
	return sf::Vector2f(x,y);
}

float Enemy:: GetRandomRotation()
{
	return rand() % 360;
}

std::string& Enemy:: GetRandomWord()
{
	unsigned int vector_size = words.size();
	unsigned int ret = rand() % vector_size;
	return words[ret];
}

void Enemy:: Activate()
{
	SetLocation(GetRandomLocation());
	SetMoveLocation(GetRandomLocation());
	SetRotation(GetRandomRotation());
	SetText(GetRandomWord());
	Text.setOrigin(-35,-25);
}


void Enemy:: Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if ( (!bMoving) && (bMoveFinished) && (Health >0) )
	{
		SetMoveLocation(GetRandomLocation());
	}

	if (IsOutOfWorldBound())
	{
		Destroy();
		return;
	}

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

			movepoint.x = 500*(rand()%5)*std::sinf(movepoint.x) * aDeltaTime->asSeconds();
			movepoint.y = 500*(rand()%5)*std::sinf(movepoint.y) * aDeltaTime->asSeconds();

			Move(movepoint);
		}
		
		if (&Sprite != nullptr) aWindow->draw(Sprite);
		if (&Text != nullptr)
		{
			Text.setPosition(Sprite.getPosition());
			Text.setRotation(Sprite.getRotation());
			aWindow->draw(Text);
		}
	}
}