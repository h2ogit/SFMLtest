#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Input.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"

#include "Weapon.h"

#include "Player.h"

using namespace game;

void Player:: Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	sf::Vector2f mousepos =_Game->_Input->GetMousePos();
	SetLocation(mousepos);

	Actor::Update(aWindow, aDeltaTime);
}

void Player:: Fire()
{
	//_Weapon->Fire(Sprite.getPosition());
}