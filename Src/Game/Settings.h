#ifndef _SETTINGS_H
#define _SETTINGS_H

using namespace std;

namespace game
{
	class Settings
	{
		public:
			int wWidh;
			int wHeight;
			std::string GameName;

			std::string ResPath;

			std::string FontFile;

			std::string WorldBackgroundTexture;

			std::string HUDBackgroundTexture;

			int PlayerHealth;
			int PlayerSpeed;
			std::string PlayerTexture;

			std::string AimTexture;
			
			int Enemy1Health;
			int Enemy1Speed;

			int Enemy2Health;
			int Enemy2Speed;

			int EnemyBossHealth;
			int EnemyBossSpeed;

			int Weapon1Damage;
			float Weapon1FireRate;
			std::string Weapon1Texture;
			int Weapon1ProjectileSpeed;
			std::string Weapon1ProjectileTexture;

			int Weapon2Damage;
			float Weapon2FireRate;
			int Weapon2ProjectileSpeed;

			



		public: 
			Settings()
			{
				wWidh = 1024;
				wHeight = 768;
				GameName = "Angry NewMan";
				ResPath = "../Res/";

				FontFile = "sansation.ttf";

				WorldBackgroundTexture = "back.jpg";

				HUDBackgroundTexture = "HUD.png";
				
				PlayerHealth = 100;
				PlayerSpeed = 5;
				PlayerTexture = "dr_evil.png";

				AimTexture = "aimcross.png";
			
				Enemy1Health = 20;
				Enemy1Speed = 200;

				Enemy2Health = 30;
				Enemy2Speed = 3;

				EnemyBossHealth = 200;
				EnemyBossSpeed = 6;

				Weapon1Damage = 10;
				Weapon1FireRate = 0.2f;
				Weapon1Texture = "WeaponL.png";
				Weapon1ProjectileSpeed = 10;
				Weapon1ProjectileTexture = "aimcross.png";
				

				Weapon2Damage = 25;
				Weapon2FireRate = 0.4f;
				Weapon2ProjectileSpeed = 8;
			}

	};
};


#endif