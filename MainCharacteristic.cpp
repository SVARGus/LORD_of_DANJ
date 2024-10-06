#include "MainCharacteristic.h"

void MainCharacteristic::displayMainCharacteristic() const {
	cout << "Сила: " << power << endl;
	cout << "Ловкость: " << dexterity << endl;
	cout << "Выносливость: " << endurance << endl;
	cout << "Интелект: " << intelligence << endl;
	cout << "Мудрость: " << wisdom << endl;
	cout << "Харизма: " << charizma << endl;
	cout << "\t<<   ---   Урон   ---   >>" << endl;
	cout << "Минимальный: " << minDamage << "\tМаксимальный: " << maxDamage << endl;
	cout << "\t<<   ---   Дополнительные характеристики   ---   >>" << endl;
	cout << "Уклонение: " << parrying << endl;
	cout << "Инициатива: " << initiative << endl;
}
void MainCharacteristic::rebootStartCharacteristic() {
	name = "NoName";
	lvl = 1; 
	power = 1;
	dexterity = 1; 
	endurance = 1; 
	intelligence = 1; 
	wisdom = 1; 
	charizma = 1; 
	minDamage = 0; 
	maxDamage = 0; 
	parrying = 0; 
	initiative = 0; 
	maxHealth = 0; 
	health = 0; 
}