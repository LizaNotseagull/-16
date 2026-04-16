#include "BSTree.h"
#include <algorithm>

// инициализируем пустое дерево
BSTree::BSTree() : root(nullptr) {}

// освобождаем всю память
BSTree::~BSTree() {
    clearRec(root);
}

void BSTree::insertRec(Node*& node, int key) {
    if (!node) {                     // достигли пустого места
        node = new Node(key);        
        return;                      
    }
    if (key < node->key)             // Если ключ меньше текущего  идём в левое поддерево
        insertRec(node->left, key);
    else                             // (больше или равно)  идём в правое поддерево
        insertRec(node->right, key);
}

// вставка
void BSTree::insert(int key) {
    insertRec(root, key);
}

// Рекурсивное удаление узлов (пост-обход)
void BSTree::clearRec(Node*& node) {
    if (!node) return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
    node = nullptr;
}

// Построение дерева из массива (очищает предыдущее)
void BSTree::Array(const std::vector<int>& arr) {
    clearRec(root);
    for (int val : arr)
        insert(val);
}

// Рекурсивный инфиксный обход (лево-корень-право)
void BSTree::inorderRec(Node* node, std::vector<int>& result) const {
    if (!node) return;
    inorderRec(node->left, result);
    result.push_back(node->key);
    inorderRec(node->right, result);
}

// возвращает вектор ключей в инфиксном порядке
std::vector<int> BSTree::T() const {
    std::vector<int> res;
    inorderRec(root, res);
    return res;
}


// Правое поддерево (выше) обозначается "+--"
// Левое поддерево (ниже) обозначается "\--"
// Отступы — 4 пробела на уровень
void BSTree::printRec(Node* node, std::ostream& out, const std::string& prefix, bool isRight, bool isRoot) const {
    if (!node) return;

    if (isRoot) {
        // Корень выводим без символов и префикса
        out << node->key << "\n";
        // Рекурсивно вызываем для правого и левого поддеревьев
        printRec(node->right, out, "", true, false);
        printRec(node->left, out, "", false, false);
    }
    else {
        // Не корень сначала правое поддерево (выше)
        printRec(node->right, out, prefix + "    ", true, false);
        out << prefix;
        if (isRight)
            out << "+-- ";
        else
            out << "\\-- ";
        out << node->key << "\n";
        // Затем левое поддерево (ниже)
        printRec(node->left, out, prefix + "    ", false, false);
    }
}

// Публичный метод вывода
void BSTree::print(std::ostream& out) const {
    if (!root) {
        out << "Дерево пусто.\n";
        return;
    }
    printRec(root, out, "", true, true);
}

// Проверка на пустоту
bool BSTree::isEmpty() const {
    return root == nullptr;
}

// Для 18 задания
bool BSTree::getSecondMax(int& secondMax) const {
    // Если дерево пусто или состоит из одного узла — второго максимума нет
    if (!root || (!root->left && !root->right))
        return false;

    Node* curr = root;
    Node* parent = nullptr;

    // Спуск к максимальному узлу (самый правый)
    while (curr->right) {
        parent = curr;
        curr = curr->right;
    }

    // Если у максимального узла есть левое поддерево
    if (curr->left) {
        // Второй максимум — это максимум левого поддерева (самый правый в нём)
        Node* leftMax = curr->left;
        while (leftMax->right)
            leftMax = leftMax->right;
        secondMax = leftMax->key;
        return true;
    }
    // Иначе второй максимум — родитель максимального узла
    else if (parent) {
        secondMax = parent->key;
        return true;
    }
    return false;
}