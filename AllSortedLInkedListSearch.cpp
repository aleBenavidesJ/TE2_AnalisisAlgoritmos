#include <iostream>
#include <vector>
#include <chrono>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class AllSortedLinkedListSearch {
public:
    Node* head;
    AllSortedLinkedListSearch() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= value) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    std::vector<int> worstCase(int n) {
        std::vector<int> worstCase(n);
        for (int i = 0; i < n; ++i) {
            worstCase[i] = i + 1;
        }
        return worstCase;
    }

    std::vector<int> bestCase(int n) {
        return {1};
    }

    std::vector<int> averageCase(int n) {
        std::vector<int> avgCase(n);
        for (int i = 0; i < n; ++i) {
            avgCase[i] = rand() % 1000;
        }
        return avgCase;
    }

    template <typename F>
    double executionTime(F func, std::vector<int>& data, int searchValue) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int value : data) {
            insert(value);
        }
        func(searchValue);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    std::vector<double> runTests(int n) {
        std::vector<int> worstC = worstCase(n);
        std::vector<int> bestC = bestCase(n);
        std::vector<int> averageC = averageCase(n);
        double worstTime = executionTime([this](int val) { search(val); }, worstC, n);
        double bestTime = executionTime([this](int val) { search(val); }, bestC, 1);
        double averageTime = executionTime([this](int val) { search(val); }, averageC, rand() % 1000);
        return {worstTime, bestTime, averageTime};
    }

    std::vector<double> runWorstCase(int n) {
        std::vector<int> worstC = worstCase(n);
        AllSortedLinkedListSearch list;
        double worstTime = executionTime([&list](int val) { list.search(val); }, worstC, n);
        return {worstTime};
    }

    std::vector<double> runBestCase(int n) {
        std::vector<int> bestC = bestCase(n);
        AllSortedLinkedListSearch list;
        double bestTime = executionTime([&list](int val) { list.search(val); }, bestC, 1);
        return {bestTime};
    }

    std::vector<double> runAverageCase(int n) {
        std::vector<int> averageC = averageCase(n);
        AllSortedLinkedListSearch list;
        double averageTime = executionTime([&list](int val) { list.search(val); }, averageC, rand() % 1000);
        return {averageTime};
    }
};
