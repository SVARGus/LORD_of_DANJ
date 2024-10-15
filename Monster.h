#pragma once
#include <iostream>
#include "MainCharacteristic.h"
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

class Monster : public MainCharacteristic
{
	string typeMonster{}; // ��� �������� (�������� �������, ������, ����������, �����, �������� � ������) - �������� � ������� ���� �������� � ��������� �����
	string descriptionMonster{}; // �������� ����
public:
	Monster() : MainCharacteristic() {}
	~Monster() {}
	void recalculateCharacteristic(/*int lvlDanj*/) override;
	void displayCharacteristic() const override;
	int attack() override;
	void takeDamage(int attack) override;
	// �������� ����� ���������� � �������� �� ����� ������ �����? ��� � ���� �����������? // ������� ������ ���������� � �������� � ��� ����� (��������� � ��������)
	void saveToBinary(ofstream& outFile) const;
	void loadFromBinary(ifstream& inFile);
	void saveToText(ofstream& outFile) const;
	void loadFromText(ifstream& inFile, const string& firstLine);
	// �������
	string getName() { return name; }
	string getTypeMonster() { return typeMonster; }
	void setLvlMonster(int Lvl) { lvl = Lvl; }

};

