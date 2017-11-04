#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP 


#include <ncurses.h>
#include <iostream>
#include <unistd.h>


#include "main.hpp"


int const gYMap = 30;
int const gXMap = 50;

    enum idColor
    {
        PLAYER = 1,
        PLAYERS_BULET = 2,
        ENEMY_1 = 3,
        DEFAULT = 10
    };



#define MSLEEP(msec) usleep(msec * 1000000.0)
#define SPACE 32
#define ESC 27


class Player;
class Unit;

class Window
{
public:
    int     _map[gYMap][gXMap];

    Window();
    Window(Window const & cpy);
    ~Window();

    Window & operator = (Window const & rhs);

    void   keyEvent(Player &player);
    void   pauseEvent();
    void   periodEvent();




    void   setUnitOnMap(Unit & unit);
    void    printMap();





//GETTER
    bool    getIsPasuse() const;
    bool    getIsGameOn() const;
    // int     **getMap();

private:
    bool    _isPause;
    bool    _isGameOn;
    // int    _matrix_priority[g_size][g_size];



    void    ncursesFunctionCreate();
    void    createColorPair();
    void    printStaticBorderLines();
    void    printHorizontLine(int y, int x, int y_limit);
    void    printVerticLine(int y, int x, int y_limit);
    void    initMap();
    void    printSquareById(int y, int x, int color);





};



#endif
