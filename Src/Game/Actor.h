#ifndef _ACTOR_H
#define _ACTOR_H

namespace game
{
	class Actor
	{
		public:
			Actor();
			~Actor();
			virtual void Update(sf::RenderWindow* aWindow);

		protected:
			sf::Vector2f MoveDir;
	};

};

#endif