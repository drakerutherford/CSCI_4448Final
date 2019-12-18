#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <array>
#include "FileLoader.h"
#include "EntityPool.h"
#include "Enemy.h"
#include "Item.h"

FileLoader::FileLoader()
{
    //ctor
}

FileLoader::~FileLoader()
{
    //dtor
}

void FileLoader::loadFiles(EntityPool * ep) {
    loadEnemies(ep);
    loadItems(ep);
}

void FileLoader::loadEnemies(EntityPool * ep) {
    std::fstream infile("enemies.txt");
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream tokenize(line);
        std::string intermediate;
        std::getline(tokenize, intermediate, ' ');
        if (intermediate.compare("Enemy:")==0){
            std::getline(tokenize, intermediate, ' ');
            std::string name = intermediate;
            std::getline(infile, intermediate);
            int hp = std::stoi(intermediate);
            std::getline(infile, intermediate);
            int atk = std::stoi(intermediate);
            std::getline(infile, intermediate);
            int def = std::stoi(intermediate);
            std::getline(infile, intermediate);
            int exp = std::stoi(intermediate);
            std::getline(infile, intermediate);
            int lvl = std::stoi(intermediate);
            char c;
            infile.get(c);
            Enemy * e = new Enemy(name, hp, def, atk, lvl, exp, c);
            ep->addEnemy(lvl, e);
        }
    }
    infile.close();
}

void FileLoader::loadItems(EntityPool * ep) {
    std::fstream infile("items.txt");
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream tokenize(line);
        std::string intermediate;
        std::getline(tokenize, intermediate, ' ');
        if (intermediate.compare("Item:")==0){
            std::getline(tokenize, intermediate, '\n');
            std::string name = intermediate;
            std::getline(infile, intermediate);
            std::string type = intermediate;
            std::getline(infile, intermediate);
            int value = std::stoi(intermediate);
            std::getline(infile, intermediate);
            int lvl = std::stoi(intermediate);
            char c;
            infile.get(c);
            Item * i = new Item(name, type, value, lvl, c);
            ep->addItem(lvl, i);
        }
    }
    infile.close();
}
