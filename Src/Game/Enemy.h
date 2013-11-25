#ifndef _ENEMY_H
#define _ENEMY_H

namespace game
{
	class Enemy : public Actor
	{
		public:
			void Init(Game* aGamePtr);
			void Activate();
			void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);
			
		private:
			sf::Vector2f GetRandomLocation();
			float GetRandomRotation();

			std::string& GetRandomWord();

			std::vector<std::string> words;

			int wW, wH;
	};

};

#endif