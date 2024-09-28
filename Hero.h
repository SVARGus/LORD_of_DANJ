#pragma once
#include <iostream>
#include "MainCharacteristic.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

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
	// добавить метод сохранения и загрузки из файла данных героя? или в меню реализовать?
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