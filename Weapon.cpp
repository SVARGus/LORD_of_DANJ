#include "Weapon.h"

void Sword::saveItemsToBinary(ofstream& outFile) const // ����� ���������� Weapon � �������� ����
{
	// ����� ���������� ����� ���������� ���������� ��������
}
void Sword::loadItemsFromBinary(ifstream& inFile) // ����� ���������� Weapon � ��������� ����
{
	// ����� ���������� ����� ���������� ���������� ��������
}
void Sword::saveItemsToText(ofstream& outFile) const // ����� �������� Weapon �� ��������� �����
{
	outFile << "wep01" << "\n"; // ����������� ��� ������� ������, � ���������� ��� �������� �������� ������� ������ ������� � �������
	outFile << idItems << "\n";
	outFile << name << "\n";
	outFile << static_cast<int>(typeWeapon) << " " << static_cast<int>(qualityWeapon) << " " << static_cast<int>(typeDamegeWeapon) << " " << damage << "\n";
	outFile << money << "\n"; // ���������� ������� � ��������� ������ ��� ��� � ������� ����� ��������� ����� Money
	outFile << description << "\n";
	outFile << "END_DESCRIPTION\n";
	// ����� ����� ��������� ���������� ���������� ��������� ����������� ��� ������� ������. ������� modifierTypeDamage � modifierQuality (���� �� ���� �������������)
}
void Sword::loadItemsFromText(ifstream& inFile) // ����� �������� Weapon �� ���������� �����
{
	string line{};
	std::getline(inFile, line);
	//idItems = line.substr(1, line.size() - 2);
	idItems = line; // ���������, ���� ����������� �������� - ������������ ������� �������
	std::getline(inFile, line);
	name = line;
	int tempTypeWeapon{};
	int tempQualityWeapon{};
	int tempTypeDamegeWeapon{};
	inFile >> tempTypeWeapon >> tempQualityWeapon >> tempTypeDamegeWeapon >> damage; // ���� ���������� ��� �������� enum
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
// ������ �����
void Spear::displayItems() const
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
}
int Spear::attack() const
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
	return 0;
}
void Spear::saveItemsToBinary(ofstream& outFile) const // ����� ���������� �������� � �������� ����
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
}
void Spear::loadItemsFromBinary(ifstream& inFile)  // ����� ���������� �������� � ��������� ����
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
}
void Spear::saveItemsToText(ofstream& outFile) const // ����� �������� �������� �� ��������� �����
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
}
void Spear::loadItemsFromText(ifstream& inFile)  // ����� �������� �������� �� ���������� �����
{
	cout << "��������� �������� ��� ������� ������ Spear" << endl;
}