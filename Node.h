#ifndef NODE_H
#define NODE_H

// Узел бинарного дерева
struct Node {
    int key;          // значение узла
    Node* left;       // указатель на левое поддерево
    Node* right;      // указатель на правое поддерево
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

#endif