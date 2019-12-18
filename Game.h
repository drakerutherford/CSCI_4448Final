#ifndef GAME_H
#define GAME_H

#include <string>
#include <curses.h>
#include "Character.h"
#include "Floor.h"
#include "EntityPool.h"
#include "Variables.h"

class Game
{
    public:
        Game(EntityPool * ep);
        virtual ~Game();

        void startGame();

    private:
        //game logic
        void gameLoop();
        void timeStep();
        void getInput();
        void updateState();
        void draw();
        void handleInventory();
        void movement();
        void clearWindows();

        //variables
        Character * currentCharacter;
        Floor * currentFloor;
        EntityPool * entityPool;

        //windows
        WINDOW * playarea;
        WINDOW * envtextarea;
        WINDOW * statarea;
        WINDOW * invenarea;

};

#endif // GAME_H
