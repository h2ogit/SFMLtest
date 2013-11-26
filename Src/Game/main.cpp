#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Game.h"

using namespace game;

Game* _Game;

int main()
{
	_Game = new Game();
	return _Game->Start();
}