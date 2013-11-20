#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Actor.h"
#include "Projectile.h"
#include "Map.h"

using namespace game;

void Map:: Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void Map:: StartMap()
{
	_Background = _Game->Spawn(new Actor(), "back.jpg");
	_Background->SetSpriteOrigin(0,0);


}