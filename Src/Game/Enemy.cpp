#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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
	float x = float(rand() % wW);
	float y = float(rand() % wH);
	return sf::Vector2f(x,y);
}

float Enemy:: GetRandomRotation()
{
	return float(rand() % 360);
}

std::string& Enemy:: GetRandomWord()
{
	unsigned int vector_size = words.size();
	unsigned int ret = rand() % vector_size;
	return words[ret];
}

Enemy::EBehavior Enemy:: GetRandomBehavior()
{
	return EBehavior(rand() % 4);
}

void Enemy:: Activate()
{
	SetLocation(GetRandomLocation());
	SetMoveLocation(GetRandomLocation());
	SetRotation(GetRandomRotation());
	SetText(GetRandomWord());
	Text.setOrigin(-35,-25);
	Behavior = GetRandomBehavior();
}


void Enemy:: Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if ( (!bMoving) && (bMoveFinished) && (Health >0) )
	{
		SetMoveLocation(GetRandomLocation());
		Behavior = GetRandomBehavior();
	}

	if (IsOutOfWorldBound())
	{
		_Game->NewmansLost++;

		PrepareForDestroy();

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

			sf::Vector2f movepoint;
			float rotangle = 0;

			switch (Behavior)
			{
				case game::Enemy::EM_Lin:
					movepoint = float(Speed) * Normalize2(MoveDest - Sprite.getPosition()) * aDeltaTime->asSeconds();
				break;

				case game::Enemy::EM_LinRot:
					movepoint = float(Speed) * Normalize2(MoveDest - Sprite.getPosition()) * aDeltaTime->asSeconds();
					rotangle = float((rand() % 100)/100.0f);
				break;

				case game::Enemy::EM_Sin:
					movepoint.x = 5 + 100*(rand()%3)*std::sinf(MoveDest.x) * aDeltaTime->asSeconds();
					movepoint.y = 5 + 100*(rand()%3)*std::sinf(MoveDest.y) * aDeltaTime->asSeconds();
				break;

				case game::Enemy::EM_Cos:
					movepoint.x = 5 + 100*(rand()%3)*std::cosf(MoveDest.x) * aDeltaTime->asSeconds();
					movepoint.y = 5 + 100*(rand()%3)*std::cosf(MoveDest.y) * aDeltaTime->asSeconds();
				break;

				case game::Enemy::EM_Tan:
					movepoint.x = 5 + 100*(rand()%3)*std::tanf(MoveDest.x) * aDeltaTime->asSeconds();
					movepoint.y = 5 + 100*(rand()%3)*std::tanf(MoveDest.y) * aDeltaTime->asSeconds();
				break;

				default:
				break;
			}

			Move(movepoint);
			Rotate(rotangle);
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

void Enemy:: Killed()
{
	_Game->NewmansKilled++;
	Actor::Killed();
	Sound.play();
}