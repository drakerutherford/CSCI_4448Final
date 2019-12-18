#ifndef WEAPONSTRATEGY_H
#define WEAPONSTRATEGY_H

#include "ItemStrategy.h"
#include "Character.h"

class WeaponStrategy : public ItemStrategy
{
    public:
        WeaponStrategy();
        virtual ~WeaponStrategy();

        void use(Character * c, Item * it);
        std::string print();

    protected:

    private:
};

#endif // WEAPONSTRATEGY_H
