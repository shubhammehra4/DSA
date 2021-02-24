#include <bits/stdc++.h>
#define ll long long
#define fab(a,b,i) for(int i=a;i<b;i++)
#define fin(i,n) for(auto &i : n)
#define pb push_back
#define pob pop_back
#define MOD 1000000007
#define endl "\n"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

class Graph {
        int V;
        list<int> *adj;
        bool *visited;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        int BFS (int src, int dest);
        void printGraph ();

};

Graph::Graph (int V)
{
    this->V = V;
    adj = new list<int>[V];
    visited = new bool[V];
};

void Graph::addEdge (int v, int w)
{
    adj[v].push_back (w);
    adj[w].push_back (v);
}

void Graph::printGraph ()
{
    for (int i = 0; i < V; i++)
    {
        cout << "\n Adjacency list of vertex "
             << i << "\n X ";

        for (auto x = adj[i].begin(); x != adj[i].end(); x++)
        {
            cout << "-> " << *x;
        }

        cout << "\n";
    }
}

int Graph::BFS (int src, int dest)
{
    for (int i = 0; i < V; i++)
        visited[i] = false;

    list<int> q;
    visited[src] = true;
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
                q.push_back (*i);

                if (*i == dest)
                    return 0;
            }
        }
    }

    return 1;
}


int main()
{
    quick;
    int l, w, n;
    cin >> l >> w >> n;
    int x[n], y[n];
    Graph g (n + 2);
    fab (0, n, i)
    {
        cin >> x[i] >> y[i];
    }
    int left, right;
    int min = INT_MAX, max = INT_MIN;
    fab (0, n, i)
    {
        fab (i + 1, n, j)
        {
            if (sqrt (pow (x[i] - x[j], 2) + pow (y[i] - y[j], 2) ) <= 100)
            {
                g.addEdge (i + 1, j + 1);
            }
        }

        if (x[i] > max)
            max = x[i], right = i;

        if (x[i] < min)
            min = x[i], left = i;
    }
    // cout << left << " " << right << endl;
    g.addEdge (0, left);
    g.addEdge (n + 1 , right);
    g.printGraph();
    cout << g.BFS (0, n + 1);
    return 0;
}