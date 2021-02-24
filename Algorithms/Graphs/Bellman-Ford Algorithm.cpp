#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;


class Graph {
        int V;
        list< pair<int, int> > *adj;

    public:
        Graph (int V);
        void addEdge (int u, int v, int w);

        void bellmanFord (int s);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge (int u, int v, int w)
{
    adj[u - 1].push_back (make_pair (v - 1, w) );
}

void Graph::bellmanFord (int src)
{
    vector<int> dist (V, INF);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int k = 0; k < V; k++)
        {
            for (auto j = adj[k].begin(); j != adj[k].end(); ++j)
            {
                int v = j->first;
                int weight = j->second;

                if (dist[i] != INF &&  dist[v] > dist[i] + weight )
                    dist[v] = dist[i] + weight;

                // dist[v] = min (dist[v], dist[i] + weight);
            }
        }

        for (int i = 0; i < V; i++)
        {
            cout << dist[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int V = 8;
    Graph g (V);
    g.addEdge (1, 2, 10);
    g.addEdge (1, 8, 8);
    g.addEdge (2, 6, 2);
    g.addEdge (3, 2, 1);
    g.addEdge (3, 4, 1);
    g.addEdge (4, 5, 3);
    g.addEdge (5, 6, -1);
    g.addEdge (6, 3, -2);
    g.addEdge (7, 2, -4);
    g.addEdge (7, 6, -1);
    g.addEdge (8, 7, 1);
    g.bellmanFord (0);
    return 0;
}
