#pragma once
#include "Hero.h"
#include <Windows.h>
#include "Game.h"
#include "Monster.h"
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

class Danj
{
	string nameDanj{ "����� �������" }; // ���������� �������� �����
	string typeDanj{ "NoneType" }; // ��� �����, � ������� ����� ������ �� ����� ����������
	int carrentLevelDanj{ 1 }; // ������� ������� �����
	int openLevelDanj{}; // �������� ������� ����� (���� ����� ����� Hero::openLvlDanj, �� ����� ������ �������������� ����� ������ �� �����, ����� ������ ����� ���������)
	int maxLevelDanj{ 100 }; // ������������ ������� �����, �� ��������� ���������� 100
	//bool key{false} // � ������� ��� ��������� � ���� ����� ����� �������� ����� � ��������������� ����� �������� (�������� ������ ��� ���������� �������)
public:
	Danj() {}
	~Danj() {}
	void displayMenuDanj() const;
	void menuDanj();
	void displayRaundBatlDanj(Monster mob) const; // ������ ������ � ����� �� ����� ���������� ������
	Monster pickingOpponent(vector<Monster> mobList) const; // �������� ������� ���������� ������ �� ���� ����� � �������� ������ ��� ������� ����� (���� ����� �������, �� ����� ���� ����� ���������� ��� ����� �������� � ��������� �����)
	int calculationExpBatl(); // ������ ����������� ����� � ������ ������
	//bool parryingBattle(const MainCharacteristic mob1, const MainCharacteristic mob2) const; // ������ ��������� (�� ������ ������ ����������� � ������� takeDamage � Hero � Monster)

};

