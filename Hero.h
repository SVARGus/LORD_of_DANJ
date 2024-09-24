#pragma once
#include <iostream>
#include "MainCharacteristic.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

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
	
public:
	// friend class MainMenu Объявляется как дружественный класс для возможности загрузки и сохранения героя в классе MainMenu без нарушения принципа инкапсуляции
	// Это позволить MainMenu напрямую работать с приватными членами класса Hero. Возможно стоит также сделать в других классах его дружественным,
	// если от туда будут записываться данные
};

