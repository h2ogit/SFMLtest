#include "SFML/Graphics.hpp"
#include "Settings.h"
#include "HUD.h"
#include "Game.h"
#include "World.h"
#include "Input.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"
#include "Player.h"
#include "Projectile.h"


#include <iostream>
//#include <vector>

using namespace game;

void Game::log(const std::string &msg)
{
	std::cout << msg << std::endl;
}

Game::Game()
{
	_World = nullptr;
	_Player = nullptr;

	//_Settings = pS(new Settings());
	//_Settings = std::shared_ptr<Settings>(new Settings());
	_Settings = pS(Settings)(new Settings());

	_Render = new sf::RenderWindow(sf::VideoMode(_Settings->wWidh, _Settings->wHeight), _Settings->GameName);
	if (_Render == nullptr) log("ERROR: render none");
		
	_Render->setMouseCursorVisible(false);
	_Render->setFramerateLimit(60);
	_Render->setVerticalSyncEnabled(true);

	ScreenCenter = sf::Vector2f(_Settings->wWidh, _Settings->wHeight);

	std::string lNewFont = _Settings->ResPath+_Settings->FontFile;
	if (!Font.loadFromFile(lNewFont)) log("ERROR::Load::Font::"+lNewFont);

	_HUD = new HUD();
	_HUD->Init(this);

	_Input = new Input();
	_Input->Init(this);
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

	_Player = dynamic_cast<Player*>(Spawn(new Player(), _Settings->AimTexture));
	_World->InitPlayer(_Player);

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

		_HUD->Update(_Render, &DeltaTime);
		
		_Render->display();	
	}

	return EXIT_SUCCESS;
}

void Game::Stop()
{
	_Render->close();
	bRuning = false;
}

Object* Game::Spawn(Object* aObj,  const std::string aTexture, const bool bCanCollide, const std::string aText, const sf::Vector2f aLoc, const float aRot)
{
	aObj->Init(this);
	aObj->SetTexture(aTexture);
	aObj->SetText(aText);
	aObj->SetLocation(aLoc);
	aObj->SetRotation(aRot);

	Objects.push_back(aObj);
	return aObj;
}

void Game::UnSpawn(Object* aObj)
{

}
//bool IsInScreenBounds(Vector2f aPos)
//{
//	if ( (aPos.x > 0) && (aPos.x < wWidh) && (aPos.y > 0) && (aPos.y < wHeight) ) return true;
//	else return false;
//}

