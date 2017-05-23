//
// Created by tim-berners-bai on 17-5-23.
//

#ifndef INDEXHEAP_INDEXHEAP_H
#define INDEXHEAP_INDEXHEAP_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class IndexHeap {

private:
    T* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[indexes[k/2]] < data[indexes[k]]) {
            swap(indexes[k/2], indexes[k]);
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[indexes[j]] < data[indexes[j + 1]])
                j += 1;
            if (data[indexes[k]] >= data[indexes[j]])
                break;
            swap(indexes[j], indexes[k]);
            reverse[indexes[j]] = j;
            reverse[indexes[k]] = k;
            k = j;
        }
    }

public:
    IndexHeap(int capacity) {
        this->capacity = capacity;
        data = new T[capacity + 1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];
        for (int i = 1; i <= capacity; ++i) {
            reverse[i] = 0;
        }
        count = 0;
    }

    ~IndexHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(int i, T e) {
        assert(count + 1 <= capacity);
        assert(i + 1 >= 1 && i + 1 <= capacity);
        i += 1;
        data[i] = e;
        indexes[count + 1] = i;
        reverse[i] = count + 1;
        count++;
        shiftUp(count);
    }

    T extractMax() {
        assert(count > 0);
        T ret = data[indexes[1]];
        swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);

        return ret;
    }

    int extractMaxIndex() {
        assert(count > 0);
        int ret = indexes[1];
        swap(indexes[1], indexes[count]);
        count--;
        shiftDown(1);

        return ret;
    }

    bool contain(int i) {
        assert(i + 1 >= 1 && i + 1 <= capacity);
        return reverse[i + 1] != 0;
    }

    T getItem(int i) {
        assert(contain(i));
        return data[i + 1];
    }

    void change(int i, T e) {
        assert(contain(i));
        i += 1;
        data[i] = e;

//        for (int j = 1; j <=count ; ++j) {
//            if (indexes[j] == i) {
//                shiftUp(j);
//                shiftDown(j);
//                return;
//            }
//        }

        int j = reverse[i];
        shiftDown(j);
        shiftUp(j);

        return;
    }
};


#endif //INDEXHEAP_INDEXHEAP_H
