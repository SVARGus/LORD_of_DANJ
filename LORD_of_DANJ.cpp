/*
Проект Игры LORD of DANJ
Курсовая работа по основам С++.

*/

#include <iostream>
#include <stdlib.h>

/*      Перечень структур       */

struct Monster // Для начала будут созданы 5 монстров, надо будет также реализовать считывание данных по монстрам из файла
{
    char NameMonster[25];
    short LvlMonster;
    int HealthMonster;
    int PowerMonster;

    char TypeMonster[5]; // Тип монстра, будет влиять на расчет прочих характеристик отличных от базовых для 1 Lvl (на первое время все 5 монстров будут относиться к одному Виду)
    char DescriptionMonster[5]; // Описание монстра от 50 до 200 символов, но пока обойдемся без описания
};

struct HeroStat // Структура персонажа (героя)
{
    char NaeHero[25];
    short LvlHero;
    // 6 основных характеристик влияющих на прочие характеристики героя, такие как количество жизней, магический резервуар и прочее
    int PowerHero; // Сила
    int DexterityHero; // Ловкость
    int EnduranceHero; // Выносливость
    int IntelligenceHero; // Интилект
    int WisdomHero; // Мудрость
    int CharizmaHero; // Харизма


    int HealthHero; // Количество жизней. (Можноли сразу в структуре прописать формулу расчета данного показателя или лучше в отдельной функции реализовать?

};

/*      Перечень прототипов функций     */


/*      Тело функций        */

void Menu_Main(bool Start = false) // прописывать в функцию принимаемы данные или нет? или заменить тип на int с возможным выбором // Start = true если меню загружается пир старте программы
{
    enum MENU{ NEWGAME = 1, LOAD, SAVE, BACK, EXIT = 0}; // Очень удобно использовать в меню, VS сам подставляет варианты меню согласно списку енама
    std::cout << "<<<<<<<<<<----------||||||||||---------->>>>>>>>>>" << std::endl;
    std::cout << "\t\t\tГЛАВНОЕ МЕНЮ" << std::endl;
    std::cout << "<<<<<<<<<<----------||||||||||---------->>>>>>>>>>" << std::endl << std::endl;
    std::cout << "\tNEWGAME - 1" << std::endl << std::endl;
    std::cout << "\tLOADING - 2" << std::endl << std::endl;
    if (Start == false)
        std::cout << "\tSAVING - 3" << std::endl << std::endl;
    std::cout << "\tSAVING - 3" << std::endl << std::endl;
    std::cout << "\tBACK - 4" << std::endl << std::endl;
    std::cout << "\tEXIT - 0" << std::endl << std::endl;
    std::cin >> MENU;
    do
    {
        switch (MENU)
        {
        case NEWGAME:
            break;
        case LOAD:
            // реализовать функцию загрузки данных ранее сохраненных посредством выбора из ранее сохраненных (если таковых нету, то так и прописать что сохранения отсуствуют)
            break;
        case SAVE:
            if (Start != false)
            {
                std::cout << "Некорректный выбор, повторите: ";
                std::cin >> MENU;
            }
            else
            {
                // Реализовать функцию сохранения игры
            }
            break;
        case BACK:
            break;
        case EXIT:
            std::cout << "Спасибо за игру! Будем вас ждать снова!";
            exit(0); // Завершение программы. Для этого подключил библиотеку <stdlib.h>, она является стандартной и возможно не требует отдельного подключения
            break;
        default:
            std::cout << "Некорректный выбор, повторите: ";
            std::cin >> MENU;
        }
    } while (!MENU);
}

/*      Основное тело программы     */
int main() // Вписать мейн с принимающими данными
{
    setlocale(LC_ALL, "ru");

    HeroStat HeroGame{}; // Характеристики героя, при старте нулевые, через меню обновляются
    short LvlDanj{}; // Уровень данжа, при старте нулевой, в меню обновляются
    short SizeMobList{};
    Monster* MobList = new Monster[SizeMobList]{}; //Массив монстров загружаемый из файла при старте игры
    //реализовать функцию считывания данных из файла со списком Монстров, первые данные в файле это SizeMobList.
    Menu_Main(true); // запуск главного меню. Надо вписать все входные данные


    return 0;
}

