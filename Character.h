#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <queue>
#include "Entity.h"
#include "Item.h"

class Item;

class Character : public Entity
{
    public:
        Character();
        virtual ~Character();
        void movement();

        int getLevel();
        int fullAtk();
        int fullDef();
        void drawInventory(WINDOW * invenarea, bool mode);
        void handleInventory(WINDOW * invenarea);
        void drawStats(WINDOW * statarea);
        void addItemToInventory(Item * it);

        void heal(int value);
        void applyArmor(Item * it);
        void applyWeapon(Item * it);

        void pushMsg(char * msg);
        void printQueue(WINDOW * msgarea);
        void instantMessage(WINDOW * msgarea, char * msg);
        void takeDamage(int atk);

    protected:

    private:
        int health = 20;
        int atk = 5;
        int def = 2;
        int level = 1;
        int exp = 0;
        Item * currentArmor = nullptr;
        Item * currentWeapon = nullptr;
        std::vector<Item *> inventory;
        std::queue<char *> msgs;
};

#endif // CHARACTER_H
