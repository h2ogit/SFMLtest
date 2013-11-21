#ifndef _PROJECTILE_H
#define _PROJECTILE_H

namespace game
{
	class Projectile : public DynamicObject
	{
		public:
			Projectile()
			{
				bActivated = false;
			}

			void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);
			void SerActive(bool bAct) {bActivated = bAct;};

		private:
			bool bActivated;
	};

};

#endif