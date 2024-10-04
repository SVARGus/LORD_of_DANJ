#include "MainMenu.h"
#include "Game.h"

MainMenu::MainMenu(Game* gameInstance) : gameRunning{ false }, game{ gameInstance } {}

void MainMenu::displayMainMenu() {
    cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;;
    cout << "\t\t\tГЛАВНОЕ МЕНЮ" << endl << endl;;
    cout << "<<<<<<<<<<----------|||||||~~~~~|||||||---------->>>>>>>>>>" << endl << endl;
    cout << "\t\t\tNEWGAME - 1" << endl << endl;
    cout << "\t\t\tLOADING - 2" << endl << endl;
    if (gameRunning == false)
    {
        cout << "\t\t\tSAVING - 3" << endl << endl;
        cout << "\t\t\tBACK - 4" << endl << endl;
    }
    cout << "\t\t\tABOUT GAME - 0" << endl << endl;
}
void MainMenu::selectMainMenu() {
    int index{};
    cin >> index;
    switch (index) // Используется с 17 стандарта
    {
    case NEWGAME:
        newGame();
        // return Village // надо проработать возврат в деревню чтоб избежать рекурсии (также возможно стоит создать деревню в самом начале в теле программы, чтоб уже передать ее в телео программы (или подумать как вызывать напрямую, но без использования паттерна Singletone
        break;
    case LOAD:
        loadGame();
        // return Village // надо проработать возврат в деревню чтоб избежать рекурсии (также возможно стоит создать деревню в самом начале в теле программы, чтоб уже передать ее в телео программы (или подумать как вызывать напрямую, но без использования паттерна Singletone
        break;
        if (gameRunning)
        {
    case SAVE:
        saveGame();
        break;
    case BACKTOGAME:
        backToGame();
        break;
        }
    case ABOUTGAME:
        aboutGame();
        break;
    case EXIT:
        exitGame();
        //cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
        break;
    default:
        cout << "Некорректный выбор ";
    }
}
void MainMenu::newGame() {
    Hero& player = Hero::getInstance();
    char Y_N{};
    do
    {
        string name{};
        cout << "Введите ваш Ник: ";
        cin >> name;
        player.setName(name);
        cout << "Ваш ник: " << player.getName() << endl;
        cout << "Подтверждаете выбор? ДА(Y) - НЕТ(N) ";
        cin >> Y_N;
    } while (Y_N == 'N' || Y_N == 'n');
    while (player.getFreepoints() > 0)
    {
        player.distrPointHero();
    }
    player.recalculateCharacteristic();
    // далее должен быть переход в класс деревня с выходом из Главного меню (надо подумать как реализовать)
    gameRunning = true; // подымаем флаг запуска игровой сессии
    game->setState(Game::VILLAGE);
}
void MainMenu::loadGame() { // позже выбрать один вариант Загрузки и Сохранения
    const string binaryDirect{ "Save_LORD_of_DANJ\\Savegame.bin" };
    const string textDirect{ "Save_LORD_of_DANJ\\Savegame.txt" };

    ifstream myFileBinary(binaryDirect, std::ios::binary);
    if (myFileBinary.is_open())
    {
        Hero& player = Hero::getInstance();
        player.loadFromBinary(myFileBinary);
        myFileBinary.close();
        cout << "Игра загружена из Бинарного файла!" << endl;
    }

    ifstream myFileText(textDirect);
    if (myFileText.is_open())
    {
        Hero& player = Hero::getInstance();
        player.loadFromText(myFileText);
        myFileText.close();
        cout << "Игра загружена из Текстового файла!" << endl;
    }
    gameRunning = true; // подымаем флаг запуска игровой сессии
    game->setState(Game::VILLAGE);
}
void MainMenu::saveGame() { // позже выбрать один вариант Загрузки и Сохранения
    //ofstream myFile;
    std::filesystem::path SaveGame = "Save_LORD_of_DANJ"; // Создаем папку для сохранения
    if (!std::filesystem::exists(SaveGame))
        std::filesystem::create_directories(SaveGame);

    const string binaryDirect{ "Save_LORD_of_DANJ\\Savegame.bin" };
    const string textDirect{ "Save_LORD_of_DANJ\\Savegame.txt" };

    ofstream myFileBinary(binaryDirect, std::ios::binary | std::ios::trunc);
    if (myFileBinary.is_open())
    {
        Hero& player = Hero::getInstance();
        player.saveToBinary(myFileBinary);
        myFileBinary.close();
        cout << "Игра сохраненена в Бинарный файл!" << endl;
    }

    ofstream myFileText(textDirect, std::ios::trunc);
    if (myFileText.is_open())
    {
        Hero& player = Hero::getInstance();
        player.saveToText(myFileText);
        myFileText.close();
        cout << "Игра сохраненена в Текстовый файл!" << endl;
    }
    game->backState();
}
void MainMenu::backToGame() {
    // также подумать как вернуться в игровую ссесию, в данном случае возврат в класс Деревня и выход из гласного меню
    game->backState();
}
void MainMenu::aboutGame() {

}
void MainMenu::exitGame() {
    cout << "\n\t\tСпасибо за игру! Будем вас ждать снова!\n\n";
    game->setState(Game::EXIT);
}