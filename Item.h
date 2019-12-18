#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Entity.h"
#include "Character.h"
#include "ItemStrategy.h"

#define WEAPON 0
#define ARMOR 1
#define HEAL 2

class Character;
class ItemStrategy;

class Item : public Entity
{
    public:
        Item(std::string _name, std::string type, int _value, int _lvl, char _c);
        virtual ~Item();

        void use(Character * c);
        std::string print();
        Item copy();
        Item * pointcopy();

        std::string getName();
        int getValue();
        void setEquip(bool b);
        bool getEquip();
        bool getConsumable();

    protected:

    private:
        ItemStrategy * is;
        std::string name;
        int value;
        int lvl;
        bool equipped;
        bool consumable;
};

#endif // ITEM_H
