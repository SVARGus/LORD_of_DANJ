#pragma once
#include <iostream>
#include "Items.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
// Класс интерфейс Оружия. Также тут будут прописаны конкретные виды Оружия (Меч, Дубина, копье). Виды оружия позже расширятся
// Бует задействован паттерн Абстрактная фабрика
class Weapon : public Items
{
protected:
	string name{};
	int damage{};
	int money{}; // Позже будет заменен на отдельный класс с ценами продажи и покупки
	string description{};
	// Прочие характеристики
public:
	virtual int attack() const = 0;
	string getName(){ return name; };
	int getDamage(){ return damage; };
};

//Абстрактная фабрика Weapon
class WeaponFactory
{
public:
	virtual Weapon* creatWeapon() = 0;
};

// Конкретные классы Оружия, а также фабрика
// МЕЧ
class Sword : public Weapon
{
public:
	Sword(){}
	void use() const override {}
	int attack() const override {}
};
class SwordFactory : public WeaponFactory
{
public:
	Weapon* creatWeapon() override {
		return new Sword();
	}
};

