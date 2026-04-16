#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h"
#include <vector>
#include <iostream>
#include <string> 

class BSTree {
private:
    Node* root;                     // корень дерева

    void insertRec(Node*& node, int key);           // рекурсивная вставка
    void clearRec(Node*& node);                     // рекурсивное удаление
    void inorderRec(Node* node, std::vector<int>& result) const; // рекурсивный инфиксный обход
    void printRec(Node* node, std::ostream& out, const std::string& prefix, bool isRight, bool isRoot) const; // рекурсивный вывод

public:
    BSTree();                       // конструктор
    ~BSTree();                      // деструктор

    void insert(int key);           // вставка ключа
    void Array(const std::vector<int>& arr); // построение дерева из массива
    std::vector<int> T() const;        // инфиксный обход (возвращает вектор)
    void print(std::ostream& out = std::cout) const; // графический вывод дерева
    bool isEmpty() const;    
    bool getSecondMax(int& secondMax) const; // второй максимум
};

#endif