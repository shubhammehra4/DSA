#include <bits/stdc++.h>
using namespace std;

// union-find
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<int> parent(n, 0);
    iota(begin(parent), end(parent), 0); // initialize parent for every kid as themselves

    function<int(int)> find = [&parent, &find](int x) -> int
    {
        return parent[x] == x ? x : find(parent[x]);
    };

    int provinces = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // avoid recalculate isConnected[i][j], isConnected[j][i]
        {
            if (isConnected[i][j])
            {
                int group1 = find(i);
                int group2 = find(j);

                if (group1 != group2)
                {
                    parent[group2] = group1; // union
                    provinces--;
                }
            }
        }
    }

    return provinces;
}

// bfs visited
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> visited(n, false);
    vector<vector<int>> adjList(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (isConnected[i][j])
                adjList[i].push_back(j);

    int provinces = 0;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            provinces++;
            visited[i] = true;
            q.push(i);

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto neighbour : adjList[node])
                {
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }

    return provinces;
}