#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Game.h"
#include "Settings.h"
#include "HUD.h"

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
	StartTime = 3.0f;
	SpawnTime = 0.33f;
	TimeElapse = 0;
	LastSpawnTime = 0;
	BossTime = 5.0f;
	BossLastSpawnTime = 0.0f;
	WaveTime = 20.0f;
	WaveTimeElapse = 0.0f;
	Wave = 1;
}

void EnemySpawner:: Update(sf::Time* aDeltaTime)
{
	TimeElapse += aDeltaTime->asSeconds();

	if ( ( TimeElapse < StartTime ))
	{
		_Game->_HUD->ShowWaveMessage(Wave, StartTime);
		return;
	}

	if ( ( TimeElapse > (WaveTime +  StartTime + Wave * 1.5) ))
	{
		TimeElapse = 0;
		SpawnTime -= 0.3f;
		BossTime -= 0.2f;
		Wave++;
		return;
	}

	if (LastSpawnTime >= SpawnTime)
	{
		SpawnEnemy();
		LastSpawnTime = 0;
	}
	else LastSpawnTime += aDeltaTime->asSeconds();

	if (BossLastSpawnTime >= BossTime)
	{
		SpawnBoss();
		BossLastSpawnTime = 0;
	}
	else BossLastSpawnTime += aDeltaTime->asSeconds();

}

void EnemySpawner:: SpawnEnemy()
{
	Enemy* lEnemy;

	if (Wave == 1)
	{
		lEnemy = dynamic_cast<Enemy*>(_Game->Spawn(new Enemy(), _Game->_Settings->Enemy1Texture, true, nullptr));
		lEnemy->SetHealth(_Game->_Settings->Enemy1Health);
		lEnemy->SetSpeed(_Game->_Settings->Enemy1Speed);
		lEnemy->SetSound(_Game->_Settings->EnemyDeathSound);
	}

	if (Wave >= 2)
	{
		lEnemy = dynamic_cast<Enemy*>(_Game->Spawn(new Enemy(), _Game->_Settings->Enemy2Texture, true, nullptr));
		lEnemy->SetHealth(_Game->_Settings->Enemy2Health);
		lEnemy->SetSpeed(_Game->_Settings->Enemy2Speed);
		lEnemy->SetSound(_Game->_Settings->EnemyDeathSound);
	}

	lEnemy->Activate();
}

void EnemySpawner:: SpawnBoss()
{
	Enemy* lEnemy;
	lEnemy = dynamic_cast<Enemy*>(_Game->Spawn(new Enemy(), _Game->_Settings->EnemyBossTexture, true, nullptr));
	lEnemy->SetHealth(_Game->_Settings->EnemyBossHealth);
	lEnemy->SetSpeed(_Game->_Settings->EnemyBossSpeed);
	lEnemy->Activate();
	lEnemy->SetText("");
}


