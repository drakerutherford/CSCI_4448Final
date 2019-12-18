#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include "Floor.h"
#include "Character.h"

Floor::Floor(EntityPool * ep, int level)
{
    exit_x = (rand() % (MAX_P_COL - 2)) + 1;
    exit_y = (rand() % (MAX_P_ROW - 2)) + 1;

    int num_monsters = rand() % 3;
    int num_items = rand() % 10;

    for (int i = 0; i < num_monsters; i++) {
        Enemy e = ep->getRandomEnemy(level);
        e.setX((rand() % (MAX_P_COL - 2)) + 1);
        e.setY((rand() % (MAX_P_ROW - 2)) + 1);
        enemies.push_back(e);
    }

    for (int i = 0; i < num_items; i++) {
        Item * it = ep->getRandomItem(level);
        it->setX((rand() % (MAX_P_COL - 2)) + 1);
        it->setY((rand() % (MAX_P_ROW - 2)) + 1);
        printf(it->print().c_str());
        items.push_back(it);
    }
}

Floor::~Floor()
{
    //dtor
}

void Floor::draw(WINDOW * playarea) {
    for (int i = 0; i < MAX_P_ROW; i++) {
        for (int j = 0; j < MAX_P_COL; j++) {
            if (i==0 || i==MAX_P_ROW-1 || j==0 || j==MAX_P_COL-1) {
                mvwaddch(playarea, i, j, '#');
            }
            else if (i==exit_y && j==exit_x) {
                mvwaddch(playarea, i, j, '>');
            }
            else {
                mvwaddch(playarea, i, j, '.');
            }
        }
    }

    for (int i = 0; i < items.size(); i++) {
        items[i]->draw(playarea);
    }

    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].draw(playarea);
    }
}

void Floor::pickUpItem(Character * c) {
    for (int i = 0; i < items.size(); i++) {
        Item * it = items[i];
        if (c->getX()==it->getX() && c->getY()==it->getY()) {
            c->addItemToInventory(it);
            items.erase(items.begin()+i);
            break;
        }
    }
}

void Floor::enemyMovement(Character * c) {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].movement(c);
    }
}
