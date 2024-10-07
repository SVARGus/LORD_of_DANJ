#pragma once
#include <iostream>
#include "Items.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
// Класс интерфейс Оружия. Также тут будут прописаны конкретные виды Оружия (Меч, Дубина, копье). Виды оружия позже расширятся
// Бует задействован паттерн Абстрактная фабрика
class Weapon : protected Items
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
// Конкретные классы Оружия
class Sword : protected Weapon 
{

};

