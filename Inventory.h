#pragma once
#include <iostream>
#include <vector>
#include "Items.h"
#include "Weapon.h"
#include <fstream>
//#include "Equipment.h" // ����� ����� ��������
//#include "OtherItems.h" // ����� ����� ��������

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

class Inventory
{
	vector<Items*> inventoryItems;
	ItemFactory* factory;
	string nameInventory{}; // ��������� �������� ��������
	//int sizeInventory{}; // � ������� ����� ����� ������������ �������� � ������ ������� ������ ��������������� � ������� ����������������.
public:
	Inventory(string name) : nameInventory{ name } {}
	//
	string getNameInventory() { return nameInventory; }
	void setNameInventory(string name) { nameInventory = name; }
	// ������ ��� ��������� ����������
	void addItem(Items* item); // ����� ���������� �������� � ��������� (�������� ��� ��������� ������� ������� ���������� � ������) // ����� ���������� ������� �������� ����� ����� �������� ������ �� �������� ������������ ���������
	void removItem(int index); // ����� �������� (������������) �������� �� ������� �� �������
	void transferItem(Inventory& other, int index); // ����� ��������� ����� ���������� (�������� ����� ������� � ���������). index (������) ������� �������� ��������� �������� � other (������) ��������
	void displayInventory() const; // ������ ����� �������� � ������������ �������
	void displayInventory(int index) const; // ����� ����������� �������� �� ��������� �� ����� ���������������� 
	Items* getItem(int index); // ��������� �������� �� �������
	// ������ ��� ��������� ����������
	void saveInventoryToBinary(ofstream& outFile) const; // ����� ���������� ��������� � �������� ����
	void loadInventoryFromBinary(ifstream& inFile); // ����� ���������� ��������� � ��������� ����
	void saveInventoryToText(ofstream& outFile) const; // ����� �������� ��������� �� ��������� �����
	void loadInventoryFromText(ifstream& inFile); // ����� �������� ��������� �� ���������� �����
	void replaceItem(int index, Items* newItem); // ����� ������ �������� �� ������� �� �����
	// ������ �� ������� - ���� �� ����� ����������� ��� ����� ����� ��������
	void sortInventoryBy(const string& criterion); // ����� ���������� �� ������ ���������
	Items* findItemByName(const string& name); // ����� ������ �� ����� // ����� ����������� ����� �� ��������� ��������� ��� �������������
	int countItemsById(const string& idIndex); // ������� ���������� ���������� ��������� // ����� ����������� ����� �� ��������� ��������� ��� �������������, �������� �� ����� � �����
	void clearInventory(); // ����� ������ ������� ��������
	double calculatedTotalWeight() const; // ������� ������ ���� ��������� (� ������� ����� ���� ����������� �� ���� ��� �������� ������ �� ����������� �����)
	double calculatedTotalValue() const; // ������ ��������� ���� ��������� ���������
	bool hasItem(const string& name) const; // �������� ������� �������� �� ������ (�������� ���� �� ��������� ������� � ��������� ��� ���������� �������)
	bool isFullInventory() const; // �������� �� ������������� ���������
	void stackIdenticalItems(); // ����� ����������� ���������� ��������� � ����
};

