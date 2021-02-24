#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
        int V;
        vector<pair<int, edge> > G;
        vector<pair<int, edge> > T;
        int *parent;
    public:
        Graph (int V);
        void addEdge (int u, int v, int w);

        int find_set (int i);
        void union_set (int u, int v);
        void kruskal();
        void print();
};

Graph::Graph (int V)
{
    parent = new int[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph::addEdge (int u, int v, int w)
{
    G.push_back (make_pair (w, edge (u, v) ) );
}

int Graph::find_set (int i)
{
    if (i == parent[i])
        return i;
    else
        return find_set (parent[i]);
}

void Graph::union_set (int u, int v)
{
    parent[u] = parent[v];
}

void Graph::kruskal()
{
    int i, uRep, vRep;
    sort (G.begin(), G.end() );

    for (i = 0; i < G.size(); i++)
    {
        uRep = find_set (G[i].second.first);
        vRep = find_set (G[i].second.second);

        if (uRep != vRep)
        {
            T.push_back (G[i]);
            union_set (uRep, vRep);
        }
    }
}

void Graph::print()
{
    cout << "MST\n";
    cout << "Edge :" << " Weight" << endl;

    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i].second.first << " - " << T[i].second.second << " : "
             << T[i].first;
        cout << endl;
    }
}
int main()
{
    Graph g (6);
    g.addEdge (0, 1, 4);
    g.addEdge (0, 2, 4);
    g.addEdge (1, 2, 2);
    g.addEdge (1, 0, 4);
    g.addEdge (2, 0, 4);
    g.addEdge (2, 1, 2);
    g.addEdge (2, 3, 3);
    g.addEdge (2, 5, 2);
    g.addEdge (2, 4, 4);
    g.addEdge (3, 2, 3);
    g.addEdge (3, 4, 3);
    g.addEdge (4, 2, 4);
    g.addEdge (4, 3, 3);
    g.addEdge (5, 2, 2);
    g.addEdge (5, 4, 3);
    g.kruskal();
    g.print();
    return 0;
}