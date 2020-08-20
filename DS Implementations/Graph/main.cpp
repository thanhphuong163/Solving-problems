#include <iostream>
#include <vector>
#include "adjMat.h"
#include "adjList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    AdjList<int> graph(4);
    graph.addEdge(0, 1, 5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3, 6);
    graph.addEdge(1, 3);
    graph.displayGraph();
    vector<long long> neighbours = graph.getNeighbour(0);
    for (long long i : neighbours) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
