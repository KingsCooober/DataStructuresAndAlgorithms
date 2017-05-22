//
// Created by tim-berners-bai on 17-4-17.
//

#ifndef SORTALGORITHMS_SHELLSORT_H
#define SORTALGORITHMS_SHELLSORT_H

template<typename T> //可以使用整数或浮点数作为元素，如果使用类(class)作为元素则需要重载大于(>)运算符。
void shellSort(T arr[], int len) {
    int gap, i, j;
    T temp;
    for (gap = len >> 1; gap > 0; gap >>= 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}

template <typename T>
void shellSort3(T arr[], int n) {
    int gap;
    for ( gap = n >> 1; gap > 0; gap >>= 1 ) {
        for ( int i = gap; i < n; ++i ) {
           T e = arr[i];
            int j;
            for ( j = i; j >= gap && e < arr[j - gap]; j -= gap ) {
                arr[j] = arr[j - gap];
            }
            arr[j] = e;
        }
    }
}

template<typename T>
void shellSort2(T arr[], int n){
    int h = 1;
    while( h < n/3 )
        h = 3 * h + 1;
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    while( h >= 1 ){
        // h-sort the array
        for( int i = h ; i < n ; i ++ ){

            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for( j = i ; j >= h && e < arr[j-h] ; j -= h )
                arr[j] = arr[j-h];
            arr[j] = e;
        }
        h /= 3;
    }
}


#endif //SORTALGORITHMS_SHELLSORT_H

