//
// Created by tim-berners-bai on 17-6-9.
//

#ifndef GRAPHTHEORY_PATH_H
#define GRAPHTHEORY_PATH_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;


template <typename Graph>
class Path {
private:
    Graph &G;
    int s;
    bool* visited;
    int* from;

    void dfs(int v) {
        visited[v] = true;
        typename Graph::adjIterator adj(G, v);
        for (int i = adj.begin(); !adj.end(); i = adj.next()) {
            if (!visited[i]) {
                from[i] = v;
                dfs(i);
            }
        }
    }

public:
    Path(Graph &graph, int s): G(graph) {
        assert(s >= 0 && s < G.V());
        visited = new bool[G.V()];
        from = new int[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }
        this->s = s;

        dfs(s);
    }

    ~Path() {
        delete[] visited;
        delete[] from;
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
};


#endif //GRAPHTHEORY_PATH_H
