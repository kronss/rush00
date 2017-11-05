#ifndef GAME_MANEGER_HPP
# define GAME_MANEGER_HPP

#include "main.hpp"

/******************************************************************************/
/*                           NOT SINGLETON PATTERN                            */
/******************************************************************************/


int const arrayMax = 50;
extern int const gYMap;
extern int const gXMap;

class GameManeger
{
public:

    GameManeger();
    ~GameManeger();


    void update(int map[gYMap][gXMap]);


//SETTER
    void setShotInArray(int const x, int const y, int const color);
    void setEnemyInArray(int const x, int const y, int const color);


private:
    Shot    *arrayShot[arrayMax];
    Enemy   *arrayEnemy[arrayMax];

//UNUSED
    GameManeger(GameManeger const &n);
    GameManeger & operator=(GameManeger const & r);
};

#endif
