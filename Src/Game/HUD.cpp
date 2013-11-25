#include "SFML/Graphics.hpp"

#include "Game.h"
#include "Settings.h"

#include "HUD.h"

#include <string>

using namespace game;

void HUD::Init(Game* aGamePtr)
{
	_Game = aGamePtr;

	Load(HUDBackgroundSprite, HUDBackgroundTexture, _Game->_Settings->HUDBackgroundTexture, sf::Vector2f(128, 704));
	Load(PlayerSprite, PlayerTexture, _Game->_Settings->PlayerTexture, sf::Vector2f(70, 705));
	PlayerSprite.setScale(sf::Vector2f(0.9f, 0.9f));
	Load(WeaponSprite, WeaponTexture, _Game->_Settings->Weapon1Texture, sf::Vector2f(200, 745));

	NewmansKilledTextStatic.setFont(_Game->GetFont());
	NewmansKilledTextStatic.setCharacterSize(12);
	NewmansKilledTextStatic.setColor(sf::Color(255, 255, 255, 255));
	NewmansKilledTextStatic.setString("Newmans killed:");
	NewmansKilledTextStatic.setPosition(130, 655);

	NewmansKilledText.setFont(_Game->GetFont());
	NewmansKilledText.setCharacterSize(12);
	NewmansKilledText.setColor(sf::Color(255, 255, 255, 255));
	NewmansKilledText.setString("0");
	NewmansKilledText.setPosition(230, 655);

	NewmansLostStatic.setFont(_Game->GetFont());
	NewmansLostStatic.setCharacterSize(12);
	NewmansLostStatic.setColor(sf::Color(255, 255, 255, 255));
	NewmansLostStatic.setString("Newmans lost:");
	NewmansLostStatic.setPosition(130, 675);

	NewmansLostText.setFont(_Game->GetFont());
	NewmansLostText.setCharacterSize(12);
	NewmansLostText.setColor(sf::Color(255, 255, 255, 255));
	NewmansLostText.setString("0");
	NewmansLostText.setPosition(230, 675);
}

void HUD::UpdateHUD(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (&HUDBackgroundSprite != nullptr) aWindow->draw(HUDBackgroundSprite);
		if (&PlayerSprite != nullptr) aWindow->draw(PlayerSprite);
		if (&WeaponSprite != nullptr) aWindow->draw(WeaponSprite);
		if (&NewmansKilledTextStatic != nullptr) aWindow->draw(NewmansKilledTextStatic);
		if (&NewmansKilledText != nullptr) aWindow->draw(NewmansKilledText);
		if (&NewmansLostStatic != nullptr) aWindow->draw(NewmansLostStatic);
		if (&NewmansLostText != nullptr) aWindow->draw(NewmansLostText);
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