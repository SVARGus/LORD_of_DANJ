#include "Items.h"
#include "Weapon.h"


Items* ConcreteItemFactory::createItem(const string& identifier)
{
	if (identifier == "wep01")
	{
		return new Sword();
	}
	else if (identifier == "wep02")
	{
		return new Spear();
	}
	// Далее будут добавляться другие предметы
	return nullptr;
}