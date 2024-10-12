#pragma once
#include <iostream>
#include "Items.h"
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

// ����� ��������� ������. ����� ��� ����� ��������� ���������� ���� ������ (���, ������, �����). ���� ������ ����� ����������
// ���� ������������ ������� ����������� �������
class Weapon : public Items
{
public:
	enum TypeWeapon {SWORD, SPEAR, CLIB}; // ���� ������: ����, �����, ������
	enum QualityWeapon {RUST, NORMAL, QUALITY, SHARPENED}; // �������� ������: ������ (������), �������, ������������, ����������
	enum TypeDamageWeapon {CUTTING, STABBING, CRUSHING}; // ��� �����: �������, �������, ��������
protected:
	TypeWeapon typeWeapon{}; // ������������ ��� ������
	QualityWeapon qualityWeapon{}; // ������������ �������� ������
	TypeDamageWeapon typeDamegeWeapon{}; // ��� �����, ����� ������ ��������
	int damage{}; // ����������� ������� ����� ����� ������������� �� QualityWeapon � TypeDamageWeapon
	int money{}; // ����� ����� ������� �� ��������� ����� � ������ ������� � �������
	string description{}; // �������� ������
	// ������ ��������������

	void setTypeWeapon(TypeWeapon newTypeWeapon) { typeWeapon = newTypeWeapon; } // �������� �� �����������
	void setQualityWeapon(QualityWeapon newQualityWeapon) { qualityWeapon = newQualityWeapon; }
public:
	virtual ~Weapon() {};
	virtual int attack() const = 0;
	void displayNameItems() const {
		switch (qualityWeapon)
		{
		case Weapon::RUST:
			if (typeWeapon == SWORD)
				cout << "������ ��� ";
			else if (typeWeapon == SPEAR)
				cout << "������ ����� ";
			else if (typeWeapon == CLIB)
				cout << "������ ������ ";
			break;
		case Weapon::NORMAL:
			if (typeWeapon == SWORD)
				cout << "������� ��� ";
			else if (typeWeapon == SPEAR)
				cout << "������� ����� ";
			else if (typeWeapon == CLIB)
				cout << "������� ������ ";
			break;
		case Weapon::QUALITY:
			if (typeWeapon == SWORD)
				cout << "������������ ��� ";
			else if (typeWeapon == SPEAR)
				cout << "������������ ����� ";
			else if (typeWeapon == CLIB)
				cout << "������������ ������ ";
			break;
		case Weapon::SHARPENED:
			if (typeWeapon == SWORD)
				cout << "���������� ��� ";
			else if (typeWeapon == SPEAR)
				cout << "���������� ����� ";
			else if (typeWeapon == CLIB)
				cout << "����������� ������ ";
			break;
		default:
			cout << "Error!!!" << endl;
		}
		cout << "\"" << name << "\"";
	}
	void selectTypeDamageWeapon() // ����� ������� ��������� �����
	{
		cout << "�������� ������ ��������� �����: \n0)�������\n1)�������\n2)��������\n";
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
	//virtual int calculateAttackDamage() = 0; // ����������� �����
	void setTypeDamageWeapon(TypeDamageWeapon newTypeDamageWeapon) { typeDamegeWeapon = newTypeDamageWeapon; } // ������� ��������, ���� �� ����� ��� �������� ��� �����
};

// ���������� ������ ������, ����������� ������� ���������� � ����� Items
// ��� // wep01
class Sword : public Weapon
{
	vector <double> modifierTypeDamage { 1.0, 0.8, 0.5 }; // ������������ ���� ����� TypeDamageWeapon // ��� ������� ���� ������ �� ���� // � ������� ����� ����� �������� ��� ������� ������
	vector <double> modifierQuality { 0.8, 1.0, 1.2, 1.5 }; // ����������� �������� ������ ��������� �� ���� QualityWeapon // ��� ������� ���� ������ �� ����� ��������
public:
	Sword() {}
	void displayItems() const override {
		cout << "������: "; displayNameItems(); cout << endl;
		cout << "ID (����������� �����): " << idItems << endl; //��������� ����� ��� ��������
		cout << "����: \n";
		cout << "\t�������: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(CUTTING)) << endl;
		cout << "\t�������: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(STABBING)) << endl;
		cout << "\t��������: " << (damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(CRUSHING)) << endl;
		cout << "�������� ������: " << description << endl;
	}
	int attack() const override // ������ ����� � ����������� �� �������� ������ � ���� �����
	{
		return damage * modifierQuality.at(qualityWeapon) * modifierTypeDamage.at(typeDamegeWeapon);
	}
	// ���� ��������� ������ ����� ���������� ����� ���������� ������� ������������� � ������ Items, ��� ��������� ��������� ��������� ������������ ���� ��������
	void saveItemsToBinary(ofstream& outFile) const override; // ����� ���������� �������� � �������� ����
	void loadItemsFromBinary(ifstream& inFile) override; // ����� ���������� �������� � ��������� ����
	void saveItemsToText(ofstream& outFile) const override; // ����� �������� �������� �� ��������� �����
	void loadItemsFromText(ifstream& inFile) override; // ����� �������� �������� �� ���������� �����
};
// ����� // wep02
class Spear : public Weapon // ����� ���� ��������������
{
	vector <double> modifierTypeDamage{ 1.0, 0.8, 0.5 }; // ������������ ���� ����� TypeDamageWeapon // ��� ������� ���� ������ �� ���� // � ������� ����� ����� �������� ��� ������� ������
	vector <double> modifierQuality{ 0.8, 1.0, 1.2, 1.5 }; // ����������� �������� ������ ��������� �� ���� QualityWeapon // ��� ������� ���� ������ �� ����� ��������
public:
	Spear() {}
	void displayItems() const override;
	int attack() const override;
	void saveItemsToBinary(ofstream& outFile) const override; // ����� ���������� �������� � �������� ����
	void loadItemsFromBinary(ifstream& inFile) override; // ����� ���������� �������� � ��������� ����
	void saveItemsToText(ofstream& outFile) const override; // ����� �������� �������� �� ��������� �����
	void loadItemsFromText(ifstream& inFile) override; // ����� �������� �������� �� ���������� �����
};

