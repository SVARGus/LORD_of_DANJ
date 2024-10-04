#include "Game.h"
#include "MainMenu.h"

Game::Game() : currentState{ MAIN_MENU }, previousState{ MAIN_MENU } { /*mainMenu = new MainMenu();*/ cout << "creat Game" << endl; }
Game::~Game() { 
	cout << "Delete" << endl;
	delete mainMenu; 
}
void Game::run() {
	mainMenu = new MainMenu(); /* �� - �� ���� ��� � ������ mainMenu ���� ��������� �� ����� Game, �� ��� ������� � ������������ ������ ��������� ������ MainMenu, 
	��� ��� ���������� ������������ ������������� Game ����� Game � MainMenu � ���������� ��������� ���������, ��� ��� ������ �� ��������. �������� ���������� ������� ���
	��������� ������������� � ����� ������� ����� ���� run()*/
	while (currentState != EXIT)
	{
		switch (currentState)
		{
		case MAIN_MENU:
			mainMenu->displayMainMenu();
			mainMenu->selectMainMenu();
			break;
		case VILLAGE:
			cout << "Village" << endl;
			break;
		case TAVERN:
			break;
		case SHOP:
			break;
		case DANJ:
			break;
		case EXIT:
			break;
		default:
			break;
		}
	}
	cout << "\n\t\t������� �� ����! ����� ��� ����� �����!\n\n";
}
void Game::setState(State newState) {
	previousState = currentState;
	currentState = newState;
}
void Game::backState() {
	currentState = previousState;
}
