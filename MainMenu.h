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
	MainMenu() : gameRunning{false}{} // �����������: ������� ������� ������ ��� �� �������� (������ ��� ��������� ����)
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
    cout << "\t\t\t������� ����" << endl << endl;;
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
    switch (char c(getchar()); c) // ������������ � 17 ���������
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
        //cout << "\n\t\t������� �� ����! ����� ��� ����� �����!\n\n";
        //*MenuVillage = 0;
        //exit(0); // ���������� ���������. ��� ����� ��������� ���������� <stdlib.h>, ��� �������� ����������� � �������� �� ������� ���������� �����������
        break;
    default:
        cout << "������������ ����� ";
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
