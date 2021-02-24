// Using DFS
#include <bits/stdc++.h>
using namespace std;
class Graph {
        int V;
        list<int> *adj;
    public:
        Graph (int V);

        void addEdge (int v, int w);
        void topologicalSortUtil (int v, bool visited[], stack<int>& Stack);
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

void Graph::topologicalSortUtil (int v, bool visited[], stack<int>& Stack)
{
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
            topologicalSortUtil (*i, visited, Stack);
    }

    Stack.push (v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil (i, visited, Stack);
    }

    while (Stack.empty() == false)
    {
        cout << Stack.top() + 1 << "-> ";
        Stack.pop();
    }
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