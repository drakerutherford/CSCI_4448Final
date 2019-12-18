#include "ArmorStrategy.h"

ArmorStrategy::ArmorStrategy()
{
    //ctor
}

ArmorStrategy::~ArmorStrategy()
{
    //dtor
}

void ArmorStrategy::use(Character * c, Item * it) {
    c->applyArmor(it);
}

std::string ArmorStrategy::print() {return "ARMOR";}
