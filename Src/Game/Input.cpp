#include "Input.h"
#include "Game.h"
#include "SFML/Graphics.hpp"

using namespace game;

Input::Input(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void Input::ProcessInput(sf::Event aEvent)
{
	if (aEvent.type == sf::Event::MouseMoved)
	{
		MousePos.x = aEvent.mouseMove.x;
		MousePos.y = aEvent.mouseMove.y;
	}
	//if (aEvent.type == sf::Event::MouseButtonPressed) MouseButtonPressed(aEvent.mouseButton);
	//if (aEvent.type == sf::Event::MouseButtonReleased) MouseButtonReleased(aEvent.mouseButton);
	if (aEvent.type == sf::Event::Closed) _Game->_Render.close();
}

sf::Vector2f* Input::GetMousePos()
{
	//float MouseX = sf::Mouse::getPosition(_Render).x;
 //   float MouseY = sf::Mouse::getPosition(_Render).y;
	//return sf::Vector2f(MouseX, MouseY);
	return &MousePos;
}