#include "main.hpp"

GameManeger::GameManeger()
{

    std::cout << "born" << std::endl;

    for (int i = 0; i < arrayMax; ++i)
    {
        arrayShot[i] = NULL;
        arrayEnemy[i] = NULL;
    }
}


GameManeger::~GameManeger()
{
    std::cout << "die" << std::endl;
    for (int i = 0; i < arrayMax; ++i)
    {
        delete arrayShot[i];  // = NULL;
        delete arrayEnemy[i]; // = NULL;
    }
}







void
GameManeger::update(int map[gYMap][gXMap])
{
   for (int i = 0; i < arrayMax; ++i)
   {
       if (arrayShot[i] != NULL)
       {
           arrayShot[i]->moveRight(map);
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
            return    ;
        }
   }
}






/******************************************************************************/
/*                                GETTER                                      */
/******************************************************************************/

// GameManeger * GameManeger::getManeger()
// {
//     if (!_game)
//     {
//         _game = new (GameManeger);

//     }
//     return (_game);
// }







/******************************************************************************/
/*                                PRIVATE                                     */
/******************************************************************************/


GameManeger::GameManeger(GameManeger const &n)
{
    
}


GameManeger & GameManeger::operator=(GameManeger const & r)
{
   return *this;
}
