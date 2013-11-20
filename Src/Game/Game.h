#ifndef _GAME_H
#define _GAME_H

namespace game
{
	class Player;
	class Input;
	class Map;
	class Actor;
	class Projectile;

	enum EActorType
	{
		EAT_Actor,
		EAT_Player,
		EAT_Enemy,
		EAT_Projectile,
	};

	class Game
	{
		public:
			
			Player* _Player;

			Input* _Input;
			Map* _Map;

			sf::Vector2f ScreenCenter;

			Game();
			~Game();

			int Start();
			void Stop();
			void log(const std::string &msg);

			const std::string* GetResPath();
			sf::Font& GetFont();

			std::vector<Actor*> Actors;
			std::vector<Projectile> Projectiles;

			Actor* Spawn(Actor* aActor,  const std::string aTexture, const std::string aText = "", const sf::Vector2f aLoc = sf::Vector2f (0,0), const float aRot = 0.f);

		private: 
			bool bRuning;

			std::string ResPath;

			sf::RenderWindow* _Render;
			sf::Font Font;
			sf::Event Event;
			sf::Clock GameClock;
			sf::Time DeltaTime;

	};
};

#endif