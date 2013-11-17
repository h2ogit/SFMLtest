#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "Actor.h"

namespace game
{
	class Projectile : public Actor
	{
		public:
			sf::CircleShape PlasmaBall;

			Projectile(sf::Vector2f aLoc, sf::Vector2f aDir);
			~Projectile();
			void Update(sf::RenderWindow* aWindow);
	};

};

#endif // _PROJECTILE_H