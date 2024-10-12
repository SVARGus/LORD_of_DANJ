#include "Weapon.h"

void Sword::saveItemsToBinary(ofstream& outFile) const // Метод сохранения Weapon в Бинарный файл
{
	// Будет реализован после реализации текстового варианта
}
void Sword::loadItemsFromBinary(ifstream& inFile) // Метод сохранения Weapon в Текстовый файл
{
	// Будет реализован после реализации текстового варианта
}
void Sword::saveItemsToText(ofstream& outFile) const // Метод загрузки Weapon из Бинарного файла
{
	outFile << "wep01" << "\n"; // индификатор для данного класса, в дальнейшем при загрузке позволит выбрать верный вариант в фабрике
	outFile << idItems << "\n";
	outFile << name << "\n";
	outFile << static_cast<int>(typeWeapon) << " " << static_cast<int>(qualityWeapon) << " " << static_cast<int>(typeDamegeWeapon) << " " << damage << "\n";
	outFile << money << "\n"; // Специально выведен в отдельную строку так как в будущем будет отдельный класс Money
	outFile << description << "\n";
	outFile << "END_DESCRIPTION\n";
	// Далее будет добавлено сохранение уникальных перменных характерных для данного класса. Наприме modifierTypeDamage и modifierQuality (пока не буду реализовывать)
}
void Sword::loadItemsFromText(ifstream& inFile) // Метод загрузки Weapon из Текстового файла
{
	string line{};
	std::getline(inFile, line);
	//idItems = line.substr(1, line.size() - 2);
	idItems = line; // Проверить, если некорректно работает - использовать верхний вариант
	std::getline(inFile, line);
	name = line;
	int tempTypeWeapon{};
	int tempQualityWeapon{};
	int tempTypeDamegeWeapon{};
	inFile >> tempTypeWeapon >> tempQualityWeapon >> tempTypeDamegeWeapon >> damage; // надо переделать для загрузки enum
	typeWeapon = static_cast<TypeWeapon>(tempTypeWeapon);
	qualityWeapon = static_cast<QualityWeapon>(tempTypeWeapon);
	typeDamegeWeapon = static_cast<TypeDamageWeapon>(tempTypeWeapon);
	inFile >> money;
	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		if (line == "END_DESCRIPTION")
		{
			break;
		}
		if (!description.empty())
		{
			description += "\n";
		}
		description += line;
	}
	description = line.substr();
}
// Методы КОПЬЯ
void Spear::displayItems() const
{
	cout << "Временная заглушка для методов класса Spear" << endl;
}
int Spear::attack() const
{
	cout << "Временная заглушка для методов класса Spear" << endl;
	return 0;
}
void Spear::saveItemsToBinary(ofstream& outFile) const // Метод сохранения предмета в Бинарный файл
{
	cout << "Временная заглушка для методов класса Spear" << endl;
}
void Spear::loadItemsFromBinary(ifstream& inFile)  // Метод сохранения предмета в Текстовый файл
{
	cout << "Временная заглушка для методов класса Spear" << endl;
}
void Spear::saveItemsToText(ofstream& outFile) const // Метод загрузки предмета из Бинарного файла
{
	cout << "Временная заглушка для методов класса Spear" << endl;
}
void Spear::loadItemsFromText(ifstream& inFile)  // Метод загрузки предмета из Текстового файла
{
	cout << "Временная заглушка для методов класса Spear" << endl;
}