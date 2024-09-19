#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

class SelectionSort {
public:
    void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            }
            if (min_idx != i)
                std::swap(arr[min_idx], arr[i]);
        }
    }

    std::vector<int> worstCase(int n) {
        std::vector<int> worstCase(n);
        for (int i = 0; i < n; i++) {
            worstCase[i] = n - i;
        }
        return worstCase;
    }

    std::vector<int> bestCase(int n) {
        std::vector<int> bestCase(n);
        for (int i = 0; i < n; i++) {
            bestCase[i] = i + 1;
        }
        return bestCase;
    }

    std::vector<int> averageCase(int n) {
        std::vector<int> avgCase(n);
        for (int i = 0; i < n; i++) {
            avgCase[i] = rand() % 1000;
        }
        return avgCase;
    }

    template <typename F>
    double executionTime(F func, std::vector<int>& data) {
        auto start = std::chrono::high_resolution_clock::now();
        func(data);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    std::vector<double> runTests(int n) {
        std::vector<int> worstC = worstCase(n);
        std::vector<int> bestC = bestCase(n);
        std::vector<int> averageC = averageCase(n);
        double worstTime = executionTime([this](std::vector<int>& data) { selectionSort(data); }, worstC);
        double bestTime = executionTime([this](std::vector<int>& data) { selectionSort(data); }, bestC);
        double averageTime = executionTime([this](std::vector<int>& data) { selectionSort(data); }, averageC);
        return { worstTime, bestTime, averageTime };
    }
};