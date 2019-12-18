#ifndef HEALSTRATEGY_H
#define HEALSTRATEGY_H

#include "ItemStrategy.h"
#include "Character.h"


class HealStrategy : public ItemStrategy
{
    public:
        HealStrategy();
        virtual ~HealStrategy();

        void use(Character * c, Item * it);
        std::string print();

    protected:

    private:
};

#endif // HEALSTRATEGY_H
