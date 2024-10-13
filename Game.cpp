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
	mainMenu = new MainMenu(); /* Из - за того что в классе mainMenu есть указатель на класс Game, то при попытке в конструкторе нельзя создавать объект MainMenu, 
	так как происходит перекрестная инициализация Game самим Game и MainMenu и происходит зависание программы, как это обойти не придумал. Наиболее подхлдящий вариант был
	перенести инициализацию в метод запуска цикла игры run()*/
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
			cout << "Таверна пока на ремонте после последней попойки))" << endl;
			break;
		case SHOP:
			cout << "Сотрудники принимают товар, скоро откроемся, также ждем приезда инкосатовров с классом Money))" << endl;
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
	//cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
}
void Game::setState(State newState) {
	previousState = currentState;
	currentState = newState;
}
void Game::backState() {
	currentState = previousState;
}
void Game::loadBaseWeapons()  // Загрузка базы оружия
{
	ifstream inFile("Base_Items_LORD_of_DANJ\\weapons.txt");
	if (!inFile) {
		std::cerr << "Ошибка при открытии файла с базой оружия.\n";
		return;
	}

	string line;
	ConcreteItemFactory factory;
	while (std::getline(inFile, line)) {
		Items* item = factory.createItem(line);  // Создаем предмет по идентификатору
		if (item) {
			item->loadItemsFromText(inFile);  // Загружаем данные предмета
			Weapon* weapon = dynamic_cast<Weapon*>(item);  // Преобразуем к Weapon
			if (weapon) {
				baseWeapon.push_back(weapon);  // Добавляем только оружие
			}
			else {
				delete item;  // Если это не оружие, освобождаем память
			}
		}
	}
	inFile.close();
	cout << "База данных Оружия загружена удачно!!!" << endl;
}
void Game::loadBaseMonster() // Загрузка базы монстров
{
	ifstream inFile("MobList.txt");
	if (!inFile) {
		std::cerr << "Ошибка при открытии файла с базой оружия.\n";
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
	cout << "База данных Монстров загружена удачно!!!" << endl;
}