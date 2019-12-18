#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <cmath>
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

    for (int i = 0; i < MAX_P_COL; i++) {
        for (int j = 0; j < MAX_P_ROW; j++) {
            visible[i][j] = false;
        }
    }
}

Floor::~Floor()
{
    //dtor
}

void Floor::draw(WINDOW * playarea) {
    for (int i = 0; i < MAX_P_ROW; i++) {
        for (int j = 0; j < MAX_P_COL; j++) {
            if (visible[j][i]) {
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
    }

    for (int i = 0; i < items.size(); i++) {
        if (visible[items[i]->getX()][items[i]->getY()])
            items[i]->draw(playarea);
    }

    for (int i = 0; i < enemies.size(); i++) {
        if (visible[enemies[i].getX()][enemies[i].getY()])
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

int clamp(int in, int r, int l) {
    if (in > r) return r;
    else if (in < l) return l;
    else return in;
}

void Floor::updateVisibility(Character * c) {
    int sight_radius = 4;
    int top = clamp(c->getY()-sight_radius,MAX_P_ROW-1,0);
    int bottom = clamp(c->getY()+sight_radius,MAX_P_ROW-1,0);
    int left = clamp(c->getX()-sight_radius,MAX_P_COL-1,0);
    int right = clamp(c->getX()+sight_radius,MAX_P_COL-1,0);
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (pow(i-c->getY(),2)+pow(j-c->getX(),2)<=pow(sight_radius,2))
                visible[j][i] = true;
        }
    }
}

bool Floor::checkAttack(Character * c, int nx, int ny) {
    bool ret = false;
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].getX()==nx && enemies[i].getY()==ny) {
            enemies[i].takeDamage(c);
            ret = true;
        }
    }
    return ret;
}
