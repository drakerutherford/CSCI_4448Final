#include <string>
#include "Item.h"
#include "Entity.h"
#include "ItemStrategy.h"
#include "HealStrategy.h"
#include "WeaponStrategy.h"
#include "ArmorStrategy.h"

Item::Item(std::string _name, std::string type, int _value, int _lvl, char _c) : name(_name), value(_value), lvl(_lvl), Entity(_c) {
    if (type.compare("ARMOR")==0) {
        is = new ArmorStrategy();
        consumable = false;
    }
    else if (type.compare("HEAL")==0) {
        is = new HealStrategy();
        consumable = true;
    }
    else if (type.compare("WEAPON")==0) {
        is = new WeaponStrategy();
        consumable = false;
    }
    equipped = false;
}

Item::~Item()
{
   // delete is;
}

void Item::use(Character * c) {
    is->use(c, this);
}

std::string Item::print() {
    char buf[256];
    sprintf(buf, "Name:%s\nType:%s\nValue:%d\nLevel:%d\nChar:%c\n",name.c_str(), is->print().c_str(), value, lvl, sprite);
    std::string s(buf);
    return s;
}

Item Item::copy() {
    return Item(name, is->print(), value, lvl, sprite);
}

Item * Item::pointcopy() {
    return new Item(name, is->print(), value, lvl, sprite);
}

std::string Item::getName() {
    return name;
}

int Item::getValue() {
    return value;
}

void Item::setEquip(bool b) {
    equipped = b;
}

bool Item::getEquip() {
    return equipped;
}

bool Item::getConsumable() {
    return consumable;
}
