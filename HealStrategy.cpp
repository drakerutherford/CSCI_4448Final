#include "HealStrategy.h"

HealStrategy::HealStrategy()
{
    //ctor
}

HealStrategy::~HealStrategy()
{
    //dtor
}

void HealStrategy::use(Character * c, Item * it) {
    c->heal(it->getValue());
}

std::string HealStrategy::print() {return "HEAL";}
