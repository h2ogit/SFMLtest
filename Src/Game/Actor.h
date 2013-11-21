#ifndef _ACTOR_H
#define _ACTOR_H

namespace game
{
	class Weapon;

	class Actor : public DynamicObject
	{
		public:
			virtual int& GetHealth() {return Health;};
			virtual void SetHealth(int aValue) {Health = aValue;};

			virtual void SetWeapon(Weapon* aWeapon, const bool ShouldShowWeapon);
			virtual Weapon* GetWeapon() {return _Weapon;};

			virtual void TakeDamage(int aDamage);
			virtual void Killed();

			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

		protected:
			int Health;

			Weapon* _Weapon;
	};
};

#endif