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
public:
	enum TypeWeapon {SWORD, SPEAR, CLIB}; // Типы оружия: Мечь, Копье, Дубина
	enum QualityWeapon {RUST, NORMAL, QUALITY, SHARPENED}; // Качество оружия: Ржавое (гнилое), Обычное, Качественное, Заточенное
	enum TypeDamageWeapon {CUTTING, STABBING, CRUSHING}; // Тип урона: Режущий, Колющий, Дробящий
protected:
	TypeWeapon typeWeapon{}; // Для
	QualityWeapon qualityWeapon{};
	TypeDamageWeapon typeDamegeWeapon{};
	int damage{}; // стандарнтый уровень урона будет расчитываться от QualityWeapon и TypeDamageWeapon
	int money{}; // Позже будет заменен на отдельный класс с ценами продажи и покупки
	string description{}; // Описание оружия
	// Прочие характеристики

	void setTypeWeapon(TypeWeapon newTypeWeapon) { typeWeapon = newTypeWeapon; } // возможно не понадобится
	void setQualityWeapon(QualityWeapon newQualityWeapon) { qualityWeapon = newQualityWeapon; }
public:
	virtual ~Weapon() {};
	virtual int attack() const = 0;

	string getName(){ return name; };
	int getDamage(){ return damage; };
	//virtual int calculateAttackDamage() = 0; // Калькулятор урона
	void setTypeDamageWeapon(TypeDamageWeapon newTypeDamageWeapon) { typeDamegeWeapon = newTypeDamageWeapon; } // Оставим открытым, чтоб во время боя выирать тип удара

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
	Sword() {}
	void use() const override {}
	int attack() const override {
		double finishDamage{};
		// реализовать расчеты через switch!!
		/*if (typeDamegeWeapon == CUTTING)
			return damage;
		else if (typeDamegeWeapon == STABBING)
			return damage * 0.8;
		else if (typeDamegeWeapon == CRUSHING)
			return damage * 0.5;
		else
			return 0;*/
	}
};
class SwordFactory : public WeaponFactory
{
public:
	Weapon* creatWeapon() override {
		return new Sword();
	}
};

