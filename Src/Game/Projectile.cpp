#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Object.h"
#include "DynamicObject.h"
#include "Actor.h"

#include "Effect.hpp"

#include "Projectile.h"

using namespace game;

void Projectile::SetInstantHit(bool bInstHit)
{
	bInstantHit = bInstHit;
	bMoving = bInstHit;
}

void Projectile::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (bActivated)
	{
		if (aWindow != nullptr)
		{
			if (IsOutOfWorldBound())
			{
				bActivated = false;
				PrepareForDestroy();
				return;
			}

			Object* Collided = GetCollidedObject();
			if (Collided != nullptr)
			{
				MakeDamage(Collided);
				bWasHit = true;
			}

			if (bInstantHit || bWasHit)
			{
				bMoving = false;
				bActivated = false;
				//PlayEffects(aWindow, aDeltaTime);
				PrepareForDestroy();
				return;
			}

			DynamicObject::Update(aWindow, aDeltaTime);
		}
	}
}

bool Projectile::Fire(sf::Vector2f aLoc)
{
	if ((aLoc != sf::Vector2f(0.f, 0.f)) || bInstantHit )
	{
		SetMoveLocation(aLoc);
		bActivated = true;
		return true;
	}
	return false;
}

void Projectile::MakeDamage(Object* aTarget)
{
	Actor* HitedActor= dynamic_cast<Actor*>(aTarget);
	if (HitedActor != nullptr) HitedActor->TakeDamage(Damage);	
}

void Projectile::Destroy()
{
	bActivated = false;
	bPlayEffect = false;

	if (_Effect != nullptr)
	{
		delete _Effect;
		_Effect = nullptr;
	}

	DynamicObject::Destroy();
}

void Projectile::PlayEffects(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	_Effect = new StormBlink();
	_Effect->load();
	_Effect->update(aDeltaTime->asSeconds(), MoveDest.x, MoveDest.y);
	aWindow->draw(*_Effect);
}