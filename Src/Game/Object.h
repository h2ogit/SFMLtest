#ifndef _OBJECT_H
#define _OBJECT_H

namespace game
{
	class Game;

	class Object
	{
		public:
			Object()
			{
				_Game = nullptr;
				_Owner = nullptr;
			}

			virtual void Init(Game* aGamePtr);
			virtual void SetTexture(const std::string &aTex);
			virtual void SetSpriteOrigin(float x, float y);
			virtual void SetText(const std::string &aText);
			virtual void SetLocation(sf::Vector2f aLoc);
			virtual void SetRotation(float aRot);

			virtual void SetOwner(const Object* aNewOwner = nullptr) {_Owner = aNewOwner;};

			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			virtual bool CanCollide();
			virtual void SetCollision(bool bCollide);

			virtual void Destroy();

			virtual void PrepareForDestroy() final;

		protected:
			Game* _Game;

			const Object* _Owner;

			bool bCollideObjects;

			sf::Texture Texture;
			sf::Sprite Sprite;
			sf::Text Text;

			virtual sf::Vector2f Normalize2(sf::Vector2f Vec);

			virtual sf::FloatRect Object::getBoundingRect() const;

			virtual bool Object::CheckCollisionWith(Object* aObj);

			virtual Object* Object::GetCollidedObject();

			bool IsOutOfWorldBound();
	};
};

#endif