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
			pS(Settings) _Settings;

			Player* _Player;

			Input* _Input;

			World* _World;

			HUD* _HUD;

			sf::Vector2i ScreenCenter;

			Game();
			~Game();

			int Start();
			void Stop();
			void log(const std::string &msg);

			//const std::string* GetResPath();
			const sf::Font& GetFont();

			std::vector<Object*> Objects;

			Object* Spawn(Object* aObj,  const std::string aTexture, const bool bCanCollide = true, const Object* aOwner = nullptr, const sf::Vector2f aLoc = sf::Vector2f (0,0), const float aRot = 0.f);
			void UnSpawn(Object* aObj);

			void TrashCollect(Object*);

			int NewmansKilled;
			int NewmansLost;
			int NewmansLive;

		private: 
			bool bRuning;

			sf::RenderWindow* _Render;
			sf::Font Font;
			sf::Event Event;
			sf::Clock GameClock;
			sf::Time DeltaTime;
			pS(sf::Music) _GameMusic;

			std::vector<Object*> TrashCollector;
			void ProcessTrash();		

	};
};

#endif