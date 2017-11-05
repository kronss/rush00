#include "main.hpp"

GameManeger::GameManeger()
{

    for (int i = 0; i < arrayMax; ++i)
    {
        arrayShot[i] = NULL;
        arrayEnemy[i] = NULL;
    }
}


GameManeger::~GameManeger()
{

    for (int i = 0; i < arrayMax; ++i)
    {
        delete arrayShot[i];  // = NULL;
        delete arrayEnemy[i]; // = NULL;
    }
}





void
GameManeger::update(Player & player, int map[gYMap][gXMap])
{
//moveBullet()
    for (int i = 0; i < arrayMax; ++i)
    {
        if (arrayShot[i] != NULL)
        {
            arrayShot[i]->moveRight(map);


            for (int j = 0; j < arrayMax; ++j)
            {
                if (arrayEnemy[j] != NULL)
                {
                    if (arrayShot[i]->checkColision(*arrayEnemy[j]))
                    {
                        arrayShot[i]->setIsDead(true);
                    }    
                }
            }
        }
    }
//moveEnemy()
    for (int i = 0; i < arrayMax; ++i)
    {
        if (arrayEnemy[i] != NULL)
        {
            if (arrayEnemy[i]->checkColision(player))
            {
                gameOn = false;
                return ;
            }    
            arrayEnemy[i]->moveLeft(map);
        }
    }
/*******************************************delete**************************/
//deleteBulletIfDead()
    for (int i = 0; i < arrayMax; ++i)
    {

        if (arrayShot[i] != NULL && arrayShot[i]->isDead())
        {
            delete arrayShot[i];
            arrayShot[i] = NULL;
        }
    }
//deleteEnemyIfDead()
    for (int i = 0; i < arrayMax; ++i)
    {
        if (arrayEnemy[i] != NULL && arrayEnemy[i]->isDead())
        {
            delete arrayEnemy[i];
            arrayEnemy[i] = NULL;
        }
    }
}

/******************************************************************************/
/*                                SETTER                                      */
/******************************************************************************/

void
GameManeger::setShotInArray(int const x, int const y, int const color)
{
   for (int i = 0; i < arrayMax; ++i)
   {
       if (arrayShot[i] == NULL)
       {
            arrayShot[i] = new Shot(x, y, color);
            return ;
        }
   }
}

void
GameManeger::setEnemyInArray(Window & window)
{
    int y_random = rand() % (gYMap);


    int i = rand() % 30; 
    if (i != 0)
        return ;


   for (int i = 0; i < arrayMax; ++i)
   {
        if (arrayEnemy[i] == NULL)
        {
            arrayEnemy[i] = new Enemy(gXMap - 1, y_random, ENEMY_1);

            window.setUnitOnMap(*(arrayEnemy[i]));




            return ;
        }
   }
}

/******************************************************************************/
/*                                GETTER                                      */
/******************************************************************************/







/******************************************************************************/
/*                                PRIVATE                                     */
/******************************************************************************/


GameManeger::GameManeger(GameManeger const &n)
{
    return ;
}

GameManeger & GameManeger::operator=(GameManeger const & r)
{
   return *this;
}
