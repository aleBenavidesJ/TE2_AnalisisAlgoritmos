#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class BubbleSort {
public:
    void bubbleSort(std::vector<int>& arr) {
        bool swapped;
        for (size_t i = 0; i < arr.size(); i++) {
            swapped = false;
            for (size_t j = 0; j < arr.size() - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
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
    double  executionTime(F func, std::vector<int>& data) {
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
        double worstTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, worstC);
        double bestTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, bestC);
        double averageTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, averageC);
        return { worstTime, bestTime, averageTime };
    }

    std::vector<double> runWorstCase(int n) {
        std::vector<int> worstC = worstCase(n);
        double worstTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, worstC);
        return {worstTime};
    }

    std::vector<double> runBestCase(int n) {
        std::vector<int> bestC = bestCase(n);
        double bestTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, bestC);
        return {bestTime};
    }

    std::vector<double> runAverageCase(int n) {
        std::vector<int> averageC = averageCase(n);
        double averageTime = executionTime([this](std::vector<int>& data) { bubbleSort(data); }, averageC);
        return {averageTime};
    }
};
