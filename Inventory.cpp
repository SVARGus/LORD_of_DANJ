#include "Inventory.h"

// Методы для первичной реализации
void Inventory::addItem(Items* item) // Метод добавления предмета в инвентарь (например при выполнеия задания награда забирается в рюкзан) // После добавления размера инветоря нужно будет добавить методы на проверку переполнения инвентаря
{
	inventoryItems.push_back(item);
	cout << "Предмет " << item->getName() << " помещен в " << nameInventory << "." << endl;
}
void Inventory::removItem(int index) // Метод удаления (выбрасывания) предмета из рюкзака по индексу
{
	if (index >= 0 && index < inventoryItems.size())
	{
		cout << "Предмет " << inventoryItems[index]->getName() << " удален из " << nameInventory << "." << endl;
		delete inventoryItems[index];
		inventoryItems.erase(inventoryItems.begin() + index);
	}
}
void Inventory::transferItem(Inventory& other, int index) // Метод трансфера между инветорями (например между игроком и магазином). index (индекс) предмеа текущего инвентаря добавить в other (другой) инветарь
{

}
void Inventory::displayInventory() const // Полный вывод инветоря с минимальными данными
{
	cout << "Содержимое " << nameInventory << ":" << endl;
	// Надо реализовать краткий вывод информации о предмете в Items и его детях
}
void Inventory::displayInventory(int index) const // Вывод конкретного предмета из инвентаря со всеми характеристиками 
{
	
}
Items* Inventory::getItem(int index) // Получение предмета по индексу
{

}
// Методы для вторичной реализации
void Inventory::saveInventoryToBinary(ofstream& outFile) const // Метод сохранения инвенторя в Бинарный файл
{

}
void Inventory::loadInventoryFromBinary(ifstream& inFile) // Метод сохранения инвенторя в Текстовый файл
{

}
void Inventory::saveInventoryToText(ofstream& outFile) const // Метод загрузки инвенторя из Бинарного файла
{

}
void Inventory::loadInventoryFromText(ifstream& inFile) // Метод загрузки инвенторя из Текстового файла
{

}
void Inventory::replaceItem(int index, Items* newItem) // метод замены предмета по индексу на новый
{

}
// методы на будущее - пока не будут реализованы или будут иметь заглушку
void Inventory::sortInventoryBy(const string& criterion) // Метод сортировки по разным критериям
{

}
Items* Inventory::findItemByName(const string& name) // Метод поиска по имени // Можно реализовать также по различным критериям при необходимости
{

}
int Inventory::countItemsById(const string& idIndex) // Подсчет количество одинаковых предметов // Можно реализовать также по различным критериям при необходимости, напримет по имени и типам
{

}
void Inventory::clearInventory() // Метод полной очистки инветаря
{

}
double Inventory::calculatedTotalWeight() const // Подсчет общего веса инвентаря (в рюкзаке могут быть ограничения по весу или перегруз влияет на подвижность героя)
{

}
double Inventory::calculatedTotalValue() const // Оценка стоимости всех предметов инвентаре
{

}
bool Inventory::hasItem(const string& name) const // Проверка наличия предмета по имения (например есть ли квестовый предмет в инвентаре для выполнения задания)
{

}
bool Inventory::isFullInventory() const // Проверка на заполненность инвенторя
{

}
void Inventory::stackIdenticalItems() // Метод объединения одинаковых предметов в стак
{

}