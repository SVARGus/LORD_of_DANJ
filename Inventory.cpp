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
	for (int i = 0; i < inventoryItems.size(); i++)
	{
		cout << i << ") ";
		inventoryItems[i]->displayNameItems();
		cout << endl;
	} // Позже подумать что можно еще выводить в сокращенном виде
}
void Inventory::displayInventory(int index) const // Вывод конкретного предмета из инвентаря со всеми характеристиками 
{
	if (index >= 0 && index < inventoryItems.size())
		inventoryItems[index]->displayItems();
}
Items* Inventory::getItem(int index) // Получение предмета по индексу
{
	for (int i = 0; i < inventoryItems.size(); i++)
		return inventoryItems[index];
}
// Методы для вторичной реализации
void Inventory::saveInventoryToBinary(ofstream& outFile) const // Метод сохранения инвенторя в Бинарный файл
{
	int sizeInventoryItems = inventoryItems.size();
	outFile.write((char*)&sizeInventoryItems, sizeof(sizeInventoryItems));
	for (int i = 0; i < inventoryItems.size(); i++)
	{
		if (true) // выявления какой метод какого подкласса будет вызван
		{

		}
		inventoryItems[i]->saveItemsToBinary(outFile);
	}
	// реализовать для каждого наследника Items свой метод сохранения для возможности в дальнейшем масштабирования, чистоты кода и для инкапсуляции логики
}
void Inventory::loadInventoryFromBinary(ifstream& inFile) // Метод сохранения инвенторя в Текстовый файл
{
	// реализовать для каждого наследника Items свой метод сохранения для возможности в дальнейшем масштабирования, чистоты кода и для инкапсуляции логики
}
void Inventory::saveInventoryToText(ofstream& outFile) const // Метод загрузки инвенторя из Бинарного файла
{
	outFile << nameInventory << "\n";
	outFile << inventoryItems.size() << "\n";
	for (int i = 0; i < inventoryItems.size(); i++)
		inventoryItems[i]->saveItemsToText(outFile);
	// реализовать для каждого наследника Items свой метод загрузки для возможности в дальнейшем масштабирования, чистоты кода и для инкапсуляции логики
}
void Inventory::loadInventoryFromText(ifstream& inFile) // Метод загрузки инвенторя из Текстового файла // реализовать для каждого наследника Items свой метод загрузки для возможности в дальнейшем масштабирования, чистоты кода и для инкапсуляции логики
{
	std::getline(inFile, nameInventory);
	int size{};
	inFile >> size;
	inFile.ignore();
	string identifier;
	for (int i = 0; i < size; i++)
	{
		std::getline(inFile, identifier);
		Items* item = factory->createItem(identifier);
		if (item)
		{
			item->loadItemsFromText(inFile);
			inventoryItems.push_back(item);
		}
		else
		{
			std::cerr << "!!!ERROR!!!   Неизвестный идентификатор предмета" << identifier << endl; // Надо методе Загрузки реализовать поимку исключений и ее обработку если будет не корректно считывать или файл поврежден
			continue;
		}
	}
}
void Inventory::replaceItem(int index, Items* newItem) // метод замены предмета по индексу на новый
{
	// реализовать
}
// методы на будущее - пока не будут реализованы или будут иметь заглушку
void Inventory::sortInventoryBy(const string& criterion) // Метод сортировки по разным критериям
{
	cout << "Метод sortInventoryBy пока не реализован " << endl;
}
Items* Inventory::findItemByName(const string& name) // Метод поиска по имени // Можно реализовать также по различным критериям при необходимости
{
	cout << "Метод findItemByName пока не реализован " << endl;
	return nullptr;
}
int Inventory::countItemsById(const string& idIndex) // Подсчет количество одинаковых предметов // Можно реализовать также по различным критериям при необходимости, напримет по имени и типам
{
	cout << "Метод countItemsById пока не реализован " << endl;
	return 0;
}
void Inventory::clearInventory() // Метод полной очистки инветаря
{
	for (auto& item : inventoryItems)
		delete item;
	inventoryItems.clear();
}
double Inventory::calculatedTotalWeight() const // Подсчет общего веса инвентаря (в рюкзаке могут быть ограничения по весу или перегруз влияет на подвижность героя)
{
	cout << "Метод calculatedTotalWeight пока не реализован " << endl;
	return 0;
}
double Inventory::calculatedTotalValue() const // Оценка стоимости всех предметов инвентаре
{
	cout << "Метод calculatedTotalValue пока не реализован " << endl;
	return 0;
}
bool Inventory::hasItem(const string& name) const // Проверка наличия предмета по имения (например есть ли квестовый предмет в инвентаре для выполнения задания)
{
	cout << "Метод hasItem пока не реализован " << endl;
	return 0;
}
bool Inventory::isFullInventory() const // Проверка на заполненность инвенторя
{
	cout << "Метод isFullInventory пока не реализован " << endl;
	return 0;
}
void Inventory::stackIdenticalItems() // Метод объединения одинаковых предметов в стак (Weapon и Equipment не будет использовать данный метод)
{
	cout << "Метод stackIdenticalItems пока не реализован " << endl;
}