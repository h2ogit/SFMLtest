#ifndef _GAME_H
#define _GAME_H

#include <memory>

namespace game
{
	#define pS(T) std::shared_ptr<T>
	#define pU(T) std::unique_ptr<T>

	class Settings;
	class Input;
	class World;

	class HUD;

	class Object;
	class DynamicObject;
	class Actor;
	class Player;

	class Game
	{
		public:
			//Settings* _Settings;

			pS(Settings) _Settings;

			Player* _Player;

			Input* _Input;
			World* _World;

			sf::Vector2f ScreenCenter;

			Game();
			~Game();

			int Start();
			void Stop();
			void log(const std::string &msg);

			//const std::string* GetResPath();
			const sf::Font& GetFont();

			std::vector<Object*> Objects;
			//std::vector<Projectile> Projectiles;

			Object* Spawn(Object* aObj,  const std::string aTexture, const bool bCanCollide = true, const std::string aText = "", const sf::Vector2f aLoc = sf::Vector2f (0,0), const float aRot = 0.f);
			void UnSpawn(Object* aObj);

		private: 
			bool bRuning;

			sf::RenderWindow* _Render;
			sf::Font Font;
			sf::Event Event;
			sf::Clock GameClock;
			sf::Time DeltaTime;

			HUD* _HUD;

	};
};

#endif