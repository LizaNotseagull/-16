#include "TreeWork8.h"
#include "BinaryTree.h"
#include "Checker.h"
#include <iostream>
#include <vector>
#include <fstream>

// ввод дерева тремя способами
static void buildTree(BinaryTree& tree) {
    std::cout << "\n___ Ввод данных тремя способами ___\n";
    std::cout << "1 - Ручной ввод последовательности (0 = нет узла)\n";
    std::cout << "2 - Случайное полное дерево\n";
    std::cout << "3 - Из файла (последовательность чисел)\n";
    int choice = Checker::safeInputInt("Выберите способ: ");

    if (choice == 1) {
        int n = Checker::safeInputPositiveInt("Сколько чисел введёте? ");
        std::vector<int> arr;
        std::cout << "Введите " << n << " целых чисел (0 = нет узла):\n";
        for (int i = 0; i < n; ++i)
            arr.push_back(Checker::safeInputInt(""));
        tree.buildFromBFS(arr);
    }
    else if (choice == 2) {
        int n = Checker::safeInputPositiveInt("Количество узлов в полном дереве: ");
        int minVal = Checker::safeInputInt("Минимальное значение ключа: ");
        int maxVal = Checker::safeInputInt("Максимальное значение ключа: ");
        std::vector<int> arr;
        for (int i = 0; i < n; ++i)
            arr.push_back(Checker::generateRandomInt(minVal, maxVal));
        tree.buildFromBFS(arr);
        std::cout << "Сгенерированы ключи: ";
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
        if (arr.empty()) {
            std::cout << "Файл пуст.\n";
            return;
        }
        tree.buildFromBFS(arr);
        std::cout << "Загружено " << arr.size() << " чисел.\n";
    }
    else {
        std::cout << "Неверный выбор.\n";
    }
}

void TreeWork8() {

    BinaryTree tree;
    buildTree(tree);
    if (tree.isEmpty()) {
        std::cout << "Дерево пусто.\n";
        return;
    }

    std::cout << "\n___ Графическое представление ДО ___\n";
    tree.print();

    std::vector<int> inorder;
    tree.infix(inorder);
    std::cout << "\nИнфиксный обход: ";
    for (int v : inorder) std::cout << v << " ";
    std::cout << "\n";

    std::cout << "\n___ Графическое представление ПОСЛЕ (без изменений) ___\n";
    tree.print();
}