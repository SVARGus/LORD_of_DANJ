#include "Game.h"
#include "MainMenu.h"
#include "Village.h"
#include "Danj.h"


Game::Game() : currentState{ MAIN_MENU }, previousState{ MAIN_MENU } { /*mainMenu = new MainMenu();*/ /*cout << "creat Game" << endl;*/ }
Game::~Game() { 
	//cout << "Delete" << endl;
	delete mainMenu; 
}
void Game::run() {
	mainMenu = new MainMenu(); /* �� - �� ���� ��� � ������ mainMenu ���� ��������� �� ����� Game, �� ��� ������� � ������������ ������ ��������� ������ MainMenu, 
	��� ��� ���������� ������������ ������������� Game ����� Game � MainMenu � ���������� ��������� ���������, ��� ��� ������ �� ��������. �������� ���������� ������� ���
	��������� ������������� � ����� ������� ����� ���� run()*/
	village = new Village();
	danj = new Danj();
	loadBaseWeapons();
	loadBaseMonster();
	while (currentState != EXIT)
	{
		switch (currentState)
		{
		case MAIN_MENU:
			mainMenu->displayMainMenu();
			mainMenu->selectMainMenu();
			break;
		case VILLAGE:
			village->displayMenuVillage();
			village->menuVillage();
			break;
		case TAVERN:
			cout << "������� ���� �� ������� ����� ��������� �������))" << endl;
			break;
		case SHOP:
			cout << "���������� ��������� �����, ����� ���������, ����� ���� ������� ������������ � ������� Money))" << endl;
			break;
		case DANJ:
			danj->displayMenuDanj();
			danj->menuDanj();
			break;
		case EXIT:
			break;
		default:
			break;
		}
	}
	//cout << "\n\t\t������� �� ����! ����� ��� ����� �����!\n\n";
}
void Game::setState(State newState) {
	previousState = currentState;
	currentState = newState;
}
void Game::backState() {
	currentState = previousState;
}
void Game::loadBaseWeapons()  // �������� ���� ������
{
	ifstream inFile("Base_Items_LORD_of_DANJ\\weapons.txt");
	if (!inFile) {
		std::cerr << "������ ��� �������� ����� � ����� ������.\n";
		return;
	}

	string line;
	ConcreteItemFactory factory;
	while (std::getline(inFile, line)) {
		Items* item = factory.createItem(line);  // ������� ������� �� ��������������
		if (item) {
			item->loadItemsFromText(inFile);  // ��������� ������ ��������
			Weapon* weapon = dynamic_cast<Weapon*>(item);  // ����������� � Weapon
			if (weapon) {
				baseWeapon.push_back(weapon);  // ��������� ������ ������
			}
			else {
				delete item;  // ���� ��� �� ������, ����������� ������
			}
		}
	}
	inFile.close();
	cout << "���� ������ ������ ��������� ������!!!" << endl;
}
void Game::loadBaseMonster() // �������� ���� ��������
{
	ifstream inFile("MobList.txt");
	if (!inFile) {
		std::cerr << "������ ��� �������� ����� � ����� ������.\n";
		return;
	}
	string line;
	while (std::getline(inFile, line))
	{
		if (line.empty())
			continue;
		Monster* monster = new Monster();
		monster->loadFromText(inFile);
		baseMonster.push_back(monster);
	}
	inFile.close();
	cout << "���� ������ �������� ��������� ������!!!" << endl;
}