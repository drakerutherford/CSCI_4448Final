#ifndef ENTITY_H
#define ENTITY_H

#include <curses.h>

class Entity
{
    public:
        Entity(char s);
        virtual ~Entity();

        int getX();
        int getY();
        int getSprite();

        void setX(int x);
        void setY(int y);
        void setSprite(char s);

        void draw(WINDOW * playarea);

    protected:
        int xcoord = 0;
        int ycoord = 0;
        char sprite;

    private:
};

#endif // ENTITY_H
