#include "SFML/Graphics.hpp"

#include "Game.h"

#include "Object.h"

//#include <string>
//#include <iostream>

using namespace game;

sf::Vector2f Object::Normalize2(sf::Vector2f Vec)
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

void Object::Init(Game* aGamePtr)
{
	_Game = aGamePtr;
}

void Object::SetLocation(sf::Vector2f aLoc)
{
	Sprite.setPosition(aLoc);
}

void Object::SetRotation(float aRot)
{
	Sprite.setRotation(aRot);
}

void Object::Update(sf::RenderWindow* aWindow, sf::Time* aDeltaTime)
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

void Object::SetTexture(const std::string &aTex)
{
	std::string file = _Game->GetResPath()->c_str() + aTex;

	if (!Texture.loadFromFile(file)) _Game->log("ERROR::Load::Texture::"+file);
	Texture.setSmooth(true);
	
	Sprite.setTexture(Texture);

	sf::FloatRect bounds = Sprite.getLocalBounds();
	Sprite.setOrigin(bounds.width/2, bounds.height/2);
}

void Object::SetSpriteOrigin(float x, float y)
{
	Sprite.setOrigin(x, y);
}

void Object::SetText(const std::string &aText)
{
	Text.setFont(_Game->GetFont());
	Text.setCharacterSize(10);
	Text.setColor(sf::Color(255, 0, 255, 255));
    Text.setString(aText);
}