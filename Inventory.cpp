#include "Inventory.h"

// ������ ��� ��������� ����������
void Inventory::addItem(Items* item) // ����� ���������� �������� � ��������� (�������� ��� ��������� ������� ������� ���������� � ������) // ����� ���������� ������� �������� ����� ����� �������� ������ �� �������� ������������ ���������
{

}
void Inventory::removItem(int index) // ����� �������� (������������) �������� �� ������� �� �������
{

}
void Inventory::transferItem(Inventory& other, int index) // ����� ��������� ����� ���������� (�������� ����� ������� � ���������). index (������) ������� �������� ��������� �������� � other (������) ��������
{

}
void Inventory::displayInventory() const // ������ ����� �������� � ������������ �������
{

}
void Inventory::displayInventory(int index) const // ����� ����������� �������� �� ��������� �� ����� ���������������� 
{

}
Items* Inventory::getItem(int index) // ��������� �������� �� �������
{

}
// ������ ��� ��������� ����������
void Inventory::saveInventoryToBinary(ofstream& outFile) const // ����� ���������� ��������� � �������� ����
{

}
void Inventory::loadInventoryFromBinary(ifstream& inFile) // ����� ���������� ��������� � ��������� ����
{

}
void Inventory::saveInventoryToText(ofstream& outFile) const // ����� �������� ��������� �� ��������� �����
{

}
void Inventory::loadInventoryFromText(ifstream& inFile) // ����� �������� ��������� �� ���������� �����
{

}
void Inventory::replaceItem(int index, Items* newItem) // ����� ������ �������� �� ������� �� �����
{

}
// ������ �� ������� - ���� �� ����� ����������� ��� ����� ����� ��������
void Inventory::sortInventoryBy(const string& criterion) // ����� ���������� �� ������ ���������
{

}
Items* Inventory::findItemByName(const string& name) // ����� ������ �� ����� // ����� ����������� ����� �� ��������� ��������� ��� �������������
{

}
int Inventory::countItemsById(const string& idIndex) // ������� ���������� ���������� ��������� // ����� ����������� ����� �� ��������� ��������� ��� �������������, �������� �� ����� � �����
{

}
void Inventory::clearInventory() // ����� ������ ������� ��������
{

}
double Inventory::calculatedTotalWeight() const // ������� ������ ���� ��������� (� ������� ����� ���� ����������� �� ���� ��� �������� ������ �� ����������� �����)
{

}
double Inventory::calculatedTotalValue() const // ������ ��������� ���� ��������� ���������
{

}
bool Inventory::hasItem(const string& name) const // �������� ������� �������� �� ������ (�������� ���� �� ��������� ������� � ��������� ��� ���������� �������)
{

}
bool Inventory::isFullInventory() const // �������� �� ������������� ���������
{

}
void Inventory::stackIdenticalItems() // ����� ����������� ���������� ��������� � ����
{

}