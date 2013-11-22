#ifndef _INPUT_H
#define _INPUT_H

namespace game
{
	class sf::Event;

	class Input
	{
		public:
			//Input();
			//~Input();
			void Init(Game* aGamePtr);
			void ProcessInput(sf::Event* aEvent);
			sf::Vector2f GetMousePos();

		private:
			Game* _Game;
			sf::Vector2f MousePos;

		protected:
			void MouseButtonReleased();
	};
};

#endif