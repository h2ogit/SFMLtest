#ifndef _GAME_H
#define _GAME_H

namespace game
{
	class Input;

	class Game
	{
		public:
			sf::RenderWindow* _Render;
			sf::Event _Event;

			Input* _Input;
			Map* _Map;

			Game();
			~Game();
			int Start();
			void Stop();
			void log(const std::string &msg);

			std::vector<Actor*> Actors;
			std::vector<Projectile*> Projectiles;

		private: 
			bool bRuning;

	};
};

#endif