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
// ���������� ������ ������
class Sword : protected Weapon 
{

};

