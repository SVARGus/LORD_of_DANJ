#pragma once
#include <iostream>
#include "MainCharacteristic.h"
#include <fstream>
#include <string>
#include "Inventory.h"
#include "Weapon.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

// Класс будет переделан в Singleton, так герой будет всегда один и для удосбства доступа.

class Hero : public MainCharacteristic
{
	int freePoints{};
	int scalExp{};
	int scalExpUp{};
	int winBattle{};
	int openLvlDanj{};
	//# InventoryWeapon : array<Weapon, 2> // добавить после реализации классов с оружием
	int Money{}; // позже вывести в отдельный класс для возможности взаимодействия с Магазином,Таверной, выпадение с монстров и других возможностей в будущем

	Hero(string name) : MainCharacteristic(name), freePoints{ 10 } {}; // Приватный конструктор для невозможности создать объект извне.
	Hero(const Hero&) = delete; // Удален конструктор копирования согласно принципу паттерна Singleton
	Hero& operator= (const Hero&) = delete; // Удален оператор присвоения согласно принципу паттерна Singleton
	//Hero() {} // нужен ли?
	Inventory inventory{"Рюкзак героя"}; // Инвентарь героя
	Weapon* equippedFirstWeapon{ nullptr }; // Экипированное оружие в одной руке
	//Weapon* equippedSecondWeapon{ nullptr };// Экипированное оружие во второй руке
public:
	//friend class MainMenu;
	// friend class MainMenu Объявляется как дружественный класс для возможности загрузки и сохранения героя в классе MainMenu без нарушения принципа инкапсуляции
	// Это позволить MainMenu напрямую работать с приватными членами класса Hero. Возможно стоит также сделать в других классах его дружественным,
	// если от туда будут записываться данные.
	static Hero& init(const string& name) {
		static Hero instance(name);
		return instance;
	}
	static Hero& getInstance() {
		static Hero instance("NoName");
		return instance;
	}
	// Методы класса (будут дополняться по необходимости)
	void recalculateCharacteristic();
	void displayCharacteristic() const;
	void takeDamage(int attack);
	void distrPointHero();
	void rebootStartHero(); // Обнуления статов игрока до стартовых статов.
	// добавить метод сохранения и загрузки из файла данных героя? или в меню реализовать? // Добавил методы сохранения и загрузки в сам класс (текстовый и бинарный)
	void saveToBinary(ofstream& outFile) const;
	void loadFromBinary(ifstream& inFile);
	void saveToText(ofstream& outFile) const;
	void loadFromText(ifstream& inFile);
	// геттеры
	int getFreepoints() const { return freePoints; }
	int getScalExp() const { return scalExp; }
	int getScalExpUp() const { return scalExpUp; }
	int getWinBattle() const { return winBattle; }
	int getOpenLvlDanj() const { return openLvlDanj; }

	// Методы для взаимодествия с инвентарем и предметами Items, а также те методы которые надо переделать
	int attack(); // Переделать под возможность использования оружия

	void displayInventory(); // Полный вывод предметов в инвенторе с урезанной информацией
	void displayInventory(int index); // вывод на экран определенного предмета со всей информацией
	void equipFirstWeapon(int index); // Экипировка оружия из инвентаря в первую руку
	void equipSecondWeapon(int index); // Экипировка оружия из инвентаря во вторую руку
	void unEquipFirstWeapon(int index); // Снять оружие 
	void unEquipSecondWeapon(int index); // Снять оружие
	void addItemToInventory(Items* item); // Метод добавления предмета в инвентарь
	void transferItemTo(Inventory& other, int index); // Метод передачи предмета из своего инвентаря в другой инвентарь (сундук, магазин)
};

