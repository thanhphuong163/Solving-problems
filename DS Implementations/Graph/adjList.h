#ifndef ADJLIST_H
#define ADJLIST_H

#include <vector>

#define ll long long
#define vt vector<T>
#define vvt vector<vt>
#define tt pair<ll, T>
#define vtt vector<tt>
#define vvtt vector<vtt>

using namespace std;

template <typename T>
class AdjList {
private:
    vvtt adjList;
public:
    AdjList(vvtt _adjList);
    AdjList(ll n_vertices);
    void addEdge(ll u, ll v);
    void addEdge(ll u, ll v, T w);
    vector<ll> getNeighbour(ll vertex);
    void displayGraph();
};

// Adjacency List constructor
template <typename T>
AdjList<T>::AdjList(vvtt _adjList){
    this->adjList = _adjList;
}

template <typename T>
AdjList<T>::AdjList(ll n_vertices)
{
    this->adjList = vvtt(n_vertices);
}

// Add unweighted edge weight(u,v) = 1
template <typename T>
void AdjList<T>::addEdge(ll u, ll v) {
    this->adjList[u].push_back(make_pair(v, 1));
}

// Add weighted edge weight(u,v) = w
template <typename T>
void AdjList<T>::addEdge(ll u, ll v, T w){
    this->adjList[u].push_back(make_pair(v, w));
}

// Get neighbours of a vertex
template <typename T>
vector<ll> AdjList<T>::getNeighbour(ll vertex)
{
    vector<ll> ans;
    for (tt neighbour : this->adjList[vertex]) {
        ans.push_back(neighbour.first);
    }
    return ans;
}

// Display adjacency list
template <typename T>
void AdjList<T>::displayGraph() {
    for (ll u=0; u < this->adjList.size(); ++u) {
        cout << u << ": ";
        for (tt neighbour : this->adjList[u]) {
            cout << "(" << neighbour.first << "," << neighbour.second << ") ";
        }
        cout << endl;
    }
}

#endif  // ADJLIST