#pragma once
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

// ����� ��������� ��� ���������� Weapon, Equipment, OtherItems
class Items
{
protected:
	string idItems{}; /*������ ���� : wep****, eqp****, oth**** .������ ��� ������� ����� ���������� ��������������(������, �����, ������...), 
	��������� ������ ����� �������� ��� ������, �������� 1 - ���, 2 - �����, 3 - ������ (���� �������� ��������� ���� ����� �� ��������)*/
	/*
	����������� idItems ��� ������������� � ����������� ���������� � ��������:
	������ 3 ������� � ����� �������� ���������� ���������. �� ������ ����� ���������� "wep" ������, "eqp" ����������, "oth" ������ ���������, ����� ����� ����� �������� ���� ������������
	� 4-5 ������ � ����� ���� ���������� �������� ����� ���������. ��� Weapon 01 - ���, 02 - �����, 03 - ������ � ��� �����. ����� ����������� ��� ���������� � ������ ���������
	� 6-9 ������� � ����� ���� ���������� ������� ����������� �������� ����. �������� ���������� ����� "������ ��������" ����� ����� idItems = wep020003
	� 10 �� 12 ����� ������� ��������� ������� ���������� �� �����������, ������ ������ ������ ���� �����������, �� �� ����� 3 �� ���� �������. 10-12 ����� ����������� � �������, �������� ����� �������� ��� ������ � ��� ���� �������� � ������
	*/
	string name{}; // ��� ��������
public:
	virtual ~Items(){}
	virtual void displayItems() const = 0;
	virtual void displayNameItems() const = 0; // ����� �� ����� ���������� ������������ ��������
	string getName() { return name; };
	virtual void saveItemsToBinary(ofstream& outFile) const = 0; // ����� ���������� Weapon � �������� ����
	virtual void loadItemsFromBinary(ifstream& inFile) = 0; // ����� ���������� Weapon � ��������� ����
	virtual void saveItemsToText(ofstream& outFile) const = 0; // ����� �������� Weapon �� ��������� �����
	virtual void loadItemsFromText(ifstream& inFile) = 0; // ����� �������� Weapon �� ���������� �����
};

class ItemFactory
{
public:
	virtual Items* createItem(const string& identifier) = 0;
	virtual ~ItemFactory() {}
};
class ConcreteItemFactory : public ItemFactory
{
public:
	Items* createItem(const string& identifier) override;
};

