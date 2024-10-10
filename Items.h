#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// Класс интерфейс для подклассов Weapon, Equipment, OtherItems
class Items
{
protected:
	string idItems{}; /*пример Айди : wep****, eqp****, oth**** .Первые три символа будут обозначать принадлежность(Оружие, броня, прочее...), 
	следующий символ будет выделять уже подвид, например 1 - меч, 2 - копье, 3 - дубина (надо подробно расписать чтоб потом не путаться)*/
	string name{}; // Имя предмета
public:
	virtual ~Items(){}
	virtual void displayItems() const = 0;
};

