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
	char Y_N{};
	cin >> select;
	switch (select)
	{
	case Danj::BATL_DANJ:
		// Вызываемый метод подбора противника и метод битвы
		//char Y_N{};
		do
		{
			batlDanj(pickingOpponent(game.baseMonster));
			player.setHealth(player.getMaxHealth()); // Воставновление здоровья для следующей битвы
			cout << "Следующая битва? ДА(Y) - НЕТ(N) ";
			cin >> Y_N;
		} while (Y_N == 'Y' || Y_N == 'y');
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
Monster Danj::pickingOpponent(vector<Monster*> mobList) const // алгоритм подбора противника исходя из типа данжа и пересчет статов под уровень данжа (пока будет обычный, но позже надо будет переделать или лучше выделить в отдельный класс)
{
	if (mobList.empty())
	{
		cout << "Список монстров пуст! Противника невозможно выбрать" << endl;
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
void Danj::calculationExpBatl() // Расчет полученного опыта в случае победы
{
	player.upExp(10 + ((carrentLevelDanj - 1) * 3));
}
void Danj::upLvlDanj(bool win) // Повышение открытого уровня данжа
{
	if (openLevelDanj == carrentLevelDanj) // повышение уровня данжа возможна только при победах на максимльно открытом уровне
	{
		if (win)
		{
			++countVictory;
		}
		else
		{
			countVictory = 0; // в случае проигрыша счетчик обнуляется
		}
		if (countVictory == (openLevelDanj*10))
		{
			cout << "Поздравляю вы достигли нужного количества побед для открытия следущего уровня данжа" << endl;
			++openLevelDanj;
			countVictory = 0;
		}
	}
}
void Danj::batlDanj(Monster mob) // расчет раунда и вывод на экран резултатов раунда
{
	int countRound{1};
	std::cout << "Пробираясь по \"" << nameDanj << "\" " << carrentLevelDanj << " уровня, вы повстречали монстра " << mob.getName() << endl;
	cout << "Приготовьтесь к битве!!!" << std::endl;
	int displayDamage{};
	while (player.getHealth() > 0 && mob.getHealth() > 0)
	{
		cout << "Раунд #" << countRound << " между " << player.getName() << " и " << mob.getName() << endl;
		if (player.getInitiative() >= mob.getInitiative())
		{
			displayDamage = player.attack();
			cout << "1) " << player.getName() << " наносит урон = " << displayDamage << endl;
			mob.takeDamage(displayDamage);
			if (mob.getHealth() <= 0)
			{
				cout << "2) " << mob.getName() << " пропускает ход" << endl;
			}
			else
			{
				displayDamage = mob.attack();
				cout << "2) " << mob.getName() << " наносит урон = " << displayDamage << endl;
				player.takeDamage(displayDamage);
			}
		}
		else // расчет раунда если Монстр получил преимущество
		{
			displayDamage = mob.attack();
			cout << "1) " << mob.getName() << " наносит урон = " << displayDamage << endl;
			player.takeDamage(displayDamage);
			if (player.getHealth() <= 0)
			{
				cout << "2) " << player.getName() << " пропускает ход" << endl;
			}
			else
			{
				displayDamage = player.attack();
				cout << "2) " << player.getName() << " наносит урон = " << displayDamage << endl;
				mob.takeDamage(displayDamage);
			}
		}
		cout << "Оставшеясе здоровье: " << player.getName() << " = " << player.getHealth() << ";" << mob.getName() << " = " << mob.getHealth() << endl;
		++countRound;
	}
	if (mob.getHealth() <= 0)
	{
		cout << "Поздравляю, вы победили!" << endl;
		calculationExpBatl();
		upLvlDanj(true);
	}
	else
	{
		cout << "Вы проиграли!!!" << endl;
		upLvlDanj(false);
	}
}