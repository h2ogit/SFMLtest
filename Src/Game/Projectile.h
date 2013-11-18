#ifndef _PROJECTILE_H
#define _PROJECTILE_H

namespace game
{
	class Actor;

	class Projectile : public Actor
	{
		public:
			//Projectile(sf::Vector2f aLoc, sf::Vector2f aDir);
			//~Projectile();
			void Init(sf::Vector2f aLoc, sf::Vector2f aDir);
			void Update(sf::RenderWindow* aWindow);
	};

};

#endif