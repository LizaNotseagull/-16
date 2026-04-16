#include "TreeWork10.h"
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

void TreeWork10() {
    BSTree tree;
    buildBinTree(tree);
    if (tree.isEmpty()) {
        std::cout << "Дерево пусто, создадим корень.\n";
        int val = Checker::safeInputInt("Введите значение для корня: ");
        tree.insert(val);
    }

    std::cout << "\n___ ДО вставки ___\n";
    tree.print(); 

    int x = Checker::safeInputInt("Введите X для вставки: ");
    tree.insert(x);

    std::cout << "\n___ ПОСЛЕ вставки ___\n";
    tree.print();

    // Проверка действительно ли значение X теперь в дереве
    if (Checker::containsValue(tree, x))
        std::cout << "Проверка: значение " << x << " успешно найдено в дереве.\n";
    else
        std::cout << "Проверка: ОШИБКА! Значение " << x << " не найдено после вставки.\n";
}