#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        list<int> *adj;
        bool *visited;
        int *level;
        int *parent;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        void BFS (int src);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    level = new int[V];
    parent = new int[V];
};

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

void Graph::BFS (int src)
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        level[i] = -1;
        parent[i] = -1;
    }

    // visited and level both are not needed one is enough
    list<int> q;
    visited[src] = true;
    q.push_back (src);
    level[src] = 0;

    while (!q.empty() )
    {
        src = q.front();
        cout << src << " : Level " << level[src] << " & Parent " << parent[src] << "->\n";
        q.pop_front();

        for (auto i = adj[src].begin(); i != adj[src].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                parent[*i] = src;
                q.push_back (*i);
            }

            if (level[*i] == -1)
                level[*i] = 1 + level[src];
        }
    }

    cout << "\n";
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
    g.BFS (4);
    g.BFS (3);
    return 0;
}
