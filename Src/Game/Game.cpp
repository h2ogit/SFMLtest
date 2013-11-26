#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

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

using namespace game;

void Game::log(const std::string &msg)
{
	std::cout << msg << std::endl;
}

Game::~Game()
{
	//delete _Settings;
	//delete _GameMusic;

	delete _World;
	delete _Player;	
	delete _HUD;
	delete _Input;
	delete _Render;

}

Game::Game()
{
	_World = nullptr;
	_Player = nullptr;

	_Settings = pS(Settings)(new Settings());

	_Render = new sf::RenderWindow(sf::VideoMode(_Settings->wWidh, _Settings->wHeight), _Settings->GameName);
	if (_Render == nullptr) log("ERROR: render none");
		
	_Render->setMouseCursorVisible(false);
	_Render->setFramerateLimit(60);
	_Render->setVerticalSyncEnabled(true);

	ScreenCenter = sf::Vector2i(_Settings->wWidh, _Settings->wHeight);

	std::string lNewFont = _Settings->ResPath+_Settings->FontFile;
	if (!Font.loadFromFile(lNewFont)) log("ERROR::Load::Font::"+lNewFont);

	_HUD = new HUD();
	_HUD->Init(this);
	NewmansKilled = 0;
	NewmansLost = 0;
	NewmansLive = 0;

	_Input = new Input();
	_Input->Init(this);

	_GameMusic = pS(sf::Music)(new sf::Music());
	if (!_GameMusic->openFromFile(_Settings->ResPath+_Settings->MusicFile)) log("ERROR::Load::Music");
	_GameMusic->setLoop(true);
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

	_Player = (new Player());
	_World->InitPlayer(_Player);

	bRuning = true;

	_GameMusic->play();

	while (bRuning)
	{
		DeltaTime = GameClock.restart();

		_Render->pollEvent(Event);
		_Input ->ProcessInput(&Event);

		_Render->clear();

		_World->UpdateWorld(_Render, &DeltaTime);

		unsigned int vector_size = Objects.size();
		for (unsigned int i = 0; i < vector_size; i++)
		{
			if (Objects[i] != nullptr) Objects[i]->Update(_Render, &DeltaTime);
		}

		NewmansLive = vector_size;

		_HUD->UpdateHUD(_Render, &DeltaTime);
		
		_Player->Update(_Render, &DeltaTime);
		
		_Render->display();

		ProcessTrash();
	}

	return EXIT_SUCCESS;
}

void Game::Stop()
{
	_Render->close();
	bRuning = false;
}

Object* Game::Spawn(Object* aObj,  const std::string aTexture, const bool bCanCollide, const Object* aOwner, const sf::Vector2f aLoc, const float aRot)
{
	aObj->Init(this);
	aObj->SetTexture(aTexture);
	aObj->SetLocation(aLoc);
	aObj->SetRotation(aRot);
	aObj->SetCollision(bCanCollide);
	aObj->SetOwner(aOwner);

	Objects.push_back(aObj);
	return aObj;
}

void Game::UnSpawn(Object* aObj)
{
	unsigned int vector_size = Objects.size();
	unsigned int delidx = 0;
	for (unsigned int i = 0; i < vector_size; i++)
	{
		if (Objects[i] == aObj)
		{
			delidx = i;
			break;
		}
	}
	Objects.erase(Objects.begin() + delidx);
}

void Game::TrashCollect(Object* aObj)
{
	TrashCollector.push_back(aObj);
}

void Game::ProcessTrash()
{
	unsigned int vector_size = TrashCollector.size();
	for (unsigned int i = 0; i < vector_size; i++)
	{
		TrashCollector[i]->Destroy();
		UnSpawn(TrashCollector[i]);
		delete TrashCollector[i];
	}
	TrashCollector.clear();
}

