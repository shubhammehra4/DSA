#include <bits/stdc++.h>
using namespace std;

// union-find
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<int> rank(n, 0);
    vector<int> parent(n, 0);
    iota(begin(parent), end(parent), 0); // initialize parent for every kid as themselves
    function<int(int)> find = [&parent, &find](int x) -> int
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    };
    auto unite = [&parent, &rank, &find](int x, int y) -> bool
    {
        int xp = find(x);
        int yp = find(y);

        if (xp == yp)
            return true;

        if (rank[xp] > rank[yp])
            parent[yp] = xp;
        else if (rank[xp] < rank[yp])
            parent[xp] = yp;
        else
        {
            parent[yp] = xp;
            rank[xp]++;
        }
        return false;
    };

    for (auto &edge : edges)
        unite(edge[0], edge[1]);

    return find(source) == find(destination);
}

// bfs
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n);
    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = true;
        if (node == destination)
            return true;

        for (auto neighbor : graph[node])
            if (!visited[neighbor])
                q.push(neighbor);
    }

    return false;
}

// dfs
bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int destination)
{
    if (node == destination)
        return true;

    if (visited[node])
        return false;

    visited[node] = true;
    for (auto neighbor : graph[node])
        if (dfs(graph, visited, neighbor, destination))
            return true;

    return false;
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> graph(n);
    for (auto &edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    return dfs(graph, visited, source, destination);
}