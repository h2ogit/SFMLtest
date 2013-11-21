#ifndef _WEAPON_H
#define _WEAPON_H

namespace game
{
	class Projectile;

	class Weapon : public Object
	{
		public:
			enum EWeaponType
			{
				EWT_Gun,
				EWT_Riffle,
			};

			int& GetDamage() {return Damage;};
			void SetDamage(int aValue) {Damage = aValue;};

			int& GetFireRate() {return FireRate;};
			void SetFireRate(int aValue) {FireRate = aValue;};

			EWeaponType& GetWeaponType() {return WeaponType;};
			void SetWeaponType(EWeaponType aWeaponType) {WeaponType = aWeaponType;};

			Projectile* GetProjectile() {return _Projectile;};
			void SetProjectile(Projectile* aProjectile) {_Projectile = aProjectile;};

			void ShowWeapon(const bool ShouldShowWeapon);

			void Fire(sf::Vector2f atLoc);

		private:
			int Damage;
			int FireRate;
			Projectile* _Projectile;

			Effect* _Effect;

			EWeaponType WeaponType;
	};

};

#endif