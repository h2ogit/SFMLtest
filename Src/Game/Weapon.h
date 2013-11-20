#ifndef _WEAPON_H
#define _WEAPON_H

namespace game
{
	class Projectile;

	class Weapon : public Actor
	{
		public:
			int& GetDamage() {return Damage;};
			void SetDamage(int aValue) {Damage = aValue;};

			int& GetFireRate() {return FireRate;};
			void SetFireRate(int aValue) {FireRate = aValue;};

			void SetProjectile(Projectile* aProjectile) {_Projectile = aProjectile;};

		private:
			int Damage;
			int FireRate;
			Projectile* _Projectile;
	};

};

#endif