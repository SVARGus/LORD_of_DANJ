#include "MainCharacteristic.h"

void MainCharacteristic::displayMainCharacteristic() const {
	cout << "����: " << power << endl;
	cout << "��������: " << dexterity << endl;
	cout << "������������: " << endurance << endl;
	cout << "��������: " << intelligence << endl;
	cout << "��������: " << wisdom << endl;
	cout << "�������: " << charizma << endl;
	cout << "\t<<   ---   ����   ---   >>" << endl;
	cout << "�����������: " << minDamage << "\t������������: " << maxDamage << endl;
	cout << "\t<<   ---   �������������� ��������������   ---   >>" << endl;
	cout << "���������: " << parrying << endl;
	cout << "����������: " << initiative << endl;
}
void MainCharacteristic::rebootStartCharacteristic() {
	name = "NoName";
	lvl = 1; 
	power = 1;
	dexterity = 1; 
	endurance = 1; 
	intelligence = 1; 
	wisdom = 1; 
	charizma = 1; 
	minDamage = 0; 
	maxDamage = 0; 
	parrying = 0; 
	initiative = 0; 
	maxHealth = 0; 
	health = 0; 
}