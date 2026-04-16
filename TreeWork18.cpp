#include "TreeWork18.h"
#include "BSTree.h"
#include "Checker.h"
#include <iostream>
#include <vector>
#include <fstream>

static void buildBinTree(BSTree& tree) {
    std::cout << "\n___ Ввод данных тремя способами ___\n";
    std::cout << "1 - Ручной ввод\n2 - Случайные числа\n3 - Из файла\n";
    int choice = Checker::safeInputInt("Выберите способ: ");
    if (choice == 1) {
        int n = Checker::safeInputPositiveInt("Количество элементов: ");
        std::vector<int> arr;
        std::cout << "Введите " << n << " целых чисел:\n";
        for (int i = 0; i < n; ++i)
            arr.push_back(Checker::safeInputInt(""));
        tree.Array(arr);
    }
    else if (choice == 2) {
        int n = Checker::safeInputPositiveInt("Количество элементов: ");
        int minVal = Checker::safeInputInt("Минимальное значение: ");
        int maxVal = Checker::safeInputInt("Максимальное значение: ");
        std::vector<int> arr;
        for (int i = 0; i < n; ++i)
            arr.push_back(Checker::generateRandomInt(minVal, maxVal));
        tree.Array(arr);
        std::cout << "Сгенерированы числа: ";
        for (int v : arr) std::cout << v << " ";
        std::cout << "\n";
    }
    else if (choice == 3) {
        std::string fname = Checker::safeInputString("Имя файла: ");
        std::ifstream fin(fname);
        if (!fin) {
            std::cout << "Не удалось открыть файл.\n";
            return;
        }
        std::vector<int> arr;
        int val;
        while (fin >> val) arr.push_back(val);
        fin.close();
        if (arr.empty()) return;
        tree.Array(arr);
        std::cout << "Загружено " << arr.size() << " чисел.\n";
    }
}

void TreeWork18() {
    BSTree tree;
    buildBinTree(tree);
    if (tree.isEmpty()) {
        std::cout << "Дерево пусто.\n";
        return;
    }

    std::cout << "\n___ Графическое представление ___\n";
    tree.print(); 

    int secondMax;
    if (tree.getSecondMax(secondMax)) {
        std::cout << "\nВторое максимальное значение: " << secondMax << "\n";
        // Проверка правильно ли найден второй максимум
        if (Checker::SecondMaxProof(tree, secondMax))
            std::cout << "Проверка: значение второго максимума подтверждено.\n";
        else
            std::cout << "Проверка: ОШИБКА! Неверный второй максимум.\n";
    }
    else {
        std::cout << "\nВ дереве менее двух узлов, второго максимума нет.\n";
    }

    std::cout << "\n___ Графическое представление (без изменений) ___\n";
    tree.print();
}