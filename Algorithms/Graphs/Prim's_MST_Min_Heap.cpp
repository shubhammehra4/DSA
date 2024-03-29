#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, int w);
    void primMST(int src);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST(int src)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> cost(V, INF);
    vector<int> mstFinal(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    cost[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (inMST[v] == false && cost[v] > weight)
            {
                cost[v] = weight;
                pq.push(make_pair(cost[v], v));
                mstFinal[v] = u;
            }
        }
    }

    cout << "Edge \t Cost\n";
    int sum = 0;
    for (int i = 0; i < V; ++i)
    {
        if (i == src)
            continue;
        sum += cost[i];
        cout << mstFinal[i] << " - " << i << "\t " << cost[i] << endl;
    }
    cout << "Total Cost: " << sum << endl;
}

int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.primMST(0);
    return 0;
}
