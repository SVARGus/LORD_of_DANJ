#pragma once
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

// Класс интерфейс для подклассов Weapon, Equipment, OtherItems
class Items
{
protected:
	string idItems{}; /*пример Айди : wep****, eqp****, oth**** .Первые три символа будут обозначать принадлежность(Оружие, броня, прочее...), 
	следующий символ будет выделять уже подвид, например 1 - меч, 2 - копье, 3 - дубина (надо подробно расписать чтоб потом не путаться)*/
	/*
	Расшифровка idItems для идентификации и дальнейшего сохранения и загрузки:
	первые 3 символа в форме латиницы обозначают подклассы. На данном этапе разработки "wep" Оружие, "eqp" Экипировка, "oth" прочие претдметы, далее можно будет добавить иные индификаторы
	с 4-5 сиволы в форме цифр обозначают конечный класс наследник. Для Weapon 01 - Меч, 02 - Копье, 03 - Дубина и так далее. Позже разработать для экипировки и прочих предметов
	с 6-9 символы в форме цифр присвается каждому уникальному предмету свое. Например Заточенное копье "Гарпун стенаний" будет иметь idItems = wep020003
	с 10 по 12 можно указать латинские символы отвечающие за зачорование, притом каждый символ свое зачарование, но не более 3 на один предмет. 10-12 будут реализованы в будущем, возможно после изучения баз данных и уже буду работать с базами
	*/
	string name{}; // Имя предмета
public:
	virtual ~Items(){}
	virtual void displayItems() const = 0;
	virtual void displayNameItems() const = 0; // Вывод на экран составного Наименование предмета
	string getName() { return name; };
	virtual void saveItemsToBinary(ofstream& outFile) const = 0; // Метод сохранения Weapon в Бинарный файл
	virtual void loadItemsFromBinary(ifstream& inFile) = 0; // Метод сохранения Weapon в Текстовый файл
	virtual void saveItemsToText(ofstream& outFile) const = 0; // Метод загрузки Weapon из Бинарного файла
	virtual void loadItemsFromText(ifstream& inFile) = 0; // Метод загрузки Weapon из Текстового файла
};

class ItemFactory
{
public:
	virtual Items* createItem(const string& identifier) = 0;
	virtual ~ItemFactory() {}
};
class ConcreteItemFactory : public ItemFactory
{
public:
	Items* createItem(const string& identifier) override;
};

