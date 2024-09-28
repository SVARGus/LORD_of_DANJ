#pragma once
#include "MainCharacteristic.h"
#include "Hero.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

class MainMenu
{
    enum MENU { EXIT = 0, NEWGAME, LOAD, SAVE, BACKTOGAME, ABOUTGAME};
	bool gameRunning{};
	MainMenu() : gameRunning{false}{} // конструктор: текущая игровая сессия еще не запущена (только что запустили игру)
public:
	void displayMainMenu();
    void selectMainMenu();
    void newGame();
    void loadGame();
    void saveGame();
    void backToGame();
    void aboutGame();
    void exitGame();
};
void MainMenu::displayMainMenu() {
    cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;;
    cout << "\t\t\tГЛАВНОЕ МЕНЮ" << endl << endl;;
    cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;
    cout << "\t\t\tNEWGAME - 1" << endl << endl;
    cout << "\t\t\tLOADING - 2" << endl << endl;
    if (gameRunning == false)
    {
        cout << "\t\t\tSAVING - 3" << endl << endl;
        cout << "\t\t\tBACK - 4" << endl << endl;
    }
    cout << "\t\t\tBACK - 4" << endl << endl;
    cout << "\t\t\tABOUT GAME - 0" << endl << endl;
}
void MainMenu::selectMainMenu() {
    switch (char c(getchar()); c) // Используется с 17 стандарта
    {
    case NEWGAME:
        newGame();
        break;
    case LOAD:
        loadGame();
        break;
        if (gameRunning)
        {
        case SAVE:
            saveGame();
            break;
        case BACKTOGAME:
            backToGame();
            break;
        }
    case ABOUTGAME:
        aboutGame();
        break;
    case EXIT:
        exitGame();
        //cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
        //*MenuVillage = 0;
        //exit(0); // Завершение программы. Для этого подключил библиотеку <stdlib.h>, она является стандартной и возможно не требует отдельного подключения
        break;
    default:
        cout << "Некорректный выбор ";
    }
}
void MainMenu::newGame() {

}
void MainMenu::loadGame() {

}
void MainMenu::saveGame() {

}
void MainMenu::backToGame() {

}
void MainMenu::aboutGame() {

}
void MainMenu::exitGame() {

}
