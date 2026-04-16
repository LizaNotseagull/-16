#include "Checker.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>      
#include <algorithm>   

#ifdef _WIN32
#include <windows.h>
#endif

void Checker::setupRussianLocale() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif
}

int Checker::safeInputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(10000, '\n');
            return value;
        }
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Ошибка! Введите целое число.\n";
        }
    }
}

int Checker::safeInputPositiveInt(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        bool ok = !line.empty();
        for (char c : line) {
            if (!std::isdigit(static_cast<unsigned char>(c))) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int value = std::stoi(line);
            if (value > 0) return value;
            else std::cout << "Ошибка! Число должно быть положительным.\n";
        }
        else {
            std::cout << "Ошибка! Введите целое положительное число.\n";
        }
    }
}

std::string Checker::safeInputString(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

int Checker::generateRandomInt(int min, int max) {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(nullptr)));
        seeded = true;
    }
    return min + rand() % (max - min + 1);
}


// Проверка наличия значения X в дереве
bool Checker::containsValue(const BSTree& tree, int x) {
    std::vector<int> vec = tree.T();          // получаем все ключи дерева
    return std::find(vec.begin(), vec.end(), x) != vec.end();      // ищем x в векторе если найден, возвращаем true
}

// Проверка правильности второго максимума
bool Checker::SecondMaxProof(const BSTree& tree, int secondMax) {
    std::vector<int> vec = tree.T();         // получаем все ключи дерева
    if (vec.size() < 2) return false;      // если в дереве меньше двух узлов, второго максимума нет
    int trueSecondMax = vec[vec.size() - 2];     // предпоследний элемент в отсортированном векторе – это второй максимум
    return trueSecondMax == secondMax;         // сравниваем с переданным значением
}