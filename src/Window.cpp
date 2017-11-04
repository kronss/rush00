#include "main.hpp"

Window::Window()
: _isPause(true), _isGameOn(true)
{
    ncursesFunctionCreate();

    createColorPair();
    printStaticBorderLines();




    // attron(COLOR_PAIR(1));
    // mvprintw(22, 2, "01 - pacman");
    // attron(COLOR_PAIR(2));
    // mvprintw(23, 2, "02 - ghost1");
    // attron(COLOR_PAIR(3));
    // mvprintw(24, 2, "03 - ghost2, waiting for a few seconds");
    // attroff(COLOR_PAIR(3));
    // mvprintw(25, 2, "00 - treasure, give You no point)");

    // mvprintw(27, 12, "'w' - step up");
    // mvprintw(28, 12, "'s' - step down");
    // mvprintw(29, 12, "'a' - step left");
    // mvprintw(30, 12, "'d' - step right");

    // mvprintw(32, 12, "'SPACE' - PAUSE");    


    // if (_map[0][0] == 0) mvprintw(32, 12, "'SPACE' - PAUSE");    

    initMap();
}



Window::~Window()
{
    nodelay(stdscr, FALSE);
    getch();
    endwin();
}


void
Window::keyEvent(Player &player)
{
    int key;

        key = getch();
        if (key == ERR)
        {
            return (pauseEvent());
        }
        else if (key == 'w')
        {
            player.moveUp((int **)_map);
        }
        else if (key == 's')
        {
            player.moveDown((int **)_map);
        }    
        else if (key == 'a')
        {
            player.moveLeft((int **)_map);
        }
        else if (key == 'd')
        {
            player.moveRight((int **)_map);
        }    
        else if (key == SPACE)
            _isPause ^= 1;


        periodEvent();
}

void        Window::pauseEvent()
{
    int key;

    while (_isPause == 1)
    {
        nodelay(stdscr, FALSE);
        key = getch();
        // mvprintw(g_size + 7, 0, "%d\n", key);
        if (key == SPACE)
        {
            _isPause ^= 1;
        }
    }
    periodEvent();
}

void        Window::periodEvent()
{
    double    period;

    nodelay(stdscr, TRUE);
    period = (1.0 / 50.0);
    MSLEEP(period);
}



void   Window::setUnitOnMap(Unit & unit)
{

   mvprintw(32, 12, "y = %d", unit.getY());    
   mvprintw(34, 12, "x = %d", unit.getX());    


    _map[unit.getY()][unit.getX()] = unit.getId();
}






/******************************************************************************/
/*                                GETTER                                      */
/******************************************************************************/

bool
Window::getIsPasuse() const
{
    return  _isPause;
}

bool
Window::getIsGameOn() const
{
    return  _isGameOn;
}

// int &**Window::getMap()
// {
//     return _map;
// }

/******************************************************************************/
/*                                PRIVATE                                     */
/******************************************************************************/

void
Window::ncursesFunctionCreate()
{
    initscr();
    curs_set(0);
    noecho();
    refresh();
}

void
Window::createColorPair()
{
    /*
    ** chanell  - color set
    ** 32       - reset to std output
    ** 33       - full black
    ** 34       - border
    **
    ** 1        - green player(-1)
    ** 2        - blue player(-2)
    ** 3        - red player(-3)
    ** 4        - cyan player(-4)
    ** 5        - unused byte
    **
    ** 9        - green player(-1) + PC
    ** 10       - blue player(-2) + PC
    ** 11       - red player(-3) + PC
    ** 12       - cyan player(-4) + PC
    ** 13       - unused byte + PC
    */
    start_color();
    init_pair(32, COLOR_WHITE, COLOR_BLACK);
    init_pair(33, 16, 16);
    init_pair(34, 241, 241);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, 242, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_BLACK, COLOR_BLUE);
    init_pair(11, COLOR_BLACK, COLOR_RED);
    init_pair(12, COLOR_BLACK, COLOR_CYAN);
    init_pair(13, 240, 240);
}

void
Window::printStaticBorderLines()
{
    printHorizontLine(0, 0, 100);
    printHorizontLine(30, 0, 100);
    printHorizontLine(40, 0, 100);

    printVerticLine(0, 0, 40);
    printVerticLine(0, 99, 40);
}

void    Window::printHorizontLine(int y, int x, int x_limit)
{
    attron(COLOR_PAIR(34));
    while (x < x_limit)
    {
        mvprintw(y, x, "*");
        ++x;
    }
    attroff(COLOR_PAIR(34));
}

void    Window::printVerticLine(int y, int x, int y_limit)
{
    attron(COLOR_PAIR(34));
    while (y < y_limit)
    {
        mvprintw(y, x, "*");
        ++y;
    }
    attroff(COLOR_PAIR(34));
}

void
Window::initMap()
{
   for (int j = 0; j < gYMap; ++j)
    {
        for (int i = 0; i < gXMap; ++i)
        {
            _map[j][i] = 0;
            //_priority?
        }
    }
}

void
Window::printMap()
{
    for (int j = 0, y = 1; j < gYMap; ++j, ++y)
    {
        for (int i = 0, x = 1; i < gXMap; ++i, x+=2)
        {
            int color = _map[j][i];
            if (color == 1)
                attron(A_BOLD);
            {
                attron(COLOR_PAIR(color));

                
                printSquareById(y, x, color);


                attroff(COLOR_PAIR(color));
            }
            if (color == 1)
                attroff(A_BOLD);
        }
    }
}

void
Window::printSquareById(int y, int x, int color)
{
    switch (color)
    {
        case (PLAYER):
        {
            mvprintw(y, x, "%2.2hhs", "#>");
            break;
        }
        case (PLAYERS_BULET):
        {
            mvprintw(y, x, "%2.2hhs", "--");
            break;
        }
        case (ENEMY_1):
        {
            mvprintw(y, x, "%2.2hhs", "+=");
        }
        default:
        {
            mvprintw(y, x, "%2.2hhs", "  ");
        }
    }
}

/******************************************************************************/

















