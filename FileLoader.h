#ifndef FILELOADER_H
#define FILELOADER_H

#include "EntityPool.h"

class FileLoader
{
    public:
        FileLoader();
        virtual ~FileLoader();

        static void loadFiles(EntityPool * ep);

    protected:

    private:
        static void loadEnemies(EntityPool * ep);
        static void loadItems(EntityPool * ep);
};

#endif // FILELOADER_H
