#ifndef _HUD_H
#define _HUD_H

namespace game
{
	class Game;

	class HUD
	{
		public:
			HUD()
			{
				_Game = nullptr;
			}

			void Init(Game* aGamePtr);

			void Load(sf::Sprite &aSprite, sf::Texture &aTexture, const std::string &aTextureName = "", const sf::Vector2f &aPosition = sf::Vector2f(0,0));

			void UpdateHUD(sf::RenderWindow* aWindow, sf::Time* aDeltaTime);

			void SetKilled(int aKilled) {NewmansKilled = aKilled;};
			void SetLost(int aLost) {NewmansLost = aLost;};

		private:
			Game* _Game;

			sf::Texture HUDBackgroundTexture;
			sf::Sprite HUDBackgroundSprite;

			sf::Texture PlayerTexture;
			sf::Sprite PlayerSprite;

			sf::Texture WeaponTexture;
			sf::Sprite WeaponSprite;

			int NewmansKilled;
			sf::Text NewmansKilledText;
			sf::Text NewmansKilledTextStatic;

			int NewmansLost;
			sf::Text NewmansLostText;
			sf::Text NewmansLostStatic;
	};
};

#endif