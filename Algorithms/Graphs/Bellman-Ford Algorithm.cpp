#include <bits/stdc++.h>
using namespace std;

struct Edge { int src, dest, weight;};

class Graph {
        int V, E;
        struct Edge* edge;
        int cnt;
    public:
        Graph (int V, int E);
        void addEdge (int src, int dest, int w);
        void BellmanFord (int src);
        void printArr (vector<int> dist);
};

Graph::Graph (int V, int E)
{
    this->V = V;
    this->E = E;
    cnt = 0;
    edge = new Edge[E];
}

void Graph::addEdge (int a, int b, int w)
{
    edge[cnt++] = {a, b, w};
}

void Graph::printArr (vector<int> dist)
{
    printf ("Vertex Distance from Source\n");

    for (int i = 0; i < dist.size(); ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

void Graph::BellmanFord (int src)
{
    vector<int> dist (V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = edge[i].src;
        int v = edge[i].dest;
        int weight = edge[i].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf ("Graph contains negative weight cycle");
            return;
        }
    }

    printArr (dist);
    return;
}

int main()
{
    Graph g (5, 8);
    g.addEdge (0, 1, -1);
    g.addEdge (0, 2, 4);
    g.addEdge (1, 2, 3);
    g.addEdge (1, 3, 2);
    g.addEdge (1, 4, 2);
    g.addEdge (3, 2, 5);
    g.addEdge (3, 1, 1);
    g.addEdge (4, 3, -3);
    g.BellmanFord (0);
    return 0;
}
