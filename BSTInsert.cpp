#include <iostream>
#include <chrono>
#include <vector>

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BSTNode* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    BSTNode* insertRec(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    std::vector<int> worstCase(int n) {
        std::vector<int> worstCase(n);
        for (int i = 0; i < n; ++i) {
            worstCase[i] = i + 1;
        }
        return worstCase;
    }

    std::vector<int> bestCase(int n) {
        std::vector<int> bestCase;
        balancedBST(bestCase, 1, n);
        return bestCase;
    }

    void balancedBST(std::vector<int>& arr, int start, int end) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        arr.push_back(mid);
        balancedBST(arr, start, mid - 1);
        balancedBST(arr, mid + 1, end);
    }

    std::vector<int> averageCase(int n) {
        std::vector<int> avgCase(n);
        for (int i = 0; i < n; ++i) {
            avgCase[i] = rand() % 1000;
        }
        return avgCase;
    }

    template <typename F>
    double executionTime(F func, std::vector<int>& data) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int value : data) {
            func(value);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    std::vector<double> runTests(int n) {
        std::vector<int> worstC = worstCase(n);
        std::vector<int> bestC = bestCase(n);
        std::vector<int> averageC = averageCase(n);
        double worstTime = executionTime([this](int val) { insert(val); }, worstC);
        double bestTime = executionTime([this](int val) { insert(val); }, bestC);
        double averageTime = executionTime([this](int val) { insert(val); }, averageC);
        return {worstTime, bestTime, averageTime};
    }

    std::vector<double> runWorstCase(int n) {
        std::vector<int> worstC = worstCase(n);
        BinarySearchTree bst;
        double worstTime = executionTime([&bst](int val) { bst.insert(val); }, worstC);
        return {worstTime};
    }

    std::vector<double> runBestCase(int n) {
        std::vector<int> bestC = bestCase(n);
        BinarySearchTree bst;
        double bestTime = executionTime([&bst](int val) { bst.insert(val); }, bestC);
        return {bestTime};
    }

    std::vector<double> runAverageCase(int n) {
        std::vector<int> averageC = averageCase(n);
        BinarySearchTree bst;
        double averageTime = executionTime([&bst](int val) { bst.insert(val); }, averageC);
        return {averageTime};
    }
};
