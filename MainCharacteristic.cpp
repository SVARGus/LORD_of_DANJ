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