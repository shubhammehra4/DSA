#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        list<int> *adj;
        bool *visited;
        int *components;
        int count;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        void dfs (int src);
        void findComponents ();
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    components = new int[V];
}

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

void Graph::dfs (int src)
{
    visited[src] = true;
    components[src] = count;

    for (auto i = adj[src].begin(); i != adj[src].end(); i++)
    {
        if (!visited[*i])
            dfs (*i);
    }
}

void Graph::findComponents ()
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        components[i] = -1;
    }

    count = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs (i);
        }
    }

    cout << "Total Components " << count << endl;

    for (int i = 0; i < V; ++i)
        cout << i << "-" << components[i] << endl;
}

int main()
{
    Graph g (9);
    g.addEdge (0, 1);
    g.addEdge (0, 2);
    g.addEdge (2, 3);
    g.addEdge (2, 4);
    g.addEdge (3, 4);
    g.addEdge (8, 7);
    g.addEdge (6, 5);
    g.findComponents ();
    return 0;
}