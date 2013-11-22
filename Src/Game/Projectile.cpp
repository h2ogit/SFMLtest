#include "SFML/Graphics.hpp"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"

#include "Effect.hpp"

#include "Projectile.h"

using namespace game;

void Projectile::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (bActivated)
	{
		if (aWindow != nullptr)
		{
			Object* Collided = GetCollidedObject();
			if (Collided != nullptr) HitTarget(Collided);

			if (bHitTarget)
			{
				if (_Effect != nullptr)
				{
					_Effect->update(aDeltaTime->asSeconds(), MoveDest.x, MoveDest.y);
					aWindow->draw(*_Effect);
				}
			}
			else DynamicObject::Update(aWindow, aDeltaTime);
		}
	}
}

bool Projectile::Fire(sf::Vector2f aLoc, int aDamage)
{
	if (aLoc != sf::Vector2f(0.f, 0.f))
	{
		Damage = aDamage;
		SetMoveLocation(aLoc);
		bMoving = false; //this is instant hit
		bActivated = true;
		return true;
	}
	return false;
}

void Projectile::HitTarget(Object* aTarget)
{
	//_Effect = new StormBlink();
	//_Effect->load();

	bHitTarget = true;
	bMoving = false;

	Actor* HitedActor= dynamic_cast<Actor*>(aTarget);
	if (HitedActor != nullptr) HitedActor->TakeDamage(Damage);

	Destroy();	
}

void Projectile::Destroy()
{
	if (_Effect != nullptr) delete _Effect;

	DynamicObject::Destroy();
}