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

class Game // Класс реализован по паттерну Singleton, так как игровой цикл может быть только один
{
public:
	enum State { MAIN_MENU, VILLAGE, TAVERN, SHOP, DANJ, EXIT };
	vector<Weapon*> baseWeapon;  // База данных оружия
	vector<Monster*> baseMonster; // База монстров
	//vector<Equipment*> baseEquipment;  // База данных амуниции
	//vector<Items*> baseOtherItems;  // База данных прочих предметов
private:
	MainMenu* mainMenu{ nullptr };
	Village* village{ nullptr };
	Danj* danj{ nullptr };
	State currentState; // Текущее состояние
	State previousState; // Предыдущее состояние для возможности возврата

	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void loadBaseWeapons();  // Загрузка базы оружия
	//void loadBaseEquipment();  // Загрузка базы амуниции
	//void loadBaseOtherItems();  // Загрузка прочих предметов
	void loadBaseMonster(); // Загрузка базы монстров
public:
	static Game& getInstance() {
		static Game instance;
		return instance;
	}
	void run(); // Запуск основного игрового цикла
	void setState(State newState); // Установка нового статуса
	void backState(); // Возврат к предыдущему статусу
};