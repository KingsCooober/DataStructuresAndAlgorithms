//
// Created by tim-berners-bai on 17-4-24.
//

#ifndef SORTALGORITHMS_QUICKSORT_H
#define SORTALGORITHMS_QUICKSORT_H

#include <iostream>
#include "InsertionSort.h"

using namespace std;

// 对 arr[l...r]部分进行 partition 操作
// 返回 p, 使得 arr[l...p-1] < arr[p] && arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {

    swap(arr[rand() % (r - l + 1) + l], arr[l]);
    T v = arr[l];
//      partition_1
//    // arr[l+1...j] < v && arr[j+1...i) > v
//    int j = l;
//    for (int i = l + 1; i <= r; ++i) {
//        if (arr[i] < v) {
//            swap(arr[++j], arr[i]);
//        }
//        if (arr[i] == v) {
//
//        }
//    }
//    swap(arr[l], arr[j]);
//    return j;

    // partition_2
    // arr[l+1...i] <= v && arr[j...r] >= v;
    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) {
            i ++;
        }
        while (j >= l + 1 && arr[j] > v) {
            j --;
        }
        if (i >= j) {
            break;
        }
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    swap(arr[l], arr[j]);
    return j;
}

// 对 arr[l...r] 部分进行快速排序
template <typename T>
void __quickSort(T arr[], int l, int r) {
//    if (l >= r)
//        return;
    if  (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

// 三路快速排序处理 arr[l...r]
// 将 arr[l...r] 分为 <v; ==v; >v; 三部分
// 之后将递归对 <v and >v 两部分继续进行三路快速排序
template <typename T>
void __quickSort3Ways(T arr[], int l, int r) {

    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }
    // partition_3
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    int lt = l;         // arr[l+1...lt] < v;
    int gt = r + 1;     // arr[gt...r] > v;
    int i = l + 1;    // arr[lt+1...i) == v;
    while (i < gt) {
        if (arr[i] > v) {
            gt--;
            swap(arr[gt], arr[i]);
        }
        else if (arr[i] < v) {
            lt++;
            swap(arr[lt], arr[i]);
            i++;
        }
        else {
            i++;
        }
    }
    swap(arr[l], arr[lt]);

    __quickSort3Ways(arr, l, lt - 1);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n) {
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n - 1);
}


#endif //SORTALGORITHMS_QUICKSORT_H
