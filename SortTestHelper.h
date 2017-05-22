//
// Created by tim-berners-bai on 17-4-16.
//

#ifndef SORTALGORITHMS_SORTTESTHELPER_H
#define SORTALGORITHMS_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    // 生成有 n 个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);

        int* arr = new int[n];
        srand(time(NULL));

        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }

        return arr;
    }

    int* generateNearlyOrderArray(int n, int swapTimes) {

        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int j = 0; j < swapTimes; ++j) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    template <typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(isSorted(arr, n));

        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

        return;
    }

    int* copyIntArray(int a[], int n) {
        int* arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }


};


#endif //SORTALGORITHMS_SORTTESTHELPER_H
