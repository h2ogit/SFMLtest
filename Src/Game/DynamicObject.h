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

			virtual int& GetSpeed() {return Speed;};
			virtual void SetSpeed(int aValue) {Speed = aValue;};

			virtual void SetMoveLocation(sf::Vector2f aValue) {MoveDest = aValue; bMoving = true; bMoveFinished = false;};
			
			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			virtual void Destroy();

			bool IsDestinationReached(const float aFactor = 10.0f);
			virtual void Move(sf::Vector2f aLoc);
			virtual void Rotate(float aDegree);

		protected:
			int Speed;
			sf::Vector2f MoveDest;

			bool bMoving;
			bool bMoveFinished;

		private:
			

	};
};

#endif