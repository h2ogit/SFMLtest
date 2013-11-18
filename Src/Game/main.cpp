//#include <iostream>
//#include <string>
#include "SFML/Graphics.hpp"
#include "Game.h"

using namespace game;

Game* _Game;

int main()
{
	_Game = new Game();
	return _Game->Start();
}
//
//using namespace std;
//using namespace sf;
//using namespace game;
//
//const int wWidh = 1024;
//const int wHeight = 768;
//const string ResPath = "../Res/";
//
//
//Projectile* Projectiles[10];
//int LastProjectileIdx = 0;
//

//

//
//Vector2f FixScreenPosition(Vector2f aPos)
//{
//	return aPos;
//}
//
//void WeaponStopFire(Vector2f aPos)
//{
//	if (LastProjectileIdx == 10)
//	{
//		delete Projectiles[LastProjectileIdx];
//		LastProjectileIdx = 0;
//	}
//	Projectiles[LastProjectileIdx] = new Projectile(aPos, aPos);
//	LastProjectileIdx++;
//	//std::cout << "WeaponStartFire: idx=" << LastProjectileIdx << " x: " << aPos.x << " | y: " << aPos.y << endl;
//}
//
//void WeaponStartFire(Vector2f aPos)
//{
//}
//
//Vector2f GetRandomRuning(Vector2f aCurrentPos)
//{
//	Vector2f RandPos;
//	RandPos.x = rand() % wWidh;
//	RandPos.y = rand() % wHeight;
//
//	Vector2f NewScrPoint;
//	NewScrPoint = Normalize2(RandPos - aCurrentPos) * float(wHeight);
//
//	return NewScrPoint;
//}
//
//void CreateGameSprites()
//{
//	Texture SkyBoxTexture; 
//	if (!SkyBoxTexture.loadFromFile(ResPath+"back.jpg")) cout << "SkyBox load error";
//	SkyBoxTexture.setSmooth(true);
//	Sprite SkyBox(SkyBoxTexture);
//	SkyBox.setOrigin(64,64);
//
//	Texture NewManTexture; 
//	if (!NewManTexture.loadFromFile(ResPath+"Newman.png")) cout << "NewMan load error";
//	NewManTexture.setSmooth(true);
//
//	Sprite NewMan(NewManTexture);
//	NewMan.setOrigin(64,64);
//	NewMan.setPosition(wWidh/2 - 100, wHeight/2);
//
//	Texture ZloTexture;
//	if (!ZloTexture.loadFromFile(ResPath+"dr_evil.png")) cout << "Zlo load error";
//	ZloTexture.setSmooth(true);
//
//	Sprite ZloMan(ZloTexture);
//	ZloMan.setOrigin(64,64);
//	ZloMan.setPosition(wWidh/2 + 100, wHeight/2);
//
//	Texture AimTexture;
//	if (!AimTexture.loadFromFile(ResPath+"aimcross.png")) cout << "Aim load error";
//	AimTexture.setSmooth(true);
//	
//	Sprite Aim(AimTexture);
//	Aim.setOrigin(32,32);
//	Aim.setPosition(wWidh/2, wHeight/2);
//}