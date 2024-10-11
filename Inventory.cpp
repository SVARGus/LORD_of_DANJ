#include "Inventory.h"

// ������ ��� ��������� ����������
void Inventory::addItem(Items* item) // ����� ���������� �������� � ��������� (�������� ��� ��������� ������� ������� ���������� � ������) // ����� ���������� ������� �������� ����� ����� �������� ������ �� �������� ������������ ���������
{
	inventoryItems.push_back(item);
	cout << "������� " << item->getName() << " ������� � " << nameInventory << "." << endl;
}
void Inventory::removItem(int index) // ����� �������� (������������) �������� �� ������� �� �������
{
	if (index >= 0 && index < inventoryItems.size())
	{
		cout << "������� " << inventoryItems[index]->getName() << " ������ �� " << nameInventory << "." << endl;
		delete inventoryItems[index];
		inventoryItems.erase(inventoryItems.begin() + index);
	}
}
void Inventory::transferItem(Inventory& other, int index) // ����� ��������� ����� ���������� (�������� ����� ������� � ���������). index (������) ������� �������� ��������� �������� � other (������) ��������
{

}
void Inventory::displayInventory() const // ������ ����� �������� � ������������ �������
{
	cout << "���������� " << nameInventory << ":" << endl;
	for (int i = 0; i < inventoryItems.size(); i++)
	{
		cout << i << ") ";
		inventoryItems[i]->displayNameItems();
		cout << endl;
	} // ����� �������� ��� ����� ��� �������� � ����������� ����
}
void Inventory::displayInventory(int index) const // ����� ����������� �������� �� ��������� �� ����� ���������������� 
{
	if (index >= 0 && index < inventoryItems.size())
		inventoryItems[index]->displayItems();
}
Items* Inventory::getItem(int index) // ��������� �������� �� �������
{
	for (int i = 0; i < inventoryItems.size(); i++)
		return inventoryItems[index];
}
// ������ ��� ��������� ����������
void Inventory::saveInventoryToBinary(ofstream& outFile) const // ����� ���������� ��������� � �������� ����
{
	int sizeInventoryItems = inventoryItems.size();
	outFile.write((char*)&sizeInventoryItems, sizeof(sizeInventoryItems));
	for (int i = 0; i < inventoryItems.size(); i++)
	{
		if (true) // ��������� ����� ����� ������ ��������� ����� ������
		{

		}
		inventoryItems[i]->saveItemsToBinary(outFile);
	}
	// ����������� ��� ������� ���������� Items ���� ����� ���������� ��� ����������� � ���������� ���������������, ������� ���� � ��� ������������ ������
}
void Inventory::loadInventoryFromBinary(ifstream& inFile) // ����� ���������� ��������� � ��������� ����
{
	// ����������� ��� ������� ���������� Items ���� ����� ���������� ��� ����������� � ���������� ���������������, ������� ���� � ��� ������������ ������
}
void Inventory::saveInventoryToText(ofstream& outFile) const // ����� �������� ��������� �� ��������� �����
{
	// ����������� ��� ������� ���������� Items ���� ����� �������� ��� ����������� � ���������� ���������������, ������� ���� � ��� ������������ ������
}
void Inventory::loadInventoryFromText(ifstream& inFile) // ����� �������� ��������� �� ���������� �����
{
	// ����������� ��� ������� ���������� Items ���� ����� �������� ��� ����������� � ���������� ���������������, ������� ���� � ��� ������������ ������
}
void Inventory::replaceItem(int index, Items* newItem) // ����� ������ �������� �� ������� �� �����
{
	// �����������
}
// ������ �� ������� - ���� �� ����� ����������� ��� ����� ����� ��������
void Inventory::sortInventoryBy(const string& criterion) // ����� ���������� �� ������ ���������
{
	cout << "����� sortInventoryBy ���� �� ���������� " << endl;
}
Items* Inventory::findItemByName(const string& name) // ����� ������ �� ����� // ����� ����������� ����� �� ��������� ��������� ��� �������������
{
	cout << "����� findItemByName ���� �� ���������� " << endl;
}
int Inventory::countItemsById(const string& idIndex) // ������� ���������� ���������� ��������� // ����� ����������� ����� �� ��������� ��������� ��� �������������, �������� �� ����� � �����
{
	cout << "����� countItemsById ���� �� ���������� " << endl;
}
void Inventory::clearInventory() // ����� ������ ������� ��������
{
	for (auto& item : inventoryItems)
		delete item;
	inventoryItems.clear();
}
double Inventory::calculatedTotalWeight() const // ������� ������ ���� ��������� (� ������� ����� ���� ����������� �� ���� ��� �������� ������ �� ����������� �����)
{
	cout << "����� calculatedTotalWeight ���� �� ���������� " << endl;
}
double Inventory::calculatedTotalValue() const // ������ ��������� ���� ��������� ���������
{
	cout << "����� calculatedTotalValue ���� �� ���������� " << endl;
}
bool Inventory::hasItem(const string& name) const // �������� ������� �������� �� ������ (�������� ���� �� ��������� ������� � ��������� ��� ���������� �������)
{
	cout << "����� hasItem ���� �� ���������� " << endl;
}
bool Inventory::isFullInventory() const // �������� �� ������������� ���������
{
	cout << "����� isFullInventory ���� �� ���������� " << endl;
}
void Inventory::stackIdenticalItems() // ����� ����������� ���������� ��������� � ���� (Weapon � Equipment �� ����� ������������ ������ �����)
{
	cout << "����� stackIdenticalItems ���� �� ���������� " << endl;
}