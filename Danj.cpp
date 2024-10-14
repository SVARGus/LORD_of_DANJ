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
Monster Danj::pickingOpponent(vector<Monster*> mobList) const // �������� ������� ���������� ������ �� ���� ����� � �������� ������ ��� ������� ����� (���� ����� �������, �� ����� ���� ����� ���������� ��� ����� �������� � ��������� �����)
{
	if (mobList.empty())
	{
		cout << "������ �������� ����! ���������� ���������� �������" << endl;
		return Monster();
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, mobList.size() - 1);
	int randomIndex = dist(gen);
	mobList[randomIndex]->setLvlMonster(carrentLevelDanj);
	mobList[randomIndex]->recalculateCharacteristic();
	return *mobList[randomIndex];
}
void Danj::calculationExpBatl() // ������ ����������� ����� � ������ ������
{
	player.upExp(10 + ((carrentLevelDanj - 1) * 3));
}
void Danj::upLvlDanj(bool win) // ��������� ��������� ������ �����
{
	if (openLevelDanj == carrentLevelDanj) // ��������� ������ ����� �������� ������ ��� ������� �� ���������� �������� ������
	{
		if (win)
		{
			++countVictory;
		}
		else
		{
			countVictory = 0; // � ������ ��������� ������� ����������
		}
		if (countVictory == (openLevelDanj*10))
		{
			cout << "���������� �� �������� ������� ���������� ����� ��� �������� ��������� ������ �����" << endl;
			++openLevelDanj;
			countVictory = 0;
		}
	}
}