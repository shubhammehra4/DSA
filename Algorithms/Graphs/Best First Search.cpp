#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph {
        int V;
        list< pair<int, int> > *adj;

    public:
        Graph (int V);
        void addEdge (int u, int v, int w);
        void bestFirstSearch (int src, int dest);
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge (int u, int v, int cost)
{
    adj[u].push_back (make_pair (cost, v) );
    adj[v].push_back (make_pair (cost, u) );
}

void Graph::bestFirstSearch (int src, int target)
{
    vector<bool> visited (V, false);
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    pq.push (make_pair (0, src) );
    visited[src] = true;

    while (!pq.empty() )
    {
        int x = pq.top().second;
        cout << x << " - ";
        pq.pop();

        if (x == target)
            break;

        for (auto i = adj[x].begin(); i != adj[x].end(); ++i)
        {
            int v = (*i).second;

            if (visited[v] == false)
            {
                visited[v] = true;
                pq.push (*i);
            }
        }
    }
}

int main ()
{
    int V = 14;
    Graph g (V);
    g.addEdge (0, 1, 3);
    g.addEdge (0, 2, 6);
    g.addEdge (0, 3, 5);
    g.addEdge (1, 4, 9);
    g.addEdge (1, 5, 8);
    g.addEdge (2, 6, 12);
    g.addEdge (2, 7, 14);
    g.addEdge (3, 8, 7);
    g.addEdge (8, 9, 5);
    g.addEdge (8, 10, 6);
    g.addEdge (9, 11, 1);
    g.addEdge (9, 12, 10);
    g.addEdge (9, 13, 2);
    g.bestFirstSearch (0, 9);
    return 0;
}