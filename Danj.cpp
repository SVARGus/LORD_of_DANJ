#include "Danj.h"

void Danj::displayMenuDanj() const {
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "\t�� ����� � " << nameDanj << endl << endl;
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "������� ������� ������: " << carrentLevelDanj << endl;
	cout << "��������� ������� �����: " << openLevelDanj << endl << endl;
	cout << "\t1) �������� � ��� �� ������� ������ �����!" << endl;
	cout << "\t2) ������� ���� ������� �����" << endl;
	cout << "\t3) ��������� � �������" << endl;
	cout << "\t4) ������� ����" << endl << endl;
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "�������� �������: " << endl;
}
void Danj::menuDanj() {
	int select{};
	int selectLvl{};
	cin >> select;
	switch (select)
	{
	case Danj::BATL_DANJ:
		break;
	case Danj::SELECT_LVL:
		cout << "������� �� ����� ������� ������� ����������: ";
		cin >> selectLvl;
		if (selectLvl <= openLevelDanj)
			carrentLevelDanj = selectLvl;
		else
			cout << "������������ ����� ������ ��� ���� ������� ��� ������ ��� ���!!!" << endl;
		break;
	case Danj::VILLAGE:
		game.setState(Game::VILLAGE);
		break;
	case Danj::MAIN_MENU:
		game.setState(Game::MAIN_MENU);
		break;
	default:
		cout << "������������ ����!!!" << endl;
	}
}