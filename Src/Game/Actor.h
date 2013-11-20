#ifndef _ACTOR_H
#define _ACTOR_H

namespace game
{
	class Weapon;

	class Actor : public Object
	{
		public:
			virtual int& GetHealth() {return Health;};
			virtual void SetHealth(int aValue) {Health = aValue;};

			virtual int& GetSpeed() {return Speed;};
			virtual void SetSpeed(int aValue) {Speed = aValue;};

			virtual void Move(sf::Vector2f aValue) {MoveDest = aValue;};

			virtual void SetWeapon(Weapon* aWeapon) {_Weapon = aWeapon;};

		protected:
			int Health;
			int Speed;

			Weapon* _Weapon;

			sf::Vector2f MoveDest;
	};
};

#endif