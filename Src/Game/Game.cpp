#include <string>
#include <iostream>
#include "Game.h"
#include "Actor.h"
#include "Projectile.h"
#include "SFML/Graphics.hpp"

using namespace game;

const int wWidh = 1024;
const int wHeight = 768;
const std::string gamename = "NewMan killer";

void Game::log(const std::string &msg)
{
	std::cout << msg << std::endl;
}

int Game::Start()
{
	_Render = sf::RenderWindow(sf::VideoMode(wWidh, wHeight), gamename);
	_Render.setMouseCursorVisible(false);

	// Create some text to draw on top of our OpenGL object
    Font font;
    if (!font.loadFromFile(ResPath+"sansation.ttf"))
        return EXIT_FAILURE;
    Text text("NewMan Killer v0.1b", font);
    text.setColor(Color(255, 0, 255, 255));
    text.setPosition(wWidh - 300, wHeight-50);

	while (window.isOpen())
	{
		float MouseX = Mouse::getPosition(window).x;
        float MouseY = Mouse::getPosition(window).y;
		Vector2f MousePos = Vector2f(MouseX, MouseY);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonPressed) WeaponStartFire(MousePos);
			if (event.type == Event::MouseButtonReleased) WeaponStopFire(MousePos);
			if (event.type == Event::Closed) window.close();
		}  

		Vector2f NewManPos = GetRandomRuning(NewMan.getPosition());
		NewMan.move(NewManPos);
		//std::cout << "x: " << NewManPos.x << " | y: " << NewManPos.y << endl;

		Vector2f ZloPos(0,0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ZloPos.y = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ZloPos.y = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ZloPos.x = -1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ZloPos.x = 1;
		if (IsInScreenBounds(ZloMan.getPosition() + ZloPos)) ZloMan.move(ZloPos);

		Vector2f NewAimPos;
		if (!IsInScreenBounds(MousePos)) NewAimPos = FixScreenPosition(MousePos);
		else NewAimPos = MousePos;
		Aim.setPosition(NewAimPos);

		window.clear();
		window.draw(SkyBox);
		window.draw(NewMan);
		window.draw(ZloMan);
		for (int i=0; i <10; i++)
		{
			if (Projectiles[i] != nullptr)
			{
				Projectiles[i]->Tick(&window);
			}
		}
		window.draw(Aim);
		window.draw(text);
		window.display();
	}

	return EXIT_SUCCESS;
}

