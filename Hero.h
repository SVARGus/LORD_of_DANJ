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

// Класс будет переделан в Singleton, так герой будет всегда один и для удосбства доступа.

class Hero : public MainCharacteristic
{
	int freePoints{};
	int scalExp{};
	int scalExpUp{};
	int winBattle{};
	int openLvlDanj{};
	//# InventoryWeapon : array<Weapon, 2> // добавить после реализации классов с оружием
	//# inventory : Inventory / добавить после реализации класса Инвентарь и предметов (Items) и соответственно оружия и амуниции
	int Money{}; // позже вывести в отдельный класс для возможности взаимодействия с Магазином,Таверной, выпадение с монстров и других возможностей в будущем

	Hero(string name) : MainCharacteristic(name), freePoints{ 10 } {}; // Приватный конструктор для невозможности создать объект извне.
	Hero(const Hero&) = delete; // Удален конструктор копирования согласно принципу паттерна Singleton
	Hero& operator= (const Hero&) = delete; // Удален оператор присвоения согласно принципу паттерна Singleton
	//Hero() {} // нужен ли?
public:
	friend class MainMenu;
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
	int attack();
	void takeDamage(int attack);
	void distrPointHero();
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
};

void Hero::recalculateCharacteristic() { // Реализация идентична до рефакторинга в ОПП
	minDamage = 1 * power;
	maxDamage = 1.5 * power;
	parrying = 0.1 * dexterity + 0.02 * wisdom;
	initiative = 0.03 * intelligence + 0.02 * wisdom + 0.01 * charizma;
	maxHealth = (10 * lvl) * (0.8 * power + 0.4 * endurance);
	scalExpUp = 100;
	for (int i = 1; i < lvl; ++i)
	{
		scalExpUp *= 1.5 * i;
	}
}
void Hero::displayCharacteristic() const {
	cout << "* - * - * - * - * - * - * - * - * - * - *" << endl;
	cout << "Имя героя:\t" << name << "\tУровень\t" << lvl << endl;
	cout << "Количество жизни: [" << health << " / " << maxHealth << "]" << endl;
	cout << "Текущий уровень опыта: " << scalExp << " / " << scalExpUp << endl;
	displayMainCharacteristic();
}
int Hero::attack() {
	int Damage = rand() % (maxDamage - minDamage) + minDamage; // Переделать алгоритм расчета урона
	return (Damage + Damage * initiative);
}
void Hero::takeDamage(int attack) {
	health -= attack;
}
void Hero::distrPointHero() {
	enum CHARACTER { POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA };
	int Points{};
	int Character{};
	while (freePoints > 0)
	{
		std::cout << "Какую характеристику хотите повысить:\n(1) Сила\n(2) Ловкость\n(3) Выносливость\n(4) Интилект\n(5) Мудрость\n(6) Харизма" << std::endl;
		std::cin >> Character;
		std::cout << "У вас свободных очков = " << freePoints << std::endl;
		std::cout << "Сколько очков хотите добавить в выбранную характеристику = ";
		do
		{
			std::cin >> Points;
			if (Points > freePoints)
				std::cout << "Вы указали некорректно количество добавляемых очков, укажите не более: " << freePoints << std::endl;
		} while (Points > freePoints);
		switch (Character)
		{
		case POWER:
			power += Points;
			break;
		case DEXTERITY:
			dexterity += Points;
			break;
		case ENDURANCE:
			endurance += Points;
			break;
		case INTELLIGENCE:
			intelligence += Points;
			break;
		case WISDOM:
			wisdom += Points;
			break;
		case CHARIZMA:
			charizma += Points;
			break;
		default:
			freePoints += Points;
		}
		freePoints -= Points;
	}
	std::cout << "Все свободные очки распределены" << std::endl;
}

void Hero::saveToBinary(ofstream& outFile) const {
	outFile.write((char*)&name, sizeof(name)); // проверить корректность работы со string
	outFile.write((char*)&lvl, sizeof(lvl));
	outFile.write((char*)&power, sizeof(power));
	outFile.write((char*)&dexterity, sizeof(dexterity));
	outFile.write((char*)&endurance, sizeof(endurance));
	outFile.write((char*)&intelligence, sizeof(intelligence));
	outFile.write((char*)&wisdom, sizeof(wisdom));
	outFile.write((char*)&charizma, sizeof(charizma));
	outFile.write((char*)&minDamage, sizeof(minDamage));
	outFile.write((char*)&maxDamage, sizeof(maxDamage));
	outFile.write((char*)&parrying, sizeof(parrying));
	outFile.write((char*)&initiative, sizeof(initiative));
	outFile.write((char*)&maxHealth, sizeof(maxHealth));
	outFile.write((char*)&health, sizeof(health));
	// разделитель для данных наследуемых от наследуемого
	outFile.write((char*)&freePoints, sizeof(freePoints));
	outFile.write((char*)&scalExp, sizeof(scalExp));
	outFile.write((char*)&scalExpUp, sizeof(scalExpUp));
	outFile.write((char*)&winBattle, sizeof(winBattle));
	outFile.write((char*)&openLvlDanj, sizeof(openLvlDanj));
	outFile.write((char*)&Money, sizeof(Money));
}
void Hero::loadFromBinary(ifstream& inFile) {
	inFile.read((char*)&name, sizeof(name)); // проверить корректность работы со string
	inFile.read((char*)&lvl, sizeof(lvl));
	inFile.read((char*)&power, sizeof(power));
	inFile.read((char*)&dexterity, sizeof(dexterity));
	inFile.read((char*)&endurance, sizeof(endurance));
	inFile.read((char*)&intelligence, sizeof(intelligence));
	inFile.read((char*)&wisdom, sizeof(wisdom));
	inFile.read((char*)&charizma, sizeof(charizma));
	inFile.read((char*)&minDamage, sizeof(minDamage));
	inFile.read((char*)&maxDamage, sizeof(maxDamage));
	inFile.read((char*)&parrying, sizeof(parrying));
	inFile.read((char*)&initiative, sizeof(initiative));
	inFile.read((char*)&maxHealth, sizeof(maxHealth));
	inFile.read((char*)&health, sizeof(health));
	// разделитель для данных наследуемых от наследуемого
	inFile.read((char*)&freePoints, sizeof(freePoints));
	inFile.read((char*)&scalExp, sizeof(scalExp));
	inFile.read((char*)&scalExpUp, sizeof(scalExpUp));
	inFile.read((char*)&winBattle, sizeof(winBattle));
	inFile.read((char*)&openLvlDanj, sizeof(openLvlDanj));
	inFile.read((char*)&Money, sizeof(Money));
}
void Hero::saveToText(ofstream& outFile) const {
	//outFile << '"' << name << '"' << '\n';
	outFile << name << '\n'; // Проверить, если некорректно работает - использовать верхний вариант
	outFile << lvl << ' ' << power << ' ' << dexterity << ' ' << endurance << ' ' << intelligence << ' ' << wisdom << ' ' << charizma << '\n';
	outFile << minDamage << ' ' << maxDamage << ' ' << parrying << ' ' << initiative << ' ' << maxHealth << ' ' << health << '\n';
	outFile << freePoints << ' ' << scalExp << ' ' << scalExpUp << ' ' << winBattle << ' ' << openLvlDanj << ' ' << Money << '\n';
}
void Hero::loadFromText(ifstream& inFile) {
	string line{};
	std::getline(inFile, line);
	//name = line.substr(1, line.size() - 2);
	name = line.substr(); // Проверить, если некорректно работает - использовать верхний вариант
	inFile >> lvl >> power >> dexterity >> endurance >> intelligence >> wisdom >> charizma;
	inFile >> minDamage >> maxDamage >> parrying >> initiative >> maxHealth >> health;
	inFile >> freePoints >> scalExp >> scalExpUp >> winBattle >> openLvlDanj >> Money;
}