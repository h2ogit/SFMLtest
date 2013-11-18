#ifndef _ACTOR_H
#define _ACTOR_H

namespace game
{
	class Actor
	{
		public:
			//Actor();
			//~Actor();
			virtual void Update(sf::RenderWindow* aWindow);

		protected:
			sf::Vector2f MoveDir;
			sf::Texture Texture;
			sf::Sprite Sprite;
			sf::Text Text;

			virtual void AddText(std::string aText);
			virtual sf::Vector2f Normalize2(sf::Vector2f Vec)
	};

};

#endif