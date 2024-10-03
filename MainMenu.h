#pragma once
#include <iostream>
//#include "MainCharacteristic.h"
#include "Hero.h"
#include <fstream>
#include <filesystem> // Ѕиблиотека дл€ работы с файловой системой (в данном случае создание папки дл€ сохранени€) –аботает на стандарте с —++17
#include <Windows.h>
#include "Game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

class MainMenu
{
    enum MENU { EXIT = 0, NEWGAME, LOAD, SAVE, BACKTOGAME, ABOUTGAME};
    bool gameRunning{};
    Game& game = Game::getInstance();
public:
    MainMenu() : gameRunning{ false } {} // конструктор: текуща€ игрова€ сесси€ еще не запущена (только что запустили игру)
	void displayMainMenu();
    void selectMainMenu();
    void newGame();
    void loadGame();
    void saveGame();
    void backToGame();
    void aboutGame();
    void exitGame();
};
