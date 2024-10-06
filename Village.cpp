#include "Village.h"

void Village::displayMenuVillage() const {
	cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;;
	cout << "\t\t\tМеню деревни " << nameVillage << endl << endl;
	cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;
	cout << "\t\t\tКуда желаете отправиться?" << endl << endl;
	cout << "\t\t\tМагазин - 1" << endl << endl;
	cout << "\t\t\tТаверна - 2" << endl << endl;
	cout << "\t\t\tДанж - 3" << endl << endl;
	cout << "\t\t\tСтатистика героя - 4" << endl << endl;
	cout << "\t\t\tГлавное меню - 5" << endl << endl;
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
			cout << "У вас есть свободные очки характеристик, желаете распределить? (Y/N)";
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
		cout << "Не корректный ввод!!!" << endl;
		break;
	}
}
