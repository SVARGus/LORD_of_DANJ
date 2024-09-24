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
	int pover{}; // Сила
	int dexterity{}; // Ловкость
	int endurance{}; // Выносливость
	int intellogence{}; // интелект
	int wisdon{}; // Мудрость
	int charizma{}; // Харизма
	int minDamage{}; // минимальный урон
	int maxDamage{}; // максимальный урон
	double parrying{}; // уклон от атаки
	double initiative{}; // Инициатива в бою
	int health{}; // здоровье
	// Позже дописать дополнительне характеристики которые будут общие для игрока и монстров
public:
	virtual ~MainCharacteristic() = 0; // чисто вирутайльный деструктор
	virtual void recalculateCharacteristic() = 0; // расчет и пересчет характеристик, каждый наследник сам реализует
	virtual void displayCharacteristic() const = 0; // Вывод характеристик на экран, каждый наследник сам реализует
	virtual int attack() = 0; // Расчет выдаваемого урона в битве
	virtual void takeDamage(int attack) = 0; // Расчет получаемого урона и расчет понижения с учетом защиты и других факторов, attack - это метод расчета урона противником
	// Геттеры переменных
	string getName() const { return name; }
	int getLvl() const { return lvl; }
	int getPover() const { return pover; }
	int getDexterity() const { return dexterity; }
	int getEndurance() const { return endurance; }
	int getIntellogence() const { return intellogence; }
	int getWisdon() const { return wisdon; }
	int getMinDamage() const { return minDamage; }
	int getMaxDamage() const { return maxDamage; }
	double getParrying() const { return parrying; }
	double getInitiative() const { return initiative; }
	int getHealth() const { return health; }
};

