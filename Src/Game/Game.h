#ifndef _GAME_H
#define _GAME_H

namespace game
{
	class Player;
	class Input;
	class Map;
	class Actor;
	class Projectile;

	class Game
	{
		public:
			
			Player* _Player;

			Input* _Input;
			Map* _Map;

			Game();
			~Game();

			int Start();
			void Stop();
			void log(const std::string &msg);

			std::string GetResPath();
			sf::Font GetFont();

			std::vector<Actor> Actors;
			std::vector<Projectile> Projectiles;

			Actor* Spawn(Actor aActor,  const std::string aTexture, const std::string aText = " ", const sf::Vector2f aLoc = sf::Vector2f (0,0), const float aRot = 0.f);

		private: 
			bool bRuning;

			std::string ResPath;

			sf::Font _Font;
			sf::Event _Event;
			sf::RenderWindow* _Render;
			sf::Clock GameClock;
			sf::Time DeltaTime;

	};
};

#endif