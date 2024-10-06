#pragma once
#include "Hero.h"
#include <Windows.h>
#include "Game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
class Village
{
	enum Menu { SHOP = 1, TAVERN, DANJ, HERO, MAIN_MENU};
	//Game& game = Game::getInstance();
	Hero& player = Hero::getInstance();
	string nameVillage{ "Transilvania" }; // ���� ����� ���� ������� � ������� ���������. � ������� ����� ��������� ��������� � ����� ����� �������������� ����� ����
	//Danj danj{} // ��� ������� ��������� ����� ���� ���������� ���� �� ������ �����������! ����������������� ����� ���������
	//Shop shop{} // ��� ������� ��������� ����� ���� ���������� ������� �� ������ �����������! ����������������� ����� ���������
	//Taver tavern{} // ��� ������� ��������� ����� ���� ���������� ������� �� ������ �����������! ����������������� ����� ���������
public:
	Village() {}
	~Village() {}
	string getNameVillage() { return nameVillage; }
	void displayMenuVillage();
	void menuVillage();
};

