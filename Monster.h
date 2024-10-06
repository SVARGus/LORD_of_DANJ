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
	Monster() {}
	~Monster() {}
	void recalculateCharacteristic(int lvlDanj);
	void displayCharacteristic() const;
	int attack();
	void takeDamage(int attack);
	// �������� ����� ���������� � �������� �� ����� ������ �����? ��� � ���� �����������? // ������� ������ ���������� � �������� � ��� ����� (��������� � ��������)
	void saveToBinary(ofstream& outFile) const;
	void loadFromBinary(ifstream& inFile);
	void saveToText(ofstream& outFile) const;
	void loadFromText(ifstream& inFile);
	// �������
	string getName() { return name; }
	string getTypeMonster() { return typeMonster; }


};

