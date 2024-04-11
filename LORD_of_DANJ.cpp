/*
Проект Игры LORD of DANJ
Курсовая работа по основам С++.

*/

#include <iostream>
#include <stdlib.h>
#include <filesystem> // Библиотека для работы с файловой системой (в данном случае создание папки для сохранения) Работает на стандарте с С++17

/*      Перечень структур       */

struct Monster // Для начала будут созданы 5 монстров, надо будет также реализовать считывание данных по монстрам из файла // ЕЩЕ не доработано
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

void Print_Hero(HeroStat HeroGame);
void Menu_Main(short* LvlDanj, HeroStat* HeroGame, bool Start = false);
HeroStat Recalculate_Hero(HeroStat HeroGame);
HeroStat Distr_Point_Hero(HeroStat HeroGame);
HeroStat New_Game();
void Save_Game(short LvlDanj, HeroStat HeroGame); // Дописать вводные данные


/*      Тело функций        */
void Print_Hero(HeroStat HeroGame) // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
{
    std::cout << "Герой - " << HeroGame.NameHero << std::endl;
    std::cout << "Уровень - " << HeroGame.LvlHero << std::endl;
    std::cout << "Сила: " << HeroGame.PowerHero << std::endl;
    std::cout << "Ловкость: " << HeroGame.DexterityHero << std::endl;
    std::cout << "Выносливость: " << HeroGame.EnduranceHero << std::endl;
    std::cout << "Интилект: " << HeroGame.IntelligenceHero << std::endl;
    std::cout << "Мудрость: " << HeroGame.WisdomHero << std::endl;
    std::cout << "Харизма: " << HeroGame.CharizmaHero << std::endl;
    std::cout << "Свободные очки: " << HeroGame.FreePoints << std::endl;
    std::cout << "Минимальный урон: " << HeroGame.MinDamage << std::endl;
    std::cout << "Максимальный урон: " << HeroGame.MaxDamage << std::endl;
    std::cout << "Уклонение: " << HeroGame.Parrying << std::endl;
    std::cout << "Инициатива: " << HeroGame.Initiftive << std::endl;
    std::cout << "Количество здоровья: " << HeroGame.HealthHero << std::endl;
}

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
        case NEWGAME: // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
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
                Save_Game(LvlDanj, HeroGame);
            }
            return;
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

HeroStat Recalculate_Hero(HeroStat HeroGame) // Функция перерасчета статов героя при повышении ЛВЛ или после распределения характеристик при старте (ЗАКОНЧИЛ / ПРОВЕРЕНО)
{
    HeroGame.MinDamage = 1 * HeroGame.PowerHero;
    HeroGame.MaxDamage = 1.5 * HeroGame.PowerHero;
    HeroGame.Parrying = 0.1 * HeroGame.DexterityHero + 0.02 * HeroGame.WisdomHero;
    HeroGame.Initiftive = 0.03 * HeroGame.IntelligenceHero + 0.02 * HeroGame.WisdomHero + 0.01 * HeroGame.CharizmaHero;
    HeroGame.HealthHero = (10 * HeroGame.LvlHero) * (0.8 * HeroGame.PowerHero + 0.4 * HeroGame.EnduranceHero);
    return HeroGame;
}

HeroStat Distr_Point_Hero(HeroStat HeroGame) // Функция распределения свободных очков при старте новой игры и при повышении уровня героя (ЗАКОНЧИЛ / ПРОВЕРЕНО)
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

HeroStat New_Game() // Функция ввода данных при старте (ЗАКОНЧИЛ / ПРОВЕРЕНО)
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

void Save_Game(short LvlDanj, HeroStat HeroGame) // Функция сохранения игры (дописать вводные данные)
{
    std::filesystem::path SaveGame = "Save_LORD_of_DANJ"; // Создаем папку для сохранения
    if (!std::filesystem::exists(SaveGame))
        std::filesystem::create_directories(SaveGame);
    // Далее сохоранение в файл, пока для игры будет только одно сохранение, позже можно сделать сохранение и загрузку если игроки разные
    FILE* Savegame;
    const char* direct = "Save_LORD_of_DANJ\\Savegame.txt";
    if ((fopen_s(&Savegame, direct, "w")) == NULL)
    {
        fprintf(Savegame, "%d ", LvlDanj);
        fprintf(Savegame, "\n");
        fprintf(Savegame, "%s ", HeroGame.NameHero);
        fprintf(Savegame, "%d ", HeroGame.LvlHero);
        fprintf(Savegame, "%d ", HeroGame.PowerHero);
        fprintf(Savegame, "%d ", HeroGame.DexterityHero);
        fprintf(Savegame, "%d ", HeroGame.EnduranceHero);
        fprintf(Savegame, "%d ", HeroGame.IntelligenceHero);
        fprintf(Savegame, "%d ", HeroGame.WisdomHero);
        fprintf(Savegame, "%d ", HeroGame.CharizmaHero);
        fprintf(Savegame, "%d ", HeroGame.FreePoints);
        fprintf(Savegame, "%d ", HeroGame.MinDamage);
        fprintf(Savegame, "%d ", HeroGame.MaxDamage);
        fprintf(Savegame, "%f ", HeroGame.Parrying);
        fprintf(Savegame, "%f ", HeroGame.Initiftive);
        fprintf(Savegame, "%d ", HeroGame.HealthHero);
    }
    else
        std::cout << "Ошибка создания сохранения!" << std::endl;
    if (fclose(Savegame) == EOF)
        std::cout << "Ошибка при сохранение!" << std::endl;
    else
        std::cout << "УСПЕШНОЕ СОХРАНЕНИЕ" << std::endl;
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

    while (true) // временный цикл с меню для проверки закгрузки данных игрока и сохранения данных игрока 
    {
        Menu_Main(&LvlDanj, &HeroGame);
    }

    Print_Hero(HeroGame); // Временный вывод для проверки

    return 0;
}

