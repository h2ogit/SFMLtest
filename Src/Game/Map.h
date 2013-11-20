#ifndef _MAP_H
#define _MAP_H

namespace game
{
	class Map
	{
		public:
			void Init(Game* aGamePtr);
			void StartMap();

		private:
			Game* _Game;
			Actor* _Background;

		protected:


	};
};

#endif