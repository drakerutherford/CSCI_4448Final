#include <curses.h>
#include "Entity.h"

Entity::Entity(char s) : sprite(s) {}

Entity::~Entity()
{
    //dtor
}

int Entity::getX() {
    return xcoord;
}
int Entity::getY() {
    return ycoord;
}
int Entity::getSprite(){
    return sprite;
}

void Entity::setX(int x) {
    xcoord = x;
}
void Entity::setY(int y) {
    ycoord = y;
}
void Entity::setSprite(char s) {
    sprite = s;
}

void Entity::draw(WINDOW * playarea) {
    mvwaddch(playarea,ycoord,xcoord,sprite);
}
