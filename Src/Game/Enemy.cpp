#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"

#include "Enemy.h"

using namespace game;

void Enemy:: Init(Game* aGamePtr)
{
	Actor::Init(aGamePtr);
	wW = _Game->_Settings->wWidh;
	wH = _Game->_Settings->wHeight;
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

void Enemy:: Activate()
{
	SetLocation(GetRandomLocation());
	SetMoveLocation(GetRandomLocation());
	SetRotation(GetRandomRotation());
}


void Enemy:: Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if ( (!bMoving) && (bMoveFinished) && (Health >0) )
	{
		SetMoveLocation(GetRandomLocation());
	}

	Actor::Update(aWindow, aDeltaTime);
}
