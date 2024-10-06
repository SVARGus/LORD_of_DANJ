#pragma once
#include "Hero.h"
#include <Windows.h>
#include "Game.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
class Village
{
	enum Menu { SHOP = 1, TAVERN, DANJ, HERO, MAIN_MENU};
	//Game& game = Game::getInstance();
	Hero& player = Hero::getInstance();
	string nameVillage{ "Transilvania" }; // Пока будет одна деревня с базовым названием. в будущем будет несколько поселений и можно будет путешествовать между ними
	//Danj danj{} // Для каждого поселения будит свой уникальный данж со своими настройками! Расскоментировать после релизации
	//Shop shop{} // Для каждого поселения будит свой уникальный Магазин со своими настройками! Расскоментировать после релизации
	//Taver tavern{} // Для каждого поселения будит свой уникальная Таверна со своими настройками! Расскоментировать после релизации
public:
	Village() {}
	~Village() {}
	string getNameVillage() { return nameVillage; }
	void displayMenuVillage();
	void menuVillage();
};

