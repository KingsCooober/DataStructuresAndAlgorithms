//
// Created by tim-berners-bai on 17-6-7.
//

#ifndef UNIONFIND_UNIONFIND_H
#define UNIONFIND_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;

namespace UF1 {
    class UnionFind {
    private:
        int* id;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            id = new int[n];
            for (int i = 0; i < count; ++i) {
                id[i] = i;
            }
        }

        ~UnionFind() {
            delete[] id;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            return id[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pID = find(p);
            int qID = find(q);
            if (pID == qID)
                return;
            for (int i = 0; i < count; ++i) {
                if (id[i] == pID)
                    id[i] == qID;
            }
        }
    };
}

namespace UF2 {
    class UnionFind {
    private:
        int* parent;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
            }
        }

        ~UnionFind() {
            delete[] parent;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p]) {
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            parent[pRoot] = qRoot;
        }

    };
}

namespace UF3 {
    class UnionFind {
    private:
        int* parent;
        int* size;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[count];
            size = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] size;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p]) {
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            if (size[pRoot] < size[qRoot]) {
                parent[pRoot] = qRoot;
                size[qRoot] += size[pRoot];
            }
            else {
                parent[qRoot] = pRoot;
                size[pRoot] += size[qRoot];
            }
        }

    };
}

namespace UF4 {
    class UnionFind {
    private:
        int* parent;
        int* rank;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[count];
            rank = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p]) {
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }
            else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            }
            else {
                parent[qRoot] = pRoot;
                rank[pRoot] += rank[qRoot];
            }
        }

    };
}

namespace UF5{
    class UnionFind {
    private:
        int* parent;
        int* rank;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[count];
            rank = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;

            if (p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }
            else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            }
            else {
                parent[qRoot] = pRoot;
                rank[pRoot] += rank[qRoot];
            }
        }

    };
}

namespace UF6{
    class UnionFind {
    private:
        int* parent;
        int* rank;
        int count;

    public:
        UnionFind(int n) {
            count = n;
            parent = new int[count];
            rank = new int[count];
            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind() {
            delete[] parent;
            delete[] rank;
        }

        int find(int p) {
            assert(p >= 0 && p < count);
            if (p != parent[p]) {
                parent[p] = find(parent[p]);
            }
            return parent[p];
        }

        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }

        void unionElements(int p, int q) {
            int pRoot = find(p);
            int qRoot = find(q);

            if (pRoot == qRoot)
                return;
            if (rank[pRoot] < rank[qRoot]) {
                parent[pRoot] = qRoot;
            }
            else if (rank[pRoot] > rank[qRoot]) {
                parent[qRoot] = pRoot;
            }
            else {
                parent[qRoot] = pRoot;
                rank[pRoot] += rank[qRoot];
            }
        }

    };
}

#endif //UNIONFIND_UNIONFIND_H