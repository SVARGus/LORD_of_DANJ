/*
Проект Игры LORD of DANJ
Курсовая работа по основам С++.
Переделка под ООП на С++ с применение паттернов

*/

#include <iostream>
#include "Game.h"
#include "MainMenu.h"


int main()
{
    setlocale(LC_ALL, "ru");
    //srand(time(NULL));

    Game &newGame = Game::getInstance();
    newGame.run();

    return 0;
}