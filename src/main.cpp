#include "main.hpp"




GameManeger gameManeger;


int main()
{
	Window window;

	Player player;

	window.setUnitOnMap(player);

	// Enemy *enemies[50];
	// for(int i = 0; i < 50; i++)
	// {
	// 	srand((unsigned int)time(NULL));
 //   	 	int a = rand()%(gXMap-1+1) + 1;

	// 	enemies[i] = new Enemy(a, gYMap, ENEMY_1);

	// 	//window.setUnitOnMap(enemies[i]);
	// 	window.printMap();
	// 	usleep(1000000);
	// 	if (i == 49)
	// 		i = 0;
	// }


		window.printMap();



		// window.pauseEvent();



	for ( ; ; )
	{


		window.keyEvent(player);



		gameManeger.update(window._map);


		window.printMap();


	}

	// Player



	return 0;
}


