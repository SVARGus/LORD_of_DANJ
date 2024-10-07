#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// ����� ��������� ��� ���������� Weapon, Equipment, OtherItems
class Items
{
protected:
	string idItems{}; /*������ ���� : wep****, eqp****, oth**** .������ ��� ������� ����� ���������� ��������������(������, �����, ������...), 
	��������� ������ ����� �������� ��� ������, �������� 1 - ���, 2 - �����, 3 - ������ (���� �������� ��������� ���� ����� �� ��������)*/
public:
	virtual ~Items(){}
	virtual void use() const = 0;
};

