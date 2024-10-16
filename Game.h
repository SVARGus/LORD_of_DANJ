#pragma once
#include <iostream>
//#include "MainMenu.h"
//#include "Village.h"
#include "Weapon.h"
#include "Items.h"
#include <vector>
#include "Monster.h"

class MainMenu;
class Village;
class Danj;

class Game // ����� ���������� �� �������� Singleton, ��� ��� ������� ���� ����� ���� ������ ����
{
public:
	enum State { MAIN_MENU, VILLAGE, TAVERN, SHOP, DANJ, EXIT };
	vector<Weapon*> baseWeapon;  // ���� ������ ������
	vector<Monster*> baseMonster; // ���� ��������
	//vector<Equipment*> baseEquipment;  // ���� ������ ��������
	//vector<Items*> baseOtherItems;  // ���� ������ ������ ���������
private:
	MainMenu* mainMenu{ nullptr };
	Village* village{ nullptr };
	Danj* danj{ nullptr };
	State currentState; // ������� ���������
	State previousState; // ���������� ��������� ��� ����������� ��������

	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void loadBaseWeapons();  // �������� ���� ������
	//void loadBaseEquipment();  // �������� ���� ��������
	//void loadBaseOtherItems();  // �������� ������ ���������
	void loadBaseMonster(); // �������� ���� ��������
public:
	static Game& getInstance() {
		static Game instance;
		return instance;
	}
	void run(); // ������ ��������� �������� �����
	void setState(State newState); // ��������� ������ �������
	void backState(); // ������� � ����������� �������
};