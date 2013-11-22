#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

namespace game
{
	class DynamicObject : public Object
	{
		public:
			DynamicObject()
			{
				bMoving = false;
			}

			virtual int& GetSpeed() {return Speed;};
			virtual void SetSpeed(int aValue) {Speed = aValue;};

			virtual void SetMoveLocation(sf::Vector2f aValue) {MoveDest = aValue; bMoving = true;};

			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

		protected:
			int Speed;
			sf::Vector2f MoveDest;

			bool bMoving;
	};
};

#endif