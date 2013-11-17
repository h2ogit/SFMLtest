#ifndef _GAME_H
#define _GAME_H

namespace game
{
	class Game
	{

	public:
		sf::RenderWindow _Render;


		int Start();
		void log(const std::string &msg);

	private: 
		bool bRuning;


	};
};

#endif