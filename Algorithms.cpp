//Algorithms.cpp

#include <iostream>
#include "Algorithms.hpp"

void heapify ( int i, int n, int A [ size ] )
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if ( left < n && A [ left ] > A [ i ] )
    {
        max = left;
    }
    else
    {
        max = i;
    }
    if ( right < n && A [ right ] > A [ max ] )
    {
        max = right;
    }
    if ( max != i )
    {
        int t = A [ max ];
        A [ max ] = A [ i ];
        A [ i ] = t;
        heapify ( max, n, A );
    }
}
void heapSortFun ( int A [ size] )
{
    int n = size;
    for ( int i = n / 2 - 1; i >= 0; i -- )
    {
        heapify ( i, n, A );
    }
    for ( int i = n - 1; i >= 0; i -- )
    {
        int t = A [ 0 ];
        A [ 0 ] = A [ i ];
        A [ i ] = t;
        heapify ( 0, i, A );
    }
    std::cout << "\n\nHeapSort algorithm:" << std::endl;
    /*for ( int i = 0; i < size; i ++ )
    {
        if ( i % 20 == 0 )
        {
            std::cout << std::endl;
        }
        std::cout << A [ i ] << " ";
    }*/
}
void bubbleSortFun ( int A [ size ] )
{
    for ( int i = size; i >= 0; i -- )
    {
        for ( int j = 0; j <= i; j ++ )
        {
            if ( A [ j ] > A [ j + 1 ] )
            {
                int t = A [ j ];
                A [ j ] = A [ j + 1 ];
                A [ j + 1 ] = t;
            }
        }
    }
    std::cout << "\n\nBubbleSort algorithm:" << std::endl;
    for ( int i = 0; i < size; i ++ )
    {
        if ( i % 20 == 0 )
        {
            std::cout << std::endl;
        }
        std::cout << A [ i ] << " ";
    }
}
void insertionSortFun ( int A [ size ] )
{
    int j;
    for ( int i = 1; i <= size; i ++ )
    {
        j = i;
        while ( j > 0 && A [ j ] < A [ j - 1 ] )
        {
            int t = A [ j ];
            A [ j ] = A [ j - 1 ];
            A [ j - 1 ] = t;
            j -= 1;
        }
    }
    std::cout << "\n\nInsertionSort algorithm:" << std::endl;
    for ( int i = 0; i < size; i ++ )
    {
        if ( i % 20 == 0 )
        {
            std::cout << std::endl;
        }
        std::cout << A [ i ] << " ";
    }
}
void selectionSortFun ( int A [ size ] )
{
    int min;
    for ( int i = 0; i < size; i ++ )
    {
        min = i;
        for ( int j = i + 1; j < size; j ++ )
        {
            if ( A [ j ] < A [ min ] )
            {
                min = j;
            }
        }

        int t = A [ i ];
        A [ i ] = A [ min ];
        A [ min ] = t;
    }
    std::cout << "\n\nSelectionSort algorithm:" << std::endl;
    for ( int i = 0; i < size; i ++ )
    {
        if ( i % 20 == 0 )
        {
            std::cout << std::endl;
        }
        std::cout << A [ i ] << " ";
    }
}
void countingSortFun ()
{

}
void quickSortFun ( int A [ size ] )
{
    quickSortAlg ( A, 0, size - 1 );
    std::cout << "\n\nQuickSort algorithm:" << std::endl;
    for ( int i = 0; i < size; i ++ )
    {
        std::cout << A [ i ] << " ";
    }
}
void quickSortAlg ( int A [ size ], int l, int h )
{
    int p;
    if ( h > l )
    {
        p = partition ( A, l, h );
        quickSortAlg ( A, l, p - 1 );
        quickSortAlg ( A, p + 1, h );
    }
}
int partition ( int A [ size ], int l, int h )
{
    int p = h;
    int firstHigh = l;
    for ( int i = l; i < h; i ++ )
    {
        if ( A [ i ] < A [ p ] )
        {
            int temp = A [ i ];
            A [ i ] = A [ firstHigh ];
            A [ firstHigh ] = temp;
            firstHigh ++;
        }
    }
    int temp = A [ p ];
    A [ p ] = A [ firstHigh ];
    A [ firstHigh ] = temp;
    return firstHigh;
}
