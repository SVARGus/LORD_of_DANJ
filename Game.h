#pragma once
#include <iostream>
//#include "MainCharacteristic.h"
//#include "Hero.h"
//#include "MainMenu.h"
//#include <fstream>
//#include <filesystem> // Библиотека для работы с файловой системой (в данном случае создание папки для сохранения) Работает на стандарте с С++17
//#include <Windows.h>
//#include "Village.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
//using std::fstream;
//using std::ifstream;
//using std::ofstream;

class MainMenu;
class Village;

class Game // Класс реализован по паттерну Singleton, так как игровой цикл может быть только один
{
public:
	enum State { MAIN_MENU, VILLAGE, TAVERN, SHOP, DANJ, EXIT };
private:
	MainMenu* mainMenu{ nullptr };
	Village* village{ nullptr };
	State currentState; // Текущее состояние
	State previousState; // Предыдущее состояние для возможности возврата
	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	//static Game* instance;
public:
	static Game& getInstance() {
		static Game instance;
		return instance;
	}
	void run(); // Запуск основного игрового цикла
	void setState(State newState); // Установка нового статуса
	void backState(); // Возврат к предыдущему статусу
};
