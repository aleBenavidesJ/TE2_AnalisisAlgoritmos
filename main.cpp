#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <gtkmm.h>
#include "Graphics.cpp"
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "MergeSort.cpp"
#include "AllSortedLinkedListSearch.cpp"
#include "BSTInsert.cpp"

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned>(time(0)));
    std::vector<int> sizes = {5000, 10000, 20000, 30000};

   std::vector<double> bubbleWorst, bubbleBest, bubbleAvg;
    std::vector<double> selectionWorst, selectionBest, selectionAvg;
    std::vector<double> mergeWorst, mergeBest, mergeAvg;
    std::vector<double> linkedListWorst, linkedListBest, linkedListAvg;
    std::vector<double> bstWorst, bstBest, bstAvg;

    for (int n : sizes) {
        std::cout << "Tamaño de datos: " << n << std::endl;

        // Pruebas para BubbleSort
        BubbleSort bubbleSort;
        double bWorst = bubbleSort.runWorstCase(n)[0];
        double bBest = bubbleSort.runBestCase(n)[0];
        double bAvg = bubbleSort.runAverageCase(n)[0];
        bubbleWorst.push_back(bWorst);
        bubbleBest.push_back(bBest);
        bubbleAvg.push_back(bAvg);
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "BubbleSort - Peor caso: " << bWorst << "s || Mejor caso: " << bBest << "s || Promedio: " << bAvg << "s\n";

        // Pruebas para SelectionSort
        SelectionSort selectionSort;
        double sWorst = selectionSort.runWorstCase(n)[0];
        double sBest = selectionSort.runBestCase(n)[0];
        double sAvg = selectionSort.runAverageCase(n)[0];
        selectionWorst.push_back(sWorst);
        selectionBest.push_back(sBest);
        selectionAvg.push_back(sAvg);
        std::cout << "SelectionSort - Peor caso: " << sWorst << "s || Mejor caso: " << sBest << "s || Promedio: " << sAvg << "s\n";

        // Pruebas para MergeSort
        MergeSort mergeSort;
        double mWorst = mergeSort.runWorstCase(n)[0];
        double mBest = mergeSort.runBestCase(n)[0];
        double mAvg = mergeSort.runAverageCase(n)[0];
        mergeWorst.push_back(mWorst);
        mergeBest.push_back(mBest);
        mergeAvg.push_back(mAvg);
        std::cout << "MergeSort - Peor caso: " << mWorst << "s || Mejor caso: " << mBest << "s || Promedio: " << mAvg << "s\n";

        // Pruebas para LinkedListSearch
        AllSortedLinkedListSearch linkedListSearch;
        double llWorst = linkedListSearch.runWorstCase(n)[0];
        double llBest = linkedListSearch.runBestCase(n)[0];
        double llAvg = linkedListSearch.runAverageCase(n)[0];
        linkedListWorst.push_back(llWorst);
        linkedListBest.push_back(llBest);
        linkedListAvg.push_back(llAvg);
        std::cout << "LinkedListSearch - Peor caso: " << llWorst << "s || Mejor caso: " << llBest << "s || Promedio: " << llAvg << "s\n";

        // Pruebas para BST Insert
        BinarySearchTree bst;
        double bstWorstTime = bst.runWorstCase(n)[0];
        double bstBestTime = bst.runBestCase(n)[0];
        double bstAvgTime = bst.runAverageCase(n)[0];
        bstWorst.push_back(bstWorstTime);
        bstBest.push_back(bstBestTime);
        bstAvg.push_back(bstAvgTime);
        std::cout << "BST Insert - Peor caso: " << bstWorstTime << "s || Mejor caso: " << bstBestTime << "s || Promedio: " << bstAvgTime << "s\n";
    }

    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.graph_cases");
    GraphicsWindow graphicsWindow(
        bubbleWorst, bubbleBest, bubbleAvg,
        selectionWorst, selectionBest, selectionAvg,
        mergeWorst, mergeBest, mergeAvg,
        linkedListWorst, linkedListBest, linkedListAvg,
        bstWorst, bstBest, bstAvg,
        sizes
    );

    return app->run(graphicsWindow);
}
