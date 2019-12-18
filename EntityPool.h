#ifndef ENTITYPOOL_H
#define ENTITYPOOL_H

#define MAX_LEVEL 64

#include <vector>
#include <array>
#include "Enemy.h"
#include "Item.h"

class EntityPool
{
    public:
        EntityPool();
        virtual ~EntityPool();

        void addEnemy(int lvl, Enemy * e);
        void addItem(int lvl, Item * i);

        std::vector<Enemy *> getEnemyList(int lvl);
        std::vector<Item *> getItemList(int lvl);

        void printEnemies();
        void printItems();

        Enemy getRandomEnemy(int lvl);
        Item * getRandomItem(int lvl);

    protected:

    private:
        std::array<std::vector<Enemy *>, MAX_LEVEL> enemyPool;
        std::array<std::vector<Item *>, MAX_LEVEL> itemPool;
};

#endif // ENTITYPOOL_H
