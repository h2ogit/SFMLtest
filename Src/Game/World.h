#ifndef _WORLD_H
#define _WORLD_H

namespace game
{
	class Object;
	class EnemySpawner;

	class World
	{
		public:
			World()
			{
				_Game = nullptr;
				_Background = nullptr;
				_EnemySpawner = nullptr;
			}

			void Init(Game* aGamePtr);
			void StartWorld();

			void InitPlayer(Player* aPlayer);

			void UpdateWorld(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

		private:
			Game* _Game;
			Object* _Background;
			EnemySpawner* _EnemySpawner;

		protected:


	};
};

#endif