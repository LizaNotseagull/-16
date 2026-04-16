#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <vector>
#include <iostream>
#include <string> 

class BinaryTree {
private:
    Node* root;                         // корень дерева

    void clearRec(Node*& node);         // рекурсивное удаление
    void infixRun(Node* node, std::vector<int>& result) const; // инфиксный обход
    void printRec(Node* node, std::ostream& out, const std::string& prefix, bool isRight) const; // вывод

public:
    BinaryTree();                       // конструктор
    ~BinaryTree();                      // деструктор

    void clear();                       // очистка дерева
    void buildFromBFS(const std::vector<int>& values); // построение дерева
    void infix(std::vector<int>& result) const; // инфиксный обход
    void print(std::ostream& out = std::cout) const; // графический вывод
    bool isEmpty() const;               // проверка на пустоту
};

#endif