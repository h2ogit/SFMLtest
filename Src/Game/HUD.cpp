#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "HUD.h"

using namespace game;

void HUD::Init(Game* aGamePtr)
{
	_Game = aGamePtr;

	Load(HUDBackgroundSprite, HUDBackgroundTexture, _Game->_Settings->HUDBackgroundTexture, sf::Vector2f(128, 704));
	Load(PlayerSprite, PlayerTexture, _Game->_Settings->PlayerTexture, sf::Vector2f(70, 705));
	PlayerSprite.setScale(sf::Vector2f(0.9, 0.9));
	Load(WeaponSprite, WeaponTexture, _Game->_Settings->Weapon1Texture, sf::Vector2f(200, 745));
}

void HUD::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (&HUDBackgroundSprite != nullptr) aWindow->draw(HUDBackgroundSprite);
		if (&PlayerSprite != nullptr) aWindow->draw(PlayerSprite);
		if (&WeaponSprite != nullptr) aWindow->draw(WeaponSprite);
		if (&AllKilledText != nullptr) aWindow->draw(AllKilledText);
	}
}

void HUD::Load(sf::Sprite &aSprite, sf::Texture &aTexture, const std::string &aTextureName, const sf::Vector2f &aPosition)
{
	std::string file = _Game->_Settings->ResPath + aTextureName;

	if (!aTexture.loadFromFile(file)) _Game->log("ERROR::Load::Texture::"+file);
	aTexture.setSmooth(true);
	
	aSprite.setTexture(aTexture);

	sf::FloatRect bounds = aSprite.getLocalBounds();
	aSprite.setOrigin(bounds.width/2, bounds.height/2);

	aSprite.setPosition(aPosition);
}