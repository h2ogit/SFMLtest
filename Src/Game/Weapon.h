#ifndef _WEAPON_H
#define _WEAPON_H

namespace game
{
	class Projectile;

	class Weapon : public Object
	{
		public:
			Weapon()
			{
				_Projectile = nullptr;
			}

			enum EWeaponType
			{
				EWT_Gun,
				EWT_Riffle,
			};

			int& GetDamage() {return Damage;};
			void SetDamage(int aValue) {Damage = aValue;};

			float& GetFireRate() {return FireRate;};
			void SetFireRate(float aValue) {FireRate = aValue;};

			EWeaponType& GetWeaponType() {return WeaponType;};
			void SetWeaponType(EWeaponType aWeaponType) {WeaponType = aWeaponType;};

			Projectile* GetProjectile() {return _Projectile;};
			void SetProjectile(Projectile* aProjectile) {_Projectile = aProjectile;};

			void ShowWeapon(const bool ShouldShowWeapon);

			void Fire(sf::Vector2f atLoc);

			virtual void Destroy();

		private:
			int Damage;
			float FireRate;
			Projectile* _Projectile;

			EWeaponType WeaponType;
	};

};

#endif