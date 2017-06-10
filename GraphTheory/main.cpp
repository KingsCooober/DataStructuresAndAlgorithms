#include "GraphTheory.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortTestPath.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    string filename1 = "/home/tim-berners-bai/CLionProjects/GraphTheory/testG2.txt";

    DenseGrapth::DenseGrapth g1(7, true);
    ReadGraph<DenseGrapth::DenseGrapth> readGraph1(g1, filename1);
    g1.show();
    Component<DenseGrapth::DenseGrapth> component1(g1);
    cout << "TestG2.txt, Component Count: " << component1.count() << endl;

    cout << endl;

    string filename2 = "/home/tim-berners-bai/CLionProjects/GraphTheory/testG2.txt";

    SparseGrapth::SparseGrapth g2(7, false);
    ReadGraph<SparseGrapth::SparseGrapth> readGraph2(g2, filename2);
    g2.show();
    Component<SparseGrapth::SparseGrapth> component2(g2);
    cout << "TestG2.txt, Component Count: " << component2.count() << endl;

    cout << endl;

    Path<SparseGrapth::SparseGrapth> dfs(g2, 0);
    cout << "DFS : ";
    dfs.showPath(3);

    cout << endl;

    ShortTestPath<SparseGrapth::SparseGrapth> bfs(g2, 0);
    cout << "BFS : ";
    bfs.showPath(3);

    return 0;
}