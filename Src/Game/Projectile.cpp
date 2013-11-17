#include "Projectile.h"
#include "SFML/Graphics.hpp"

using namespace game;

Projectile:: Projectile(sf::Vector2f aLoc, sf::Vector2f aDir)
{
	PlasmaBall.setRadius(10.0f);
	PlasmaBall.setOrigin(10,10);
	PlasmaBall.setFillColor(sf::Color::Green);
	PlasmaBall.setPosition(aLoc);
}

Projectile:: ~Projectile()
{
	delete &PlasmaBall;
}

void Projectile:: Tick(sf::RenderWindow* aWindow)
{
	aWindow->draw(PlasmaBall);
}