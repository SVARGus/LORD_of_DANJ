#pragma once
#include <iostream>
#include "Items.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
// ����� ��������� ������. ����� ��� ����� ��������� ���������� ���� ������ (���, ������, �����). ���� ������ ����� ����������
// ���� ������������ ������� ����������� �������
class Weapon : public Items
{
protected:
	string name{};
	int damage{};
	int money{}; // ����� ����� ������� �� ��������� ����� � ������ ������� � �������
	string description{};
	// ������ ��������������
public:
	virtual int attack() const = 0;
	string getName(){ return name; };
	int getDamage(){ return damage; };
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
	Sword(){}
	void use() const override {}
	int attack() const override {}
};
class SwordFactory : public WeaponFactory
{
public:
	Weapon* creatWeapon() override {
		return new Sword();
	}
};

