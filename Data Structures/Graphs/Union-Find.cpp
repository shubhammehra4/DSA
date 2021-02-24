#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        int E;
        list<int> *adj;
    public:
        Graph (int V);

        void addEdge (int v, int w);

        int isCycle();
};

Graph::Graph (int V)
{
    this->V = V;
    E = 0;
    adj = new list<int>[V];
}

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    E += 1;
}

struct subset
{
    int parent;
    int rank;
};

int find (struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find (subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union (struct subset subsets[], int x, int y)
{
    if (subsets[x].rank < subsets[y].rank)
        subsets[x].parent = y;
    else if (subsets[x].rank > subsets[y].rank)
        subsets[y].parent = x;
    else
    {
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}

int Graph::isCycle()
{
    struct subset* subsets = (struct subset*) malloc (V * sizeof (struct subset) );

    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (int i = 0; i < V; i++)
    {
        for (auto j = adj[i].begin(); j != adj[i].end(); j++)
        {
            int x = find (subsets, i);
            int y = find (subsets, *j);

            if (x == y) return 1;

            Union (subsets, x, y);
        }
    }

    return 0;
}

int main()
{
    Graph g (3);
    g.addEdge (0, 1);
    g.addEdge (1, 2);
    g.addEdge (2, 0);

    if (g.isCycle() )
        cout << "Graph Contains Cycle";
    else
        cout << "Graph is Acyclic";

    return 0;
}