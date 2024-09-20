#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

class MergeSort {
public:
    void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

        double worstTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, worstC);
        double bestTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, bestC);
        double averageTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, averageC);

        return { worstTime, bestTime, averageTime };
    }

    std::vector<double> runWorstCase(int n) {
        std::vector<int> worstC = worstCase(n);
        double worstTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, worstC);
        return { worstTime };
    }

    std::vector<double> runBestCase(int n) {
        std::vector<int> bestC = bestCase(n);
        double bestTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, bestC);
        return { bestTime };
    }

    std::vector<double> runAverageCase(int n) {
        std::vector<int> averageC = averageCase(n);
        double averageTime = executionTime([this](std::vector<int>& data) { mergeSort(data, 0, data.size() - 1); }, averageC);
        return { averageTime };
    }
};
