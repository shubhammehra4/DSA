#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool *visited;
    // low-link value defaults to id of the node but is the
    // lowest id that a node can reach i.e. lowest from all edges connected to it
    int *low;
    int *ids; // unique ids
    int id;   // id counter
    int outEdgeCount;

public:
    Graph(int V);

    void addEdge(int v, int w);
    void DFS(int src, int parent, vector<pair<int, int>> &bridges);
    void findBridges();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
    low = new int[V];
    ids = new int[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int src, int parent, vector<pair<int, int>> &bridges)
{
    visited[src] = true;
    low[src] = ids[src] = id;
    id++;

    for (auto i = adj[src].begin(); i != adj[src].end(); i++)
    {
        if (*i == parent)
            continue;

        if (!visited[*i])
        {
            DFS(*i, src, bridges);
            low[src] = min(low[src], low[*i]);

            // bridge condition
            if (ids[src] < low[*i])
                bridges.push_back({src, *i});
        }
        else
            low[src] = min(low[src], ids[*i]); // update low link value
    }
}

void Graph::findBridges()
{
    vector<pair<int, int>> bridges;
    id = 0;
    outEdgeCount = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        ids[i] = 0;
        low[i] = 0;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i, -1, bridges);
    }

    for (int i = 0; i < V; i++)
        cout << ids[i] << "-" << low[i] << "\n";

    cout << "Bridges :" << endl;
    for (auto x : bridges)
        cout << x.first << "-" << x.second << endl;
}

int main()
{
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 8);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.findBridges();
    return 0;
}