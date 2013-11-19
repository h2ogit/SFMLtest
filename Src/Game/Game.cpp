#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Map.h"
#include "Input.h"
#include "Actor.h"
#include "Player.h"
#include "Projectile.h"


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
	_Render = new sf::RenderWindow(sf::VideoMode(wWidh, wHeight), gamename);
	if (_Render == nullptr) log("ERROR: render none");
		
	_Render->setMouseCursorVisible(false);
	_Render->setFramerateLimit(60);

	_Input = new Input();
	_Input->Init(this);
	
	_Map = new Map(this);
	_Map->StartMap();

	ResPath = "../Res/";
	std::string lNewFont = ResPath+"sansation.ttf";
	if (!_Font.loadFromFile(lNewFont)) log("ERROR::Load::Font::"+lNewFont);
}

std::string Game::GetResPath()
{
	return ResPath;
}

sf::Font Game::GetFont()
{
	return _Font;
}

int Game::Start()
{
	_Player = dynamic_cast<Player*>(Spawn(Player(), "aimcross.png"));
	_Player->Init(this);

	bRuning = true;

	DeltaTime = GameClock.restart();

	while (bRuning)
	{
		_Render->pollEvent(_Event);
		_Input ->ProcessInput(&_Event);

		_Render->clear();

		unsigned int vector_size = Actors.size();
		for (unsigned int i = 0; i < vector_size; i++)
		{
			Actors[i].Update(_Render, &DeltaTime);
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

Actor* Game:: Spawn(Actor aActor,  const std::string aTexture, const std::string aText, const sf::Vector2f aLoc, const float aRot)
{
	aActor.SetTexture(aTexture);
	aActor.SetText(aText);
	aActor.SetLocation(aLoc);
	aActor.SetRotation(aRot);
	Actors.push_back(aActor);
	return &Actors.back();
}

//bool IsInScreenBounds(Vector2f aPos)
//{
//	if ( (aPos.x > 0) && (aPos.x < wWidh) && (aPos.y > 0) && (aPos.y < wHeight) ) return true;
//	else return false;
//}

