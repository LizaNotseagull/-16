#include "TreeWork8.h"
#include "TreeWork10.h"
#include "TreeWork18.h"
#include "Checker.h"
#include <iostream>

int main() {
    Checker::setupRussianLocale();
#ifdef _WIN32
    system("chcp 1251 > nul");
#endif

    int choice;
    do {
        std::cout << "\n ГЛАВНОЕ МЕНЮ \n";
        std::cout << "1 - TreeWork8 (Инфиксный обход)\n";
        std::cout << "2 - TreeWork10 (Вставка элемента)\n";
        std::cout << "3 - TreeWork18 (Второй максимум)\n";
        std::cout << "0 - Выход\n";
        choice = Checker::safeInputInt("Ваш выбор: ");

        switch (choice) {
        case 1: TreeWork8(); break;
        case 2: TreeWork10(); break;
        case 3: TreeWork18(); break;
        case 0: std::cout << "Программа завершена.\n"; break;
        default: std::cout << "Неверный выбор.\n";
        }
    } while (choice != 0);

    return 0;
}