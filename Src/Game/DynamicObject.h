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
				bMoveFinished = false;
			}

			virtual float& GetSpeed() {return Speed;};
			virtual void SetSpeed(float aValue) {Speed = aValue;};

			virtual void SetMoveLocation(sf::Vector2f aValue) {MoveDest = aValue; bMoving = true; bMoveFinished = false;};
			
			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			virtual void Destroy();

		protected:
			float Speed;
			sf::Vector2f MoveDest;

			bool bMoving;
			bool bMoveFinished;

		private:
			bool IsDestinationReached();
			virtual void Move(sf::Vector2f aLoc);

	};
};

#endif