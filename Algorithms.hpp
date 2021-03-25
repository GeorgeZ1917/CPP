//Algorithms.hpp
#include <array>

const int size { 10 };

void heapify ( int i, int n, int A [ size ] );
void heapSortFun ( int A [ size ] );
void bubbleSortFun ( int A [ size ] );
void insertionSortFun ( int A [ size ] );
void selectionSortFun ( int A [ size ] );
void countingSortFun ( int A [ size ] );
void quickSortFun ( int A [ size ] );
void quickSortAlg ( int A [ size ], int l, int h );
int partition ( int A [ size ], int l, int h );