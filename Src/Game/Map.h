#ifndef _MAP_H
#define _MAP_H

namespace game
{
	class Map
	{
		public:
			Map(Game* aGamePtr);
			~Map();

			void StartMap();

			

		private:
			Game* _Game;

		protected:


	};
};

#endif