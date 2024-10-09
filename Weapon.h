#pragma once
#include <iostream>
#include "Items.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
// ����� ��������� ������. ����� ��� ����� ��������� ���������� ���� ������ (���, ������, �����). ���� ������ ����� ����������
// ���� ������������ ������� ����������� �������
class Weapon : protected Items
{
public:
	enum TypeWeapon {SWORD, SPEAR, CLIB}; // ���� ������: ����, �����, ������
	enum QualityWeapon {RUST, NORMAL, QUALITY, SHARPENED}; // �������� ������: ������ (������), �������, ������������, ����������
	enum TypeDamageWeapon {CUTTING, STABBING, CRUSHING}; // ��� �����: �������, �������, ��������
protected:
	TypeWeapon typeWeapon{}; // ���
	QualityWeapon qualityWeapon{};
	TypeDamageWeapon typeDamegeWeapon{};
	int damage{}; // ����������� ������� ����� ����� ������������� �� QualityWeapon � TypeDamageWeapon
	int money{}; // ����� ����� ������� �� ��������� ����� � ������ ������� � �������
	string description{}; // �������� ������
	// ������ ��������������

	void setTypeWeapon(TypeWeapon newTypeWeapon) { typeWeapon = newTypeWeapon; } // �������� �� �����������
	void setQualityWeapon(QualityWeapon newQualityWeapon) { qualityWeapon = newQualityWeapon; }
public:
	virtual ~Weapon() {};
	virtual int attack() const = 0;

	string getName(){ return name; };
	int getDamage(){ return damage; };
	//virtual int calculateAttackDamage() = 0; // ����������� �����
	void setTypeDamageWeapon(TypeDamageWeapon newTypeDamageWeapon) { typeDamegeWeapon = newTypeDamageWeapon; } // ������� ��������, ���� �� ����� ��� ������� ��� �����

};

//����������� ������� Weapon
class WeaponFactory
{
public:
	virtual Weapon* creatWeapon() = 0;
};

// ���������� ������ ������, � ����� �������
// ���
class Sword : public Weapon
{
public:
	Sword() {}
	void use() const override {}
	int attack() const override {
		double finishDamage{};
		// ����������� ������� ����� switch!!
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

