#include "SFML/Graphics.hpp"

#include "Object.h"
#include "Actor.h"
#include "Player.h"

#include "Game.h"
#include "Input.h"

using namespace game;

void Player:: Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	sf::Vector2f mousepos =_Game->_Input->GetMousePos();
	SetLocation(mousepos);


	Actor::Update(aWindow, aDeltaTime);
}