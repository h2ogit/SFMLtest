#ifndef _OBJECT_H
#define _OBJECT_H

namespace game
{
	class Game;

	class Object
	{
		public:
			virtual void Init(Game* aGamePtr);
			virtual void SetTexture(const std::string &aTex);
			virtual void SetSpriteOrigin(float x, float y);
			virtual void SetText(const std::string &aText);
			virtual void SetLocation(sf::Vector2f aLoc);
			virtual void SetRotation(float aRot);

			virtual void SetOwner(Object* aNewOwner) {_Owner = aNewOwner;};

			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			virtual bool CanCollide() {return bCollideObjects;};

			virtual void Destroy();

		protected:
			Game* _Game;

			sf::Texture Texture;
			sf::Sprite Sprite;
			sf::Text Text;

			virtual sf::Vector2f Normalize2(sf::Vector2f Vec);

			virtual sf::FloatRect Object::getBoundingRect() const;

			virtual bool Object::CheckCollisionWith(Object* aObj);

			virtual Object* Object::GetCollidedObject();

			Object* _Owner;

			bool bCollideObjects;
	};
};

#endif