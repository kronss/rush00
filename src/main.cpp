#include "main.hpp"




GameManeger gameManeger;
bool gameOn = true;

int main()
{
	Window window;
	Player player; 

	window.setUnitOnMap(player);
	
	srand((unsigned int)time(NULL));

	window.printMap();

		window.pauseEvent();

	while (window.getIsGameOn() && gameOn)
	{

		window.keyEvent(player);




		gameManeger.update(player, window._map);

		gameManeger.setEnemyInArray(window);


		window.printMap();


	}

	if (!gameOn)
	{
		int i = 10;
	    mvprintw(++i, 10, "_____.___.________   ____ ___     _____ _____________________ ");
	    mvprintw(++i, 10, "\\__  |   |\\_____  \\ |    |   \\   /  _  \\\\______   \\_   _____/ ");
	    mvprintw(++i, 10, "/   |   | /   |   \\|    |   /  /  /_\\  \\|       _/|    __)_ ");
	    mvprintw(++i, 10, " \\____   |/    |    \\    |  /  /    |    \\    |   \\|        \\  ");
	    mvprintw(++i, 10, "/ ______|\\_______  /______/   \\____|__  /____|_  /_______  /");
	    mvprintw(++i, 10, " \\/               \\/                   \\/       \\/        \\/ ");
	    mvprintw(++i, 10, ".____    ________   ________    ______________________________ ");
	    mvprintw(++i, 10, "|    |   \\_____  \\  \\_____  \\  /   _____/\\_   _____/\\______   \\ ");
	    mvprintw(++i, 10, "|    |    /   |   \\  /   |   \\ \\_____  \\  |    __)_  |       _/");
	    mvprintw(++i, 10, "|    |___/    |    \\/    |    \\/        \\ |        \\ |    |   \\");
	    mvprintw(++i, 10, "|_______ \\_______  /\\_______  /_______  //_______  / |____|_  /");
	    mvprintw(++i, 10, "        \\/       \\/         \\/        \\/         \\/         \\/ ");
	}
	


	return 0;
}


