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
        void dijkstrasShortestPath (int s, int e);
        void printPath (vector<int> prev, vector<int>dist, int s, int e);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge (int u, int v, int w)
{
    adj[u].push_back (make_pair (v, w) );
    adj[v].push_back (make_pair (u, w) );
}

void Graph::printPath (vector<int> prev, vector<int> d, int src, int end)
{
    vector<int> path;

    if (d[end] == INF)
        return;

    for (int i = end; i != -1; i = prev[i])
        path.push_back (i);

    cout << "Path is \n";

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

void Graph::dijkstrasShortestPath (int src, int end)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist (V, INF); // every node is at infinite distance
    pq.push (make_pair (0, src) );
    dist[src] = 0;
    vector<bool> flag (V, false);
    vector<int> prev (V, -1);

    while (!pq.empty() )
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        flag[u] = true;

        if (dist[u] < w) continue;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (flag[v] == false && dist[v] > dist[u] + weight)
            {
                prev[v] = u;
                dist[v] = dist[u] + weight;
                pq.push (make_pair (dist[v], v) );
            }
        }

        if (u == end) break; // Optimisation step to stop further processing
    }

    cout << "Vertex Distance from Source\n";

    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\t" << prev[i] << endl;

    printPath (prev, dist, src, end);
}

int main()
{
    int V = 9;
    Graph g (V);
    g.addEdge (0, 1, 4);
    g.addEdge (0, 7, 8);
    g.addEdge (1, 2, 8);
    g.addEdge (1, 7, 11);
    g.addEdge (2, 3, 7);
    g.addEdge (2, 8, 2);
    g.addEdge (2, 5, 4);
    g.addEdge (3, 4, 9);
    g.addEdge (3, 5, 14);
    g.addEdge (4, 5, 10);
    g.addEdge (5, 6, 2);
    g.addEdge (6, 7, 1);
    g.addEdge (6, 8, 6);
    g.addEdge (7, 8, 7);
    g.dijkstrasShortestPath (0, 7);
    return 0;
}
