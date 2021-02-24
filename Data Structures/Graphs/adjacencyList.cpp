#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        list<int> *adj;
    public:
        Graph (int V);

        void addEdge (int v, int w);

        void printGraph (int v);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

void Graph::printGraph (int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << "\n Adjacency list of vertex "
             << i << "\n X ";

        for (auto x = adj[i].begin(); x != adj[i].end(); x++)
        {
            cout << "-> " << *x;
        }

        cout << "\n";
    }
}

int main()
{
    Graph g (5);
    g.addEdge (0, 1);
    g.addEdge (0, 4);
    g.addEdge (0, 3);
    g.addEdge (1, 2);
    g.addEdge (1, 3);
    g.addEdge (2, 3);
    g.addEdge (3, 4);
    g.printGraph (5);
    return 0;
}