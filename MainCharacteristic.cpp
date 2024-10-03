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