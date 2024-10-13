#include "Hero.h"

void Hero::recalculateCharacteristic() { // Реализация идентична до рефакторинга в ОПП
	minDamage = 1 * power;
	maxDamage = 1.5 * power;
	parrying = 0.1 * dexterity + 0.02 * wisdom;
	initiative = 0.03 * intelligence + 0.02 * wisdom + 0.01 * charizma;
	maxHealth = (10 * lvl) * (0.8 * power + 0.4 * endurance);
	health = maxHealth;
	scalExpUp = 100;
	for (int i = 1; i < lvl; ++i)
	{
		scalExpUp *= 1.5 * i;
	}
}
void Hero::displayCharacteristic() const {
	cout << "* - * - * - * - * - * - * - * - * - * - *" << endl;
	cout << "Имя героя:\t" << name << "\tУровень\t" << lvl << endl;
	cout << "Количество жизни: [" << health << " / " << maxHealth << "]" << endl;
	cout << "Текущий уровень опыта: " << scalExp << " / " << scalExpUp << endl;
	displayMainCharacteristic();
	cout << "* - * - * - * - * - * - * - * - * - * - *" << endl;
	displayInventoryHero();
}
int Hero::attack() {
	int Damage = rand() % (maxDamage - minDamage) + minDamage; // Переделать алгоритм расчета урона
	return (Damage + Damage * initiative);
}
void Hero::takeDamage(int attack) {
	if (rand() % 30 / 10 <= parrying / lvl)
	{
		cout << "Герою удалось уклониться от удара!" << endl;
		return;
	}		
	health -= attack;
}
void Hero::distrPointHero() {
	enum CHARACTER { POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA };
	int Points{};
	int Character{};
	while (freePoints > 0)
	{
		std::cout << "Какую характеристику хотите повысить:\n(1) Сила\n(2) Ловкость\n(3) Выносливость\n(4) Интилект\n(5) Мудрость\n(6) Харизма" << std::endl;
		std::cin >> Character;
		std::cout << "У вас свободных очков = " << freePoints << std::endl;
		std::cout << "Сколько очков хотите добавить в выбранную характеристику = ";
		do
		{
			std::cin >> Points;
			if (Points > freePoints)
				std::cout << "Вы указали некорректно количество добавляемых очков, укажите не более: " << freePoints << std::endl;
		} while (Points > freePoints);
		switch (Character)
		{
		case POWER:
			power += Points;
			break;
		case DEXTERITY:
			dexterity += Points;
			break;
		case ENDURANCE:
			endurance += Points;
			break;
		case INTELLIGENCE:
			intelligence += Points;
			break;
		case WISDOM:
			wisdom += Points;
			break;
		case CHARIZMA:
			charizma += Points;
			break;
		default:
			freePoints += Points;
		}
		freePoints -= Points;
	}
	std::cout << "Все свободные очки распределены" << std::endl;
}

void Hero::saveToBinary(ofstream& outFile) const {
	outFile.write((char*)&name, sizeof(name)); // проверить корректность работы со string (с одним словом работает, позже проверить с составным именем из 2 и более слов)
	outFile.write((char*)&lvl, sizeof(lvl));
	outFile.write((char*)&power, sizeof(power));
	outFile.write((char*)&dexterity, sizeof(dexterity));
	outFile.write((char*)&endurance, sizeof(endurance));
	outFile.write((char*)&intelligence, sizeof(intelligence));
	outFile.write((char*)&wisdom, sizeof(wisdom));
	outFile.write((char*)&charizma, sizeof(charizma));
	outFile.write((char*)&minDamage, sizeof(minDamage));
	outFile.write((char*)&maxDamage, sizeof(maxDamage));
	outFile.write((char*)&parrying, sizeof(parrying));
	outFile.write((char*)&initiative, sizeof(initiative));
	outFile.write((char*)&maxHealth, sizeof(maxHealth));
	outFile.write((char*)&health, sizeof(health));
	// разделитель для данных наследуемых от наследуемого
	outFile.write((char*)&freePoints, sizeof(freePoints));
	outFile.write((char*)&scalExp, sizeof(scalExp));
	outFile.write((char*)&scalExpUp, sizeof(scalExpUp));
	outFile.write((char*)&winBattle, sizeof(winBattle));
	outFile.write((char*)&openLvlDanj, sizeof(openLvlDanj));
	outFile.write((char*)&Money, sizeof(Money));
}
void Hero::loadFromBinary(ifstream& inFile) {
	inFile.read((char*)&name, sizeof(name)); // проверить корректность работы со string (с одним словом работает, позже проверить с составным именем из 2 и более слов)
	inFile.read((char*)&lvl, sizeof(lvl));
	inFile.read((char*)&power, sizeof(power));
	inFile.read((char*)&dexterity, sizeof(dexterity));
	inFile.read((char*)&endurance, sizeof(endurance));
	inFile.read((char*)&intelligence, sizeof(intelligence));
	inFile.read((char*)&wisdom, sizeof(wisdom));
	inFile.read((char*)&charizma, sizeof(charizma));
	inFile.read((char*)&minDamage, sizeof(minDamage));
	inFile.read((char*)&maxDamage, sizeof(maxDamage));
	inFile.read((char*)&parrying, sizeof(parrying));
	inFile.read((char*)&initiative, sizeof(initiative));
	inFile.read((char*)&maxHealth, sizeof(maxHealth));
	inFile.read((char*)&health, sizeof(health));
	// разделитель для данных наследуемых от наследуемого
	inFile.read((char*)&freePoints, sizeof(freePoints));
	inFile.read((char*)&scalExp, sizeof(scalExp));
	inFile.read((char*)&scalExpUp, sizeof(scalExpUp));
	inFile.read((char*)&winBattle, sizeof(winBattle));
	inFile.read((char*)&openLvlDanj, sizeof(openLvlDanj));
	inFile.read((char*)&Money, sizeof(Money));
}
void Hero::saveToText(ofstream& outFile) const {
	//outFile << '"' << name << '"' << '\n';
	outFile << name << '\n'; // Проверить, если некорректно работает - использовать верхний вариант
	outFile << lvl << ' ' << power << ' ' << dexterity << ' ' << endurance << ' ' << intelligence << ' ' << wisdom << ' ' << charizma << '\n';
	outFile << minDamage << ' ' << maxDamage << ' ' << parrying << ' ' << initiative << ' ' << maxHealth << ' ' << health << '\n';
	outFile << freePoints << ' ' << scalExp << ' ' << scalExpUp << ' ' << winBattle << ' ' << openLvlDanj << ' ' << Money << '\n';
	inventory.saveInventoryToText(outFile);
}
void Hero::loadFromText(ifstream& inFile) {
	string line{};
	std::getline(inFile, line);
	//name = line.substr(1, line.size() - 2);
	name = line.substr(); // Проверить, если некорректно работает - использовать верхний вариант
	inFile >> lvl >> power >> dexterity >> endurance >> intelligence >> wisdom >> charizma;
	inFile >> minDamage >> maxDamage >> parrying >> initiative >> maxHealth >> health;
	inFile >> freePoints >> scalExp >> scalExpUp >> winBattle >> openLvlDanj >> Money;
	inventory.loadInventoryFromText(inFile);
}
void Hero::rebootStartHero() {
	rebootStartCharacteristic();
	freePoints = 10;
	scalExp = 0;
	scalExpUp = 0;
	winBattle = 0;
	openLvlDanj = 0;
	Money = 0;
}

void Hero::displayInventoryHero() const // Полный вывод предметов в инвенторе с урезанной информацией
{
	inventory.displayInventory();
}
void Hero::displayInventoryHero(int index) const // вывод на экран определенного предмета со всей информацией
{
	inventory.displayInventory(index);
}
void Hero::equipFirstWeapon(int index) // Экипировка оружия из инвентаря в первую руку
{
	Weapon* weapon = dynamic_cast<Weapon*>(inventory.getItem(index));
	if (weapon)
	{
		equippedFirstWeapon = weapon;
		cout << "Герой экипировал оружие: " << equippedFirstWeapon->getName() << endl;
	}
	else
		cout << "В инветаре в данной ячейке нету оружия" << endl;
}
void Hero::equipSecondWeapon(int index) // Экипировка оружия из инвентаря во вторую руку
{
	cout << "Метод equipSecondWeapon пока не реализован" << endl;
}
void Hero::unEquipFirstWeapon(int index) // Снять оружие 
{
	equippedFirstWeapon = nullptr;
}
void Hero::unEquipSecondWeapon(int index) // Снять оружие
{
	//equippedSecondWeapon = nullptr;
	cout << "Метод unEquipFirstWeapon пока не реализован" << endl;
}
void Hero::addItemToInventory(Items* item) // Метод добавления предмета в инвентарь
{
	inventory.addItem(item);
}
void Hero::transferItemTo(Inventory& other, int index) // Метод передачи предмета из своего инвентаря в другой инвентарь (сундук, магазин)
{

}