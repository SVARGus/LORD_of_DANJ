#include "Village.h"

void Village::displayMenuVillage() const {
	cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;;
	cout << "\t\t\t���� ������� " << nameVillage << endl << endl;
	cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;
	cout << "\t\t\t���� ������� �����������?" << endl << endl;
	cout << "\t\t\t������� - 1" << endl << endl;
	cout << "\t\t\t������� - 2" << endl << endl;
	cout << "\t\t\t���� - 3" << endl << endl;
	cout << "\t\t\t���������� ����� - 4" << endl << endl;
	cout << "\t\t\t������� ���� - 5" << endl << endl;
	cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;
}
void Village::menuVillage() {
	Game& game = Game::getInstance();
	int state{};
	cin >> state;
	switch (state)
	{
	case Village::SHOP:
		game.setState(Game::SHOP);
		break;
	case Village::TAVERN:
		game.setState(Game::TAVERN);
		break;
	case Village::DANJ:
		game.setState(Game::DANJ);
		break;
	case Village::HERO:
		player.displayCharacteristic();
		if (player.getFreepoints() > 0)
		{
			cout << "� ��� ���� ��������� ���� �������������, ������� ������������? (Y/N)";
			switch (int c = getchar(); c)
			{
			case 'Y':
			case 'y':
				player.distrPointHero();
			}
		}
		break;
	case Village::MAIN_MENU:
		game.setState(Game::MAIN_MENU);
		break;
	default:
		cout << "�� ���������� ����!!!" << endl;
		break;
	}
}
