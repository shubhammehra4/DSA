#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        list<int> *adj;
        bool *visited;
        int *parent;
        int *pre;
        int *post;
        int count;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        void DFSUtil (int src);
        void DFS (int src);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    parent = new int[V];
    pre = new int[V];
    post = new int[V];
}

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

void Graph::DFSUtil (int src)
{
    visited[src] = true;
    pre[src] = count++;
    cout << src << " : Parent " << parent[src] << " ->\n";

    for (auto i = adj[src].begin(); i != adj[src].end(); i++)
    {
        if (!visited[*i])
        {
            parent[*i] = src;
            DFSUtil (*i);
            post[*i] = count++;
        }
    }
}

void Graph::DFS (int src)
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        pre[i] = -1;
        post[i] = -1;
    }

    count = 0;
    DFSUtil (src);
    post[src] = count;
    cout << "\n";

    for (int i = 0; i < V; i++)
    {
        cout << pre[i] << " : " << i << " : " << post[i] << "\n";
    }

    cout << "\n";
}

int main()
{
    Graph g (5);
    g.addEdge (0, 1);
    g.addEdge (0, 2);
    g.addEdge (2, 3);
    g.addEdge (2, 4);
    g.addEdge (3, 4);
    g.DFS (0);
    // g.DFS (3);
    return 0;
}