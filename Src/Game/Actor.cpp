#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Actor.h"

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

void Actor::SetTexture(std::string aTex)
{
	if (!Texture.loadFromFile(_Game->GetResPath()+aTex)) _Game->log("ERROR::Load::Texture::"+aTex);
	Texture.setSmooth(true);
	
	Sprite.setTexture(Texture);

	sf::Vector2u lTexSize = Texture.getSize();
	Sprite.setOrigin(lTexSize.x/2, lTexSize.y/2);
}


void Actor::SetText(std::string aText)
{
	Text.setFont(_Game->GetFont());
	Text.setCharacterSize(10);
	Text.setColor(sf::Color(255, 0, 255, 255));
    Text.setString(aText);
}