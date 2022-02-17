#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopologicalSorting(vector<vector<int>> &adjLists)
{
    int n = adjLists.size();
    vector<int> inDegree(n, 0);

    for (int i = 0; i < n; i++)
        for (auto neighbor : adjLists[i])
            inDegree[neighbor] += 1;

    queue<int> q;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    vector<int> ordering;

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ordering.push_back(node);

        for (auto neighbor : adjLists[node])
        {
            inDegree[neighbor] -= 1;

            if (inDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (ordering.size() != n)
        throw "Cycle Detected";

    return ordering;
}