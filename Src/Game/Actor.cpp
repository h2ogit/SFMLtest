#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Actor.h"

#include <string>
#include <iostream>

using namespace game;

sf::Vector2f Actor::Normalize2(sf::Vector2f Vec)
{
  float magnitude = sqrt(Vec.x*Vec.x+Vec.y*Vec.y);
  if (magnitude > 0)
  {
    float invertedMag = 1 / magnitude;
    Vec.x *= invertedMag;
    Vec.y *= invertedMag;
  }
  return Vec;
}

void Actor::Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void Actor::SetLocation(sf::Vector2f aLoc)
{
	Sprite.setPosition(aLoc);
}

void Actor::SetRotation(float aRot)
{
	Sprite.setRotation(aRot);
}

void Actor::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
{
	if (aWindow != nullptr)
	{
		if (&Sprite != nullptr) aWindow->draw(Sprite);
		if (&Text != nullptr)
		{
			Text.setPosition(Sprite.getPosition());
			Text.setRotation(Sprite.getRotation());
			aWindow->draw(Text);
		}
	}
}

void Actor::SetTexture(const std::string &aTex)
{
	std::string file = _Game->GetResPath()->c_str() + aTex;

	if (!Texture.loadFromFile(file)) _Game->log("ERROR::Load::Texture::"+file);
	Texture.setSmooth(true);
	
	Sprite.setTexture(Texture);

	sf::Vector2u lTexSize = Texture.getSize();
	Sprite.setOrigin(lTexSize.x/2, lTexSize.y/2);
}

void Actor::SetSpriteOrigin(float x, float y)
{
	Sprite.setOrigin(x, y);
}

void Actor::SetText(const std::string &aText)
{
	Text.setFont(_Game->GetFont());
	Text.setCharacterSize(10);
	Text.setColor(sf::Color(255, 0, 255, 255));
    Text.setString(aText);
}