#include "Monster.h"

void Monster::recalculateCharacteristic(/*int lvlDanj*/) {
	power = power + ((rand() % 2 + 1) * (lvlDanj-1));
	dexterity = dexterity + ((rand() % 2 + 1) * (lvlDanj - 1));
	endurance = endurance + ((rand() % 2 + 1) * (lvlDanj - 1));
	intelligence = intelligence + ((rand() % 2 + 1) * (lvlDanj - 1));
	wisdom = wisdom + ((rand() % 2 + 1) * (lvlDanj - 1));
	charizma = charizma + ((rand() % 2 + 1) * (lvlDanj - 1));
	minDamage = 1 * power;
	maxDamage = 1.5 * power;
	parrying = 0.1 * dexterity + 0.02 * wisdom;
	initiative = 0.03 * intelligence + 0.02 * wisdom + 0.01 * charizma;
	health = (10 * lvlDanj) * (0.8 * power + 0.4 * endurance);
}
int Monster::attack() {
	int Damage = rand() % (maxDamage - minDamage) + minDamage; // Переделать алгоритм расчета урона
	return (Damage + Damage * initiative);
}
void Monster::takeDamage(int attack) {
	if (rand() % 30 / 10 <= parrying / lvl)
	{
		cout << name << " удалось уклониться от удара!" << endl;
		return;
	}
	health -= attack;
}
void Monster::displayCharacteristic() const {
	cout << "* - * - * - * - * - * - * - * - * - * - *" << endl;
	cout << "Имя Монстра:\t" << name << "\tТип:\t" << typeMonster << endl;
	displayMainCharacteristic();
	cout << "Описание: " << descriptionMonster << endl;
	cout << "* - * - * - * - * - * - * - * - * - * - *" << endl;
}
void Monster::saveToBinary(ofstream& outFile) const {
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
	outFile.write((char*)&typeMonster, sizeof(typeMonster)); // проверить корректность работы со string
	outFile.write((char*)&descriptionMonster, sizeof(descriptionMonster)); // проверить корректность работы со string
}
void Monster::loadFromBinary(ifstream& inFile) {
	inFile.read((char*)&name, sizeof(name)); // проверить корректность работы со string
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
	inFile.read((char*)&typeMonster, sizeof(typeMonster)); // проверить корректность работы со string
	inFile.read((char*)&descriptionMonster, sizeof(descriptionMonster)); // проверить корректность работы со string
}
void Monster::saveToText(ofstream& outFile) const {
	//outFile << '"' << name << '"' << '\n';
	outFile << name << '\n'; // Проверить, если некорректно работает - использовать верхний вариант
	outFile << lvl << ' ' << power << ' ' << dexterity << ' ' << endurance << ' ' << intelligence << ' ' << wisdom << ' ' << charizma << '\n';
	outFile << minDamage << ' ' << maxDamage << ' ' << parrying << ' ' << initiative << ' ' << maxHealth << ' ' << health << '\n';
	outFile << typeMonster << '\n';
	outFile << descriptionMonster << '\n';
}
void Monster::loadFromText(ifstream& inFile) {
	string line{};
	std::getline(inFile, line);
	//name = line.substr(1, line.size() - 2);
	name = line.substr(); // Проверить, если некорректно работает - использовать верхний вариант
	inFile >> lvl >> power >> dexterity >> endurance >> intelligence >> wisdom >> charizma;
	//inFile >> minDamage >> maxDamage >> parrying >> initiative >> maxHealth >> health;
	inFile.ignore();
	std::getline(inFile, line);
	typeMonster = line;
	descriptionMonster.clear();
	while (std::getline(inFile, line))
	{
		if (line == "END_MONSTER")
		{
			break;
		}
		if (!descriptionMonster.empty())
		{
			descriptionMonster += "\n";
		}
		descriptionMonster += line;
	}
}