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
        DEFAULT = 32
    };



#define MSLEEP(msec) usleep(msec * 1000000.0)
#define SPACE 32
#define ESC 27


class Player;
class Unit;
class Enemy;

class Window
{
public:
    int     _map[gYMap][gXMap];

    Window();
    ~Window();

    Window & operator = (Window const & rhs);

    void    keyEvent(Player &player);





    void    printMap();
    void    pauseEvent();



//SETTER
    void    setUnitOnMap(Unit & unit);



//GETTER
    bool    getIsPasuse() const;
    bool    getIsGameOn() const;

private:
    bool    _isPause;
    bool    _isGameOn;
    // int    _matrix_priority[g_size][g_size];


    Window(Window const & cpy);



    void    periodEvent();

    void    ncursesFunctionCreate();
    void    createColorPair();
    void    printStaticBorderLines();
    void    printHorizontLine(int y, int x, int y_limit);
    void    printVerticLine(int y, int x, int y_limit);
    void    initMap();
    void    printSquareById(int y, int x, int color);





};



#endif
