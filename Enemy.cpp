#include <stdio.h>
#include <string>
#include "Enemy.h"
#include "Entity.h"
#include "Variables.h"

Enemy::Enemy(std::string _name, int _health, int _def, int _atk, int _level, int _exp, char _c) :
    name(_name), health(_health), def(_def), atk(_atk), level(_level), exp(_exp), Entity(_c) {}

Enemy::~Enemy()
{
    //dtor
}

std::string Enemy::print() {
    char buf[256];
    sprintf(buf, "Name:%s\nHealth:%d\nAttack:%d\nDefense:%d\nExp:%d\nLevel:%d\nChar:%c\n",name.c_str(), health, atk, def, exp, level, sprite);
    std::string s(buf);
    return s;
}

Enemy Enemy::copy() {
    return Enemy(name, health, def, atk, level, exp, sprite);
}

void Enemy::movement(Character * c) {
    int nx = xcoord;
    int ny = ycoord;

    int tx = c->getX();
    int ty = c->getY();

    if (nx < tx) nx++;
    else if (nx > tx) nx--;
    if (ny < ty) ny++;
    else if (ny > ty) ny--;

    if (nx==tx && ny==ty) {
        c->takeDamage(atk);
        char buf[256];
        sprintf(buf, "The %s strikes!", name.c_str());
        c->pushMsg(buf);
    }
    else {
        xcoord = nx;
        ycoord = ny;
    }
}

void Enemy::takeDamage(Character * c) {
    health -= c->fullAtk() - def;
    char buf[256];
    sprintf(buf, "You strike the %s!", name.c_str());
    c->pushMsg(buf);
}
