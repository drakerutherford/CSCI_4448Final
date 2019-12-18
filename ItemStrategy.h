#ifndef ITEMSTRATEGY_H
#define ITEMSTRATEGY_H

#include <string>
#include "Character.h"

class Character;
class Item;

class ItemStrategy
{
    public:
        ItemStrategy();
        virtual ~ItemStrategy();

        virtual void use(Character * c, Item * it) = 0;
        virtual std::string print() = 0;

    protected:

    private:
};

#endif // ITEMSTRATEGY_H
