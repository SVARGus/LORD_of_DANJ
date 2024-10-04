/*
Проект Игры LORD of DANJ
Курсовая работа по основам С++.
Переделка под ООП на С++ с применение паттернов

*/

#include <iostream>
#include <stdlib.h>
#include <filesystem> // Библиотека для работы с файловой системой (в данном случае создание папки для сохранения) Работает на стандарте с С++17
#include <chrono> 
#include <Windows.h>
#include "Game.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    Game &newGame = Game::getInstance();
    newGame.run();


    return 0;
}

//
///*      Перечень структур       */
//
//struct Monster // Для начала будут созданы 5 монстров, надо будет также реализовать считывание данных по монстрам из файла // ЕЩЕ не доработано
//{
//    char NameMonster[25];
//    short LvlMonster; // пока не используется, на на будущее добавил
//    // 6 базовых характеристик, на 1 лвл в сумме 16 и у каждого монстра по разному распределены. При повышении лвл будет добавлятся минимум в 2 раза больше чем при повышении лв героя
//    int PowerMonster;
//    int DexterityMonster; // Ловкость
//    int EnduranceMonster; // Выносливость
//    int IntelligenceMonster; // Интилект
//    int WisdomMonster; // Мудрость
//    int CharizmaMonster; // Харизма
//
//    // Характеристики которые расчитываются на основе 5 базовых статов (Сила, Ловкость...)
//    int MinDamage; // Влияет Сила
//    int MaxDamage; // Влияет Сила
//    double Parrying; // Уклонение от атаки, уменьшает получаемый урон (влияет Ловкость и Мудрость)
//    double Initiative; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма). Может увеличивать урон при бое, имеет накопительный эффект в бою, Максимально за бой может быть 3-х кратное увеличение урона (активируется)
//    int HealthMonster;
//
//    char TypeMonster[5]; // Тип монстра, будет влиять на расчет прочих характеристик отличных от базовых для 1 Lvl (на первое время все 5 монстров будут относиться к одному Виду)
//    char DescriptionMonster[5]; // Описание монстра от 50 до 200 символов, но пока обойдемся без описания
//};
//
//struct HeroStat // Структура персонажа (героя)
//{
//    char NameHero[25]; // Имя героя (НИК)
//    short LvlHero; // Уровень героя
//    // 6 основных характеристик влияющих на прочие характеристики героя, такие как количество жизней, магический резервуар и прочее
//    int PowerHero; // Сила
//    int DexterityHero; // Ловкость
//    int EnduranceHero; // Выносливость
//    int IntelligenceHero; // Интилект
//    int WisdomHero; // Мудрость
//    int CharizmaHero; // Харизма
//    int FreePoints; // Свободные очки характеристик (при старте все 6 характеристик по 1 + 10 сободных для распределения, сюда они также начисляются при повышении ЛВЛ
//    // Характеристики которые расчитываются на основе 5 базовых статов (Сила, Ловкость...)
//    int MinDamage; // Влияет Сила
//    int MaxDamage; // Влияет Сила
//    double Parrying; // Уклонение от атаки, уменьшает получаемый урон (влияет Ловкость и Мудрость)
//    double Initiative; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма). Может увеличивать урон при бое, имеет накопительный эффект в бою, Максимально за бой может быть 3-х кратное увеличение урона (активируется)
//    int HealthHero; // Количество жизней. (Можноли сразу в структуре прописать формулу расчета данного показателя или лучше в отдельной функции реализовать? (влияет Сила, Выносливость и уровень)
//    int ScalExp; // Шкала опыта
//    int ScalExpUp; // Сколько нужно уопыта набрать для нового уровня героя
//    short WinBattle; // счетчик побед героя без проигрыша (несгораемый уровень будет 5, 10, 15 и т.д.)
//    short OpenLVLDanj; // какой максимальный уровень дажна открыт у игрока
//    // Позже можно добавить другие характеристики или выделить их в отдельную структуру доп характеристик
//};
//
///*      Перечень прототипов функций     */
//
//void Print_Hero(HeroStat HeroGame);
//void Menu_Main(short& LvlDanj, HeroStat& HeroGame,int *MenuVillage, bool Start = false);
//HeroStat Recalculate_Hero(HeroStat HeroGame);
//HeroStat Distr_Point_Hero(HeroStat HeroGame);
//HeroStat New_Game();
//void Save_Game(const short LvlDanj, const HeroStat HeroGame); // Дописать вводные данные
//void Load_Game(short& LvlDanj, HeroStat& HeroGame);
//void Load_Mob_List(short& SizeMobList, Monster*& MobList);
//void Print_Mob_List(short SizeMobList, Monster* MobList);
//Monster Recalculate_Mob(Monster* Moblist, int LvlDanj, int Index);
//int Damage_Battle(int MinDamage, int MaxDamage, double Initiative);
//bool Parrying_Battle(double Parrying, int Lvl);
//void Battle_Monste_Hero(short& LvlDanj, HeroStat& HeroGame, const short SizeMobList, Monster* const Moblist);
//
//
//
///*      Тело функций        */
//void Print_Hero(HeroStat HeroGame) // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//{
//    std::cout << "Герой - " << HeroGame.NameHero << std::endl;
//    std::cout << "Уровень - " << HeroGame.LvlHero << std::endl;
//    std::cout << "Сила: " << HeroGame.PowerHero << std::endl;
//    std::cout << "Ловкость: " << HeroGame.DexterityHero << std::endl;
//    std::cout << "Выносливость: " << HeroGame.EnduranceHero << std::endl;
//    std::cout << "Интилект: " << HeroGame.IntelligenceHero << std::endl;
//    std::cout << "Мудрость: " << HeroGame.WisdomHero << std::endl;
//    std::cout << "Харизма: " << HeroGame.CharizmaHero << std::endl;
//    std::cout << "Свободные очки: " << HeroGame.FreePoints << std::endl;
//    std::cout << "Минимальный урон: " << HeroGame.MinDamage << std::endl;
//    std::cout << "Максимальный урон: " << HeroGame.MaxDamage << std::endl;
//    std::cout << "Уклонение: " << HeroGame.Parrying << std::endl;
//    std::cout << "Инициатива: " << HeroGame.Initiative << std::endl;
//    std::cout << "Количество здоровья: " << HeroGame.HealthHero << std::endl;
//    std::cout << "Шкала текуцщего опыта: " << HeroGame.ScalExp << std::endl;
//    std::cout << "Сколько опыта для перехода на новый уровень: " << HeroGame.ScalExpUp << std::endl;
//    std::cout << "счетчик побед пез проигрыша: " << HeroGame.WinBattle << std::endl;
//    std::cout << "Максимальный уровень дажа открытый у героя: " << HeroGame.OpenLVLDanj << std::endl;
//}
//
//void Menu_Main(short& LvlDanj, HeroStat& HeroGame, int *MenuVillage, bool Start) // прописывать в функцию принимаемы данные или нет? или заменить тип на int с возможным выбором // Start = true если меню загружается пир старте программы
//{
//    system("cls"); // очистка консоли
//    enum MENU { NEWGAME = 1, LOAD, SAVE, BACK, EXIT = 0 }; // Очень удобно использовать в меню, VS сам подставляет варианты меню согласно списку енама
//    int Menu{};
//    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;;
//    std::cout << "\t\t\tГЛАВНОЕ МЕНЮ" << std::endl << std::endl;;
//    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;
//    std::cout << "\t\t\tNEWGAME - 1" << std::endl << std::endl;
//    std::cout << "\t\t\tLOADING - 2" << std::endl << std::endl;
//    if (Start == false)
//    {
//        std::cout << "\t\t\tSAVING - 3" << std::endl << std::endl;
//        std::cout << "\t\t\tBACK - 4" << std::endl << std::endl;
//    }
//    std::cout << "\t\t\tEXIT - 0" << std::endl << std::endl;
//    std::cin >> Menu;
//    do
//    {
//        switch (Menu)
//        {
//        case NEWGAME: // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//            HeroGame = New_Game();
//            return;
//            break;
//        case LOAD:
//            Load_Game(LvlDanj, HeroGame); // реализовать функцию загрузки данных ранее сохраненных посредством выбора из ранее сохраненных (если таковых нету, то так и прописать что сохранения отсуствуют)
//            return;
//            break;
//        case SAVE:
//            if (Start != false)
//            {
//                std::cout << "Некорректный выбор, повторите: ";
//                std::cin >> Menu;
//            }
//            else
//            {
//                Save_Game(LvlDanj, HeroGame);
//            }
//            return;
//            break;
//        case BACK:
//            return;
//            break;
//        case EXIT:
//            std::cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
//            *MenuVillage = 0;
//            return;
//            //exit(0); // Завершение программы. Для этого подключил библиотеку <stdlib.h>, она является стандартной и возможно не требует отдельного подключения
//            break;
//        default:
//            std::cout << "Некорректный выбор, повторите: ";
//            std::cin >> Menu;
//        }
//    } while (Menu != 4);
//}
//
//HeroStat Recalculate_Hero(HeroStat HeroGame) // Функция перерасчета статов героя при повышении ЛВЛ или после распределения характеристик при старте (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//{
//    HeroGame.MinDamage = 1 * HeroGame.PowerHero;
//    HeroGame.MaxDamage = 1.5 * HeroGame.PowerHero;
//    HeroGame.Parrying = 0.1 * HeroGame.DexterityHero + 0.02 * HeroGame.WisdomHero;
//    HeroGame.Initiative = 0.03 * HeroGame.IntelligenceHero + 0.02 * HeroGame.WisdomHero + 0.01 * HeroGame.CharizmaHero;
//    HeroGame.HealthHero = (10 * HeroGame.LvlHero) * (0.8 * HeroGame.PowerHero + 0.4 * HeroGame.EnduranceHero);
//    HeroGame.ScalExpUp = 100;
//    for (int i = 1; i < HeroGame.LvlHero; i++)
//    {
//        HeroGame.ScalExpUp *= 1.5 * i;
//    }
//    return HeroGame;
//}
//
//HeroStat Distr_Point_Hero(HeroStat HeroGame) // Функция распределения свободных очков при старте новой игры и при повышении уровня героя (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//{
//    enum CHARACTER { POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA };
//    int Points{};
//    int Character{};
//    while (HeroGame.FreePoints > 0)
//    {
//        std::cout << "Какую характеристику хотите повысить:\n(1) Сила\n(2) Ловкость\n(3) Выносливость\n(4) Интилект\n(5) Мудрость\n(6) Харизма" << std::endl;
//        std::cin >> Character;
//        std::cout << "У вас свободных очков = " << HeroGame.FreePoints << std::endl;
//        std::cout << "Сколько очков хотите добавить в выбранную характеристику = ";
//        do
//        {
//            std::cin >> Points;
//            if (Points > HeroGame.FreePoints)
//                std::cout << "Вы указали некорректно количество добавляемых очков, укажите не более: " << HeroGame.FreePoints << std::endl;
//        } while (Points > HeroGame.FreePoints);
//        switch (Character)
//        {
//        case POWER:
//            HeroGame.PowerHero += Points;
//            break;
//        case DEXTERITY:
//            HeroGame.DexterityHero += Points;
//            break;
//        case ENDURANCE:
//            HeroGame.EnduranceHero += Points;
//            break;
//        case INTELLIGENCE:
//            HeroGame.IntelligenceHero += Points;
//            break;
//        case WISDOM:
//            HeroGame.WisdomHero += Points;
//            break;
//        case CHARIZMA:
//            HeroGame.CharizmaHero += Points;
//        default:
//            HeroGame.FreePoints += Points;
//        }
//        HeroGame.FreePoints -= Points;
//    }
//    std::cout << "Все свободные очки распределены" << std::endl;
//    return HeroGame;
//}
//
//HeroStat New_Game() // Функция ввода данных при старте (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//{
//    system("cls"); // очистка консоли
//    HeroStat HeroGame{ "Name", 1, 1, 1, 1, 1, 1, 1, 10 };
//    HeroGame.WinBattle = 0;
//    HeroGame.OpenLVLDanj = 1;
//    char Y_N{};
//    do
//    {
//        std::cout << "Введите ваш Ник: ";
//        std::cin >> HeroGame.NameHero;
//        std::cout << "Ваш ник: " << HeroGame.NameHero << std::endl;
//        std::cout << "Подтверждаете выбор? ДА(Y) - НЕТ(N) ";
//        std::cin >> Y_N;
//    } while (Y_N == 'N' || Y_N == 'n');
//    HeroGame = Distr_Point_Hero(HeroGame); // Переход в распределение характеристик
//    HeroGame = Recalculate_Hero(HeroGame); // Функция перерасчета характеристик с учетом распределенных статов
//
//    return HeroGame;
//}
//
//void Save_Game(const short LvlDanj, const HeroStat HeroGame) // Функция сохранения игры (дописать вводные данные)
//{
//    std::filesystem::path SaveGame = "Save_LORD_of_DANJ"; // Создаем папку для сохранения
//    if (!std::filesystem::exists(SaveGame))
//        std::filesystem::create_directories(SaveGame);
//    // Далее сохоранение в файл, пока для игры будет только одно сохранение, позже можно сделать сохранение и загрузку если игроки разные
//    FILE* Savegame;
//    const char* direct = "Save_LORD_of_DANJ\\Savegame.txt";
//    if ((fopen_s(&Savegame, direct, "w")) == NULL)
//    {
//        fprintf(Savegame, "%d ", LvlDanj); // можно удалить из сохранений и загрузок. но после окончательной проверки
//        fprintf(Savegame, "\n"); // можно удалить из сохранений и загрузок. но после окончательной проверки
//        fprintf(Savegame, "%s ", HeroGame.NameHero);
//        fprintf(Savegame, "%hd ", HeroGame.LvlHero);
//        fprintf(Savegame, "%d ", HeroGame.PowerHero);
//        fprintf(Savegame, "%d ", HeroGame.DexterityHero);
//        fprintf(Savegame, "%d ", HeroGame.EnduranceHero);
//        fprintf(Savegame, "%d ", HeroGame.IntelligenceHero);
//        fprintf(Savegame, "%d ", HeroGame.WisdomHero);
//        fprintf(Savegame, "%d ", HeroGame.CharizmaHero);
//        fprintf(Savegame, "%d ", HeroGame.FreePoints);
//        fprintf(Savegame, "%d ", HeroGame.MinDamage);
//        fprintf(Savegame, "%d ", HeroGame.MaxDamage);
//        fprintf(Savegame, "%f ", HeroGame.Parrying);
//        fprintf(Savegame, "%f ", HeroGame.Initiative);
//        fprintf(Savegame, "%d ", HeroGame.HealthHero);
//        fprintf(Savegame, "%d ", HeroGame.ScalExp);
//        fprintf(Savegame, "%d ", HeroGame.ScalExpUp);
//        fprintf(Savegame, "%hd ", HeroGame.WinBattle);
//        fprintf(Savegame, "%hd ", HeroGame.OpenLVLDanj);
//    }
//    else
//        std::cout << "Ошибка создания сохранения!" << std::endl;
//    if (fclose(Savegame) == EOF)
//        std::cout << "Ошибка при сохранение!" << std::endl;
//    else
//        std::cout << "УСПЕШНОЕ СОХРАНЕНИЕ" << std::endl;
//    Sleep(3000); // Системная пауза в 3 сек
//    system("cls"); // очистка консоли
//}
//
//void Load_Game(short& LvlDanj, HeroStat& HeroGame) // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
//{
//    FILE* Loadgame;
//    const char* direct = "Save_LORD_of_DANJ\\Savegame.txt";
//    if ((fopen_s(&Loadgame, direct, "r")) == NULL)
//    {
//        fscanf_s(Loadgame, "%hd ", &LvlDanj); // можно удалить из сохранений и загрузок. но после окончательной проверки
//        fscanf_s(Loadgame, "\n"); // можно удалить из сохранений и загрузок. но после окончательной проверки
//        fscanf_s(Loadgame, "%s ", &HeroGame.NameHero, sizeof(HeroGame.NameHero));
//        fscanf_s(Loadgame, "%hd ", &HeroGame.LvlHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.PowerHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.DexterityHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.EnduranceHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.IntelligenceHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.WisdomHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.CharizmaHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.FreePoints);
//        fscanf_s(Loadgame, "%d ", &HeroGame.MinDamage);
//        fscanf_s(Loadgame, "%d ", &HeroGame.MaxDamage);
//        fscanf_s(Loadgame, "%lf ", &HeroGame.Parrying);
//        fscanf_s(Loadgame, "%lf ", &HeroGame.Initiative);
//        fscanf_s(Loadgame, "%d ", &HeroGame.HealthHero);
//        fscanf_s(Loadgame, "%d ", &HeroGame.ScalExp);
//        fscanf_s(Loadgame, "%d ", &HeroGame.ScalExpUp);
//        fscanf_s(Loadgame, "&hd ", &HeroGame.WinBattle);
//        fscanf_s(Loadgame, "%hd ", &HeroGame.OpenLVLDanj);
//    }
//    else
//        std::cout << "Ошибка загрузки" << std::endl;
//    if (fclose(Loadgame) == EOF)
//        std::cout << "Ошибка при Загрузке!" << std::endl;
//    else
//        std::cout << "ИГРА УСПЕШНО ЗАГРУЖЕНА" << std::endl;
//    Sleep(3000); // Системная пауза в 3 сек
//    system("cls"); // очистка консоли
//}
//
//void Load_Mob_List(short& SizeMobList, Monster*& MobList) // (ЗАКОНЧИЛ / ПРОВЕРЕНО) Осталось только базу п\монстров подкорректировать
//{
//    FILE* LoadMobList;
//    const char* direct = "MobList.txt"; // файл пока не создан
//    if ((fopen_s(&LoadMobList, direct, "r")) != NULL)
//        std::cout << "Ошибка загрузки базы Монстров или файл " << direct << " отсуствует!" << std::endl;
//    else
//    {
//        fscanf_s(LoadMobList, "%d ", &SizeMobList);
//        fscanf_s(LoadMobList, "\n");
//        MobList = new Monster[SizeMobList]{};
//        for (int i = 0; i < SizeMobList; i++)
//        {
//            fscanf_s(LoadMobList, "%s ", MobList[i].NameMonster, sizeof(MobList[i].NameMonster));
//            fscanf_s(LoadMobList, "%hd ", &MobList[i].LvlMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].PowerMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].DexterityMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].EnduranceMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].IntelligenceMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].WisdomMonster);
//            fscanf_s(LoadMobList, "%d ", &MobList[i].CharizmaMonster);
//        }
//    }
//    if (fclose(LoadMobList) == EOF)
//        std::cout << "Ошибка закрытия файла с данными монстров" << std::endl;
//    else
//        std::cout << "База Монстров успешно загружена!!!" << std::endl;
//    Sleep(3000); // Системная пауза в 3 сек
//    system("cls"); // очистка консоли
//}
//
//void Print_Mob_List(short SizeMobList, Monster* MobList) // Функция вывода данных по монстрам - временно для проверки
//{
//    std::cout << SizeMobList << std::endl;
//    for (int i = 0; i < SizeMobList; i++)
//    {
//        std::cout << MobList[i].NameMonster << " " << MobList[i].LvlMonster << " " << MobList[i].PowerMonster << " " << MobList[i].DexterityMonster << " " << MobList[i].EnduranceMonster << " " << MobList[i].IntelligenceMonster << " " << MobList[i].WisdomMonster << " " << MobList[i].CharizmaMonster << std::endl;
//    }
//}
//
//Monster Recalculate_Mob(Monster* Moblist, int LvlDanj, int Index) // Функция расчета статов монстра, запускается перед боем после рандомного выбора монстра (ГОТОВА / НЕ ПРВОЕРЕНА)
//{
//    --LvlDanj; // для первого уровня не будет пересчет основных статов
//    Monster MobBattle = Moblist[Index];
//    MobBattle.PowerMonster = Moblist[Index].PowerMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.DexterityMonster = Moblist[Index].DexterityMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.EnduranceMonster = Moblist[Index].EnduranceMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.IntelligenceMonster = Moblist[Index].IntelligenceMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.WisdomMonster = Moblist[Index].WisdomMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.CharizmaMonster = Moblist[Index].CharizmaMonster + ((rand() % 2 + 1) * LvlDanj);
//    MobBattle.MinDamage = 1 * MobBattle.PowerMonster;
//    MobBattle.MaxDamage = 1.5 * MobBattle.PowerMonster;
//    MobBattle.Parrying = 0.1 * MobBattle.DexterityMonster + 0.02 * MobBattle.WisdomMonster;
//    MobBattle.Initiative = 0.03 * MobBattle.IntelligenceMonster + 0.02 * MobBattle.WisdomMonster + 0.01 * MobBattle.CharizmaMonster;
//    MobBattle.HealthMonster = (10 * ++LvlDanj) * (0.8 * MobBattle.PowerMonster + 0.4 * MobBattle.EnduranceMonster);
//
//    return MobBattle;
//}
//
//int Damage_Battle(int MinDamage, int MaxDamage, double Initiative) // Функция расчета урона с учетом инициативы (ГОТОВА / НЕ ПРВОЕРЕНА)
//{
//    int Damage = rand() % (MaxDamage - MinDamage) + MinDamage;
//    return (Damage + Damage * Initiative);
//}
//
//bool Parrying_Battle(double Parrying, int Lvl) // Функция просчитывания шанса уклониться от удара (ГОТОВА / НЕ ПРВОЕРЕНА)
//{
//    if (rand() % 30 / 10 <= Parrying / Lvl)
//        return true;
//    return false;
//}
//
//void Battle_Monste_Hero(short& LvlDanj, HeroStat& HeroGame, const short SizeMobList, Monster* const Moblist) // Функция битвы. (ГОТОВА / НЕ ПРВОЕРЕНА)
//{
//    bool Begin{ true };
//    while (Begin == true)
//    {
//        int Index = rand() % SizeMobList; // Рандобный выбор Монстра с которым будет битва
//        Monster MobBattle = Recalculate_Mob(Moblist, LvlDanj, Index); // Генерирует статы монстра исходя из уровня данжа
//        int HealthHero = HeroGame.HealthHero; // Характеристика показывающая количество жизней героя в течение боя
//        std::cout << "Пробираясь по Подземелью " << LvlDanj << " уровня, вы повстречали монстра " << MobBattle.NameMonster << ".\nПриготовьтесь к битве!!!" << std::endl;
//        int Damage{}; // нанесенный урон
//        int ExpBattle{}; // начисляемый опыт в результате боя
//        for (int i = 0; HealthHero > 0 && MobBattle.HealthMonster > 0; i++)
//        {
//            if (HeroGame.Initiative >= MobBattle.Initiative && i == 0)
//            {
//                if (Parrying_Battle(MobBattle.Parrying, LvlDanj) == false)
//                {
//                    Damage = Damage_Battle(HeroGame.MinDamage, HeroGame.MaxDamage, HeroGame.Initiative);
//                    std::cout << "Вы имеет преимущество и атакуете первым и наносите " << MobBattle.NameMonster;
//                    std::cout << " увеличенный урон равный - " << Damage << std::endl;
//                    MobBattle.HealthMonster -= Damage;
//                }
//                else
//                {
//                    std::cout << "Имея преимущество в скрытности, вы подкрадываетесь и атакуете " << MobBattle.NameMonster;
//                    std::cout << ", но Он в последний момент замечает вашу атаку и уворачивается" << std::endl;
//                }
//                Sleep(1000);
//            }
//            if (Parrying_Battle(HeroGame.Parrying, HeroGame.LvlHero) == false)
//            {
//                Damage = Damage_Battle(MobBattle.MinDamage, MobBattle.MaxDamage, MobBattle.Initiative);
//                std::cout << MobBattle.NameMonster << " наносит вам урон - " << Damage << std::endl;
//                HealthHero -= Damage;
//            }
//            else
//            {
//                std::cout << "Вам удается увернуться от удара " << MobBattle.NameMonster << std::endl;
//            }
//            Sleep(1000);
//            if (Parrying_Battle(MobBattle.Parrying, LvlDanj) == false)
//            {
//                Damage = Damage_Battle(HeroGame.MinDamage, HeroGame.MaxDamage, HeroGame.Initiative);
//                std::cout << "Вы наносите " << Damage << " урона " << MobBattle.NameMonster << std::endl;
//                MobBattle.HealthMonster -= Damage;
//            }
//            else
//            {
//                std::cout << MobBattle.NameMonster << " уварачивается от вашего удара" << std::endl;
//            }
//            Sleep(1000);
//            std::cout << "По результатам раунда " << i + 1 << " остаток жизней: " << HeroGame.NameHero << " = " << HealthHero << "; " << MobBattle.NameMonster << " = " << MobBattle.HealthMonster << std::endl << std::endl;
//            Sleep(1000);
//            // вставить паузу (5 сек будет достаточно) или по нажатию
//        }
//        if (HealthHero > 0 && MobBattle.HealthMonster <= 0)
//        {
//            std::cout << "Поздравляю. вы победили в честном бою " << MobBattle.NameMonster << std::endl;
//            Sleep(500);
//            ExpBattle = 10 + ((LvlDanj - 1) * 3);
//            std::cout << "За победу вам начислено " << ExpBattle << " опыта" << std::endl;
//            Sleep(500);
//            HeroGame.ScalExp += ExpBattle;
//            if (HeroGame.WinBattle < LvlDanj * 5)
//                HeroGame.WinBattle++;
//            std::cout << "Счетчик побед составляет = " << HeroGame.WinBattle << std::endl;
//            Sleep(500);
//        }
//        else if (HealthHero <= 0 && MobBattle.HealthMonster > 0)
//        {
//            HeroGame.WinBattle -= (HeroGame.WinBattle % 5);
//            std::cout << "Вы проиграли и ваш счетчик побед сброшен до " << HeroGame.WinBattle << std::endl;
//        }
//        else
//            std::cout << "Бой завершился в нечью" << std::endl;
//        if (HeroGame.ScalExp >= HeroGame.ScalExpUp)
//        {
//            HeroGame.ScalExp = (HeroGame.ScalExp % HeroGame.ScalExpUp);
//            HeroGame.LvlHero++;
//            HeroGame.FreePoints += 2;
//            std::cout << "Ваш уровень повышен до " << HeroGame.LvlHero << std::endl;
//            HeroGame = Recalculate_Hero(HeroGame); // перерасчет статов после повышения, очки будет распределить только в деревне (вне данжа)
//        }
//        if (HeroGame.WinBattle >= (HeroGame.WinBattle / LvlDanj) && HeroGame.WinBattle >= (5 * LvlDanj) && LvlDanj == HeroGame.OpenLVLDanj)
//        {
//            HeroGame.OpenLVLDanj++;
//            std::cout << "Вы открыли новый уровень данжа: " << HeroGame.OpenLVLDanj << std::endl;
//            bool Variable{};
//            std::cout << "Желаете перейти на новый уровень? Учтите на новом уровне более сильные монстры и вы возможно не сможете с ними справиться!. Ваш выбор: (1) Перейти. (0) Отказаться = ";
//            std::cin >> Variable;
//            if (Variable == true)
//                LvlDanj++;
//        }
//        /* Также здесь прописать системную паузу, также и в каждом раунде*/
//        std::cout << "Продожить исследование данжа (1) или венуться в деревню (0): ";
//        std::cin >> Begin;
//        system("cls");
//    }
//}
//
///*      Основное тело программы     */
//int main_2() // Вписать мейн с принимающими данными
//{
//    setlocale(LC_ALL, "ru");
//    srand(time(NULL));
//
//    HeroStat HeroGame{}; // Характеристики героя
//    short LvlDanj{ 1 }; // Уровень данжа, при старте 1, в меню обновляются // переменную нужно сохранять при сохранении игры и выгружать при загрузке
//    short SizeMobList{};
//    Monster* MobList{ nullptr };
//    Load_Mob_List(SizeMobList, MobList); // функция чтения данных по монтсрам в массив структурных данных монстров
//    //Print_Mob_List(SizeMobList, MobList); // Временная функция для проверки загрузки массива структурных данных
//    //MobList = new Monster[SizeMobList]{}; //Массив монстров загружаемый из файла при старте игры
//    //реализовать функцию считывания данных из файла со списком Монстров, первые данные в файле это SizeMobList.
//    int MenuVillage{};
//    Menu_Main(LvlDanj, HeroGame, &MenuVillage, true); // запуск главного меню. Надо вписать все входные данные
//    do
//    {
//        system("cls");
//        std::cout << "Приветсвтуем тебя герой в Нашей деревне, сдесь вы можете отдохнуть от битв. От сюда направиться в данж для его очистки от монстров.";
//        std::cout << " Продать свойю лут и приобрести экипировку у трговцев(пока не доступно).Получить задание от жителей на убийство определенных монстров (Пока не доступно)." << std::endl << std::endl;
//        std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;
//        std::cout << "\t\t\tГлавное меню - 1" << std::endl << std::endl;
//        std::cout << "\t\t\tОтправиться в данж - 2" << std::endl << std::endl;
//        std::cout << "\t\t\tПосетить магазины - 3" << std::endl << std::endl;
//        std::cout << "\t\t\tПообщаться с жителями - 4" << std::endl << std::endl;
//        std::cout << "\t\t\tПроверить свою статистику - 5" << std::endl << std::endl;
//        std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;
//        std::cout << "Сделайте свой выбор: ";
//        std::cin >> MenuVillage;
//        switch (MenuVillage)
//        {
//        case 1:
//            Menu_Main(LvlDanj, HeroGame, &MenuVillage);
//            break;
//        case 2:
//            system("cls");
//            if (HeroGame.OpenLVLDanj > 1)
//            {
//                std::cout << "У вас уже открыт уровень данжа с 1 по " << HeroGame.OpenLVLDanj << ". На какой руовень хотите спуститься? ";
//                do
//                {
//                    std::cin >> LvlDanj;
//                } while (LvlDanj > HeroGame.OpenLVLDanj);
//            }
//            Battle_Monste_Hero(LvlDanj, HeroGame, SizeMobList, MobList);
//            break;
//        case 3:
//            system("cls");
//            std::cout << "Магазин закрыт на переучет, приходите после обновления!" << std::endl;
//            Sleep(3000);
//            break;
//        case 4:
//            system("cls");
//            std::cout << "У жителей нет для вас заданий, приходите после обновления!" << std::endl;
//            Sleep(3000);
//            break;
//        case 5:
//            system("cls");
//            Print_Hero(HeroGame);
//            if (HeroGame.FreePoints > 0)
//            {
//                std::cout << "У вас есть свободные не распределенные очки = " << HeroGame.FreePoints << " Желаете их распределить? ДА(1) или НЕТ (0) ";
//                bool Ask{};
//                std::cin >> Ask;
//                if (Ask == true)
//                    Distr_Point_Hero(HeroGame);
//            }
//            Sleep(5000);
//        }
//    } while (MenuVillage != 0);
//    //delete[]MobList;
//
//    return 0;
//}
