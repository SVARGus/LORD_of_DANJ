#pragma once
#include <iostream>
#include <vector>
#include "Items.h"
#include "Weapon.h"
#include <fstream>
//#include "Equipment.h" // Позже будет добавлен
//#include "OtherItems.h" // Позже будет добавлен

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class Inventory
{
	vector<Items*> inventoryItems;
	ItemFactory* factory;
	string nameInventory{}; // Добавляет инветарю название
	//int sizeInventory{}; // в будущем можно будет ограничивать инветарь и ввести рюкзаки разной вместитеьностью и прочими характеристиками.
public:
	Inventory(string name) : nameInventory{ name } {}
	//
	string getNameInventory() { return nameInventory; }
	void setNameInventory(string name) { nameInventory = name; }
	// Методы для первичной реализации
	void addItem(Items* item); // Метод добавления предмета в инвентарь (например при выполнеия задания награда забирается в рюкзан) // После добавления размера инветоря нужно будет добавить методы на проверку переполнения инвентаря
	void removItem(int index); // Метод удаления (выбрасывания) предмета из рюкзака по индексу
	void transferItem(Inventory& other, int index); // Метод трансфера между инветорями (например между игроком и магазином). index (индекс) предмеа текущего инвентаря добавить в other (другой) инветарь
	void displayInventory() const; // Полный вывод инветоря с минимальными данными
	void displayInventory(int index) const; // Вывод конкретного предмета из инвентаря со всеми характеристиками 
	Items* getItem(int index); // Получение предмета по индексу
	// Методы для вторичной реализации
	void saveInventoryToBinary(ofstream& outFile) const; // Метод сохранения инвенторя в Бинарный файл
	void loadInventoryFromBinary(ifstream& inFile); // Метод сохранения инвенторя в Текстовый файл
	void saveInventoryToText(ofstream& outFile) const; // Метод загрузки инвенторя из Бинарного файла
	void loadInventoryFromText(ifstream& inFile); // Метод загрузки инвенторя из Текстового файла
	void replaceItem(int index, Items* newItem); // метод замены предмета по индексу на новый
	// методы на будущее - пока не будут реализованы или будут иметь заглушку
	void sortInventoryBy(const string& criterion); // Метод сортировки по разным критериям
	Items* findItemByName(const string& name); // Метод поиска по имени // Можно реализовать также по различным критериям при необходимости
	int countItemsById(const string& idIndex); // Подсчет количество одинаковых предметов // Можно реализовать также по различным критериям при необходимости, напримет по имени и типам
	void clearInventory(); // Метод полной очистки инветаря
	double calculatedTotalWeight() const; // Подсчет общего веса инвентаря (в рюкзаке могут быть ограничения по весу или перегруз влияет на подвижность героя)
	double calculatedTotalValue() const; // Оценка стоимости всех предметов инвентаре
	bool hasItem(const string& name) const; // Проверка наличия предмета по имения (например есть ли квестовый предмет в инвентаре для выполнения задания)
	bool isFullInventory() const; // Проверка на заполненность инвенторя
	void stackIdenticalItems(); // Метод объединения одинаковых предметов в стак
};

