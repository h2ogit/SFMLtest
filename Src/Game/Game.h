#ifndef _GAME_H
#define _GAME_H

namespace sf
{
  class RenderWindow;
  class Event;
};

namespace game
{
	class Input;

	class Game
	{
		public:
			sf::RenderWindow _Render;
			sf::Event _Event;

			Input* _Input;

			Game();
			~Game();
			int Start();
			void log(const std::string &msg);

		private: 
			bool bRuning;

	};
};

#endif