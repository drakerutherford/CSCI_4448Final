#include <curses.h>
#include <string>
#include <string.h>
#include "Character.h"
#include "Item.h"
#include "Variables.h"

Character::Character() : Entity('@')
{
    xcoord = 1;
    ycoord = 1;
}

Character::~Character()
{
    //dtor
}

int Character::getLevel() {
    return level;
}

void Character::drawInventory(WINDOW * invenarea, bool mode) {
    wclear(invenarea);
    mvwaddstr(invenarea, 0, 0, "--INVENTORY--");
    if (inventory.size()>0) {
        for (int i = 0; i < inventory.size(); i++) {
            mvwaddstr(invenarea, i+1, 0, inventory[i]->getName().c_str());
            if (inventory[i]->getEquip()) mvwaddch(invenarea, i+1, strlen(inventory[i]->getName().c_str()), '*');
        }
    }
    else if (mode) {
        mvwaddstr(invenarea, 1, 0, "Your inventoryis empty!");
    }
    wrefresh(invenarea);
}

void Character::handleInventory(WINDOW * invenarea) {
    bool in_inv = true;
    int selection = 1;
    while (in_inv) {
        drawInventory(invenarea, true);
        if (inventory.size() > 0) {
            mvwaddstr(invenarea, selection, strlen(inventory[selection-1]->getName().c_str()), "<--");
        }
        wrefresh(invenarea);
        char in = getch();
        switch (in) {
            case 'w':
                if (selection > 1) selection--;
                break;
            case 'x':
                if (selection<inventory.size()) selection++;
                break;
            case ';':
                if (inventory.size() > 0) {
                    inventory[selection-1]->use(this);
                    if (inventory[selection-1]->getConsumable()) {
                        inventory.erase(inventory.begin()+selection-1);
                        if (inventory.size() > 0) selection--;
                    }
                }
                break;
            case 'i':
                in_inv = false;
                drawInventory(invenarea, false);
                wrefresh(invenarea);
                break;
        }
    }
}

void Character::addItemToInventory(Item * it) {
    inventory.push_back(it);
}

int Character::fullAtk() {
    int ret = atk;
    if (currentWeapon != nullptr) {
        ret += currentWeapon->getValue();
    }
    return ret;
}

int Character::fullDef() {
    int ret = def;
    if (currentArmor != nullptr) {
        ret += currentArmor->getValue();
    }
    return ret;
}

void Character::drawStats(WINDOW * statarea) {
    wclear(statarea);
    char statstr[MAX_P_COL*3];
    sprintf(statstr, "HP: %d ATK: %d DEF: %d LVL: %d EXP: %d", health, fullAtk(), fullDef(), level, exp);
    mvwaddstr(statarea, 0, 0, statstr);
    wrefresh(statarea);
}

void Character::heal(int value) {
    health += value;
}

void Character::applyArmor(Item * it) {
    if (currentArmor != nullptr) {
        currentArmor->setEquip(false);
    }
    currentArmor = it;
    it->setEquip(true);
}

void Character::applyWeapon(Item * it) {
    if (currentWeapon != nullptr) {
        currentWeapon->setEquip(false);
    }
    currentWeapon = it;
    it->setEquip(true);
}

void Character::pushMsg(char * msg) {
    int len = strlen(msg);
    char * ptr = (char*)malloc(sizeof(char)*(len+1));
    strcpy(ptr,msg);
    msgs.push(ptr);
}

void Character::printQueue(WINDOW * msgarea) {
    char in;
    while (!msgs.empty()) {
        werase(msgarea);
        mvwaddstr(msgarea, 0, 0, msgs.front());
        free(msgs.front());
        msgs.pop();
        if (msgs.size() > 0) waddstr(msgarea, "--MORE--");
        wrefresh(msgarea);
        if (!msgs.empty()) {
            in = wgetch(msgarea);
            while (in != ' ') {in = wgetch(msgarea);}
        }
    }
}

void Character::instantMessage(WINDOW * msgarea, char * msg) {
    pushMsg(msg);
    printQueue(msgarea);
}

void Character::takeDamage(int atk) {
    health -= atk - fullDef();
}
