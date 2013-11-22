#include "SFML/Graphics.hpp"
#include "SFML/Window/Event.hpp"

#include "Game.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"
#include "Player.h"

#include "Input.h"

using namespace game;

void Input::Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void Input::ProcessInput(sf::Event* aEvent)
{
	if (aEvent->type == sf::Event::MouseMoved)
	{
		MousePos.x = aEvent->mouseMove.x;
		MousePos.y = aEvent->mouseMove.y;
	}
	//if (aEvent.type == sf::Event::MouseButtonPressed) MouseButtonPressed(aEvent.mouseButton);
	if (aEvent->type == sf::Event::MouseButtonReleased) MouseButtonReleased();

	if (aEvent->type == sf::Event::Closed)
	{
		_Game->Stop();
	}
}

sf::Vector2f Input::GetMousePos()
{
	//float MouseX = sf::Mouse::getPosition(_Render).x;
 //   float MouseY = sf::Mouse::getPosition(_Render).y;
	//return sf::Vector2f(MouseX, MouseY);
	return MousePos;
}

void Input::MouseButtonReleased()
{
	_Game->_Player->Fire();
}


		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ZloPos.y = -1;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ZloPos.y = 1;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ZloPos.x = -1;
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ZloPos.x = 1;