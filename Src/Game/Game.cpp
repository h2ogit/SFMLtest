#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Input.h"
#include "Actor.h"
#include "Projectile.h"
#include "Map.h"

#include <string>
#include <iostream>
#include <vector>

using namespace game;

const int wWidh = 1024;
const int wHeight = 768;
const std::string gamename = "Steammancer2d";

void Game::log(const std::string &msg)
{
	std::cout << msg << std::endl;
}

Game::Game()
{
	_Input = new Input(this);
}

int Game::Start()
{
	_Render = new sf::RenderWindow(sf::VideoMode(wWidh, wHeight), gamename);
	if (&_Render == nullptr)
	{
		log("ERROR: render none");
		return EXIT_FAILURE;
	}
	_Render->setMouseCursorVisible(false);
	bRuning = true;

	while (bRuning)
	{
		_Render->pollEvent(_Event);
		_Input ->ProcessInput(_Event);

		_Render->clear();

		unsigned int vector_size = Actors.size();
		for (int i = 0; i < vector_size; i++)
		{
			Actors[i]->Update(_Render);
		}
		
		_Render->display();	
	}

	return EXIT_SUCCESS;
}

void Game::Stop()
{
	_Render->close();
	bRuning = false;
}

//bool IsInScreenBounds(Vector2f aPos)
//{
//	if ( (aPos.x > 0) && (aPos.x < wWidh) && (aPos.y > 0) && (aPos.y < wHeight) ) return true;
//	else return false;
//}

