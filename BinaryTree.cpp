#include "BinaryTree.h"
#include <string>

// Конструктор
BinaryTree::BinaryTree() : root(nullptr) {}

// Деструктор
BinaryTree::~BinaryTree() {
    clearRec(root);
}

// Рекурсивное удаление
void BinaryTree::clearRec(Node*& node) {
    if (!node) return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
    node = nullptr;
}

// Очистка дерева 
void BinaryTree::clear() {
    clearRec(root);
}

// Построение дерева (0 = нет узла)
void BinaryTree::buildFromBFS(const std::vector<int>& values) {
    clear();
    if (values.empty() || values[0] == 0) return;
    root = new Node(values[0]);
    std::vector<Node*> nodes(1, root);
    size_t parentIndex = 0;
    size_t i = 1;
    while (parentIndex < nodes.size() && i < values.size()) {
        Node* curr = nodes[parentIndex];
        // левый потомок
        if (i < values.size() && values[i] != 0) {
            curr->left = new Node(values[i]);
            nodes.push_back(curr->left);
        }
        i++;
        // правый потомок
        if (i < values.size() && values[i] != 0) {
            curr->right = new Node(values[i]);
            nodes.push_back(curr->right);
        }
        i++;
        parentIndex++;
    }
}

// Рекурсивный инфиксный обход
void BinaryTree::infixRun(Node* node, std::vector<int>& result) const {
    if (!node) return;
    infixRun(node->left, result);
    result.push_back(node->key);
    infixRun(node->right, result);
}

//инфиксный обход
void BinaryTree::infix(std::vector<int>& result) const {
    result.clear();
    infixRun(root, result);
}

// Рекурсивный вывод с отступами
void BinaryTree::printRec(Node* node, std::ostream& out, const std::string& prefix, bool isRight) const {
    if (!node) return;
    // Сначала правое поддерево (выше)
    printRec(node->right, out, prefix + "    ", true);
    out << prefix;
    if (isRight)
        out << "+-- ";
    else
        out << "\\-- ";
    out << node->key << "\n";
    // Затем левое поддерево (ниже)
    printRec(node->left, out, prefix + "    ", false);
}

// Графический вывод
void BinaryTree::print(std::ostream& out) const {
    if (!root) {
        out << "Дерево пусто.\n";
        return;
    }
    out << root->key << "\n";
    printRec(root->right, out, "", true);
    printRec(root->left, out, "", false);
}

// Проверка на пустоту
bool BinaryTree::isEmpty() const {
    return root == nullptr;
}