#pragma once
#include <iostream>
#include "Items.h"
#include <vector>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

// Класс интерфейс Оружия. Также тут будут прописаны конкретные виды Оружия (Меч, Дубина, копье). Виды оружия позже расширятся
// Бует задействован паттерн Абстрактная фабрика
class Weapon : protected Items
{
public:
	enum TypeWeapon {SWORD, SPEAR, CLIB}; // Типы оружия: Мечь, Копье, Дубина
	enum QualityWeapon {RUST, NORMAL, QUALITY, SHARPENED}; // Качество оружия: Ржавое (гнилое), Обычное, Качественное, Заточенное
	enum TypeDamageWeapon {CUTTING, STABBING, CRUSHING}; // Тип урона: Режущий, Колющий, Дробящий
protected:
	TypeWeapon typeWeapon{}; // Определенный тип оружия
	QualityWeapon qualityWeapon{}; // Определенное качество оружия
	TypeDamageWeapon typeDamegeWeapon{}; // Тип урона, игрок сможет выбирать
	int damage{}; // стандарнтый уровень урона будет расчитываться от QualityWeapon и TypeDamageWeapon
	int money{}; // Позже будет заменен на отдельный класс с ценами продажи и покупки
	string description{}; // Описание оружия
	// Прочие характеристики

	void setTypeWeapon(TypeWeapon newTypeWeapon) { typeWeapon = newTypeWeapon; } // возможно не понадобится
	void setQualityWeapon(QualityWeapon newQualityWeapon) { qualityWeapon = newQualityWeapon; }
public:
	virtual ~Weapon() {};
	virtual int attack() const = 0;
	void displayNameItems() const {
		switch (qualityWeapon)
		{
		case Weapon::RUST:
			if (typeWeapon == SWORD)
				cout << "Ржавый меч ";
			else if (typeWeapon == SPEAR)
				cout << "Ржавое копье ";
			else if (typeWeapon == CLIB)
				cout << "Гнилая дубина ";
			break;
		case Weapon::NORMAL:
			if (typeWeapon == SWORD)
				cout << "Обычный меч ";
			else if (typeWeapon == SPEAR)
				cout << "Обычное копье ";
			else if (typeWeapon == CLIB)
				cout << "Обычная дубина ";
			break;
		case Weapon::QUALITY:
			if (typeWeapon == SWORD)
				cout << "Качественный меч ";
			else if (typeWeapon == SPEAR)
				cout << "Качественное копье ";
			else if (typeWeapon == CLIB)
				cout << "Качественная дубина ";
			break;
		case Weapon::SHARPENED:
			if (typeWeapon == SWORD)
				cout << "Заточенный меч ";
			else if (typeWeapon == SPEAR)
				cout << "Заточенное копье ";
			else if (typeWeapon == CLIB)
				cout << "Укрепленная дубина ";
			break;
		default:
			cout << "Error!!!" << endl;
		}
		cout << "\"" << name << "\"";
	}
	void selectTypeDamageWeapon() // Выбор способа нанесения урона
	{
		cout << "Выберите способ нанесения урона: \n0)Режущий\n1)Колющий\n2)Дробящий\n";
		int choice{};
		cin >> choice;
		switch (choice)
		{
		case Weapon::CUTTING:
			typeDamegeWeapon = CUTTING;
			break;
		case Weapon::STABBING:
			typeDamegeWeapon = STABBING;
			break;
		case Weapon::CRUSHING:
			typeDamegeWeapon = CRUSHING;
			break;
		default:
			cout << "Error!!!" << endl;
			break;
		}
	}
	int getDamage(){ return damage; };
	//virtual int calculateAttackDamage() = 0; // Калькулятор урона
	void setTypeDamageWeapon(TypeDamageWeapon newTypeDamageWeapon) { typeDamegeWeapon = newTypeDamageWeapon; } // Оставим открытым, чтоб во время боя выбирать тип удара
	void saveItemsToBinary(ofstream& outFile) const; // Метод сохранения Weapon в Бинарный файл
	void loadItemsFromBinary(ifstream& inFile); // Метод сохранения Weapon в Текстовый файл
	void saveItemsToText(ofstream& outFile) const; // Метод загрузки Weapon из Бинарного файла
	void loadItemsFromText(ifstream& inFile); // Метод загрузки Weapon из Текстового файла
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
	vector <double> modifierTypeDamage { 1.0, 0.8, 0.5 }; // Модификаторы типа урона TypeDamageWeapon // Для каждого типа оружия он свой // в будущем будет также уникален для каждого оружия
	vector <double> modifierQuality { 0.8, 1.0, 1.2, 1.5 }; // Модификатор качества оружия влияющего на урон QualityWeapon // Для каждого типа оружия он может меняться
public:
	Sword() {}
	void displayItems() const{
		cout << "Оружие: "; displayNameItems(); cout << endl;
		cout << "ID (инвентарный номер): " << idItems << endl; //Временный вывод для проверки
		cout << "Урон: \n";
		cout << "\tРежущий: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(CUTTING)) << endl;
		cout << "\tКолющий: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(STABBING)) << endl;
		cout << "\tДробящий: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(CRUSHING)) << endl;
		cout << "Описание оружия: " << description << endl;
	}
	int attack() const override // расчет урона в зависимости от Качества оружия и типа урона
	{
		return damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(typeDamegeWeapon);
	}
};
class SwordFactory : public WeaponFactory
{
public:
	Weapon* creatWeapon() override {
		return new Sword();
	}
};

