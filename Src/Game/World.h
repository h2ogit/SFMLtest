#ifndef _WORLD_H
#define _WORLD_H

namespace game
{
	class World
	{
		public:
			void Init(Game* aGamePtr);
			void StartWorld();

			void InitPlayer(Player* aPlayer);

		private:
			Game* _Game;
			Object* _Background;

		protected:


	};
};

#endif