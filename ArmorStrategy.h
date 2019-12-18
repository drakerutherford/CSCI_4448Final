#ifndef ARMORSTRATEGY_H
#define ARMORSTRATEGY_H

#include "ItemStrategy.h"
#include "Character.h"

class ArmorStrategy : public ItemStrategy
{
    public:
        ArmorStrategy();
        virtual ~ArmorStrategy();

        void use(Character * c, Item * it);
        std::string print();

    protected:

    private:
};

#endif // ARMORSTRATEGY_H
