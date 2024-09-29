#pragma once
#include <iostream>
#include "MainCharacteristic.h"
#include "Hero.h"
#include <fstream>
#include <filesystem> // ���������� ��� ������ � �������� �������� (� ������ ������ �������� ����� ��� ����������) �������� �� ��������� � �++17
#include <Windows.h>

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
        // return Village // ���� ����������� ������� � ������� ���� �������� �������� (����� �������� ����� ������� ������� � ����� ������ � ���� ���������, ���� ��� �������� �� � ����� ��������� (��� �������� ��� �������� ��������, �� ��� ������������� �������� Singletone
        break;
    case LOAD:
        loadGame();
        // return Village // ���� ����������� ������� � ������� ���� �������� �������� (����� �������� ����� ������� ������� � ����� ������ � ���� ���������, ���� ��� �������� �� � ����� ��������� (��� �������� ��� �������� ��������, �� ��� ������������� �������� Singletone
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
        break;
    default:
        cout << "������������ ����� ";
    }
}
void MainMenu::newGame() {
    Hero& player = Hero::getInstance();
    char Y_N{};
    do
    {
        cout << "������� ��� ���: ";
        cin >> player.name;
        cout << "��� ���: " << player.getName() << endl;
        cout << "������������� �����? ��(Y) - ���(N) ";
        cin >> Y_N;
    } while (Y_N == 'N' || Y_N == 'n');
    while (player.getFreepoints() > 0)
    {
        player.distrPointHero();
    }
    player.recalculateCharacteristic();
    // ����� ������ ���� ������� � ����� ������� � ������� �� �������� ���� (���� �������� ��� �����������)


    gameRunning = true; // �������� ���� ������� ������� ������
}
void MainMenu::loadGame() { // ����� ������� ���� ������� �������� � ����������
    const string binaryDirect{ "Save_LORD_of_DANJ\\Savegame.bin" };
    const string textDirect{ "Save_LORD_of_DANJ\\Savegame.txt" };

    ifstream myFileBinary(binaryDirect, std::ios::binary);
    if (myFileBinary.is_open())
    {
        Hero& player = Hero::getInstance();
        player.loadFromBinary(myFileBinary);
        myFileBinary.close();
        cout << "���� ��������� �� ��������� �����!" << endl;
    }

    ifstream myFileText(textDirect);
    if (myFileText.is_open())
    {
        Hero& player = Hero::getInstance();
        player.loadFromText(myFileText);
        myFileText.close();
        cout << "���� ��������� �� ���������� �����!" << endl;
    }
    gameRunning = true; // �������� ���� ������� ������� ������
}
void MainMenu::saveGame() { // ����� ������� ���� ������� �������� � ����������
    //ofstream myFile;
    std::filesystem::path SaveGame = "Save_LORD_of_DANJ"; // ������� ����� ��� ����������
    if (!std::filesystem::exists(SaveGame))
        std::filesystem::create_directories(SaveGame);

    const string binaryDirect{ "Save_LORD_of_DANJ\\Savegame.bin" };
    const string textDirect{ "Save_LORD_of_DANJ\\Savegame.txt" };

    ofstream myFileBinary(binaryDirect, std::ios::binary | std::ios::trunc);
    if (myFileBinary.is_open())
    {
        Hero& player = Hero::getInstance();
        player.saveToBinary(myFileBinary);
        myFileBinary.close();
        cout << "���� ����������� � �������� ����!" << endl; 
    }

    ofstream myFileText(textDirect, std::ios::trunc);
    if (myFileText.is_open())
    {
        Hero& player = Hero::getInstance();
        player.saveToText(myFileText);
        myFileText.close();
        cout << "���� ����������� � ��������� ����!" << endl;
    }
}
void MainMenu::backToGame() {
    // ����� �������� ��� ��������� � ������� ������, � ������ ������ ������� � ����� ������� � ����� �� �������� ����
}
void MainMenu::aboutGame() {

}
void MainMenu::exitGame() {
    cout << "\n\t\t������� �� ����! ����� ��� ����� �����!\n\n";
    exit(0);
}
