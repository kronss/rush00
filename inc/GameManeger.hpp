#ifndef GAME_MANEGER_HPP
# define GAME_MANEGER_HPP

#include "main.hpp"

/******************************************************************************/
/*                            SINGLETON PATTERN                               */
/******************************************************************************/

// class Shot;
// class Enemy;


int const arrayMax = 50;
extern int const gYMap;
extern int const gXMap;

class GameManeger
{
public:

    GameManeger();
    ~GameManeger();










    void update(int map[gYMap][gXMap]);



    void setShotInArray(int const x, int const y, int const color);














private:
    Shot    *arrayShot[arrayMax];

    Enemy   *arrayEnemy[arrayMax];










    GameManeger(GameManeger const &n);

    GameManeger & operator=(GameManeger const & r);


};

#endif





// Singleton& instance = Singleton::Instance();
