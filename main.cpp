#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
#include "AllSortedLinkedListSearch.cpp"
#include "BSTInsert.cpp"

int main() {
    srand(static_cast<unsigned>(time(0)));
    std::vector<int> sizes = {1000, 2000, 4000, 8000};
    int randomIndex = rand() % sizes.size();
    int n = sizes[randomIndex];

    std::cout << "Tamaño de datos aleatorio: " << n << std::endl;
    std::cout << std::fixed << std::setprecision(8);

    BubbleSort bubbleSort;
    std::vector<double> bubbleTimes = bubbleSort.runTests(n);
    std::cout << "\n----- BubbleSort -----\n";
    std::cout << "Peor caso: " << bubbleTimes[0] << " s\n";
    std::cout << "Mejor caso: " << bubbleTimes[1] << " s\n";
    std::cout << "Caso promedio: " << bubbleTimes[2] << " s\n";

    SelectionSort selectionSort;
    std::vector<double> selectionTimes = selectionSort.runTests(n);
    std::cout << "\n----- SelectionSort -----\n";
    std::cout << "Peor caso: " << selectionTimes[0] << " s\n";
    std::cout << "Mejor caso: " << selectionTimes[1] << " s\n";
    std::cout << "Caso promedio: " << selectionTimes[2] << " s\n";

    MergeSort mergeSort;
    std::vector<double> mergeTimes = mergeSort.runTests(n);
    std::cout << "\n----- MergeSort -----\n";
    std::cout << "Peor caso: " << mergeTimes[0] << " s\n";
    std::cout << "Mejor caso: " << mergeTimes[1] << " s\n";
    std::cout << "Caso promedio: " << mergeTimes[2] << " s\n";

    AllSortedLinkedListSearch linkedListSearch;
    std::vector<double> linkedListTimes = linkedListSearch.runTests(n);
    std::cout << "\n----- AllSortedLinkedListSearch -----\n";
    std::cout << "Peor caso: " << linkedListTimes[0] << " s\n";
    std::cout << "Mejor caso: " << linkedListTimes[1] << " s\n";
    std::cout << "Caso promedio: " << linkedListTimes[2] << " s\n";

    BinarySearchTree bst;
    std::vector<double> bstTimes = bst.runTests(n);
    std::cout << "\n----- BinarySearchTree Insert -----\n";
    std::cout << "Peor caso: " << bstTimes[0] << " s\n";
    std::cout << "Mejor caso: " << bstTimes[1] << " s\n";
    std::cout << "Caso promedio: " << bstTimes[2] << " s\n";

    return 0;
}
