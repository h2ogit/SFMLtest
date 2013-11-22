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
				bHitTarget = false;
				_Effect = nullptr;
			}

			void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			bool Fire(const sf::Vector2f aLoc = sf::Vector2f(0,0), const int aDamage = 0);

			void Destroy();

			void SetDamage(int aValue) {Damage = aValue;};

		private:
			bool bActivated;

			bool bHitTarget;

			StormBlink* _Effect;
			//float EffectDurration;

			void HitTarget(Object* aTarget);

			int Damage; //set from weapon
	};

};

#endif