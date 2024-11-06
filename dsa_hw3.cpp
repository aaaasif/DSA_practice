#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class my_Tree {
public:
    Node* root;
    my_Tree() : root(nullptr) {}

    Node* buildFullTree(const std::vector<int>& sortedElements, Node* node, int i, int n) {
        if (i < n) {
            Node* temp = new Node(sortedElements[i]);
            node = temp;
            node->left = buildFullTree(sortedElements, node->left, 2 * i + 1, n);
            node->right = buildFullTree(sortedElements, node->right, 2 * i + 2, n);
        }
        return node;
    }

    void inOrderTraversal(Node* node) const {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
};

class my_SortedTree {
public:
    std::vector<int> numbers;
    std::vector<int> sortedNumbers;
    my_Tree tree;

    my_SortedTree(const std::vector<int>& nums) : numbers(nums) {}

    void sortNumbers() {
        sortedNumbers = numbers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());
    }

    void buildTree() {
        int n = sortedNumbers.size();
        tree.root = tree.buildFullTree(sortedNumbers, tree.root, 0, n);
    }

    void printInOrder() const {
        std::cout << "In-order traverse (increasing order): ";
        tree.inOrderTraversal(tree.root);
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> values = {14, 23, 13, 18, 11, 26, 16};
    my_SortedTree sortedTree(values);

    std::cout << "After sorting them, you will get:" << std::endl;
    sortedTree.sortNumbers();
    for (int num : sortedTree.sortedNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sortedTree.buildTree();

    std::string response;
    std::cout << "Do you want to print them? ";
    std::cin >> response;
    if (response == "YES" || response == "yes") {
        sortedTree.printInOrder();
    }

    return 0;
}