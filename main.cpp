#include "SelectionSort.h"
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "MaxHeap.h"
#include "HeapSort.h"

int main() {
    int n = 100000;
    int swapTimes = 100;
    cout << "Test for Generate Random Array, size = " << n << ", random range [0, "<<n<<"]"<< endl;
    int* arr0 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr1 = SortTestHelper::copyIntArray(arr0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr0, n);
    int* arr3 = SortTestHelper::copyIntArray(arr0, n);
    int* arr4 = SortTestHelper::copyIntArray(arr0, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr0, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr1, n);
    SortTestHelper::testSort("Quick Sort Three Ways", quickSort3Ways, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);

    cout << endl;

    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap times = " << swapTimes << endl;
    int* arr5 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    int* arr6 = SortTestHelper::copyIntArray(arr5, n);
    int* arr7 = SortTestHelper::copyIntArray(arr5, n);
    int* arr8 = SortTestHelper::copyIntArray(arr5, n);
    int* arr9 = SortTestHelper::copyIntArray(arr5, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr6, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr5, n);
    SortTestHelper::testSort("Quick Sort Three Ways", quickSort3Ways, arr7, n);

    cout << endl;

    cout << "Test for Random Array, size = " << n << ", random range [0,10]" << endl;
    int* arr10 = SortTestHelper::generateRandomArray(n, 0, 10);
    int* arr11 = SortTestHelper::copyIntArray(arr10, n);
    int* arr12 = SortTestHelper::copyIntArray(arr10, n);
    int* arr13 = SortTestHelper::copyIntArray(arr10, n);
    int* arr14 = SortTestHelper::copyIntArray(arr10, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr10, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr12, n);
    SortTestHelper::testSort("Quick Sort Three Ways", quickSort3Ways, arr13, n);


    cout << endl << endl;


    delete[] arr0;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;
    delete[] arr11;
    delete[] arr12;
    delete[] arr13;
    delete[] arr14;

    return 0;
}