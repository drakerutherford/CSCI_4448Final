#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "Entity.h"
#include "Character.h"

class Enemy : public Entity
{
    public:
        Enemy(std::string _name, int _health, int _def, int _atk, int _level, int _exp, char _c);
        virtual ~Enemy();
        void movement(Character * c);
        Enemy copy();
        std::string print();

    protected:

    private:
        std::string name;
        int health;
        int atk;
        int def;
        int exp;
        int level;
};

#endif // ENEMY_H
