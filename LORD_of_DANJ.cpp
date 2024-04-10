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
    char NameHero[25]; // Имя героя (НИК)
    short LvlHero; // Уровень героя
    // 6 основных характеристик влияющих на прочие характеристики героя, такие как количество жизней, магический резервуар и прочее
    int PowerHero; // Сила
    int DexterityHero; // Ловкость
    int EnduranceHero; // Выносливость
    int IntelligenceHero; // Интилект
    int WisdomHero; // Мудрость
    int CharizmaHero; // Харизма
    int FreePoints; // Свободные очки характеристик (при старте все 6 характеристик по 1 + 10 сободных для распределения, сюда они также начисляются при повышении ЛВЛ
    // Характеристики которые расчитываются на основе 5 базовых статов (Сила, Ловкость...)
    int MinDamage; // Влияет Сила
    int MaxDamage; // Влияет Сила
    int Parrying; // Уклонение от атаки, уменьшает получаемый урон (влияет Ловкость и Мудрость)
    int Initiftive; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма)
    int HealthHero; // Количество жизней. (Можноли сразу в структуре прописать формулу расчета данного показателя или лучше в отдельной функции реализовать? (влияет Сила, Выносливость и уровень)
    // Позже можно добавить другие характеристики или выделить их в отдельную структуру доп характеристик
};

/*      Перечень прототипов функций     */


/*      Тело функций        */

void Menu_Main(bool Start = false) // прописывать в функцию принимаемы данные или нет? или заменить тип на int с возможным выбором // Start = true если меню загружается пир старте программы
{
    enum MENU{ NEWGAME = 1, LOAD, SAVE, BACK, EXIT = 0}; // Очень удобно использовать в меню, VS сам подставляет варианты меню согласно списку енама
    int Menu{};
    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;;
    std::cout << "\t\t\tГЛАВНОЕ МЕНЮ" << std::endl << std::endl;;
    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;
    std::cout << "\t\t\tNEWGAME - 1" << std::endl << std::endl;
    std::cout << "\t\t\tLOADING - 2" << std::endl << std::endl;
    if (Start == false)
        std::cout << "\t\t\tSAVING - 3" << std::endl << std::endl;
    std::cout << "\t\t\tSAVING - 3" << std::endl << std::endl;
    std::cout << "\t\t\tBACK - 4" << std::endl << std::endl;
    std::cout << "\t\t\tEXIT - 0" << std::endl << std::endl;
    std::cin >> Menu;
    do
    {
        switch (Menu)
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
                std::cin >> Menu;
            }
            else
            {
                // Реализовать функцию сохранения игры
            }
            break;
        case BACK:
            break;
        case EXIT:
            std::cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
            exit(0); // Завершение программы. Для этого подключил библиотеку <stdlib.h>, она является стандартной и возможно не требует отдельного подключения
            break;
        default:
            std::cout << "Некорректный выбор, повторите: ";
            std::cin >> Menu;
        }
    } while (Menu != 4);
}

void Recalculate_Hero(HeroStat HeroGame) // Функция перерасчета статов героя при повышении ЛВЛ или после распределения характеристик при старте
{

}

HeroStat Distr_Point_Hero(HeroStat HeroGame) // Функция распределения свободных очков при старте новой игры и при повышении уровня героя
{
    enum CHARACTER{POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA};
    int Points{};
    int Character{};
    while (HeroGame.FreePoints > 0)
    {
        std::cout << "Какую характеристику хотите повысить:\n(1) Сила\n(2) Ловкость\n(3) Выносливость\n(4) Интилект\n(5) Мудрость\n(6) Харизма" << std::endl;
        switch (Character)
        {
        case POWER:
            break;
        case DEXTERITY:
            break;
        case ENDURANCE:
            break;
        case INTELLIGENCE:
            break;
        case WISDOM:
            break;
        case CHARIZMA:
            break;
        default:
            break;
        }
    }
    return HeroGame;
}

HeroStat New_Game() // Функция ввода данных при старте
{
    HeroStat HeroGame{};
    HeroGame.LvlHero = 1;
    char Y_N{};
    do
    {
        std::cout << "Введите ваш Ник: ";
        std::cin >> HeroGame.NameHero;
        std::cout << "Ваш ник: " << HeroGame.NameHero << std::endl;
        std::cout << "Подтверждаете выбор? ДА(Y) - НЕТ(N) ";
        std::cin >> Y_N;
    } while (Y_N == 'N', 'n');
    //int Points{};
    // функция распределения очков

    return HeroGame;
}

/*      Основное тело программы     */
int main() // Вписать мейн с принимающими данными
{
    setlocale(LC_ALL, "ru");

    HeroStat HeroGame{"Name", 0, 1, 1, 1, 1, 1, 1, 10}; // Характеристики героя, при старте нулевые, через меню обновляются

    short LvlDanj{}; // Уровень данжа, при старте нулевой, в меню обновляются
    short SizeMobList{};
    Monster* MobList = new Monster[SizeMobList]{}; //Массив монстров загружаемый из файла при старте игры
    //реализовать функцию считывания данных из файла со списком Монстров, первые данные в файле это SizeMobList.
    Menu_Main(true); // запуск главного меню. Надо вписать все входные данные


    return 0;
}

