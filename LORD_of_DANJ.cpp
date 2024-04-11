﻿/*
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
    double Parrying; // Уклонение от атаки, уменьшает получаемый урон (влияет Ловкость и Мудрость)
    double Initiftive; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма). Может увеличивать урон при бое, имеет накопительный эффект в бою, Максимально за бой может быть 3-х кратное увеличение урона (активируется)
    int HealthHero; // Количество жизней. (Можноли сразу в структуре прописать формулу расчета данного показателя или лучше в отдельной функции реализовать? (влияет Сила, Выносливость и уровень)
    // Позже можно добавить другие характеристики или выделить их в отдельную структуру доп характеристик
};

/*      Перечень прототипов функций     */

void Menu_Main(short* LvlDanj, HeroStat* HeroGame, bool Start = false);
HeroStat Recalculate_Hero(HeroStat HeroGame);
HeroStat Distr_Point_Hero(HeroStat HeroGame);
HeroStat New_Game();


/*      Тело функций        */

void Menu_Main(short *LvlDanj, HeroStat *HeroGame, bool Start) // прописывать в функцию принимаемы данные или нет? или заменить тип на int с возможным выбором // Start = true если меню загружается пир старте программы
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
        case NEWGAME: // (ЗАКОНЧИЛ / НЕ ПРОВЕРЕН)
            *HeroGame = New_Game();
            return;
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

HeroStat Recalculate_Hero(HeroStat HeroGame) // Функция перерасчета статов героя при повышении ЛВЛ или после распределения характеристик при старте (ЗАКОНЧИЛ / НЕ ПРОВЕРЕН)
{
    HeroGame.MinDamage = 1 * HeroGame.PowerHero;
    HeroGame.MaxDamage = 1.5 * HeroGame.PowerHero;
    HeroGame.Parrying = 0.1 * HeroGame.DexterityHero + 0.02 * HeroGame.WisdomHero;
    HeroGame.Initiftive = 0.03 * HeroGame.IntelligenceHero + 0.02 * HeroGame.WisdomHero + 0.01 * HeroGame.CharizmaHero;
    HeroGame.HealthHero = (10 * HeroGame.LvlHero) * (0.8 * HeroGame.PowerHero + 0.4 * HeroGame.EnduranceHero);
    return HeroGame;
}

HeroStat Distr_Point_Hero(HeroStat HeroGame) // Функция распределения свободных очков при старте новой игры и при повышении уровня героя (ЗАКОНЧИЛ / НЕ ПРОВЕРЕН)
{
    enum CHARACTER{POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA};
    int Points{};
    int Character{};
    while (HeroGame.FreePoints > 0)
    {
        std::cout << "Какую характеристику хотите повысить:\n(1) Сила\n(2) Ловкость\n(3) Выносливость\n(4) Интилект\n(5) Мудрость\n(6) Харизма" << std::endl;
        std::cin >> Character;
        std::cout << "У вас свободных очков = " << HeroGame.FreePoints << std::endl;
        std::cout << "Сколько очков хотите добавить в выбранную характеристику = ";
        do
        {
            std::cin >> Points;
            if (Points > HeroGame.FreePoints)
                std::cout << "Вы указали некорректно количество добавляемых очков, укажите не более: " << HeroGame.FreePoints << std::endl;
        } while (Points > HeroGame.FreePoints);
        switch (Character)
        {
        case POWER:
            HeroGame.PowerHero += Points;
            break;
        case DEXTERITY:
            HeroGame.DexterityHero += Points;
            break;
        case ENDURANCE:
            HeroGame.EnduranceHero += Points;
            break;
        case INTELLIGENCE:
            HeroGame.IntelligenceHero += Points;
            break;
        case WISDOM:
            HeroGame.WisdomHero += Points;
            break;
        case CHARIZMA:
            HeroGame.CharizmaHero += Points;
        }
        HeroGame.FreePoints -= Points;
    }
    std::cout << "Все свободные очки распределены" << std::endl;
    return HeroGame;
}

HeroStat New_Game() // Функция ввода данных при старте (ЗАКОНЧИЛ / НЕ ПРОВЕРЕН)
{
    HeroStat HeroGame{ "Name", 1, 1, 1, 1, 1, 1, 1, 10 };
    char Y_N{};
    do
    {
        std::cout << "Введите ваш Ник: ";
        std::cin >> HeroGame.NameHero;
        std::cout << "Ваш ник: " << HeroGame.NameHero << std::endl;
        std::cout << "Подтверждаете выбор? ДА(Y) - НЕТ(N) ";
        std::cin >> Y_N;
    } while (Y_N == 'N'|| Y_N == 'n');
    HeroGame = Distr_Point_Hero(HeroGame); // Переход в распределение характеристик
    HeroGame = Recalculate_Hero(HeroGame); // Функция перерасчета характеристик с учетом распределенных статов

    return HeroGame;
}

/*      Основное тело программы     */
int main() // Вписать мейн с принимающими данными
{
    setlocale(LC_ALL, "ru");

    HeroStat HeroGame{}; // Характеристики героя
    short LvlDanj{1}; // Уровень данжа, при старте нулевой, в меню обновляются // переменную нужно сохранять при сохранении игры и выгружать при загрузке
    // Сдесь будет функция чтения данных по монтсрам в массив структурных данных монстров, сначала считывается SizeMobList, а потом уже MobList
    short SizeMobList{};
    Monster* MobList = new Monster[SizeMobList]{}; //Массив монстров загружаемый из файла при старте игры
    //реализовать функцию считывания данных из файла со списком Монстров, первые данные в файле это SizeMobList.
    Menu_Main(&LvlDanj, &HeroGame, true); // запуск главного меню. Надо вписать все входные данные


    return 0;
}

