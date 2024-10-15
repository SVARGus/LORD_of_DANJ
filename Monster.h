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
	Monster() : MainCharacteristic() {}
	~Monster() {}
	void recalculateCharacteristic(/*int lvlDanj*/) override;
	void displayCharacteristic() const override;
	int attack() override;
	void takeDamage(int attack) override;
	// добавить метод сохранения и загрузки из файла данных героя? или в меню реализовать? // Добавил методы сохранения и загрузки в сам класс (текстовый и бинарный)
	void saveToBinary(ofstream& outFile) const;
	void loadFromBinary(ifstream& inFile);
	void saveToText(ofstream& outFile) const;
	void loadFromText(ifstream& inFile, const string& firstLine);
	// Геттеры
	string getName() { return name; }
	string getTypeMonster() { return typeMonster; }
	void setLvlMonster(int Lvl) { lvl = Lvl; }

};

