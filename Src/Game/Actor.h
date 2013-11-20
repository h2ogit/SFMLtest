#ifndef _ACTOR_H
#define _ACTOR_H

namespace game
{
	class Game;

	class Actor
	{
		public:
			virtual void Init(Game* aGamePtr);
			virtual void SetTexture(const std::string &aTex);
			virtual void SetSpriteOrigin(float x, float y);
			virtual void SetText(const std::string &aText);
			virtual void SetLocation(sf::Vector2f aLoc);
			virtual void SetRotation(float aRot);

			virtual void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime); // aDeltaTime.asSeconds();

		protected:
			Game* _Game;

			sf::Texture Texture;
			sf::Sprite Sprite;
			sf::Text Text;

			sf::Vector2f MoveDir;

			virtual sf::Vector2f Normalize2(sf::Vector2f Vec);
	};
};

#endif