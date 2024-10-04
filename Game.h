#pragma once
#include <iostream>
//#include "MainCharacteristic.h"
//#include "Hero.h"
//#include "MainMenu.h"
//#include <fstream>
//#include <filesystem> // ���������� ��� ������ � �������� �������� (� ������ ������ �������� ����� ��� ����������) �������� �� ��������� � �++17
//#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;
//using std::fstream;
//using std::ifstream;
//using std::ofstream;

class MainMenu;

class Game // ����� ���������� �� �������� Singleton, ��� ��� ������� ���� ����� ���� ������ ����
{
public:
	enum State { MAIN_MENU, VILLAGE, TAVERN, SHOP, DANJ, EXIT };
private:
	MainMenu* mainMenu; // �����-��� ������???
	State currentState; // ������� ���������
	State previousState; // ���������� ��������� ��� ����������� ��������
	Game();
	~Game();
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	//static Game* instance;
public:
	static Game& getInstance() {
		static Game instance;
		return instance;
	}
	void run(); // ������ ��������� �������� �����
	void setState(State newState); // ��������� ������ �������
	void backState(); // ������� � ����������� �������
};
