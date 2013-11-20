#include "SFML/Graphics.hpp"
#include "Game.h"
#include "World.h"
#include "Input.h"

#include "Object.h"
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
	_Render->setVerticalSyncEnabled(true);

	ScreenCenter = sf::Vector2f(wWidh, wHeight);

	ResPath = "../Res/";
	std::string lNewFont = ResPath+"sansation.ttf";
	if (!Font.loadFromFile(lNewFont)) log("ERROR::Load::Font::"+lNewFont);

	_Input = new Input();
	_Input->Init(this);
}

const std::string* Game::GetResPath()
{
	return &ResPath;
}

const sf::Font& Game::GetFont()
{
	return Font;
}

int Game::Start()
{
	_World = new World();
	_World->Init(this);
	_World->StartWorld();

	_Player = dynamic_cast<Player*>(Spawn(new Player(), "aimcross.png"));

	bRuning = true;

	while (bRuning)
	{
		DeltaTime = GameClock.restart();

		_Render->pollEvent(Event);
		_Input ->ProcessInput(&Event);

		_Render->clear();

		unsigned int vector_size = Objects.size();
		for (unsigned int i = 0; i < vector_size; i++)
		{
			Objects[i]->Update(_Render, &DeltaTime);
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

Object* Game::Spawn(Object* aObj,  const std::string aTexture, const std::string aText, const sf::Vector2f aLoc, const float aRot)
{
	aObj->Init(this);
	aObj->SetTexture(aTexture);
	aObj->SetText(aText);
	aObj->SetLocation(aLoc);
	aObj->SetRotation(aRot);

	Objects.push_back(aObj);
	return aObj;
}

//bool IsInScreenBounds(Vector2f aPos)
//{
//	if ( (aPos.x > 0) && (aPos.x < wWidh) && (aPos.y > 0) && (aPos.y < wHeight) ) return true;
//	else return false;
//}

