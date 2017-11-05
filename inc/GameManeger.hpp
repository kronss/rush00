#ifndef GAME_MANEGER_HPP
# define GAME_MANEGER_HPP

#include "main.hpp"

/******************************************************************************/
/*                           NOT SINGLETON PATTERN                            */
/******************************************************************************/


int const arrayMax = 50;
extern int const gYMap;
extern int const gXMap;
extern bool gameOn;

class GameManeger
{
public:

    GameManeger();
    ~GameManeger();


    void update(Player & player, int map[gYMap][gXMap]);


//SETTER
    void setShotInArray(int const x, int const y, int const color);
    void setEnemyInArray(Window & window);


private:
    Shot    *arrayShot[arrayMax];
    Enemy   *arrayEnemy[arrayMax];

//UNUSED
    GameManeger(GameManeger const &n);
    GameManeger & operator=(GameManeger const & r);
};

#endif
