#include "main.hpp"




GameManeger gameManeger;


int main()
{
	Window window;
	Player player; 

	window.setUnitOnMap(player);
	
	srand((unsigned int)time(NULL));

	window.printMap();

		// window.pauseEvent();

	for ( ; ; )
	{


		window.keyEvent(player);



		gameManeger.update(window._map);
		gameManeger.setEnemyInArray(window);


		window.printMap();


	}

	// Player



	return 0;
}


