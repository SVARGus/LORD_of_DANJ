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
    // 6 базовых характеристик, на 1 лвл в сумме 16 и у каждого монстра по разному распределены. При повышении лвл будет добавлятся минимум в 2 раза больше чем при повышении лв героя
    int PowerMonster;
    int DexterityMonster; // Ловкость
    int EnduranceMonster; // Выносливость
    int IntelligenceMonster; // Интилект
    int WisdomMonster; // Мудрость
    int CharizmaMonster; // Харизма
    
    // Характеристики которые расчитываются на основе 5 базовых статов (Сила, Ловкость...)
    int MinDamage; // Влияет Сила
    int MaxDamage; // Влияет Сила
    double Parrying; // Уклонение от атаки, уменьшает получаемый урон (влияет Ловкость и Мудрость)
    double Initiative; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма). Может увеличивать урон при бое, имеет накопительный эффект в бою, Максимально за бой может быть 3-х кратное увеличение урона (активируется)
    int HealthMonster;

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
    double Initiative; // Инициатива, влияет на возможность повторного удара (влияет Интелект, Мудрость и Харизма). Может увеличивать урон при бое, имеет накопительный эффект в бою, Максимально за бой может быть 3-х кратное увеличение урона (активируется)
    int HealthHero; // Количество жизней. (Можноли сразу в структуре прописать формулу расчета данного показателя или лучше в отдельной функции реализовать? (влияет Сила, Выносливость и уровень)
    int ScalExp; // Шкала опыта
    int ScalExpUp; // Сколько нужно уопыта набрать для нового уровня героя
    // Позже можно добавить другие характеристики или выделить их в отдельную структуру доп характеристик
};

/*      Перечень прототипов функций     */

void Print_Hero(HeroStat HeroGame);
void Menu_Main(short& LvlDanj, HeroStat& HeroGame, bool Start = false);
HeroStat Recalculate_Hero(HeroStat HeroGame);
HeroStat Distr_Point_Hero(HeroStat HeroGame);
HeroStat New_Game();
void Save_Game(const short LvlDanj, const HeroStat HeroGame); // Дописать вводные данные
void Load_Game(short& LvlDanj, HeroStat& HeroGame);
void Load_Mob_List(short& SizeMobList, Monster*& MobList);


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
    std::cout << "Инициатива: " << HeroGame.Initiative << std::endl;
    std::cout << "Количество здоровья: " << HeroGame.HealthHero << std::endl;
    std::cout << "Шкала текуцщего опыта: " << HeroGame.ScalExp << std::endl;
    std::cout << "Сколько опыта для перехода на новый уровень: " << HeroGame.ScalExpUp << std::endl;
}

void Menu_Main(short& LvlDanj, HeroStat& HeroGame, bool Start) // прописывать в функцию принимаемы данные или нет? или заменить тип на int с возможным выбором // Start = true если меню загружается пир старте программы
{
    enum MENU { NEWGAME = 1, LOAD, SAVE, BACK, EXIT = 0 }; // Очень удобно использовать в меню, VS сам подставляет варианты меню согласно списку енама
    int Menu{};
    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;;
    std::cout << "\t\t\tГЛАВНОЕ МЕНЮ" << std::endl << std::endl;;
    std::cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << std::endl << std::endl;
    std::cout << "\t\t\tNEWGAME - 1" << std::endl << std::endl;
    std::cout << "\t\t\tLOADING - 2" << std::endl << std::endl;
    if (Start == false)
    {
        std::cout << "\t\t\tSAVING - 3" << std::endl << std::endl;
        std::cout << "\t\t\tBACK - 4" << std::endl << std::endl;
    }
    std::cout << "\t\t\tEXIT - 0" << std::endl << std::endl;
    std::cin >> Menu;
    do
    {
        switch (Menu)
        {
        case NEWGAME: // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
            HeroGame = New_Game();
            return;
            break;
        case LOAD:
            Load_Game(LvlDanj, HeroGame); // реализовать функцию загрузки данных ранее сохраненных посредством выбора из ранее сохраненных (если таковых нету, то так и прописать что сохранения отсуствуют)
            return;
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
            return;
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
    HeroGame.Initiative = 0.03 * HeroGame.IntelligenceHero + 0.02 * HeroGame.WisdomHero + 0.01 * HeroGame.CharizmaHero;
    HeroGame.HealthHero = (10 * HeroGame.LvlHero) * (0.8 * HeroGame.PowerHero + 0.4 * HeroGame.EnduranceHero);
    HeroGame.ScalExpUp = 100;
    for (int i = 0; i < HeroGame.LvlHero; i++)
    {
        HeroGame.ScalExpUp *= 1.5 * i;
    }
    return HeroGame;
}

HeroStat Distr_Point_Hero(HeroStat HeroGame) // Функция распределения свободных очков при старте новой игры и при повышении уровня героя (ЗАКОНЧИЛ / ПРОВЕРЕНО)
{
    enum CHARACTER { POWER = 1, DEXTERITY, ENDURANCE, INTELLIGENCE, WISDOM, CHARIZMA };
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
        default:
            HeroGame.FreePoints += Points;
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
    } while (Y_N == 'N' || Y_N == 'n');
    HeroGame = Distr_Point_Hero(HeroGame); // Переход в распределение характеристик
    HeroGame = Recalculate_Hero(HeroGame); // Функция перерасчета характеристик с учетом распределенных статов

    return HeroGame;
}

void Save_Game(const short LvlDanj, const HeroStat HeroGame) // Функция сохранения игры (дописать вводные данные)
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
        fprintf(Savegame, "%f ", HeroGame.Initiative);
        fprintf(Savegame, "%d ", HeroGame.HealthHero);
        fprintf(Savegame, "%d ", HeroGame.ScalExp);
        fprintf(Savegame, "%d ", HeroGame.ScalExpUp);
    }
    else
        std::cout << "Ошибка создания сохранения!" << std::endl;
    if (fclose(Savegame) == EOF)
        std::cout << "Ошибка при сохранение!" << std::endl;
    else
        std::cout << "УСПЕШНОЕ СОХРАНЕНИЕ" << std::endl;
}

void Load_Game(short& LvlDanj, HeroStat& HeroGame) // (ЗАКОНЧИЛ / ПРОВЕРЕНО)
{
    FILE* Loadgame;
    const char* direct = "Save_LORD_of_DANJ\\Savegame.txt";
    if ((fopen_s(&Loadgame, direct, "r")) == NULL)
    {
        fscanf_s(Loadgame, "%d ", &LvlDanj);
        fscanf_s(Loadgame, "\n");
        fscanf_s(Loadgame, "%s ", &HeroGame.NameHero, sizeof(HeroGame.NameHero));
        fscanf_s(Loadgame, "%d ", &HeroGame.LvlHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.PowerHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.DexterityHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.EnduranceHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.IntelligenceHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.WisdomHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.CharizmaHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.FreePoints);
        fscanf_s(Loadgame, "%d ", &HeroGame.MinDamage);
        fscanf_s(Loadgame, "%d ", &HeroGame.MaxDamage);
        fscanf_s(Loadgame, "%lf ", &HeroGame.Parrying);
        fscanf_s(Loadgame, "%lf ", &HeroGame.Initiative);
        fscanf_s(Loadgame, "%d ", &HeroGame.HealthHero);
        fscanf_s(Loadgame, "%d ", &HeroGame.ScalExp);
        fscanf_s(Loadgame, "%d ", &HeroGame.ScalExpUp);
    }
    else
        std::cout << "Ошибка загрузки" << std::endl;
    if (fclose(Loadgame) == EOF)
        std::cout << "Ошибка при Загрузке!" << std::endl;
    else
        std::cout << "ИГРА УСПЕШНО ЗАГРУЖЕНА" << std::endl;
}

void Load_Mob_List(short& SizeMobList, Monster*& MobList) // (ЗАКОНЧИЛ / ПРОВЕРЕНО) Осталось только базу п\монстров подкорректировать
{
    FILE* LoadMobList;
    const char* direct = "MobList.txt"; // файл пока не создан
    if ((fopen_s(&LoadMobList, direct, "r")) != NULL)
        std::cout << "Ошибка загрузки базы Монстров или файл " << direct << " отсуствует!" << std::endl;
    else
    {
        fscanf_s(LoadMobList, "%d ", &SizeMobList);
        fscanf_s(LoadMobList, "\n");
        MobList = new Monster[SizeMobList]{};
        for (int i = 0; i < SizeMobList; i++)
        {
            fscanf_s(LoadMobList, "%s ", MobList[i].NameMonster, sizeof(MobList[i].NameMonster));
            fscanf_s(LoadMobList, "%hd ", &MobList[i].LvlMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].PowerMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].DexterityMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].EnduranceMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].IntelligenceMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].WisdomMonster);
            fscanf_s(LoadMobList, "%d ", &MobList[i].CharizmaMonster);
        }
    }
    if (fclose(LoadMobList) == EOF)
        std::cout << "Ошибка закрытия файла с данными монстров" << std::endl;
    else
        std::cout << "База Монстров успешно загружена!!!" << std::endl;
}

// Ниже функции на этапе написания, в прототипы еще не добавлены!!!

void Print_Mob_List(short SizeMobList, Monster* MobList) // Функция вывода данных по монстрам - временно для проверки
{
    std::cout << SizeMobList << std::endl;
    for (int i = 0; i < SizeMobList; i++)
    {
        std::cout << MobList[i].NameMonster << " " << MobList[i].LvlMonster << " " << MobList[i].PowerMonster << " " << MobList[i].DexterityMonster << " " << MobList[i].EnduranceMonster << " " << MobList[i].IntelligenceMonster << " " << MobList[i].WisdomMonster << " " << MobList[i].CharizmaMonster << std::endl;
    }
}

Monster Recalculate_Mob(Monster* Moblist, int LvlDanj, int Index) // Функция расчета статов монстра, запускается перед боем после рандомного выбора монстра
{
    return *Moblist;
}

int Damage_Battle(int MinDamage, int MaxDamage, double Initiative) // Функция расчета урона с учетом инициативы
{
    int Damage = rand() % (MaxDamage - MinDamage) + MinDamage;
    return (Damage + Damage * Initiative);
}

bool Parrying_Battle(double Parrying, int Lvl) // Функция просчитывания шанса уклониться от удара
{
    if (rand() % 30/10 <= Parrying / Lvl)
        return true;
    return false;
}

void Battle_Monste_Hero(short& LvlDanj, HeroStat& HeroGame, const short SizeMobList, Monster* Moblist) // Функция битвы. Надо добавить и проработать счетчик побед для перехода на другой уровень Данжа
{
    {
        int Index = rand() % SizeMobList; // Рандобный выбор Монстра с которым будет битва
        Recalculate_Mob(Moblist, LvlDanj, Index); // Генерирует статы монстра исходя из уровня данжа
        int HealthHero = HeroGame.HealthHero; // Характеристика показывающая количество жизней героя в течение боя
        std::cout << "Пробираясь по Подземелью " << LvlDanj << " уровня, вы повстречали монстра " << Moblist[Index].NameMonster << ".\nПриготовьтесь к битве!!!" << std::endl;
        for (int i = 0; HealthHero > 0 && Moblist[Index].HealthMonster > 0; i++)
        {
            if (HeroGame.Initiative >= Moblist[Index].Initiative && i == 0)
            {
                if (Parrying_Battle(Moblist[Index].Parrying, LvlDanj) == false)
                {
                    std::cout << "Вы имеет преимущество и атакуете первым и наносите " << Moblist[Index].NameMonster;
                    std::cout << " увеличенный урон равный - " << Damage_Battle(HeroGame.MinDamage, HeroGame.MaxDamage, HeroGame.Initiative) << std::endl;
                    // сдесь расчет оставшейся жизни героя, надо еще продумать как выводить текущие уровни жизней участников боя, после каждого удара или после каждого раунда?
                }
                else
                {
                    std::cout << "Имея преимущество в скрытности, вы подкрадываетесь и атакуете " << Moblist[Index].NameMonster;
                    std::cout << ", но Он в последний момент замечает вашу атаку и уворачивается" << std::endl;
                }
            }
            if (Parrying_Battle(HeroGame.Parrying, HeroGame.LvlHero) == false)
            {
                std::cout << Moblist[Index].NameMonster << " наносит вам урон - " << Damage_Battle(Moblist[Index].MinDamage, Moblist[Index].MaxDamage, Moblist[Index].Initiative) << std::endl;
                // сдесь расчет оставшейся жизни героя, надо еще продумать как выводить текущие уровни жизней участников боя, после каждого удара или после каждого раунда?
            }
            else
            {
                std::cout << "Вам удается увернуться от удара " << Moblist[Index].NameMonster << std::endl;
            }
            //Дописать удар героя и после выписать статистику раунда взаимных ударов при условии что у обоих остались жизни!!!
        }
        //Записать резултаты проигрыша или победы.
        //По результатам победы насчитать опыт исходя из уровня данжа.
        //Сбросить счетчик побед до 0 (5, 10, 15 это несгораемые поеды и переход на новый уровень зависит от количества побед - например с 1 на 2 требуется 5 побед, с 2 по 3 уже 15 побед и т.д.)
        //Также прописать условие если ЛВЛ героя повышен и пересчитать статы

        /* Также здесь прописать системную паузу, также и в каждом раунде*/
    }
}

/*      Основное тело программы     */
int main() // Вписать мейн с принимающими данными
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    HeroStat HeroGame{}; // Характеристики героя
    short LvlDanj{ 1 }; // Уровень данжа, при старте 1, в меню обновляются // переменную нужно сохранять при сохранении игры и выгружать при загрузке
    short SizeMobList{};
    Monster* MobList{ nullptr };
    Load_Mob_List(SizeMobList, MobList); // функция чтения данных по монтсрам в массив структурных данных монстров
    //Print_Mob_List(SizeMobList, MobList); // Временная функция для проверки загрузки массива структурных данных
    //MobList = new Monster[SizeMobList]{}; //Массив монстров загружаемый из файла при старте игры
    //реализовать функцию считывания данных из файла со списком Монстров, первые данные в файле это SizeMobList.
    Menu_Main(LvlDanj, HeroGame, true); // запуск главного меню. Надо вписать все входные данные


    Print_Hero(HeroGame); // Временный вывод для проверки
    Menu_Main(LvlDanj, HeroGame);

    return 0;
}