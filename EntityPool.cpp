#include <vector>
#include <array>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
#include "Item.h"
#include "EntityPool.h"

EntityPool::EntityPool()
{
    //ctor
}

EntityPool::~EntityPool()
{
    for (size_t i = 0; i < MAX_LEVEL; i++) {
        std::vector<Enemy *> e = enemyPool[i];
        for (size_t j = 0; j < e.size(); j++) {
            delete e[j];
        }

        std::vector<Item *> it = itemPool[i];
        for (size_t j = 0; j < it.size(); j++) {
            delete it[j];
        }
    }
}

void EntityPool::addEnemy(int lvl, Enemy * e) {
    (enemyPool[lvl]).push_back(e);
}
void EntityPool::addItem(int lvl, Item * i) {
    (itemPool[lvl]).push_back(i);
}

std::vector<Enemy *> EntityPool::getEnemyList(int lvl) {
    return enemyPool[lvl];
}
std::vector<Item *> EntityPool::getItemList(int lvl) {
    return itemPool[lvl];
}

void EntityPool::printEnemies() {
    for (size_t i = 0; i < MAX_LEVEL; i++) {
        std::vector<Enemy *> e = enemyPool[i];
        for (size_t j = 0; j < e.size(); j++) {
            printf("%s\n",e[j]->print().c_str());
        }
    }
}

void EntityPool::printItems() {
    for (size_t i = 0; i < MAX_LEVEL; i++) {
        std::vector<Item *> it = itemPool[i];
        for (size_t j = 0; j < it.size(); j++) {
            printf("%s\n",it[j]->print().c_str());
        }
    }
}

Enemy EntityPool::getRandomEnemy(int lvl) {
    std::vector<Enemy *> el = getEnemyList(lvl);
    int choose = rand() % el.size();
    return el[choose]->copy();

}

Item * EntityPool::getRandomItem(int lvl) {
    std::vector<Item *> il = getItemList(lvl);
    int choose = rand() % il.size();
    return il[choose]->pointcopy();
}
