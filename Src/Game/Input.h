#ifndef _INPUT_H
#define _INPUT_H

namespace game
{
	class Input
	{
		public:
			Input(Game* aGamePtr);
			~Input();
			void ProcessInput(sf::Event aEvent);
			sf::Vector2f* GetMousePos();
		private:
			Game* _Game;
			sf::Vector2f MousePos;
		protected:

	};
};

#endif