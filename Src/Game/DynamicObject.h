#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

namespace game
{
	class DynamicObject : public Object
	{
		public:
			virtual int& GetSpeed() {return Speed;};
			virtual void SetSpeed(int aValue) {Speed = aValue;};

			virtual void Move(sf::Vector2f aValue) {MoveDest = aValue;};

		protected:
			int Speed;
			sf::Vector2f MoveDest;
	};
};

#endif