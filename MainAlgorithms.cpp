//MainAlgorithms.cpp

#include <iostream>
#include <random>
#include "Algorithms.hpp"

int main ()
{
    std::random_device rd;
    std::mt19937 rng ( rd () );
    std::uniform_int_distribution<int> uni ( 0, size );
    int * heapSort = new int [ size ];
    int * bubbleSort = new int [ size ];
    int * insertionSort = new int [ size ];
    int * selectionSort = new int [ size ];
    int * quickSort = new int [ size ];
    for ( int i = 0; i < size; i ++ )
    {
        heapSort [ i ] = uni ( rng );
    }
    bubbleSort = heapSort;
    insertionSort = heapSort;
    selectionSort = heapSort;
    quickSort = heapSort;
    //heapSortFun ( heapSort );
    //bubbleSortFun ( bubbleSort );
    selectionSortFun ( selectionSort );
    //quickSortFun ( quickSort );
    return 0;
}