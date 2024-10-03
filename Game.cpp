#include "Game.h"

void Game::run() {
	while (currentState != EXIT)
	{
		switch (currentState)
		{
		case MAIN_MENU:
			mainMenu->displayMainMenu();
			mainMenu->selectMainMenu();
			break;
		case VILLAGE:
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