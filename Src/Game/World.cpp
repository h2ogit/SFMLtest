#include "SFML/Graphics.hpp"

#include "Game.h"
#include "World.h"

#include "Object.h"

using namespace game;

void World:: Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void World:: StartWorld()
{
	_Background = _Game->Spawn(new Object(), "back.jpg");
	_Background->SetSpriteOrigin(0,0);


}