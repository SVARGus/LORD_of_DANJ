#pragma once
#include <iostream>
#include "MainCharacteristic.h"
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

class Monster : public MainCharacteristic
{
	string typeMonster{}; // Тип монстров (например скелеты, нежить, разбойники, ящеры, растения и другие) - возможно в будущем надо выделить в отдельный класс
	string descriptionMonster{}; // Описание моба
public:
	Monster() {}
	~Monster() {}
	void recalculateCharacteristic(int lvlDanj);
	void displayCharacteristic() const;
	int attack();
	void takeDamage(int attack);
	// добавить метод сохранения и загрузки из файла данных героя? или в меню реализовать? // Добавил методы сохранения и загрузки в сам класс (текстовый и бинарный)
	void saveToBinary(ofstream& outFile) const;
	void loadFromBinary(ifstream& inFile);
	void saveToText(ofstream& outFile) const;
	void loadFromText(ifstream& inFile);
	// Геттеры
	string getName() { return name; }
	string getTypeMonster() { return typeMonster; }


};

