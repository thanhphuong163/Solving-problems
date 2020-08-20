#ifndef ADJMAT_H
#define ADJMAT_H
#include <vector>

#define vt vector<T>
#define vvt vector<vt>
#define ll long long

using namespace std;

template <typename T>
class AdjMat {
private:
    vvt adjMat;
public:
    AdjMat(vvt _adjMat);
    AdjMat(ll n_vertices);
    void addEdge(ll u, ll v);
    void addEdge(ll u, ll v, T w);
    vector<ll> getNeighbour(ll vertex);
    void displayGraph();
};

// Adjacency Matrix constructor
template <typename T>
AdjMat<T>::AdjMat(vvt _adjMat)
{
    this->adjMat = _adjMat;
}

template <typename T>
AdjMat<T>::AdjMat(ll n_vertices)
{
    this->adjMat = vvt(n_vertices, vt(n_vertices, 0));
}

// Add unweighted edge weight(u,v) = 1
template <typename T>
void AdjMat<T>::addEdge(ll u, ll v)
{
    this->adjMat[u][v] = 1;
}

// Add weighted edge weight(u,v) = w
template <typename T>
void AdjMat<T>::addEdge(ll u, ll v, T w)
{
    this->adjMat[u][v] = w;
}

// Get neighbours of a vertex
template <typename T>
vector<ll> AdjMat<T>::getNeighbour(ll vertex)
{
    vector<ll> ans;
    for (ll i=0; i < this->adjMat[vertex].size(); ++i)
    {
        if (this->adjMat[vertex][i] != 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// Display adjacency matrix
template <typename T>
void AdjMat<T>::displayGraph()
{
    ll h = this->adjMat.size();
    ll w = this->adjMat[0].size();
    for (ll u = 0; u < h; ++u)
    {
        for (ll v = 0; v < w; ++v)
        {
            cout << this->adjMat[u][v] << " ";
        }
        cout << endl;
    }
}

#endif