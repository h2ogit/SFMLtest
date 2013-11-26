#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "Game.h"
#include "Settings.h"

#include "HUD.h"

#include <sstream>

using namespace game;

std::string IntToStr(int tmp)
{
    std::ostringstream out;
    out << tmp;
    return out.str();
}

void HUD::Init(Game* aGamePtr)
{
	_Game = aGamePtr;

	bMessageShown = false;
	MessageDurationElapsed = 0.0f;
	MessageDurationMax = 0.0f;
	Message.setFont(_Game->GetFont());
	Message.setCharacterSize(30);
	Message.setColor(sf::Color(0, 255, 255, 255));
	Message.setString("");
	Message.setPosition(float(_Game->_Settings->wWidh/2), float(_Game->_Settings->wHeight/2 -15));

	Load(HUDBackgroundSprite, HUDBackgroundTexture, _Game->_Settings->HUDBackgroundTexture, sf::Vector2f(128, 704));
	Load(PlayerSprite, PlayerTexture, _Game->_Settings->PlayerTexture, sf::Vector2f(70, 705));
	PlayerSprite.setScale(sf::Vector2f(0.9f, 0.9f));
	Load(WeaponSprite, WeaponTexture, _Game->_Settings->Weapon1Texture, sf::Vector2f(200, 745));

	//---

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

	//---

	NewmansLostTextStatic.setFont(_Game->GetFont());
	NewmansLostTextStatic.setCharacterSize(12);
	NewmansLostTextStatic.setColor(sf::Color(255, 255, 255, 255));
	NewmansLostTextStatic.setString("Newmans lost:");
	NewmansLostTextStatic.setPosition(130, 675);

	NewmansLostText.setFont(_Game->GetFont());
	NewmansLostText.setCharacterSize(12);
	NewmansLostText.setColor(sf::Color(255, 255, 255, 255));
	NewmansLostText.setString("0");
	NewmansLostText.setPosition(230, 675);

	//---

	NewmansLiveTextStatic.setFont(_Game->GetFont());
	NewmansLiveTextStatic.setCharacterSize(12);
	NewmansLiveTextStatic.setColor(sf::Color(255, 255, 255, 255));
	NewmansLiveTextStatic.setString("Newmans live:");
	NewmansLiveTextStatic.setPosition(130, 695);

	NewmansLiveText.setFont(_Game->GetFont());
	NewmansLiveText.setCharacterSize(12);
	NewmansLiveText.setColor(sf::Color(255, 255, 255, 255));
	NewmansLiveText.setString("0");
	NewmansLiveText.setPosition(230, 695);

}

void HUD::UpdateHUD(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (&HUDBackgroundSprite != nullptr) aWindow->draw(HUDBackgroundSprite);
		if (&PlayerSprite != nullptr) aWindow->draw(PlayerSprite);
		if (&WeaponSprite != nullptr) aWindow->draw(WeaponSprite);

		if (&NewmansKilledTextStatic != nullptr) aWindow->draw(NewmansKilledTextStatic);
		if (&NewmansKilledText != nullptr)
		{
			NewmansKilledText.setString(IntToStr(_Game->NewmansKilled));
			aWindow->draw(NewmansKilledText);
		}

		if (&NewmansLostTextStatic != nullptr) aWindow->draw(NewmansLostTextStatic);
		if (&NewmansLostText != nullptr)
		{
			NewmansLostText.setString(IntToStr(_Game->NewmansLost));
			aWindow->draw(NewmansLostText);
		}

		if (&NewmansLiveTextStatic != nullptr) aWindow->draw(NewmansLiveTextStatic);
		if (&NewmansLiveText != nullptr)
		{
			NewmansLiveText.setString(IntToStr(_Game->NewmansLive));
			aWindow->draw(NewmansLiveText);
		}

		if (bMessageShown)
		{
			MessageDurationElapsed += aDeltaTime->asSeconds();
			if (MessageDurationElapsed < MessageDurationMax)
			{
				if (&Message != nullptr) aWindow->draw(Message);
			}
			else
			{
				bMessageShown = false;
				Message.setString("");
				MessageDurationElapsed = 0.0f;
				MessageDurationMax = 0.0f;
			}
		}
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

void HUD:: ShowMessage(std::string aMsg, float aDuration)
{
	bMessageShown = true;
	Message.setString(aMsg);
	MessageDurationMax = aDuration;
}

void HUD:: ShowWaveMessage(int aWaveNum, float aDuration)
{
	std::string newmsg = "Wave #"+IntToStr(aWaveNum)+" is starting...";
	ShowMessage(newmsg, aDuration);
}