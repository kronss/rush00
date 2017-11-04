#include "main.hpp"




int main()
{
	Window window;

	Player player;

	window.setUnitOnMap(player);





		window.printMap();



		// window.pauseEvent();



	for ( ; ; )
	{


		window.keyEvent(player);

		window.printMap();


	}

	// Player



	return 0;
}


