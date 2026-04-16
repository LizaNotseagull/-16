#ifndef CHECKER_H
#define CHECKER_H

#include "BSTree.h" 
#include <string>

class Checker {
public:
    static void setupRussianLocale();

    // Безопасный ввод
    static int safeInputInt(const std::string& prompt);
    static int safeInputPositiveInt(const std::string& prompt);
    static std::string safeInputString(const std::string& prompt);

    // Генерация случайного числа
    static int generateRandomInt(int min, int max);

    // Проверяет, присутствует ли значение X в дереве (через полный обход)
    static bool containsValue(const BSTree& tree, int x);

    // Проверяет, правильно ли найден второй максимум (эталонный способ)
    static bool SecondMaxProof(const BSTree& tree, int secondMax);
};

#endif