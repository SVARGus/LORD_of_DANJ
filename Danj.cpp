#include "Danj.h"

void Danj::displayMenuDanj() const {
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "\tВы вошли в " << nameDanj << endl << endl;
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "Текущий уровень данажа: " << carrentLevelDanj << endl;
	cout << "Доступный уровень данжа: " << openLevelDanj << endl << endl;
	cout << "\t1) Вступить в бой на текущем уровне данжа!" << endl;
	cout << "\t2) Выбрать иной уровень данжа" << endl;
	cout << "\t3) Вернуться в деревню" << endl;
	cout << "\t4) Главное Меню" << endl << endl;
	cout << "~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~" << endl;
	cout << "Выберите вариант: " << endl;
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
		cout << "Укажите на какой уровень желаете спуститься: ";
		cin >> selectLvl;
		if (selectLvl <= openLevelDanj)
			carrentLevelDanj = selectLvl;
		else
			cout << "Некорректный выбор уровня или этот уровень еще закрыт для вас!!!" << endl;
		break;
	case Danj::VILLAGE:
		game.setState(Game::VILLAGE);
		break;
	case Danj::MAIN_MENU:
		game.setState(Game::MAIN_MENU);
		break;
	default:
		cout << "Некорректный ввод!!!" << endl;
	}
}