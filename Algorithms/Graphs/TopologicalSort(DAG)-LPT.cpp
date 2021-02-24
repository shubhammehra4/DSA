// Using In degree and Longest Path
#include <bits/stdc++.h>
using namespace std;
class Graph {
        int V;
        list<int> *adj;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        void topologicalSort();
};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
};

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
}

void Graph::topologicalSort()
{
    vector<int> in_degree (V, 0);
    vector<int> LPT (V, 0);

    for (int i = 0; i < V; i++)
    {
        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
            in_degree[*itr]++;
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (in_degree[i] == 0)
            q.push (i);
    }

    int cnt = 0;
    vector<int> top_order;

    while (!q.empty() )
    {
        int i = q.front();
        q.pop();
        top_order.push_back (i);

        for (auto itr = adj[i].begin(); itr != adj[i].end(); itr++)
        {
            if (--in_degree[*itr] == 0)
            {
                LPT[*itr] = max (LPT[*itr], 1 + LPT[i]);
                q.push (*itr);
            }
        }

        cnt++;
    }

    if (cnt != V)
    {
        cout << "There exist a cycle in the graph\n";
        return;
    }

    cout << "Topological Order\n";

    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] << " ";

    cout << "\nLPT\n";

    for (int i = 0; i < top_order.size(); i++)
        cout << LPT[i] << " ";

    cout << endl;
}

int main()
{
    Graph g (8);
    g.addEdge (0, 2);
    g.addEdge (0, 3);
    g.addEdge (0, 4);
    g.addEdge (1, 2);
    g.addEdge (1, 7);
    g.addEdge (2, 5);
    g.addEdge (3, 5);
    g.addEdge (3, 7);
    g.addEdge (4, 7);
    g.addEdge (5, 6);
    g.addEdge (6, 7);
    g.topologicalSort();
    return 0;
}