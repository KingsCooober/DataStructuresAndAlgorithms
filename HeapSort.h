//
// Created by tim-berners-bai on 17-4-28.
//

#ifndef SORTALGORITHMS_HEAPSORT_H
#define SORTALGORITHMS_HEAPSORT_H

#include <iostream>

using namespace std;

template <typename T>
void __shiftDown(T arr[], int n, int k) {
    while (2 * k + 1 <= n) {
        int j = 2 * k + 1;
        if (j + 1 <= n && arr[j + 1] > arr[j])
            j++;

        if (arr[k] >= arr[j])
            break;

        swap(arr[k], arr[j]);
        k = j;
    }
}

template <typename T>
void heapSort(T arr[], int n) {
    // heapify
    for (int i = (n - 1) / 2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}


#endif //SORTALGORITHMS_HEAPSORT_H
