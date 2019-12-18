#include <string>
#include <windows.h>
#include <winbase.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
#include "EntityPool.h"


Game::Game(EntityPool * ep) : entityPool(ep)
{
    initscr();
    curs_set(0);
    noecho();
    resize_term(MAX_ROW,MAX_COL);

    playarea = newwin(MAX_P_ROW, MAX_P_COL, 2, 0);
    envtextarea = newwin(2,MAX_P_COL,0,0);
    statarea = newwin(2,MAX_P_COL,MAX_P_ROW+2,0);
    invenarea = newwin(MAX_P_ROW,14,2,MAX_P_COL+4);

    currentCharacter = new Character();
    currentFloor = new Floor(ep, currentCharacter->getLevel());
}

Game::~Game()
{
    //dtor
}

void Game::startGame() {
    gameLoop();
}

void Game::gameLoop() {
    while (1) {
        timeStep();
        draw();
        //if (currentCharacter->isDead()) {
        //    failScreen();
        //    break;
        //}
        currentCharacter->printQueue(envtextarea);
        getInput();
    }
}

void Game::draw() {
    clearWindows();
    currentFloor->draw(playarea);
    currentCharacter->draw(playarea);
    refresh();
    wrefresh(playarea);
    currentCharacter->drawInventory(invenarea, false);
    currentCharacter->drawStats(statarea);
}

void Game::getInput() {
    bool advance = false;
    int nx = currentCharacter->getX();
    int ny = currentCharacter->getY();
    while (!advance) {
        char in = wgetch(playarea);
        switch (in) {
            case 'q': ny--; nx--; advance = true; break;
            case 'w': ny--; advance = true; break;
            case 'e': ny--; nx++; advance = true; break;
            case 'a': nx--; advance = true; break;
            case 's': advance = true; break;
            case 'd': nx++; advance = true; break;
            case 'z': ny++; nx--; advance = true; break;
            case 'x': ny++; advance = true; break;
            case 'c': ny++; nx++; advance = true; break;
            case 'i': currentCharacter->handleInventory(invenarea); break;
            case ';': currentFloor->pickUpItem(currentCharacter); break;
        }
    }
    if (!(nx < 1 || nx > (MAX_P_COL-2) || ny < 1 || ny > (MAX_P_ROW-2))) {
        currentCharacter->setX(nx);
        currentCharacter->setY(ny);
    }
}

void Game::clearWindows() {
    wclear(playarea);
    wclear(envtextarea);
    wclear(statarea);
    wclear(invenarea);
    clear();
}

void Game::timeStep() {
    currentFloor->enemyMovement(currentCharacter);
}
