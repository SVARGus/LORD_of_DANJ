#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


class MainCharacteristic
{
protected:
	string name{}; // Имя
	int lvl{}; // Уровень
	int power{}; // Сила
	int dexterity{}; // Ловкость
	int endurance{}; // Выносливость
	int intelligence{}; // интелект
	int wisdom{}; // Мудрость
	int charizma{}; // Харизма
	int minDamage{}; // минимальный урон
	int maxDamage{}; // максимальный урон
	double parrying{}; // уклон от атаки
	double initiative{}; // Инициатива в бою
	int maxHealth{}; // Максимальное здоровье
	int health{}; // Текущий уровень жизни
	// Позже дописать дополнительне характеристики которые будут общие для игрока и монстров

	MainCharacteristic() {} // Конструктор по умолчанию
	MainCharacteristic(string name) : name{ name }, lvl{ 1 }, power{ 1 }, dexterity{ 1 }, endurance{ 1 }, intelligence{ 1 }, wisdom{ 1 }, charizma{ 1 } {} // конструктор для нследников
public:
	virtual ~MainCharacteristic() {}; // чисто вирутайльный деструктор
	virtual void recalculateCharacteristic() = 0; // расчет и пересчет характеристик, каждый наследник сам реализует
	virtual void displayCharacteristic() const = 0; // Вывод характеристик на экран, каждый наследник сам реализует
	virtual int attack() = 0; // Расчет выдаваемого урона в битве
	virtual void takeDamage(int attack) = 0; // Расчет получаемого урона и расчет понижения с учетом защиты и других факторов, attack - это метод расчета урона противником
	// Геттеры переменных
	string getName() const { return name; }
	int getLvl() const { return lvl; }
	int getPower() const { return power; }
	int getDexterity() const { return dexterity; }
	int getEndurance() const { return endurance; }
	int getIntelligence() const { return intelligence; }
	int getWisdon() const { return wisdom; }
	int getMinDamage() const { return minDamage; }
	int getMaxDamage() const { return maxDamage; }
	double getParrying() const { return parrying; }
	double getInitiative() const { return initiative; }
	int getMaxHealth() const { return maxHealth; }
	int getHealth() const { return health; }
	// Сеттеры, если требуются
	void setHealth(int Health) { health = Health; } // Изменение текущего уровня здоровья
	void setName(string Name) { name = Name; }
	// Реализованные методы общие для наследников
	void displayMainCharacteristic() const;
};
