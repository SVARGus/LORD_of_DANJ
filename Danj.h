#pragma once
#include "Hero.h"
#include <Windows.h>
#include "Game.h"
#include "Monster.h"
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Danj
{
	enum Menu {BATL_DANJ = 1, SELECT_LVL, VILLAGE, MAIN_MENU};
	Hero& player = Hero::getInstance();
	Game& game = Game::getInstance();
	string nameDanj{ "Склеп древних" }; // Уникальное название данжа
	string typeDanj{ "NoneType" }; // Тип данжа, в будущем будет влиять на выбор противника
	int carrentLevelDanj{ 1 }; // Текущий уровень данжа
	int openLevelDanj = player.getOpenLvlDanj(); // Открытый уровень данжа (пока будет равен Hero::openLvlDanj, но позже данная характеристика будет убрана из героя, когда данжей будет несколько)
	int maxLevelDanj{ 100 }; // Максимальный уровень данжа, по умолчанию устанолвен 100
	int countVictory{}; // счетчик побед для повышения уровня данжа
	//bool key{false} // В будущем для попадания в данж нужно будет получить ключь и соответствовать неким условиям (доступно станет при расширении локаций)
public:
	Danj() {}
	~Danj() {}
	void displayMenuDanj() const;
	void menuDanj();
	// Боевку в будущем надо вывести в отдельный класс
	void displayRaundBatlDanj(Monster mob) const; // расчет раунда и вывод на экран резултатов раунда
	Monster pickingOpponent(vector<Monster*> mobList) const; // алгоритм подбора противника исходя из типа данжа и пересчет статов под уровень данжа (пока будет обычный, но позже надо будет переделать или лучше выделить в отдельный класс)
	void calculationExpBatl(); // Расчет полученного опыта в случае победы
	void upLvlDanj(bool win); // Повышение открытого уровня данжа (встроен конкулятор побед)
	//bool parryingBattle(const MainCharacteristic mob1, const MainCharacteristic mob2) const; // расчет уклонения (на данный момент реализовано в методах takeDamage в Hero и Monster)

};

