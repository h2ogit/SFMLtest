#ifndef _PROJECTILE_H
#define _PROJECTILE_H

namespace game
{
	//class Effect;
	class StormBlink;

	class Projectile : public DynamicObject
	{
		public:
			Projectile()
			{
				bActivated = false;
				bPlayEffect = false;
				bInstantHit = false;
				bWasHit = false;
				_Effect = nullptr;
			}

			void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			bool Fire(const sf::Vector2f aLoc = sf::Vector2f(0,0));

			void Destroy();

			void SetDamage(const int aValue = 0) {Damage = aValue;};

			void SetInstantHit(bool bInstHit);

		private:
			bool bActivated;
			bool bInstantHit;
			bool bPlayEffect;
			
			bool bWasHit;

			StormBlink* _Effect;

			void MakeDamage(Object* aTarget);

			void PlayEffects(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			int Damage; //set from weapon
	};

};

#endif