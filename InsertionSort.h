//
// Created by tim-berners-bai on 17-4-16.
//

#ifndef SORTALGORITHMS_INSERTIONSORT_H
#define SORTALGORITHMS_INSERTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void insertionSort1(T arr[], int n) {

    for (int i = 1; i < n; ++i) {

        // 寻找元素 arr[i] 合适的插入位置
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
            swap(arr[j], arr[j - 1]);
    }
}

template <typename T>
void insertionSort2(T arr[], int n) {

    for (int i = 1; i < n; ++i) {

        // 寻找元素 arr[i] 合适的插入位置
        T e = arr[i];
        int j;      // j 保存元素 e 应该插入的位置
        for (j = i; j > 0 && e < arr[j - 1]; --j)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}

template <typename T>
void insertionSort(T arr[], int l, int r) {
    for (int i = l + 1; i <= r; ++i) {

        T e = arr[i];
        int j;
        for (j = i; j > l && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
    return;
}

#endif //SORTALGORITHMS_INSERTIONSORT_H
