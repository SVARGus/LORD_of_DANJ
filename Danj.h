#pragma once
#include "Hero.h"
#include <Windows.h>
#include "Game.h"
#include "Monster.h"
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Danj
{
	string nameDanj{ "Склеп древних" }; // Уникальное название данжа
	string typeDanj{ "NoneType" }; // Тип данжа, в будущем будет влиять на выбор противника
	int carrentLevelDanj{ 1 }; // Текущий уровень данжа
	int openLevelDanj{}; // Открытый уровень данжа (пока будет равен Hero::openLvlDanj, но позже данная характеристика будет убрана из героя, когда данжей будет несколько)
	int maxLevelDanj{ 100 }; // Максимальный уровень данжа, по умолчанию устанолвен 100
	//bool key{false} // В будущем для попадания в данж нужно будет получить ключь и соответствовать неким условиям (доступно станет при расширении локаций)
public:
	Danj() {}
	~Danj() {}
	void displayMenuDanj() const;
	void menuDanj();
	void displayRaundBatlDanj(Monster mob) const; // расчет раунда и вывод на экран резултатов раунда
	Monster pickingOpponent(vector<Monster> mobList) const; // алгоритм подбора противника исходя из типа данжа и пересчет статов под уровень данжа (пока будет обычный, но позже надо будет переделать или лучше выделить в отдельный класс)
	int calculationExpBatl(); // Расчет полученного опыта в случае победы
	//bool parryingBattle(const MainCharacteristic mob1, const MainCharacteristic mob2) const; // расчет уклонения (на данный момент реализовано в методах takeDamage в Hero и Monster)

};

