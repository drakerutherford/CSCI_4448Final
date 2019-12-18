#include "WeaponStrategy.h"

WeaponStrategy::WeaponStrategy()
{
    //ctor
}

WeaponStrategy::~WeaponStrategy()
{
    //dtor
}

void WeaponStrategy::use(Character * c, Item * it) {
    c->applyWeapon(it);
}

std::string WeaponStrategy::print() {return "WEAPON";}
