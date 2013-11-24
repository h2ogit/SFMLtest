#ifndef _ENEMYSPAWNER_H
#define _ENEMYSPAWNER_H

namespace game
{
	class EnemySpawner
	{
		public:
			EnemySpawner()
			{
				_Game = nullptr;
			}

			void Init(Game* aGamePtr);
			void Update(sf::Time* aDeltaTime);

		private:
			Game* _Game;

			float StartTime;
			float SpawnTime;
			float LastSpawnTime;
			float TimeElapse;

			void SpawnEnemy();

	};

};

#endif