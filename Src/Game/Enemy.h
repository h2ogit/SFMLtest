#ifndef _ENEMY_H
#define _ENEMY_H

namespace game
{
	class Enemy : public Actor
	{
		enum EBehavior
		{
			EM_Lin,
			EM_LinRot,
			EM_Sin,
			EM_Cos,
			EM_Tan,
		} Behavior;

		EBehavior GetRandomBehavior();

		public:
			void Init(Game* aGamePtr);
			void Activate();
			void Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);
			void Killed();

		private:
			sf::Vector2f GetRandomLocation();
			float GetRandomRotation();
			

			std::string& GetRandomWord();

			std::vector<std::string> words;

			int wW, wH;

	};

};

#endif