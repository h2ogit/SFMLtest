#include "SFML/Graphics.hpp"
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

//	Texture SkyBoxTexture; 
//	if (!SkyBoxTexture.loadFromFile(ResPath+"back.jpg")) cout << "SkyBox load error";
//	SkyBoxTexture.setSmooth(true);
//	Sprite SkyBox(SkyBoxTexture);
//	SkyBox.setOrigin(64,64);

void Actor::Update(sf::RenderWindow* aWindow)
{
	//aWindow->draw(PlasmaBall);
}

void AddText(std::string aText)
{
	// Create some text to draw on top of our OpenGL object
    Font font;
    if (!font.loadFromFile(ResPath+"sansation.ttf")) return EXIT_FAILURE;
    Text text("NewMan Killer v0.1b", font);
    text.setColor(Color(255, 0, 255, 255));
    text.setPosition(wWidh - 300, wHeight-50);
}