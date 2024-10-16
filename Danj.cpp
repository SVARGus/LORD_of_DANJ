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
	char Y_N{};
	cin >> select;
	switch (select)
	{
	case Danj::BATL_DANJ:
		// ���������� ����� ������� ���������� � ����� �����
		//char Y_N{};
		do
		{
			batlDanj(pickingOpponent(game.baseMonster));
			player.setHealth(player.getMaxHealth()); // �������������� �������� ��� ��������� �����
			cout << "��������� �����? ��(Y) - ���(N) ";
			cin >> Y_N;
		} while (Y_N == 'Y' || Y_N == 'y');
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
void Danj::batlDanj(Monster mob) // ������ ������ � ����� �� ����� ���������� ������
{
	int countRound{1};
	std::cout << "���������� �� \"" << nameDanj << "\" " << carrentLevelDanj << " ������, �� ����������� ������� " << mob.getName() << endl;
	cout << "������������� � �����!!!" << std::endl;
	int displayDamage{};
	while (player.getHealth() > 0 && mob.getHealth() > 0)
	{
		cout << "����� #" << countRound << " ����� " << player.getName() << " � " << mob.getName() << endl;
		if (player.getInitiative() >= mob.getInitiative())
		{
			displayDamage = player.attack();
			cout << "1) " << player.getName() << " ������� ���� = " << displayDamage << endl;
			mob.takeDamage(displayDamage);
			if (mob.getHealth() <= 0)
			{
				cout << "2) " << mob.getName() << " ���������� ���" << endl;
			}
			else
			{
				displayDamage = mob.attack();
				cout << "2) " << mob.getName() << " ������� ���� = " << displayDamage << endl;
				player.takeDamage(displayDamage);
			}
		}
		else // ������ ������ ���� ������ ������� ������������
		{
			displayDamage = mob.attack();
			cout << "1) " << mob.getName() << " ������� ���� = " << displayDamage << endl;
			player.takeDamage(displayDamage);
			if (player.getHealth() <= 0)
			{
				cout << "2) " << player.getName() << " ���������� ���" << endl;
			}
			else
			{
				displayDamage = player.attack();
				cout << "2) " << player.getName() << " ������� ���� = " << displayDamage << endl;
				mob.takeDamage(displayDamage);
			}
		}
		cout << "���������� ��������: " << player.getName() << " = " << player.getHealth() << ";" << mob.getName() << " = " << mob.getHealth() << endl;
		++countRound;
	}
	if (mob.getHealth() <= 0)
	{
		cout << "����������, �� ��������!" << endl;
		calculationExpBatl();
		upLvlDanj(true);
	}
	else
	{
		cout << "�� ���������!!!" << endl;
		upLvlDanj(false);
	}
}