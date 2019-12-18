#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "FileLoader.h"
#include "Game.h"
#include "FileLoader.h"
#include "EntityPool.h"

using namespace std;

int main()
{
    srand(time(NULL));
    EntityPool * ep = new EntityPool();
    FileLoader::loadFiles(ep);
    Game g = Game(ep);
    g.startGame();
    while (0) {

    }
    delete ep;
    return 0;
}
