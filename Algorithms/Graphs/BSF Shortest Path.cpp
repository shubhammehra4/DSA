#include <bits/stdc++.h>
using namespace std;

class Graph {
        int V;
        list<int> *adj;
        bool *visited;
        int *pred;
        int *dist;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        bool BFS (int src, int dest);
        void shortestPath (int src, int dist);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    pred = new int[V];
    dist = new int[V];
};

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

bool Graph::BFS (int src, int dest)
{
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    list<int> q;
    visited[src] = true;
    dist[src] = 0;
    q.push_back (src);

    while (!q.empty() )
    {
        int u = q.front();
        q.pop_front();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                dist[*i] = dist[u] + 1;
                pred[*i] = u;
                q.push_back (*i);

                if (*i == dest)
                    return true;
            }
        }
    }

    return false;
}

void Graph::shortestPath (int src, int dest)
{
    if (BFS (src, dest) == false)
    {
        cout << "Given source and destination are not connected" << endl;
        return;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back (crawl);

    while (pred[crawl] != -1)
    {
        path.push_back (pred[crawl]);
        crawl = pred[crawl];
    }

    cout << "Length of Shortest Path is : " << dist[dest] << endl;
    cout << "Path is : " << endl;

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

int main()
{
    Graph g (8);
    g.addEdge (0, 1);
    g.addEdge (0, 3);
    g.addEdge (1, 2);
    g.addEdge (3, 4);
    g.addEdge (3, 7);
    g.addEdge (4, 5);
    g.addEdge (4, 6);
    g.addEdge (4, 7);
    g.addEdge (5, 6);
    g.addEdge (6, 7);
    g.shortestPath (0, 6);
    return 0;
}
