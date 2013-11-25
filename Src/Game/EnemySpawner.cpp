#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"
#include "Enemy.h"

#include "EnemySpawner.h"

#include <iostream>

using namespace game;

void EnemySpawner:: Init(Game* aGamePtr)
{
	_Game = aGamePtr;
	StartTime = 1.0f;
	SpawnTime = 0.25f;
	TimeElapse = 0;
	LastSpawnTime = 0;
}

void EnemySpawner:: Update(sf::Time* aDeltaTime)
{
	TimeElapse += aDeltaTime->asSeconds();
	if ( TimeElapse >= StartTime )
	{
		if (LastSpawnTime >= SpawnTime)
		{
			SpawnEnemy();
			LastSpawnTime = 0;
		}
		else LastSpawnTime += aDeltaTime->asSeconds();

	}
}

void EnemySpawner:: SpawnEnemy()
{
	Enemy* lEnemy;
	lEnemy = dynamic_cast<Enemy*>(_Game->Spawn(new Enemy(), "Newman.png", true, nullptr));
	lEnemy->SetHealth(_Game->_Settings->Enemy1Health);
	lEnemy->SetSpeed(_Game->_Settings->Enemy1Speed);
	lEnemy->Activate();
}


