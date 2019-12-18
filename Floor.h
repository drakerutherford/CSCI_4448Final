#ifndef FLOOR_H
#define FLOOR_H



#include <vector>
#include <curses.h>
#include "Item.h"
#include "Enemy.h"
#include "EntityPool.h"
#include "Character.h"
#include "Variables.h"

class Floor
{
    public:
        Floor(EntityPool * ep, int level);
        virtual ~Floor();

        void draw(WINDOW * playarea);
        void pickUpItem(Character * c);
        void enemyMovement(Character * c);

    protected:

    private:
        int exit_x;
        int exit_y;
        std::vector<Enemy> enemies;
        std::vector<Item *> items;
};

#endif // FLOOR_H
