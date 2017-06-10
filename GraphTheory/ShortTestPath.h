//
// Created by tim-berners-bai on 17-6-10.
//

#ifndef GRAPHTHEORY_SHORTTESTPATH_H
#define GRAPHTHEORY_SHORTTESTPATH_H

#include <iostream>
#include <cassert>
#include <queue>
#include <stack>

using namespace std;

template <typename Graph>
class ShortTestPath {

private:
    Graph &G;
    int s;
    bool* visited;
    int* from;
    int* ord;

public:
    ShortTestPath(Graph &graph, int s):G(graph) {
        assert(s >= 0 && s < graph.V());

        visited = new bool[graph.V()];
        from = new int[graph.V()];
        ord = new int[graph.V()];

        for (int i = 0; i < graph.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
            ord[i] = -1;
        }

        this->s = s;

        queue<int> q;

        q.push(s);
        visited[s] = true;
        ord[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            typename Graph::adjIterator adj(G, v);
            for (int i = adj.begin(); !adj.end(); i = adj.next()) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    from[i] = v;
                    ord[i] = ord[v] + 1;
                }
            }
        }
    }

    ~ShortTestPath() {
        delete[] visited;
        delete[] from;
        delete[] ord;
    }

    bool hasPath(int w) {
        assert(w >= 0 && w < G.V());
        return visited[w];
    }

    void path(int w, vector<int> &vec) {
        assert(w >= 0 && w < G.V());
        stack<int> s;
        int p = w;
        while (p != -1) {
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty()) {
            vec.push_back((int &&) s.top());
            s.pop();
        }
    }

    void showPath(int w) {
        assert(w >= 0 && w < G.V());
        vector<int> vector1;
        path(w, vector1);
        for (int i = 0; i < vector1.size(); ++i) {
            cout << vector1[i];
            if (i == vector1.size() - 1)
                cout << endl;
            else
                cout << " -> ";
        }
    }

    int length(int w) {
        assert(w >= 0 && w < G.V());
        return ord[w];
    }
};


#endif //GRAPHTHEORY_SHORTTESTPATH_H
