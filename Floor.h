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
        void updateVisibility(Character * c);
        bool checkAttack(Character * c, int nx, int ny);

    protected:

    private:
        int exit_x;
        int exit_y;
        std::vector<Enemy> enemies;
        std::vector<Item *> items;
        bool visible[MAX_P_COL][MAX_P_ROW];
};

#endif // FLOOR_H
