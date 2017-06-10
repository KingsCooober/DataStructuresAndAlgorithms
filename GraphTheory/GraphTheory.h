//
// Created by tim-berners-bai on 17-6-8.
//

#ifndef GRAPHTHEORY_GRAPHTHEORY_H
#define GRAPHTHEORY_GRAPHTHEORY_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

namespace DenseGrapth {
    class DenseGrapth {

    private:
        int n, m;
        bool directed;
        vector<vector<bool>> g;

    public:
        DenseGrapth(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            for (int i = 0; i < n; ++i) {
                g.push_back(vector<bool>(n, false));
            }
        }

        ~DenseGrapth() {

        }

        int V() {
            return n;
        }

        int E() {
            return m;
        }

        void addEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            if (hasEdge(v, w))
                return;

            g[v][w] = true;
            if (!directed) {
                g[w][v] = true;
            }
            m++;
        }

        bool hasEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);
            return g[v][w];
        }

        void show() {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << g[i][j] << "\t";
                }
                cout << endl;
            }
        }

        class adjIterator {
        private:
            DenseGrapth &G;
            int v;
            int index;
        public:
            adjIterator(DenseGrapth &grapth, int v): G(grapth) {
                this->v = v;
                this->index = -1;
            }

            int begin() {
                index = -1;
                return next();
            }

            int next() {
                for (index += 1; index < G.V(); ++index) {
                    if (G.g[v][index])
                        return index;
                }
                return -1;
            }

            bool end() {
                return index >= G.V();
            }
        };

    };
}

namespace SparseGrapth {
    class SparseGrapth {

    private:
        int n, m;
        bool directed;
        vector<vector<int>> g;

    public:
        SparseGrapth(int n, bool directed) {
            this->n = n;
            this->m = 0;
            this->directed = directed;
            for (int i = 0; i < n; ++i) {
                g.push_back(vector<int>());
            }
        }

        ~SparseGrapth() {

        }

        int V() {
            return n;
        }

        int E() {
            return m;
        }

        void addEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            if (hasEdge(v, w))
                return;

            g[v].push_back(w);

            if (v != w && !directed) {
                g[w].push_back(v);
            }
            m++;
        }

        bool hasEdge(int v, int w) {
            assert(v >= 0 && v < n);
            assert(w >= 0 && w < n);

            for (int i = 0; i < g[v].size(); ++i) {
                if (g[v][i] == w)
                    return true;
            }

            return false;
        }

        void show() {
            for (int i = 0; i < n; ++i) {
                cout << "vertex " << i << ":\t";
                for (int j = 0; j < g[i].size(); ++j) {
                    cout << g[i][j] << "\t";
                }
                cout << endl;
            }
        }

        class adjIterator {
        private:
            SparseGrapth &G;
            int v;
            int index;
        public:
            adjIterator(SparseGrapth &grapth, int v): G(grapth) {
                this->v = v;
                this->index = 0;
            }

            int begin() {
                index = 0;
                if (G.g[v].size())
                    return G.g[v][index];
                return -1;
            }

            int next() {
                index++;
                if (index < G.g[v].size())
                    return G.g[v][index];
                return -1;
            }

            bool end() {
                return index >= G.g[v].size();
            }

        };
    };
}

#endif //GRAPHTHEORY_GRAPHTHEORY_H
